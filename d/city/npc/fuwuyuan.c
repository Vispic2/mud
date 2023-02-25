//hapagou.c 哈巴狗
#include <ansi.h>
#include <command.h>
string ask_me();
inherit NPC;

void create()
{
	set_name("服务员", ({ "dog" }) );
	set("title", "名人堂服务员");  
	set("gender", "女性");
	set("age", 15);
	set("str", 22);
	set("int", 30);
	set("dex", 30);
	set("con", 30);

	set("long",
"你看到的是名人堂的服务员。\n");
	set("combat_exp", 2000000);
	set("attitude", "friendly");

	set("max_qi", 10000);
	set("max_jing", 10000);
	set("inquiry", ([ 
	"清理busy" :  (: ask_me :), 
	]) );
setup();
}

int ask_me()
{
	object me=this_player(); 
	int busy=me->query_busy();
me->add_busy(0-busy+3);
write(YEL"你发现自己好像变得轻松了！"NOR"\n");

return 1;
}  
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
