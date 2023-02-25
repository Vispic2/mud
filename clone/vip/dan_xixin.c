// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "洗心丹" NOR, ({ "xixin dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一粒晶莹剔透的丹药，由东方一族秘制而成，服了之后使人强行散去本门武功，从而重新拜师学艺。\n");
		set("unit", "粒");
		set("value", 20000);
		set("yuanbao", 1200);
		set("only_do_effect", 1);
		    
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;
	mapping all_fam = ([
		"武当派":({
				"taiji-quan",
				"taiji-shengong",
				"wudang-xinfa",
				"tiyunzong",
				"wudang-zhang",
				"paiyun-shou",
				"wudang-jian",
				"taiji-jian",
				"taiji-dao",
				"raozhi-roujian",
				"huzhua-shou",
				"zhenshan-zhang",
				"yitian-zhang",
				"shenmen-jian",
				"xuanxu-dao",
				"yitian-zhang",
				"shenmen-jian",
			}),
		"少林派":({
				"jingang-buhuaiti",
                                "banruo-zhang",
                                "jingang-zhi",
                                "jingang-quan",
                                "xumishan-zhang",
				"cibei-dao",
				"damo-jian",
				"fengyun-shou",
				"fumo-jian",
				"hunyuan-yiqi",
				"shaolin-xinfa",
				"jingang-quan",
				"longzhua-gong",
				"luohan-quan",
				"nianhua-zhi",
				"pudu-zhang",
				"qianye-shou",
				"sanhua-zhang",
				"riyue-bian",
				"shaolin-shenfa",
				"weituo-gun",
				"wuchang-zhang",
				"xiuluo-dao",
				"yingzhua-gong",
				"yijinjing",//公共到180
				"yizhi-chan",
				"zui-gun",
//以下为少林藏经阁特有武功
				"yipai-liangsan",
				"xiuluo-zhi",
				"duoluoye-zhi",
				"wuxiang-zhi",
			}),
		"天龙寺":({
				"kurong-changong",
				"duanshi-xinfa",
				"tiannan-step",
				"sun-finger",
			}),
		"华山派":({
				"huashan-sword",
				"huashan-xinfa",
				"huashan-quanfa",
				"huashan-shenfa",
				"zixia-shengong",
				"poyu-quan",
				"hunyuan-zhang",
				"feiyan-huixiang",
				"kuangfeng-jian",
				"yunu-sword",
				"fanliangyi-dao",
			}),
		"华山剑宗":({
				"huashan-sword",
				"huashan-xinfa",
				"huashan-quanfa",
				"huashan-shenfa",
				"zixia-shengong",
				"poyu-quan",
				"hunyuan-zhang",
				"feiyan-huixiang",
				"kuangfeng-jian",
				"yunu-sword",
				"fanliangyi-dao",
			}),
		"峨嵋派":({
				"persuading",
				"jinding-zhang",
				"tiangang-zhi",
				"huifeng-jian",
				"yanxing-dao",
				"zhutian-bu",
				"emei-xinfa",
				"linji-zhuang",
				"piaoxue-zhang",
				"jiuyin-baiguzhao",//周芷若，作为公共技能可学到100级
			}),
		"桃花岛":({
				"bibo-shengong",
				"luoying-xinfa",
				"tanzhi-shentong",
				"luoying-shenzhang",
				"xuanfeng-leg",
				"anying-fuxiang",
				"luoying-shenjian",
				"yuxiao-jian",
				"lanhua-shou",
				"bihai-chaosheng",
			}),
		"神龙教":({
				"shenlong-xinfa",
				"yixingbu",
				"shenlong-bashi",
				"huagu-mianzhang",
				"shedao-qigong",
			}),
		"丐帮":({
				"jiaohua-neigong",
				"huntian-qigong",
				"changquan",
				"xiaoyaoyou",
				"feiyan-zoubi",
				"dragon-strike",//公共武学，需炒菜
				"jiaohua-bangfa",
				"dagou-bang",
				"mantianhuayu-zhen",
				"jueming-tui",
				"chansi-shou",//白世镜
				"suohou-gong",//马大元
				"fengmo-zhang",//彭有敬
				"fumo-zhang",//jian
				
			}),
		"古墓派":({
				"yunv-xinfa",
				"surge-force",
				"yunv-jian",
				"quanzhen-jian",
				"xuantie-jian",
				"yunv-shenfa",
				"meinv-quan",
				"sad-strike",//公共
				"fireice-strike",
				"tianluo-diwang",
				"yufeng-zhen",
				"yinsuo-jinling",
				"tianluo-diwang",
			}),
		"全真教":({
				"quanzhen-xinfa",
				"xiantian-gong",
				"quanzhen-jian",
				"jinyan-gong",
				"jinguan-yusuo",
				"chongyang-shenzhang",
				"haotian-zhang",
				"zhongnan-zhi",
			}),
		"星宿派":({
				"huagong-dafa",
				"freezing-force",
				"guixi-gong",
				"feixing-shu",
				"zhaixinggong",
				"chousui-zhang",
				"sanyin-wugongzhao",
				"chanhun-suo",
				"tianshan-zhang",
			}),
		"逍遥派":({
				"xiaoyao-xinfa",
				"beiming-shengong",
				"xiaowuxiang",
				"lingbo-weibu",
				"feiyan-zoubi",
				"liuyang-zhang",
				"ruyi-dao",
				"zhemei-shou",
			}),
		"雪山寺":({
				"longxiang-gong",
				"mizong-neigong",
				"mingwang-jian",
				"xiangmo-chu",
				"riyue-lun",
				"shenkong-xing",
				"dashou-yin",
				"yujiamu-quan",
				"xiaowuxiang",
				"huoyan-dao",
			}),
		"血刀门":({
				"xue-dao",
				"mingwang-jian",
				"mizong-neigong",
				"xuehai-mogong",
				"shenkong-xing",
				"dashou-yin",
				"yujiamu-quan",
			}),

		"灵鹫宫":({
				"zhemei-shou",
				"liuyang-zhang",
				"yueying-wubu",
				"bahuang-gong",
				"tianyu-qijian",
				"lingjiu-xinfa",
				"zhougong-jian",
			}),
		"慕容世家":({
				"zihui-xinfa",
				"douzhuan-xingyi",
				"beidou-xianzong",
				"canhe-zhi",
				"qixing-quan",
				"murong-sword",
				"longcheng-shendao",
			}),
		"欧阳世家":({
				"shedu-qiqiao",
				"hamagong",
				"chanchu-bufa",
				"lingshe-quan",
				"lingshe-zhangfa",
				"baibian-daxue",
			}),
		"关外胡家":({
				"lengyue-shengong",
				"hujia-daofa",
				"taxue-wuhen",
				"sixiang-bufa",
				"mantian-xing",
				"tianchang-zhang",
				"hujia-quan",
				"baisheng-daofa",
				"miaojia-jian"
			}),
		"段氏皇族":({
				"duanshi-xinfa",
				"tiannan-step",
				"jinyu-quan",
				"duanjia-sword",
				"sun-finger",
				"wuluo-zhang",
				"feifeng-whip",//刀白凤
				"qingliang-daxuefa",//朱丹臣
				"yuezhao-gong",//hua
			}),
	  "日月神教":({
	 "pixie-jian",
    "changquan",
    "kuihua-xinfa",
    "lingxu-bu",	
	"damo-jian",	
	"taiji-jian",
	"huifeng-jian",
	"taishan-sword",
   "hengshan-jian",
    "hengshan-sword",
   "huashan-sword",
   "wuxing-jueji",
  
    "songshan-sword",
    "piaomiao-shenfa",
    "liushui-bian",
    "kuihua-shengong",
    "huanmo-longtianwu",
    "riyue-guanghua",
    "riyue-jian",
    "riyue-xinfa",
    "tianmo-dao",
    "tianmo-gun",
    "tianmo-jian",
    "tianmo-jianfa",
    "tianmo-zhang",
    "xuwu-piaomiao",
    }),
    "明教":({
    "jiuyang-shengong",
     "qiankun-danuoyi",
   //  set_skill("qishang-quan", 250);

      "taiji-quan",
       "taiji-jian",
       "shenghuo-ling",
      "bianfu-bu",     
       "hanbing-mianzhang",
       
       "guangming-jing",
       "guangming-zhang",
       "liehuo-jian",
       "lieyan-dao",
       "pili-daofa",
       "pili-quan",
       "pili-shou",
       "qingfu-shenfa",
       "shenghuo-bu",
       "shenghuo-quan",
       "shenghuo-shengong",
       "qishang-quan",
       "shenghuo-xinfa",
       "lingxu-bu"
       "taiji-dao",
       "wuxing-jueji",
       "xiaoyao-jian",
       }),
         "魔教":({
    "mojiao-medical",
 "moshen-jianfa",
      "moshen-daofa",
       "longteng-daofa",
      "moshen-zhangfa",
       "yinlong-shou",
       "moshen-quanfa",
      "moshen-zhangfa",
       "yinlong-shou",
       "liuxing-jianfa",
       "moshen-bufa",
        "jiutian-xiaoyaobu",       
       "chiyou-kuangzhanjue",
       "moshen-xinfa",
       "moshen-jianfa",
       "mingyue-blade",
       "yanzi-blade",
       "moshen-zhenshen",
       "jinshi-kuangjian",
       "moon-blade",
       }),
            "移花宫":({
    "mingyu-gong",
        "jueqing-zhang",
       "mingyu-shengong",
      "yifeng-jian",
        "yihua-jiemu",
         "yifeng-dodge",
       
       }),
     "玄冥谷":({
    "dulong-shenzhua",
        "feihua-zhang",
       "hexing-bu",
      "lingxu-bu",
        "piaofeng-quan",
         "shexing-lifan",
                "xuanming-shengong",
         "xuanming-zhang",
"hexing-bifa",
       }),

     "唐门":({
    "biye-wu",
        "biyun-xinfa",
    //   "boyun-suowu",
    //  "medical",
        "qiulinshiye",
        // "qiulin-shiye",
             //   "tangmen-jueqi",
        // "tangmen-medical",
       //  "tangmen-poison",
        // "tangmen-throwing",
        "liuxing-biao",
 //     "wuzhan-mei",
      "dusha-zhang",
      "lansha-shou",
      "zimu-zhen",
      "zhuihun-biao",
      "pili-biao",
       }),
       "五毒教":({
    "xiuluo-yinshagong",
        "wudu-shengong",
       "wudu-yanluobu",
      "tianchan-zhang",
        "qianzhu-wandushou",
         "wusheng-zhao",
                "jinwu-goufa",
         "ruanhong-zhusuo",
         "xiewei-bian",
         "hansha-sheying",
         "wudu-qishu",
      "wudu-jing",
      "dusha-zhang",
            "chilian-shenzhang",
         "shedu-qiqiao",
                "lansha-shou",
      "wudu-goufa",
      "jueqing-bian",
            "dusha-zhang",
       }),
       
              "飞天御剑流":({
    "shayi-xinfa",
        "wuxing-dun",
       "shiren-quanfa",
      "aikido",
        "shiren-jianfa",
         "huoxinliu-jianfa",
                "feitian-yujianliu",
                "xuanhuliu-quanfa",
                "ittouryu",
                "enmeiryu",

       }),
       
       
       
                     "绝情谷":({
    "fenxin-jue",
        "jueqing-xinfa",
"pokong-quan",
"guhong-zhang",
"jueqing-shenfa",
"yinyang-ren",
"heijian-jindao",
"guxing-jian",
"zilei-jian",
"tianjue-dao",
"luoyun-dao",
"poguang-dao",
"jueqing-zhang",
       }),
       
 "红花会":({
"honghua-shengong",
"youlong-shenfa",
"baihua-cuocuff",
"heisha-zhang",
"benlei-shou",
"luohua-jian",
"zhuihun-jian",
"qiuge-dao",
"wuying-feidao",
"painting",
"jueqing-zhang",
"medicine",
         }),
         
         "雁荡派":({
"yandang-xinfa",
"huanmo-shenfa",
"zhentian-quan",
"qiantian-zhi",
"yandang-jianfa",
         }),
         
           "凌霄城":({
"bingxue-xinfa",
"snowstep",
"snow-zhang",
"xueshan-sword",
"mingyu-gong",
"hanshan-strike",
"doom-hand",
"snowwhip",
         }),
       
	]);

	if(!me->query("family"))
	{
		tell_object(me,"你还没有师门吧，无需使用"+query("name")+"。\n");
		return 0;
	}
	message_vision(CYN "$N" CYN "小心的服下了一"+query("unit")+"" + name() + CYN "，决定重新做人。"NOR"\n", me);

	family = me->query("family/family_name");
	if(skills=all_fam[family])
	{
		for(i=0;i<sizeof(skills);i++)
		{
			me->delete_skill(skills[i]);
		}
	}
	/*
	else
	{
		tell_object(me,"门派数据错误，请联系管理员。\n");
		return 0;
	}
	*/
	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"服用了一粒"+this_object()->query("name")+""HIM"，获得了一次重新选择师门的机会！");
	me->delete("family");
	me->delete("title");
	me->delete("class");
	me->delete("quest");
	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
