//room: 
inherit ROOM;

void create()
{
  set("short","长廊");
  set("long", @LONG
这里是非常气派的长廊。但是却没什么人在这里，南边是青
龙堂的大厅。
LONG  );

  set("exits",([
      "north" : __DIR__"chlang1",
      "south" : __DIR__"qing",
  ]));			   
  set("objects",([
      __DIR__"npc/shinu1"   :1,
  ]));
  set("no_fight",0);
  set("no_steal",0);
  set("no_clean_up", 0);
  setup();
  //replace_program(ROOM);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
