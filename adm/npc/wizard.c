//vip1 累计赞助100元
//vip2 累计赞助300元
//vip3 累计赞助500元
//vip4 累计赞助800元
//vip5 累计赞助1000元
//vip6 累计赞助1300元
//vip7 累计赞助1500元
//vip8 累计赞助1800元
//vip9 累计赞助2000元
//vip10 累计赞助3000元
inherit NPC;
#include <ansi.h>
string ask_baibao();
int ask_fanli();
int ask_xiandan();
int ask_kuilei();
int ask_viplv();
int ask_lunhui();
string ask_zzjiangli();
int ask_chunjie();
string  *zz_skills=({
		"aikido",
	"anranxiaohun-zhang",
	"anying-fuxiang",
	"art",
	"bagua-dao",
	"bagua-zhang",
	"bahuang-gong",
	"bai-quan",
	"baibian-daxue",
	"baihua-cuocuff",
	"baihua-cuoquan",
	"baihua-quan",
	"baisheng-daofa",
	"baiyun-xinfa",
	"banruo-zhang",
	"bashi-shentong",
	"bat-blade",
	"bazhen-zhang",
	"beiming-shengong",
	"benlei-shou",
	"bibo-shengong",
	"biluo-zhang",
	"bingpo-blade",
	"bingxue-xinfa",
	"biye-wu",
	"biyun-xinfa",
	"bizhen-qingzhang",
	"blood-sword",
	"bluesea-force",
	"boyun-suowu",
	"canglang-bian",
	"canhe-zhi",
	"chanchu-bufa",
	"changquan",
	"chanhun-suo",
	"chansi-shou",
	"chaos-steps",
	"chixin-jian",
	"chixin-qingchang-jian",
	"chiyou-kuangzhanjue",
	"chongling-jian",
	"chongyang-shenzhang",
	"chousui-zhang",
	"chuanyun-shou",
	"chuanyun-tui",
	"chuixue-jian",
	"chunyang-jue",
	"cibei-dao",
	"cloudstaff",
	"cuixin-strike",
	"cuixin-zhang",
	"dafumo-quan",
	"dagou-bang",
	"damo-jian",
	"daojian-guizhen",
	"dashou-yin",
	"daya-jian",
	"deisword",
	"demon-blade",
	"demon-steps",
	"demon-strike",
	"diwangquan",
	"diyu-sword",
	"dongyang-dao",
	"doom-hand",
	"doomsteps",
	"doomstrike",
	"doomsword",
	"douzhuan-xingyi",
	"dragon-strike",
	"duanjia-sword",
	"duanshi-xinfa",
"
	duanyun-fu",
	"dulong-shenzhua",
	"duoluoye-zhi",
	"duoming-jinhua",
	"dusha-zhang",
	"enmeiryu",
	"fall-steps",
	"fanliangyi-dao",
	"fanyun-zhang",
	"feidao",
	"feifeng-whip",
	"feihua-zhang",
	"feitian-yujianliu",
	"feixian-steps",
	"feixian-sword",
	"feixing-shu",
	"feiyan-huixiang",
	"feiyu-bian",
	"fengmo-zhang",
	"fengyu-piaoxiang",
	"fengyun-shou",
	"fenxin-jue",
	"five-avoid",
	"force",
	"freezing-force",
	"fumo-jian"
	"fumo-zhang",
	"fushang-neigong",
	"fy-sword",
	"ghosty-steps",
	"guangming-zhang",
	"guhong-zhang",
	"guiyuan-tunafa",
	"guxing-jian",
	"hamagong",
	"hamashengong",
	"hanbing-mianzhang",
	"hanbing-shenzhang",
	"hanbing-zhenqi",
	"hansha-sheying",
	"hanshan-strike",
	"hanxing-bada",
	"haotian-zhang",
	"heijian-jindao",
	"hengshan-jian",
	"hengshan-sword",
	"hexing-bifa",
	"honghua-shengong",
	"houquan",
	"huagong-dafa",
	"huagu-mianzhang",
	"huanhua-jian",
	"huanyin-zhi",
	"huashan-sword",
	"huashan-zhangfa",
	"huifeng-jian",
	"huixin-strike",
	"huiyan-xinfa",
	"hujia-daofa",
	"hujia-quan",
	"huntian-qigong",
	"hunyuan-yiqi",
	"hunyuan-zhang",
	"huoxinliu-jianfa",
	"huoyan-dao",
	"huzhua-shou",
	"ill-quan",
	"ittouryu",
	"jinding-zhang",
	"jingang-buhuaiti",
	"jingang-quan",
	"jingang-zhi",
	"jingyiforce",
	"jinhong-steps",
"jinshe-jian",
"jinshe-zhang",
"jinshe-zhui",
"jinshi-kuangjian",
"jinwu-blade",
"jinwu-goufa",
"jinyu-quan",
"jiuyang-shengong",
"jiuyin-baiguzhao",
"jiuyin-baiguzhua",
"jiuyin-shenfa",
"jiuyin-shengong",
"jiuyin-shenzhang",
"jiuyin-shenzhua",
"jiuyin-zhengong",
"juehu-shou",
"jueming-tui",
"jueqing-bian",
"jueqing-jian",
"jueqing-zhang",
"king-of-dragon",
"kongming-quan",
"kongshoudao",
"kuaihuo-strike",
"kuang-blade",
"kuang-jian",
"kuangfeng-blade",
"kuangfeng-jian",
"kuihua-dafa",
"kuihua-feiying",
"kuihua-mogong",
"kuihua-shengong",
"kuihua-xinfa",
"kunlun-jian",
"kunlun-zhang",
"kurong-changong",
"kwan-yin-spells",
"lanhua-shou",
"lansha-shou",
"lefthand-sword",
"lengyue-shengong",
"liancheng-jian",
"liangyi-jian",
"liehuo-jian",
"lieyan-dao",
"lieyan-jue",
"lingbo-weibu",
"lingboweibu",
"lingshe-quan",
"lingshe-zhangfa",
"lingyuan-xinfa",
"linji-zhuang",
"liuhe-dao",
"liuhe-zhang",
"liujue-dao",
"liumang-quan",
"liuquan-steps",
"liushui-bian",
"liuxing-jianfa",
"liuyang-zhang",
"liuyue-jian",
"lonely-sword",
"longcheng-shendao",
"longfenghuan",
"longteng-daofa",
"longxiang-gong",
"longzhua-gong",
"luohan-quan",
"luohua-jian",
"luoriquan",
"luoyan-hand",
"luoyan-jian",
"luoying-shenzhang",
"luoying-xinfa",
"luoying-zhang",
"luoyun-dao",
"magic-dark",
"magic-earth",
"magic-fire",
"magic-ice",
"magic-light",
"magic-old",
"magic-water",
"mantian-huayu",
"mantian-xing",
"mantianhuayu-zhen",
"meihua-shou",
"meinv-quan",
"miaojia-jian",
"mingwang-jian",
"mingyu-gong",
"mingyu-shengong",
"mingyue-blade",
"moon-blade",
"moshen-xinfa",
"moshen-zhenshen",
"murong-daofa",
"murong-jianfa",
"murong-sword",
"music",
"never-defeated",
"nianhua-zhi",
"ningxue-shenzhao",
"ningxue-shenzhua",
"nodust-steps",
"nuquan",
"paiyun-shou",
"pangu-hammer",
"panshi-shengong",
"panyang-zhang",
"piaofeng-quan",
"piaoxue-hand",
"piaoxue-zhang",
"piaoyibu",
"pidi-shenzhen",
"pili-biao",
"pili-daofa",
"pili-quan",
"pixie-jian",
"pixie-sword",
"pmshenfa",
"pofeng-strike",
"poguang-dao",
"pokong-quan",
"poyu-quan",
"poyun-hand",
"pudu-zhang",
"puyaogedou",
"qiankun-danuoyi",
"qiantian-zhi",
"qianye-shou",
"qianzhu-wandushou",
"qidao",
"qingfu-shenfa",
"qingliang-daxuefa",
"qingming-xuangong",
"qingpingsword",
"qingshe-sword",
"qingyi-jian",
"qingyun-shou",
"qishang-quan",
"qishen-dao",
"qiufeng-chenfa",
"qiuge-dao",
"qiulin-shiye",
"qiulinshiye",
"qiusheng-blade",
"qixian-jian",
"qixian-wuxingjian",
"qixing-jian",
"qixing-shou",
"quanzhen-jian",
"qujing-gunfa",
"qxxy-shou",
"ranmu-daofa",
"raozhi-roujian",
"riyue-bian",
"riyue-lun",
"rouyun-steps",
"ruanhong-zhusuo",
"ruijin-jue",
"rulai-shenzhang",
"ruyi-dao",
"ruying-leg",
"sad-strike",
"sanfen-jianshu",
"sanhua-zhang",
"sanyin-wugongzhao",
"shadowsteps",
"shaolin-shenfa",
"sharen-sword",
"shayi-xinfa",
"shedao-qigong",
"shedu-qiqiao",
"shenghuo-ling",
"shenghuo-quan",
"shenghuo-shengong",
"shenghuo-xinfa",
"shenkong-xing",
"shenlong-bashi",
"shenlong-tuifa",
"shenlong-xinfa",
"shenmen-jian",
"shentuo-zhang",
"shenyuan-gong",
"shenzhang-bada",
"shenzhao-jing",
"shenzhaojing",
"shexing-lifan",
"shiba-pan",
"shigu-bifa",
"shortsong-blade",
"shuishangpiao",
"siqi-sword",
"six-finger",
"six-sword",
"sixiang-bufa",
"snow-zhang",
"snowstep",
"snowwhip",
"softsword",
"songfeng-jian",
"songshan-jian",
"songshan-qigong",
"songshan-sword",
"songyang-strike",
"songyang-zhang",
"sougu",
"sun-finger",
"suohou-gong",
"surge-force",
"taiji-jian",
"taiji-quan",
"taiji-shengong",
"taishan-sword",
"taixuan-gong",
"tangmen-throwing",
"tanzhi-shentong",
"three-sword",
"thunderwhip",
"tianchan-zhang",
"tianchang-strike",
"tianchang-zhang",
"tiangang-bati",
"tiangang-zhi",
"tianjue-dao",
"tianluo-diwang",
"tianmo-bufa",
"tianmo-dao",
"tianmo-gun",
"tianmo-huti",
"tianmo-jian",
"tianmo-jinshen",
"tianmo-liaoluan",
"tianmo-zhang",
"tiannan-step",
"tiannan-step.c",
"tianrenheyi",
"tianshan-zhang",
"tianyu-qijian",
"tie-steps",
"tiexian-quan",
"tiexue-hammer",
"tiezhang-zhangfa",
"tiyunzong",
"tmdafa",
"tmdao",
"tmjian",
"tmquan",
"tmzhang",
"tongbi-zhang",
"touch",
"tougu-zhen",
"wanjian-guizong",
"weituo-chu",
"weituo-gun",
"wind-blade",
"wuchang-zhang",
"wudang-array",
"wudang-mianzhang",
"wudoumi-shengong",
"wudu-bian",
"wudu-goufa",
"wudu-shengong",
"wudu-yanluobu",
"wuhu-duanmendao",
"wuliang-jian",
"wuluo-zhang",
"wusheng-zhao",
"wushuang-jian",
"wuxiang-zhi",
"wuxing-dun",
"wuying-jian",
"wuying-leg",
"wuyue-blade",
"wuyun-jian",
"wuzhan-mei",
"xianglong-zhang",
"xiangmo-chu",
"xiangmo-zhangfa",
"xiantian-gong",
"xiantian-qigong",
"xiaowuxiang",
"xiaoyao-jian",
"xiaoyaoyou",
"xiewei-bian",
"xingxiu-duzhang",
"xingyi-zhang",
"xiuluo-dao",
"xiuluo-yinshagong",
"xiuluo-zhi",
"xixing-dafa",
"xiyang-jian",
"xiyang-neigong",
"xiyu-tiezheng",
"xuanfeng-leg",
"xuanhualiu-quanfa",
"xuanming-shengong",
"xuanming-zhang",
"xuantian-shengong",
"xuantian-strike",
"xuantian-wuji",
"xuantie-jian",
"xuantie-jianfa",
"xuantie-sword",
"xuanxu-dao",
"xuanyin-jian",
"xuanyuan-arrow",
"xuanyuan-axe",
"xue-dao",
"xuehai-mogong",
"xuekui",
"xueshan-sword",
"xumishan-zhang",
"xunlei-jian",
"yandang-jianfa",
"yandang-xinfa",
"yanling-shenfa",
"yanxing-dao",
"yanzi-blade",
"yifeng-jian",
"yijin-duangu",
"yijinjing",
"yinfeng-dao",
"yingzhua-gong",
"yinlong-bian",
"yinlong-shou",
"yinlong-whip",
"yinsuo-jinling",
"yinyang-jiuzhuan",
"yinyang-ren",
"yinyang-shiertian",
"yitian-jian",
"yitian-tulong",
"yitian-zhang",
"yixingbu",
"yiyang-zhi",
"yizhi-chan",
"youming-guizhao",
"yuan-blade",
"yuejia-qiang",
"yuenv-jian",
"yueying-wubu",
"yuezhao-gong",
"yufeng-zhen",
"yujiamu-quan",
"yujiashu",
"yunlong-bian",
"yunlong-jian",
"yunlong-shengong",
"yunlong-shou",
"yunlong-zhua",
"yunu-sword",
"yunv-jian",
"yunv-xinfa",
"yunv-xinjing",
"yunwu-strike",
"yuxiao-jian",
"zhanzhuang-gong",
"zhemei-shou",
"zhenshan-zhang",
"zhentian-quan",
"zhong-qiang",
"zhongnan-zhi",
"zhongping-qiang",
"zhougong-jian",
"zhuihun-biao",
"zhuihun-jian",
"zihui-xinfa",
"zijinbagua-dao",
"zilei-jian",
"zimu-zhen",
"zixia-shengong",
"zui-gun",
	"zui-quan",
	"zuixian-wangyue"
});
string *sk_list = ({
		"qishang-quan",
		"zhuihun-jian",
		"zhuihun-jian",
		"zhuihun-jian",
		"baihua-quan",
		"baihua-quan",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"sougu",
		"sougu",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-shenfa",
		"yunlong-shenfa",
		"hanxing-bada",
		"hanxing-bada",
		"huanyin-zhi",
		"zijinbagua-dao",
		"sanfen-jianshu",
		"ningxue-shenzhao",
		"sanfen-jianshu",
		"huanyin-zhi",
		"zijinbagua-dao",
		"xuanming-zhang",
		"ningxue-shenzhao",
		"xuanming-zhang",
		"shenzhaojing",
});
string *sk_list2 = ({
		"qishang-quan",
		"zhuihun-jian",
		"baihua-quan",
		"hanbing-mianzhang",
		"sougu",
		"yunlong-bian",
		"yunlong-shenfa",
		"hanxing-bada",
		"xuanming-zhang",
		"sanfen-jianshu",
		"huanyin-zhi",
		"ningxue-shenzhao",
		"zijinbagua-dao",
		"shenzhaojing",
		"jiuyang-shengong",
});

