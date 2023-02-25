// fish.h

int is_fish() { return 1; }

int has_died = 0;

void setup()
{
	set_weight(500 + random(1000));
	set("value", query_weight() / 50);

	::setup();
	if (clonep())
		call_out("die", 60 + random(60));
}

void die()
{
	remove_call_out("die");

	if (! environment())
	{
		destruct(this_object());
		return;
	}

	message("vision", name() + "一翻白肚，死了。\n", environment());
	set("long", "这是一条" + name() + "，它已经死了。\n");
	set_name("死" + name(), ({ "si yu", "siyu" }));
	has_died = 1;
	call_out("decay", 30 + random(30));
	set("value", query("value") / 2);
}

void decay()
{
	remove_call_out("decay");

	if (! environment())
	{
		destruct(this_object());
		return;
	}

	message("vision", name() + "腐烂了，发出一阵阵臭味。\n", environment());
	set("long", "这是一条" + name() + "，它已经开始腐烂了。\n");
	set_name("烂鱼", ({ "lan yu", "lanyu" }));
	set("value", 0);
	call_out("vanish", 20 + random(20));
}

void vanish()
{
	if (environment())
	{
		message("vision", "一阵风吹过，把" + name() +
			"给吹散了。\n", environment());
	}

	destruct(this_object());
}

void sold()
{
	destruct(this_object());
}

int broil(object me, object ob)
{
	object fob;

	if (query("value") == 0)
	{
		write("这么一条臭鱼还烤什么！\n");
		return 1;
	}

	me = this_player();
	if (me->is_busy())
	{
		write("你现在忙着呢，过会儿再烤吧。\n");
		return 1;
	}

	message_vision("$N把" + name() + "放在" + ob->name() +
		       "上细细的烤着，只听毕啵毕啵的声音，一"
		       "阵诱人的香味散了出来。\n", me);

	write(HIY "你把鱼烤好了！"NOR"\n");
	fob = new("/clone/food/fish");
	fob->move(me, 1);
	destruct(this_object());
	me->start_busy(1);
	return 1;
}
