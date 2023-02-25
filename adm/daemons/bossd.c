// by name 2021.3.20 qq：21315491
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
string query_save_file()
{
	return DATA_DIR "bossd";
}

//外国人入侵
void check_waiguorenruqin();
varargs void start_story(string sname);
void go_on_process(object ob);
void init_story();
int filter_listener(object ob);
static int flag;
static object  running_story;
int last_update = 0;
#define REFRESH_INTERVAL	10 * 3600
string *story_name;
mapping history;
static int step;
static mapping interval;
//赌徒北丑，门派弟子下山
void check_beichoumenpai();
int dutu_ok = 1;
int mpz_ok = 1;
//心魔入侵
void check_xinmoruqin();
void  load_room();
int check_hp(object me,int value);
int choose_player(object me);
int top_list(object ob1,object ob2);
string *allroom_file,room_file,*allplace_name,place_name;//全局变量，以便调用
//神秘商人
void check_shenmishangren();
void check_shenmishangrens();
static int shenmishangren_flag;
//倚天屠龙
void check_yitiantulong();
static int yitian_flag;
static int tulong_flag;
//定时副本，灵脉山洞，麒麟洞，守卫襄阳，公益活动
void check_dingshifuben();
void wupin();
static int dingshifuben_flag1;
static int dingshifuben_flag2;
static int dingshifuben_flag3;
static int dingshifuben_flag4;
static int wupin_flag;
//幽魂年兽
void check_youhunnianshou();
static int youhunnianshou_flag;
//其他BOSS	
void check_qitaboss();
static int qitaboss_flag;
//开心答题
void check_kaixindati();
static int kaixindati_flag;
//学习http
void http();
#include "/cmds/usr/props.h"
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "BOSS精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "BOSS系统已经启动。");
	restore();
	if (! arrayp(story_name))
	init_story();
	if (! mapp(history))
	history = ([ ]);
	interval = ([ ]);
	set_heart_beat(20);
}

void heart_beat()
{
//外国人入侵
check_waiguorenruqin();
//赌徒北丑，门派弟子下山
check_beichoumenpai();
//心魔入侵
check_xinmoruqin();
//神秘商人
check_shenmishangren();
//倚天屠龙
check_yitiantulong();
//定时副本，灵脉山洞，麒麟洞，守卫襄阳
check_dingshifuben();
//幽魂年兽
check_youhunnianshou();
//其他BOSS	
check_qitaboss();
//开心答题
check_kaixindati();
//HTTP学习
http();
}



//世界boss
void check_waiguorenruqin()
{
mixed *sj= localtime(time());
if(sj[1]==0&&sj[2]>9&&sj[2]<24){
if(!objectp(running_story)&&!flag){
flag = 1;
remove_call_out("start_story");
remove_call_out("process_story");
call_out("start_story", 0);
}
}
else flag = 0;
}
int query_next_update()
{
	return last_update + REFRESH_INTERVAL - time();
}
void init_story()
{
	CHANNEL_D->do_channel(this_object(), "sys", "BOSS系统更新所有BOSS。");
	story_name = get_dir("/adm/daemons/boss/" + "*.c");
	story_name = map_array(story_name, (: $1[0..<3] :));

	last_update = time();
}
void go_on_process(object ob)
{
	remove_call_out("start_story");
	remove_call_out("process_story");
	call_out("process_story", 1, ob);
}
int clean_up()
{
	return 1;
}
object query_running_story()
{
	return running_story;
}
varargs void start_story(string sname)
{
	string *all_story;
	string name;
	object ob;
	CHANNEL_D->do_channel(this_object(), "sys", "BOSS系统开始选择BOSS。");
	if (sname)
		all_story = explode(sname, ",");
	else
		all_story = story_name;
	while (sizeof(all_story)){
		name = all_story[random(sizeof(all_story))];
		if (undefinedp(history[name]))
			history += ([ name : 0 ]);
		else
			history[name] = (int)time();
		CHANNEL_D->do_channel(this_object(), "sys","BOSS系统选择了BOSS(" + name + ")。"); 
		if (ob = find_object("/adm/daemons/boss/" + name))
		destruct(ob);	
		catch(ob = load_object("/adm/daemons/boss/" + name));
	    running_story = ob;	
		if (objectp(ob)){
			step = 0;
			go_on_process(ob);
			break;
		}
	}
}
string *query_all_story()
{
	return story_name;
}
void process_story(object ob)
{
	mixed line;
	object *listeners;
	string prompt;
	go_on_process(ob);
	if (! objectp(ob)){
		return;
	}
	line = ob->query_story_message(step);
	step++;
	prompt = ob->prompt();
	if (! prompt) prompt = HIG "【异域挑战】"NOR"" ;
	if (functionp(line)) catch(line = evaluate(line));
	if (stringp(line))
	{
		listeners = filter_array(users(), (: filter_listener :));
		message("story",  prompt + WHT + line + ""NOR"\n", listeners);
	}

	if (intp(line) && ! line)
	{
		destruct(ob);
	}
}
int filter_listener(object ob)
{
	if (ob->query("env/no_story")) return 0;
	return 1;
}



