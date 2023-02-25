#include <ansi.h>;
inherit "/kungfu/class/generate/chinese";

string *names = ({
	""HIG"神兽玄武",""HIR"神兽朱雀",""HIW"神兽白虎",""HIC"神兽青龙",""HIY"神兽之首麒麟"NOR"",
});

void create()
{
	string *fams;

	set_name("神兽玄武", ({"shenshou",}));
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");

	setup();
	fams = keys(init_family);
	setup_family(fams[random(sizeof(fams))]);
}

int accept_fight(object me)
{
	tell_object(me,"既然来挑战就放开手脚，别畏手畏脚的！\n");
	return 0;
}

void init_data(int level)
{
	object me = this_object();
	mapping smap = me->query_skills();
	int lvl,i;
	string *skills;

	set_name(names[level-1], ({"shenshou",}));

	//神兽的等级与副本env等级关联
	lvl = 100+level*50;

	skills = keys(smap);
	for(i=0;i<sizeof(skills);i++)
	{
		me->set_skill(skills[i],lvl);
	}

	//经验，气血，附加伤害力等与等级关联
	me->set("combat_exp",lvl*lvl/10*lvl+10000);
	me->set_temp("apply/damage",lvl*2);
	me->set("jiali",lvl*2);
	me->set("qi",lvl*30);
	me->set("eff_qi",lvl*30);
	me->set("max_qi",lvl*30);
	me->set("jing",lvl*20);
	me->set("eff_jing",lvl*20);
	me->set("max_jing",lvl*20);
	me->set("neili",lvl*30);
	me->set("max_neili",lvl*30);
}

void die()
{
	int sllv,i,pot,exp,mar,yuanbao;
	object weap,bo,me = this_object();
	object ob,obj;
	string *items,str;
	mapping give;

	//神兽sllv:1-5
	sllv = environment()->query("sllv");

	//随机掉落物品奖励及概率列表掉落概率跟副本等级有关
	give =  ([
		"/clone/shizhe/putao" : (5-sllv)*2,
		"/clone/shizhe/book_tianfu" : (5-sllv)*2,
		"/clone/money/yuanbao" : (15-sllv)*2,
		"/clone/money/yuanbao" : (15-sllv)*2,
		"/clone/shizhe/tianxiang" : (10-sllv)*2,
		"/clone/shizhe/jinsha" : (5-sllv)*2,
		"/clone/shizhe/fushougao" : (10-sllv)*2,
		"/clone/shizhe/tianling" : (5-sllv)*2,
		"/clone/shizhe/dan_chongmai1" : (5-sllv)*2,
		"/clone/shizhe/dan_chongmai2" : (10-sllv)*2,
		"/clone/shizhe/dan_chongmai3" : (20-sllv)*2,
		"/clone/shizhe/book_tianfu2" : (20-sllv)*2,
		"/clone/shizhe/dan_chongmai4" : (30-sllv-sllv)*2,
		"/clone/shizhe/tianling2" : (70-sllv*sllv)*2,
		"/clone/shizhe/putao1" : (80-sllv*sllv)*2,
		"/clone/shizhe/dan_jiuzhuan" : (100-sllv*sllv)*2,
		"/clone/shizhe/butian" : (150-sllv*sllv)*2,
		"/clone/shizhe/tiancs" : (150-sllv*sllv)*2,
		"/clone/shizhe/dan_xixin" : (200-sllv*sllv)*2,
		"/clone/shizhe/tuzhi" : (120-sllv*sllv)*2,
		"/clone/shizhe/dalibao" : (120-sllv*sllv)*2,
		
	]);

	items = keys(give);
	for(i=0;i<sizeof(items);i++)
	{
		if(random(give[items[i]])==0)
		{
			obj = new(items[i]);
			obj->move(environment(this_object()));
		}
	}

	if (objectp(ob = query_last_damage_from()))
	{
		//获得经验和实战，跟副本等级有关
		
		exp = ob->improve_experience(sllv*5000);  //实战
		pot = ob->improve_potential(sllv*5000);		//潜能
	    
		tell_object(ob, sprintf(HIG "你击败"+query("name")+"，获得%s点实战体会、%s点潜能。"NOR"\n",
		chinese_number(exp),chinese_number(pot)));

	}
	destruct(me);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
