// logind.c
//不要乱改
#include <ansi.h>
#include <command.h>
#include <login.h>
#include <config.h>
#include <getconfig.h>

#define MUDLIST_CMD     "/cmds/usr/mudlist"
#define REBOOT_CMD      "/cmds/arch/reboot"

inherit F_DBASE;

static int wiz_lock_level = 0;

static string *movie;

string *banned_name = ({
    "你", "你", "我", "他", "她", "它","东方","艹","逼",
    "爸", "爷", "　", "妈","她妈","他妈","操操","fuck","下阴","阴部","口交","性交","阴唇","阴道",
    "屎", "尿", "粪","操你","日你","大爷","老妈","干你","操妈",
"自己","杀手","闪电","雪人","逍遥","我们","你们","他们","咱们","大家","某人","尸体",
"天神","总管","龙神","仙人","巫师","门客","玩家","书","书剑","名字待定","中神通","蒙面",
"蒙面人","刺客","忍者","镖师","鬼魂","头颅","杀人犯",
// Mud 地名，门派名
"衡山","华山","嵩山","恒山","泰山","雪山","黄山","天山","西域","苗疆","东北","中原",
"南疆","长江","黄河","中国","中华","昆仑山","长白山","白驼山","武当山","峨嵋山",
"冰火岛","桃花岛","黑木崖",
"少林","丐帮","明教","密宗","古墓","全真","铁掌","大理","白驼","桃花","星宿",
"天龙寺","大轮寺","五毒教","正义","邪恶","五岳剑派","日月神教","官府","武林",
"少林寺","武当派","铁掌帮","普通百姓","峨嵋派","姑苏慕容","古墓派","华山派","嵩山派",
"明教","神龙教","星宿派",
// 重要人物名字
"金庸","邓小平","江泽民","毛泽东","朱榕基","皇帝", "皇上","总理", "主席", "习近平", "李克强",
 "管理员", "巫师", "干部",
// 小说人物
"张三丰","张无忌","郭靖","杨过","令狐冲","胡斐","苗人凤","韦小宝","袁承志","胡一刀",
"陈家洛","段誉","萧锋","乔锋","虚竹","东方不败","欧阳锋","洪七公","黄药师","段皇爷",
"一灯大师","王重阳","周伯通","黄蓉","风清扬","独孤求败",
// 脏话
"统一","法轮","法轮研究","法轮大","吃人","他妈的","去你的","操你妈","干你娘","废物",
"混蛋","坏蛋","杀人","抢劫","强奸","妓女","台独","领导","中央","屁眼","屁股","裸体",
"放屁","鸡巴","阴道","婊子","你丫","日你","赤佬","瘪三","傻逼","蠢蛋","操他","我操",
"太监","宦官","阉割","阉人","鸡", "奸淫", "淫荡", "轮奸", "奸", "三级", "政治",
//特殊名字
"淑女","君子",

});

// 内部调用的函数
private void get_user(string arg, object ob);
private void get_char(string arg, object ob);
void jiance(string arg,object ob,string str);
private void init_new_player(object user);

// 可以被外部调用的函数
object  make_body(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg, int maxlen);


void create() 
{
	seteuid(ROOT_UID);
	set("channel_id", "连线");
}

void logon(object ob)
{
	string str;

	object *players;
	players = users();
	if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
		write(ZJTMPSAY"你的地址在本 MUD 不受欢迎。\n");
		destruct(ob);
		return;
	}
	write("\n");
	str = crypt(ZJKEY,"yigejiaghu123");
    write("ver1.0:"+str+"\n");
	input_to("jiance",ob,str);
}

void jiance(string arg,object ob,string str)
{
	if(!arg){
		input_to("jiance",ob,str);
		return;
	}
	ob->set_temp("web_log",1);
	if(arg!="//")
	write("版本验证成功\n");
	input_to("get_user", ob);
}

