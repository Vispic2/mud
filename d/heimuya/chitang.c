//room: 
inherit ROOM;

void create()
{
  set("short","池塘");
  set("long",@LONG
这是一个小池塘，池塘里有数对鸳鸯悠游其间，池边还有四
只白鹤在觅食。
LONG );

  set("exits",([
      "north" : __DIR__"baihutang",
      "west"  : __DIR__"shenggu",
      "east"  :__DIR__"chufang2",
  ]));
  set("objects",([
      "/d/dali/npc/xianhe" : 4,
  ]));
//  set("no_clean_up", 0);
  setup();
  //replace_program(ROOM);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
