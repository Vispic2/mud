#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file,shimen;
	string str;
	object ob;
 
	if (! environment(me)) 
		return 0; 
	if(!wizardp(me)){
    if (time()<(me->query("a/a")+10))
		return notify_fail("限制10秒用一次。\n");
    if (me->is_fighting())
		return notify_fail("忙乱中。\n");
	if (me->is_busy())
		return notify_fail("你正忙著呢。\n");
	if (me->is_ghost()) 
		return notify_fail("等你还了阳再说吧。\n"); 
	if (me->is_in_prison())   
		return notify_fail("你正在做牢呢。\n");
	if (! me->query("born"))
		return notify_fail("你还没有出生呢！\n");
	if (me->query("doing"))
		return notify_fail("你还想干什么？！\n");
	if (environment(me)->query("no_magic"))
		return notify_fail("你发现这里有点古怪！\n");		
	if (me->query_temp("jun_quest/party"))
		return notify_fail("你还想在战争中使用？！\n");
	if (present("biao huo", me))
		return notify_fail("你身上带著镖银，不能施展！\n");
	if (present("letter", me) || present("receipt", me)) 
		return notify_fail("你身上带著密函，不能施展。\n");
		}
			if(me->query("family/family_name") == "凌霄城")
		{
			shimen = "/d/lingxiao/dadian";
			}else
		if(me->query("family/family_name") == "红花会")
		{
			shimen = "/d/huizhu/damen";
			}else
			if(me->query("family/family_name") == "雁荡派")
		{
			shimen = "/d/yandang/luoyan6";
			}else
		if(me->query("family/family_name") == "绝情谷")
		{
			shimen = "/d/jqg/dating";
			}else
		if(me->query("family/family_name") == "唐门")
		{
			shimen = "/d/tangmen/qianliju";
			}else
		if(me->query("family/family_name") == "魔教")
		{
			shimen = "/d/wansong/fuguitin";
			}else
				if(me->query("family/family_name") == "飞天御剑流")
		{
			shimen = "/d/feitian/xiaowu";
			}else
				if(me->query("family/family_name") == "五毒教")
		{
			shimen = "/d/wudujiao/huating1";
			}else
		if(me->query("family/family_name") == "玄冥谷")
		{
			shimen = "/d/xuanminggu/xuanmingfeng";
			}else
		if(me->query("family/family_name") == "神龙教")
		{
			shimen = "/d/shenlong/dating";
			}else
		if(me->query("family/family_name") == "星宿派")
		{
			shimen = "/d/xingxiu/riyuedong";
			}else
		if(me->query("family/family_name") == "少林派")
		{
			shimen = "/d/shaolin/fzlou2";
			}else
		if(me->query("family/family_name") == "武当派")
		{
			shimen = "/d/wudang/xiaoyuan";
			}else
		if(me->query("family/family_name") == "峨嵋派")
		{
			shimen = "/d/emei/hcahoudian";
			}else
		if(me->query("family/family_name") == "丐帮")
		{
			shimen = "/d/city/gbxiaowu";
			}else
		if(me->query("family/family_name") == "桃花岛")
		{
			shimen = "/d/taohua/dating";
			}else
		if(me->query("family/family_name") == "古墓派")
		{
			shimen = "/d/gumu/zhengting";
			}else
		if(me->query("family/family_name") == "血刀门")
		{
			shimen = "/d/xuedao/shandong3";
			}else
		if(me->query("family/family_name") == "雪山寺")
		{
			shimen = "/d/xueshan/neidian";
			}else
		if(me->query("family/family_name") == "欧阳世家")
		{
			shimen = "/d/baituo/dating";
			}else
		if(me->query("family/family_name") == "灵鹫宫")
		{
			shimen = "/d/lingjiu/dating";
			}else
		if(me->query("family/family_name") == "关外胡家")
		{
			shimen = "/d/guanwai/xiaowu";
			}else
		if(me->query("family/family_name") == "慕容世家")
		{
			shimen = "/d/yanziwu/shangyu";
			}else
		if(me->query("family/family_name") == "段氏皇族")
		{
			shimen = "/d/dali/neitang";
			}else
		if(me->query("family/family_name") == "逍遥派")
		{
			shimen = "/d/xiaoyao/qingcaop";
			}else
		if(me->query("family/family_name") == "全真教")
		{
			shimen = "/d/quanzhen/shiweishi";
			}else
		if(me->query("family/family_name") == "明教")
		{
			shimen = "/d/mingjiao/dadian";
			}else
		if(me->query("family/family_name") == "华山派")
		{
			shimen = "/d/huashan/qunxianguan";
			}else
		if(me->query("family/family_name") == "日月神教")
		{
			shimen = "/d/heimuya/up1";
			}else
		if(me->query("family/family_name") == "华山剑宗")
		{
			shimen = "/d/huashan/xiaowu";
		}else
		if(me->query("family/family_name") == "移花宫")
		{
				shimen = "/d/yihua/yaoyue";
				} else
		if(me->query("family/family_name") == "白云城")
		{
			shimen = "/d/city/chaguan";
		}else{
			write(HIR"你貌似还没有门派，你想去哪里？？？"NOR"\n");
			return 1;
			}
	
		if (base_name(environment(me)) == shimen)
		return notify_fail("你已经到了。\n");		
        me->set("a/a",time());
		message("vision", me->name() + "举起右手在面前极速画了一个圆，竟划破了面前的""空间，只见圆内的空间真空将" + me->name() + "给吸了进去。\n",environment(me), ({me}));
		tell_object(me, "你从空间裂缝中钻出。\n");
		me->move(shimen);
		message("vision", me->name() + "从空间裂缝中钻出。\n",environment(me), ({me}));

	return 1;
	}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
