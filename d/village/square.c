// Room: /d/village/square.c	 
inherit ROOM; 
	
void create() 
{ 
	set("short", "打谷场"); 
	set("long", @LONG 
这里是村子的中心，一个平坦的广场，每年秋收打谷就在这。广场东 
角有棵大槐树，平日茶余饭後，村里的男女老少都爱聚在这里谈天说地。      
LONG 
	); 
	set("exits", ([ /* sizeof() == 3 */ 
		"northwest" : __DIR__"nwroad2", 
		"south" : __DIR__"sroad4", 
		"east"  : __DIR__"eroad3", 
	])); 
	set("objects", ([ 
		__DIR__"npc/kid": 2, 
		"/clone/npc/walker" : 1, 
	]));	
	set("outdoors", "village"); 
	setup(); 
} 

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
