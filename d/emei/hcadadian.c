//Room: hcadadian.c 华藏庵大雄宝殿
inherit ROOM;

void create()
{
      set("short","大雄宝殿");
      set("long",@LONG
这是峨嵋山华藏庵的大雄宝殿。正中供奉着普贤菩萨。一群青衣小师太正
在地上诵经。后面有道小门通往后殿。
LONG);
      set("exits",([ /* sizeof() == 1 */
	  "northdown"  : __DIR__"hcaguangchang", 
	  "south"      : __DIR__"hcahoudian", 
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
