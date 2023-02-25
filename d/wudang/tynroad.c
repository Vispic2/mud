// tynroad.c 桃园小路
// by Marz 

inherit ROOM;

string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});
void create()
{
	int i = random(sizeof(npcs));
	    
	set("short", "桃园小路");
	set("long", @LONG
眼前豁然开朗，你轻松地走在桃园边的小路上。路上落英缤纷，一边是桃树
林，盛开着粉红的桃花，红云一片，望不到边。还可以看见蜜蜂「嗡嗡」地在花
间飞上飞下忙个不停，间或传来猿猴的叽咋声。这儿是武当山脚，北边是条环山
的黄土路。
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"south" : __DIR__"tyroad8",
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
