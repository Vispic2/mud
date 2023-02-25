// shanlu7.c
// Date: Nov.1997 by Venus

inherit BUILD_ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山路崎岖，曲折蜿延。四周林木苍翠，修竹茂密。山路旁是涵碧
亭，在这里极目远眺，群山环湖尽收眼底，的确是隐居得好去处。西
边是上山的路，往东便是下山的路。
LONG);
	set("exits", ([
	    "eastdown": __DIR__"yuhuangsj",
	    "westup"  : __DIR__"yuhuangsd",
	]));
	set("outdoors", "hangzhou");
	set("max_room", 4);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
