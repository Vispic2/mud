//Room: shierliantai.c 十二莲台
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","十二莲台");
      set("long",@LONG
这里是武当绝顶的十二莲台，台与台之间以曲栏相连，雕刻精美，是远眺
的最佳所在。站立此台四眺，宛如身在千叶宝莲之上，千峰万壑都在脚下。往
西可望到七百里外的华山，东望则汉水如练，襄、樊一带尽收眼底。
LONG);
      set("exits",([ /* sizeof() == 1 */
	  "east"     : __DIR__"jinding",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
