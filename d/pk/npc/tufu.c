#include <ansi.h>
inherit NPC;
string *random_ob = ({
   "/clone/vip/putao",
   "/clone/vip/fushougao",
   "/clone/shizhe/cjj",
});
void create()
{
	
    set_name(HIM"地狱屠夫"NOR, ( { "tu fu" }));
	set("nickname", "地狱屠夫"NOR);
	set("gender", "男性" );
	set("age", 48);
	set("long", "这是一个杀人不眨眼的屠夫，残暴至极！");
	    set("con",100);
        set("per",100);
        set("str",100);
        set("int",100);
        set("combat_exp",10000000);
        set("max_neili", 1000000);
        set("neili", 1000000);
        set("max_jingli",1000000);
        set("jingli",1000000);
        set("jiali",1000000);
        set("max_qi", 1000000);
        set("qi", 1000000);
        set("eff_qi", 1000000);
        set("max_jing", 1000000);
        set("jing", 1000000);
        set("eff_jing", 1000000);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("unarmed",100);
	setup();
}

int accept_kill(object ob)
{
   
	command("say 受死！！！");
	return 1;
}

int accept_fight(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_hit(object ob)
{

   return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_ansuan(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_touxi(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}

void die()
{
int times;
int exp,pot,mar;
object me,obj;
string id = random_ob[random(sizeof(random_ob))];//随机物品
me=this_object()->query_last_damage_from();
exp=100+random(50);
me->add("combat_exp", exp);
pot=60+random(20);
me->add("potential", pot);
mar=20+random(10);
me->add("experience", mar);	
tell_object(me,"恭喜你杀死了"+name()+"，你获得了："+exp+"点经验，"+pot+"点潜能，"+mar+"点实战！\n");
switch (random(10))
	{
		case 0 : 
		case 5 :
		case 9 :
		new(id)->move(me);
        CHANNEL_D->do_channel(this_object(),"rumor", me->query("name")+"在屠人场中获得了"+id->short()+"。");									
		break;
	}
return ::die();
}

void unconcious()
{
	die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
