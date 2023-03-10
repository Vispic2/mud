// This program is a part of NITAN MudLIB 
// redl 2015.2

#include <ansi.h>
inherit NPC;

void levelup();

int is_quarry(){return 1;}
int is_not_hunting(){return 1;}

mixed owner()
{
        object own = query_temp("owner", this_object());
        if (!own || !objectp(own)) return 0;// || !living(own)
        return own;
}

int is_worm()
{
        return 1;
}

int is_worm2()//蛊虫有主吗？ GIFTD把奖励转嫁给主人
{
        return owner();
}

int is_owner(object own)
{
        if (!owner() || own != owner()) return 0;
        return 1;
}

int is_canup()
{
        object own = owner();
        if (query("jcg/upg_energy", own) > (query("levelp") * 50 + (1<<(query("levelp")/4))) ) return 1;
        return 0;
}

int do_upg(string arg)
{
        object me = this_player();
        int costm = ((100<<(query("levelp")/5)) + (query("levelp")+1) * 300) * 5, cost;
        
        if (me->is_busy())
                return notify_fail(NOR BUSY_MESSAGE NOR);
        if (!arg || (arg!="jincan gu" && arg!="gu" && arg!="jincan"))
                return 0;
        if (query("levelp") < query("can_perform/qianzhu-wandushou/jin", me)) {
                levelup();
                return 1;
        }       
        if (query("eff_qi", me) < query("max_qi", me) || 
                query("eff_jing", me) < query("max_jing", me) || 
                query("qi", me) < query("max_qi", me) || 
                query("jing", me) < query("max_jing", me) || 
                query("jingli", me) < query("max_jingli", me) || 
                query("neili", me) < query("max_neili", me)
                ) {
                return notify_fail(NOR "你目前的状态不佳。\n" NOR);
        }
        if (!is_canup()) {
                return notify_fail(NOR "你还需要对" +name()+NOR+ "进行杀戮培养。\n" NOR);
        }
        if (query("max_jingli", me) <= costm / 2) {
                return notify_fail(NOR "你的最大精力不足以升级" +name()+NOR+ "。\n" NOR);
        }
        if (query("max_neili", me) <= costm) {
                return notify_fail(NOR "你的最大内力不足以升级" +name()+NOR+ "。\n" NOR);
        }
        cost = 500 + random(costm / (10 + query("levelp") / 5));
        addn("max_jingli", -cost/2, me);
        addn("max_neili", -cost, me);
        set("jingli", 0, me);
        set("neili", 0, me);
        set("jing", 0, me);
        set("qi", 0, me);
        set("eff_jing", 0, me);
        set("eff_qi", 0, me);
        addn("upg_energy_count", cost);
        message_vision(HIY "$N" HIY "划破眉心，蘸起一滴" HIR "精血" HIY "点在$n" HIY "的头上，自身却奄奄一息。\n" NOR, me, this_object());
        tell_object(me, NOR + "( 你损失了"+(string)(cost/2)+"点最大精力和"+(string)cost+"点最大内力 )\n" NOR);
        if (query("upg_energy_count") >= costm) {
                delete("upg_energy_count");
                //call_out("levelup", 1);
                levelup();
                delete("jcg/upg_energy", me);
                me->start_busy(4);
        }
        else {
                message_vision(NOR "$N" NOR "轻轻扇动了一下翅膀，想要飞起来。\n" NOR, this_object());
                me->start_busy(2);
        }
        return 1;
}

int do_stays()
{
        if (query_temp("gstay_time") > time()) return 0;
        set_temp("gstay_time", time()+300);
        message_vision(NOR "$N" NOR "脸上居然人性化地露出一个“本座就在这呆会儿的表情”。\n" NOR, this_object());
        return 1;
}

void msgcanup()
{
        object me = this_object();
        object own = owner();
        remove_call_out("msgcanup");
        
        if (!own) return;
        if (!me->is_fighting()) {
                tell_object(own, NOR + query("name", me) + NOR "嗡嗡嗡地乱飞，蠢蠢不安的样子。 (你可以尝试upg jincan gu？)\n" NOR);
                return;
        }
        call_out("msgcanup", 2);
}

int addexp(int n)
{
        object own, me = this_object();
        if (query("levelp")>=99) return 1;
        if (is_worm2()) {
                own = owner();
                n = n * (100 + ABILITY_D->check_ability(own, "n-bdjcg-grow1") * 2 + ABILITY_D->check_ability(own, "n-bdjcg-grow2") * 2) / 100;
        }
        if (!own) return 1;
        addn("jcg/upg_energy", n, own);
        if (is_canup()) {
                //message_vision(HIY "$N" HIY "可以升级了。\n" NOR, me);
                call_out("msgcanup", 2);
        }
}

