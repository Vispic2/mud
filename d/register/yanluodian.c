
#include <ansi.h>
#include <login.h>
#include <command.h>

inherit ROOM;

int is_chat_room() { return 1; }


int do_washto(string arg);
int do_born(string arg);
int do_tianfu(string arg);
mapping born = ([
	"扬州人氏" : "/d/city/kedian",
	
	"欧阳世家" : ([ "born"      : "西域人氏",
			"surname"   : "欧阳",
			"startroom" : "/d/baituo/dating",
		     ]),
	"关外胡家" : ([ "born"      : "关外人氏",
			"surname"   : "胡",
			"startroom" : "/d/guanwai/xiaowu",
		     ]),
	"段氏皇族" : ([ "born"      : "大理人氏",
			"surname"   : "段",
			"startroom" : "/d/dali/wangfugate",
		     ]),
	"慕容世家" : ([ "born"      : "江南人氏",
			"surname"   : "慕容",
			"startroom" : "/d/yanziwu/cuixia",
		     ]),
		
]);

void create()
{
	int i, k;
	string desc;
	string *position;

	set("short", HIR "阎罗殿" NOR);
	set("long", @LONG
这里阴深恐怖，让人感觉到一阵阵的寒意，两旁列着牛头马面，冥
府狱卒，各个威严肃穆。十殿阎罗，尽皆在此，地藏王坐在大堂之上，
不怒自威。
    大殿角落有一个石头砌成的池子，其中水清澈却不见底，不知道它
究竟有多深。
    旁边有几个牌子，你也许应该仔细看看。
LONG );
	set("exits", ([
//	"down" : __DIR__"entry",
	]));
	set("no_fight", 1);
	set("item_desc", ([ 
	    "指定洗点" : "投胎之前可以先洗一下属性点，直到自己满意：\n"ZJOBACTS"指定洗点:washto\n",		
	    "新手洗点" : "投胎前选择你想发展的路线。\n"
		ZJOBACTS2+ZJMENUF(2,2,8,30)"臂力流(降龙十八掌):washto 30 13 24 13"ZJSEP"悟性流(独孤九剑):washto 13 30 24 13"ZJSEP"根骨流(黯然销魂掌):washto 13 24 30 13"ZJSEP"身法流(辟邪剑法):washto 13 13 24 30"ZJSEP"\n",
	    "转生" : "投胎乃人生大事，切记不可草率！"ZJBR"请选择你的转生地点：\n"ZJOBACTS,
		"天赋" : "投胎之前可以先洗一下请刷出你想要的天赋！\n"ZJOBACTS"刷新:tianfu msx\n",			
		"天性" : "投胎前选择你的天性。\n"
		ZJOBACTS2+ZJMENUF(2,2,8,30)"阴险狡诈:tianxing y"ZJSEP"光明磊落:tianxing g"ZJSEP"狡黠多变:tianxing j"ZJSEP"心狠手辣:tianxing x"ZJSEP"\n",
		]));
	set("objects", ([
		__DIR__"npc/dizangwang" : 1,
	]));
	set("no_say", "阎罗殿内阴森恐怖，你哪里敢乱说话？\n");
	desc = query("item_desc/转生");
	position = keys(born);
	for (i = 0, k = 1; i < sizeof(position); i++){
		if (! stringp(born[position[i]]))
			continue;
		desc += sprintf("%2d. " HIW "%s" NOR ":born %s$zj#", k++, position[i], position[i]);
	}
	for (i = 0; i < sizeof(position); i++)
	{
		if (! mapp(born[position[i]]))
			continue;
		desc += sprintf("%2d. " HIC "%s" NOR ":born %s$zj#", k++, position[i], position[i]);
	}
	set("item_desc/转生", desc+"\n");

	setup();
}
void init()
{

	add_action("do_washto", "washto");
	add_action("do_born", "born");
	add_action("do_tianfu", "tianfu");
	add_action("do_tianxing", "tianxing");
//	add_action("do_email", "email");
	add_action("do_yanzheng", "yanzheng");
}
int do_yanzheng(string arg)
{
object me=this_player();
	if(!arg){	
	return notify_fail(INPUTTXT("请输入验证码(验证码请前往QQ邮箱查看)：","yanzheng $txt#")+"\n");	
	}
	if(me->query("new_code")==arg){
	me->set("new_code_xiaojian",1);
	write("验证码验证成功！\n");
	return 1;
	}else{
	write("验证码错误！\n");
	return 1;
	}
}
int do_email(string arg)
{
    string code=""+random(9)+""+random(9)+""+random(9)+""+random(9)+"";
	object me=this_player();	
	
	
	
	if(me->query("new_code_time")>time())
	return notify_fail("验证码已发送至你指定的QQ邮箱，如需重新发送请在"+(me->query("new_code_time")-time())+"秒后再尝试重新发送！\n");
	if(!arg){	
	return notify_fail(INPUTTXT("请务必输入正确的QQ邮箱(没有的话去注册)，稍后会给你发一封邮件内涵注册验证码","email $txt#")+"\n");	
	}
// 	if(is_az(arg[0..0])){
// write(HIR"警告：请使用数字邮箱，不能使用英文邮箱，你的ID已被记录！\n"NOR);
// me->add("mail-bug",1);
// return 1;
// }
	//write("设置邮箱成功，你设置的邮箱是："+arg+"，注册验证码已发送到指定QQ邮箱！\n");
	me->set("new_code",code);
	
	if(strsrch(arg,"@qq.com")==-1)
    me->set("data_email",arg+"@qq.com");
    else
	me->set("data_email",arg);
	
	me->set("new_code_time",time()+60);
    me->force_me("api_mail");
    return 1;
}
int do_tianfu(string arg)
{
	object me = this_player();
	if (arg=="msx"){
		UPDATE_D->born_player(me);
		me->set_temp("tianfu", 1);	
		return 1;
	}
	else{
  		write(ZJOBLONG"选择错误，请重新选择！\n",me);
		return 1;
	}
}

