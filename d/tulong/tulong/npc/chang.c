#include <ansi.h>
inherit NPC;

void create()
{
	object jing,dao;
	set_name("常金鹏", ({ "chang jinpeng", "chang" }) );
	set("long", "这便是天鹰教朱雀坛的坛主常金鹏。\n"
		    "五十来岁年纪，脸上手上的肌肉凹凹凸凸、盘根错节。\n");
	set("attitude", "heroism");
	set("title", "天鹰教");
	set("nickname", HIR "朱雀坛坛主" NOR);
	set("age", 52);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		"常金鹏喝道：恶贼还不放手？\n",
		"常金鹏喝道：恶贼不得无礼！\n",
		(: perform_action, "hammer.poli" :),
	}) );

	set("per", 20);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	
	set("max_qi", 5500);
	set("max_jing", 2000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 200);
	set("combat_exp", 2000000);

	set_skill("force", 200+random(50));
	set_skill("longxiang-gong", 200+random(50));
	set_skill("dodge", 200+random(50));
	set_skill("shenkong-xing", 200+random(50));
	set_skill("cuff", 200+random(50));
	set_skill("yujiamu-quan", 200+random(50));
	set_skill("hand", 200+random(50));
	set_skill("dashou-yin", 200+random(50));
	set_skill("parry", 200+random(50));
	set_skill("hammer", 200+random(50));
	set_skill("riyue-lun", 200+random(50));

	map_skill("force", "longxiang-gong");
	map_skill("dodge", "shenkong-xing");
	map_skill("cuff", "yujiamu-quan");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "riyue-lun");
	map_skill("hammer", "riyue-lun");

	prepare_skill("hand", "dashou-yin");
	prepare_skill("cuff", "yujiamu-quan");

	set_temp("apply/attack", 80+random(80));
	set_temp("apply/defense", 80+random(80));
	set_temp("apply/armor", 80+random(80));
	set_temp("apply/damage", 80+random(80));

	setup();

	carry_object("/d/tulong/tulong/npc/obj/jiaofu")->wear();
	carry_object("/d/tulong/tulong/npc/obj/hammer")->wield();
	
	dao = find_object("/d/tulong/obj/tulongdao");
	jing = find_object("/d/tulong/obj/zhenjing");

	if (clonep()&&(!dao||!environment(dao)) && (!jing||!environment(jing))) {
		if(!dao) dao = load_object("/d/tulong/obj/tulongdao");
		dao->move(this_object());
	}
}

int accept_ansuan(object who)
{
	return notify_fail("你刚想暗算，可是只见会场里黑压压的挤满了人，根本看不清楚。\n");
}

void init()
{
	object env;
	add_action("do_bi","bi");
	add_action("do_get","get");
	remove_call_out("put");
	call_out("put",3);
}

void put()
{
	object obj,obj2, *ob_list;
	obj = present("tulong blade",this_object());
	obj2 = present("ding", environment());
		
	if (	!obj && !present("tulong blade", obj2) )
	{
		message_vision(HIC "\n$N哈哈一笑，道：“你来晚了，屠龙刀早已被人拿走了。”"NOR"\n", this_object());
	}
	else
	if (objectp(obj) && objectp(obj2)) 
	{
		obj->move(obj2);
		message_vision(HIC "\n$N哈哈一笑，手一挥，将那屠龙宝刀掷进了烈焰冲天的大铁鼎中。"NOR"\n",this_object());
	}
	obj = present("tulong blade",this_object());
	if (objectp(obj)) destruct(obj);
}

int do_get(string arg)
{
	object obj = this_object();
	string what, where;

	if(!arg)
	return 0;	
	if(sscanf(arg, "%s from %s", what, where) != 2)
	return 0;

	if(what == "tulong blade"||what == "blade"||what == "dao"||what == "tulong" || where =="ding")
	{
		message_vision(CYN "$N对$n大喝一声：大胆！竟敢打宝刀的主意！"NOR"\n",obj,this_player());

		message_vision(CYN "$N对$n喝道：先过我这一关。"NOR"\n",obj,this_player());
		if (!obj->query_temp("bishi"))
		{
			obj->set_temp("bishi", 1);
			this_player()->set_temp("bishi", 1);
		}
            if (!this_player()->query_temp("bishi")) this_player()->set_temp("bishi", 1);
		obj->kill_ob(this_player());
		this_player()->kill_ob(obj);
		return 1;
	}

	return 0;
}

int do_bi()
{
	object obj = this_object();
	message_vision(CYN "$N对$n大喝一声：那我们就比试比试！来吧。"NOR"\n",obj,this_player());
      if (!this_player()->query_temp("bishi")) this_player()->set_temp("bishi", 1);
	obj->kill_ob(this_player());
	this_player()->kill_ob(obj);
	return 1;
}

int accept_fight(object me)
{
	object obj = this_object();
	command("say 他奶奶的，要打架吗？正合老子心意！\n");
	this_player()->kill_ob(obj);
	kill_ob(me);
	return 1;
}

int accept_hit(object me)
{
	object obj = this_object();
	command("say 他奶奶的，要打架吗？正合老子心意！\n");
	this_player()->kill_ob(obj);
	kill_ob(me);
	return 1;
}

int accept_kill(object me)
{
	object obj = this_object();
	command("say 他奶奶的，要打架吗？正合老子心意！\n");
	this_player()->kill_ob(obj);
	kill_ob(me);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
