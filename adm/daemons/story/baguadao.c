// story:baguadao 紫金八卦刀

#include <ansi.h>

static string char_id;
static string char_name;
static string family_name;

int give_gift();
object select_character();

static mixed *story = ({
	"胡一刀大笑道：“商剑鸣，到了此时你还是束手就擒吧！”",
	"商剑鸣：“商某与阁下无冤无仇，今日苦苦相逼究是为何？”",
	"胡一刀：“苗家一家上下数十口性命，他们又和你有什么仇？受死吧！”",
	"商剑鸣只见对方剑锋一闪，暗道：“我命休矣！”",
	"——镪——",
	"只见一柄长剑飞插上了横梁。",
	"胡一刀虎目圆瞪，道：“你是谁？为何插手此事？”",
	"商剑鸣睁开双眼，只见一人左手负后，右手提一柄单刀，面色沉着。",
	"那人谈谈的道：“阁下技胜一筹，何必又非要赶尽杀绝？”",
	"胡一刀：“他欠苗人凤几十条性命，今天此仇不能不报。”",
	"那人道：“苗人凤是你朋友？”",
	"胡一刀：“不是，我也是他的仇人。”",
	"那人冷笑一声道：“原来阁下是怕了苗人凤，想拿商剑鸣的人头来换你自己的人头！”",
	"那人又接着道：“既然如此，我不插手好了！”",
	"胡一刀大怒道：“呸！我胡一刀岂是这种卑鄙下流之人！”",
	"那人冷冷的道：“原来你就是人称‘辽东大侠’的胡一刀？”",
	"胡一刀：“正是在下！”",
	"那人又冷笑一声，道：“我生平最恨的就是你们这些所谓的大侠，这事我管定了。”",
	"胡一刀怒极，拔出了腰间单刀，喝道：“好！我就领教你的高招！进招吧！”",
	"那人哼了一声，身形一展，扑了上去。",
	"呛！",
	"镪！",
	"~嗤啦！~",
	"~~~啊！~~~",
	"…………",
	"那人道：“现在阁下还有什么话说？”",
	"只见胡一刀右手血流不断，看着地上的两根断指，一张黑脸涨得通红，半天说不出话。",
	"胡一刀摇了摇头，苦笑道：“胡某只得今日才知‘天外有天，人外有人’四字。”",
	"那人也不理睬，淡淡的道：“既然如此，那么阁下请便吧。”",
	"…………",
	"商剑鸣：“请问恩人尊姓大名？今日之恩，商某今生难以回报！”",
	"那人道：“哼！你是什么东西，也配我的姓名？今日是你运气好而已，也别谢我。”",
	"那人顿了一顿，接着道：“告诉你也无妨，$F$N便是在下。”",
	"商剑鸣：“这套紫金八卦刀法乃我商家祖传秘诀，绝不输于他胡家刀法，恩人可以参详一翻。”",
	(: give_gift :),
});

void create()
{
	seteuid(getuid());

	if (! objectp(select_character()))
	{
		destruct(this_object());
		return;
	}
}

string prompt() { return HIR "【武林传闻】" NOR; }

object select_character()
{
	object *obs;
	object ob;

	obs = filter_array(all_interactive(),
			   (: ultrap($1) &&
			      living($1) &&
			      $1->query_skill("zijinbagua-dao", 1) < 1 &&
			      $1->query_skill("blade", 1) > 120 &&
			      $1->query_skill("sword", 1) > 100 &&
			      $1->query("family/family_name") &&
			      $1->query("family/family_name") != "关外胡家" &&
			      $1->query("born_family") != "关外胡家" &&
			      $1->query("shen") < 0 &&
			      ! wizardp($1) &&
			      ! $1->query("story/baguadao") :));
	if (! sizeof(obs))
		return 0;

	ob = obs[random(sizeof(obs))];
	char_id = ob->query("id");
	char_name = ob->name(1);
	family_name = ob->query("family/family_name");
	return ob;
}

mixed query_story_message(int step)
{
	mixed msg;

	if (step >= sizeof(story))
		return 0;

	msg = story[step];
	if (stringp(msg))
	{
		msg = replace_string(msg, "$N", char_name);
		msg = replace_string(msg, "$F", family_name);
		msg = replace_string(msg, "$ID", char_id);
	}
	return msg;
}

int give_gift()
{
	object ob;

	ob = find_player(char_id);
	if (! ob) return 1;

	if (ob->query_skill("zijinbagua-dao", 1) < 50)
		ob->set_skill("zijinbagua-dao", 50);

	ob->set("story/baguadao", 1);
	tell_object(ob, HIC "你从商剑鸣那里学习到了紫金八卦刀。"NOR"\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
			      "从商剑鸣那里学习到了紫金八卦刀。");
	STORY_D->remove_story("baguadao");
	return 1;
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
