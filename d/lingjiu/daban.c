//ROOM daban.c

inherit ROOM;

string look_jingzi();
void create()
{
	set("short","缀锦阁");
	set("long",@LONG
这是日常梳妆打扮的地方，放着一张红木梳妆台 ， 正对着你的是一
面光润的铜镜(jingzi)，梳妆台上散落着一些胭脂花粉。台旁摆着斗大的
一个汝瓷花囊，插着满满的水晶球儿般的白菊。
LONG );
	set("exits", ([
	    "west" : __DIR__"changl14",
	]));
	set("item_desc", ([
	    "【铜镜】" : (: look_jingzi :) ,
	]));
	set("no_clean_up", 0);
	setup();
}

string look_jingzi()
{
	object me=this_player();

	message_vision("$N偷眼看着镜中的自己。\n",me);	
	if ((string)me->query("gender")=="女性")
		return "你抬眼往镜中瞧去，只见一个貌若春花的女子脉脉含情地凝望着你。你脸上一热，羞涩地低下了头，心想：那就是我吗？\n";
	if ((string)me->query("gender")=="男性")
		return "你抬眼往镜中瞧去，只见一个五大三粗的男子在镜中直瞪着你。你不觉心想：唉，这么雅致之处我真不好意思呆着了。\n";
	if ((string)me->query("gender")=="无性")
 		return "你抬眼往镜中瞧去，只见一个不男不女的人影恍惚镜中。你不觉心想：唉，为什么爹妈没给我一个女儿身呢？\n";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
