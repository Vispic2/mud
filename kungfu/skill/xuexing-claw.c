// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// taotao
// 丹辰子
// 丐帮第二十代弟子
// 2003513
// 男性
// claw
// 血腥爪





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N一手扳住$n上腭，一手扳住下颌，用力一分，把$n下巴撕了下来",
"force" :60,
"dodge" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "扳下巴"
]),
// ZHAOSHI :1

([
"action" :"$N扑向$n，一口咬住$n的喉咙，喀嚓一声$n的食管，气管，血管全都被撕得希巴烂，像一堆烂麻绳",
"force" :90,
"dodge" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "咬血管"
]),
// ZHAOSHI :2

([
"action" :"$N五指插进$n天灵盖，喀的一声扳开头骨，把$n脑浆一把抓了出来，舔了几口",
"force" :120,
"dodge" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "抓脑浆"
]),
// ZHAOSHI :3

([
"action" :"$N一手摁住$n喉咙，咬向$n胸腹，三两口就啃得见了肋骨，几下就把$n胸腹肌肉撕扯殆尽，心肺等内脏清晰可见",
"force" :150,
"dodge" :100,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "吃内脏"
]),
// ZHAOSHI :4

([
"action" :"$N一声狞笑，踩住$n脊背，抓住$n双手，啪的一声将两臂硬拽了下来，手臂与身体连接处血肉模糊，白骨森森",
"force" :180,
"dodge" :120,
"damage_type": "瘀伤",
"lvl" : 4,
"skill_name" : "拽手臂"
]),
// ZHAOSHI :5

([
"action" :"$N踩住$n的背，一用劲，咯的一声闷响，$n的脊椎骨断成十七二十八截，$N再从$n身体中血淋淋地扯出半条不成模样的脊椎骨",
"force" :210,
"dodge" :140,
"damage_type": "瘀伤",
"lvl" : 5,
"skill_name" : "拆脊椎"
]),
// ZHAOSHI :6

([
"action" :"$N抓住$n两条腿，使劲一撕，把$n撕成两片，鲜血四溅，$n的内脏稀里乎噜流了一地",
"force" :240,
"dodge" :160,
"damage_type": "瘀伤",
"lvl" : 6,
"skill_name" : "撕双腿"
]),
 });
// ZHAOSHI :7
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"血腥爪"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "claw" || usage=="parry"; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level = (int)me->query_skill("xuexing-claw",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
