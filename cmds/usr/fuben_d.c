// fuben_d
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string str)
{
object room;
    	
	if(environment(me)->query("no_magic", 1))
		return notify_fail("这里无法使用这个功能。\n");
	if (me->is_ghost())
		return notify_fail("你还是等还了阳再说吧。\n");
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中。\n");
	if (!me->query("born"))
	    return notify_fail("你还没出生呢。。。\n");
 
if(!str){
write(ZJOBLONG + "副本任务"ZJBR"低级小于300w 中级500-800w 高级高于1000w经验\n" + 
ZJOBACTS2+ZJMENUF(3,3,9,31) + 
"武馆训练[低级]:fly wuguan"ZJSEP
"试炼草人[低级]:fuben_d caoren"ZJSEP
"迷失幻境[低级]:fuben_d huanjing"ZJSEP
"伏击金兵[中级]:fly jinbing"ZJSEP
"单骑破元[中级]:fly danbing"ZJSEP
"勇闯魔窟[中级]:fuben_d moku"ZJSEP
"十三皇陵[高级]:fly shisan"ZJSEP
"每日签到[公共]:fly qiandao"ZJSEP
"千尺瀑布[公共]:fly pubu"ZJSEP
"镇魂妖塔[公共]:fly zht"ZJSEP
"华山论剑[公共]:fly lunjian"ZJSEP
"武林大会[公共]:fly lunjians"ZJSEP
"屠人之场[公共]:fly turen"ZJSEP
"灵脉山洞[活动]:fly lm"ZJSEP
"守卫襄阳[活动]:fly shouwei"ZJSEP
"凌云大门[活动]:fly lingyun"ZJSEP
"公益活动[活动]:fly gyhd"ZJSEP
"帮派战斗[帮会]:fly bpzd"ZJSEP
"王陵争霸[帮会]:fly wlzb"ZJSEP
"镖行天下[组队]:fly hubiao"ZJSEP
"团队剿匪[组队]:fly jiaofei"ZJSEP
"五行神兽[门票]:fly slzd"ZJSEP
"西夏校场[门票]:fly xxxc"ZJSEP
"\n");
return 1;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
      if (str == "moku") {
//       if(me->query("combat_exp")<5000000||me->query("combat_exp")>8000000){
// tell_object(me, "此副本属于中级副本，经验高于500万且小于800万，不能挑战了！"NOR"\n");
// return 1;
// }
        if(!objectp(room = new("/d/fuben_moku/moku"))){
        	write("副本开启失败。\n");
        	return 1;
        }
        	if(!room->start_fuben_moku(this_player()))
        	destruct(room);
        	return 1;
        }
        if (str == "caoren"){
//         if(me->query("combat_exp")>3000000){
// tell_object(me, "此副本属于低级副本，经验高于300万，不能挑战了！"NOR"\n");
// return 1;
// }
        	if(!objectp(room = new("/d/fuben_caoren/shilianchang"))){
        		write("副本开启失败。\n");
        		return 1;
        	}
        	if(!room->start_fuben_caoren(this_player()))
        	destruct(room);
        	return 1;
        }        
        if (str == "huanjing"){
//                 if(me->query("combat_exp")>3000000){
// tell_object(me, "此副本属于低级副本，经验高于300万，不能挑战了！"NOR"\n");
// return 1;
// }
            "/d/fuben_huanjing/huanjing"->start_fuben(me);
            return 1;
        }
return 1;	
}

/*
write(ZJOBLONG + "副本任务低级小于300w 中级300-800w 高级高于800w经验\n" + 
ZJOBACTS2+ZJMENUF(3,3,9,31) + 
"武馆训练[低级]主产经验潜能:fly wuguan"ZJSEP
"试炼草人[低级]主产小葡萄:fuben_d caoren"ZJSEP
"迷失幻境[低级]主产道具:fuben_d huanjing"ZJSEP
"伏击金兵[中级]主产黄金:fly jinbing"ZJSEP
"单骑破元[中级]主产经验:fly danbing"ZJSEP
"勇闯魔窟[中级]主产道具:fuben_d moku"ZJSEP
"十三皇陵[高级]主产灵慧:fly shisan"ZJSEP
"每日签到[公共]主产经验潜能:fly qiandao"ZJSEP
"千尺瀑布[公共]主产冲脉丹:fly pubu"ZJSEP
"镇魂妖塔[公共]主产经验潜能:fly zht"ZJSEP
"华山论剑[公共]主产五绝令牌:fly lunjian"ZJSEP
"武林大会[公共]主产五绝令牌:fly lunjians"ZJSEP
"屠人之场[公共]主产九转:fly turen"ZJSEP
"灵脉山洞[活动]主产潜能:fly lm"ZJSEP
"守卫襄阳[活动]主产经验:fly shouwei"ZJSEP
"凌云大门[活动]主产元宝票:fly lingyun"ZJSEP
"公益活动[活动]主产各种道具:fly gyhd"ZJSEP
"帮派战斗[帮会]主产经验潜能:fly bpzd"ZJSEP
"王陵争霸[帮会]主产威望阅历:fly wlzb"ZJSEP
"镖行天下[组队]主产黄金:fly hubiao"ZJSEP
"团队剿匪[组队]主产经验潜能:fly jiaofei"ZJSEP
"五行神兽[门票]主产道具:fly slzd"ZJSEP
"西夏校场[门票]主产经验潜能:fly xxxc"ZJSEP
"\n");
*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
