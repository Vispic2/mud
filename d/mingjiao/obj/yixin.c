// yixin.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("阳教主遗信", ({"yi xin", "xin", "letter"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long", @LONG
夫人亲启：

    夫人妆次：夫人自归阳门，日夕郁郁。余粗鄙寡德，无足为欢，甚可歉咎，
兹当永别，唯夫人谅之。三十二代衣教主遗命，令余练成乾坤大挪移神功后，率
众前赴波斯总教，设法迎回圣火令。本教虽发源于波斯，然在中华生根，开枝散
叶，已数百年于兹。今鞑子占我中土，本教誓与周旋到底，决不可遵波斯总教无
理命令，而奉蒙古元人为主。圣火令若重入我手，我中华明教即可与波斯总教分
庭抗礼也。

    今余神功第四层初成，即悉成昆之事，血气翻涌不克自制，真力将散，行当
大归。天也命也，复何如耶？

    今余命在旦夕，有负衣教主重托，实为本教罪人。盼夫人持余此亲笔遗书，
召聚左右光明使者、四大护教法王、五行旗使、五散人，颁余遗命曰：“不论何
人重获圣火令者，为本教第三十四代教主。不服者杀无赦。令谢逊暂摄副教主之
位，处分本教重务。”

    乾坤大挪移心法暂由谢逊接掌，日后转奉新教主。光大我教，驱除胡虏，行
善去恶，持正除奸，令我明尊圣火普惠天下世人，新教主其勉之。

    余将以身上残存功力，掩石门而和成昆共处。夫人可依秘道全图脱困。当世
无第二人有乾坤大挪移之功，即无第二人能推动此‘无妄’位石门，待后世豪杰
练成，余及成昆骸骨朽矣。

						 顶天谨白。

    余名顶天，然于世无功，于教无勋，伤夫人之心，赍恨而没，狂言顶天立地，
诚可笑也。
LONG );
		set("material", "paper");
	}
}

string long()
{
	return query("long") + HIG "
你看完心底暗自寻思，想不到阳教主这封信和乾坤大挪移心法却是没能送了出去。
阳夫人自杀殉情，便使这遗信和心法几乎长眠于此了，若是千百年后才能有人来
此，却不知道还能看到否？"NOR"\n";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
