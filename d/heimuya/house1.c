//room: 
inherit ROOM;

void create()
{
  set("short","内室");
  set("long",@LONG
这是一个精雅的小舍，一进门便可闻到一阵浓冽的花香。房
中挂着一幅五女向凤图，图中绘着五个宫装美女，美目盼兮，艳
丽脱俗。屋里还有一张茶几，几张椅子，椅子上铺着绣花锦垫，
西面有一扇洞形门通向后厅。
LONG );

  set("exits",([
      "west" : __DIR__"huoting", 
  ]));  set("valid_startroom", 1);
  setup();
  //replace_program(ROOM);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
