#include <ansi.h>
inherit NPC;
private int copy_skill(object me, object ob);
private void init_player(object me);
string *random_ob = ({      
   "/clone/shizhe/putao",  //葡萄
   "/clone/shizhe/dan_chongmai1",  //下品冲脉丹
   "/clone/shizhe/jinsha",    //金砂
   "/clone/shizhe/book_wuliang", //无良经书
   "/clone/shizhe/book_tianfu",     //初级天赋书
    "/clone/shizhe/cagate", //玛瑙残片
    "/clone/shizhe/ccrystal",  //水晶残片
    "/clone/shizhe/cjade",   //翡翠残片
    "/clone/shizhe/cdiamond",   //钻石碎粒
      "/clone/shizhe/cagate", //玛瑙残片
    "/clone/shizhe/ccrystal",  //水晶残片
    "/clone/shizhe/cjade",   //翡翠残片
    "/clone/shizhe/cdiamond",   //钻石碎粒
     "/clone/shizhe/cjj",   //高级抽奖卷
     "/clone/shizhe/shimenka",   //高级抽奖卷
});

void create()
{
	set_name(HIR"火麒麟"NOR,({"huoqi lin"}));
	set("gender", "野兽");
	set("long", HIR"这是一只火麒麟，实力忽强忽弱，令人难以琢磨，务必小心！\n"NOR);
	set("combat_exp",999999);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("max_neili", 200000);
	set("neili", 200000);
	set("eff_qi", 200000);
	set("max_qi", 200000);
	set("qi", 200000);
	set("max_jing", 200000);
	set("jing", 200000);
	set("max_jingli", 200000);
    set("eff_jingli", 200000);
 	set("jingli", 200000);
	set("dex", 20);
	set("no_look",1);
	set("no_touxi",1);			
	set("qi_no",1);
	setup();
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


int accept_kill(string arg)
{
    
	object ob=this_object();
	object me=this_player();
	object kill=this_object();
	int room;
	object where = environment(me);
    if (me->is_fighting())
	return notify_fail("你正在战斗呢。\n");
	if (me->is_busy())
	return notify_fail("你正在战斗呢。\n");
	me->set("dizhi/qilin",where);
	me->set("npc/npc",1);
	write("地址:"+me->query("dizhi/qilin")+"\n");
	if(query("zd") >= 3)
	{	
		destruct(ob);	
		return 0;
	}
	else
	{
	kill=new("/d/aaa/npc/qilin");
	copy_skill(kill,me);
	kill->set("no_look",0);
	init_player(me);
	room=new("/fuben/room/qilindong");	
	kill->move(room);
	me->move(room);
	kill_ob(me);
	me->kill_ob(kill);
	add("zd",1);
	write("请小心！战斗开始！\n");
	return 1;
	}
	return 1;
}
void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer=this_player(),ob;	
	int exp,pot,com,yuanbao,yuanbaos;
	if (objectp(killer = query_last_damage_from()))
	{
	com=100000+random(100);
	pot=80000+random(50);
	exp=30000+random(30);
	yuanbaos=1+random(2);
	killer->add("combat_exp",com);
	killer->add("potential",pot);
	killer->add("experience",exp);
	killer->add("yuanbaos",yuanbaos);	
	killer->move(killer->query("dizhi/qilin"));
	tell_object(killer,"你杀死"+name()+"，获得了("+com+")点经验，("+pot+")潜能，("+exp+")实战，("+yuanbaos+")元宝票。\n");
	}	
	switch (random(10))
	{
		case 5 :
		new(id)->move(killer);
        CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在【麒麟洞】获得了"+id->short()+"。");									
		break;
	}
    	::die();
    }
    
void unconcious()
{
	die();
}

private int copy_skill(object me, object ob)
{
	mapping hp_status, skill_status, map_status, prepare_status;
	mapping my;
	string *sname, *mname, *pname;
	int i, temp;

	if (mapp(skill_status = me->query_skills()))
	{
		skill_status = me->query_skills();
		sname = keys(skill_status);

		temp = sizeof(skill_status);
		for (i = 0; i < temp; i++)
			me->delete_skill(sname[i]);
	}

	if (mapp(skill_status = ob->query_skills()))
	{
		skill_status = ob->query_skills();
		sname = keys(skill_status);

		for (i = 0; i < sizeof(skill_status); i++)
			me->set_skill(sname[i], skill_status[sname[i]]);
	}
	
	if (mapp(map_status = me->query_skill_map()))
	{
		mname = keys(map_status);

		temp = sizeof(map_status);
		for (i = 0; i < temp; i++)
			me->map_skill(mname[i]);
	}

	if (mapp(map_status = ob->query_skill_map()))
	{
		mname = keys(map_status);

		for(i = 0; i < sizeof(map_status); i++)
			me->map_skill(mname[i], map_status[mname[i]]);
	}

	if (mapp(prepare_status = me->query_skill_prepare()))
	{
		pname = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i = 0; i < temp; i++)
			me->prepare_skill(pname[i]);
	}

	if (mapp(prepare_status = ob->query_skill_prepare()))
	{
		pname = keys(prepare_status);

		for(i = 0; i < sizeof(prepare_status); i++)
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
	}

	hp_status = ob->query_entire_dbase();
	my = me->query_entire_dbase();

	my["str"] = hp_status["str"];
	my["int"] = hp_status["int"];
	my["con"] = hp_status["con"];
	my["dex"] = hp_status["dex"];

	my["max_qi"]     = hp_status["max_qi"];
	my["eff_qi"]     = hp_status["eff_qi"];
	my["qi"]	 = hp_status["qi"];
	my["max_jing"]   = hp_status["max_jing"];
	my["eff_jing"]   = hp_status["eff_jing"];
	my["jing"]       = hp_status["jing"];
	my["max_neili"]  = hp_status["max_neili"];
	my["neili"]      = hp_status["neili"];
	my["jiali"]      = hp_status["jiali"];
	my["combat_exp"] = hp_status["combat_exp"];

	me->reset_action();
	return 1;
}

private void init_player(object me)
{
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
	me->set_override("die", (: call_other, __FILE__, "check_out" :));	
}

int check_out(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	tell_object(me, HIR "\n你觉得眼前一片模糊，"+name()+HIR"消失再了你面前！"NOR"\n");
	me->move(me->query("dizhi/qilin"));
	if(me->is_busy())
	me->interrupt_me(me,me->query_busy());
	if (! living(me))
	me->revive();
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
