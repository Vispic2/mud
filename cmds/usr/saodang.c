// arg.c
#include <ansi.h>
inherit F_CLEAN_UP;
void special_bonus(object me);
//已经修复师门无限刷新BUG 寒江雪
int main(object me, string arg)
{
	object where = environment(me);
	int cishu;
	string d;
	int hhh=me->query("zjvip/level")*100;
	//int shengyu=(5000+hhh-me->query("shimen/today"));//剩余次数为	
	int shengyu=0;
	if (!arg){		
	write(INPUTTXT("  剩余师门："+shengyu+"次。"ZJBR"  请输入扫荡次数。", "saodang $txt#") + "\n");//增加扫荡的次数	
	return 1;
	}
	if (sscanf(arg, "%d", cishu) != 1) 
	return 1;
	if (me->is_busy())
	return notify_fail(HIR"你现在正忙着呢。"NOR"\n");
	//if (cishu < 1 || cishu > 1000+hhh)
	if (cishu < 1 || cishu > 1)
	return notify_fail(HIR"扫荡次数最少一次，最多也不能超过"+(1000+hhh)+"次。"NOR"\n");
	if (shengyu<cishu)
	return notify_fail(HIR"扫荡次数不能大于师门剩余次数！"NOR"\n");	
	if (me->query("shimen/today")<=50000)
	return notify_fail(HIR"请先完成本周1次师门再来扫荡！"NOR"\n");
	if (me->is_fighting())
	return notify_fail(HIR"临阵磨枪？来不及啦。"NOR"\n");
    me->add("shimen/today",cishu);
	me->add("combat_exp",(800*cishu));
	me->add("potential",(400*cishu));
	me->add("experience", (200*cishu));
	me->add("score", (50*cishu));
	me->add("yuanbaos", (250));
	if(me->query("shen")>0)
	{
	me->add("shen", (50*cishu));
	}
    else
	{
    me->add("shen", -(50*cishu));
	}
	me->add("weiwang", (10*cishu));	
	for(int i=1;i<=cishu;i++){	
	me->add("quest_count",10);
	// if(me->query("quest_count")%50==0){
	// special_bonus(me);
	// }
	// if(me->query("quest_count")>=1000){
	// me->delete("quest_count");
	// special_bonus(me);
	// }	
	}
	tell_object(me,HIM"扫荡了："+cishu+"次师门任务。\n");
	tell_object(me,HIG"获得了："+(1200*cishu)+"经验、"+(600*cishu)+"潜能、"+(300*cishu)+"体会、"+(100*cishu)+"阅历、"+(100*cishu)+"正神、"+(10*cishu)+"威望、250 元宝票。"NOR"\n");
	log_file("cmds/saodang", sprintf("%s：%s(%s)扫荡了，次数："+cishu+"，经验："+800*cishu+"，潜能："+400*cishu+"，体会："+200*cishu+"。\n",ctime(time()),me->query("name"),me->query("id")));	
	return 1;
}

