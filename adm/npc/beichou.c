#include <ansi.h>

inherit NPC;
/*
inherit F_DEALER;
inherit F_UNIQUE;
mixed ask_cancel();
*/
void create()
{
        set_name("北丑", ({ "bei chou", "bei", "chou", "xizi" }));
        set("long", @LONG
这是一个身着戏子打扮的瘦小老头，长得尖嘴
猴腮，天生一副奸相。谁人能知这便是当今武
林中号称「南贤北丑」戏子北丑。虽其排名在
南贤之下，但却也是南贤生平最畏惧之人。
LONG);
        set("nickname", HIW "北戏子" NOR);
        set("title", HIC "武林泰斗" NOR);
        set("gender", "男性" );
        set("age", 68);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("combat_exp", 12000000);


       

        set("chat_chance", 1);
        set("chat_msg",({
                CYN "北丑嘻嘻道：戏子我没别的本事，就会打听消息，就算是巫师造谣，俺也能知道。\n" NOR,
                CYN "北丑亮出一指道：便宜啊，几两银子就能查条谣言，这可真是跳楼价。\n" NOR,
                CYN "北丑贼眯眯的说：天算地算不如人算，可是再怎么算戏子我都知道。\n" NOR,
        }));

        set_skill("dodge", 500);
        set_skill("unarmed", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("sword", 500);
        set_skill("poison", 500);
        set_skill("medical", 500);
        set_skill("hand", 500);
        set_skill("strike", 500);
        set_skill("staff", 500);
        set_skill("finger", 500);
        set_skill("claw", 500);
        set_skill("blade", 500);
        set_skill("pixie-jian", 500);
        set_skill("literate", 500);
        set_skill("taoism", 500);
        set_skill("buddhism", 500);
        set_skill("jiuyang-shengong", 500);
        set_skill("lingbo-weibu", 500);
        set_skill("qiankun-danuoyi", 500);
        set_skill("xuanming-zhang", 500);
        set_skill("jiuyin-baiguzhao", 500);
        set_skill("lonely-sword", 500);
        set_skill("qianzhu-wandushou", 500);
        set_skill("ranmu-daofa", 500);
        set_skill("dagou-bang", 500);
        set_skill("shaolin-yishu", 500);
        set_skill("wudu-qishu", 500);
        set_skill("throwing", 500);
        set_skill("mantian-xing", 500);
        set_skill("idle-force", 500);
        set_skill("sad-strike", 500);

        map_skill("unarmed", "sad-strike");
        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "lingbo-weibu");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("hand", "qianzhu-wandushou");
        map_skill("strike", "xuanming-zhang");
        map_skill("claw", "jiuyin-baiguzhao");
        map_skill("sword", "dugu-jiujian");
        map_skill("blade", "ranmu-daofa");
        map_skill("staff", "dagou-bang");
        map_skill("throwing", "mantian-xing");
        map_skill("poison", "wudu-qishu");
        map_skill("medical", "shaolin-yishu");

        prepare_skill("unarmed", "sad-strike");

        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: perform_action, "sword.po" :),
                (: perform_action, "blade.zhenyan" :),
                (: perform_action, "blade.huo" :),
                (: perform_action, "staff.wugou" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "unarmed.xiao" :),
                (: perform_action, "parry.nuoyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "throwing.shan" :),
                (: perform_action, "hand.zhugu" :),
                (: perform_action, "strike.wuji" :),
                (: perform_action, "finger.six" :),
                (: perform_action, "finger.zhongheng" :),
                (: perform_action, "claw.zhua" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "heal" :),
                (: exert_function, "dispel" :),
                (: exert_function, "regenerate" :),
        }));

        setup();
        carry_object("d/city/obj/cloth")->wear();


      
       // set_temp("bomb_count", 1);
}

/*

mixed accept_ask(object ob, string topic)
{
        object fob;

        if (topic == ob->query("id"))
        {
                command("laugh " + topic);
                return 1;
        }

        fob = find_player(topic);
        if (! fob || ! ob->visible(fob)) fob = find_living(topic);
        if (! fob || ! ob->visible(fob) || ! environment(fob))
                return;

        if (fob->query("ask_cheap") >= 1)
        {
                ob->set_temp("pending/ask_beichou", topic);
                ob->set_temp("pending/ask_value", 1000);
                message_vision(CYN "$N" CYN "皱了皱眉头，对$n" CYN "摇摇"
                               "头道：看来你这次确实是遇到了困难，收你十"
                               "两白银就是了。\n" NOR, this_object(), ob);
                return 1;
        } else
        {
                ob->set_temp("pending/ask_beichou", topic);
                ob->set_temp("pending/ask_value", 100000);
                message_vision(CYN "$N" CYN "嘿嘿奸笑两声，对$n" CYN "小"
                               "声道：没有问题，不过得要十两黄金，不二"
                               "价！\n" NOR, this_object(), ob);
                return 1;
        }
}



mixed ask_cancel()
{
        object me = this_player();
        int t = uptime();

        if (me->is_busy() || me->is_fighting())
                return "等你忙完了再说吧！\n";

        if (! me->query("quest"))
                return "走开，别捣乱！\n";

        if (t > 900)
                return "走开，你早干什么去了？\n";

        me->delete("quest");

        return "好了！\n";
}
*/
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