private void get_user(string arg, object ob)
{
	//arg,账号║密码║密文║email。
	object old_link,user;
	string *myinfo,ip,email;
	object *usr;
    int i,iplimit;
//tell_object(find_player("name"),"执行结果2："+arg+"=\n");
     /*
     ipt=query_ip_number(ob);
	 for(i = 0; i<sizeof(players); i++){
     ips=query_ip_number(players[i]);    
     if(ipt==ips){
     ob->set_temp("ipsss",1);
     }
     if(ob->query_temp("ipsss") >=3){          
     write(ZJTMPSAY"你当前登陆账号与线上账号IP相同数大于等于3个，"    
     "请先将在线无用的账号将其QUIT再重新连线。\n");
     destruct(ob);
     }
     }
     */     
     
    usr = users() + filter(children(LOGIN_OB), (: interactive :));
    iplimit = 0;
    for(i = 0; i < sizeof(usr); i++){
        if (query_ip_number(usr[i]) == query_ip_number(ob)){
        iplimit++;
       }        
    }
    /*
    if(iplimit>=5){
    write(ZJTMPSAY"你当前登陆账号与线上账号IP相同数大于等于5个，"    
     "请先将在线无用的账号将其QUIT再重新连线。\n");
     destruct(ob);
    }*/
     
  
     

	if( !arg||arg=="") {
		input_to("get_user", ob);
		return;
	}
    //arg+="2046889157@qq.com";
    
/*
	if( sizeof(myinfo)!=4 ) {
		write(ZJTMPSAY"未知错误，请重试s。。。\n");
		input_to("get_user", ob);
		return;
	}
	*/
	/*
	if(myinfo[2]!="yigejiaghu123"){ 
	if(myinfo[2]!="yigejiaghu123s"){ 
    write(ZJTMPSAY"密文错误，加群：1074716854 下载最新客户端进行登陆！"+myinfo[2]+"\n");
	destruct(ob);
	}else{
	ob->set_temp("web",1);
	}
    }
*/
	myinfo = explode(arg,"║");
    ob->set_temp("web",1);
	if( !check_legal_id(lower_case(myinfo[0]))) {
		//0001，ID不合法
		input_to("get_user", ob);
		return;
	}		
	myinfo[0] = lower_case(myinfo[0]);


	if (wiz_level(myinfo[0]) < wiz_lock_level)
        {
		write(sprintf(ZJTMPSAY"对不起，%s正在维护中，请稍后登录。。。\n",LOCAL_MUD_NAME()));
		input_to("get_user",ob);
		return;
	}

	if( (string)ob->set("id", myinfo[0]) != myinfo[0]) {
		write(ZJTMPSAY"未知错误，请重试i。。。\n");
		input_to("get_user", ob);
		return;
	}

	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) 
	{
		if( !ob->restore() ) 
		{
			write(ZJTMPSAY"人物存档出现问题。。。\n");
			input_to("get_user", ob);
			return;
		}
		
		
		if (! stringp(myinfo[1]) || oldcrypt(myinfo[1], ob->query("password"))!=ob->query("password"))
		{
			write(ZJTMPSAY"游戏密码错误，请联系管理员！\n");
			destruct(ob);
			return;
		}
		
		
		
	}
	else 
		ob->set("body", USER_OB);


     (string)ob->set("data_id",myinfo[0]);
     (string)ob->set("data_password",myinfo[1]);
    // (string)ob->set("data_email",myinfo[3]);
     
	if( (string)ob->set("password",oldcrypt(myinfo[1],"zj")) != oldcrypt(myinfo[1],"zj")) {
		write(ZJTMPSAY"未知错误，请重试p。。。\n");
		input_to("get_user", ob);
		return;
	}

	write("\n");

	user = find_body(ob->query("id"));
	if (user) {
		old_link = user->query_temp("link_ob");
		if( old_link ) {
			if(interactive(user))
			{
				tell_object(user, RED"你的账号在别处登录，你被迫下线了！\n");
				exec(old_link, user);
			}
			destruct(old_link);
		}
		//0007，登陆成功
		write(SYSY"0007\n");
		user->set("start_ip",myinfo[2]);
		write(ZJTMPSAY"登录成功，正在加载世界。。。"NOR"\n");
		reconnect(ob, user);
		return;
	}
	if( objectp(user = make_body(ob)) ) {
		user->set_temp("link_ob",ob);
		if( file_size(user->query_save_file() + __SAVE_EXTENSION__) >= 0 ){
			if( user->restore() ) {
				//////0007，登陆成功
				write(SYSY"0007\n");
			     user->set("start_ip",myinfo[2]);
				write(ZJTMPSAY"登录成功，正在加载世界。。。"NOR"\n");
				enter_world(ob, user);
				return;
			} else {
				write(ZJTMPSAY"人物存档出现问题。。。\n");
				input_to("get_user", ob);
				return;
			}
		}
	}
	destruct(user);
	//请建立角色
	write(SYSY"0008\n");
	input_to("get_char", ob);
}

