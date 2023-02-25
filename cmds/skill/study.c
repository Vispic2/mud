// study.c

#include <skill.h>
#include <command.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

void auto_study(object me,string skill,int times)
{
	if(!me||!me->query_temp("pending/auto_study"))
		return;
	if(me->is_busy())
		call_out("auto_study",1,me,skill,times);

	else if(me->query("neili")<200)
	{
                me->force_me("use huxin dan");
                me->force_me("exert regenerate");
                me->force_me("exert recover");
		me->force_me("dazuo "+me->query("max_qi")/3);
		call_out("auto_study",10,me,skill,times);
	}
	else if( (int)me->query("jing") < me->query("eff_jing"))
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < me->query("eff_jing"))
			{
				tell_object(me,"精神不足，等待恢复中。。。\n");
				call_out("auto_study",10,me,skill,times);
			}
			else
			{
				call_out("auto_study",1,me,skill,times);
			}
		}
		else
		{
			tell_object(me,"精神不足，等待恢复中。。。\n");
			call_out("auto_study",10,me,skill,times);
		}
	}
	else
	{
		tell_object(me,"托管中，继续研读。。。。。。\n");
		tell_object(me,ZJFORCECMD("study "+skill+" with "+times));
	}
}

int main(object me, string arg)
{
	object where = environment(me);
	object ob;
	string zhao_name, book_name;
	string sname;
	string *args;
	mapping needs;
	string *need_sk;
	mixed need_lvl;
	int my_skill, cost, times, i;
	int t = time();

	if (! arg)
		return notify_fail("你要读什么？\n");

	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (t == me->query_temp("time/study"))
		return notify_fail("你刚刚才读过书（如果你要连续读书，可以指明读书的次数）。\n");

	if (me->is_fighting())
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if (environment(me)->query("no_learn") || environment(me)->query("no_study"))
		return notify_fail("你无法在这个地方安心读书。\n");

	if (! arg )
		return notify_fail("你要研读什么？\n");

	if ((sscanf(arg, "%s with %d", book_name, times) != 2))
	{
		if ((sscanf(arg, "%s %d", book_name, times) != 2))
		{
			return notify_fail(INPUTTXT("请输入研读次数：","study "+arg+" with $txt#")+"\n");
		}
	}

	if (times < 1 || times > 9999)
		return notify_fail("读书次数最少一次，最多也不能超过9999次。\n");

	if (! objectp(ob = present(book_name, me)))
		return notify_fail("没这本书可读啊？\n");

	if (! mapp(ob->query("skill")))
		return notify_fail("你无法从这样东西学到任何东西。\n");

	if (!me->query_skill("literate", 1))
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	message("vision", me->name() + "正专心地研读" + ob->name() + "。\n", environment(me), me);
	if ((int)me->query("combat_exp") < ob->query("skill/exp_required"))
	{
		write("你的实战经验不足，再怎么读也没用。\n");
		return 1;
	} 

	cost = (ob->query("skill/jing_cost") * 1+ ob->query("skill/difficulty") - me->query_int()) / 1;
	if (cost < 10) 
	cost = 1;

	if (mapp(needs = ob->query("skill/need")))
	{
		foreach (need_sk in keys(needs))
		{
			// check all skills
			need_lvl = needs[need_sk];
			if (functionp(need_lvl))
				need_lvl = evaluate(need_lvl);
			else
			if (! intp(need_lvl))
				need_lvl = 0;

			if (me->query_skill(need_sk, 1) < need_lvl)
				// not reach the line
				return notify_fail("你研读了一会儿，发现如果不通晓" + to_chinese(need_sk) + "的话，恐怕难以领会上面的含义。\n");
			// check next skill
		}
	}




	sname = ob->query("skill/name");
	notify_fail("以你目前的能力，还没有办法学这个技能。\n");
	if (! SKILL_D(sname)->valid_learn(me)){
	return 0;
}




	if (! XUE_CMD->can_learn(me, sname))
		return 0;

	if (me->query_skill(sname, 1) > ob->query("skill/max_skill"))
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");

	if (me->query_skill(sname, 1) < ob->query("skill/min_skill"))
		return notify_fail("你研读了一会儿，但是却发现你对这门技能的理解还太浅，结果毫无收获。\n");

	if (! me->query_skill(sname, 1))
		me->set_skill(sname, 0);

	my_skill = me->query_skill(sname, 1);
	if (! me->can_improve_skill(sname))
	{
		return notify_fail("也许是缺乏实战经验，你对" + ob->name() + "上面所说的东西总是无法领会。\n");
	}

	me->set_temp("time/study", t);
	me->set_temp("pending/auto_study",1);
	for (i = 0; i < times && i<10000; i++)
	{
		if ((int)me->query("jing") > cost)
			me->receive_damage("jing",cost);

		else if (SKILL_D("force/regenerate")->exert(me, me))
		{
			write("你觉得精神好了一些，继续读书。\n");
			i--;
			continue;
		}
		else
		{
			me->set("jing", 1);
			break;
		}
            if(where->query("guibing_room")){
			me->improve_skill(sname,((int) me->query_skill("literate", 1)+ 100)*2);
            }else{		
			me->improve_skill(sname, (int) me->query_skill("literate", 1) + 100);
	    }		
      }

	if (! i)
		return notify_fail("你现在太累了，结果一行也没有看下去。\n");

	if (zhao_name = SKILL_D(sname)->query_skill_name(my_skill))
		write(sprintf("你研读了" + chinese_number(i) + "行有关%s的技巧，对「%s」这一招似乎有些心得。\n",to_chinese(sname), zhao_name));
	else
		write(sprintf("你研读了"+chinese_number(i) + "行有关%s的技巧，似乎有点心得。\n",to_chinese(sname)));

	if (i < times)
		call_out("auto_study",1,me,book_name,times-i);

	return 1;
}

int help(object me)
{
	write( @HELP
指令格式: study|du <物品名称> [次数]
	  study|du <物品名称> with [次数]

这个指令使你可以通过阅读秘笈或其他物品自学某些技巧, 但前提
是: 你不能是个『文盲』。并且你不能在不能战斗的地方读书。

see also : learn
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