void create()
{
		set_name(HIY"巫师"NOR,({  "wizard", "wushi" }) );
		set("gender", "男性" );
		set("title",HIY"创世神");
		set("age", 30);
		set("long", "这是一个成天无所事事的巫师。\n");

		set("str", 17);
		set("dex", 16);
		set("con", 15);
		set("int", 17);
		set("shen_type", 1);
		set("combat_exp", 100);
		set("attitude", "peaceful");

		setup();

		set("inquiry", ([
			"储物袋": (: ask_baibao :),
			//"弟子贡献": (: ask_fanli :),
			"仙丹": (: ask_xiandan :),
	        "VIP成就": (: ask_viplv :),	
	        "替身傀儡": (: ask_kuilei :),	
	         "轮回丹": (: ask_lunhui :),	
	         "赞助奖励": (: ask_zzjiangli :),	
	         //"春节回馈": (: ask_chunjie :),	

		]));

		carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	
	add_action("ask_xidian","xidian");
	add_action("do_getvip","getvip");
	add_action("do_getsk","getsk");
}



int ask_viplv()
{
	int i,lv;
	object me;
	string str;
int a,b,c,d,e;
	me = this_player();
	str = ZJOBLONG"合理消费，快乐游戏，坚持签到每天来江湖中走一遭，终有一天你会成为一代宗师，加油！"ZJBR"你的vip成就如下：\n";
	str += ZJOBACTS2+ZJMENUF(1,1,10,30);
	str += "VIP1[洗心丹1颗]["+((me->query("zjvip/level")>1)?"已达成":"需VIP等级1")+"]["
			+(me->query("zjvip/vipgift/vip1")?"已领取":"未领取")
			+"]:getvip 1"ZJSEP;
	str += "VIP2[九转金丹10颗]["+((me->query("zjvip/level")>2)?"已达成":"需VIP等级2")+"]["
			+(me->query("zjvip/vipgift/vip2")?"已领取":"未领取")
			+"]:getvip 2"ZJSEP;
	str += "VIP3[公共技能随机奖励]["+((me->query("zjvip/level")>3)?"已达成":"需VIP等级3")+"]["
			+(me->query("zjvip/vipgift/vip3")?"已领取":"未领取")
			+"]:getvip 3"ZJSEP;
	str += "VIP4[公共技能自选1次]["+((me->query("zjvip/level")>4)?"已达成":"需VIP等级4")+"]["
			+(me->query("zjvip/vipgift/vip4")?"已领取":"未领取")
			+"]:getvip 4"ZJSEP;			
	str += "VIP5[孟子与鬼谷]["+((me->query("zjvip/level")>5)?"已达成":"需VIP等级5")+"]["
			+(me->query("zjvip/vipgift/vip5")?"已领取":"未领取")
			+"]:getvip 5"ZJSEP;
			
			str += "VIP6[100颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，10串"HIM"神奇葡萄"NOR"，10颗"HIY"九转金丹"NOR"["+((me->query("zjvip/level")>6)?"已达成":"需VIP等级6")+"]["
			+(me->query("zjvip/vipgift/vip6")?"已领取":"未领取")
			+"]:getvip 6"ZJSEP;
			str += "VIP7[200颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，20串"HIM"神奇葡萄"NOR"，20颗"HIY"九转金丹"NOR""NOR"]["+((me->query("zjvip/level")>7)?"已达成":"需VIP等级7")+"]["
			+(me->query("zjvip/vipgift/vip7")?"已领取":"未领取")
			+"]:getvip 7"ZJSEP;
			str += "VIP8[300颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，30串"HIM"神奇葡萄"NOR"，30颗"HIY"九转金丹"NOR""NOR"]["+((me->query("zjvip/level")>8)?"已达成":"需VIP等级8")+"]["
			+(me->query("zjvip/vipgift/vip8")?"已领取":"未领取")
			+"]:getvip 8"ZJSEP;
			str += "VIP9[400颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，40串"HIM"神奇葡萄"NOR"，40颗"HIY"九转金丹"NOR""NOR"]["+((me->query("zjvip/level")>9)?"已达成":"需VIP等级9")+"]["
			+(me->query("zjvip/vipgift/vip9")?"已领取":"未领取")
			+"]:getvip 9"ZJSEP;
			str += "VIP10[500颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，50串"HIM"神奇葡萄"NOR"，50颗"HIY"九转金丹"NOR""NOR"]["+((me->query("zjvip/level")>10)?"已达成":"需VIP等级10")+"]["
			+(me->query("zjvip/vipgift/vip10")?"已领取":"未领取")
			+"]:getvip 10"ZJSEP;
			
			
			
	tell_object(me,str+"\n");
}

