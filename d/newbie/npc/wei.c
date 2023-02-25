// wei

inherit NPC;

void greeting(object me);

void create()
{
	set_name("韦小宝", ({"wei xiaobao", "wei"}));
	set("long", "他一脸顽皮像，眼神中透露着狡黠，没有半点正经。\n");
	set("gender", "男性");
	set("age", 21);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 24);

	setup();
	carry_object("/clone/cloth/cloth.c")->wear();
}

void init()
{
	object me;

	::init();
	me = this_player();
	if (! objectp(me) || ! userp(me))
		return;

	remove_call_out("greeting");
	call_out("greeting", 0, me);
}

void greeting(object me)
{
	if (! objectp(me) || environment(me) != environment(this_object()))
		return;

	command("xixi " + me->query("id"));
	command("say 这位" + RANK_D->query_respect(me) +
		"，嘿，在武林中立足，光讲仁义是万万不行的，只有像我和令狐大侠那样，狡黠多变，才活得下去！");
}

void check_leave(object me, string dir)
{
	if (dir == "out")
	{
		message_vision("$N对$n笑道：走！多捣点乱，那多有意思？\n",this_object(), me);
		me->set("character", "狡黠多变");
	} else
	if (dir == "north")
	{
		command("shake");
		command("say 不好玩儿。");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
