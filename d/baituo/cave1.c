//cave1.c
inherit ROOM;

void create()
{
  set("short","岩洞内");
  set("long",
	"这里是岩洞内部，洞顶上悬挂着洁白的钟乳石。\n"
      );
  set("exits",([
      "south" : __DIR__"cave",
     ]));
  set("no_clean_up", 0);
// set("objects",([
//      ]));
 setup();
 replace_program(ROOM);
}





/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
