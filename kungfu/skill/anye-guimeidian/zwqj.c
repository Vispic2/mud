#include <ansi.h>

inherit F_SSERVER;

string query_name() { return HIY"醉舞"ZJBR"情剑"; }

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("醉舞情剑笑群雄只能对战斗中的对手使用。\n");

        if((int)me->query("neili") < 1500 )
                return notify_fail("你的真气不够！\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够！\n");
       
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        
 
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N飞身跃起，使出醉舞情剑法终极绝技「醉舞情剑」!n"NOR, me);
           message_vision(HIB"\n突然只见$N使出醉舞情剑法终极绝技『醉舞情剑』！\n"NOR, me);
                      me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIC"\n$N飞身跃起，使出醉舞情剑法终极绝技「醉舞情剑」!\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“任凭世人笑我癫！！”\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HBRED"$N引醉舞情剑法长吟：“狂叹红尘游世间！！”\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBRED"$N引醉舞情剑法长吟：“独饮千杯江湖醉！！”！\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBRED"$N引醉舞情剑法长吟：“一掌一棍逍遥仙！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“身若惊鸿莺穿柳，剑似追魂不离人。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“昔有佳人公孙氏，一舞剑器动四方。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“观者如山色沮丧，天地为之久低昂。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“霍如羿射九日落，矫如群帝骖龙翔。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“来如雷霆收震怒，罢如江海凝清光。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“双剑一出尊天下！醉舞情剑笑群雄。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“古剑寒黯黯，铸来几千秋。白光纳日月，紫气排斗牛。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“有客借一观，爱之不敢求。湛然玉匣中，秋水澄不流。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“至宝有本性，精刚无与俦。可使寸寸折，不能绕指柔。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“愿快直士心，将断佞臣头。不愿报小怨，夜半刺私仇。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“我有昆吾剑，求趋夫子庭。白虹时切玉，紫气夜干星！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“锷上芙蓉动，匣中霜雪明。倚天持报国，画地取雄名。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“赵客缦胡缨，吴钩霜雪明。！！”！\n"NOR,me,target);
message_vision(HBRED"$N引醉舞情剑法长吟：“银鞍照白马，飒沓如流星。！！”！\n"NOR,me,target);                
message_vision(HBRED"$N引醉舞情剑法长吟：“十步杀一人，千里不留行。！！”！\n"NOR,me,target);                                
message_vision(HBRED"$N引醉舞情剑法长吟：“事了拂衣去，深藏身与名。。！！”！\n"NOR,me,target);                                                
  message_vision(HBRED"$N引醉舞情剑法长吟：“闲过信陵饮，脱剑膝前横。！！”！\n"NOR,me,target);                                                              
   message_vision(HBRED"$N引醉舞情剑法长吟：“将炙啖朱亥，持觞劝侯嬴。！！”！\n"NOR,me,target);                                                                             
  message_vision(HBRED"$N引醉舞情剑法长吟：“三杯吐然诺，五岳倒为轻。！！”！\n"NOR,me,target); 
   message_vision(HBRED"$N引醉舞情剑法长吟：“眼花耳热后，意气素霓生。。！！”！\n"NOR,me,target);
   message_vision(HBRED"$N引醉舞情剑法长吟：“救赵挥金槌，邯郸先震惊。！！”！\n"NOR,me,target);
   message_vision(HBRED"$N引醉舞情剑法长吟：“千秋二壮士，煊赫大梁城。。！！”！\n"NOR,me,target);
   message_vision(HBRED"$N引醉舞情剑法长吟：“纵死侠骨香，不惭世上英。！！”！\n"NOR,me,target);
   message_vision(HBRED"$N引醉舞情剑法长吟：“谁能书合下，白首太玄经。！！”！\n"NOR,me,target);
   message_vision(HBRED"$N引醉舞情剑法长吟：“剑气纵横三万里。！！”！\n"NOR,me,target);
   message_vision(HBRED"$N引醉舞情剑法长吟：“一剑霜寒十九州。！！”！\n"NOR,me,target);                                                                                                                                                 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n$N乘招势未收,劲吐内力，狂风暴雨之醉舞情剑法气向$n卷去！\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBRED"$N旧力未消,新力又生.醉舞情剑法忽左忽右,飘摇四起”！\n"NOR,me,target);  
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           message_vision(HIC"\n$N无法控制内息流动，只好后跃收招。\n"NOR, me, weapon);


           me->add("neili", -700);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(4);
   return 1;
}


