// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
	
	"sword":	"剑法",
	"blade":	"刀法",
	"hammer":       "锤法",
	"whip":	 	"鞭法",
	//"club" :	"棍法",
	"staff":	"长兵",
	"throwing":     "暗器",
	"force":	"内功",
	"xinfa":	"心法",
	"parry":	"招架",
	"dodge":	"轻功",
	"magic":	"法术",
	"unarmed":      "拳脚",
	"finger":       "指法",
	"hand":	 	"手法",
	"cuff":	 	"拳法",
	"claw":	 	"爪法",
	"strike":       "掌法",
	"medical":      "医术",
	"poison":       "毒技",
	"cooking":      "厨艺",
	"chuixiao-jifa" : "吹萧",
	"guzheng-jifa"  : "古筝",
	"tanqin-jifa"   : "弹琴",
]);

int main(object me, string arg)
{
	mapping map;
	string *types, *skill, ski, map_to;
	string msg,mp;
	int i, modify;
	
	int xiuyang;
	int n,ng;
	object weapon;
	seteuid(getuid());
	if (! arg)
	{
		map = me->query_skill_map();
		if (! mapp(map) || sizeof(map) == 0)
			return notify_fail("你现在没有使用任何特殊技能。\n");
		skill = keys(valid_types);
		msg = ZJOBLONG"以下是你目前使用中的特殊技能：\n";
		msg+=HIC+"≡"+HIY+"一一一一一一一一一一一一一一一一一一一一一"+HIC+"≡"+NOR+"\n";
		for (i = 0; i < sizeof(skill); i++){
			if (undefinedp(map[skill[i]]))
				continue;
			if (! me->query_skill(skill[i]))
				continue;
			modify = me->query_temp("apply/" + skill[i]);
			msg += sprintf("  %-14s： %-18s  有效等级：%s%3d"NOR"\n",valid_types[skill[i]],
				undefinedp(map[skill[i]]) ? "无" : to_chinese(map[skill[i]]),
				(modify==0 ? "" : (modify>0 ? HIC : HIR)),
				me->query_skill(skill[i]));
		}
		msg+=HIC+"≡"+HIY+"一一一一一一一一一一一一一一一一一一一一一"+HIC+"≡"+NOR+"\n";
	mp=me->query("family/family_name");	
	
	xiuyang=me->query("xiuyang");	
	weapon = me->query_temp("weapon");
if(mp)
{		
	msg+=""HIW"        "+mp+"专属激发效果：          "+ZJURL("cmds:familyts")+ZJSIZE(25)+""HIY"【专属说明】"+"\n"NOR;
	if(mp=="丐帮")
	{
	ng=me->query_skill("huntian-qigong",1);
	if( me->query_skill_mapped("force") == "huntian-qigong")
	 	{
		 n=me->query_skill("force")/5+me->query("con")+xiuyang/10;
		 msg += HIC"内功已激发浑天气功:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 n=me->query_skill("sword-cognize",1)/5+me->query("con");
		 msg += ",基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "xiaoyaoyou")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发逍遥游:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("strike") == "dragon-strike"
		 	&&me->query_skill_prepared("strike") == "dragon-strike" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("str");   
		 			msg += "掌法已激发降龙十八掌:\n"+"    掌法激发+"+n+"";	
		 			 msg += ",破甲+"+n+"\n";	   			 	
		  } 
		  if( me->query_skill_mapped("parry") == "dagou-bang")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发打狗棒法:\n"+"    招架激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "dragon-strike")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发降龙十八掌:\n"+"    招架激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("staff") == "dagou-bang"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "staff"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("int");  
		 		msg += "长兵已激发打狗棒法:\n"+"    长兵激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "huntian-qigong"
			&& me->query_skill_mapped("dodge") == "xiaoyaoyou"
			&& (me->query_skill_mapped("parry") == "dagou-bang"||me->query_skill_mapped("parry") == "dragon-strike")
			&& ((me->query_skill_mapped("staff") == "dagou-bang"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff")
			     ||(me->query_skill_mapped("strike") == "dragon-strike"&&me->query_skill_prepared("strike") == "dragon-strike" ))	 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		   }								
	}	
		
		
	if(mp=="全真教")
	{
	ng=me->query_skill("xiantian-gong",1);
	if( me->query_skill_mapped("force") == "xiantian-gong")
	 	{
		 msg += HIC"内功已激发先天功:\n";	
		 n=me->query_skill("taoism",1)/10;
		 msg += ",抗毒+"+n+"";	
		}	
		 if( me->query_skill_mapped("dodge") == "jinyan-gong")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发金雁功:\n"+"    轻功激发+"+n+"\n";			
		 }
			 if( me->query_skill_mapped("sword") == "quanzhen-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword"	 )
		 {
		 		n=ng/10+xiuyang/10+me->query("con");  
		 		msg += "剑法已激发全真剑法:\n"+"    剑法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "xiantian-gong"
			&& me->query_skill_mapped("dodge") == "jinyan-gong"
			&& (me->query_skill_mapped("parry") == "jinguan-yusuo")
			&& (me->query_skill_mapped("sword") == "quanzhen-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		   }								
		
	}	
		
		
	if(mp=="峨嵋派")
	{
	if( me->query_skill_mapped("force") == "linji-zhuang")
	 	{
		 		n=me->query_skill("force")/5+me->query("con")+xiuyang/10;
		 msg += HIC"内功已激发临济十二庄:\n"+"    招架激发+"+n+"";	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=me->query_skill("linji-zhuang",1)*20;
		 msg += ",血量+"+n+"";	
		}	
		 if( me->query_skill_mapped("dodge") == "zhutian-bu")
		 {	
		 		n=me->query_skill("linji-zhuang",1)/10+xiuyang/10;	
		 msg += "轻功已激发诸天化身步:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "huifeng-jian")
		 {	
		 		n=me->query_skill("linji-zhuang",1)/10+xiuyang/10;	
		 msg += "招架已激发回风拂柳剑:\n"+"    招架激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("parry") == "piaoxue-zhang")
		 {	
		 		n=me->query_skill("linji-zhuang",1)/10+xiuyang/10;	
		 msg += "招架已激发飘雪穿云掌:\n"+"    招架激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("strike") == "piaoxue-zhang"
		 	&&me->query_skill_prepared("strike") == "piaoxue-zhang" 
		 	)
		 	{
		 		n=me->query_skill("linji-zhuang",1)/10+xiuyang/10+me->query("str");   
		 			msg += "掌法已激发飘雪穿云掌:\n"+"    掌法激发+"+n+"";	
		 			 msg += ",内功激发+"+n+"\n";	   			 	
		  } 
		 if( me->query_skill_mapped("sword") == "huifeng-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=me->query_skill("linji-zhuang",1)/10+xiuyang/10+me->query("con");  
		 		msg += "剑法已激发回风拂柳剑:\n"+"    剑法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "linji-zhuang"
			&& me->query_skill_mapped("dodge") == "zhutian-bu"
			&& (me->query_skill_mapped("parry") == "piaoxue-zhang"||me->query_skill_mapped("parry") == "huifeng-jian")
			&&(   (me->query_skill_mapped("sword") == "huifeng-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(me->query_skill_mapped("strike") == "piaoxue-zhang"&&me->query_skill_prepared("strike") == "piaoxue-zhang" ))	 	
		 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		   }					
	}	
	if(mp=="古墓派")
	{
	ng=me->query_skill("surge-force",1);
	if( me->query_skill_mapped("force") == "surge-force")
	 	{
		 		n=me->query_skill("force")/5+me->query("con")+xiuyang/10;
		 msg += HIC"内功已激发怒海狂涛:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 		//n=me->query_skill("force")/2;
		 //msg += ",护甲+"+n+"\n";	
		 	n=xiuyang/5+me->query("con");
		 msg += ",基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "yunv-shenfa")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发玉女身法:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("unarmed") == "sad-strike"
		 	&&me->query_skill_prepared("unarmed") == "sad-strike" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("int");   
		 			msg += "拳脚已激发黯然销魂掌:\n"+"    拳脚激发+"+n+"";	
		 			 msg += ",破甲+"+n+"\n";	   			 	
		  } 
		  if( me->query_skill_mapped("parry") == "sad-strike")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发黯然销魂掌:\n"+"    招架激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "xuantie-jian")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发玄铁剑法:\n"+"    招架激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("sword") == "xuantie-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("int");  
		 		msg += "剑法已激发玄铁剑法:\n"+"    剑法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "surge-force"
			&& me->query_skill_mapped("dodge") == "yunv-shenfa"
			&& (me->query_skill_mapped("parry") == "sad-strike"||me->query_skill_mapped("parry") == "xuantie-jian")
			&& ((me->query_skill_mapped("sword") == "xuantie-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
			     ||(me->query_skill_mapped("unarmed") == "sad-strike"&&me->query_skill_prepared("unarmed") == "sad-strike" ))	 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		   }									
			
	}	
		
	if(mp=="华山派")
	{
	ng=me->query_skill("zixia-shengong",1);
	if( me->query_skill_mapped("force") == "zixia-shengong")
	 	{
		 		n=me->query_skill("force")/5+me->query("int")+xiuyang/10;
		 msg += HIC"内功已激发紫霞神功:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=me->query_skill("sword-cognize",1)/5+me->query("int");
		 msg += ",基础伤害+"+n+"";	
		}	
		 if( me->query_skill_mapped("dodge") == "feiyan-huixiang")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发飞燕回翔:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "huashan-sword")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发华山剑法:\n"+"    招架激发+"+n+"\n";			
		 }
		
		 if( me->query_skill_mapped("sword") == "huashan-sword"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("int");  
		 		msg += "剑法已激发华山剑法:\n"+"    剑法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "zixia-shengong"
			&& me->query_skill_mapped("dodge") == "feiyan-huixiang"
			&& (me->query_skill_mapped("parry") == "huashan-sword")
			&& (me->query_skill_mapped("sword") == "huashan-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		   }							
		
	}	
	if(mp=="灵鹫宫")
	{
	ng=me->query_skill("bahuang-gong",1);
	if( me->query_skill_mapped("force") == "bahuang-gong")
	 	{
		 msg += HIC"内功已激发八荒六合独尊功:\n"+"    ";	
		 n=xiuyang/5+me->query("dex");
		 msg += "    基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "yueying-wubu")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发月影舞步:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "tianyu-qijian")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发天羽奇剑:\n"+"    招架激发+"+n+"\n";			
		 }
		
		 if( me->query_skill_mapped("sword") == "tianyu-qijian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("dex");  
		 		msg += "剑法已激发天羽奇剑:\n"+"    剑法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "bahuang-gong"
			&& me->query_skill_mapped("dodge") == "yueying-wubu"
			&& (me->query_skill_mapped("parry") == "tianyu-qijian")
			&& (me->query_skill_mapped("sword") == "tianyu-qijian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		 		}					
	}	
	if(mp=="少林派")
	{
	 if( me->query_skill_mapped("force") == "hunyuan-yiqi")
	 	{
		 		n=me->query_skill("force")/5+me->query("con");
		 msg += HIC"内功已激发混元一气功:\n"+"    轻功激发+"+n+"、招架激发"+n+"";	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "shaolin-shenfa")
		 {	
		 		n=me->query_skill("hunyuan-yiqi",1)/10;	
		 msg += "轻功已激发少林身法:\n"+"    轻功激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("sword") == "damo-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=me->query_skill("hunyuan-yiqi",1)/10+me->query("con");  
		 		msg += "剑法已激发达摩剑法:\n"+"    剑法激发+"+n+"";	
		 		n=me->query_skill("hunyuan-yiqi",1)/10+xiuyang/5+me->query("con");
		 msg += ",基础伤害+"+n+"\n";		
		 }			
		 if( me->query_skill_mapped("whip") == "riyue-bian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "whip"	 
		 	)
		 	{
		 		n=me->query_skill("hunyuan-yiqi",1)/10+me->query("con");  
		 		msg += "鞭法已激发日月鞭法:\n"+"    鞭法激发+"+n+"";	
		 		n=me->query_skill("hunyuan-yiqi",1)/10+me->query("con");
		 msg += ",基础伤害+"+n+"\n";		
		 	}	 
		 			 		
		 		
		 if( me->query_skill_mapped("strike") == "yipai-liangsan"
		 	&&me->query_skill_prepared("strike") == "yipai-liangsan" 
		 	)
		 	{
		 		n=me->query_skill("hunyuan-yiqi",1)/10+me->query("con");   
		 			msg += "掌法已激发一拍两散:\n"+"    内功激发+"+n+"";	
		 			 msg += ",掌法激发+"+n+"\n";	   			 	
		  } 
		 if( me->query_skill_mapped("force") == "hunyuan-yiqi"
			&& me->query_skill_mapped("dodge") == "shaolin-shenfa"
			&& me->query_skill_mapped("parry") == "jingang-buhuaiti"
			&&(   (me->query_skill_mapped("sword") == "damo-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(me->query_skill_mapped("whip") == "riyue-bian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "whip")	 
					||(me->query_skill_mapped("strike") == "yipai-liangsan"&&me->query_skill_prepared("strike") == "yipai-liangsan" ))	 	
		 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		   }		
	}	
		
		
	if(mp=="神龙教")
	{
	ng=me->query_skill("shenlong-xinfa",1);
	if( me->query_skill_mapped("force") == "shenlong-xinfa")
	 	{
		 		n=me->query_skill("force")/3+me->query("dex")+xiuyang/10;
		 msg += HIC"内功已激发神龙心法:\n"+"    招架激发+"+n;	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+me->query("dex");
		 msg += ",基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "yixingbu")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发意形步法:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("strike") == "huagu-mianzhang"
		 	&&me->query_skill_prepared("strike") == "huagu-mianzhang" 
		 	)
		 	{
		 		n=ng/5+xiuyang/10+me->query("dex");   
		 			msg += "掌法已激发化骨绵掌:\n"+"    掌法激发+"+n+"";	
		 		n=ng/10+xiuyang/10+me->query("dex");   
		 			msg += ""+"、毒技激发+"+n+"\n";	  			 	
		  } 
		   if( me->query_skill_mapped("hand") == "shenlong-bashi"
		 	&&me->query_skill_prepared("hand") == "shenlong-bashi" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("dex");   
		 			msg += "手法已激发神龙八式:\n"+"    手法激发+"+n+"";	
		 			msg += ""+"、基础伤害+"+n+"\n";	  			 	
		  } 
		  
		  if( me->query_skill_mapped("parry") == "shenlong-bashi")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发神龙八式:\n"+"    招架激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "huagu-mianzhang")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发化骨绵掌:\n"+"    招架激发+"+n+"\n";			
		 }
		 
		 if( me->query_skill_mapped("force") == "shenlong-xinfa"
			&& me->query_skill_mapped("dodge") == "yixingbu"
			&& (me->query_skill_mapped("parry") == "shenlong-bashi"||me->query_skill_mapped("parry") == "huagu-mianzhang")
			&& ((me->query_skill_mapped("strike") == "huagu-mianzhang"&&me->query_skill_prepared("strike") == "huagu-mianzhang" )
			     ||(me->query_skill_mapped("hand") == "shenlong-bashi"&&me->query_skill_prepared("hand") == "shenlong-bashi" ))	 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		   }				
	}	
	if(mp=="桃花岛")
	{
		ng=me->query_skill("bibo-shengong",1);
	if( me->query_skill_mapped("force") == "bibo-shengong")
	 	{
		 		n=me->query_skill("force")/5+me->query("int")+xiuyang/10;
		 msg += HIC"内功已激发碧波神功:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+me->query("int");
		 msg += ",基础伤害+"+n+"";	
		}	
		 if( me->query_skill_mapped("dodge") == "anying-fuxiang")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发暗影浮香:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "yuxiao-jian")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发玉箫剑法:\n"+"    招架激发+"+n+"\n";			
		 }
		
		 if( me->query_skill_mapped("sword") == "yuxiao-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("int");  
		 		msg += "剑法已激发玉箫剑法:\n"+"    剑法激发+"+n+"";	
		 		msg += ",护体+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "bibo-shengong"
			&& me->query_skill_mapped("dodge") == "anying-fuxiang"
			&& (me->query_skill_mapped("parry") == "yuxiao-jian")
			&& (me->query_skill_mapped("sword") == "yuxiao-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		   }							
	}	
		
	if(mp=="武当派")
	{
	if( me->query_skill_mapped("force") == "taiji-shengong")
	 	{
		 		n=me->query_skill("force")/5+me->query("con")+xiuyang/10;
		 msg += HIC"内功已激发太极神功:\n"+"    轻功激发+"+n+"";	
		 		n=me->query_skill("taoism",1)/10;
		 msg += ",抗毒+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "tiyunzong")
		 {	
		 		n=me->query_skill("taiji-shengong",1)/10+xiuyang/10;	
		 msg += "轻功已激发梯云纵:\n"+"    轻功激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("sword") == "taiji-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=me->query_skill("taiji-shengong",1)/10+xiuyang/10+me->query("con");  
		 		msg += "剑法已激发太极剑法:\n"+"    剑法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		 if( me->query_skill_mapped("unarmed") == "taiji-quan"
		 	&&me->query_skill_prepared("unarmed") == "taiji-quan" 
		 	)
		 	{
		 		n=me->query_skill("taiji-shengong",1)/10+xiuyang/10+me->query("con");   
		 			msg += "拳脚已激发太极拳:\n"+"    护体+"+n+"";	
		 			 msg += ",招架激发+"+n+"\n";	   			 	
		  } 
		 if( me->query_skill_mapped("force") == "taiji-shengong"
			&& me->query_skill_mapped("dodge") == "tiyunzong"
			&& (me->query_skill_mapped("parry") == "taiji-quan"||me->query_skill_mapped("parry") == "taiji-jian")
			&&(   (me->query_skill_mapped("sword") == "taiji-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(me->query_skill_mapped("unarmed") == "taiji-quan"&&me->query_skill_prepared("unarmed") == "taiji-quan" ))	 	
		 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		   }				
	}	
		
		
		
	if(mp=="逍遥派")
	{
	ng=me->query_skill("beiming-shengong",1);
	if( me->query_skill_mapped("force") == "beiming-shengong")
	 	{
		 n=me->query_skill("force")/5+me->query("int")+xiuyang/10;
		 msg += HIC"内功已激发北冥神功:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 n=xiuyang/5+me->query("int");
		 msg += ",基础伤害+"+n+"\n";	
		}	
			  if( me->query_skill_mapped("hand") == "zhemei-shou"
		 	&&me->query_skill_prepared("hand") == "zhemei-shou" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("int");   
		 			msg += "掌法已激发天山折梅手:\n"+"    手法激发+"+n+"";	
		 			 msg += ",破甲+"+n+"\n";	   			 	
		  } 
		  if( me->query_skill_mapped("parry") == "zhemei-shou")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发天山折梅手:\n"+"    招架激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "ruyi-dao")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发如意刀:\n"+"    招架激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("blade") == "tianshan-zhang"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "blade"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("int");  
		 		msg += "刀法已激发如意刀:\n"+"    刀法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "beiming-shengong"
			&& me->query_skill_mapped("dodge") == "lingbo-weibu"
			&& (me->query_skill_mapped("parry") == "shemei-shou"||me->query_skill_mapped("parry") == "ruyi-dao")
			&& ((me->query_skill_mapped("blade") == "ruyi-dao"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")
			     ||(me->query_skill_mapped("hand") == "zhemei-shou"&&me->query_skill_prepared("hand") == "zhemei-shou" ))	 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		 		//	n=xiuyang/5;   
		 			//msg += "    毒技等级+"+n+"\n";	 
		   }									
		
		
	}	
		
	if(mp=="星宿派")
	{	
	ng=me->query_skill("freezing-force",1);
	if( me->query_skill_mapped("force") == "freezing-force")
	 	{
		 		n=me->query_skill("force")/5+me->query("str")+xiuyang/10;
		 msg += HIC"内功已激发冰蚕寒功:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"\n";	
		 		}	
		 if( me->query_skill_mapped("dodge") == "zhaixinggong")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发摘星功:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("strike") == "chousui-zhang"
		 	&&me->query_skill_prepared("strike") == "chousui-zhang" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("str");   
		 			msg += "掌法已激发抽髓掌:\n"+"    掌法激发+"+n+"";	
		 			 msg += ",破甲+"+n+"\n";	   			 	
		  } 
		  if( me->query_skill_mapped("parry") == "chousui-zhang")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发抽髓掌:\n"+"    招架激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "tianshan-zhang")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发天山杖法:\n"+"    招架激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("staff") == "tianshan-zhang"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "staff"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("str");  
		 		msg += "长兵已激发天山杖法:\n"+"    长兵激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "freezing-force"
			&& me->query_skill_mapped("dodge") == "zhaixinggong"
			&& (me->query_skill_mapped("parry") == "tianshan-zhang"||me->query_skill_mapped("parry") == "chousui-zhang")
			&& ((me->query_skill_mapped("staff") == "tianshan-zhang"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff")
			     ||(me->query_skill_mapped("strike") == "chousui-zhang"&&me->query_skill_prepared("strike") == "chousui-zhang" ))	 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		 			n=xiuyang/5;   
		 			msg += "    毒技等级+"+n+"\n";	 
		   }									
		
	}	
		
		
	if(mp=="血刀门")
	{
	ng=me->query_skill("xuehai-mogong",1);
	if( me->query_skill_mapped("force") == "xuehai-mogong")
	 	{
		 		//n=me->query_skill("force")/5+me->query("int")+xiuyang/10;
		 msg += HIC"内功已激发血海魔功:\n"+"    ";	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+me->query("str");
		 msg += ",破甲+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "shenkong-xing")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发身空行:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "xue-dao")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发血刀刀法:\n"+"    招架激发+"+n+"\n";			
		 }
		
		 if( me->query_skill_mapped("blade") == "xue-dao"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "blade"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("str");  
		 		msg += "刀法已激发血刀刀法:\n"+"    刀法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "xuehai-mogong"
			&& me->query_skill_mapped("dodge") == "shenkong-xing"
			&& (me->query_skill_mapped("parry") == "xue-dao")
			&& (me->query_skill_mapped("blade") == "xue-dao"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		 		}									
	}	
	if(mp=="雪山寺")
	{
	ng=me->query_skill("longxiang-gong",1);
	if( me->query_skill_mapped("force") == "longxiang-gong")
	 	{
		 		//n=me->query_skill("force")/5+me->query("int")+xiuyang/10;
		 msg += HIC"内功已激发龙象般若功:\n"+"    ";	
		 		//n=me->query_skill("force")/2;
		// msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+me->query("str");
		 msg += ",护体+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "shenkong-xing")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发身空行:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "riyue-lun")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发日月轮法:\n"+"    招架激发+"+n+"\n";			
		 }
		
		 if( me->query_skill_mapped("hammer") == "riyue-lun"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "hammer"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("str");  
		 		msg += "锤法已激发日月轮法:\n"+"    锤法激发+"+n+"";	
		 		msg += ",破甲+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "longxiang-gong"
			&& me->query_skill_mapped("dodge") == "shenkong-xing"
			&& (me->query_skill_mapped("parry") == "riyue-lun")
			&& (me->query_skill_mapped("hammer") == "riyue-lun"&&objectp(weapon)&&(string)weapon->query("skill_type") == "hammer")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+""NOR;	
		 			if(ng/2>650)ng=650*2; 
		 			n=xiuyang/10+ng/2; 
		 			 msg += ",基础伤害+"+n+"\n"NOR;	 
		   }								
	}	
	if(mp=="段氏皇族")
	{
	ng=me->query_skill("kurong-changong",1);
	if( me->query_skill_mapped("force") == "kurong-changong")
	 	{
		 		n=me->query_skill("force")/5+me->query("int")+xiuyang/10;
		 msg += HIC"内功已激发枯荣禅功:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+me->query("int");
		 msg += ",基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "tiannan-step")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发天南步法:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("finger") == "six-finger"
		 	&&me->query_skill_prepared("finger") == "six-finger" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("int");   
		 			msg += "指法已激发六脉神剑:\n"+"    指法激发+"+n+"";	
		 			 msg += ",基础伤害+"+n+"\n";	   			 	
		  } 
		  if( me->query_skill_mapped("parry") == "six-finger")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发六脉神剑:\n"+"    招架激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("force") == "kurong-changong"
			&& me->query_skill_mapped("dodge") == "tiannan-step"
			&& me->query_skill_mapped("parry") == "six-finger"
			&& me->query_skill_mapped("finger") == "six-finger"&&me->query_skill_prepared("finger") == "six-finger"	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;		 
		   }										
	}	
	if(mp=="慕容世家")
	{
	ng=me->query_skill("zihui-xinfa",1);
	if( me->query_skill_mapped("force") == "zihui-xinfa")
	 	{
		 		n=me->query_skill("force")/5+me->query("con")+xiuyang/10;
		 msg += HIC"内功已激发紫薇心法:\n"+"    ";	
		 msg += "    招架激发+"+n+"";
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+me->query("con");
		 msg += "    基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "beidou-xianzong")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发北斗仙踪:\n"+"    轻功激发+"+n+"\n";			
		 }
		  //if( me->query_skill_mapped("parry") == "daojian-guizhen")
		 //{	
		 		//n=ng/10+xiuyang/10;	
		 //msg += "招架已激发刀剑归真:\n"+"    招架激发+"+n+"\n";			
		 //}
		
		 if( me->query_skill_mapped("sword") == "murong-sword"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("con");  
		 		msg += "剑法已激发慕容剑法:\n"+"    剑法激发+"+n+"";	
		 		n=ng/5+xiuyang/10+me->query("con"); 
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "zihui-xinfa"
			&& me->query_skill_mapped("dodge") == "beidou-xianzong"
			&& (me->query_skill_mapped("parry") == "douzhuan-xingyi")
			&& (me->query_skill_mapped("sword") == "murong-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		 		}					
	}	
	if(mp=="欧阳世家")
	{
	ng=me->query_skill("hamagong",1);
	if( me->query_skill_mapped("force") == "hamagong")
	 	{
		 		n=me->query_skill("force")/5+me->query("str")+xiuyang/10;
		 msg += HIC"内功已激发蛤蟆功:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+me->query("str");
		 msg += ",基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "chanchu-bufa")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发蟾蜍步法:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("unarmed") == "hamagong"
		 	&&me->query_skill_prepared("unarmed") == "hamagong" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("str");   
		 			msg += "拳脚已激发蛤蟆功:\n"+"    拳脚激发+"+n+"";	
		 			 msg += ",破甲+"+n+"\n";	   			 	
		  } 
		  if( me->query_skill_mapped("parry") == "hamagong")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发蛤蟆功:\n"+"    招架激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "lingshe-zhangfa")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发灵蛇杖法:\n"+"    招架激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("staff") == "lingshe-zhangfa"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "staff"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("str");  
		 		msg += "长兵已激发灵蛇杖法:\n"+"    长兵激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "hamagong"
			&& me->query_skill_mapped("dodge") == "chanchu-bufa"
			&& (me->query_skill_mapped("parry") == "hamagong"||me->query_skill_mapped("parry") == "lingshe-zhangfa")
			&& ((me->query_skill_mapped("staff") == "lingshe-zhangfa"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff")
			     ||(me->query_skill_mapped("unarmed") == "hamagong"&&me->query_skill_prepared("unarmed") == "hamagong" ))	 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		 		//	n=xiuyang/5;   
		 		//	msg += "    毒技等级+"+n+"\n";	 
		   }									
	}	
	if(mp=="关外胡家")
	{
	ng=me->query_skill("lengyue-shengong",1);
	if( me->query_skill_mapped("force") == "lengyue-shengong")
	 	{
		 		n=me->query_skill("force")/5+(me->query("int")+me->query("str"))/2+xiuyang/10;
		 msg += HIC"内功已激发冷月神功:\n"+"    ";	
		 msg += "    招架激发+"+n+",轻功激发+"+n+"";
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+(me->query("int")+me->query("str"))/2;
		 msg += "    基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "sixiang-bufa")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发四象步法:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "daojian-guizhen")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发刀剑归真:\n"+"    招架激发+"+n+"\n";			
		 }
		
		 if( me->query_skill_mapped("blade") == "daojian-guizhen"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "blade"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+(me->query("int")+me->query("str"))/2;  
		 		msg += "刀法已激发刀剑归真:\n"+"    刀法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "lengyue-shengong"
			&& me->query_skill_mapped("dodge") == "sixiang-bufa"
			&& (me->query_skill_mapped("parry") == "daojian-guizhen")
			&& (me->query_skill_mapped("blade") == "daojian-guizhen"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		 		}						
	}	
		
	if(mp=="华山剑宗")
	{ng=me->query_skill("huashan-xinfa",1);
	if( me->query_skill_mapped("force") == "huashan-xinfa")
	 	{
		 		n=me->query_skill("force")/5+me->query("int")+xiuyang/10;
		 msg += HIC"内功已激发华山心法:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		 		n=me->query_skill("force")/2;
		 msg += ",护甲+"+n+"";	
		 	n=me->query_skill("sword-cognize",1)/5+me->query("int");
		 msg += ",基础伤害+"+n+"";	
		}	
		 if( me->query_skill_mapped("dodge") == "huashan-shenfa")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发华山身法:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "lonely-sword")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发独孤九剑:\n"+"    招架激发+"+n+"\n";			
		 }
		
		 if( me->query_skill_mapped("sword") == "lonely-sword"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	)
		 {
		 		n=ng/10+xiuyang/10+me->query("int");  
		 		msg += "剑法已激发独孤九剑:\n"+"    剑法激发+"+n+"";	
		 		msg += ",破甲+"+n+"\n";		
		 }			
		
		 if( me->query_skill_mapped("force") == "huashan-xinfa"
			&& me->query_skill_mapped("dodge") == "huashan-shenfa"
			&& (me->query_skill_mapped("parry") == "lonely-sword")
			&& (me->query_skill_mapped("sword") == "lonely-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		   }						
	}	
	if(mp=="明教")
	{
		//九阳分支
	if( me->query_skill_mapped("force") == "jiuyang-shengong")
	{		
	ng=me->query_skill("jiuyang-shengong",1);
	if( me->query_skill_mapped("force") == "jiuyang-shengong")
	 	{
	 msg += HIC"内功已激发九阳神功:\n";	
		 n=xiuyang/5+me->query("int");
		 msg += "    护体+"+n+"\n";	
		}	
		 		 if( me->query_skill_mapped("unarmed") == "jiuyang-shengong"
		 	&&me->query_skill_prepared("unarmed") == "jiuyang-shengong" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("int");   
		 			msg += "拳脚已激发九阳神功:\n"+"    招架激发+"+n+"";	
		 			 msg += ",护体+"+n+"\n";	   			 	
		  } 
		  if( me->query_skill_mapped("claw") == "sougu-yingzhua"
		 	&&me->query_skill_prepared("claw") == "sougu-yingzhua" 
		 	)
		 	{
		 		n=ng/10+xiuyang/10+me->query("int");   
		 			msg += "爪法已激发九阳神功:\n"+"    基础伤害+"+n+"";	
		 			 msg += ",爪法激发+"+n+"\n";	   			 	
		  } 
		 if( me->query_skill_mapped("force") == "jiuyang-shengong"
			&& me->query_skill_mapped("dodge") == "bianfu-bu"
			&& me->query_skill_mapped("parry") == "qiankun-danuoyi"
			&& ((me->query_skill_mapped("claw") == "sougu-yingzhua"&&me->query_skill_prepared("claw") == "sougu-yingzhua" )
			     ||(me->query_skill_mapped("unarmed") == "jiuyang-shengong"&&me->query_skill_prepared("unarmed") == "jiuyang-shengong" ))	 	)
		   {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		 		//	n=xiuyang/5;   
		 		//	msg += "    毒技等级+"+n+"\n";	 
		   }	
		 } 
		 //圣火神功分支
		 if( me->query_skill_mapped("force") == "shenghuo-shengong")
	{		
	ng=me->query_skill("shenghuo-shengong",1);
	if( me->query_skill_mapped("force") == "shenghuo-shengong")
	 	{
		 	//	n=me->query_skill("force")/5+me->query("str")+xiuyang/10;
		// msg += HIC"内功已激发九阳神功:\n"+"    招架激发+"+n+",轻功激发+"+n;	
		  msg += HIC"内功已激发圣火神功:\n";	
		 		//n=me->query_skill("force")/2;
		 //msg += ",护甲+"+n+"";	
		 	n=xiuyang/5+me->query("int");
		 msg += "    基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "shenghuo-bu")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发圣火步法:\n"+"    轻功激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("sword") == "shenghuo-ling"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	) 
			{
				n=ng/10+xiuyang/10+me->query("int");  
		 		msg += "剑法已激发圣火令:\n"+"    剑法激发+"+n+"";	
		 		n=ng/5+xiuyang/10+me->query("int");  
		 		msg += ",基础伤害+"+n+"\n";		
			}
		 if( me->query_skill_mapped("force") == "shenghuo-shengong"
			&& me->query_skill_mapped("dodge") == "shenghuo-bu"
			&& me->query_skill_mapped("parry") == "qiankun-danuoyi"
			&& (me->query_skill_mapped("sword") == "shenghuo-ling"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		    {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		   }	
		 }  									 									
	}	
	if(mp=="日月神教")
	{
		//葵花神功
	if( me->query_skill_mapped("force") == "kuihua-shengong")
	{		
		ng=me->query_skill("kuihua-shengong",1);
		if( me->query_skill_mapped("force") == "kuihua-shengong")
	 	{
		 		n=me->query_skill("force")/5+me->query("dex")+xiuyang/10;
		 msg += HIC"内功已激发葵花神功:\n    招架激发+"+n;	
		  	n=xiuyang/5+me->query("dex");
		 msg += ",基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("parry") == "kuihua-shengong")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发葵花神功:\n"+"    招架激发+"+n+"\n";			
		 }
		
		 if( me->query_skill_mapped("sword") == "kuihua-shengong"
		 	&&objectp(weapon)
		 	&&((string)weapon->query("skill_type") == "sword"||(string)weapon->query("skill_type") == "pin")	 
		 	) 
			{
				n=ng/10+xiuyang/10+me->query("dex");  
		 		msg += "剑法已激发葵花神功:\n"+"    轻功激发+"+n+"";	
		 		msg += ",破甲+"+n+"\n";		
			}
		 
		 if( me->query_skill_mapped("force") == "kuihua-shengong"
			&& me->query_skill_mapped("dodge") == "kuihua-shengong"
			&& me->query_skill_mapped("parry") == "kuihua-shengong"
			&& (me->query_skill_mapped("sword") == "kuihua-shengong"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		    {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/50; 
		 			 msg += ",暴击+"+n+"\n"NOR;	
		   }	
		 } 
		 //吸星大法
		 if( me->query_skill_mapped("force") == "xixing-dafa")
	{		
	ng=me->query_skill("xixing-dafa",1);
	if( me->query_skill_mapped("force") == "xixing-dafa")
	 	{
		 n=me->query_skill("force")/5+me->query("con")+xiuyang/10;
		 msg += HIC"内功已激发吸星大法:\n"+"    招架激发+"+n+"轻功激发+"+n;	
		  	n=xiuyang/5+me->query("con");
		 msg += ",基础伤害+"+n+"\n";	
		}	
		 if( me->query_skill_mapped("dodge") == "piaomiao-shenfa")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "轻功已激发缥缈身法:\n"+"    轻功激发+"+n+"\n";			
		 }
		  if( me->query_skill_mapped("parry") == "tianmo-jian")
		 {	
		 		n=ng/10+xiuyang/10;	
		 msg += "招架已激发天魔剑法:\n"+"    招架激发+"+n+"\n";			
		 }
		 if( me->query_skill_mapped("sword") == "tianmo-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword"	 
		 	) 
			{
				n=ng/10+xiuyang/10+me->query("con");  
		 		msg += "剑法已激发天魔剑法:\n"+"    剑法激发+"+n+"";	
		 		msg += ",基础伤害+"+n+"\n";		
			}
		 if( me->query_skill_mapped("force") == "xixing-dafa"
			&& me->query_skill_mapped("dodge") == "piaomiao-shenfa"
			&& me->query_skill_mapped("parry") == "tianmo-jian"
			&& (me->query_skill_mapped("sword") == "tianmo-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		    {
		   			n=xiuyang/5;   
		 			msg += "全激发:\n"+"    护体+"+n+"、破甲+"+n;	
		 			n=xiuyang/100; 
		 			 msg += ",抗暴+"+n+"\n"NOR;	
		   }	
		 }  							
	}	



		msg= replace_string(msg,"\n",ZJBR);
		if(msg[(strlen(msg)-4)..(strlen(msg)-1)]=="$br#")
			msg= msg[0..(strlen(msg)-5)];
		msg += "\n";
		write(msg);
		return 1;
	}	
}

	

	if (sscanf(arg, "%s %s", ski, map_to) != 2)
		return notify_fail("指令格式：enable|jifa [<技能种类> <技能名称>|none]\n");
	
	if (undefinedp(valid_types[ski]))
		return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。\n");

	if (map_to == "none")
	{
		me->map_skill(ski);
		me->reset_action();
		write(HIW "你从现在起取消" HIG + CHINESE_D->chinese(ski) + HIW "的特殊技能。"NOR"\n");
		return 1;
	} else if (map_to == ski)
	{
		write("「" + to_chinese(ski) + "」是所有" + valid_types[ski] + "的基础，不需要 enable。\n");
		return 1;
	}

	if (me->query_skill_mapped(ski) == map_to)
		return notify_fail("你现在正激发这种技能呢。\n");

	if (me->query_skill(map_to, 1) < 1)
		return notify_fail("你不会这种技能。\n");

	if (me->query_skill(ski, 1) < 1)
		return notify_fail("你还不会半点" + to_chinese(ski) + "呢。\n");

	if (! SKILL_D(map_to)->valid_enable(ski))
		return notify_fail("这个技能不能当成这种用途。\n");

	me->map_skill(ski, map_to);
	me->reset_action();
	write(HIW "你从现在起用" HIR + CHINESE_D->chinese(map_to) + HIW "作为" HIG + CHINESE_D->chinese(ski) + HIW "的特殊技能。"NOR"\n");

	if (ski == "magic")
	{
		write("你改用另一种法术系，精力必须重新锻练。\n");
		me->set("jingli", 0);
		me->receive_damage("jing", 0);
	}
	else if (ski == "force")
	{
		write("你改用另一种内功，内力必须重新锻练。\n");
		me->set("neili", 0);
		me->receive_damage("qi", 0);
		//me->force_me("update me");
	}

	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : enable|jifa [<技能种类> <技能名称> | none]
	   enable|jifa ?

这个指令让你指定所要用的技能，需指明技能种类和技能名称。如果不加参
数则会显示出技能种类及你目前所使用的技能名称 ，如果加一个？会列出
所有能使用特殊技能的技能种类。

HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
