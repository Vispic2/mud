// qingyangzi.c  青陽子
// Written by Vin  2002/4/28

#include <ansi.h>
inherit NPC;

int ask_me();
int tattoo(object me);
string ask_qu();


mapping body_type = ([ "脸部" : ({ "face" }),
                       "胸口" : ({ "chest" }),
                       "后背" : ({ "back" }),
                       "臀部" : ({ "buttock" }),
                       "左臂" : ({ "leftarm" }),
                       "右臂" : ({ "rightarm" }), ]);

void create()
{
        set_name(HIY"青陽子"NOR, ({ "qingyang zi", "qingyang", "zi" }));
        set("long", "他便是天下第一刺青师青陽子。\n" );

        set("nickname", HIB "刺青师" NOR);
        set("gender", "男性");
        set("attitude", "friendly");
        set("age", 325);
        set("shen_type", 0);
        set("str", 500);

        set("inquiry", ([
                "刺青" : (: ask_me :),
                "去青" : (: ask_qu :),
                "说明":"击杀幽魂/年兽有概率掉落图纸，幽魂每周六周日刷新，年兽除夕期间刷新注意!",
  
        ]));

        setup();

    

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/npc_item2")->wield();
        set_temp("handing", carry_object("/clone/npc_item1"));
}

void init()
{
        add_action("do_show", "show");
        add_action("do_answer", "answer");
        // 刺青过程中禁止查看自身状态，为什么要这样呢？因为
        // 实际数据已经在进行玩家所看到的刺青过程前便设置了。
        add_action("do_check", "hp");
        add_action("do_check", "score");
        add_action("do_check", "special");
        add_action("do_decide", "decide");
}


string ask_qu()
{
	object me = this_player();
	
		
	write(ZJOBLONG"青阳子说道：纹上容易去掉难，最近我研发的新技术，可以帮你去掉刺青，但技术还有瑕疵，所以就不再收取费用了。所有刺青只能全部去除，目前还做不到分部位去除。如果"+RANK_D->query_respect(me)+"确定"HIR"去青"NOR"，请点击确认按钮：\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)+
		HIR"确定去青"NOR":decide\n");
	return "纹上容易去掉难，全部去除无保留！\n";
}


int do_decide()
{
	object me;
	me = this_player();
	if (!me->query("tattoo"))
	return notify_fail("你还没有刺青，谈什么去青呢？\n");		
	me->delete("tattoo",1);
	message_sort(CYN "$N" CYN "把$n装进一台神秘的机器，关闭舱门。一阵轰鸣后" CYN "，打开舱门，$n惊奇的发现身上所有的刺青都无影无踪了。\n" NOR, this_object(),this_player());		
	return 1;
}



int do_check()
{
        object me = this_player();

        if (me->query_temp("item/status") == "waiting")
        {
                message_vision(CYN "$N" CYN "对$n" CYN "喝道：别乱"
                               "动！还没刺完，你猴急什么？\n" NOR,
                               this_object(), me);
                return 1;
        }
}

int do_show(string arg)
{
        string status, msg, mat;
        object me, ob;
        int value, n;

        me = this_player();
        if (! arg)
                return notify_fail("你想要亮出什么东西？\n");

        mat = arg;

        if (! objectp(ob = present(mat, me)))
                return notify_fail("你身上似乎没有这种东西。\n");

        status = query_temp("item/status");

        if (status == "look_working")
        {
                message_vision(CYN "$N" CYN "头也不抬，对$n" CYN "说道："
                               "我这正忙，你的事等会再说。\n" NOR,
                               this_object(), me);
                return 1;
        }

        if (! ob->query("can_tattoo"))
        {
                message_vision(CYN "$N" CYN "眉头一皱，对$n" CYN "说道："
                               "我只对图腾感兴趣，没事别来烦我。\n" NOR,
                               this_object(), me);
                return 1;
        }

        if (ob->query("value") >= 50000)
                msg = sprintf(CYN "$N" CYN "接过$n" CYN "拿出的图样，凝视良久"
                              "之后，幽幽一声长叹。\n" NOR);
        else
        if (ob->query("value") >= 30000)
                msg = sprintf(CYN "$N" CYN "接过$n" CYN "拿出的图样，看了一会"
                              "，脸上露出赞许的神色。\n" NOR);
        else
        if (ob->query("value") >= 10000)
                msg = sprintf(CYN "$N" CYN "接过$n" CYN "拿出的图样，皱了皱眉"
                              "，似乎想说些什么。\n" NOR);
        else
                msg = sprintf(CYN "$N" CYN "望着$n" CYN "递来的图样，冷笑一声"
                              "，脸上露出不屑的神色。\n" NOR);

        value = ob->query("value") / 50;
        msg += sprintf(CYN "$N" CYN "点了点头道：这样的刺青需要黄金%s两，你自"
                       "己斟酌吧。\n" NOR, chinese_number(value));
        message_vision(msg, this_object(), me);

        return 1;
}

