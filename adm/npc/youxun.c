// youxun.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
inherit F_UNIQUE;

static object *receiver;

object *query_receiver() { return receiver; }

int ask_fee();
int filter_listener(object user);

void create()
{
	set_name("游讯", ({ "you xun", "you", "xun", "youxun" }) );
	set("nickname", HIG "滑不留手" NOR);
	set("gender", "男性" );
	set("age", 42);
	set("long", "他就是专门打探、贩卖消息的游讯。\n");
	set("attitude", "friendly");
	set("skill_youxun", 1);
	set("max_jing", 500);
	set("max_qi", 500);
	set("str", 21);
	set("icon","00625");
	set("int", 29);
	set("con", 21);
	set("dex", 35);
	set("combat_exp", 250000);

	set("inquiry", ([
		"谣言": "不是小的吹牛，谁的谣言我都能查出来。",
		"收费" : (: ask_fee :),
		"打听" : "嘿嘿嘿，你想打听谁？鄙人消息那个灵通...",
		"发呆神功" : "想学么(idle-force)？鄙人教，不收钱的。",
	]));

	set("vendor_goods", ({
		"/clone/gift/feidan",
		"/clone/gift/feimao",
		"/clone/gift/kuangquan",
		"/clone/gift/duwan",
		"/clone/gift/shedu",
	}));

	set("chat_chance", 1);
	set("chat_msg",({
		"游讯嘻嘻道：小的我没别的本事，就会打听消息，就算是巫师造谣，我也能知道。\n",
		"游讯亮出一指道：便宜啊，几两银子就能查条谣言，这可真是跳楼价。\n",
		"游讯贼眯眯的说：天算地算不如人算，可是再怎么算我游某都知道。\n",
	}));

	set_skill("dodge", 150);
	set_skill("unarmed", 50);
	set_skill("idle-force", 500);

	setup();
	carry_object("d/city/obj/cloth")->wear();
	set_temp("bomb_count", 1);
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

mixed accept_ask(object ob, string topic)
{
	object fob;
	if (topic == ob->query("id"))
	{
		command("laugh " + topic);
		return 1;
	}
	fob = find_player(topic);
	if (! fob || ! ob->visible(fob)) fob = find_living(topic);
	if (! fob || ! ob->visible(fob) || ! environment(fob))
		return;

	ob->set_temp("pending/ask_youxun", topic);
	message_vision(CYN "$N" CYN "嘿嘿奸笑两声，对$n"CYN "小声道：“没有问题，不过得要50两黄金，不二价！”"NOR"\n", this_object(), ob);
	return 1;
}

int recognize_apprentice(object me, string skill)
{
	if (skill != "idle-force")
	{
		if (me->add_temp("illegal_learn", 1) > 3)
		{
			command("say 滚！你烦不烦？！");
			message_vision("$n一脚把$N踢出门外！\n",
				       me, this_object());
			me->set_temp("illegal_learn", 2);
			me->move("/d/city/beidajie1");
			me->unconcious();
		} else
			command("say 我只教发呆神功，不传其它武功！");
		return -1;
	}

	message_vision("$N向$n请教发呆神功的诀窍。\n", me, this_object());

	if (me->query_temp("learned_idle_force"))
	{
		if (me->add_temp("too_many_xue", 1) > 3)
		{
			command("say 你好罗嗦！！！");
			message_vision("$n飞起一脚把$N踢出门外！\n",
				       me, this_object());
			me->set_temp("too_many_xue", 1);
			me->move("/d/city/beidajie1");
			me->unconcious();
		} else
			command("say 你先把我刚才教你的领悟好再说吧！");
		return -1;
	}

	command("say 听好了！发呆神功宗旨：!@#$%^&");

	if (me->query("potential") < me->query("learned_points") + 10)
	{
		write("你听得稀里糊涂，看来是潜能不够了。\n");
		return -1;
	}

	if (me->query_skill("idle-force", 1) > 500)
	{
		write("你听完了心想，这些我都懂啊，看来游讯也就知道这么多了。\n");
		return -1;
	}

	me->set_temp("learned_idle_force", 1);
	me->add("learned_points", 10);
	write(HIG "你听了心中颇有所得，马上进行发呆练习！"NOR"\n");
	return -1;
}

void append_receiver(object ob)
{
	if (! receiver)
		receiver = ({ ob });
	else
		if (member_array(ob, receiver) == -1)
			receiver += ({ ob });
}

int accept_object(object me, object ob)
{
	string wid;

	if (clonep(this_object()))
	{
		command("hehe");
		command("say 我是真游讯，如假包换啊！");
		return 1;
	}

	if (ob->id("visible bomb"))
	{
		command("say 不要了？那就还给我吧。");
		return 1;
	}

	if (! stringp(ob->query("money_id")))
	{
		switch (me->query_temp("youxun_refused"))
		{
		case 0:
			command("heihei");
			command("say 这种破烂你留着吧。");
			me->set_temp("youxun_refused", 1);
			return 0;

		case 1:
			message_vision("$N飞起一脚，把$n踢了出去，骂道：捣什么乱？\n",
				       this_object(), me);
			break;

		case 2:
			message_vision("$N飞起一脚，狠狠的把$n踢了出去，骂道：还来捣乱？\n",
				       this_object(), me);
			me->receive_damage("qi", 100);
			me->receive_wound("qi", 10);
			break;

		default:
			message_vision("$N大怒，一招万佛朝宗，就见$n像纸片一样飞了出去。\n",
				       this_object(), me);
			command("chat* heng " + me->query("id"));
			me->unconcious();
			break;
		}

		me->add_temp("youxun_refused", 1);
		me->move("/d/city/beidajie1");
		message_vision("只听“啪”的一声，$N狠狠的摔在了地上。\n", me);
		return -1;
	}

	if (ob->value() < 3000)
	{
		message_vision("$N接过$n递过去的" + ob->name() +
			       "，皱了皱眉，道：就这点钱？算了，你不要就给我吧！\n",
			       this_object(), me);
		destruct(ob);
		return 1;
	}

	me->delete_temp("youxun_refused", 1);
	if (stringp(wid = me->query_temp("pending/ask_youxun", 1)))
	{
		object fob;

		if (ob->value() < 500000)
		{
			message_vision("$N冷笑一声道：“就这点钱？你还是打发鲁有脚还差不多。”\n",
				       this_object());
			return 0;
		}

		me->delete_temp("pending/ask_youxun");
		fob = find_player(wid);
		if (! fob || ! me->visible(fob)) fob = find_living(wid);
		if (! fob || ! me->visible(fob) || ! environment(fob))
		{
			message_vision("$N挠挠头对$n道：“怪事... 刚才我还有他的消息呢，怎么这么一会儿...”\n",
				       this_object(), me);
			return 0;
		}

		destruct(ob);
		command("whisper " + me->query("id") +" 据可靠消息，这个人刚才在" +
			environment(fob)->short() + "。");
		return 1;
	}

	if ((int)me->query_temp("receive_rumor_time") < time())
		me->set_temp("receive_rumor_time", time());
	me->add_temp("receive_rumor_time", ob->value() / 3000 * 60);
	message_vision("$N乐得合不拢嘴，连忙接过" + ob->name() +
		       "，点头哈腰的对$n道：好！好！\n", this_object(), me);
	command("tell " + me->query("id") +
		sprintf(" 要是 %d 分钟内有人造谣，我一定揭穿他的老底。",
			(me->query_temp("receive_rumor_time") - time()) / 60));
	destruct(ob);
	append_receiver(me);
	return 1;
}

int ask_fee()
{
	int n;
	object me;

	me = this_player();
	if (me->query_temp("receive_rumor_time") < time())
	{
		command("say 不贵不贵，三十两银子包管一分钟！");
		return 1;
	}

	n = me->query_temp("receive_rumor_time") - time();
	n /= 60;
	if (! n)
	{
		command("tell " + me->query("id") +
			" 马上到时间啦，再想听消息，快点拿钱来啊！");
	} else
	{
		command("tell " + me->query("id") +
			sprintf(" 你还能听 %d 分钟的消息。", n));
	}

	message("visoin", name() + "嘀嘀咕咕的对" + me->name() +
			  "说了一些话。\n", environment(me), ({ me }));
	return 1;
}


private void restore_bomb()
{
	set_temp("bomb_count", 1);
}

void receive_report(object user, string verb)
{
	string msg;

	msg = sprintf("听说%s(%s)又要发谣言了。",
		      user->query("name"), user->query("id"));
	if (random(100) < 7)
	{
		command("heihei");
		command("say " + msg+"\n");
	}

	if (! receiver)
		return;

	receiver = filter_array(receiver, (: filter_listener :));
	if (! sizeof(receiver))
	{
		receiver = 0;
		return 0;
	}

	message("vision", HIG "游讯悄悄的告诉你：" + msg + "\n",receiver, user);
}

private int filter_listener(object ob)
{
	if (! objectp(ob))
		return 0;

	if (present("rumor generator", ob))
		return 1;

	if (ob->query_temp("receive_rumor_time") > time())
		return 1;

	ob->delete_temp("receive_rumor_time");
	return 0;
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
