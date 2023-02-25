// invader.c

#include <ansi.h>
#include <command.h>
#define INVASIOND "/adm/daemons/invasion/invasiond"
#define TOTAL_INVADER 24

inherit NPC;

void init()
{
    object ob;
    ob = this_object();

    if (random(20) == 1 && time() - query("born_time") > 5 &&
        query("lvl") >= 4 &&
        time() - query_temp("last_chat") > 60)
    {
        command("chat 我现在占领了" NOR HIM + environment(ob)->query("short") + NOR HIW "，伙记们我们继续杀呀！");
        set_temp("last_chat", time());
        add_temp("total_chat", 1);
    }
}

int accept_fight(object ob)
{
    command("say 东亚病夫也来猖狂，你活得不耐烦了！");
    if (!is_fighting())
        this_object()->set("now_killing", ob->query("id"));
    if (!is_busy())
        exert_function("powerup");
    kill_ob(ob);
    return 1;
}

int accept_hit(object ob)
{
    command("say 东亚病夫也来猖狂，你活得不耐烦了！");
    if (!is_busy())
        exert_function("powerup");
    if (!is_fighting())
        this_object()->set("now_killing", ob->query("id"));
    kill_ob(ob);
    return 1;
}

int accept_touxi(object ob)
{
    command("say 居然偷袭我，你找死！");
    if (!is_fighting())
        this_object()->set("now_killing", ob->query("id"));
    if (!is_busy())
        exert_function("powerup");
    kill_ob(ob);
    return 1;
}

int accept_kill(object ob)
{
    command("say 哼！我正想杀几个人呢！");
    if (!is_fighting())
        this_object()->set("now_killing", ob->query("id"));
    if (!is_busy())
        exert_function("powerup");
    return 1;
}

void unconcious()
{
    die();
}

void die()
{
    object ob, ob1;
    int exp, pot, tihui, weiwang, score, div;
    string gift;
    object item;
    
    string *ob1_list = ({
        "/clone/liandan/qi_sui",
        "/clone/liandan/nei_sui",
        "/clone/liandan/jing_sui",        
    });




    ob = find_player(this_object()->query("now_killing"));
    if (this_object()->query("nation") == "日本") {
        command("chat 八格呀路，我死不瞑目！");
    }
    else if (this_object()->query("nation") == "英国" || this_object()->query("nation") == "美国")
    {
        command("chat Oh,Shit! I don't want to die!");
    }
    else if (random(2) == 0)
    {
        command("chat 天啊，我来中国本是为了发财，想不到今天命丧于此，呜呜呜!");
    }
    else
    {
        command("chat 上帝啊，请接纳我这个有罪的灵魂吧!");
    }

    if (ob)
    {
        switch (query("lvl"))
        {
        case 1:
            pot = 6000;
            break;
        case 2:
            pot = 8000;
            break;
        case 3:
            pot = 12000;
            break;
        case 4:
            pot = 15000;
            break;
        case 5:
            pot = 20000;
            break;
        }

        if (ob->query("combat_exp") > query("combat_exp"))
        {
            div = ob->query("combat_exp") / query("combat_exp");
            if (div > 5)
            div = 5;
            pot /= div;
        }

        
        exp = pot * 2 + random(80);
        pot = pot + random(50);
        tihui = pot / 2 + random(10);
        weiwang = 20 + random(5);
        score = 20 + random(5);

        if (ob->query("potential") >= ob->query_potential_limit()){
            pot = 1;
        }
        if (ob->query("experience") >= ob->query_experience_limit() && tihui > 0) {
            tihui = 1;
        }
if(random(3)==1){
        gift = ob1_list[random(sizeof(ob1_list))];                
        item = new(gift);
        item->move(ob);
       tell_object(ob, HIW "\n你干掉了一名异族联军的" NOR + query("rank") + "，" + HIG "意外获得了" +item->name()+"\n" );
}


        ob->add("combat_exp", exp);
        ob->add("potential", pot);
        ob->add("experience", tihui);

        ob->add("weiwang", weiwang);
        ob->add("score", score);

        tell_object(ob, HIW "\n你干掉了一名异族联军的" NOR + query("rank") + "。\n" + HIG "你获得了" NOR HIR + chinese_number(exp) + HIG "点经验，" NOR HIW + chinese_number(pot) + NOR HIG "点潜能以及" HIY + chinese_number(tihui) + HIG "点实战体会。\n" NOR + HIC "江湖阅历以及威望也都有了不同程度的提高。\n" );
        if (ob->query("waidi/born_time") != this_object()->query("born_time")) {
            ob->delete ("waidi");
            ob->set("waidi/born_time", this_object()->query("born_time"));
            ob->add("waidi/number", 1);
        } else
        {
            ob->add("waidi/number", 1);
        }
    }

    if (!query_last_damage_from())
    ob1 = ob;
    else
    ob1 = query_last_damage_from();

    INVASIOND->set("record/" + query("number") + "/exist", 0);
    INVASIOND->set("record/" + query("number") + "/killer", ob1->query("name") + "(" + ob1->query("id") + ")");
    INVASIOND->add("record/total_killed", 1);
    CHANNEL_D->do_channel(ob1, "chat", "各位国人，我在" NOR HIY +environment()->query("short") + NOR HIR "击毙了" + query("title") + NOR HIG + query("name") + NOR HIW "。"NOR"" );
    if (INVASIOND->query("record/total_killed") >= TOTAL_INVADER)
    INVASIOND->set_reward();
    ::die();
}

int do_leave()
{
    mapping exits;
    string *dirs, dir;
    object room;

    if (!is_fighting() && !is_busy())
    {
        if (time() - query("born_time") > 600)
        {
            command("say 看来战争已经结束了，我还是回国吧。");
            message_vision("$N急急忙忙的走了。\n", this_object());
            INVASIOND->set("record/" + this_object()->query("number") + "/exist", 0);
            destruct(this_object());
            return 0;
        }

        if (!mapp(exits = environment()->query("exits")) ||
            !sizeof(exits))
            return 0;

        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        if (!dir)
            return 0;
        room = find_object(environment()->query("exits/" + dir));
        if (!room)
            room = load_object(""+environment()->query("exits/" + dir)+"");
        if (room->query("no_fight"))
            return 0;
        command("go " + dir);
    }
    return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
