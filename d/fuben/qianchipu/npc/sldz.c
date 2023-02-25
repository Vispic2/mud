#include <ansi.h>;
inherit "/kungfu/class/generate/chinese";

void create()
{
	string *fams;

	set_name("试炼弟子", ({"shilian dizi",}));
	set("gender", "男性");
	set("age", 125);
	set("attitude", "peaceful");

	setup();
	fams = keys(init_family);
	setup_family(fams[random(sizeof(fams))]);
}

int accept_fight(object me)
{
	tell_object(me,"你这样畏手畏脚的如何能适应这里的修炼？\n");
	return 0;
}

void init()
{
	object me = this_object();
	mapping smap = me->query_skills();
	int i;
	string *skills;
	int lvl = environment()->query("sllv")*10;

	skills = keys(smap);
	for(i=0;i<sizeof(skills);i++)
	{
		me->set_skill(skills[i],lvl);
	}

	me->set("combat_exp",lvl*lvl/12*lvl+12000);
	me->set_temp("apply/damage",120+lvl/2);
	me->set_temp("apply/unarmed_damage",120+lvl/2);
	me->set("jiali",lvl);
	me->set("qi",lvl*32);
	me->set("eff_qi",lvl*32);
	me->set("max_qi",lvl*32);
	me->set("jing",lvl*32);
	me->set("eff_jing",lvl*32);
	me->set("max_jing",lvl*32);
	me->set("neili",lvl*32);
	me->set("max_neili",lvl*32);
}

void die()
{
	int m,sllv,i,pot,exp,lvl;
	object weap,bo,me = this_object();
	object *inv,ob,obj;
	string *items,str;
	mapping give;

	sllv = environment()->query("sllv");

	give =  ([
		//"/clone/shizhe/book_tianfu" : 20+sllv/5,
		"/clone/shizhe/dan_chongmai1" : 20+sllv/5,
		"/clone/shizhe/jinsha" : 20+sllv/5,
	//	"clone/money/yuanbao" : 30+sllv/5,
	]);

	if (objectp(ob = query_last_damage_from())&&environment(me)==environment(ob))
	{
		items = keys(give);
		for(i=0;i<sizeof(items);i++)
		{
			if(random(100)<give[items[i]])
			{
				obj = new(items[i]);
				obj->move(environment(this_object()));
			}
		}

		exp = ob->improve_experience(random(100) + sllv*8);
		pot = ob->improve_potential(random(100) + sllv*6);

		tell_object(ob, sprintf(HIG "你击败"+query("name")+"，获得了%s点潜能、%s点实战体会。"NOR"\n",
				chinese_number(pot),chinese_number(exp)));

		ob->add("qianchi", 1);
		if(!ob->query("qianchilv")||ob->query("qianchilv")<ob->query("qianchi"))
		ob->set("qianchilv",ob->query("qianchi"));

		lvl = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333))/10;
		if((ob->query("qianchi")-lvl)>70)
		ob->force_me("slover1");
		else
		environment()->nextlv(3);
		destruct(me);
	}
	else
	{
		inv = all_inventory(environment());
		for(i=0;i<sizeof(inv);i++)
		{
			if(playerp(inv[i]))
				inv[i]->move("/d/fuben/qianchipu/qianchipu");
		}
		destruct(environment());
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
