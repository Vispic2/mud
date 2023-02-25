//cpasswd.c by XiaoYao
// Modify by snowman@SJ 01/05/1999.
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{

// if(!wizardp(me))
//     return notify_fail("测试阶段\n"NOR);
    //if(!arg && wizardp(me))
    if(!arg)
    {
    write(ZJOBLONG + ZJSIZE(30)+HIG"     [  你  目  前  拥  有  武  学  进  阶  点  ："+me->query("jinjiedian")+"  点  ]"ZJBR"||--------------------------------------||"ZJBR
    +HIG+""ZJBR"    目    前    支    持    进    阶    的    武    功    有  ：\n" + ZJOBACTS2+ZJMENUF(2,2,10,30)+ 
    "葵花魔功:skillsss khmg"ZJSEP
    "不败神功:skillsss bbsg"ZJSEP
    "九阴神功:skillsss jysg"ZJSEP
    "南海玄功:skillsss nhxg"ZJSEP"\n"NOR);
	return 1;
	}
    if(arg=="khmg")
    {
    write(ZJOBLONG+ZJSIZE(30)+HIY"〖葵花魔攻进阶说明〗"ZJBR
    ""HIR"进阶加成："ZJBR
    "每次[葵花魔攻技能 [群魔乱舞]进阶释放技能要求，内力需要增加=次数*50点"ZJBR
    "首次进阶[葵花魔攻技能 [群魔乱舞]必定连续攻击10次，后续每进阶一次加一连。"ZJBR
    "进阶[葵花魔攻技能 [群魔乱舞]次数大于等于10次消耗内力等于攻击次数*10，否则次数*20。"ZJBR
    "进阶[葵花魔攻技能 [群魔乱舞]次数大于等于5次大概率busy对方，busy时间等于进阶次数。"ZJBR
    "进阶[葵花魔攻技能 [群魔乱舞]次数大于等于5次自busy固定1秒随机1秒。"ZJBR
    ""HIM"每次进阶需要："ZJBR
    "潜能100000点、"ZJBR
    "实战100000点、"ZJBR
    "灵慧10000点、"ZJBR
    "最大内力1000点、"ZJBR
    "最大精力1000点、"ZJBR
    "武学进阶点10点。"ZJBR
    ""HIW"目前进阶葵花魔攻："+me->query("khmg")+"次。"
    "\n"+ ZJOBACTS2+ZJMENUF(2,2,10,30)+
    ""HIG"武学进阶:skillsss khmgs"ZJSEP
    "返回首页:skillsss"ZJSEP"\n"NOR);
    }
    if(arg=="khmgs")
    {    
    if(me->query_skill("kuihua-mogong")<1)
    return notify_fail(HIR"你没有这项技能，不能进阶武学！\n"NOR);
   
	if((me->query("potential") - me->query("learned_points")) < 100000)
	return notify_fail("你的潜能不足10万点不能进阶武功。\n");
    if((me->query("experience") - me->query("learned_experience")) < 100000)
	return notify_fail("你的实战体会不足10万点不能进阶武功。\n");
    if (me->query("magic_points")  < 10000)
	return notify_fail("你的灵慧不足1万点不能进阶武功。\n");	
	if (me->query("max_neili")  < 1000)
	return notify_fail("你的最大内力不足1k点不能进阶武功。\n");	
	if (me->query("max_jingli")  < 1000)
	return notify_fail("你的最大精力不足1k点不能进阶武功。\n");	
    if(me->query("jinjiedian") < 10)
    return notify_fail("你的武学进阶点不足。"+HIG+ZJSIZE(25)+ZJURL("cmds:skillsss help")+"获得方法\n"NOR);   
    
    me->add("potential",-100000);
    me->add("experience",-100000);
    me->add("magic_points",-10000);
    me->add("max_neili",-1000);
    me->add("max_jingli",-1000);    
    me->add("jinjiedian",-10);
    
    me->add("khmg",1);
    me->add("khmgs",1);
    write("恭喜你进阶成功\n"NOR);
    }	
    
    
    
    
    
    //每次进阶释放消耗内力增加100点。
//每进阶一次提升伤害等于提升了30级不败神功。
//进阶大于等于10次固定5秒busy+随机=技能等级/40。
//进阶大于等于5次，busy固定1+随机1
//首次进阶连击加一次，算法为5+进阶次数，当进阶10次时连击次数等于15，15为连击上限。
   if(arg=="bbsg")
    {
    write(ZJOBLONG+ZJSIZE(30)+HIY"〖不败神功进阶说明〗"ZJBR
    ""HIR"进阶加成："ZJBR    
     "每次进阶释放技能要求，内力需要增加=次数*100点"ZJBR
    "每进阶 [不败神功]技能 [破字真决]一次提升伤害等于提升了30级不败神功。"ZJBR
    "首次进阶连击加一次，算法为5+进阶次数，当进阶10次时连击次数等于15，15为连击上限。"ZJBR
    "进阶[不败神功]技能 [破字真决]大于等于10次固定5秒busy+随机=技能等级/40。"ZJBR
    "进阶[不败神功]技能 [破字真决]次数大于等于5次自busy固定1秒随机1秒。"ZJBR
    ""HIM"每次进阶需要："ZJBR
    "潜能100000点、"ZJBR
    "实战100000点、"ZJBR
    "灵慧10000点、"ZJBR
    "最大内力1000点、"ZJBR
    "最大精力1000点、"ZJBR
    "武学进阶点10点。"ZJBR
    ""HIW"目前进阶不败神功："+me->query("bbsg")+"次。"
    "\n"+ ZJOBACTS2+ZJMENUF(2,2,10,30)+
    ""HIG"武学进阶:skillsss bbsgs"ZJSEP
    "返回首页:skillsss"ZJSEP"\n"NOR);
    }
    if(arg=="bbsgs")
    {    
    if(me->query_skill("never-defeated")<1)
    return notify_fail(HIR"你没有这项技能，不能进阶武学！\n"NOR);
   
	if((me->query("potential") - me->query("learned_points")) < 100000)
	return notify_fail("你的潜能不足10万点不能进阶武功。\n");
    if((me->query("experience") - me->query("learned_experience")) < 100000)
	return notify_fail("你的实战体会不足10万点不能进阶武功。\n");
    if (me->query("magic_points")  < 10000)
	return notify_fail("你的灵慧不足1万点不能进阶武功。\n");	
	if (me->query("max_neili")  < 1000)
	return notify_fail("你的最大内力不足1k点不能进阶武功。\n");	
	if (me->query("max_jingli")  < 1000)
	return notify_fail("你的最大精力不足1k点不能进阶武功。\n");	
    if(me->query("jinjiedian") < 10)
    return notify_fail("你的武学进阶点不足。"+HIG+ZJSIZE(25)+ZJURL("cmds:skillsss help")+"获得方法\n"NOR);   
    me->add("potential",-100000);
    me->add("experience",-100000);
    me->add("magic_points",-10000);
    me->add("max_neili",-1000);
    me->add("max_jingli",-1000);
    me->add("jinjiedian",-10);
    
    me->add("bbsg",1);
    me->add("bbsgs",1);
    write("恭喜你进阶成功\n"NOR);
    }
    	
    	
    	
    	
    	
       if(arg=="jysg")
    {
    write(ZJOBLONG+ZJSIZE(30)+HIY"〖九阴神功进阶说明〗"ZJBR
    ""HIR"进阶加成："ZJBR    
    "每次进阶[九阴神功]技能[九阴神拳]的强度都会提升%10左右。"ZJBR
   "进阶[九阴神功]技能[九阴神拳]次数大于等于5次自busy固定1秒随机1秒。"ZJBR
    ""HIM"每次进阶需要："ZJBR
    "潜能100000点、"ZJBR
    "实战100000点、"ZJBR
    "灵慧10000点、"ZJBR
    "最大内力1000点、"ZJBR
    "最大精力1000点、"ZJBR
    "武学进阶点10点。"ZJBR
    ""HIW"目前进阶九阴神功："+me->query("jysg")+"次。"
    "\n"+ ZJOBACTS2+ZJMENUF(2,2,10,30)+
    ""HIG"武学进阶:skillsss jysgs"ZJSEP
    "返回首页:skillsss"ZJSEP"\n"NOR);
    }
    if(arg=="jysgs")
    {    
    if(me->query_skill("jiuyin-shengong")<1)
    return notify_fail(HIR"你没有这项技能，不能进阶武学！\n"NOR);
  
	if((me->query("potential") - me->query("learned_points")) < 100000)
	return notify_fail("你的潜能不足10万点不能进阶武功。\n");
    if((me->query("experience") - me->query("learned_experience")) < 100000)
	return notify_fail("你的实战体会不足10万点不能进阶武功。\n");
    if (me->query("magic_points")  < 10000)
	return notify_fail("你的灵慧不足1万点不能进阶武功。\n");	
	if (me->query("max_neili")  < 1000)
	return notify_fail("你的最大内力不足1k点不能进阶武功。\n");	
	if (me->query("max_jingli")  < 1000)
	return notify_fail("你的最大精力不足1k点不能进阶武功。\n");	
    if(me->query("jinjiedian") < 10)
    return notify_fail("你的武学进阶点不足。"+HIG+ZJSIZE(25)+ZJURL("cmds:skillsss help")+"获得方法\n"NOR);   
    me->add("potential",-100000);
    me->add("experience",-100000);
    me->add("magic_points",-10000);
    me->add("max_neili",-1000);
    me->add("max_jingli",-1000);
    me->add("jinjiedian",-10);
   
    me->add("jysg",1);
    me->add("jysgs",1);
    write("恭喜你进阶成功\n"NOR);
    }
    	
    	
    	
    	
    	
    	
    	
    	
    if(arg=="nhxg")
    {
    write(ZJOBLONG+ZJSIZE(30)+HIY"〖南海玄功进阶说明〗"ZJBR
    ""HIR"进阶加成："ZJBR    
    "每次进阶[南海玄功]技能[南海护体]可以增加后天四维根骨，臂力，身法，悟性，5点无上限。"ZJBR
   "进阶[南海玄功]技能[无影法杖]提升一连击，上限30连。"ZJBR
      "进阶[南海玄功]技能[无影法杖]次数大于等于5次自busy固定1秒随机1秒。"ZJBR
    ""HIM"每次进阶需要："ZJBR
    "潜能100000点、"ZJBR
    "实战100000点、"ZJBR
    "灵慧10000点、"ZJBR
    "最大内力1000点、"ZJBR
    "最大精力1000点、"ZJBR
    "武学进阶点10点。"ZJBR
    ""HIW"目前进阶南海玄功："+me->query("jysg")+"次。"
    "\n"+ ZJOBACTS2+ZJMENUF(2,2,10,30)+
    ""HIG"武学进阶:skillsss nhxgs"ZJSEP
    "返回首页:skillsss"ZJSEP"\n"NOR);
    }
    if(arg=="nhxgs")
    {    
    if(me->query_skill("bluesea-force")<1)
    return notify_fail(HIR"你没有这项技能，不能进阶武学！\n"NOR);
  
	if((me->query("potential") - me->query("learned_points")) < 100000)
	return notify_fail("你的潜能不足10万点不能进阶武功。\n");
    if((me->query("experience") - me->query("learned_experience")) < 100000)
	return notify_fail("你的实战体会不足10万点不能进阶武功。\n");
    if (me->query("magic_points")  < 10000)
	return notify_fail("你的灵慧不足1万点不能进阶武功。\n");	
	if (me->query("max_neili")  < 1000)
	return notify_fail("你的最大内力不足1k点不能进阶武功。\n");	
	if (me->query("max_jingli")  < 1000)
	return notify_fail("你的最大精力不足1k点不能进阶武功。\n");	
    if(me->query("jinjiedian") < 10)
    return notify_fail("你的武学进阶点不足。"+HIG+ZJSIZE(25)+ZJURL("cmds:skillsss help")+"获得方法\n"NOR);   
    me->add("potential",-100000);
    me->add("experience",-100000);
    me->add("magic_points",-10000); 
    me->add("max_neili",-1000);
    me->add("max_jingli",-1000);
    me->add("jinjiedian",-10);
   
    me->add("nhxg",1);
    me->add("nhxgs",1);
    write("恭喜你进阶成功\n"NOR);
    }
    	
    	
    if(arg=="help")
    {
    write("1、可以通过去渡劫谷修炼获得\n");
    write("2、可以通过师门概率获得\n");
    write("3、可以通过抽奖概率获得\n");
    write("4、可以通过赞助获得\n");
    write("5、通过副本获得\n");
    }
    return 1;	
}
int help(object me)
{
	write(@HELP
武学进阶点获得方法：
1、可以通过去渡劫谷修炼获得
2、可以通过师门概率获得
3、可以通过抽奖概率获得
4、可以通过赞助获得
HELP );
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
