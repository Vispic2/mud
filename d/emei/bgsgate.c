//Room: bgsgate.c 报国寺山门
inherit ROOM;
string look_gate();

void create()
{
      set("short","报国寺山门");
      set("long",@LONG
报国寺为峨嵋出入之门户。山门(gate)上有一块大匾。寺外苍楠环卫，翠
柏掩映。由此一路向西上开始登峨嵋山，北面下山是一条弯弯的石阶路。
LONG);
      set("outdoors", "emei");
      set("item_desc", ([
	  "gate" : (: look_gate :),
      ]));
      set("objects", ([
	       __DIR__+"npc/guest": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
	  "northdown" : __DIR__"qsjie2",
	  "west"      : __DIR__"bgs",
      ]));
      setup();
}
string look_gate()
{
      return
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌　　　报　　国　　寺　　　≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