void levelup()
{
        string n1;
        object me = this_object();
        int lv = query("levelp", me);
        object own = owner();
        
        if (!own) return;
        if (lv >= 99) return;
        lv += 1;
        //if (is_worm2()) {
        //      own = owner();
                if (lv > query("can_perform/qianzhu-wandushou/jin", own)) addn("can_perform/qianzhu-wandushou/jin", 1, own);
        //}
        set("levelp", lv, me);
        message_vision(HIC "$N" HIC "抱成一团互相胡乱撕咬，顷刻之后，你发现它们的数量少了一只。\n" NOR, me);
        if (lv >= 70) n1 = HIB "百毒" + NOR + YEL + "金蚕蛊";
        else if (lv >= 40) n1 = HIB "剧毒" + NOR + YEL + "金蚕蛊";
        else n1 = NOR + YEL + "金蚕蛊";
        if (lv<99)
                set_name( NOR + chinese_number(100 - lv) + "只" + n1 + NOR, ({ "jincan gu", "jincan", "gu" }));
        else {
                set_name( NOR + n1 + HIW "王" + NOR, ({ "jincan gu", "jincan", "gu" }));
                set("special_skill/zhuque", 1);
        }
        if (is_worm2()) set("title", filter_color(query("name", owner()))+"的" );
        set("max_qi", 50000 + query("owneradd") * lv);
        set("max_jing", 50000 + query("owneradd") / 2 * lv);
        set("str", 10 + lv);
        set("con", 5000 + lv * 5000);
        set("dex", 6000 + lv * 3000);
    set_temp("apply/attack", 5000 + lv * 2500);
    set_temp("apply/damage", 100 + lv * 10);
    set_temp("apply/armor", 5000 + lv * 2000);
    set_temp("apply/defence", 500 + lv * 250);
    set("age", lv);
    set("worm_poison", ([
                "level"  : 100 + lv * lv / 2,
                "perhit" : 10 + lv * lv,
                "remain" : 3,
                "maximum": 10,
                "supply" : 1,
        ]));
        set_temp("apply/reduce_damage", 10 + lv / 2);
        set_temp("apply/avoid_attack", 29 + lv / 2);
        set_temp("apply/avoid_defense", 19 + lv / 2);
        set_temp("apply/avoid_parry", 19 + lv / 2);
        set_temp("apply/avoid_dodge", 19 + lv / 2);
        set_temp("apply/avoid_force", 19 + lv / 2);
        full_self();
        //command("say " + (string)query("levelp"));
}

void create()
{
                set("levelp", 0);
                set_name( NOR "金蚕蛊" NOR, ({ "jincan gu", "jincan", "gu" }));
        //levelup();
        set("long", WHT "这是一些浑身骨刺，性情凶恶的蛊虫。\n传说饲养到最后能金刚不坏，并且无坚不摧。\n"
                        HIK"( stays指令可以让它驻留 )\n" NOR);
        set("race", "野兽");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "尾巴", "翅膀" }));
        set("verbs", ({ "bite" }));

        set("combat_exp", (1<<62)/2);
        set("level", 61321);
                set_heart_beat(1);
        setup();
        set("unit", "群");
}

void init()
{
        object o1, o2, *obs;
        object me = this_player();
        if (query("env/invisible", me) || is_owner(me)) {
                        add_action("do_upg", "upg");
                        add_action("do_stays", "stays");
                return;
        }
        if (environment() && query("no_fight", environment())) return;
                if (playerp(me)) return;
                if (is_owner(me)) return;
                if (me->is_master()) return;
                if (me->is_warcraft()) return;
                if (me->is_baby()) return;
                if (sscanf(base_name(me), "/kungfu/class/generate/%*s")) return;
                if (sscanf(base_name(me), "/d/city2/song/%*s")) return;
        if (me->is_worm() && me->is_worm2() && this_object()->is_worm2()
                && this_object()->owner()==me->owner())
                return;
                o1 = query_temp("owner", this_object());
                o2 = query_temp("owner", me);
                if (o1) {
                        if ( o1==o2 ) return;
                        if (!playerp(o1) && base_name(o1)==base_name(me) ) return;
                        if (!playerp(o1) && base_name(o1)==base_name(o2) ) return;
                        obs = o1->query_team();
                        if (obs && sizeof(obs) && 
                                (member_array(me, obs)>-1 || member_array(o2, obs)>-1) )
                        return;
                }
                kill_ob(me);
}

