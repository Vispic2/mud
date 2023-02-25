
#include <ansi.h>

// 内部函数
string show_time();
mixed  create_challenger();
mixed  master_opinion(int n);
mixed  continue_story(int n);
int    find_respond(object ob);

// 外部可以调用的函数
void   stop_story();
string cannot_respond(object ob);
void   respone_for_challenge(object me);

mixed *story = ({
	(: show_time :),
	"一个神秘的人来到了中原...",
	(: create_challenger :),
	(: master_opinion, 1 :),
	(: master_opinion, 2 :),
	(: master_opinion, 3 :),
	(: master_opinion, 4 :),
});

string *where_list = ({
	"/d/city/guangchang",
	"/d/xiangyang/guangchang",
});

#define NOT_READY		       0
#define CHALLENGER_IS_WAITING	   1
#define NO_USER_CAN_RESPOND	     2
#define CHALLENGER_KILLED_BY_ULTRA      3
#define CHALLENGER_IS_TOO_CHEAP	 4
#define CHALLENGER_IS_FIGHTING	  5

int stop;	       // FLAG: 是否需要终止故事
int too_cheap;	  // FLAG: 敌人的水平是否太差(相比最高水平玩家而言)
int next;	       // continue_story函数根据改值继续
string accepted;	// 应战者姓名
object cob;	     // 挑战者
object rob;	     // 应战者
object *ultra ;	 // 大宗师

string *too_cheap_msg = ({
	"$N怒道：“谁敢这么说？你算是什么人？”",
	"“砰”的一声，$N被打得飞了出去，眼看是活不成了。",
	"达摩祖师：“罪过！罪过！”",
});

string *fenco = ({
	"王语嫣", "黄蓉", "赵敏", "苗若兰",
	"袁紫衣", "水笙", "阿珂", "岳灵珊",
	"霍青桐", "小龙女",
});

string *fenmsg = ({
	"快快快！$C！快快快！",
	"冲啊！$C！冲啊！$C！",
	"$C，加油！$C加油！",
	"$C努力呀！就看你的啦！",
	"$C不要退，往上冲！加油！加油！加油！",
});

string *menco = ({
	"胡斐", "苗人凤", "狄云", "段誉",
	"尹志平", "韦小宝", "令狐冲", "陈家洛",
	"杨过", "石破天", "张无忌", "袁承志",
});

string *menmsg = ({
	"$N，不要怕，往上攻！",
	"$N！攻他上身，他拳脚功夫不行！",
	"$N！攻他下三路，他下盘不稳！",
	"$N快攻他正手，他正手反应慢！",
	"$N还不快攻他反手，他反手力道不行！",
});

string prompt() { return HIR "【挑战】" NOR; }

void create()
{
	seteuid(getuid());
	stop = 0;
	too_cheap = 0;
	accepted = 0;
	cob = 0;
	rob = 0;
	ultra = 0;
}

mixed query_story_message(int step)
{
	if (stop) return 0;
	return step < sizeof(story) ? story[step] :
				      continue_story(step - sizeof(story));
}

string show_time()
{
	return "江湖历" + NATURE_D->game_time() + "。";
}

mixed create_challenger()
{
	object ob;
	object *u;
	int i,tmp,lv;
	string where;

	ob = NPCS_D->create_challenger();

	if (! ob)
	{
		stop_story();
		return "结果迷路了...";
	}

	u = all_interactive();
	lv = 3;
	for(i=0;i<sizeof(u);i++)
	{
		tmp = to_int(pow(to_float(u[i]->query("combat_exp")*10),0.33333333));
		if(lv<tmp) lv = tmp;
	}
	ob->set_lvl(lv);
	where = where_list[random(sizeof(where_list))];
	ob->move(where);
	message("vision", ob->name() + "大摇大摆的走了过来，当街一立！\n", environment(ob));
	CHANNEL_D->do_channel(this_object(), "rumor", "听说从" + ob->query("nation") + "来了一个名叫" + ob->name(1) + "的人。");
//	QQ_D->msg("【谣言】听说从" + no_color(ob->query("nation")) + "来了一个名叫" + no_color(ob->name(1)) + "的人。");
	next = NOT_READY;
	cob = ob;
	return ob->name() + "：“" + ob->challenge() + "”";
}

