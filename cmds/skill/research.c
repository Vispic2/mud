// research.c

#include <skill.h>
#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;
#include <dbase.h>

mapping learned;
int *query_scale(string skill);

void create() { seteuid(getuid()); }

void auto_research(object me,string skill,int times)
{
	if(!me||!me->query_temp("pending/auto_research"))
		return;

	if(me->is_busy())
		call_out("auto_research",1,me,skill,times);

	else if(me->query("neili")<500)
	{
                me->force_me("use huxin dan");
                me->force_me("exert regenerate");
                me->force_me("exert recover");
		me->force_me("dazuo "+me->query("max_qi")/2);
		call_out("auto_research",10,me,skill,times);
	}

	else if( (int)me->query("jing") < me->query("eff_jing"))
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < me->query("eff_jing"))
			{
				tell_object(me,"精神不足，等待恢复中。。。\n");
				call_out("auto_research",10,me,skill,times);
			}
			else
			{
				call_out("auto_research",1,me,skill,times);
			}
		}
		else
		{
			tell_object(me,"精神不足，等待恢复中。。。\n");
			call_out("auto_research",10,me,skill,times);
		}
	}
	else
	{
		tell_object(me,"托管中，继续研究。。。。。。\n");
		tell_object(me,ZJFORCECMD("research "+skill+" "+times));
	}
}