mixed hit_ob(object me, object ob, int damage)
{
        string limb, *limbs;
        object own;
        int cd1, chance1, da1, da2, da3, chance2, limit_exp;
        int lv = query("levelp", me);
        int damage2, ng = lv / 31 + 1;

        if (!ob) return 1;
        if( !limb ) {
                limbs=query("limbs", ob);
                if( !arrayp(limbs) ) {
                        limbs = ({ "身体" });
                        set("limbs", limbs, ob);
                }
        }

        if (is_worm2()) {
                own = owner();
                da1 = ABILITY_D->check_ability(own, "da_power-bdjcg-wpin");
                da2 = ABILITY_D->check_ability(own, "da_power-bdjcg-wpin2") * 10;
                da3 = ABILITY_D->check_ability(own, "da_power-bdjcg-wpin3") * 5;
                chance2 = ABILITY_D->check_ability(own, "chance-bdjcg-cpin") / 5;
        }
        
                if (lv > 0 && !random(7 - chance2)) {
                        if (!random(14 - lv / 10) && !ob->is_weak()) {
                                limb = limbs[random(sizeof(limbs))];
                                message_vision(HIY "$N" HIY "的尾部一震，射出一根" HIR "血红蛰针" HIY "钉在$n" HIY "的"+ limb +"，$n" HIY "浑身酸软无力。\n" NOR, me, ob);
                                ob->set_weak(lv / 4 + 1, 0);
                        }
                        if ((!random(14 - lv / 10) || (lv >= 99)) && !ob->is_freeze()) {
                                limb = limbs[random(sizeof(limbs))];
                                message_vision(HIY "$N" HIY "的尾部一震，射出一根" HIB "幽蓝蛰针" HIY "正中$n" HIY "的"+ limb +"，$n" HIY "被冻结起来了。\n" NOR, me, ob);
                                ob->set_freeze(lv / 4 + 1, 0);
                        }
                        if (lv >= 30 && !random(10 - lv / 20) && !ob->is_busy()) {
                                limb = limbs[random(sizeof(limbs))];
                                message_vision(HIY "$N" HIY "的尾部一震，射出一根" HIK "漆黑蛰针" HIY "正中$n" HIY "的"+ limb +"，$n" HIY "整个变得僵直。\n" NOR, me, ob);
                                ob->start_busy(3 + random(3));
                        }
                        if (lv >= 65 && !random(7) && query("neili", ob) > 0) {
                                limb = limbs[random(sizeof(limbs))];
                                message_vision(HIY "$N" HIY "的尾部一震，射出一根" HIG "油绿蛰针" HIY "正中$n" HIY "的"+ limb +"，$n" HIY "真气狂泻不止。\n" NOR, me, ob);
                                addn("neili", -query("neili", ob)/2, ob);
                        }
                        if (lv >= 75 && !random(6) && query("neili", ob) > 0) {
                                limb = limbs[random(sizeof(limbs))];
                                message_vision(HIY "$N" HIY "的尾部一震，射出一根" HIG "油绿蛰针" HIY "正中$n" HIY "的"+ limb +"，$n" HIY "真气狂泻不止。\n" NOR, me, ob);
                                addn("neili", -query("neili", ob)/2, ob);
                        }
                        if (lv >= 85 && !random(5) && query("neili", ob) > 0) {
                                limb = limbs[random(sizeof(limbs))];
                                message_vision(HIY "$N" HIY "的尾部一震，射出一根" HIG "油绿蛰针" HIY "正中$n" HIY "的"+ limb +"，$n" HIY "真气狂泻不止。\n" NOR, me, ob);
                                addn("neili", -query("neili", ob)/2, ob);
                        }
                        if (lv >= 99 && random(3) && !ob->query_condition("no_perform")) {
                                limb = limbs[random(sizeof(limbs))];
                                message_vision(HIY "$N" HIY "的尾部一震，射出一根" HIM "粉红蛰针" HIY "正中$n" HIY "的"+ limb +"，$n" HIY "突然忘了绝招。\n" NOR, me, ob);
                                ob->apply_condition("no_perform", lv / 4 + 1);
                        }
                }
                

        damage2 = damage / 20 * lv * lv * (100+da1);
        damage2 *= lv / 10 + random(3) + 1;
        if (lv >= 99) {
                damage2 = query("max_qi", ob) / (7+random(4));
        }
        if (userp(ob)) damage2 /= 10;
        else damage2 = damage2 / 100 * (100 + da2 + da3);

                if (query("spattack_time")<time()) {
                        if (is_worm2()) {
                                own = owner();
                                cd1 = ABILITY_D->check_ability(own, "cd-bdjcg-wpin") / 5;
                                if (cd1 > 5) cd1 = 5;
                                chance1 = ABILITY_D->check_ability(own, "ap_power-bdjcg-wpin");
                        }
                        set("spattack_time", time() + 8 - cd1);
                  while (ng--) {
                        damage = damage2 + random(damage2/4);
                limb = limbs[random(sizeof(limbs))];
                        if (((random(lv * 2) + 100) * (100 + chance1) / 100) > random(query("level", ob))) {
                                message_combatd(HIW "$N" HIW "的尾部一震，暴雨般射出" + chinese_number(damage/1000000+1) + "根蛰针，正中$n" HIW "的"+ limb +"。\n" NOR, me, ob);
                                ob->receive_damage("jing", damage / 2, me);
                                ob->receive_wound("jing", damage / 4, me);
                                ob->receive_damage("qi", damage, me);
                                ob->receive_wound("qi", damage / 2, me);
                                COMBAT_D->report_status(ob);
                        }
                        else {
                                message_combatd(HIW "$N" HIW "的尾部一震，暴雨般射出" + chinese_number(damage/1000000+1) + "根蛰针，$n" HIW + 
                                        (random(2) ? "猛地":"轻轻") + (random(2) ? "一跳":"后退") +"避开了。\n" NOR, me, ob);
                        }
                  }
                }
        if ( base_name(me)!=base_name(ob) && (!query_temp("suck_energy_jcg", ob)) ) {
                limit_exp = query("combat_exp", ob);
                if (ob->is_worm() && query("worm_poison/level", ob) && query("worm_poison/level", ob)>1 ) {
                        message_vision(HIR "$N" HIR "的脖子一晃，变出张血盆巨口死死咬住$n" HIR "，$n" HIR "体内的" + (string)query("worm_poison/level", ob) + "点生命精华快速流失。\n" NOR, me, ob);
                        addexp(query("worm_poison/level", ob));
                        set("qi", -1<<62, ob);
                        set("eff_qi", -1<<62, ob);
                        set_temp("suck_energy_jcg", 1, ob);
                } 
                else if ( !userp(ob) && 
                        limit_exp > 0 && 
                        ( random(limit_exp) < 100000000 ||//小于1亿
                        random(5000 + (ob->is_boss() ? 10000 : 0)) < lv )
                        ) {
                        limit_exp = limit_exp / 1000000;
                        if (limit_exp > 500) limit_exp = 250;
                        if (limit_exp < 1) limit_exp = 1;
                        message_vision(HIR "$N" HIR "的脖子一晃，变出张血盆巨口死死咬住$n" HIR "，$n" HIR "体内的" + (string)limit_exp + "点生命精华快速流失。\n" NOR, me, ob);
                        addexp(limit_exp);
                        set("qi", -1<<62, ob);
                        set("eff_qi", -1<<62, ob);
                        set_temp("suck_energy_jcg", 1, ob);
                }
        }
        return 1;
}

