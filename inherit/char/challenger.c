// challenge.c
// challenge.c

#include <ansi.h>
#include <command.h>

inherit NPC;
string *diaoluo_list = ({
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao1",
"/clone/vip/cjj",
"/clone/vip/cjj",
"/clone/vip/cjj",
"/clone/vip/dan_jiuzhuan",
"/clone/vip/jiuzhuan1",
"/clone/vip/dan_str",
"/clone/vip/dan_dex",
"/clone/vip/dan_con",
"/clone/vip/dan_int",
	});

object with_ob = 0;

void set_lvl(int lvl)
{
	object me = this_object();
	mapping smap = me->query_skills();
	int i,rqi;
	string *skills;

        lvl=220;

	skills = keys(smap);
	rqi = (random(lvl/12)+10)*1000000;
	for(i=0;i<sizeof(skills);i++)
	{
		me->set_skill(skills[i],lvl);
	}
	/*
	me->set_skill("yinyang-hu",220);
	me->set_skill("yinyang-bao",220);
	me->set_skill("yinyang-shang",220);
	me->set_skill("yinyang-po",220);
	*/
	me->set("combat_exp",lvl*lvl*lvl*lvl/10+10000000);
	me->set("jiali",100);

	me->set("qi",lvl*20000+rqi);
	me->set("eff_qi",lvl*20000+rqi);
	me->set("max_qi",lvl*20000+rqi);

	me->set("jing",999999999);
	me->set("eff_jing",999999999);
	me->set("max_jing",999999999);

	me->set("neili",lvl*10000);
	me->set("gain/2dp",lvl);//抗暴属性

	me->set("max_neili",lvl*10000);
	me->set("str",50);
	me->set("int",50);
	me->set("con",50);
	me->set("dex",50);

}

int get_damage(string id){
	return (int)query("boss/"+id);
}
int sort_damage(string user1,string user2)
{
	return get_damage(user2)-get_damage(user1);
}

varargs int receive_damage(string type, int damage, mixed who)
{
	object me = this_object();
	string id;
	int sjdam;
	sjdam = ::receive_damage(type,damage,who);
	if(objectp(who)){	
		me->add("boss/"+who->query("id"),sjdam);
		me->add("all_recive_damage",sjdam);
	}

	return sjdam;
}


void unconcious()
{
	die();
}

