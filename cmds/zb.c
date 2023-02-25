//by name

#include <weapon.h>
inherit SWORD;
string long();
void create()
{
	set_name(HIR"死神镰刀"NOR, ({ "sword" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄测试剑\n");
		set("value", 100000);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
		
set("level",10);        //品阶
set("xilie","死神");     //系列
set("yuansu","金");    //品阶
set("gong",999);      //攻击
set("fang",999);       //防御
set("bao",999);        //暴击
set("po",999);         //破甲
set("shan",999);       //闪避
set("pfm","百分之一的概率秒杀对手！");
	}
	init_sword(180);
	setup();
}
string long()
{
string res=query("long");
res+="------------------------------------\n";
res+=HIY"【当前品阶】："+(query("level")?""+query("level")+"":"无")+"\n";
res+=HIW"【系列】："+(query("xilie")?""+query("xilie")+"":"无")+"\n";
res+=HIW"【元素】："+(query("yuansu")?""+query("yuansu")+"":"无")+"\n";
res+=HIR"【攻击】："+(query("gong")?""+query("gong")+"":"无")+"\n";
res+=HIR"【防御】："+(query("fang")?""+query("fang")+"":"无")+"\n";
res+=HIM"【暴击率】："+(query("bao")?""+query("bao")+"":"无")+"\n";
res+=HIM"【破甲率】："+(query("po")?""+query("po")+"":"无")+"\n";
res+=HIM"【闪避率】："+(query("shan")?""+query("shan")+"":"无")+"\n";
res+=HIC"【绝招说明】："+(query("pfm")?""+query("pfm")+"":"无")+"\n";

return res;
}


int move(mixed dest)
{
if( ::move(dest)==0) return 0;
//message("channel:rumor",YEL" [至尊上线] "HIR"欢迎:尊敬的至尊用户"+dest->query("name")+ "连线进入游戏！\n"NOR,users());
return 1;
}
mixed hit_ob(object me, object ob, int damage_bonus)
{
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
