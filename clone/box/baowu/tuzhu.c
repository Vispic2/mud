#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);

object offensive_target(object me);

void create()
{
        set_name(HIY "土灵珠" NOR, ({"tu lingzhu", "tuzhu"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("material", "crystal");
set("no_steal",1);
                set("value",10000);
                set("no_give", "这种稀世之宝怎么能轻易送人呢?\n");
                set("no_sell", "卖?这种稀世之宝谁买得起啊!\n");
                set("long","传说中的五行宝珠之一，佩之可避石砸，并可发出土系法术。\n为祈雨所必需之物。");
                set("replace_file", __DIR__"rose");
                set("bb",1);
                set("armor_prop/armor", 100);
                set("spells/earth", 1);
        }
        setup();
}

int init()
{
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
        return 1;
}

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all" && arg != "tuzhu" &&  arg != "tu lingzhu" )
    return notify_fail("你要佩带什么？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
  msg = "$N戴上一颗"+name+"，黄色的宝珠在胸前一颤一颤的。\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("wear_msg",msg);
remove_call_out("tuzhuconditions");
call_out("tuzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if (arg != "all" && arg != "tuzhu" && arg != "tu lingzhu")
    return notify_fail("你要摘掉什么？\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("unequip_msg",msg);
  remove_call_out("tuzhuconditions");
  return 0;
}

void tuzhuconditions(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
string type;
type = ob->query("armor_type");
if (!who) return;
if (who)
{
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
}
if (!who) return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
        if( ! target ) return ;
 if( ! present( target,environment(who)) ) return ;    
        msg = HIY"土灵珠冉冉升起，$n的头上出现一座巨大的石山，只见土灵珠一沉，\n
石山急速下落！\n"NOR;
//divid by 10;

                ap = who->query("combat_exp")/2;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap) > dp/2 )
                 {
                        damage = 500+random(800);
                        damage -= random((int)target->query("eff_jing") / 5);

                        if( damage > 0 ) 
                        {
                                msg += HIC "结果$n躲避不及，被石山砸个正着！头破血流。\n" NOR;
if (damage> 800) damage=800;
                                target->receive_damage("jing", damage);
                                target->receive_wound("jing", damage/3);
                                target->receive_damage("qi", damage);
                                target->receive_wound("qi", damage/3);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n谁知$n毫无反应。\n" NOR;   
                }
                else
                        msg += "但是被$n躲开了。\n";

                message_vision(msg, who, target); 
        }
call_out("tuzhuconditions",7,who,ob);
}

void owner_is_killed()
{
       destruct(this_object());
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