void heart_beat_p()
{
        object own = owner();
        if (!own) {
                message_vision(HIY "$N" HIY "一震背上的金翅，嗖地不见了。\n" NOR, this_object());
                destruct(this_object());
                return;
        }
        if (living(this_object())) {
                if (!query_temp("guardfor"))
                        command("guard "+query("id", own));
                if (!this_object()->is_fighting()) {
                        this_object()->stop_busy();
                        this_object()->clear_condition();
                } else {
                        if (!random(104-query("levelp")) && (sizeof(query_enemy()))) {
                                hit_ob(this_object(), query_enemy()[random(sizeof(query_enemy()))], query("levelp")*100);
                        }
                }
                if (query_temp("gstay_time") < time() && environment(own) && environment(own)!=environment()) {      
                        this_object()->move(environment(own));
                }
                if (query_temp("gfull_time") < time()) {
                        this_object()->clear_condition();
                        this_object()->clear_weak();
                        this_object()->clear_freeze();
                        if (query("eff_qi") < query("max_qi")) addn("eff_qi", random(query("levelp"))+1);
                        if (query("eff_jing") < query("max_jing")) addn("eff_jing", random(query("levelp"))+1);
                        set("neili", query("max_neili"));
                        set("jingli", query("max_jingli"));
                        set_temp("gfull_time", time() + 144 - query("levelp"));
                        if (!query("no_fight", environment(own))) message_combatd(HIW "$N" HIW "背上的六对金色翅膀一扇，状态有所恢复。\n" NOR, this_object());
                }
        }
        call_out("heart_beat_p", 1);
}

