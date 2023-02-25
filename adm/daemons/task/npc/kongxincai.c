//子虚道人

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

#define MAZE "/u/mudren/maze"
#define MIRROR "/adm/daemons/task/mirror"

int ask_bingcan(); 

void create()
{
    seteuid(getuid());
    set_name(HIW"空心菜"NOR, ({"zixu daoren", "zixu", "daoren"}));
    set("long", @LONG
此人身着一身锦衣，紫发红颜，一副杀马特的风格，这便是武林中号称「非酋之酋」
LONG);
    set("nickname", HIW "酋长" NOR);
    set("title", HIC "非洲部落酋长" NOR);
    set("gender", "男性");
    set("age", 108);
    set("attitude", "friendly");
    set("max_jing", 50000);
    set("max_qi", 50000);
    set("max_jingli", 50000);
    set("jingli", 50000);
    set("max_neili", 50000);
    set("neili", 50000);
    set("jiali", 350);
    set("str", 50);
    set("int", 50);
    set("con", 50);
    set("dex", 50);
    set("combat_exp", 12000000);

    set("inquiry", ([
        "冰蚕" : (: ask_bingcan :),
    ]));

    set_skill("force", 500);
    
    set("chat_chance_combat", 120);


    setup();
    carry_object("/d/wudang/obj/tiancs")->wear();
}


int ask_bingcan()
{
	object ob = this_player();
	object a1,a2,a3,a4;	 
	command("nod "+ob->query("id"));
	command("say 我这就给你。");
	a1 = new("/clone/insect/bingcan");
	a1->move(ob);
	a1->move(ob);
	a1->move(ob);			
	tell_object(ob,HIR"你获得了"+a1->short()+"。"NOR"\n");	
	 
	return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
