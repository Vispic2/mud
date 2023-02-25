// Room: /city/bingqiku.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "卤酶脝梅驴芒");
	set("long", @LONG
脮芒脌茂脢脟卤酶脝梅驴芒拢卢碌陆麓娄脪酶鹿芒脡脕脡脕拢卢脠脙脠脣脩脹禄篓莽脭脗脪隆拢卤娄碌露隆垄卤娄陆拢隆垄陆冒鹿驴掳么拢卢麓贸
碌露隆垄鲁陇陆拢隆垄脡脷掳么拢卢露脤碌露隆垄露脤陆拢隆垄露脤鹿梅拢卢赂梅脡芦赂梅脩霉碌脛卤酶脝梅脫娄脫脨戮隆脫脨拢卢脛茫脪禄脢卤虏禄脰陋
碌脌脤么脢虏脙麓潞脙隆拢
LONG );
	set("exits", ([
		"north" : __DIR__"bingyin",
	]));
	set("no_clean_up", 0);
	create_door("north", "脤煤脙脜", "south", DOOR_CLOSED);
	setup();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
