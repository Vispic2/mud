// Room: /d/gaibang/cdandao1.c 
// Date: jeeny 2001.5	 
#include <room.h> 
inherit ROOM; 
	
void create() 
{ 
	set("short", "暗道"); 
	set("long", @LONG 
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。  
LONG 
	); 
	set("exits", ([ 
		"northeast" : __DIR__"undertre", 
		"southwest" : __DIR__"cdandao2", 
	])); 
	set("no_clean_up", 0); 
	setup(); 
	replace_program(ROOM); 
} 

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
