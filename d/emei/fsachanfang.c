//Room: fsachanfang.c 禅房
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","禅房");
      set("long",@LONG
这里是一间安静宽敞的禅房，乃是福寿庵中弟子打坐修行之所。地下整整
齐齐地放着许多蒲团。几位年轻师太和俗家女弟子正肃容入定。
LONG);
      set("exits",([ /* sizeof() == 1 */
	  "west"    : __DIR__"lingwenge",
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      set("no_fight", 1);
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