int main(object me, string arg)
{
	object where = environment(me);
	string skill, skill_name;
	int jing_cost, times;
	int is_force_skill;
	int is_parry_skill;
	int lvl;
	string *ks;
	int *ls, *scale;
	int improve;
	int i;
	int lvls;
	int ndjs;
	int xuyao;
	int t = time();

	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (t == me->query_temp("time/research"))
		return notify_fail("你刚刚才研究过（如果你要连续研究，可以指明研究的次数）。\n");

	if (environment(me)->query("no_learn") || environment(me)->query("no_fight"))
		return notify_fail("这里太纷杂，你没法作研究。\n");

	if (! arg)
		return notify_fail("research|yanjiu <技能> <次数>\n");
/*
	if (sscanf(arg, "%s %d", skill, times) != 2)
	{
		skill = arg;
		return notify_fail(INPUTTXT("请输入研究次数：","yanjiu "+arg+" $txt#")+"\n");
	}
	*/
		if (sscanf(arg, "%s %d", skill, times) != 2)
	{
		skill = arg;
		return notify_fail(INPUTTXT("请输入研究次数：","yanjiu "+arg+" $txt#")+"\n"+
			ZJOBACTS2+ZJMENUF(3,3,9,31)"提升100级:research_100 "+skill+ZJSEP+
			"提升10级:research_10 "+skill+ZJSEP+
			"提升1级:research_1 "+skill+"\n");
	}
	if (times < 1 || times > 10000)
		return notify_fail("研究次数最少1次，最多也不能超过10000次。\n");

lvls=times;

	if (me->is_fighting())
		return notify_fail("临阵磨枪？来不及啦。\n");

	if (! (lvl = me->query_skill(skill, 1)))
		return notify_fail("这项技能你还不会，研究什么？\n");

	if ((string) SKILL_D(skill)->type() == "knowledge")
		return notify_fail(to_chinese(skill) + "只能靠你学习才能提高的。\n");

	if (lvl < 180)
		return notify_fail("你对" + to_chinese(skill) + "的掌握程度还未到研究的程度。\n");

//	notify_fail("依你目前的能力，没有办法研究这种技能。\n");
	if (! SKILL_D(skill)->valid_learn(me) ||
	    ! SKILL_D(skill)->valid_research(me))
		// 不能学习或是不能研究
		return 0;

	if (! XUE_CMD->can_learn(me, skill))
		return 0;

	if ((me->query("potential") - me->query("learned_points")) < times)
		return notify_fail("你的潜能不够研究这么多次了。\n");

	// Lookup skills for relation skills

	write(HIG "你开始研究" + chinese_number(times) + "次有关「" +
	      to_chinese(skill) + "」的奥秘。"NOR"\n");
	message("vision", me->name() + "在冥神思索。\n", where, ({ me }));

	// calculate the basic effect
	is_force_skill = SKILL_D(skill)->valid_enable("force");
	is_parry_skill = SKILL_D(skill)->valid_enable("parry") && (! is_force_skill);
	ks = keys(me->query_skills());
	ls = ({ });
	for (i = 0; i < sizeof(ks); i++)
	{
		mapping action;
		int eff;

		if (ks[i] == skill) continue;
		if (SKILL_D(ks[i])->main_skill() &&
		    SKILL_D(ks[i])->main_skill() != ks[i]) continue;
		if (SKILL_D(skill)->valid_enable(ks[i]))
			ls += ({ me->query_skill(ks[i], 1) });
		if (SKILL_D(ks[i])->valid_enable(skill) ||
		    is_force_skill && SKILL_D(ks[i])->valid_enable("force"))
		{
			// Relation skill
			action = SKILL_D(ks[i])->query_action(me, 0);
			eff = (int)me->query_skill(ks[i], 1);
			if (action)
			{
				// do more effect
				eff += (action["force"] + action["damage"] +
					action["attack"] + action["parry"] +
					action["dodge"]) * eff / 1000;
			}
				
			ls += ({ eff });
		}
	}
	ls = sort_array(ls, -1);
	scale = query_scale(skill);
	improve = 0;
	for (i = 0; i < sizeof(ls) && i < sizeof(scale); i++)
		improve += ls[i] * scale[i];
	improve = improve / 10 / (100 + SKILL_D(skill)->difficult_level()) +
		  me->query("int") / 2;
	improve += lvl / 30;
	improve += improve * where->query("research_improve") / 100;
	if (lvl > 500)
		improve /= lvl / 100 - 5 + 2;
	if (me->query("int") >23)
		improve += improve*(me->query("int")-23)*4/300;
	if (improve < 2)
		improve = 2;
		
			
			
	jing_cost = 0 / (int)me->query("int");

	if ((int)me->query("eff_jing") < jing_cost)
		return notify_fail("你觉得你精力不济，实在没有办法进行研究。\n");

	if (! me->can_improve_skill(skill))
	{
		write("也许是缺乏实战经验，你感到难以继续研究" +
		      to_chinese(skill) + "的问题了。\n");
		return 1;
	}

	me->set_temp("time/research", t);
	for (i = 0; i < times; i++)
	{
    		if ((int)me->query("jing") < jing_cost)
		{
			if (me->query("env/auto_regenerate") &&
			    SKILL_D("force/regenerate")->exert(me, me))
			{
				// try to regenerate & learn again
				write("你觉得精神好了一些，继续进行研究。\n");
				i--;
				continue;
			} else
			{
				me->set("jing", 0);
				break;
			}
		}
		me->receive_damage("jing", jing_cost);

		if (! i)
		{
			skill_name = SKILL_D(skill)->query_skill_name(lvl);
			if (skill_name){
	
				write(sprintf(HIM "你研究了一会，对「%s」这一"  "招似乎想通了些什么。"NOR"\n", skill_name)); 
				}else{
				
				//tell_object(me,ZJFORCECMD("research "+skill+" "+lvls));
				write(sprintf(HIM "你研究了一会，似乎对「%s」有些新的领悟。"NOR"\n",   to_chinese(skill)));
				
				}
		}
		
		
	    if(where->query("guibing_room")){
		me->improve_skill(skill, ((improve-1)/2)*2);
		}else{		
		me->improve_skill(skill, (improve-1)/2);	
		}
		/*
		if(me->query("id")=="name"){
		ndjs=(improve-1)/2;
		xuyao=((me->query_skill(skill,1)+1)*(me->query_skill(skill,1)+1))-me->query_learned()[skill];
	    xuyao=xuyao/(1+ndjs*100/(lvl+100));
		//tell_object(find_player("name"),"每潜能："+(improve-1)/2+" 熟练度："+(1+ndjs*100/(lvl+100))+" \n 需要潜能："+xuyao+" 目标熟练度："+((me->query_skill(skill,1)+1)*(me->query_skill(skill,1)+1))+" 已有熟练度："+me->query_learned()[skill]+"\n");
		}
		*/
		me->add("learned_points", 1);              //     amount = 1 + amount * 100 / (lvl + 100);  learned[skill] > (skills[skill] + 1) * (skills[skill] + 1))
	}

	if (! i && times==0 )
		write("你今天太累了，结果什么也没有研究成。\n");
	else
	if (i >= 0 && i < times) {
		write("你觉得太累了，研究了" + chinese_number(i) + "次后只好停下来休息。\n");
	        me->set_temp("pending/auto_research",1);
		call_out("auto_research",1,me,skill,times-i);
}

	return 1;
}

int *query_scale(string skill)
{
	if (SKILL_D(skill)->valid_enable("force")) skill = "force";
	switch (skill)
	{
	case "parry": return ({ 5, 20, 140, 70, 50, 30, 10, 5, 4, 3, 2, 1 });
	case "dodge": return ({ 80, 100, 30, 10, 8, 5, 2, 1 });
	case "force": return ({ 150, 120, 50, 40, 20, 8, 5, 2, 1 });
	default:      return ({ 80, 120, 90, 55, 30, 15, 5, 2, 1 });
	}
}



int help(object me)
{
	write(@HELP
指令格式 : research | yanjiu <技能> <次数>
 
这个指令可以让你研究一种技能的疑难问题，当你师傅这项技能的级
别不如你的时候，可以通过研究自己来提高，进度的速度要和你对这
项技能的掌握程度和相关技能的熟悉情况相关，当然悟性也会起的一
定的作用，但是关键还是看技能的水平。一般来说相关的技能越多越
好，研究起来可能会事半功倍，如果会得太少，可能恰恰相反。

其他相关指令 : apprentice, practice, skills, study, learn
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
