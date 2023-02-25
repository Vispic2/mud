// qiulinshiye.c 秋林拾叶

inherit SKILL;

string *dodge_msg = ({
	"只见$n略一低头，形似弯腰拾叶，轻而易举的躲过$N这一招。\n",
	"但是$n目光流转，双肩微动，脚步轻移已避开了$N的攻击。\n",
	"然而$n微微移步向前，仿佛直走中宫却又飘忽不定，$N的攻势全部落空。\n"
        "但是$n身形如竹叶飞舞，随风绕着$N的出招飘动，好象要击中，却若无物。\n",
        "可是$n身随意转，仿佛闲庭散步，人却已在数丈以外，闪过了这一招。\n",
	"$n漫不经心的向左迈出一步，刚好避过$N的凌厉攻势。\n",
	"可是$n恰巧往右走了一步，躲过了$N这一招。\n",
	"只见$n一招「白鹤冲天」，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
	"$n一个「鹞子翻身」，向后纵出数丈之远，避开了$N的凌厉攻势。\n",
	"$n使出「大鹏展翅」，向一旁飘然纵出，轻轻着地。\n"
        "但是$n身形飘忽，轻轻一纵，早已避开。\n",
       "$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
        "可是$n侧身一让，$N这一招扑了个空。\n",
        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
        "$n身形微晃，有惊无险地避开了$N这一招。\n"
        });

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练秋林拾叶。\n");
        me->receive_damage("qi", 30);
        return 1;
}
string perform_action_file(string action)
{
		return __DIR__"qiulinshiye/" + action;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
