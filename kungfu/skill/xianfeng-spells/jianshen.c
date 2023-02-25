#include <ansi.h>

string name() { return HIW "剑神" NOR; }
string query_name() { return "剑神"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;
        object ob;
        object weapon;

        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("哪来的无知后辈，没有供奉与我，还想召唤我！\n");

   if(me->query("shushan/jianshen_cast")!=1)
          return notify_fail("你还没领会「剑神」！\n");

        if( me->query("neili")<1000 )
                return notify_fail("你的法力不够。\n");

        if ((int)me->query_skill("xianfeng-spells", 1) < 800)
                return notify_fail("你的仙风云体术修为不够。\n");

        if (me->query_skill_mapped("spells") != "xianfeng-spells")
                return notify_fail("你还没有激发仙风云体术呢。\n");

        if (find_living(me->query("id") + "剑神"))
                return notify_fail("你召唤来的剑神还在人世间，尚未返回天界。\n");

        skill = me->query_skill("xianfeng-spells", 1);
        me->add("neili", -1000);

        message_combatd(HIC "\n$N" HIC "口中念念有辞，突然天空中出现「剑神」的身影！\n\n" NOR, me);

        // 设置剑神
        ob = new("/kungfu/class/misc/jianshen");
        ob->init_npc(me);
        ob->move(environment(me));

        me->start_busy(3);

        return 1;
}