private void get_char(string arg, object ob)
{
	//arg,性别║头像║昵称。
	object user;
	string *myinfo,result;

	if( !arg||arg=="") {
		input_to("get_char", ob);
		return;
	}

	myinfo = explode(arg,"║");
	if(sizeof(myinfo)!=3){
		write(ZJTMPSAY"错误，请检查重试。\n");
		input_to("get_char", ob);
		return;
	}

	if( !check_legal_name(myinfo[2],4) ) {
		//0009，昵称不符合要求
		input_to("get_char", ob);
		return;
	}
	if (stringp(result = NAME_D->invalid_new_name(myinfo[2])))
	{
		write(ZJTMPSAY"对不起，" + result+"\n");
		input_to("get_char", ob);
		return;
	}

	ob->set("purename", myinfo[2]);
	ob->set("name", myinfo[2]);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", 10);
	user->set("dex", 10);
	user->set("con", 10);
	user->set("int", 10);
	user->set("kar", 10);
	user->set("per", 10);
	user->set("gender", myinfo[0]);
	user->set("img", myinfo[1]);
   
	init_new_player(user);
	VIP_D->restore_vdata(user);
//0007，登陆成功
	write(SYSY"0007\n");
	call_out("enter_world",1,ob, user);
}

object make_body(object ob)
{
	string err;
	object user;
	int n;

