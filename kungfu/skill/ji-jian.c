//ji-jian.c 铚€灞卞熀纭€鍓戞硶
// by 浠欎緺宸笀鏉庣櫧
#include <ansi.h>
inherit SKILL;

mapping *action = ({
(["action" : "$N闈㈤湶寰瑧锛屾墜涓?w涓€鎶栵紝鍓戝厜鏆存定锛屾磼鍚?n鐨?l",
	"force"  : 30,
	"attack" : 30,
	"parry"  : 30,
	"dodge"  : 30,
	"damage" : 1000,
	"lvl"    : 0,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N韬舰绐侀棯锛屽墤鎷涢櫋鍙橈紝鎵嬩腑$w浠庝竴涓粷鎯充笉鍒扮殑鏂逛綅锛屾枩鍒哄悜$n鐨?l",
	"force"  : 40,
	"attack" : 30,
	"parry"  : 30,
	"dodge"  : 30,
	"damage" : 1100,
	"lvl"    : 10,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N鏆撮€€鏁板昂锛屼綆棣栨姎鍓戯紝闅忓悗鎵嬩腑$w楠ょ劧绌夸笂锛屽埡鍚?n鐨?l",
	"force"  : 50,
	"attack" : 30,
	"parry"  : 30,
	"dodge"  : 30,
	"damage" : 1300,
	"lvl"    : 20,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N韬舰涓€鏅冿紝鐤炬帬鑰屼笂锛屾墜涓?w榫欏悷涓€澹帮紝瀵瑰噯$n鐨?l杩為€掓暟鍓?,
	"force"  : 60,
	"attack" : 30,
	"parry"  : 30,
	"dodge"  : 30,
	"damage" : 1800,
	"lvl"    : 30,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N涓€闂€屼笂鎵戝悜$n锛屽褰遍殢褰紝鎵嬩腑$w鈥滈摦鈥濈劧鏈夊０锛屽悜$n鐨?l鍒哄幓",
	"force"  : 70,
	"attack" : 30,
	"parry"  : 30,
	"dodge"  : 30,
	"damage" : 1800,
	"lvl"    : 40,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N涓€涓晶韬紝鎵嬩腑$w鐤惧線鏂滀笂鎸戣捣锛岀洿鎸?n鐨?l",
	"force"  : 80,
	"attack" : 40,
	"parry"  : 40,
	"dodge"  : 40,
	"damage" : 2500,
	"lvl"    : 50,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N寰井涓€涓浆韬紝鎵嬩腑$w鍗村凡鑷倠涓嬬┛鍑猴紝缃╁悜$n鐨?l",
	"force"  : 90,
	"attack" : 50,
	"parry"  : 50,
	"dodge"  : 50,
	"damage" : 3500,
	"lvl"    : 60,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N绁炶壊寰彉锛屼竴鎷涖€屼腹鍑ゆ湞闃炽€嶏紝鍓戞嫑椤挎椂鍙樺緱鍑屽帀鏃犳瘮锛屾墜涓?w濡傚尮閾捐埇娲掑悜$n鐨?l",
	"force"  : 100,
	"attack" : 60,
	"parry"  : 60,
	"dodge"  : 60,
	"damage" : 4500,
	"lvl"    : 70,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N缂撶紦浣庨锛屾帴鐫€涓€鎷涖€屾礂鍓戞€€涓姳鏈堛€嶏紝鎵嬩腑$w涓鐩磋繘锛岃繀鎹锋棤姣斿湴寰€$n鐨?l鍒哄幓",
	"force"  : 110,
	"attack" : 70,
	"parry"  : 70,
	"dodge"  : 70,
	"damage" : 5500,
	"lvl"    : 80,
	"damage_type" : "鍒轰激"
]),
(["action" : "$N绾垫涓婅蛋锛屽崟鑵跨寷鍦拌涪鍚?n鑵伴棿锛?n姝ｈ鎶借韩鍥為槻锛屽彧瑙佸埞閭ｉ棿鍓戝厜涓€闂紝$n涓€鎷涖€岃繋闂ㄨ吙鍙嶅妶鍗庡北銆嶏紝$w宸茬粡鍙嶅妶鑰屼笅",         "force"  : 120,
	"attack" : 80,
	"parry"  : 80,
	"dodge"  : 80,
	"damage" : 6500,
	"lvl"    : 90,
	"damage_type" : "鍒轰激"
]),
(["action":"$N鐭韩渚ф锛屼竴鎷涖€岃繑鑵曠考寰烽棷甯愩€嶏紝鎵嬩腑$w鍙嶆墜鐤炬寫鑰屽嚭锛屸€滃敯鈥濈殑涓€澹板線$n鐨?l鍒哄幓",
	"force"  : 130,
	"attack" : 90,
	"parry"  : 90,
	"dodge"  : 90,
	"damage" : 6500,
	"lvl"    : 100,
	"damage_type" : "鍒轰激"
]),
(["action":"$N涓€鎷涖€岄粍榫欒浆韬悙椤汇€嶏紝钃﹀湴鐤鹃€€涓€姝ワ紝鍙堝啿鍓嶄笁姝ワ紝鎵嬩腑$w鍖栦负涓€閬撳噷鍘夌殑寮у厜寰€$n鐨?l鍒哄幓",
	"force"  : 140,
	"attack" : 100,
	"parry"  : 100,
	"dodge"  : 100,
	"damage" : 6500,
	"lvl"    : 110,
	"damage_type" : "鍒轰激"
]),
(["action":"$N涓€鎷涖€屼笂姝ヤ簯杈规憳鏈堛€嶏紝绾佃韩璺冭捣锛屼笉瑙佽釜褰憋紝鎺ョ潃鍗村張浠庡崐绌轰腑绌夸笅锛屽弻鎵嬫彙鐫€$w锛屽０鍔块€间汉鍦板埡鍚?n鐨?l",
	"force"  : 150,
	"attack" : 110,
	"parry"  : 110,
	"dodge"  : 110,
	"damage" : 6600,
	"lvl"    : 120,
	"damage_type" : "鍒轰激"
]),
(["action":"$N涓€鎷涖€屾彁鎾╁墤鐧介工鑸掔繀銆嶏紝鎵嬩腑$w鈥滃棨鈥濈殑涓€澹版枩鍒哄悜澶╃┖锛岄殢鍗冲悜涓嬧€滃埛鍒封€濅袱涓嬶紝鍒掑嚭涓€涓弶瀛楋紝寰€$n鐨?l鍒哄幓",
	"force"  : 160,
	"attack" : 120,
	"parry"  : 120,
	"dodge"  : 120,
	"damage" : 6610,
	"lvl"    : 130,
	"damage_type" : "鍒轰激"
]),
(["action":"$N宸﹁吙寰姮锛屼竴鎷涖€屽啿澶╂帉鑻忕Е鑳屽墤銆嶏紝宸︽墜铏氬嚮锛屽彸鎵?w鐚涘湴鑷笅鏂规寫璧凤紝婵€璧蜂竴鑲″姴椋庡弽鎸?n鐨?l",
	"force"  : 170,
	"attack" : 130,
	"parry"  : 130,
	"dodge"  : 130,
	"damage" : 6620,
	"lvl"    : 140,
	"damage_type" : "鍒轰激"
]),
});

