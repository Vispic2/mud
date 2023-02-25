// invocation.c
#include <ansi.h>
inherit F_SSERVER;
#define MAX_GUARD 15
string query_name() { return "召唤"ZJBR"魔龙"; }
int perform(object me, object target)
{
	object soldier;
	int	spells;
	string 	msg;
	object	env;
	object	*inv;
	int	i,exp;
	if( !target ) target = offensive_target(me);
        
        

        if (present("dark angel",environment(me)))
		return notify_fail("只能如唤一个魔龙为你做战！\n");
if ((int)me->query_skill("dragon-parry", 1) < 1200)
                return notify_fail("你的魔龙缠身修为不够。\n");
        

	message_vision(HBBLU HIR"$N"HBBLU HIR"用手在地上划了一个血阵，口中念念有词\n", me,target);
	message_vision(HBRED CYN"$N"HBRED CYN"念到，一誊生死卷 甘愿为魔颠！！！\n", me,target);
      message_vision(HBRED CYN"$N"HBRED CYN"念到，天命不败，魔主不死 ！\n", me,target);
      	message_vision(HBBLU HIR"$N"HBBLU HIR"念到：“伟大的九幽魔主，让此方天地变成无间地狱吧!”\n", me,target);
	message_vision(HBBLU HIR"$N"HBBLU HIR"念到：“沉睡于九幽的魔龙，现出汝的真身吧！！！”\n", me,target);
        message_vision(HBBLU HIR"$N"HBBLU HIR"念到：“以吾之血唤九幽魔龙，助吾杀敌！” \n", me,target);
	message_vision(HBBLU HIR"$N"HBBLU HIR"声嘶力竭的呐喊着：“杀！杀！杀！杀！杀！杀 ！杀！杀！”\n", me,target);
         message_vision(HBBLU HIR"$N"HBBLU HIR"念到：“统御魔界的九幽魔主啊 请降下惩戒吧!” \n", me,target);		
	message_vision(HBYEL HIR"天空之上突然出现一道裂痕，一道身影从中走了出来 ！\n", me,target);


	me->add("neili", -2500);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/liehuo-dragon");
message_vision(HBBLU HIR"九幽魔龙出现了！！\n", me,target);
	soldier->move(environment(me));
if (userp(me))
{
	soldier->set("combat_exp",me->query("combat_exp"));
exp = (int)me->query("combat_exp");
	soldier->set("qi",me->query("max_qi"));
	
	soldier->set("max_qi",me->query("max_qi"));
	soldier->set("jing",me->query("max_qi"));
	
	soldier->set("max_jing",me->query("max_qi"));
	soldier->set("neili",me->query("max_neili"));
	soldier->set("max_neili",me->query("max_neili"));
}
        soldier->invocation(me, (exp));
	soldier->set("possessed", me);
	return 1;
}