	seteuid(getuid());
	user = new(USER_OB);
	if (! user)
	{
		write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set("surname", ob->query("surname"));
	user->set("purename", ob->query("purename"));
	user->set_name( 0, ({ ob->query("id")}) );
	return user;
}

private void init_new_player(object user)
{
	// 初始化必要属性
	user->set("title", "普通百姓");
	user->set("birthday", time() );
	user->set("potential", 99);
	user->set("food", (user->query("str") + 10) * 10);
	user->set("water", (user->query("str") + 10) * 10);
	//user->set("channels", ({ "chat", "rumor", "party","bill", "sos", "family","ic", "rultra" }));
    user->set("channels", ({ "chat", "rumor", "party",
				 "bill", "sos", "family",
				 "ic", "rultra" }));
	// 记录名字
	NAME_D->map_name(user->query("name"), user->query("id"));

	// 设置必要的环境参数
	user->set("env/wimpy", 60);
}

varargs void enter_world(object ob, object user, int silent)
{
	object cloth, shoe, room, login_ob;
	string startroom;
	string ipname;
	if(! is_root(previous_object()))
		return;
    	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	if(ob->query_temp("web_log"))
	{
		user->set_temp("web_log",1);
		if(ob->query_temp("last_ip"))
			user->set("last_ip",ob->query_temp("last_ip"));
	}
	else
	{
		user->delete_temp("web_log");
		user->set("last_ip",query_ip_name(ob));
	}

	//log_file("loginip","时间："+ctime(time())+" 玩家："+user->query("id")+" IP："+user->query("last_ip")+"\n");
	ob->set("registered", user->query("registered"));

	if (interactive(ob)) exec(user, ob);

	write("\n目前权限：" + wizhood(user) + "\n");

	user->setup();
	if (user->query("age") == 14)
	{
		user->set("food", user->max_food_capacity());
		user->set("water", user->max_water_capacity());
	}

	user->save();
	user->set("last_save", time());
	user->set("name_time",0);
	/*
	user->force_me("look");
	write(ZJTTMENU"飞行:help ditu"ZJSEP"客栈:recall"ZJSEP"门派:recalle"ZJSEP"回家:huijia"ZJSEP"附近:help ditus"ZJSEP+HIR"充值:paym_zh"ZJSEP+HIG"其"HIG"他:help qt\n"NOR);
	write("\n");
	*/
		user->force_me("mycmds");
	user->force_me("look");
	ob->save();

	// check the user
	UPDATE_D->check_user(user);
	TOP_D->map_user(user);
	if (! silent)
	{
		if (! user->query("registered"))
			color_cat(UNREG_MOTD);
		else
			color_cat(MOTD);

		write("你连线进入了" + LOCAL_MUD_NAME() + "。\n\n");

		if (! user->query("registered") || ! stringp(user->query("character")))
		{
			if (user->is_ghost())
				user->reincarnate();
			user->set("startroom", REGISTER_ROOM);
		} else
		if (! stringp(user->query("born")))
		{
			if (user->is_ghost())
				user->reincarnate();
			user->set("startroom", BORN_ROOM);
		}

		if (user->is_in_prison())
			startroom = user->query_prison();
		else
		if (user->is_ghost())
			startroom = DEATH_ROOM;
		else
		if (! stringp(startroom = user->query("startroom")) ||
		    file_size(startroom + ".c") < 0)
			startroom = START_ROOM;
		if (present("chuwu dai 2", user))
		{
			user->set("startroom", "/d/death/block");
			startroom = "/d/death/block";
		}

		if (! catch(load_object(startroom)))
			user->move(startroom);
		else
		{
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		tell_room(startroom, user->query("name") + "连线进入这个世界。\n", ({user}));
	}
	login_ob = new(LOGIN_OB);
	login_ob->set("id", user->query("id"));
	login_ob->restore();
	if (login_ob->query("registered"))
	{
		if (! intp(login_ob->query("login_times")))
		{	
			write(NOR "\n你是第一次光临" + LOCAL_MUD_NAME() + "。\n");
			login_ob->set("login_times", 1);
		} else
		{
			login_ob->add("login_times", 1);	
			write("\n你上次光临" + LOCAL_MUD_NAME() + "是 " + HIG + ctime(login_ob->query("last_on")) + NOR + " 从 " + HIR +
				login_ob->query("last_from") + NOR + " 连接的。\n");
		}
	}

	destruct(login_ob);

	CHANNEL_D->do_channel(this_object(), "sys",sprintf("%s(%s)由%s连线进入。",user->name(), user->query("id"),
			(ipname = query_ip_number(user)) ? ipname : "未知地点"));
 
    if ( user->query("mud_age") <= 0)
    {
        message("channel:chat",HIR+LOCAL_MUD_NAME()+"："HIY"热烈欢迎新玩家  " +user->query("name")+"("+user->query("id")+")来到"+LOCAL_MUD_NAME()+"！请各位多多关照！"NOR"\n",users());            
        //user->force_me("api_mail");
        user->force_me("mycmds");
        user->force_me("look");
    }
    
	if (wizhood(user) != "(admin)" && EXAMINE_D->query("log_by/" + user->query("id")))
		user->start_log();

	if(FAMILY_D->query_lunjian_leader()==user->query("id"))
	{
		CHANNEL_D->do_channel(this_object(), "chat",sprintf("【武林至尊】%s(%s)连线进入游戏。",user->name(), user->query("id")));
		shout(sprintf(ZJSIZE(22)+HBGRN+HIR" 武林至尊 "ZJSIZE(22)+HBCYN+HIR"%s进入游戏。"NOR"\n",user->name()));
		write(sprintf(ZJSIZE(22)+HBGRN+HIR" 武林至尊 "ZJSIZE(22)+HBCYN+HIR"%s进入游戏。"NOR"\n",user->name()));
	}
	else 

	if(FAMILY_D->query_family_leader(user->query("family/family_name"))==user->query("id"))
		CHANNEL_D->do_channel(this_object(), "chat",sprintf("%s首席弟子%s(%s)连线进入游戏。",
			user->query("family/family_name"), user->name(), user->query("id")));
	NEWS_D->prompt_user(user);
	GIFT_D->check_gift(user);
   
	user->set("shangxian_time",time());
	user->save();
	if ((user->query("qi") < 0 || user->query("jing") < 0) && living(user))
		user->unconcious();
	//by name 千万别删这段，处理未知BUG
	if(user->query("combat_exp")>=2000000000||
	user->query("int")>=9999999||
	user->query("dex")>=9999999||
	user->query("str")>=9999999||
	user->query("con")>=9999999){
	user->set("combat_exp",1);	
	user->set("int",1);
	user->set("dex",1);
	user->set("str",1);
	user->set("con",1);
	}	
}

varargs void reconnect(object ob, object user, int silent)
{

	user->set_temp("link_ob", ob);
	if(ob->query_temp("web_log"))
		user->set_temp("web_log",1);
	else
		user->delete_temp("web_log");
	ob->set_temp("body_ob", user);
	exec(user, ob);

	user->reconnect();
	
	if( !silent && (! wizardp(user) || ! user->query("env/invisible"))) {
		tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
		({user}));
	}
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s[%s]由%s重新连线进入。", user->query("name"),
			user->query("id"), query_ip_number(user)));
			/*
	user->force_me("look");
	write(ZJTTMENU"飞行:help ditu"ZJSEP"客栈:recall"ZJSEP"门派:recalle"ZJSEP"回家:huijia"ZJSEP"附近:help ditus"ZJSEP+HIR"充值:paym_zh"ZJSEP+HIG"其"HIG"他:help qt\n"NOR);
	write("\n");
	*/
	user->force_me("mycmds");
	user->force_me("look");
	//房间丢失
	if(!find_object(file_name(environment(user)))){
	user->move("/d/city/kedian");
	tell_object(user,"你所在房间出现异常，已经将你传送至扬州客栈...\n");
	}	
}

