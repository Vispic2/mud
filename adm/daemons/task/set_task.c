

//by name 加入zj协议

inherit F_DBASE;

#include <ansi.h>

#define ZIXU "/adm/daemons/task/npc/zixu"                 //task发布宣布者
#define TASK_CARRIER "/adm/daemons/task/npc/task_carrier" //task 携带者
#define TASK_OBJECT "/adm/daemons/task/obj/"              //task物件目录
#define MIRROR "/adm/daemons/task/mirror.c"               //宝镜放置的路径
int ask_baojin();
void create()
{
    seteuid(getuid());
    set("name", HIG "宝镜任务精灵" NOR);
    set("id", "mirror daemon");
    call_out("task_reminder", 30);
}

void task_reminder()
{
    object zixu = find_object(ZIXU);
    if (!zixu)
        zixu = load_object(""+ZIXU+"");

    CHANNEL_D->do_channel(zixu, "chat", HIR "请注意，宝镜任务将于三分钟后重新分布。"NOR"" );
 //   QQ_D->msg("子虚道人：请注意，宝镜任务将于三分钟后重新分布。");
    remove_call_out("set_task");
    call_out("set_task", 180);
}

void set_task()
{
    object npc, zixu, task, *mirror, mirror_owner, *npc_inv;
    string *i_list, *ip;
    int level, x, i, ii, same, y;

    zixu = find_object(ZIXU);
    if (!zixu)
        zixu = load_object(ZIXU);
    level = random(15) + 1;

    CHANNEL_D->do_channel(zixu, "chat", HIY "宝镜任务重新分布完毕。"NOR"");

    remove_call_out("task_reminder");
    call_out("task_reminder", 1020);

    i_list = get_dir(TASK_OBJECT);

    for (x = 0; x < sizeof(i_list); x++)
    {
        task = find_object(TASK_OBJECT + i_list[x]);
        if (task)
            destruct(task);
    }

    for (x = 0; x < sizeof(i_list); x++)
    {

        task = find_object(TASK_OBJECT + i_list[x]);
        if (!task)
        {
            npc = new (TASK_CARRIER);

            task = load_object(TASK_OBJECT + i_list[x]);
            task->set("task_time", time() / 100);

            NPCS_D->place_npc(npc, 0);
            if (strsrch(npc->query("long"), "一个拾荒者") > -1)
            { //增加npc的伪装
                npc_inv = all_inventory(npc);
                for (y = 0; y < sizeof(npc_inv); y++)
                {
                    destruct(npc_inv[y]);
                }
                npc->carry_object("/clone/cloth/cloth")->wear();
                npc->set("combat_exp", 1);
            }
            else
            {
                NPCS_D->set_from_me(npc, zixu, random(100) + 1);
                npc->add_temp("apply/attack", npc->query_skill("force") *
                                                  (level - 1) / 15);
                npc->add_temp("apply/dodge", npc->query_skill("force") *
                                                 (level - 1) / 15);
                npc->add_temp("apply/parry", npc->query_skill("force") *
                                                 (level - 1) / 15);
                npc->add_temp("apply/damage", 5 + level * 7);
                npc->add_temp("apply/unarmed_damage", 5 + level * 7);
                npc->add_temp("apply/armor", 10 + level * 15);
                
            }
            npc->set("task_name",task->name());
            npc->set("nickname",""HIR"【"HIC"宝镜"HIG"任务"HIR"】"NOR"");
            /*
            npc->set("inquiry", ([
            "宝镜任务": (: ask_baojin :),
           ]));
           */
            task->move(npc);
            
            
            NPCS_D->random_move(npc);
            NPCS_D->random_move(npc);
            NPCS_D->random_move(npc);
            NPCS_D->random_move(npc);
        }
    }

    mirror = children(MIRROR);

    if (sizeof(mirror) == 1)
        return; //只有主物件没有任何clone出来的

    for (i = 0; i < sizeof(mirror); i++)
    {

        if (!clonep(mirror[i]))
            continue; //若是主物件不注入

        mirror_owner = environment(mirror[i]);

        if (query_ip_number(mirror_owner) == 0)
        {
            destruct(mirror[i]);
            tell_object(mirror_owner, "你目前没有ip地址，因此"
                                      "这块宝镜天神予以没收。\n");
            continue;
        }

        if (!ip)
        {
            ip = ({query_ip_number(mirror_owner)});

            mirror[i]->set("power", 100);
            tell_object(mirror_owner, HIR "只见一道红光注入你的乾坤宝"
                                          "镜里面，使它顿时有了灵气。"NOR"\n" );
            continue;
        }
        else
        {
            same = 0;
            for (ii = 0; ii < sizeof(ip); ii++)
            {
                if (query_ip_number(mirror_owner) == ip[ii])
                    same = 1;
            }
            if (same == 1)
            {
                destruct(mirror[i]);
                tell_object(mirror_owner, "你所在ip还有另外的宝镜，"
                                          "这块宝镜天神予以没收。\n");
            }
            else
            {
                ip += ({query_ip_number(mirror_owner)});
                mirror[i]->set("power", 100);
                tell_object(mirror_owner, HIR "只见一道红光注入你的乾坤宝"
                                              "镜里面，使它顿时有了灵气。"NOR"\n" );
            }
        }
    }
}

int ask_baojin()
{
write("请执行命令：ask ID about 道具名字\n");
}