void die()
{
	object ob,diaoluo;
	object story;
	string msg;
	int i,j,expi, poti, weiwangi, scorei, sjs;
	string *items,*killer;
	object obj;
	mapping boss,give;
    int expt,pott,mott;
	if (!objectp(story = "/adm/daemons/bossd"->query_running_story()))
	return;
	story->stop_story();

	msg = query("chat_lost");
	if (! msg) msg = "岂有此理！怎么... 怎么可能会这样？";
	command("chat " + msg);

set("finished", 1);

//伤害统计
	if(! boss=query("boss")) return;

	//killer = keys(boss);
	killer=keys(boss=query("boss"));
	if(! sizeof(killer)) return;

	killer = sort_array(killer, (: sort_damage :) );
	if(! sizeof(killer)) return;

	if(objectp(ob=find_player(killer[0]))){
		CHANNEL_D->do_channel(this_object(), "rumor", ob->name() + "带领群雄打败了" + name() + "，捍卫了中原武林的尊严。");
		expi = random(query("combat_exp") / 10) + 10;
		if(expi>1000000)
		expi = 50000+random(50000);

		poti = random(1000) + 10000;

		weiwangi = random(query("combat_exp") / 5000) + 10;
		if(weiwangi>100000)
		weiwangi = 5000+random(500);
		scorei = random(query("combat_exp") / 5000) + 10;
		if(scorei>100000)
		scorei = 5000+random(500);

		ob->add("combat_exp", expi);
		ob->add("potential", poti);
		ob->add("weiwang", weiwangi);
		ob->add("score", scorei);
		tell_object(ob, sprintf(HIG "你获得了%d点经验、%d点潜能，%d点威望、%d点阅历。"NOR"\n",expi,poti,weiwangi,scorei));
	}


	j = sizeof(killer);
	if(j > 10) j=10;

	msg = "—————————————————————————\n"+HIG+"伤害排行表：(名次：玩家 -->> 伤害值)"NOR"\n";
	for(i=0; i < j; i++)
	{
		if(objectp(ob=find_player(killer[i])))
		{
			msg += "第"+chinese_number(i+1)+"名："+ob->name()+" -->> "+ boss[killer[i]] +"\n";
		}else{
			msg += "第"+chinese_number(i+1)+"名：无名氏 -->> "+ boss[killer[i]] +"\n";
		}
	}
	message_vision(msg + "—————————————————————————\n",this_object());

	if(give = query("die_give2"))
	{
		items = keys(give);
		for(i=0;i<sizeof(items);i++)
		{
			sjs = 1+give[items[i]];
			if((random(sjs)==0) && objectp(ob=find_player(killer[0])))
			{
				obj = new(items[i]);
				obj->move(ob);
				tell_object(ob,HIM"你获得了"+obj->query("name")+"。"NOR"\n");
				CHANNEL_D->do_channel( this_object(), "ic",ob->name()+"抢走了我的"+obj->query("name")+"。");
		
				sjs = 3+give[items[i]];
				if((random(sjs)==0) && sizeof(killer)>1 && objectp(ob=find_player(killer[1])))
				{
					obj = new(items[i]);
					obj->move(ob);
					tell_object(ob,HIM"你获得了"+obj->query("name")+"。"NOR"\n");
					CHANNEL_D->do_channel( this_object(), "ic",ob->name()+"抢走了我的"+obj->query("name")+"。");
			
					sjs = 5+give[items[i]];
					if((random(sjs)==0) && sizeof(killer)>2 && objectp(ob=find_player(killer[2])))
					{
						obj = new(items[i]);
						obj->move(ob);
						tell_object(ob,HIM"你获得了"+obj->query("name")+"。"NOR"\n");
						CHANNEL_D->do_channel( this_object(), "ic",ob->name()+"抢走了我的"+obj->query("name")+"。");
					}
				}
			}
		}
	}

	for(i=0;i<sizeof(killer);i++)
	{
		if(objectp(ob=find_player(killer[i])))
		{
		    mott=boss[killer[i]]/5000+10;
			ob->add("weiwang",mott);

			if (ob->query("combat_exp")<10000000)
			{
				if(boss[killer[i]]/100>100000)
				{
				expt=25000+random(25000);
				ob->add("combat_exp",expt);
				tell_object(ob,HIM"你获得了"+expt+"点经验和"+mott+"点威望。"NOR"\n");
				}
				else
				{
				ob->add("combat_exp",boss[killer[i]]/100);
				tell_object(ob,HIM"你获得了"+boss[killer[i]]/100+"点经验和"+mott+"点威望。"NOR"\n");
				}
			}
			else
			{
				if(boss[killer[i]]/100>100000)
				{
				expt=25000+random(25000);
				ob->add("combat_exp",expt);
				tell_object(ob,HIM"你获得了"+expt+"点经验和"+mott+"点威望。"NOR"\n");
				}
				else
				{
				ob->add("combat_exp",boss[killer[i]]/200);
				tell_object(ob,HIM"你获得了"+boss[killer[i]]/200+"点经验和"+mott+"点威望。"NOR"\n");
				}
			}
	    diaoluo = new(diaoluo_list[random(sizeof(diaoluo_list))]);
		diaoluo->set_amount(1);
		diaoluo->move(ob);
        tell_object(ob,HIM"恭喜你获得了一"+ diaoluo->name()+"奖励。"NOR"\n");
		}
	}
	"/adm/daemons/hongbaod.c"->boss_hb();
	//发送红包
}

void win()
{
	object story;
	string msg;

	if (sizeof(query_enemy()))
		return;

	if (! objectp(story = "/adm/daemons/bossd"->query_running_story()))
		return;

	story->stop_story();
	command("chat* haha");
	msg = query("chat_win");
	if (! msg) msg = "中原武林，不堪一击！";
	command("chat " + msg);
	set("finished", 1);
	call_out("destruct", 0, this_object());
	::win();
}