//赌徒北丑，门派入侵
void check_beichoumenpai()
{
mixed *sj= localtime(time());
	int GMT = time();
	string d, times;
	int h, s;
	object room, ob;
	times = ctime(GMT);
	//Sun(星期日) Mon(星期一)  Tue(星期二)  Wed(星期三)  Thu(星期四)  Fri(星期五)  Sat(星期六)
	d = times[0..2];//星期
	h = to_int(times[10..12]);//时
	s = to_int(times[14..15]);//分
	
	if (h >= 17 && h <= 20 && 0 == s && dutu_ok)
	{
	    __DIR__"dshuodong/dutu/dutu_beichou"->start();
	    dutu_ok = 0;
	}
	
	if(h > 8 && h < 22)
	{
		if((s == 30) && mpz_ok)
		{
		    __DIR__"dshuodong/mpz/mpz"->start();
	    	mpz_ok = 0;
		}
	}
	
	if (s == 20)
	    dutu_ok = 1;
	if (s == 50)
	    mpz_ok = 1;
}

//心魔入侵
void check_xinmoruqin()
{
mixed *sj= localtime(time());
	int GMT = time();
	string d, times;
	int h, s,value;
	object room, ob;
		string *duobao=({
"/clone/vip/dan_qingxin",
"/clone/vip/putao",
"/clone/vip/dan_zhengqi",
"/clone/vip/dan_xieqi",
"/clone/vip/jinsha",
"/clone/vip/lingzhi",
});
	times = ctime(GMT);

	//Sun(星期日) Mon(星期一)  Tue(星期二)  Wed(星期三)  Thu(星期四)  Fri(星期五)  Sat(星期六)
	d = times[0..2];//星期
	h = to_int(times[10..12]);//时
	s = to_int(times[14..15]);//分
//	用来处理世界怪物，晚上九点开始，到凌晨三点
	if ((h>=21||h<=3)&&(s==30||s==0))

	{
	object npc,obj,*npcs;
	//因为要产生新的世界怪物，原来的世界怪物应该清除 以节省内存
		npcs = children("/clone/worldboss/xinmo");
		foreach (npc in npcs)
		destruct(npc);
	npc=new("/clone/worldboss/xinmo");
	obj=new(duobao[random(sizeof(duobao))]);

	if (obj->query("yuanbao"))
	value=obj->query("yuanbao")*10000;
	else
	if (obj->query("value"))
	value=obj->query("value")/2;
	else
	value=100000;	
	obj->move(npc);	
    check_hp(npc,value);	
	while (1)
	{
	load_room();
		if (!room_file->query("no_fight"))	
		break;
	}
	npc->move(room_file);
	choose_player(npc);
	npc->force_me("chat 理智？哼，愚蠢的事物，本魔在"+place_name+"的"+room_file->query("short")+"挑战天下高手，让本魔来征服江湖！");
//	QQ_D->msg("【心魔】理智？哼，愚蠢的事物，本魔在"+no_color(place_name)+"的"+no_color(room_file->query("short"))+"挑战天下高手，让本魔来征服江湖！");
	}
	else
	return;
		
}
void  load_room()
{
mapping room_place = ([
	"白驼山"		: "/d/baituo/",
	"北京"			: "/d/beijing/",
	"长安" 			: "/d/changan/",
	"扬州"			: "/d/city/",
	"成都"			: "/d/city3/",
	"大理"			: "/d/dali/",
	"峨嵋山" 		: "/d/emei/",
	"佛山"			: "/d/foshan/",
	"丐帮" 			: "/d/gaibang/",
	"福州"			: "/d/fuzhou/",
	"关外"			: "/d/guanwai/",
	"归云山庄"	: "/d/guiyun/",
	"古墓" 			: "/d/gumu/",
	"杭州"			: "/d/hangzhou/",
	"黑木涯"		: "/d/heimuya/",
	"衡山" 			: "/d/hengshan/",
	"恒山"			: "/d/henshan/",
	"黄河"			: "/d/huanghe/",
	"华山派"		: "/d/huashan/",
	"灵鹫宫"			: "/d/lingjiu/",
	"灵州"			: "/d/lingzhou/",
	"梅庄"			: "/d/meizhuang/",
	"明教" 			: "/d/mingjiao/",
	"青城山"		: "/d/qingcheng/",
	"全真派" 		: "/d/quanzhen/",
	"泉州" 			: "/d/quanzhou/",
	"少林寺" 		: "/d/shaolin/",
	"神龙岛"		: "/d/shenlong/",
	"嵩山"			: "/d/songshan/",
	"苏州"			: "/d/suzhou/",
	"泰山"			: "/d/taishan/",
	"桃花岛"		: "/d/taohua/",
	"天龙寺"		: "/d/tianlongsi/",
	"万劫谷"		: "/d/wanjiegu/",
	"武当山"		: "/d/wudang/",
	"侠客岛"		: "/d/xiakedao/",
	"襄阳"			: "/d/xiangyang/",
	"逍遥派"		: "/d/xiaoyao/",
	"星宿海" 		: "/d/xingxiu/",
	"血刀门" 		: "/d/xuedao/",
	"雪山" 			: "/d/xueshan/",
	"燕子坞" 		: "/d/yanziwu/",
	"五毒教" 		: "/d/wudu/",
	"魔教" 		: "/d/wansong/",
]);
//读取所有的大地图名称
allplace_name=keys(room_place);
//随机读取一个大地图
place_name=allplace_name[random(sizeof(allplace_name))];
//读取一个大地图内全部的房间
allroom_file=stat(room_place[place_name]);
//只保留大地图目录内的.c文件（房间）
foreach (room_file in allroom_file)
{
if (strsrch(room_file,".c")==-1)
allroom_file-=({room_file});
}
//随机获取一个房间地点
room_file=room_place[place_name]+allroom_file[random(sizeof(allroom_file))];
}
//处理生成的世界怪物的状态量。
int check_hp(object me,int value)
{
int qi,neili;
 qi = me->query("max_qi")*20;
 neili = me->query("max_neili")*20;

me->set("max_qi",qi);
me->set("eff_qi",qi);
me->set("qi",qi);
me->set("max_neili",neili);
me->set("neili",neili);

return 1;
}
//随机选择前三名的玩家进行处理
int choose_player(object me)
{
       object *ob,*list,rand_player;
   
        ob = filter_array(children(USER_OB),(: userp($1) && !wizardp($1) :));
        list = sort_array(ob, (: top_list :));
        
        if (sizeof(list)>3)//如果连三个玩家都没有，怎么办?哈哈 ，没有就报错呗，算了加个判断。
        {   
        list = ({list[0],list[1],list[2]});//读取前三位
        rand_player = list[random(sizeof(list))];//随机读取一位玩家
        "/cmds/adm/copyskill"->copy_skill(me,rand_player);//复制对应玩家的技能
        me->set_name(rand_player->name()+"·心魔", ({ getuid(rand_player)+" mo", "mo" }));
        me->set("name",rand_player->name()+"·心魔");//第二次比较保险
        return 1;
        }
             
}
//直接用已经写好的排列规则
int top_list(object ob1,object ob2)
{
    return "/cmds/usr/topz"->top_list(ob1,ob2);    
}



