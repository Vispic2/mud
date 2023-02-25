#include <ansi.h>
#include <dbase.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIY"圣灵珠"NOR, ({"sheng lingzhu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("material", "crystal");
                set("value",100000);
set("no_steal",1);
                set("no_get", "送人？亏你想的出来！\n");
//                set("no_give", "这种稀世之宝怎么能轻易送人呢?\n");
                set("no_sell", "卖?这种稀世之宝谁买得起啊!\n");
                set("long","天地初开时，清者归于上，浊者归于下；有一种半清半浊归于中，是为此宝！\n
因此五行皆为其子。\n");
                set("replace_file", __DIR__"rose");
                set("armor_prop/armor", 800);
                set("spells/fire", 1);
                set("spells/thunder",1);
                set("spells/water",1);
                set("spells/wind",1);
                set("spells/earth",1);
        }
        setup();
}

int init()
{
        object who = this_player();
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
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

if(arg!="all"&&arg != "sheng lingzhu" )
    return notify_fail("你要佩带什么？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

  msg = "$N戴上一颗"+name+"，顿感神清气爽。\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("wear_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if ( arg!= "all" && arg != "sheng lingzhu")
    return notify_fail("你要摘掉什么？\n");

if (me->is_busy())
	return notify_fail("你正忙着呢。\n");

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}
  zhu->set("unequip_msg",msg);
remove_call_out("shengzhuconditions");
  return 0;
}

void shengzhuconditions(object who,object ob)
{
     object target;
     object me = this_player();
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
if(me->query("combat_exp")>500000 )
{
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIR"圣灵珠五彩毫光猛然四射，刹时风雨雷电齐至，山崩地裂！\n"NOR;
//divid by 10;

                ap = me->query("combat_exp");
                dp = target->query("combat_exp");
                        
                        
                if( random(ap) > dp/2 )
                 {
                        damage = 1200+random(800);
                        damage -= random((int)target->query("eff_jing") / 5);

                        if( damage > 0 ) 
                        {
                                msg += HIC "结果$n躲避不及，被雷电劈个正着，又被地火烧得皮焦骨烂。\n
被山石砸得皮破血流，还被风迷了双眼，又被水浇个透心凉，肌肤尽裂。\n" NOR;
if (damage> 1200) damage=1200;
                                target->receive_damage("jing", damage/2);
                                target->receive_wound("jing", damage/4);
                                target->receive_damage("qi", damage*8/5);
                                target->receive_wound("qi", damage/2);
                                target->start_busy(5);
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
call_out("shengzhuconditions",7,who,ob);
}
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
