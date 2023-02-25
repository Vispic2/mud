// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIC "沧海笑" NOR; }
string query_name() { return "沧海笑"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int skill, ap, dp, damage, px, md, sx;
        int hp;
		me = this_player();
        me->clean_up_enemy();

        if( !target ) target = me->select_opponent();

        skill = me->query_skill("lonely-sword", 1);

        if( me->query("family/family_name") != "华山派" && me->query("family/family_name") != "华山剑宗" )
                return notify_fail("你不是华山派弟子\n");

        if( !me->is_fighting(target) )
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( skill < 270 )
                return notify_fail("你的独孤九剑等级不够，无法施展" + name() + "。\n");

        if( !objectp(weapon=me->query_temp("weapon") )
         || weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对，无法施展" + name() + "。\n");

        if( me->query_skill_mapped("sword") != "lonely-sword" )
                return notify_fail("你没有激发独孤九剑，无法施展" + name() + "。\n");

        if( (int)me->query_skill("force") < 270 )
                return notify_fail("你的内功火候不够，难以施展" + name() + "。\n");

if( (int)me->query_skill("sword-cognize") < 270 )
                return notify_fail("你的剑道修养火候不够，难以施展" + name() + "。\n");

        if( (int)me->query_skill("lonely-sword") < 270 )
                return notify_fail("你的独孤九剑火候不够，难以施展" + name() + "。\n");

        if( (int)me->query_skill("sword") < 270 )
                return notify_fail("你的基本剑术火候不够，难以施展" + name() + "。\n");

        if( !living(target) )
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        if( me->query("neili")<500 )
                return notify_fail("你此时的内力不足，难以施展" + name() + "。\n");

        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");

        px = target->query_skill("pixie-jian", 1);
        md = target->query_skill("moon-blade", 1);
        sx = target->query_skill("six-finger", 1);

        if( px || md )
                ap += ap/10;              // 作为万剑之宗，对避邪剑法，圆月刀法有加成。

        if( sx )
                ap -= ap/10;              // 不擅长应付六脉聚气成剑远程攻击，有减成。

        if( objectp(weapon2=target->query_temp("weapon")) )
        {
                msg = HIC "$N" HIC "一袭青衫，踏歌而来，口中作歌曰：" HBWHT "沧海一声笑，滔滔两岸潮，浮沉随浪只记今朝\n" NOR
                        HIW "歌声中，只见$N" HIW "肩膀微动，一道白光瞬间击出，射向$n。  \n"  NOR;

                if( ap / 2 + random(ap) > dp )
                {
                        me->add("neili", -100);
                        msg += HIR "$n" HIR "大骇，连忙举起手中兵器胡乱抵挡，却不想虎口剧痛，手中" + weapon2->name() +
                               HIR "捏不住，脱手而出。\n" NOR
                               HIC "$N" HIC "大笑道：$n" HIC "不过如此，尝尝下面这招滋味如何？\n \n" NOR;

                        weapon2->unequip();
                        weapon2->move(environment(me));
                } else
                {
                        me->add("neili", -200);
                        msg += CYN "$n" HIY "心随意动，手中" + weapon2->name() +  "轻轻一点。\n" NOR
                               HIY "只听[叮]的一声响，$N" HIY "轻笑道：$n" HIY "果然了得，\n" NOR
                               HIY "可做我对手。且接这招如何？ \n \n"NOR;
                }
                message_combatd(msg, me, target);
        }
        else
        {
                msg = HIC "$N" HIC "一袭青衫，踏歌而来，口中作歌曰：" HBWHT "沧海一声笑，滔滔两岸潮，浮沉随浪只记今朝\n" NOR
                      HIW "$N" HIW "笑道：久闻$n" HIW "不凡，且接这招如何？  \n"  NOR;
                        message_combatd(msg, me, target);

        }

        msg = HIC "$N" HIC "继续歌道：" HBWHT" 苍天笑，纷纷世上潮，谁负谁胜出天知晓 \n" NOR
              HIC "$N" HIC "随意挥洒手中的" + weapon->name() +"发出道道" HIW "剑气"HIC"，寒光闪闪，\n" NOR
              HIC "从四面八方朝$n" HIC" 直射而去！\n" NOR;

        damage = me->query_skill("sword");

        if( ap * 2/3 + random(ap) > dp )
        {
                damage = damage * 3;

                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 200,
                                           HIR "$n" HIR "被漫天剑气惊得面如土色，只觉"
                                           "避无所避，挡无可挡，转眼间" HIW "剑气" HIR "临身"
                                           "全身各大穴道鲜血喷溅！\n\n" NOR);


                        if( me->query_temp("apply/fatal_blow") && me->query("ability2/fatal_blow") )
                        {
                                if( random(100) < me->query("ability2/fatal_chance") )
                                {
                                        target->receive_damage("qi", target->query("qi") * me->query_temp("apply/fatal_blow")/100, me);
                                        target->receive_wound("qi", target->query("qi") * me->query_temp("apply/fatal_blow")/200, me);
                                        msg += HIR "紧接着，$N" HIR "追加了致命一击，给$n" HIR "造成更严重的创伤。\n" NOR;
                                }
                        }

                me->start_busy(1);
                if( !target->is_busy() )
                        target->start_busy(2);
                me->add("neili", -400);

        } else
        {
                msg += CYN "$n" CYN "眼见漫天" HIW "剑气" CYN "，势不可挡，"
                       "身法连闪之下，堪堪避了开去，惊出一身冷汗！\n\n" NOR;
                me->start_busy(2);
                me->add("neili", -500);
                target->start_busy(2);
        }
        message_combatd(msg, me, target);

        hp=target->query("qi");

        if( hp<target->query("max_qi")/10 )
        {
                msg  = HIR "$N" HIR "见$n" HIR"浑身浴血，已是摇摇欲坠，叹了一声道： \n" NOR
                       HIR "人生苦短，还是早早投胎去吧！手中" + weapon->name() +" 一挥！\n" NOR
                       HIR "$n" HIR "喉中咯咯作响，面上尽是不甘之色，终于倒了下去。 \n\n" NOR;
                msg += HIC"$N" HIC "青衫飘飘而去，歌声如风：苍生笑，不再寂寥，豪情仍在痴痴笑笑~~ \n\n\n" NOR;
                message_combatd(msg, me, target);
                target->die(me);
                return 1;
        }

        msg = HIC"$N" HIC "青衫飘飘而去，歌声如风：苍生笑，不再寂寥，豪情仍在痴痴笑笑~~ \n\n\n" NOR;

        message_combatd(msg, me, target);
        return 1;
}