/*
#include <ansi.h>
#include <command.h>

inherit NPC;

object with_ob = 0;

void set_lvl(int lvl)
{
    object me = this_object();
	mapping smap = me->query_skills();
	int i,rqi;
	string *skills;

    lvl=220;
	rqi = (random(lvl/12)+10)*1000000;
	skills = keys(smap);
	for(i=0;i<sizeof(skills);i++)
	{
		me->set_skill(skills[i],lvl);
	}
	
	me->set("combat_exp",lvl*lvl*lvl*lvl/10+10000000);
	me->set("jiali",100);

	me->set("qi",lvl*20000+rqi);
	me->set("eff_qi",lvl*20000+rqi);
	me->set("max_qi",lvl*20000+rqi);

	me->set("jing",999999999);
	me->set("eff_jing",999999999);
	me->set("max_jing",999999999);

	me->set("neili",lvl*10000);
	me->set("gain/2dp",lvl);//抗暴属性

	me->set("max_neili",lvl*10000);
	me->set("str",50);
	me->set("int",50);
	me->set("con",50);
	me->set("dex",50);
}

varargs int receive_damage(string type, int damage, mixed who)
{
	object me = this_object();

	if(objectp(who))
	{
		me->add("boss/"+who->query("id"),damage);
		me->add("all_recive_damage",damage);
	}

	if(me->query("qi")*2 < me->query("max_qi")&&me->query_temp(""))
	{
		message_vision("$N惨叫一声，吐出一口鲜血，好像从身上掉下来了一些什么东西。。。\n", me);
	}

	return ::receive_damage(type,damage,who);
}

void die()
{
	object ob;
	object story;
	string msg;
	int expi, poti, weiwangi, scorei;
	int i;
	string *items,*killer;
	object obj;
	mapping boss,give;

	if (! objectp(ob = query_last_damage_from()))
		return;

	if (! objectp(story = "/adm/daemons/bossd"->query_running_story()))
		return;

	story->stop_story();
	msg = query("chat_lost");
	if (! msg) msg = "岂有此理！怎么... 怎么可能会这样？";
	command("chat " + msg);
	CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name() + "打败了" + name() + "，捍卫了中原武林的尊严。");

//最后一击
	expi = random(query("combat_exp") / 100) + 1000;
	poti = random(2000) + 5000;
	weiwangi = random(query("combat_exp") / 1000) + 10;
	scorei = random(query("combat_exp") / 1000) + 10;
    if (ob->query("combat_exp")>10000000) expi /= 2;
	ob->add("combat_exp", expi);
	ob->add("potential", poti);
	ob->add("weiwang", weiwangi);
	ob->add("score", scorei);

	tell_object(ob, sprintf(HIG "你获得了%s点经验、%s点潜能，并增加了%s点威望、%s点江湖阅历。"NOR"\n",
			chinese_number(expi),chinese_number(poti),
			chinese_number(weiwangi),chinese_number(scorei)));
	set("finished", 1);


//伤害统计
	killer = keys(boss=query("boss"));
	if(give = query("die_give2"))
	{
		items = keys(give);
	}
	for(i=0;i<sizeof(killer);i++)
	{
		if(objectp(ob=find_player(killer[i])))
		{
			message_vision("$N累计对boss造成"+ boss[killer[i]] +"点伤害。\n", ob);
			//by name 如果伤害大于100w当100w来算，防止出现bug等情况。
			if(boss[killer[i]]>1000000){
			boss[killer[i]]=1000000;			
			}
			//log_files("boss_give", sprintf("%s：对boss造成 %d      点伤害，ID="+ob->query("id")+"。\n",ctime(time()),boss[killer[i]]));
			ob->add("weiwang",boss[killer[i]]/100);
            if (ob->query("combat_exp")<10000000){   //经验小于1千w，奖励增加否则减少。
            ob->add("combat_exp",boss[killer[i]]/5);
            }else{
            ob->add("combat_exp",boss[killer[i]]/10);
            }
            
            if (ob->query("combat_exp")<10000000){   //经验小于1千w，奖励增加否则减少。
            ob->add("potential",boss[killer[i]]/30);
            }else{
            ob->add("potential",boss[killer[i]]/50);
            }
            
            
            
			if(give&&present(ob,environment(this_object())))
			{
				int j;
				for(j=0;j<sizeof(items);j++)
				{
					if(random(give[items[j]])==0&&random(query("all_recive_damage"))<boss[killer[i]])
					{
						obj = new(items[j]);
						obj->move(ob);
						tell_object(ob,HIM"你获得了"+obj->query("name")+"。"NOR"\n");
						CHANNEL_D->do_channel( this_object(), "ic",ob->query("name")+"抢走了我的"+obj->query("name")+"。");
						//log_files("boss_give", sprintf("%s："+ob->query("id")+"得到了%s。\n",ctime(time()),obj->query("name")));
					}
				}
			}
            if (ob->query("combat_exp")<10000000)
			tell_object(ob,HIM"你获得了"+boss[killer[i]]/5+"点经验和"+boss[killer[i]]/30+"点潜能和"+boss[killer[i]]/100+"点威望。"NOR"\n");
            else tell_object(ob,HIM"你获得了"+boss[killer[i]]/10+"点经验和"+boss[killer[i]]/50+"点潜能和"+boss[killer[i]]/100+"点威望。"NOR"\n");
		}
	}
//掉落物品
	if(give = query("die_give"))
	{
		items = keys(give);
		for(i=0;i<sizeof(items);i++)
		{
			if(random(give[items[i]])==0)
			{
				obj = new(items[i]);
				obj->move(environment(this_object()));
			}
		}
	}

	call_out("destruct", 0, this_object());
}

void win()
{
	object ob;
	object story;
	string msg;

	if (sizeof(query_enemy()))
		return;

	if (! objectp(story = "/adm/daemons/bossd"->query_running_story()))
		return;

	story->stop_story();
	command("chat* haha");
	msg = query("chat_win");
	if (! msg) msg = "中原武林，不堪一击！";
	command("chat " + msg);
	set("finished", 1);
	call_out("destruct", 0, this_object());
	::win();
}
*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