string main_skill()
{
        return "ji-jian";
}

mapping sub_skills = ([
        "wuming1" : 500,
        "wuming2" : 500,
        ]);

int get_finish(object me)
{
           if( me->query("int")<50 )
        {
                tell_object(me, "浣犳紨缁冨畬姣曪紝瑙夊緱棰嗘偀涓嶅埌浠€涔堬紝涓嶇涓€鐗囪尗鐒躲€俓n");
                return 0;
        }
        if( me->query("con")<50 )
        {
                tell_object(me, "浣犳紨缁冨畬姣曪紝灏辫寰楃溂鍓嶉噾鏄熶贡鍐掞紝澶槼绌寸獊绐佺殑璺炽€俓n");
                return 0;
        }

        if( me->query_skill("literate",1) <500 )
        {
tell_object(me, "浣犺寰楄渶灞卞熀纭€鍓戞硶涓嶅お濂芥噦锛岀湅鏉ラ渶瑕佹彁楂樺闂墠琛屻€俓n");
            return 0;
        }
        
        if( me->query_skill("lamaism",1) <500 )
        {
tell_object(me, "浣犳紨缁冨畬锛屽彂鐜板鏋滈€氭檽瀵嗗畻蹇冩硶搴旇鏇存湁甯姪銆俓n");
            return 0;
        }
        
        if( me->query_skill("buddhism",1) <500 )
        {
tell_object(me, "浣犳紨缁冨畬锛屽彂鐜板鏋滈€氭檽绂呭畻蹇冩硶搴旇鏇存湁甯姪銆俓n");
            return 0;
        }
        
        if ((int)me->query("max_neili") < 20000)
        {
tell_object(me, "浣犺寰楀唴鍔涗笉缁э紝鏃犳硶铻嶄細璐€氫袱閮ㄦ棤鍚嶅墤娉曟畫绡囥€俓n");
            return 0;
        }

        if (random(10)<7)
        {
        tell_object(me, "浣犺寰楁湁鎵€鏀惰幏锛屾垨璁稿啀婕旂粌涓€娆″氨鑳借瀺浼氳疮閫氾紝瀛︽垚铚€灞卞熀纭€鍓戞硶銆俓n");
                return 0;
        }

        tell_object(me, HIW "涓€闃靛嚒灏樺線浜嬫秾涓婂績澶达紝浣犲嚑娆叉斁澹伴暱鍙广€傜溂鍓嶄笉鏂诞鐜颁袱閮ㄦ棤鍚嶅墤娉曟畫绡囩殑鎷涘紡锛岄湈閭ｉ棿锛屼綘缁堜簬閫氭檽铚€灞卞熀纭€鍓戞硶銆俓n" NOR);

        CHANNEL_D->do_channel(this_object(), "rumor", "鍚" + me->name() + "婕旂粌鍑?HIY"铚€灞卞熀纭€鍓戞硶"HIM"銆俓n");
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage) { return usage == "sword"||usage == "parry"; } 

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 5000)
		return notify_fail("浣犵殑鍐呭姏淇负澶祬銆俓n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("浣犵殑鍩烘湰鍐呭姛淇负涓嶈冻銆俓n");

	if ((int)me->query_skill("martial-cognize") < 200)
		return notify_fail("浣犺寰楄繃浜庢繁濂ワ紝浠ヨ嚜宸辩殑姝﹀淇吇鍏ㄧ劧鏃犳硶鏄庣櫧銆俓n");

		if (me->query("str") < 50)
                return notify_fail("浣犵殑鍏堝ぉ鑷傚姏涓嶈冻鏃犳硶瀛︿範銆俓n");
        if (me->query("dex") < 50)
                return notify_fail("浣犵殑鍏堝ぉ韬硶涓嶈冻鏃犳硶瀛︿範銆俓n");
		if (me->query("int") < 50)
                return notify_fail("浣犵殑鍏堝ぉ鏅哄晢涓嶈冻鏃犳硶瀛︿範銆俓n");
        if (me->query("con") < 50)
                return notify_fail("浣犵殑鍏堝ぉ鏍归涓嶈冻鏃犳硶瀛︿範銆俓n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("ji-jian", 1))
		return notify_fail("浣犵殑鍩烘湰鍓戞硶姘村钩鏈夐檺銆俓n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i]["lvl"])
	return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
   int i,j,level;
   level   = (int) me->query_skill("ji-jian",1);
   for(i = sizeof(action); i > 0; i--){       if(level > action[i-1]["lvl"]){
       j=NewRandom(i,20,level/5);
       if ((int)me->query_skill("ji-jian", 1) > 500){
    return([
        "action":HIR+replace_string(replace_string(action[j]["action"],"$w","$W"),"$W","$w"HIR)+NOR,
    "force":3000,
    "dodge":3000,
    "parry":3000,
    "damage":3000,
    "damage_type":"鍓戜激",
    ]);
   }
   else return action[j];
   }
}
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("浣犱娇鐢ㄧ殑姝﹀櫒涓嶅銆俓n");

	if ((int)me->query("qi") < 60)
		return notify_fail("浣犵殑浣撳姏鐩墠鏃犳硶缁冧範铚€灞卞熀纭€鍓戞硶銆俓n");

	if ((int)me->query("neili") < 70)
		return notify_fail("浣犵殑鍐呭姏涓嶅锛屾棤娉曠粌涔犺渶灞卞熀纭€鍓戞硶銆俓n");

	me->add("qi", 30);
	me->add("neili", -62);
	return 1;
}

void skill_improved(object me)
{
 int i;
 string *sub_skillnames;
 sub_skillnames = keys(sub_skills);
 for(i=0;i<sizeof(sub_skillnames);i++)
 me->delete_skill(sub_skillnames[i]);
}
string perform_action_file(string action)
{
	return __DIR__"ji-jian/" + action;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
