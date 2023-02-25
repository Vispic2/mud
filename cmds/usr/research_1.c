//by name qq： 3468713544
#include <ansi.h>
#include <skill.h>
#include <command.h>
inherit F_CLEAN_UP;
int *query_scale(string skill);
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
	int ndjs;
	int xuyao;
	int ddd;
    skill=arg;
//    for(ddd=0;ddd<=10;ddd++){
	if (me->is_busy())
	return notify_fail("你现在正忙着呢。\n");
	if (environment(me)->query("no_learn") || environment(me)->query("no_fight"))
	return notify_fail("这里太纷杂，你没法作研究。\n");	
	if (me->is_fighting())
	return notify_fail("临阵磨枪？来不及啦。\n");
	if (! (lvl = me->query_skill(skill, 1)))
	return notify_fail("这项技能你还不会，研究什么？\n");
	if ((string) SKILL_D(skill)->type() == "knowledge")
	return notify_fail(to_chinese(skill) + "只能靠你学习才能提高的。\n");
	if (lvl < 180)
	return notify_fail("你对" + to_chinese(skill) + "的掌握程度还未到研究的程度。\n");
	if (! SKILL_D(skill)->valid_learn(me) ||  ! SKILL_D(skill)->valid_research(me))		
	return 0;
	if (! XUE_CMD->can_learn(me, skill))
	return 0;
	if ((me->query("potential") - me->query("learned_points")) < times)
	return notify_fail("你的潜能不够研究这么多次了。\n");
	is_force_skill = SKILL_D(skill)->valid_enable("force");
	is_parry_skill = SKILL_D(skill)->valid_enable("parry") && (! is_force_skill);
	ks = keys(me->query_skills());
	ls = ({ });
	for (i = 0; i < sizeof(ks); i++){
		mapping action;
		int eff;
		if (ks[i] == skill) continue;
		if (SKILL_D(ks[i])->main_skill() && SKILL_D(ks[i])->main_skill() != ks[i]) continue;
		if (SKILL_D(skill)->valid_enable(ks[i]))
		ls += ({ me->query_skill(ks[i], 1) });
		if (SKILL_D(ks[i])->valid_enable(skill) ||is_force_skill && SKILL_D(ks[i])->valid_enable("force")){		
			action = SKILL_D(ks[i])->query_action(me, 0);
			eff = (int)me->query_skill(ks[i], 1);
			if (action){			
				eff += (action["force"] + action["damage"] +action["attack"] + action["parry"] +action["dodge"]) * eff / 1000;
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
	me->improve_skill(skill,improve);			
	ndjs=(improve-1)/2;
	xuyao=((me->query_skill(skill,1)+1)*(me->query_skill(skill,1)+1))-me->query_learned()[skill];
	xuyao=xuyao/(1+ndjs*100/(lvl+100));
	if (! me->can_improve_skill(skill)){
		write("也许是缺乏实战经验，你感到难以继续研究" + to_chinese(skill) + "的问题了。\n");
		return 1;
	}
    me->improve_skill(skill,xuyao*24*8*8);
    if(where->query("guibing_room")){
    me->add("potential",-xuyao/2);
    }else{
    me->add("potential",-xuyao);
    }
    tell_object(me,HIY"目前等级："+me->query_skill(skill,1)+"  消耗潜能："+xuyao+"\n"NOR);
    
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
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