mixed master_opinion(int n)
{
	object ob;
	object *u;

	if (n == 1)
		ultra = NPCS_D->query_ultra_master();

	ultra -= ({ 0 });
	if (! sizeof(ultra))
		ultra = NPCS_D->query_ultra_master();

	if (! cob)
	{
		stop_story();
		return "怎么人突然吭都不吭一声就溜走了？";
	}

	ob = ultra[random(sizeof(ultra))];
	ultra -= ({ ob });

	if (n < 4)
	{
		ob->force_me("chat " + cob->query("opinion/msg")[n - 1]);
		return 1;
	}

	u = all_interactive();
	if (! sizeof(u))
	{
		if (! too_cheap)
		{
			ob->force_me("chat 可惜啊可惜，现在江湖中竟然无人能收拾此人！");
			next = NO_USER_CAN_RESPOND;
			return 1;
		}

		if (cob->query("nation") == "日本")
		{
			ob->force_me("chat 哼！哪里来的日本鬼子？吃" + RANK_D->query_self(ob) + "一招！");
			next = CHALLENGER_KILLED_BY_ULTRA;
			return 1;
		}

		ob->force_me("chat 哈哈！中原能收拾你的人多了！你武功太差，不值得让人出手，滚吧！");
	//	QQ_D->msg("【异域】哈哈！中原能收拾你的人多了！你武功太差，不值得让人出手，滚吧！");
		next = CHALLENGER_IS_TOO_CHEAP;
		return 1;
	}

	if (sizeof(u) < 10)
	{
		ob->force_me("chat* sigh");
		ob->force_me("chat 江湖能收拾此人的固然不少，不过合适的确是寥寥无几。");
//		QQ_D->msg("【异域】江湖能收拾此人的固然不少，不过合适的确是寥寥无几。");
	} else
	{
		ob->force_me("chat* heng");
		ob->force_me("chat 这人来找死！能摆平它的人大有人在！");
//		QQ_D->msg("【异域】这人来找死！能摆平它的人大有人在！");
	}
	ob->force_me("chat 众江湖豪杰，速去扬我中原武林威风！！");
	//QQ_D->msg("【异域】众江湖豪杰，速去扬我中原武林威风！！");
	next = CHALLENGER_IS_WAITING;
	return 1;
}

mixed continue_story(int n)
{
	string msg;

	if (! cob)
		return 0;

	switch (next)
	{
	case CHALLENGER_IS_TOO_CHEAP:
		if (n >= sizeof(too_cheap_msg))
		{
			stop_story();
			return 0;
		} else
			return replace_string(too_cheap_msg[n], "$N", cob->name(1));
		return;

	case CHALLENGER_KILLED_BY_ULTRA:
		cob->force_me("chat 八格呀路！");
		CHANNEL_D->do_channel(this_object(), "rumor", "听说日本鬼子" + cob->name(1) + "被打得他妈都认不出他来了。");
		destruct(cob);
		stop_story();
		return 0;

	case NO_USER_CAN_RESPOND:
		cob->force_me("chat* haha");
		stop_story();
		CHANNEL_D->do_channel( this_object(),
			"rumor", "听说来自" + cob->query("nation") +
			"的" + cob->name(1) + "在中国居然没有对手，真是中原武林的奇耻大辱！");
		return cob->name(1) + "：“中原武林，不过如此！我去了！”";

	case CHALLENGER_IS_FIGHTING:
		if (! rob || environment(rob) != environment(cob))
		{
			stop_story();
			if (rob)
			{
				rob->add("weiwang", -rob->query("weiwang") / 10);
				rob->lost();
			}
			CHANNEL_D->do_channel( this_object(),
			"rumor", "听说" + accepted + "在和" + cob->query("nation") +
			"" + cob->name(1) + "交手的时候临阵脱逃，使中原武林蒙羞！");
			return cob->name(1) + "狂笑不止：“懦夫！中国都是一些懦夫！哈哈！”";
		}

		if (random(3)) return 1;
		if (rob->query("gender") == "男性")
			msg = fenco[random(sizeof(fenco))] + "大声喊道：" +
			      fenmsg[random(sizeof(fenmsg))];
		else
			msg = menco[random(sizeof(menco))] + "大声喊道：" +
			      menmsg[random(sizeof(menmsg))];
		msg = replace_string(msg, "$N", rob->name(1));
		msg = replace_string(msg, "$C", RANK_D->query_respect(rob));
		return msg;
	}

	switch (n)
	{
	case 1:
		return cob->name(1) +
		       (random(2) ? "：“怎么，没人敢来应战么？那我再等等！”"
				  : "：“嘿嘿，都是一些胆小鬼！”");

	case 6:
		return cob->name(1) +
		       (random(2) ? "似乎等得很不耐烦。"
				  : "一会儿看看天空，一会儿望望地面，看起来很是悠闲。");

	case 11:
		return cob->name(1) +
		       (random(2) ? "：“怎么，还有没人敢来应战么？你们真是让我失望！”"
				   : "：“说什么中土武学博大精深，原来都是谣传。”");

	case 16:
		return cob->name(1) +
		       (random(2) ? "摇摇头，又叹叹气，一副不屑的样子。”"
				   : "哼了一声，满脸尽是不屑。");
/*
	case 21:
		return cob->name(1) +
		       (random(2) ? "：“算了！我看我还是走吧！”"
				   : "：“我也算是来过了，看来还是不要在这浪费时间了。”");
*/

	case 2700:
		return cob->name(1) +
		       (random(2) ? "：“中原武林，全都是一些缩头乌龟！算了，我准备走了！”"
				   : "：“哈哈哈哈！什么武术？都是一些骗人的东西！我准备走了！”");

	case 2705:
		CHANNEL_D->do_channel(this_object(), "rumor", "听说来自" +
			cob->query("nation") + "的" + cob->name(1) + "在中国"
			"耀武扬威了一番后安然的回国去了，真是耻辱。");
		return 0;
	}

	return 1;
}

void stop_story()
{
	stop = 1;
}

void remove()
{
	if (cob)
	{
		if (environment(cob))
		{
			message("vision", cob->name() + "脸色苍白，脚步踉跄，灰溜溜地狼狈而逃。\n", environment(cob));
		}
		destruct(cob);
	}
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