//神秘商人
void check_shenmishangren()
{
mixed *sj= localtime(time());
object npc,room,ob,*obs;
int i=random(10);
    if(!shenmishangren_flag&&sj[1]%30==0){
	npc=new("/adm/npc/shangren");
	if(i<3){
	npc->move("/d/city/kedian");
	room=load_object("/d/city/kedian.c");
    room->set("action_list",(["限时抢购":"myshops",]));
	message("channel:chat",HIY"【异域】：据说"+npc->name()+HIW"在扬州客店落脚，快去看看这次他带了些什么好货！"NOR"\n",users());
//	QQ_D->msg("【异域】：据说"+no_color(npc->name())+"在扬州客店落脚，快去看看这次他带了些什么好货！");
	call_out("check_shenmishangrens",300);
	}else
	if(i>3&&i<6){
	npc->move("/d/xiangyang/kedian");
	room=load_object("/d/xiangyang/kedian.c");
    room->set("action_list",(["限时抢购":"myshops",]));
	message("channel:chat",HIY"【异域】：据说"+npc->name()+HIG"在襄阳客店落脚，快去看看这次他带了些什么好货！"NOR"\n",users());
//	QQ_D->msg("【异域】：据说"+no_color(npc->name())+"在襄阳客店落脚，快去看看这次他带了些什么好货！");
	call_out("check_shenmishangrens",300);
	}else{
	npc->move("/d/hangzhou/kedian");
	room=load_object("/d/hangzhou/kedian.c");
    room->set("action_list",(["限时抢购":"myshops",]));
	message("channel:chat",HIY"【异域】：据说"+npc->name()+HIY+"在杭州客店落脚，快去看看这次他带了些什么好货！"NOR"\n",users());
//	QQ_D->msg("【异域】：据说"+no_color(npc->name())+"在杭州客店落脚，快去看看这次他带了些什么好货！");
	call_out("check_shenmishangrens",300);
	}
  shenmishangren_flag=1;
  }else
  if(sj[1]==10||sj[1]==40){
  shenmishangren_flag=0;
 }
}
void check_shenmishangrens()
{
object npc,room,ob,*obs;
obs = children("/adm/npc/shangren");
foreach(ob in obs){
if(typeof(ob)=="object"){
room=load_object("/d/city/kedian.c");
room->delete("action_list",(["限时抢购":"myshops",]));
room=load_object("/d/xiangyang/kedian.c");
room->delete("action_list",(["限时抢购":"myshops",]));
room=load_object("/d/hangzhou/kedian.c");
room->delete("action_list",(["限时抢购":"myshops",]));
destruct(ob);
}
}
}


