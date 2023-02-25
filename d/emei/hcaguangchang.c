//Room: hcaguangchang.c 华藏庵广场
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","华藏庵广场");
      set("long",@LONG
这里是峨嵋华藏庵的广场，地上铺着青砖。正前方有一道台阶，通往大
雄宝殿。殿前有个丈许高的大香炉，香炉前的香台上，红烛高烧，香烟飘绕。
广场上有几个小师太正在练功。自此左右各有一条走廊通向后殿。
LONG);
      set("objects", ([
	   CLASS_D("emei") + "/xu" : 1,
	   "/clone/npc/mu-ren" : 4,
      ]));

      set("outdoors", "emei");

      set("exits",([ /* sizeof() == 1 */
	  "north"   : __DIR__"hcazhengdian", 
	  "southup" : __DIR__"hcadadian", 
	  "west"    : __DIR__"hcawest1", 
	  "east"    : __DIR__"hcaeast1", 
      ]));

      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