int do_tianxing(string arg)
{
	object room, me=this_player();

	if (arg == "j")
	{
		message_vision(HIY"你选择了天性为：狡黠多变。"NOR"\n", me);	    
	    me->set("character", "狡黠多变");
	    me->set("tianxings",1);
	    return 1;
	}
	if (arg == "g")
	{
		message_vision(HIY"你选择了天性为：光明磊落。"NOR"\n", me);	    
	    me->set("character", "光明磊落");
	    me->set("tianxings",1);
	    return 1;
	}
	if (arg == "y")
	{
			message_vision(HIY"你选择了天性为：阴险狡诈。"NOR"\n", me);	    
	    me->set("character", "阴险奸诈");
	    me->set("tianxings",1);
	    return 1;
	}
	if (arg == "x")
	{
		message_vision(HIY"你选择了天性为：心狠手辣。"NOR"\n", me);	    
	    me->set("character", "心狠手辣");
	    me->set("tianxings",1);
	    return 1;
	}

	return 1;
}

int do_washto(string arg)
{
	int i,n;
	int points;
	int tmpstr, tmpint, tmpcon, tmpdex;
	object me;
	mapping my;

	if (! objectp(me = this_player()) || ! userp(me))
		return 1;
	if (!arg||!stringp(arg))
	{
		tell_object(me,INPUTTXT("请输入你想分配的方案：$br#"
						"按照臂力、悟性、根骨、身法次序输入4个用"
						"空格分开的数，注意每个数不能低于13或大于30，4个数之和必须为80。","washto $txt#")+"\n");
		return 1;
	}

	if(sscanf(arg, "%d %d %d %d",tmpstr,tmpint,tmpcon,tmpdex)  != 4)
	{
		tell_object(me,INPUTTXT("输入格式不对，请重新输入你想分配的方案：$br#"
						"按照臂力、悟性、根骨、身法次序输入4个用"
						"空格分开的数，注意每个数不能低于13或大于30，4个数之和必须为80。","washto $txt#")+"\n");
		return 1;
	}

	if(tmpstr<13||tmpint<13||tmpcon<13||tmpdex<13||tmpstr>30||tmpint>30||tmpcon>30||tmpdex>30||(tmpstr+tmpint+tmpcon+tmpdex)!=80)
	{
		tell_object(me,INPUTTXT("输入格式不对，请重新输入你想分配的方案：$br#"
						"按照臂力、悟性、根骨、身法次序输入4个用"
						"空格分开的数，注意每个数不能低于13或大于30，4个数之和必须为80。","washto $txt#")+"\n");
		return 1;
	}

	write(HIC "你跳入忘忧池，顿时被一股激流卷了进去。"NOR"\n", me);

	my = me->query_entire_dbase();

	my["str"] = tmpstr;
	my["int"] = tmpint;
	my["con"] = tmpcon;
	my["dex"] = tmpdex;
	my["kar"] = 10 + random(20);
	my["per"] = 10 + random(20);

	write(HIC "“啪”的一声，你被湿漉漉的抛了出来。"NOR"\n", me);
	write(sprintf(HIY "\n你这次获得的四项先天天赋分别是：\n"
			  "膂力：【 " HIG "%d" HIY " 】 "
			  "悟性：【 " HIG "%d" HIY " 】\n"
			  "根骨：【 " HIG "%d" HIY " 】 "
			  "身法：【 " HIG "%d" HIY " 】\n"
			  "如果你满意，就去转生吧！"NOR"\n",
		      tmpstr, tmpint, tmpcon, tmpdex));
	me->set_temp("washed", 1);

	return 1;
}