//倚天屠龙
void check_yitiantulong()
{
mixed *sj= localtime(time());
object jian,jing,road3,dao;
	if(sj[1]==30&&sj[2]==21){
		jian = find_object("/d/tulong/obj/yitianjian");
		jing = find_object("/d/tulong/obj/zhenjing");
		if ( !yitian_flag && (!jian||!environment(jian)) && (!jing||!environment(jing)) ) {
			road3 = find_object("/d/heimuya/road3");
			if(!road3) road3 = load_object("/d/heimuya/road3");
			road3->start_yitian();
			yitian_flag = 1;
			QQ_D->msg("【倚天屠龙】赵敏冷哼几声，露出不屑的眼神。");
		    QQ_D->msg("【倚天屠龙】赵敏：不错！倚天剑就在我手中，有本事就尽管到万安寺中来拿。");
		    QQ_D->msg("【倚天屠龙】赵敏一众携带倚天剑出现在万安寺，倚天剑剧情启动。");
		}
	}
	else yitian_flag = 0;
	
	if(sj[1]==30&&sj[2]==20){
		dao = find_object("/d/tulong/obj/tulongdao");
		jing = find_object("/d/tulong/obj/zhenjing");
		if ( !tulong_flag && (!dao||!environment(dao)) && (!jing||!environment(jing)) ) {
			road3 = find_object("/d/beijing/haigang");
			if(!road3) 
			road3 = load_object("/d/beijing/haigang");
			road3->start_tulong();
			tulong_flag = 1;
			QQ_D->msg("【倚天屠龙】白龟寿仰天一声长笑。");
            QQ_D->msg("【倚天屠龙】白龟寿：我天鹰教得到屠龙宝刀，今日在王盘山岛举行扬刀立威大会。");
            QQ_D->msg("【倚天屠龙】白龟寿携带屠龙刀出现在王盘山，屠龙刀剧情启动。");
		}
	}
	else tulong_flag = 0;
}