// 发出提示信息
int ask_me()
{
        message_sort(CYN "$N" CYN "抬头看了看$n" CYN "，点头道：先把你打算纹"
                     "刺的图腾拿给我看(" HIY "show" NOR + CYN ")看，让我估算"
                     "一下价钱，如果觉得合适就交钱。\n" NOR, this_object(),
                     this_player());
        return 1;
}

// 接受定金
int accept_object(object me, object ob)
{
        string status;
        int val;

        status = query_temp("item/status");
        if (status == "look_working")
        {
                message_vision(CYN "$N" CYN "头也不抬，对$n" CYN "说道："
                               "我这正忙，你的事等会再说。\n" NOR,
                               this_object(), me);
                return 0;
        }

        if (status == "waiting")
        {
                if (query_temp("item/player_id") == me->query("id"))
                {
                        command("say 你给我躺好，别乱动。");
                        return 0;
                }

                message_vision(CYN "$N" CYN "头也不抬，对$n" CYN "说道："
                               "我这正忙，你的事等会再说。\n" NOR,
                               this_object(), me);
                return 0;
        }

        if (status == "accept")
        {
                if (query_temp("item/player_id") != me->query("id"))
                {
                        command("say 没见我正忙么，还来添什么乱！");
                        return 0;
                }

                if (! ob->query("money_id"))
                {
                        command("say 我让你交钱，你给我这个干嘛？");
                        return 0;
                }
        }

        if (ob->query("can_tattoo") && ob->query("tattoo_type"))
        {
                mixed p;
                string *types;

                types = keys(body_type);

                p = me->query("tattoo/tattoo");
                if (arrayp(p))
                        types -= p;
                else
                if (stringp(p))
                        types -= ({ p });

                if (! sizeof(types))
                {
               	        message_vision(CYN "$N" CYN "对$n" CYN "冷笑道：你全"
               	                       "身已经纹得跟鬼一样了，还嫌不够么？\n"
               	                       NOR, this_object(), me);
                        return 0;
                }

                if ((p = ob->query("can_tattoo")) == "all")
                {
                        types = keys(body_type);
                } else
                if (arrayp(p))
                        types = p;
                else
                if (stringp(p))
                        types = ({ p });

                // 确认该ID是否有地方已经被刺青
                p = me->query("tattoo/tattoo");
                if (arrayp(p))
                        types -= p;
                else
                if (stringp(p))
                        types -= ({ p });

                if (! sizeof(types))
                {
                        message_vision(CYN "$N" CYN "摇了摇头道：这个图"
                                       "腾并不适合纹到你剩下的部位上。\n"
                                       NOR, this_object(), me);
                        return 0;
                }

                // 计算刺青所花费的价值
                val = ob->query("value") / 50;
                message_vision(CYN "$N" CYN "点了点头道：这样的刺青需要黄金" +
                               chinese_number(val) + "两，你现在就付钱吧。\n"
                               NOR, this_object(), me);
                val *= 10000;
                ob->set("itemalue", val);
                me->set_temp("item/status", "item_gived");
                me->set_temp("itemalue", val);
                set_temp("item/status", "accept");
                set_temp("item/player_id", me->query("id"));
                set_temp("item/accept", ob);

                remove_call_out("time_out");
                call_out("time_out", 30, me, ob);
                return 1;
        }

        if (ob->query("money_id"))
        {
                object origin;
                mixed p;
                string *types;

                if (me->query_temp("item/status") == "answer_type")
                {
                        message_vision(CYN "$N" CYN "摇摇头，对$n" CYN "道：别急"
                                       "着给钱，先说说你要干什么？\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                if (me->query_temp("item/status") != "item_gived")
                {
                        message_vision(CYN "$N" CYN "把$n" CYN "递过去的" + ob->name() +
                                       CYN "推了回来，摇头道：无功不受禄。\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                if (ob->value() < me->query_temp("itemalue"))
                {
                        message_vision(CYN "$N" CYN "冷笑道：江湖上谁不知道我青"
                                       "陽子说一不二，难道能为你破例？\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                origin = query_temp("item/accept");
                if ((p = origin->query("can_tattoo")) == "all")
                {
                        types = keys(body_type);
                } else
                if (arrayp(p))
                        types = p;
                else
                if (stringp(p))
                        types = ({ p });

                // 确认该ID是否有地方已经被刺青
                p = me->query("tattoo/tattoo");
                if (arrayp(p))
                        types -= p;
                else
                if (stringp(p))
                        types -= ({ p });

                if (! sizeof(types))
                {
                        message_vision(CYN "$N" CYN "摇了摇头道：这个刺"
                                       "青不适合纹到你剩下的部位。\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                set_temp("itempes", types);
                set_temp("item/money", ob);

                ob->move(this_object());

                message_vision(CYN "$N" CYN "对$n" CYN "说道：你打算在什"
                               "么地方刺青？请告诉(" HIY "answer" NOR +
                               CYN ")我具体部位。\n" NOR, this_object(), me);
                tell_object(me, HIC "你还可以在" HIY + implode(types, "、" )
                                + HIC "上刺青。\n" NOR);

                me->set_temp("item/status", "answer_type");
                return -1;
        }

        message_vision(CYN "青陽子对$N" CYN "皱眉道：好象有点问题，你让巫"
                       "师来帮你看看。\n" NOR, me);
        return 0;
}

int do_answer(string arg)
{
        string *tattooed, *types;
        string tlong, special;
        object ob, me;
        object money;

        me = this_player();
        if (me->query_temp("item/status") != "answer_type")
                return 0;

        if (! arg)
                return notify_fail("你要回答什么？\n");

        message_vision(CYN "$n" CYN "歪着头想了一会，对$N" CYN "道：那"
                       "就劳驾你把刺青纹在我的" + arg + "上吧！\n" NOR,
                       this_object(), me);

        if (member_array(arg, query_temp("itempes")) == -1 ||
            undefinedp(body_type[arg]))
        {
                message_vision(CYN "$N" CYN "看了看$n" CYN "，鄙夷的冷"
                               "笑了一声。\n" NOR, this_object(), me);
                return 1;
        }

        if (objectp(money = query_temp("item/money")))
                destruct(money);

        set_temp("item/status", "look_working");
        me->set_temp("item/status", "waiting");

        ob = query_temp("item/accept");

        message_sort(HIC "\n$N" CYN "点了点头，对$n" CYN "说道：我们"
                     "这就开始吧，你躺到那边的床上去，别乱动。$N"
                     HIC "说完便转过身去，随手将" + ob->name() + HIC
                     "浸入身后的水盆，待" + ob->name() + HIC "完全湿"
                     "透后，再小心翼翼地从水中取出，轻轻蒙在$n" HIC
                     "的" + arg + "之上。\n\n" NOR, this_object(), me);

        // 为已经刺了青的部位记号
        tattooed = me->query("tattoo/tattoo");

        if (! arrayp(tattooed))
                tattooed = ({ });

        tattooed -= ({ arg });
        tattooed += ({ arg });
        me->set("tattoo/tattoo", tattooed);

        // 增加不同部位的刺青描述
        tlong = ob->query("tattoo_long");

        switch (arg)
        {
        case "脸部":
                me->set("tattoo/face_long", tlong);
                break;
        case "胸口":
                me->set("tattoo/chest_long", tlong);
                break;
        case "后背":
                me->set("tattoo/back_long", tlong);
                break;
        case "左臂":
                me->set("tattoo/leftarm_long", tlong);
                break;
        case "右臂":
                me->set("tattoo/rightarm_long", tlong);
                break;
            case "臀部":
                me->set("tattoo/buttock_long", tlong);
                break;
        default:
                me->set("tattoottock_long", tlong);
                break;
        }

        // 刺青加属性 
        if (ob->query("tattoo_str"))
        me->add("str", ob->query("tattoo_str"));
        me->add("strs", ob->query("tattoo_str"));
        if (ob->query("tattoo_int"))
        me->add("int", ob->query("tattoo_int"));
        me->add("ints", ob->query("tattoo_int"));
        if (ob->query("tattoo_con"))
        me->add("con", ob->query("tattoo_con"));
        me->add("cons", ob->query("tattoo_con"));
        if (ob->query("tattoo_dex"))
        me->add("dex", ob->query("tattoo_dex"));
        me->add("dexs", ob->query("tattoo_dex"));
        if (ob->query("tattoo_per"))        
        me->add("per", ob->query("tattoo_per"));
        if (ob->query("tattoo_gain/max_qi"))        
        me->add("gain/max_qi", ob->query("tattoo_gain/max_qi"));
        // 执行刺青的过程描述
        me->start_busy(bind((: call_other, __FILE__, "tattoo" :), me));

        remove_call_out("time_out");
        destruct(ob);
        return 1;
}

int tattoo(object me)
{
        object ob;
        string msg;
        int finish;

        if (! me->query_temp("tattoo/step"))
                me->set_temp("tattoo/step", 1);

        finish = 0;
        switch (me->query_temp("tattoo/step"))
        {
        case 1:
                msg = "青陽子走进内堂，端出一个檀木沉香盒，轻轻拈出一根银针。";
                break;
        case 2:
                msg = "接着青陽子将$N的身体摆放端正，再沿着图腾中的纹样施针。";
                break;
        case 3:
                msg = "只见青陽子掌出如风，每一针皆是一沾即过，来去极为迅捷。";
                break;
        case 4:
                msg = "不多时，纹样的轮廓已被青陽子勾勒出来，和图腾分毫不差。";
                break;
        case 5:
                msg = "又一会，$N刺青上的纹样渐渐清晰了起来，与肌肤融为一体。";
                break;
        case 6:
                msg = "你不禁感叹青陽子的针法精奇，刺下千多针竟不见有血涌出。";
                break;
        case 7:
                msg = "青陽子接着从盒子里取出十八色瓷瓶，分取粉末放入色盘中。";
                break;
        case 8:
                msg = "青陽子用指甲尖轻轻挑出各色粉末，再分别弹入$N刺青之上。";
                break;
        case 9:
                msg = "过得良久，弹在刺青上的各色粉末已经渐渐渗入了$N的肌肤。";
                break;
        case 10:
                msg = "刺青上的颜色慢慢显露了出来，色彩明艳，与图腾更无二致。";
                break;
        case 11:
                msg = "只见刺青上的纹样精雕细琢，栩栩如生，似要冲关欲出一般。";
                break;
        case 12:
                msg = "青陽子凝视许久，点了点头，轻轻拂去了刺青上剩余的粉末。";
                break;
        default:
                msg = "青陽子对$N说道：图腾上的纹样已经都帮你刺好了，起身吧。";
                finish = 1;
                break;
        }
        msg += "\n";

        msg = replace_string(msg, "$N", "你");
        msg = replace_string(msg, "$n", name());
        message("vision", HIG + msg + NOR, me);

        if (finish)
        {
                if (objectp(ob = present("qingyang zi", environment(me))))
                {
                        ob->delete_temp("item");
                        message_vision(HIC "\n$N" HIC "对$n" HIC "说道："
                                       "钱我收了，刺青则帮你纹了，从此你"
                                       "我两无相欠。\n" NOR, ob, me);
                }

                me->delete_temp("item");
                me->delete_temp("tattoo/step");
                tell_object(me, HIY "\n刺青结束后，你感到身体似乎有了某"
                                "种奇特的变化。\n" NOR);
                return 0;
        }
        me->add_temp("tattoo/step", 1);
        return 1;
}

void time_out(object me, object ob)
{
        object money;
        int at_present;

        money = query_temp("item/money");

        if (! objectp(me))
                me = find_player(query_temp("item/player_id"));

        if (! objectp(me) || environment(me) != environment())
        {
                command("say 奇怪，刚才那位客人呢？怎么这就走了？\n");
                at_present = 0;
        } else
        {
                command("say 你慢慢犹豫吧，我可不能跟你耗着！想好再来吧！");
                at_present = 1;
        }

        delete_temp("item");
        if (objectp(me))
                me->delete_temp("item");

        if (money)
        {
                if (at_present)
                        command("give " + money->query("id") +
                                " to " + me->query("id"));

                if (environment(money) == this_object())
                        command("drop " + money->query("id"));
        }

        if (ob)
        {
                if (at_present)
                        command("give " + ob->query("id") +
                                " to " + me->query("id"));

                if (environment(ob) == this_object())
                        command("drop " + ob->query("id"));
        }
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