int do_return(object ob, object me, string arg)
{
    string target, item;
    object who, pay;
    int count, exp, pot /*, tihui*/, gx;
    //增加阅历奖励 2016-12-21
    int score;
    int kar;

    if (!arg)
        return notify_fail("你要给谁什么东西？\n");

    if (sscanf(arg, "%s to %s", item, target) != 2 &&
        sscanf(arg, "%s %s", target, item) != 2)
        return 0;

    if (item != ob->query("id"))
        return 0;

    who = present(target, environment(me));

    if (!objectp(who))
        return notify_fail("这里没有这个人。\n");

    if (who->query("id") != ob->query("owner_id"))
        return 0;

    if (!living(who))
        return notify_fail("你还是得等人家醒了再说吧。\n");

    if (me->query("mirror_task/task_time") != ob->query("task_time"))
    {
        me->delete ("mirror_task");
        me->set("mirror_task/task_time", ob->query("task_time"));
    }

    me->add("mirror_task/count", 1);
    me->add("mirror_count", 1);

    count = me->query("mirror_task/count");

    exp = 1000 + random(1000);
    if (count > 20)
    pot = 5000 + random(2500);
    else if (count > 10)
     pot = 2000 + random(1000);
    else if (count > 5)
    pot = 1000 + random(500);
    else
    pot = 600 + random(300);

    if (count == 5)
    pot += 1000;
    if (count == 10)
    pot += 3000;
    if (count == 15)
    pot += 5000;
    gx = 2 + random(2);
    kar = me->query("kar"); //修改阅历增加和福缘挂钩 2016-12-21
    score = 20 + random(kar);
    me->add("combat_exp", exp);
    me->add("potential", pot);
    me->add("yuanbaos",4);
    me->delete ("xquest/mirror");
    tell_object(me, "你拿出" + ob->name() + "(" + ob->query("id") + ")给" +who->name() + "。\n" + WHT + who->name() + "说道：“啊，真是多谢这位" +RANK_D->query_respect(me) + "了。”\n" NOR);
    tell_object(me, HIY "这是你这一轮完成的第" + HIR +chinese_number(me->query("mirror_task/count")) + NOR + HIY "个宝镜任务。\n" NOR +HIG "通过这次锻炼，你获得了" NOR HIR + chinese_number(exp) +HIG "点经验，" NOR HIW + chinese_number(pot) + NOR HIG "点潜能，"+HIY+ZJSIZE(24)+" 四点元宝票！"NOR"\n" NOR HIW "外加奖励三十两白银。"NOR"\n" );
    if (me->query("mirror_count")){
        tell_object(me, HIY "你累计已完成" + HIR + chinese_number(me->query("mirror_count")) + NOR + HIY "个宝镜任务。\n" NOR);
    }
    message("vision", me->name() + "拿出" + ob->name() + "(" + ob->query("id") + ")给" + who->name() + "。\n" + WHT + who->name() + "说道：啊，真是多谢这位" + RANK_D->query_respect(me) + "了。”\n" NOR, environment(me), ({me}));
    pay = new ("/clone/money/silver");
    pay->set_amount(30);
    pay->move(me, 1);
    destruct(ob);
    
    if (me->query("mirror_count") == 100 || me->query("mirror_count") == 200 || me->query("mirror_count") == 300 || me->query("mirror_count") == 400 || me->query("mirror_count") == 500)
    call_other(__FILE__, "set_item", me);
    return 1;
}

string set_item(object me)
{
    //task增加100、200、400任务奖品 by 薪有所属
    // 完成100个task：美容丸、福源丹
    string *ob1_list = ({
"/clone/liandan/qi_1",
"/clone/liandan/nei_1",
"/clone/liandan/jing_1",
    });

    // 完成200个task：7成丹
    string *ob2_list = ({
   "/clone/liandan/qi_1",
   "/clone/liandan/nei_1",
   "/clone/liandan/jing_1",   
   "/clone/liandan/qi_2",
   "/clone/liandan/nei_2",
   "/clone/liandan/jing_2",
    });

    // 完成300个task：85成丹
    string *ob3_list = ({
    "/clone/liandan/qi_2",
    "/clone/liandan/nei_2",
    "/clone/liandan/jing_2",
    });

    // 完成400个task：稀有特殊合成材料
    string *ob4_list = ({
     "/clone/liandan/qi_2",
     "/clone/liandan/nei_2",
     "/clone/liandan/jing_2",     
     "/clone/liandan/qi_3",
     "/clone/liandan/nei_3",
     "/clone/liandan/jing_3",
    });

    // 完成500个task：无花果
    string *ob5_list = ({
"/clone/liandan/qi_3",
"/clone/liandan/nei_3",
"/clone/liandan/jing_3",
    });
    string gift;
    object item;

    if (me->query("mirror_count") == 100)
    {
        gift = ob1_list[random(sizeof(ob1_list))];
    }
    else if (me->query("mirror_count") == 200)
    {
        gift = ob2_list[random(sizeof(ob2_list))];
    }
    else if (me->query("mirror_count") == 300)
    {
        gift = ob3_list[random(sizeof(ob3_list))];
    }
    else if (me->query("mirror_count") == 400)
    {
        gift = ob4_list[random(sizeof(ob4_list))];
    }
    else if (me->query("mirror_count") == 500)
    {
        me->delete ("mirror_count");
        gift = ob5_list[random(sizeof(ob5_list))];
    }

    item = new (gift);
    item->move(me);

    if (item->query("base_unit")) {
        tell_object(me, HIG "你获得了一" + item->query("base_unit") + NOR +item->name() + "\n");
    }else{
        tell_object(me, HIG "你获得了一" + item->query("unit") + NOR + item->name() + "\n");
    }
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