//定时副本
void check_dingshifuben()
{
mixed *sj= localtime(time());
object ob;
   if(!dingshifuben_flag1&&(sj[1]==10&&sj[2]==10)){			
	ob = load_object("/d/dali/shulinwai");
	ob->start_sc();			//启动副本
	message("channel:chat",HIY"【活动】："+HIY+"大理树林外"+HIR+"《灵脉山洞》"+HIY+"开放，速去探索其中灵脉！"NOR"\n",users());
	QQ_D->msg("【活动】：大理树林外《灵脉山洞》开放，速去探索其中灵脉！");
	dingshifuben_flag1=1;
	}else
	if(sj[1]==20){
	dingshifuben_flag1=0;
	}	
	if(!dingshifuben_flag2&&(sj[1]==10&&sj[2]==17)){			
	ob = load_object("/d/city3/lingyunku");
	ob->start_qilin();			
	message("channel:chat",HIY"【活动】："+HIY+"成都凌云窟"+HIR+"《麒麟洞》"+HIY+"开放，速去击杀火麒麟！"NOR"\n",users());
	QQ_D->msg("【活动】：成都凌云窟《麒麟洞》开放，速去击杀火麒麟！");
	dingshifuben_flag2=1;
	}else
	if(sj[1]==20){
	dingshifuben_flag2=0;
	}
	if(!dingshifuben_flag3&&(sj[1]==10&&sj[2]==19)){			
	ob = load_object("/d/xiangyang/northgate2");
	ob->start_xiangyang();			
	message("channel:chat",HIY"【活动】："+HIY+"襄阳玄武门外"+HIR+"《守卫襄阳》"+HIY+"开放，速去击杀蒙古兵！"NOR"\n",users());
	QQ_D->msg("【活动】：襄阳玄武门外《守卫襄阳》开放，速去击杀蒙古兵！");
	dingshifuben_flag3=1;
	}else
	if(sj[1]==20){
	dingshifuben_flag3=0;
	}
	if(!dingshifuben_flag4&&(sj[1]==0&&sj[2]==8)){
    ob = load_object("/fuben/jlj/ljc");
    ob->start_jlj();		
    message("channel:chat",HIY"【活动】："+HIY+"扬州垃圾场"+HIR+"《公益活动》"+HIY+"开放，速去捡垃圾捡垃圾维护扬州环境！"NOR"\n",users());
    QQ_D->msg("【活动】：扬州垃圾场《公益活动》开放，速去捡垃圾捡垃圾维护扬州环境！");
    call_out("wupin",1);
    dingshifuben_flag4=1;
    }else
    if(sj[1]==10){
    dingshifuben_flag4=0;
    }	
}
void wupin()
{
    mixed sj=localtime(time());
    object ob,pro;
    string id = props[random(sizeof(props))];
    string room=get_dir("/fuben/jlj/")[random(sizeof(get_dir("/fuben/jlj/")))];
    ob=load_object(id);
    pro=load_object("/fuben/jlj/"+room);
    if(sj[1]<=10&&sj[2]==8&&!wupin_flag){
    ob->set("gyhd/jlj",1);
    ob->move(pro);
    wupin_flag=1;
    tell_room(pro,""HIY"天空一声巨响，啪的一下【"+NOR+ob->name()+NOR+"】"HIY"掉在了你的面前。"NOR"\n");
    call_out("wupin",1+random(30));
    }else{
    wupin_flag=0;
    remove_call_out("wupin");
    }
}
//幽魂年兽
void check_youhunnianshou()
{
mixed *sj= localtime(time());
object ob;
string place;
	if(!youhunnianshou_flag&&(sj[6]==6&&sj[1]%5==0||sj[6]==0&&sj[1]%5==0)){			
	    ob = new("/d/aaa/npc/youhun");
		NPCS_D->place_npc(ob, ({}));
		place = ob->query("place");		
		message("channel:chat",HIY"【活动】："+HIM+"幽魂("+ob->query("id")+")"+HIM+"来到了武林四处滥杀，位于："+place+HIM"一带，击杀后可以获得丰富奖励！"NOR"\n",users());
		youhunnianshou_flag=1;
	}else{
	youhunnianshou_flag=0;
	}
	   if(0){
        ob = new("/d/aaa/npc/npc");
		NPCS_D->place_npc(ob, ({}));
		place = ob->query("place");		
		message("channel:chat",HIY"【除夕】："+HIR+"年兽("+ob->query("id")+")"+HIW+"来到了武林四处滥杀，位于："+place+HIW"一带，击杀后可以获得丰富奖励！"NOR"\n",users());
	  }	
}



