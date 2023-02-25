// by happ@YSZZ

inherit NPC;
string ask_cloth();
#include <ansi.h>

void create()
{
   set_name("雅典娜", ({ "yadian na", "na" }));
   set("long", @LONG

LONG);
   set("gender", "女性");
   set("no_get", 1);
   set_temp("no_kill", 1);
   set("age", 20);
   set("attitude", "peaceful");
   set("per",100);//means no rong-mao description.
   set("max_qi", 12000);
   set("max_gin", 14000);
   set("max_jing", 12000);
   set("force", 12000);
   set("max_force", 24000);
   set("force_factor", 500);
   set("max_mana", 14000);
   set("mana", 28000);
   set("mana_factor", 600);
   set("combat_exp", 20000000);
   set("daoxing", 20000000);
   set_skill("spells", 900);
   set_skill("buddhism", 900);
   set_skill("unarmed", 900);
   set_skill("jienan-zhi", 900);
   set_skill("dodge", 900);
   set_skill("lotusmove", 900);
   set_skill("parry", 900);
   set_skill("force", 900);
   set_skill("staff", 900);
   set_skill("lunhui-zhang", 900);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 90);
   set("inquiry",([
      "黄金圣衣": (: ask_cloth:) ]));

   setup();
   /*
carry_object("/d/migong/12gong/obj/armor")->wear();
   carry_object("/d/migong/12gong/obj/cloth")->wear();
  carry_object("/d/migong/12gong/obj/pifeng")->wear();
     carry_object("/d/migong/12gong/obj/shield")->wear();
carry_object("/d/migong/12gong/obj/staff")->wield();
*/
}

string ask_cloth()
{
        object ob = this_object();
        object me = this_player();
        object cloth;
        if( me->query("gong/number") >= 12 && !me->query("gong/all") )
       {
        command("chat "HIY+me->name()+"历尽磨难，终于得到了黄金圣衣！");
        me->set("gongs/all",1);
        me->set("gong/all",1);
        cloth=new("/d/xiangyang/12gong/npc/obj/gold_cloth");
        cloth->move(me);
me->add("combat_exp",200000);
me->add("potential",200000);
return "你得到了,30万经验,30万潜能,黄金圣衣一件!\n
你可要注意了,如果你死了,或者你自己把圣衣给(drop)了,可别回来再找我要圣衣!";
        }
        return "要过了还来要什么?";
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "唉，你太无聊了吧！\n");
	command("hehe");
}

void die()
{
	unconcious();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
