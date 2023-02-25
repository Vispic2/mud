//room: /d/btshan/restroom.c
//restroom
inherit ROOM;

void create()
{
  set("short","休息室");
  set("long",
      "这里是间休息室，里面有张大床。在这里睡觉非常舒服，没人能\n"
  "打扰。南面是气派的长廊。\n"
     );

  set("exits",([
      "south" : __DIR__"changlang",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);

 setup();
 replace_program(ROOM);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
