// majuan.c.c 马圈

inherit ROOM;

void create()
{
	set("short", "马圈");
	set("long", @LONG
皇家马圈，自然是好马云集。一排排齐整的马厩，一匹匹英挺
高头俊马，让你不由想起大草原上万马奔腾的壮伟景象。
LONG
	);
	set("exits", ([
		"east" : __DIR__"houhuayuan2",
	]) );
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
