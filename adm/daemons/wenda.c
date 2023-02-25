// storyd.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;

// 初始化wenda系统
#define REFRESH_INTERVAL	10 * 3600

int     last_update = 0;

static int flag;
static int a_flag;
static int b_flag;
static int frag;
int    filter_listener(object ob);


string query_save_file()
{
	return DATA_DIR "wenda";
}

void create()
{
	//seteuid(ROOT_UID);
	seteuid(getuid());
	set("channel_id", "问答系统");
	CHANNEL_D->do_channel( this_object(), "sys", "问答系统开始运行。");

	set_heart_beat(20);
}

int query_next_update()
{
	return last_update + REFRESH_INTERVAL - time();
}


void heart_beat()
{
	object *players;
	mixed* r;
	int a1,a2,a3,i;
	int q=random(100),w=random(100),e=random(100),t=random(100),y=random(100),u=random(100);
	int time = time();
	r = localtime(time);

  if(r[1]%5==0&&!frag&&!query("wenda_ok"))  //5分钟一个问题
	{
		players = users();
		b_flag=1;
		a1=random(57);
    	for(i = 0; i<sizeof(players); i++)
       {
       players[i]->set("huida",1);
       tell_object(players[i],HIW"  新MUD问答系统开始运行！"NOR"\n"); 
       set("wenda_ok",1);
       }
		if(a1==0)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"山有木兮木有枝"+ZJURL("cmds:huidaadmin "+"心悦君兮君不知 ")ZJSIZE(24)+"〖回答〗"NOR"");	
		}
		
		else if(a1==1)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"人生若只如初见"+ZJURL("cmds:huidaadmin "+"何事秋风悲画扇 ")ZJSIZE(24)+"〖回答〗"NOR"");	
		}else if(a1==2)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"十年生死两茫茫"+ZJURL("cmds:huidaadmin "+"不思量，自难忘 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==3)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"曾经沧海难为水"+ZJURL("cmds:huidaadmin "+"除却巫山不是云 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==4)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"玲珑骰子安红豆"+ZJURL("cmds:huidaadmin "+"入骨相思知不知 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==5)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"只愿君心似我心"+ZJURL("cmds:huidaadmin "+"定不负相思意 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==6)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"愿得一心人"+ZJURL("cmds:huidaadmin "+"白头不相离 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==7)
		{
CHANNEL_D->do_channel(this_object(), "chat", HIY""+q+"*"+w+"*"+e+"*"+t+"=?"+ZJURL("cmds:huidaadmin "+""+(q*w*e*t)+" ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==8)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY""+q+"*"+w+"*"+e+"*"+t+"=?"+ZJURL("cmds:huidaadmin "+""+(q*w*e*t)+" ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==9)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"人面不知何处去"+ZJURL("cmds:huidaadmin "+"桃花依旧笑春风 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==10)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"人间四月芳菲尽"+ZJURL("cmds:huidaadmin "+"山寺桃花始盛开 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==11)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"春宵一刻值千金"+ZJURL("cmds:huidaadmin "+"花有清香月有阴 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==12)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"今人不见古时月"+ZJURL("cmds:huidaadmin "+"今月曾经照古人 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==13)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"月上柳梢头"+ZJURL("cmds:huidaadmin "+"人约黄昏后 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==14)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"沧海月明珠有泪"+ZJURL("cmds:huidaadmin "+"蓝田日暖玉生烟 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==15)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"男儿何不带吴钩"+ZJURL("cmds:huidaadmin "+"收取关山五十州 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==16)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"苟利国家生死以"+ZJURL("cmds:huidaadmin "+"岂因祸福避趋之 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==17)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"人生自古谁无死"+ZJURL("cmds:huidaadmin "+"留取丹心照汗青 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==18)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"商女不知亡国恨"+ZJURL("cmds:huidaadmin "+"隔江犹唱后庭花 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==19)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"我见青山多妩媚"+ZJURL("cmds:huidaadmin "+"料青山见我应如是 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==20)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"日照香炉生紫烟"+ZJURL("cmds:huidaadmin "+"遥看瀑布挂前川 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==21)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"人间万事"+ZJURL("cmds:huidaadmin "+"毫发常重泰山轻 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==22)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"造化钟神秀"+ZJURL("cmds:huidaadmin "+"阴阳割昏晓 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==23)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"庐山烟雨浙江潮"+ZJURL("cmds:huidaadmin "+"未至千般恨不消 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==24)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"人生得意须尽欢"+ZJURL("cmds:huidaadmin "+"莫使金樽空对月 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==25)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"疏影横斜水清浅"+ZJURL("cmds:huidaadmin "+"暗香浮动月黄昏 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==26)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"不经一番寒彻骨"+ZJURL("cmds:huidaadmin "+"怎得梅花扑鼻香 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==27)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"春江潮水连海平"+ZJURL("cmds:huidaadmin "+"海上明月共潮生 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==28)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY""+q+"+"+w+"+"+e+"+"+t+"=?"+ZJURL("cmds:huidaadmin "+""+(q+w+e+t)+" ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==29)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY""+q+"*"+w+"*"+e+"*"+t+"=?"+ZJURL("cmds:huidaadmin "+""+(q*w*e*t)+" ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==30)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"请输入"+q+"的3次方加"+w+""+ZJURL("cmds:huidaadmin "+""+((q*q*q)+w)+" ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==31)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"演员打斗真叫绝（打一字）"+ZJURL("cmds:huidaadmin "+"角 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==32)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"两个傻瓜要起身（打一成语）"+ZJURL("cmds:huidaadmin "+"蠢蠢欲动 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==33)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"伯牙望知音，琴声意绵绵。(打一成语）"+ZJURL("cmds:huidaadmin "+"一见钟情 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==34)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"笑傲江湖发生在哪个朝代"+ZJURL("cmds:huidaadmin "+"明朝 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==35)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"万瑜楼的绝学是"+ZJURL("cmds:huidaadmin "+"忘我武拳 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==36)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"云一緺，玉一梭"+ZJURL("cmds:huidaadmin "+"澹澹衫儿薄薄罗 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==37)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"尊前拟把归期说"+ZJURL("cmds:huidaadmin "+"欲语春容先惨咽 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==38)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"饮酒莫辞醉"+ZJURL("cmds:huidaadmin "+"醉多适不愁 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==39)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"风卷寒云暮雪晴"+ZJURL("cmds:huidaadmin "+"江烟洗尽柳条轻 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==40)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"但使龙城飞将在"+ZJURL("cmds:huidaadmin "+"不教胡马度阴山 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==41)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"舞榭歌台"+ZJURL("cmds:huidaadmin "+"风流总被雨打风吹去 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==42)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"天南地北双飞客"+ZJURL("cmds:huidaadmin "+"老翅几回寒暑 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==43)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"欢乐趣，离别苦"+ZJURL("cmds:huidaadmin "+"就中更有痴儿女 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==44)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"床前明月光"+ZJURL("cmds:huidaadmin "+"疑是地上霜 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==45)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"明月松间照"+ZJURL("cmds:huidaadmin "+"清泉石上流 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==46)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"何当共剪西窗烛"+ZJURL("cmds:huidaadmin "+"却话巴山夜雨时 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==47)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"孤舟蓑笠翁"+ZJURL("cmds:huidaadmin "+"独钓寒江雪 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==48)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"寻寻觅觅，冷冷清清"+ZJURL("cmds:huidaadmin "+"凄凄惨惨戚戚 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==49)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"满地黄花堆积。憔悴损"+ZJURL("cmds:huidaadmin "+"如今有谁堪摘 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==50)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"有情风万里卷潮来"+ZJURL("cmds:huidaadmin "+"无情送潮归 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==51)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"庭院深深深几许，杨柳堆烟"+ZJURL("cmds:huidaadmin "+"帘幕无重数 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==52)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"一曲新词酒一杯"+ZJURL("cmds:huidaadmin "+"去年天气旧亭台 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==53)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"曾经沧海难为水"+ZJURL("cmds:huidaadmin "+"除却巫山不是云 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==54)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"滚滚长江东逝水"+ZJURL("cmds:huidaadmin "+"浪花淘尽英雄 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==55)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"枯藤老树昏鸦，小桥流水人家"+ZJURL("cmds:huidaadmin "+"古道西风瘦马 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==56)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"一生一代一双人"+ZJURL("cmds:huidaadmin "+"争教两处销魂 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}else if(a1==57)
		{
	CHANNEL_D->do_channel(this_object(), "chat", HIY"前不见古人，后不见来者"+ZJURL("cmds:huidaadmin "+"念天地之悠悠，独怆然而涕下 ")ZJSIZE(24)+"〖回答〗"NOR"");
		}
		
		frag=1;
	}else{
	frag=0;
	}
	if(r[1]==12||r[1]==22||r[1]==32||r[1]==42||r[1]==52||r[1]==2)  //问题出来后，2分钟未回答即失去本轮回答资格
	{	
	    delete("wenda_ok");
        players = users();
	    b_flag=0;
		for(i = 0; i<sizeof(players); i++)
         {
         players[i]->set("huida",0);
       }
	}
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
