// Room: /d/gaibang/hzandao2.c 
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
		"southeast" : __DIR__"underhz", 
		"northwest" : __DIR__"hzandao1", 
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
