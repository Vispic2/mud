#include <ansi.h>
inherit F_SSERVER;
int main(object me, object target)
{
string msg;
mapping q;
if (!target){
me->clean_up_enemy();
target = me->select_opponent();
}			
if(!mapp(q=me->query("quest"))){
return notify_fail("你现在没有师门任务，使用「秒杀师门」干什么？\n");  
}
if(me->query("yqq") < 1)
return notify_fail("秒杀师门限权100R，访问http://"+NAME_PAY+"/进行购买卡密。\n");		
if(! target || ! me->is_fighting(target))
return notify_fail("「秒杀师门」只能对师门怪使用！！！\n");		
msg = HIW "$N" HIW "使出致命绝技「秒杀师门」，招式变得不清不楚！"NOR"\n";
message_combatd(msg, me);
if (target->query_temp("quester")==me->query("id")||target->query("id")==me->query("quest/id")||target->name()==q["name"]||target->query("id")==q["id"]){
message_combatd("结果$N一击致命，"+target->name()+"吐血不止，立刻身亡！\n", me);
target->receive_wound("qi", 1, me);
target->die(me);
me->start_busy(3+random(5));
}else{  	
message_combatd("$N使出「秒杀师门」，对敌人没有任何伤害。\n", me);
}
return 1;
}


int help(object me)
{
	write(@HELP
签到
HELP
	);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
