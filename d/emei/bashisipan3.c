//Room: bashisipan3.c 八十四盘
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","八十四盘");
      set("long",@LONG
八十四盘，道路艰险陡峭，迂回盘折，令人不能喘息。路左是蔽日遮天的
冷杉林，路右是深不见底的绝壁峡谷。由此往上至接引殿，北下到洗象池。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "northdown"  : __DIR__"bashisipan2",
	  "southeast"  : __DIR__"jieyindian",
	  "northeast"  : __DIR__"lengsl4",
      ]));
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