int check_legal_id(string id)
{
	int i;

	id = lower_case(id);

	i = strlen(id);

	if( (i<4||i>20) && (string)SECURITY_D->get_status(id) == "(player)" ) {
		write(ZJTMPSAY"对不起，你的ID长度不符合要求(4-20)。\n");
		return 0;
	}

	if( id[0]<'a' || id[0]>'z' ) {
		write(ZJTMPSAY"对不起，你的ID必须用英文字母开头。\n");
		return 0;
	}
	while(i--)
	{
		if( !((id[i]>='a' && id[i]<='z')||id[i]=='_'||(id[i]>='0' && id[i]<='9')) ) {
			write(ZJTMPSAY"对不起，你的ID只能用英文字母或包含数字及‘_’的组合。\n");
			return 0;
		}
	}

	return 1;
}

int check_legal_name(string name, int maxlen)
{
	int i;

	i = strlen(name);
	
    if ((i < 2) || (i > maxlen))
    {
        write(WHT "对不起，你的中文姓名不能太长或太短。\n" NOR);
        return 0;
    }


	if (! is_chinese(name))
	{
		write(ZJTMPSAY"对不起，请您用「中文」取名字。\n");
		return 0;
	}

	for(i=0;i<sizeof(banned_name);i++)
	{
		if (strsrch(name,banned_name[i]) != -1)
		{
			write(ZJTMPSAY"对不起，名字中不能包含【"+banned_name[i]+"】。\n");
			return 0;
		}
	}

	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	foreach(ob in body) if (getuid(ob) == name) return ob;
	return 0;
}

int set_wizlock(int level)
{
	if (wiz_level(this_player(1)) <= level)
		return 0;

	if (geteuid(previous_object()) != ROOT_UID)
		return 0;

	wiz_lock_level = level;
	return 1;
}

int can_login(int level)
{
	if (level < wiz_lock_level)
		return 0;

	return 1;
}

int howmuch_money(object ob)
{
	int total;
	int total2;
	object gold, silver, coin;

	total = 0;
	total2 = 0;

	gold = present("gold_money",ob);
	silver = present("silver_money",ob);
	coin = present("coin_money",ob);

	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	total2 = (int)ob->query("balance");
	if (!total2 || total2 < 0) {
		ob->set("balance", 0);
	}
	total=total+total2;
	return total;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