int do_born(string arg)
{
	object me;
	object obj;
	object item;
	mixed dest;
	string new_name;
	string msg,str;

	if (! objectp(me = this_player()) ||  ! userp(me))
		return 1;

	//if (! me->query("new_code_xiaojian"))
	 //   return notify_fail(ZJOBLONG"请先设置QQ邮箱，然后请前往QQ邮箱查看注册验证码，得到验证码后游戏内输入指令："+HIC+ZJSIZE(24)+ZJURL("cmds:yanzheng")+"yanzheng"+NOR+"进行验证！\n");
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    

	if (! me->query_temp("washed"))
		return notify_fail(ZJOBLONG"你先选择好属性点再投胎也不迟啊！\n");
   if (! me->query_temp("tianfu"))
		return notify_fail(ZJOBLONG"你先选择好天赋再投胎也不迟啊！\n");
	if (! me->query("character"))
	    return notify_fail(ZJOBLONG"你先选择好天性在投胎也不迟啊！\n");
	if (arg && arg[0] < 160)
		return notify_fail("你必须输入中文地名，比如born 扬州人氏，或者是born 欧阳世家以避免投错胎。\n");
	new_name = 0;
	if (arg) sscanf(arg, "%s %s", arg, new_name);
	if (! arg || (! stringp(dest = born[arg]) && ! mapp(dest))){
		message_vision("牛头恶狠狠的对$N说：你要干什么！投胎去哪里？\n", me);
		return 1;
	}

	if (mapp(dest) && stringp(dest["notice"]))
		return notify_fail(dest["notice"]);

	if (stringp(dest))
	{
		if (! objectp(obj = find_object(dest)))
			obj = load_object(dest);
		me->set("startroom", dest);
		me->set("born", arg);
		me->set("born_family", "没有");
	} else
	{
		if (! objectp(obj = find_object(dest["startroom"])))
			obj = load_object(dest["startroom"]);

		if (new_name)
		{
			if (! sscanf(new_name, dest["surname"] + "%*s"))
				new_name = dest["surname"] + new_name;

			if (strlen(new_name) > 4)
				return notify_fail("你的名字太长了。\n");

			if (strlen(new_name) < 2)
				return notify_fail("你的名字太短了。\n");

			if (! is_chinese(new_name))
				return notify_fail("请你用中文起名字。\n");
		}

		if (me->query("surname") != dest["surname"])
		{
			// 名字需要变化
			NAME_D->remove_name(me->name(1), me->query("id"));
			if (! new_name) new_name = dest["surname"] + me->query("purename");
			if (stringp(msg = NAME_D->invalid_new_name(new_name)))
			{
				write(msg);
				write("你可以考虑在投入世家的时候重新选择名字：born <世家> <名字>\n");
				return 1;
			}
			me->set("surname", dest["surname"]);
			me->set("purename", new_name[strlen(dest["surname"])..<1]);
			me->set_name();
			NAME_D->map_name(me->name(1), me->query("id"));
		}

		me->set("startroom", dest["startroom"]);
		me->set("born", dest["born"]);
		me->set("born_family", arg);

		if (mapp(dest["family"]))
		{
			me->set("family", dest["family"]);
			me->assign_apprentice(dest["family"]["title"], 0);
		}
	}
	if (! objectp(obj))
	{
		message_vision("牛头一呆，搔搔头说：怎么好像有问题...\n", me);
		return 1;
	}
		if (! me->query("registered"))
	{
		me->set("registered",1);
	}
	
	message_vision("牛头飞起一脚，将$N踢了出去。\n", me);
	me->move(obj);
	me->set("mud_age", 0);
	me->set("age", 14);
	me->save();
	message_vision("$N揉揉眼睛，迷惘的望着这个陌生的世界。\n", me);
	
	//一个邮箱只能注册一个号
	write_file(__DIR__+"regmail.txt",me->query("data_email")+"\n");
	return 1;
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
