//room: changl8.c
inherit ROOM;

void create()
{
  set("short","画廊");
  set("long",@LONG
这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面
雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做的，
走在上面毫无声息，你只感到脚下软软的，非常舒服。西边通向大厅。
LONG );
  set("exits",([
      "west" : __DIR__"changl15",
      "east" : __DIR__"changl4",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