int receive_damage(string type, int n) 
{ 
        int lv = query("levelp");
        if (query("jinchan_msgtime")<time()){
                        set("jinchan_msgtime",time());
                        message_combatd(HIY "$N" HIY "背上的六对金色翅膀一扇，坚若磐石。\n" NOR, this_object());
                        return ::receive_damage(type, 0);
        }
        if (lv >= 99 && random(2)) return ::receive_damage(type, 0);
        n /= 1<<query("ab/reduce_damage-bdjcg");
        return ::receive_damage(type, n / (10<<lv/7));//1e≈19
} 
      
int receive_wound(string type, int n) 
{ 
        return;
} 
      
varargs void die(object killer)
{
        object ob;
                int lv = query("levelp") / 10 + 1;
                int isnpc = 1;

                if (!killer)
                        killer = query_last_damage_from();
                if (!killer)
                        killer = query_temp("last_opponent", this_object());
                if (!killer || userp(killer))
                        isnpc = 0;
                
                if (isnpc && (random(100) < 39 + 12 * query("ab/avoid_die-bdjcg")))
                        return;
                else if (random(100) < 10 + lv + 2* query("ab/avoid_die-bdjcg"))
                        return;

        if(random(100)<lv && //90% can call_die
         objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
                return;
        }
        
        return ::die(killer);
}

mapping request()
{
        mapping rval, parts = query("parts",load_object("/clone/misc/corpse"));
        string ke, *keyp = keys(parts);
        mixed *val;
        
        keyp = filter_array(keyp, (: $1!="head" && $1!="hair" :));
        //command("say " + implode(keyp, "、"));
        ke = keyp[random(sizeof(keyp))];
        val = parts[ke];
        rval = ([
                "id" : val[4],
                "unit" : val[1],
                "name"  : val[3],
        ]);
        return rval;
}

int make_request(object master, object who)
{
        mapping mval = ([]);

        if (query("family/jcg/request_time", who) > time()) {
                tell_object(who, NOR + CYN + master->name() + NOR + CYN + "摇摇头说：这么不成器，你过段时间再来吧。\n" + NOR);
                return 0;
        }
        if (query("can_perform/qianzhu-wandushou/jin", who)) {
                tell_object(who, NOR + CYN + master->name() + NOR + CYN + "疑惑道：你不是已经拥有金蚕蛊了嘛。\n" + NOR);
                return 0;
        }
        set("family/jcg/request_time", time() + 1800, who);
        while (!mval["id"] || !mval["name"] || !mval["unit"])
                mval = request();
        set("family/jcg/request_job", mval, who);
        tell_object(who, NOR + CYN + master->name() + NOR + CYN + "说道：听说祖师爷饮食嗜好非凡，你这次带"+
                mval["unit"]+mval["name"]+"("+mval["id"]+")去问问辛辰子师兄？\n" + NOR+
                HIK"( 你接到了分尸送器官的任务，参见cut ? from corpse )\n\n");
        return 1;
}

int is_complete_request(object master, object who, object ob)
{
        mapping mval = query("family/jcg/request_job", who);
        
        if (!mval || !mapp(mval) ||!sizeof(mval))
                return 0;
        if (base_name(ob)!="/clone/misc/part")
                return 0;
        if (query("id", ob)!=mval["id"])
                return 0;
        if (query("name", ob)!=mval["name"])
                return 0;
        
        delete("family/jcg/request_job", who);
        delete("family/jcg/request_time", who);
        addn("family/jcg/request_complete", 1, who);
        if (query("family/jcg/request_complete", who) < 9) {
                tell_object(who, NOR CYN + master->name() + NOR CYN + "对你恶狠狠地笑了笑。\n" + NOR);
                return 1;
        }
        master->command("say 好吧，我可以带回山去讨好老怪了。这蛊你拿去多练习练习！");
        tell_object(who, HIC "你学会了「百毒金蚕蛊」。\n" NOR);
        if (who->can_improve_skill("qianzhu-wandushou"))
                who->improve_skill("qianzhu-wandushou", 1500000);
        if (who->can_improve_skill("hand"))
                who->improve_skill("qianzhu-wandushou", 1500000);
        who->improve_skill("martial-cognize", 1500000);
        set("can_perform/qianzhu-wandushou/jin", 1, who);
        delete("family/jcg/request_complete", who);
        return 1;       
}


