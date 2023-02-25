#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "碧海"ZJBR"潮生"; }

int perform(object me, object target)
{
	string msg;
	int ap, dp, lvl;
	int jing, skill;
	object ob;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail(HIW "碧海潮生按玉箫" NOR
				   "只能对战斗中的对手使用。\n");

	if (! objectp(ob = me->query_temp("handing")) || ! ob->valid_as_xiao())
	{
		// 手里没有握萧，察看兵器
		if (! objectp(ob = me->query_temp("weapon")) ||
		    ! ob->valid_as_xiao())
		{
			// 手里的兵器也不能作为萧使用
			return notify_fail("你手里没有拿萧，无法使出这个绝招！\n");
		}
	}

	skill = me->query_skill("yuxiao-jian", 1);

	if (skill < 150)
		return notify_fail("你的玉箫剑法等级不够, 不能使用"
				   HIW "碧海潮生按玉箫" NOR "。\n");

	if (me->query("neili") < 300)
		return notify_fail("你的内力不够，无法运用"
				   HIW "碧海潮生按玉箫" NOR "。\n");

        if (target->query("qi")>target->query("max_jing")*3 && !userp(target))
	      return notify_fail("对方气血充盈，" HIW "碧海潮生按玉箫" NOR "无法影响。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	ap = me->query_skill("yuxiao-jian", 1) / 2 +
	     me->query_skill("force") + me->query_skill("chuixiao-jifa");
	dp = target->query_skill("force") * 2;

	lvl = (int) me->query_skill("yuxiao-jian", 1) / 5 + 1;
	if (lvl > 40) lvl = (lvl - 40) / 3 + 40;

	jing = (int) target->query("max_jing");
	if (jing>10000) jing = (int) me->query("max_jing");

	msg = HIC "$N" HIC "手按" + ob->name() + HIC "，脚踏八卦方位，奏出" NOR
	      HIW "§" HIC "碧海潮生按玉箫" HIW "§" NOR
	      HIC "............"NOR"\n";
	msg += HIW "\n只听得如鸣琴，如击玉，发了几声，接着悠悠"
		   "扬扬，飘下一阵清亮柔和的洞箫声来。"NOR"\n";

	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "$n" HIR "心头一荡，脸上不自禁的露出微笑！"NOR"\n";
		target->receive_damage("jing", jing / 5, me);
		target->receive_wound("jing", jing / 5, me);
		message_combatd(msg, me, target);
	} else
	{
		msg += HIY "$n" HIY "暗暗凝神守一，对这箫声自是应付裕如！"NOR"\n";
		message_vision(msg, me, target);
	}

	msg = HIW "那洞箫声情致飘忽，缠绵宛转，便似一个女子一会"
		  "儿叹息，一会儿呻吟，一会儿又软语温存或\n"
		  "柔声叫唤。"NOR"\n";

	if (ap / 4 + random(ap) > dp)
	{
		msg+= HIR "$n只感全身热血沸腾，就只想手舞足蹈的乱动一番！"NOR"\n";
		target->receive_damage("jing", jing / 3, me);
		target->receive_wound("jing", jing / 3, me);
		message_combatd(msg, me, target);
	} else
	{
		msg += HIY "$n" HIY "暗暗凝神守一，对这箫声自是应付裕如！"NOR"\n";
		message_vision(msg, me, target);
	}

	msg = HIW  "那箫声清亮宛如大海浩淼，万里无波，远处潮水缓缓推近，渐近渐快，其后洪涛汹涌，白浪连\n"
		   "山，而潮水中鱼跃鲸浮，海面上风啸鸥飞，再加上水妖海怪，群魔弄潮，忽而冰山飘至，忽而\n"
		   "热海如沸，极尽变幻之能事。"NOR"\n";

	if (ap / 4 + random(ap / 2) > dp)
	{
		msg+= HIR "$n" HIR "只感心头滚热，喉干舌燥！"NOR"\n";
		target->receive_damage("jing", jing / 2, me);
		target->receive_wound("jing", jing / 2, me);
		message_combatd(msg, me, target);
	} else
	{
		msg += HIY "$n" HIY "暗暗凝神守一，对这箫声自是应付裕如！"NOR"\n";
		message_vision(msg, me, target);
	}

	msg = HIW "箫声愈来愈细，几乎难以听闻，尤如潮退后水平如"
		  "镜，海底却又是暗流湍急。"NOR"\n";

	if (ap / 5 + random(ap / 4) > dp)
	{
		msg+= HIR "$n" HIR "此时已陷绝境，再也无法脱身！"NOR"\n";
		target->receive_damage("jing", jing / 2, me);
		target->receive_wound("jing", jing / 2, me);
		me->start_busy(1 + random(2));
		me->add("neili", -200);
		message_combatd(msg, me, target);
		return 1;
	} else
	{
		msg+= HIY "$n" HIY "暗暗凝神守一，对这箫声自是应付裕如！"NOR"\n";
		me->start_busy(2 + random(3));
		me->add("neili", -200);
		message_vision(msg, me, target);
		return 1;
	}

	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
