//称号

#pragma optinmize
#pragma save_binary

#include <ansi.h>

//可加成基本属性值


mapping titles=([
"庇护":(["obtain":"永远支持本MUD即可","con":1,"max_qi":100]),
"毒仙":(["obtain":"冰蚕寒功>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"剑魔":(["obtain":"独孤九剑>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"武者":(["obtain":"基本内功>200","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"太极":(["obtain":"太极神>500、太极拳>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"阳圣":(["obtain":"乾坤大挪移>500、九阳神功>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"杀神":(["obtain":"杀生>100万次","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"北冥潇":(["obtain":"凌波微步>500、北冥神功>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"南慕容":(["obtain":"斗转星移>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"侠客行":(["obtain":"太玄功>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"暗夜鬼魅":(["obtain":"辟邪剑法>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"碧海潮生":(["obtain":"玉箫剑法>500、碧海潮生曲>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"富可敌国":(["obtain":"元宝>666666","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"龙象之力":(["obtain":"龙象般若功>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"雪上飞狐":(["obtain":"冷月神功>500、胡家刀法>500","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"倾城倾国":(["obtain":"性别：女性、容貌>50点","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"陌上君子":(["obtain":"性别：男性、容貌>50点","con":1,"dex":1,"int":1 ,"str":1,"max_qi":100]),
"奢华贵族":(["obtain":"VIP等级>5级","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"盖世齐天":(["obtain":"四维各>100点","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),
"百岁老人":(["obtain":"年龄>100岁","con":1,"dex":1,"int":1,"str":1,"max_qi":100]),

]);
//转换为中文名称
mapping chinesename=([
"str":"臂力",
"int":"悟性",
"con":"根骨",
"age":"年龄",
"dex":"身法",
"max_jing":"精神上限",
"max_jingli":"精力上限",
"max_qi":"气血上限",
"max_neili":"内力上限",
"yanjiux":"研究效率",
"yanjiuc":"研究次数",
"baoji":"暴击率",
"baojixg":"暴击效果",
"xixue":"吸血率",
"weiwang":"需要威望",
"sm":"称号说明",
"bodyreset":"重修次数",
"blevel":"肉身等级",
"per":"容貌",
"zjvip/level":"vip等级",
"yuanbao":"元宝",
"qiangdaotask":"衙门贡献",
"gender":"性别",
"combat/MKS":"杀人数",
"combat/dietimes":"死亡次数",
"obtain":HIR"获取方式"NOR,
]);

//需要达标的属性值
mapping need_attribute=([
"富可敌国":(["yuanbao":666666]),
"倾城倾国":(["per":50,"gender":"女性"]),
"陌上君子":(["per":50,"gender":"男性"]),
"奢华贵族":(["zjvip/level":5]),
"杀神":(["combat/MKS":1000000]),
"盖世齐天":(["str":100,"con":100,"int":100,"dex":100]),
"百岁老人":(["age":100]),
]);


//需要达标的技能
mapping need_skill=([
"武者":(["force":200]),
"毒仙":(["freezing-force":500]),
"剑魔":(["lonely-sword":500]),
"太极":(["taiji-shengong":500,"taiji-jian":500]),
"阳圣":(["qiankun-danuoyi":500,"jiuyang-shengong":500]),
"北冥潇":(["beiming-shengong":500,"lingbo-weibu":500]),
"南慕容":(["douzhuan-xingyi":500]),
"侠客行":(["taixuan-gong":500]),
"暗夜鬼魅":(["pixie-jian":500]),
"碧海潮生":(["yuxiao-jian":500,"bihai-chaosheng":500]),
"龙象之力":(["longxiang-gong":500]),
"雪上飞狐":(["lengyue-shengong":500,"hujia-daofa":500]),
]);

void create(){seteuid(getuid());}

int use_title(object me,string title)
{
mixed xg=titles[title];
string *att,at;
att=keys(xg);
me->delete("tltlea");
foreach(at in att)
{
if(intp(xg[at]))
me->set("titlea/"+at,xg[at]);
}
me->set("chenghao",title);
tell_object(me,"你佩戴了成就:"HIC+title+NOR+"\n");
return 1;
}
string query_xg(object me,string title)
{
string msg,msgg;
mixed xg=titles[title];
if (xg){
msg=HIR+xg["obtain"]+NOR;
}
else
msg=HIR"该称号无任何加成"NOR;
return msg;
}

string query_yq(object me,string title)
{
string msg,msgg;
mixed xg=titles[title];
if (xg){
msg="";
foreach (msgg in keys(xg))
if (intp(xg[msgg]))
msg+=GRN+chinesename[msgg]+"+"+xg[msgg]+NOR;
}
else
msg=GRN"该称号无任何加成"NOR;
return msg;
}
string query_title(object me,string title)
{
string msg,msgg;
mixed xg=titles[title];
    if (xg)
{

msg=chinesename["obtain"]+":"+xg["obtain"]+"\n";
msg+=HIC+NOR+ZJBR"================称号加成================\n";
if (xg["sm"])
msg+=chinesename["sm"]+":\n"+xg["sm"]+"\n";

foreach (msgg in keys(xg))
if (intp(xg[msgg]))
msg+=HIY"("+chinesename[msgg]+")"NOR+HIW":"+xg[msgg]+NOR"\n";



 }
else
msg="该称号无任何加成";
	return msg;
}

mapping alltitles()
{
return titles;
}
//购买称号处理
int buy_title(object me,string title)
{
string att,*allatt;
mapping attribute;
//先计算属性是否达标


if(me->query("titles/"+title))
{
tell_object(me,"你已经完成这个成就了\n");
return 1;
}

if (need_attribute[title])
{
allatt=keys(need_attribute[title]);
attribute=need_attribute[title];
foreach(att in allatt)
if(me->query(att)<attribute[att])
{
tell_object(me,"你未达成"+chinesename[att]+"："+me->query(att)+"/"+attribute[att]+"要求。\n");
return 1;
}
}

//再计算技能是否达标
if(need_skill[title])
{
allatt=keys(need_skill[title]);
attribute=need_skill[title];
foreach(att in allatt)
if(me->query_skill(att,1)<attribute[att])
{
tell_object(me,"你的"+to_chinese(att)+"低于"+(attribute[att])+"级。\n");
return 1;
}
}

//最后计算声望是否足够

attribute=titles[title];
/*
if(me->query("reputation")<attribute["reputation"])
{
tell_object(me,"你的声望不够。\n");
return 1;
}
*/
//by name  称号加成
//printf("执行结果：%O\n",attribute);
//if(attribute){
foreach(att in keys(attribute)){
if(att=="int"||att=="str"||att=="dex"||att=="con"||att=="max_qi"){
//printf("执行结果：加成:%O 值:%O\n",att,attribute[att]);
me->add(att,attribute[att]);
me->add("titles/"+att+"",attribute[att]);
}
}
//}
me->set("titles/"+title,1);
tell_object(me,"恭喜你获得成就"+HIC+title+"\n"NOR);

return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
