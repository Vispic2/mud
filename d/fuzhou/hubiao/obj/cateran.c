// cateran.c

#include <ansi.h>
inherit "/kungfu/class/generate/chinese";
int do_copy(object ob);

string *title = ({
	"天河帮", "长鲸岛", "神农帮", "巨鲸帮", "海沙派", "青竹帮",
	"龙游帮", "金龙帮", "鄱阳帮", "恶虎沟", "千柳庄"
});

void create()
{
	mapping name;
	int i;
	string *fams;

	name = NPCS_D->get_cn_name();
	set_name(name["name"], name["id"] + ({ "jie fei" }));
	set("title", HIW+title[random(sizeof(title))]+NOR+(i?"":"女")+"帮众");
	set("gender", i?"男性":"女性");
	set("age", 27+random(30));

	set("long","这个拦路的劫匪是"+query("title")+"，满脸伤疤，一脸凶狠而霸道的样子。\n");

	if (random(21) > 5)
		add_money("silver", random(100));

	set("attitude", "peaceful");

	set("combat_exp", 5000000);

	set("str", 20+random(5));
	set("int", 20+random(5));
	set("con", 20+random(5));
	set("dex", 20+random(5));

	set("hubiao_jiefei", 1);

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("max_neili", 20000);
	set("neili", 5000);
	set("neili", 20000);
	set_temp("apply/armor", 100);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("jingli", 20000);
	set("max_jingli", 20000);

	set("no_ansuan",1);
	set("no_bark", 1);
	set("no_quest", 1);
	set("location", 1);

	set_skill("strike", 500);
	set_skill("cuff", 500);
	set_skill("hand", 500);
	set_skill("dodge", 500);
	set_skill("sword", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("blade", 500);
	set_skill("hammer", 500);
	set_skill("club", 500);
	set_skill("staff", 500);
	set_skill("literate", query("int") * 10);
	set_skill("whip", 500);
	set_skill("dagger", 500);
	set("location",1);
	set("no_get", 1);

	setup();
	call_out("dest", 300);
	fams = keys(init_family);
	setup_family(fams[random(sizeof(fams))]);
}

int do_copy(object ob)
{
	mapping skills;
	string *sk;
	object me;
	int lv,exp,i;

	me = this_object();

	exp = ob->query("combat_exp");
	exp = exp / 100 * (100+random(20));

	me->set("max_qi", ob->query("max_qi")*3/2);
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	me->set("max_jing", ob->query("max_jing"));
	me->set("eff_jing", ob->query("max_jing"));
	me->set("jing", ob->query("max_jing"));
	me->set("max_neili", ob->query("max_neili"));
	me->set("neili", ob->query("neili"));
	if( me->query("neili") < me->query("max_neili"))
	me->set("neili", me->query("max_neili"));
	me->set("eff_jingli", ob->query("eff_jingli"));
	me->set("jingli", ob->query("jingli"));
	if( me->query("jingli") < me->query("eff_jingli"))
	me->set("jingli", me->query("eff_jingli"));
	me->set("combat_exp", exp);
	me->set("jiali", me->query_skill("force")/4);
	NPCS_D->init_npc_skill(me,NPCS_D->check_level(me));
}

void init()
{
	object cart,me=this_player();

	::init();
	cart = query_temp("target");
	if (cart && me->query_temp("protecting") == cart) {
		kill_ob(me);
		me->kill_ob(this_object());
	}
}

void kill_ob(object ob)
{
	object me = this_object();

	if(!objectp(me->query_temp("target"))
	|| (me->query_temp("target") != ob->query_temp("protecting"))){
		me->remove_enemy(ob);
		ob->remove_killer(me);
		return;
	}
	::kill_ob(ob);
}

void fight_ob(object ob)
{
	if (!objectp(query_temp("target"))
	|| ob->query_temp("protecting") != query_temp("target")) {
		command("say 走远点，老子正忙着呢。");
		ob->remove_killer(this_object());
	}
	else ::fight_ob(ob);
}

void dest()
{
	object ob = this_object();

	if (environment(ob)) message_vision("$N匆匆忙忙地离开了。\n",ob);
	destruct(ob);
}


void die()
{
int i;
        object ob1,ob2,ob3;
i=random(50);
        if (i>417) {
        ob1 = new("/clone/vip/jiuzhuan");
	ob1->move(environment(this_object()));
        }

        if (i>35) {
        ob3 = new("/clone/shizhe/qiandai");
	ob3->move(environment(this_object()));
        }

        if (i<0) {
        ob2 = new("/clone/vip/jiuzhuan");
	ob2->move(environment(this_object()));
        }
	::die();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