void special_bonus(object me)
{
	string *ob_list = ({
        "/clone/shizhe/cagate",
	    "/clone/shizhe/cjade",
	    "/clone/shizhe/cdiamond",
	    "/clone/shizhe/ccrystal",
		"/clone/vip/hantie",
		"/clone/vip/wujins",        
		"/clone/shizhe/qiandai",
		"/clone/shizhe/jinkuai",
		"/clone/shizhe/puti-zi",		
		"/clone/shizhe/tianxiang",	        
		"/clone/shizhe/fushougao",	        
		"/clone/shizhe/hua5",
        "/clone/shizhe/tianling",
        "/clone/shizhe/jinsha",
        "/clone/shizhe/putao",      
		"/clone/shizhe/dan_chongmai4",	
		"/clone/shizhe/dan_chongmai3",				
		"/clone/shizhe/dan_chongmai2",	
		"/clone/shizhe/dan_chongmai1",					
		"/clone/shizhe/book_tianfu",			
		"/clone/shizhe/book_wuliang",
		"/clone/shizhe/lingzhi",		
		"/clone/shizhe/lingzhi2",		
		"/clone/shizhe/build_ling",	
	    "/clone/shizhe/tianling3",	     	    
        "/clone/shizhe/avipcard",
        "/clone/shizhe/bagua",
        "/clone/shizhe/baiyu",
        "/clone/shizhe/book_tianfu",
        "/clone/shizhe/book_tianfu1",
        "/clone/shizhe/book_tianfu2",
        "/clone/shizhe/book_wuliang",
        "/clone/shizhe/build_ling",
        "/clone/shizhe/cagate",
        "/clone/shizhe/canghai",
        "/clone/shizhe/ccrystal",
        "/clone/shizhe/cdiamond",
        "/clone/shizhe/cjade",
        "/clone/shizhe/cjj",
        "/clone/shizhe/dan_chongmai1",
        "/clone/shizhe/dan_chongmai2",
        "/clone/shizhe/dan_chongmai3",
        "/clone/shizhe/dan_chongmai4",
        "/clone/shizhe/dan_con",
        "/clone/shizhe/dan_dex",
        "/clone/shizhe/dan_fuyuan",
        "/clone/shizhe/dan_guangyin",
        "/clone/shizhe/dan_huichun",
        "/clone/shizhe/dan_hutu",
        "/clone/shizhe/dan_int",
        "/clone/shizhe/dan_qingxin",
        "/clone/shizhe/dan_str",
        "/clone/shizhe/dan_xieqi",
        "/clone/shizhe/dan_zhengqi",
        "/clone/shizhe/dan_zhenyuan",
        "/clone/shizhe/diaogan",
        "/clone/shizhe/fushougao",
        "/clone/shizhe/heimu-ling",
        "/clone/shizhe/hua5",
        "/clone/shizhe/jinpiao",
        "/clone/shizhe/jinsha",
        "/clone/shizhe/kuilei",
        "/clone/shizhe/ling1",
        "/clone/shizhe/ling_wolong",
        "/clone/shizhe/lingzhi",
        "/clone/shizhe/lingzhi2",
        "/clone/shizhe/putao",
        "/clone/shizhe/putao1",
        "/clone/shizhe/puti-zi",
        "/clone/shizhe/tianling",
        "/clone/shizhe/tianling3",
        "/clone/shizhe/tianxiang",
        "/clone/shizhe/tianyan",
        "/clone/shizhe/xuantie",
        "/clone/shizhe/yanzhi",
        "/clone/shizhe/yanzhi2",
        "/clone/shizhe/zhuisha",
        "/clone/shizhe/zyao1",
        "/clone/shizhe/zyao2",
});
	string *ob_list1 = ({
    	"/clone/vip/butian",		
		"/clone/vip/tiancs",
		"/clone/shizhe/dan_str",
		"/clone/shizhe/dan_int",
		"/clone/shizhe/dan_con",
		"/clone/shizhe/dan_dex",
		"/clone/shizhe/dan_jiuzhuan",
        "/clone/shizhe/tianling2",
        "/clone/shizhe/tianling4",
		"/clone/shizhe/dan_bianxing",
		"/clone/shizhe/dan_chongsu",
		"/clone/shizhe/avipcard",
		"/clone/shizhe/putao1",
	    "/clone/shizhe/jiuzhuan1",
        "/clone/shizhe/xuanhuang",
	});
    object ob;
    string ppp;
    int err;
	if (random(500)>5) {
	ppp=ob_list[random(sizeof(ob_list))];
	ob = new(ppp);
	err=catch(call_other(ppp, "???"));
    if(err){
    tell_object(me,"报错了："+ppp+"，请立即联系本服巫师！\n");
    }
	tell_object(me, HIG "你获得了一" + ob->query("unit") + ob->name() + HIG "。"NOR"\n");
    } else {
    ob = new(ob_list1[random(sizeof(ob_list1))]);
    message("channel:chat",HIC"【扫荡】扫荡系统：据说"+me->query("name")+"通过扫荡获得了一"+ob->query("unit")+ob->name()+HIM"。\n",users());	
    }
	ob->move(me, 1);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