//其他boss 
void check_qitaboss()
{
mixed *sj= localtime(time());
string *d,*dd,ds,dds;
int i=random(10);
	if(!qitaboss_flag&&sj[1]%30==0)
	{
    d = ({
	"/d/city/guangchang",	
	"/d/quanzhou/zhongxin",		
	"/d/shaolin/nanyang",			
    "/d/guanwai/jishi",		    
    "/d/dali/center",		
	"/d/beijing/tiananmen",	
	"/d/city3/guangchang",				    	    	    			
  });  
    dd = ({
    "/fuben/npc_boss/baihu",		    
    "/fuben/npc_boss/shenlong",		  
    "/fuben/npc_boss/damu-feizei",		
    "/fuben/npc_boss/qicai-liulishou",	
    "/fuben/npc_boss/chanchu",				    	    	    			
   });      	        	
    ds = d[random(sizeof(d))];
    dds = dd[random(sizeof(dd))];
	dds->move(ds);	
	if(i<3){
	message("channel:chat",CYN"【BO"HIG"SS】"CYN"：听说"+dds->query("name")+CYN+"出现在"+ds->query("short")+"四处作乱！各位侠士们速去制裁！"NOR"\n",users());	
	}else
	if(i>3&&i<6){
	message("channel:chat",CYN"【BO"HIG"SS】"CYN"：最近"+dds->query("name")+CYN+"又出现了，目前在"+ds->query("short")+"到处恶意伤人！各位武侠速去击杀作乱者！"NOR"\n",users());	
	}else
	{
	message("channel:chat",CYN"【BO"HIG"SS】"CYN"：据说"+dds->query("name")+CYN+"现世在"+ds->query("short")+"！各位武侠速去一探究竟！"NOR"\n",users());	
	}
	qitaboss_flag=1;
}else
if(sj[1]==10||sj[1]==40){
qitaboss_flag=0;
}
}



//开心答题
void check_kaixindati()
{
    mixed *sj= localtime(time());
    object player;
	if(!kaixindati_flag&&sj[1]==10&&sj[2]==18){	
	set("channel_id", "唐伯虎");
	CHANNEL_D->do_channel( this_object(), "chat", HIY"潜能如江海，君能几瓢饮？科举闯关答题时间到了。"+NOR"。");
	QQ_D->msg("唐伯虎：潜能如江海，君能几瓢饮？科举闯关答题时间到了。");
    set("channel_id", "活动NPC系统");		 
	foreach(player in users()){
    if(!player->query("env/dati")) 
    continue;  
    player->delete_temp("kxcd");          
    player->set_temp("kxcd/start_time",1);	
    tell_object(player,ZJFORCECMD("kaixindati"));
     } 	
     kaixindati_flag=1;
   }else
   if(sj[1]==20){
   kaixindati_flag=0;
   }
}


//学习http
void http()
{
/*
object https;
if(https = find_object("/cmds/usr/http/dujitang")){
destruct(https);
}
load_object("/cmds/usr/http/dujitang");
*/
//"/cmds/usr/http/djt.c"->main(this_object(),"djt");
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