int do_getvip(string arg)
{
	int i,lv;
	object ob,me;
	string sk,str;

	me = this_player();
	if(!me->query("zjvip/times"))
	{
		tell_object(me,HIR"你没有vip，不能领取vip成就！\n"NOR);
		return 1;
	}
/*	lv = me->query("zjvip/level");
	if(!arg)
	{
		tell_object(me,HIR"你要干什么！\n"NOR);
		return 1;
	}*/
	if(arg=="1")
	{
		if (me->query("zjvip/all_pay")<100) 
		{
			tell_object(me,HIY"加油，达到vip1你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip1"))
		{
			tell_object(me,HIR"你已经领取过vip1成就奖励了！\n"NOR);
			return 1;
		}
		ob = new("/clone/shizhe/dan_xixin");
		ob->set_amount(1);
		tell_object(me,HIY"你领取到了 1 颗洗心丹！\n"NOR);	
		me->set("zjvip/vipgift/vip1",1);
		ob->move(me);
	}
	
	else if(arg=="2")
	{
		if (me->query("zjvip/all_pay")<300) 
		{
			tell_object(me,HIY"加油，达到vip2你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
	else 
		if(me->query("zjvip/vipgift/vip2"))
		{
			tell_object(me,HIR"你已经领取过vip2成就奖励了！\n"NOR);
			return 1;
		}
		ob = new("/clone/shizhe/dan_jiuzhuan");
		ob->set_amount(10);
		tell_object(me,HIY"你领取到了 10 颗九转金丹！\n"NOR);	
		me->set("zjvip/vipgift/vip2",1);
		ob->move(me);
	}
	
	
	else if(arg=="3")
	{
		if (me->query("zjvip/all_pay")<500) 
		{
			tell_object(me,HIR"你还没有达成该成就，不能领取奖励！\n"NOR);
			return 1;
		}
		else
		 if(me->query("zjvip/vipgift/vip3"))
		{
			tell_object(me,HIR"你已经领取过vip3成就奖励了！\n"NOR);
			return 1;
		}
		if(random(30)==10)
			sk = "jiuyang-shengong";
		else
			sk = sk_list[random(sizeof(sk_list))];

		me->set("zjvip/vipgift/vip3",1);
		if(me->query_skill(sk,1))
		{
			tell_object(me,"你抽中了"+to_chinese(sk)+"，只可惜你已经会了！\n");
			return 1;
		}
		me->set_skill(sk, 180);

		
		if(sk=="jiuyang-shengong")
		{
			tell_object(me, HIY"你得到了一本九阳真经！\n"NOR );
			ob = new("/clone/book/jiuyang-book");
			ob->move(me, 1);
		}
		tell_object(me, HIY"你的"+to_chinese(sk)+"提升到了180级！\n"NOR );
	}
	else
	
	  if(arg=="4")
	{
			if (me->query("zjvip/all_pay")<800) 
		{
			tell_object(me,HIR"你还没有达到vip4，不能领取奖励！\n"NOR);
			return 1;
		}
		else
	    if(me->query("zjvip/vipgift/vip4"))
		{
			tell_object(me,HIR"你已经领取过vip4成就奖励了！\n"NOR);
			return 1;
		}
		str = ZJOBLONG"请选择你想要的技能：\n";
		str += ZJOBACTS2+ZJMENUF(2,2,10,30);
		for(i=0;i<sizeof(sk_list2);i++)
		{
			str += to_chinese(sk_list2[i])+":getsk "+sk_list2[i];
			if(i<(sizeof(sk_list2)-1)) str += ZJSEP;
		}
		tell_object(me,str+"\n");
	}

else if(arg=="5")
	{
		if (me->query("zjvip/all_pay")<1000) 
		{
			tell_object(me,HIY"加油，达到vip5你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip5"))
		{
			tell_object(me,HIR"你已经领取过vip5成就奖励了！\n"NOR);
			return 1;
		}
		ob = new("/clone/shizhe/mengzi");
		ob->move(me);
		//ob->set_amount(1);
		ob = new("/clone/shizhe/guigu");
		//ob->set_amount(1);
		ob->move(me);
		tell_object(me,HIY"你领取到了两本书《孟子》与《鬼谷神算》！\n"NOR);	
		me->set("zjvip/vipgift/vip5",1);
	//	ob->move(me);
	}else if(arg=="6")
	{
		if (me->query("zjvip/all_pay")<1300) 
		{
			tell_object(me,HIY"加油，达到vip6你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip6"))
		{
			tell_object(me,HIR"你已经领取过vip6成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(100);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(100);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(100);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(100);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(10);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(10);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip6",1);	
	}
else if(arg=="7")
	{
		if (me->query("zjvip/all_pay")<1500) 
		{
			tell_object(me,HIY"加油，达到vip7你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip7"))
		{
			tell_object(me,HIR"你已经领取过vip7成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(200);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(200);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(200);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(200);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(20);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(20);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip7",1);	
	}
else if(arg=="8")
	{
		if (me->query("zjvip/all_pay")<1800) 
		{
			tell_object(me,HIY"加油，达到vip8你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip8"))
		{
			tell_object(me,HIR"你已经领取过vip8成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(300);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(300);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(300);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(300);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(20);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(20);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip8",1);	
	}
	
else if(arg=="9")
	{
		if (me->query("zjvip/all_pay")<2000) 
		{
			tell_object(me,HIY"加油，达到vip9你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip9"))
		{
			tell_object(me,HIR"你已经领取过vip9成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(400);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(400);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(400);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(400);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(40);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(40);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip9",1);	
	}
else if(arg=="10")
	{
		if (me->query("zjvip/all_pay")<3000) 
		{
			tell_object(me,HIY"加油，达到vip10你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip10"))
		{
			tell_object(me,HIR"你已经领取过vip10成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(500);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(500);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(500);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(500);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(50);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(50);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip10",1);	
	}
	return 1;
}

int do_getsk(string arg)
{
	int i,lv;
	object ob,me;
	string sk,str;

	me = this_player();
	if(!me->query("zjvip/times"))
	{
		tell_object(me,HIR"你没有vip，不能领取vip成就！\n"NOR);
		return 1;
	}
	lv = me->query("zjvip/level");
	if(!arg || member_array(arg,sk_list2)==-1)
	{
		tell_object(me,HIR"你要干什么！\n"NOR);
		return 1;
	}
		if (me->query("zjvip/all_pay")<800) 
	{
		tell_object(me,HIR"你还没有达到vip4，不能领取奖励！\n"NOR);
		return 1;
	}
	else
	 if(me->query("zjvip/vipgift/vip4"))
	{
		tell_object(me,HIR"你已经领取过vip4成就奖励了！\n"NOR);
		return 1;
	}
	if(me->query_skill(arg,1))
	{
		tell_object(me,HIY"你选择了"+to_chinese(arg)+"，只可惜你已经会了，请换一个吧！\n"NOR);
		return 1;
	}
	me->set("zjvip/vipgift/vip4",1);
	me->set_skill(arg, 180);
	if(arg=="jiuyang-shengong")
	{
		tell_object(me,HIY "你得到了一本九阳真经！\n" NOR);
		ob = new("/clone/book/jiuyang-book");
		ob->move(me, 1);
	}
	tell_object(me, HIY"你的"+to_chinese(arg)+"提升到了180级！\n"NOR );
	return 1;
}
int ask_fanli()
{
		int i;
		object ob = this_player();
		i=ob->query("zjvip/dizi_pay");	 
		if(ob->query("zjvip/dizi_pay")<1){
				command(HIR"say 你目前的弟子贡献太低，无法领取奖励。"NOR);
				message_vision(HIY"$N已累计获得了"+ob->query("zjvip/dizi_fanli")+"个元宝的奖励。"NOR"\n",ob,  this_object());
				return 1;
		}
		else {
				command("nod "+ob->query("id"));
				command(HIY"say 你已符合领取弟子贡献奖励条件。"NOR);
     			ob->add("yuanbao",i);
				ob->add("zjvip/dizi_pay",-i);
				ob->add("zjvip/dizi_fanli",i);
				message_vision(HIY"$N获得了"+i+"个元宝的奖励。"NOR"\n",ob,  this_object());
				message_vision(HIY"$N已累计获得了"+ob->query("zjvip/dizi_fanli")+"个元宝的奖励。"NOR"\n",ob,  this_object());
				return 1;
		}
}
int ask_xiandan()
{
	int a,b,c,d;
	object ob = this_player();

	a=ob->query("gift/xiandan");
	b=ob->query("gift/unknowdan");
	c=ob->query("gift/shenliwan");
	d=ob->query("gift/xisuidan");
	 
	if (ob->query("zjvip/times") <1) {
		command(HIR"say 对不起，我只处理东方族人的事情！"NOR);
		return 1;
	}
	else {
		command("nod "+ob->query("id"));
		command("say 我来帮你查一下记录。");
		command("say 这位" + RANK_D->query_respect(ob) +"，你已经吃了："+chinese_number(a)+"颗"HIY"醍醐仙丹"NOR"，"+chinese_number(b)+"颗"HIR"火红仙丹"NOR"，"+chinese_number(c)+"颗"HIG"神力丸"NOR"，"+chinese_number(d)+"颗"YEL"洗髓丹"NOR"。");
		return 1;
	}
}

string ask_baibao()
{
	object ob;
	mapping myfam;
	object nang;

	ob = this_player();
	myfam = (mapping)ob->query("family");
		
	//if(!myfam) return "你还是先加入门派吧？";

	if (ob->query("combat_exp") < 10000)
		return ""HIR"虽然我这里有只乾坤袋，可是你战斗经验这么差，被人抢走了怎么办？"NOR"\n";

//	if (ob->query("chuwudai"))
	//	return ""HIR"你之前不是已经领过了吗？你还是赶紧联系管理员去处理一下吧。"NOR"\n";
		
	if ( present("chuwu dai", ob))
		return ""HIR"你已经有了一个储物袋，别贪得无厌！"NOR"\n";

	nang=new("/clone/misc/baibao");
	nang->set("owner_id", ob->query("id"));
	nang->move(ob);
	ob->set("chuwudai", 1);
	write(HIY"你得到一个储物袋!\n"NOR);
	return ""HIY"这可是个宝贝，好好利用它吧。"NOR"";
}

int ask_kuilei()
{
	object ob = this_player();
	object yao;
	int last = ob->query("zjvip/last_get_kuilei");
	int now = time();
	 
	if (ob->query("zjvip/times") <1) {
		command(HIR"say 对不起，我只处理东方族人的事情！"NOR);
		return 1;
	}
	if ((ob->query("zjvip/all_pay")+ob->query("gongxians"))<100) {
		command(HIR"say 对不起，你的贡献不够，不符合领取替身傀儡的条件！"NOR);
		return notify_fail("对不起，你的贡献不够，不符合领取的条件【需要100贡献】！\n");
	}
	if(localtime(last)[4] != localtime(now)[4])
	{
		ob->set("zjvip/last_get_kuilei",now);
		ob->delete("zjvip/get_kuilei");
	}

	if (ob->query("zjvip/get_kuilei")>=((ob->query("zjvip/all_pay")+ob->query("gongxians"))/200)) {
		command(HIR"say 以你目前的贡献只能领"+chinese_number((ob->query("zjvip/all_pay")+ob->query("gongxians"))/200)+"个替身傀儡！"NOR);
		return 1;
	}

	command("nod "+ob->query("id"));
	command(HIY"say 我这就给你。"NOR);
	yao = new("/clone/shizhe/kuilei");
	yao->move(ob);
	ob->add("zjvip/get_kuilei",1);

	message_vision("$N给了$n一个" + yao->query("name") + "。\n",this_object(),ob);
	//log_files("gift", sprintf(ob->query("id")+"在%s：领取了一个替身傀儡。\n",ctime(time())));
	return 1;
		
}

int ask_lunhui()
{
	object ob = this_player();
	object yao;
	if ((ob->query("guizhen")) < 5) 
	{
		command(HIR"say 五转一轮回！"NOR);
		return notify_fail("五转一轮回！\n");
	}
    
    ob->add("guizhen",-5);
	command("nod "+ob->query("id"));
	command(HIY"say 我这就给你。"NOR);
	yao = new("/clone/shizhe/dan_lunhui");
	yao->move(ob);
	message_vision("$N给了$n一个" + yao->query("name") + "。\n",this_object(),ob);
	log_file("adms/zhuanshis", sprintf(ob->query("id")+"在%s：领取了一粒轮回丹。\n",ctime(time())));
	return 1;
		
}
string ask_zzjiangli()
{
	object ob = this_player();
	int zong;
	string skill,*skills,*name;
	if ((ob->query("zzjianglii")) <1)  {
			command(HIR"say 你的次数用完了。"NOR);
		return "你的次数用完了。\n";
	}
	ob->start_busy(10); 
	zong=sizeof(zz_skills);
	//command(HIR"say 每人只能领"+zong+"取一次哦！"+NOR);
	skill=zz_skills[random(zong)];
	if(is_chinese(to_chinese(skill))){  //判断是不是技能，通过判断他有没有中文名字。
		name = explode(skill,".c");   //过滤.c，因为to_chinese。
	  ob->set_skill(skill, 190); 
	    ob->add("zzjianglii",-1);
	//msg+="技能名 "+to_chinese(name[0])+""ZJBR"技能ID "+skills+":chaski "+skills+""ZJSEP;
	message_vision("$N传授给$n关于" +to_chinese(name[0])+ "的一些经验。\n",this_object(),ob);
 }else{
			return HIR"say 没有找到合适的技能，再来一次吧"NOR;

 }	
 
 return "不错，不错。";
}
int ask_chunjie()
{
	object ob = this_player();
	object yao;
	if ((ob->query("chunjie")) >= 1) 
	{
		command(HIR"say 每人只能领取一次哦！"NOR);
		return 1;
	//	return notify_fail("每人只能领取一次哦！\n");
	}
    
    ob->set("chunjie",1);
	command("nod "+ob->query("id"));
	command(HIY"say 我这就给你。"NOR);
	yao = new("/clone/shizhe/putao1");
	yao->set_amount(5);
	yao->move(ob);
	message_vision("$N给了$n五个" + yao->query("name") + "。\n",this_object(),ob);
	yao = new("/clone/shizhe/dan_jiuzhuan");
    yao->set_amount(5);
	yao->move(ob);
	message_vision("$N给了$n五个" + yao->query("name") + "。\n",this_object(),ob);
	//log_files("adms/zhuanshis", sprintf(ob->query("id")+"在%s：领取了一粒轮回丹。\n",ctime(time())));
	return 1;
		
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
