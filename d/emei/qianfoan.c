//Room: qianfoan.c 千佛庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","千佛庵");
      set("long",@LONG
此处是洪椿坪千佛庵。山间小坪坝，四面层峦叠障，峰环岭护；两侧深谷
幽岚，溪涧玲叮。坪上古木扶疏，亭亭如盖，山阴沁透，白雾飘游，极为幽静
清凉。此处常见雨雾霏霏，林中迷迷蒙蒙，乃山中雾气所为。正所谓「山行本
无雨，空翠湿人衣」。这就是誉为奇观的「洪椿晓雨」。此处殿美景幽，气象
新异，令人心醉。沿途南上是「九十九道拐」，北下经黑龙江栈道至清音阁。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "southwest" : __DIR__"jsjdg1",
	  "enter"     : __DIR__"qfadadian",
	  "north"     : __DIR__"heilong2",
      ]));
      setup();
}

int valid_leave(object me, string dir)
{
	int c_skill;

	me = this_player();
	if (dir == "southwest")
	{
		c_skill = me->query_skill("dodge", 1);
		if (me->query("qi") > 40)
		{
			me->receive_damage("qi", 20 + random(20));
			if (me->can_improve_skill("dodge") && c_skill < 100)
			   me->improve_skill("dodge", 1 + me->query_skill("dodge", 1) / 15);
			tell_object(me,"你爬上八十四盘，有些累了。\n");
		} else
		{
			me->set("qi", 0);
			tell_object(me, "你太累了，再也走不动了。\n");
			return -1;
		}
      }
      return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
