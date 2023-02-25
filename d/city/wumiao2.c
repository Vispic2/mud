// Room: /city/wumiao2.c

#include <room.h>

inherit ROOM;
string look_shu();
int ask_character(string arg);

int ask_washto(string arg);
void create()
{
	set("short", "武庙二楼");
	set("long", @LONG
这里是岳王庙的二楼，这里供的是岳飞的长子岳云和义子张宪，两尊塑像
金盔银铠，英气勃勃。
LONG );

	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_sleep_room", 1);
	set("exits", ([
		"south" : __DIR__"wumiao",
	]));

		set("action_list", ([
		"更换性格" : "xingge",
		"重新洗点":"xidian",
	]));
	setup();
}
void init()
{
    add_action("do_xingge", "xingge");
    add_action("do_effect","effect");
	add_action("do_uses","xidian");
}
int do_xingge(string arg)
{
object me = this_player();
tell_object(me,ZJOBLONG"请选择性格，第一次免费，之后每次扣费200元宝：\n"
		ZJOBACTS2+ZJMENUF(2,2,6,30)+
        "狡黠多变:effect 狡黠多变"ZJSEP
		"光明磊落:effect 光明磊落"ZJSEP
		"阴险奸诈:effect 阴险奸诈"ZJSEP
		"心狠手辣:effect 心狠手辣\n");
	return 1;
}


int do_effect(string arg)
{
	object me = this_player();
	if (me->query("xixingge")&&me->query("yuanbao") < 200)
	{
	tell_object(me,HIR"你的元宝数量不够！！"NOR"\n");		
		return 1;
	}
	if (me->query("character")==arg)
		{
	tell_object(me,HIR"请选择与你现在性格不一样的！"NOR"\n");		
		return 1;
	}
	if (arg=="狡黠多变") 
	 me->set("character", "狡黠多变");
	else
	 if (arg=="光明磊落") 
	   me->set("character", "光明磊落");

	else 
	if (arg=="心狠手辣") 
	 me->set("character", "心狠手辣");

	else 
	if (arg=="阴险奸诈") 
	me->set("character", "阴险奸诈");
		else 	
		{
	tell_object(me,HIR"\n敬请期待新性格！"NOR"\n");		
	return 1;
		}
	  tell_object(me,"性格转换成功!\n");
	  if (me->query("xixingge"))
	  {	  me->add("yuanbao",-200);
    tell_object(me,"200元宝已扣除!\n");
	  }
	  me->set("xixingge",1);
    return 1;
}

varargs int do_uses(string arg)
{
	mapping shuxing=([]), my;
	string *sname, str, line;
	int i;
	int max_sx, max_sx2;
	int tmpstr, tmpint, tmpcon, tmpdex;
	object me = this_player();
		
	if (!me->query("xidian")) {
		tell_object(me, "你当前可以免费试用一次。\n");
	}
	if (me->query("xidian") && me->query("yuanbao") < 200)
	{
		return notify_fail("你的元宝不够。\n");
	}
	if(!arg) {
		str = ZJOBLONG+ "你真的想重新分配先天属性吗？请慎重选择，一旦洗点造成严重后果概不负责，第一次免费,后续收费200元宝！\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		
		str += sprintf("确定:xidian -yes" + ZJSEP);
		str += sprintf("取消:look");
		tell_object(me, str + "\n");
	 return 1;
	} else 
	if(arg == "-yes") {
	max_sx = me->query("con") + me->query("dex")+me->query("int")+me->query("str");
	write(INPUTTXT(HIR"注：值必须在13-80之间"ZJBR"总和不能超过你现有的先天"+max_sx+"点。"+NOR+ZJBR+HIW+"(臂力 悟性 根骨 身法)"+NOR+ZJBR+HIY+"(例：20 20 20 20，中间以空格隔开)"+NOR+ZJBR+"请输入四项先天点数：","xidian $txt#")+"\n");
	} else if(sscanf(arg, "-yes %d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) == 4) {
	if (tmpstr < 13 || tmpstr >80|| tmpint < 13 || tmpint >80|| tmpcon < 13 || tmpcon >80|| tmpdex < 13 || tmpdex >80) {
	write(HIR"你有一项输入不在(13-80)范围之内。"NOR"\n");
	return 1;
    }
	my = me->query_entire_dbase();
	max_sx = (my["con"] + my["dex"]+my["int"]+my["str"]);
	if (tmpstr+ tmpint+ tmpcon+ tmpdex != max_sx) {
	write(HIR"你想分配的先天点数不等于目前的总先天属性。"NOR"\n");
	return 1;
}

		line = sprintf("str(%d)int(%d)con(%d)dex(%d)", tmpstr, tmpint, tmpcon, tmpdex);		
		max_sx2 = tmpstr+ tmpint+ tmpcon+ tmpdex;	
		my["str"]= tmpstr;
		my["int"]= tmpint;
		my["con"]= tmpcon;
		my["dex"]= tmpdex;
		
	    message_vision(HIY"$N在"+short()+"重塑了身体！"NOR"\n", me);
		tell_object(me, HIY"身体重塑成功，请再操作升级一次天赋！"NOR"\n");		
		UPDATE_D->check_skill(me);
		me->save();
	    if (me->query("xidian"))
    	me->add("yuanbao",-200);
		me->set("xidian", 1);
	   } else 
	   if(sscanf(arg, "%d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) == 4) {		
		str = ZJOBLONG+ HIC"你的设置："HIG"臂力("+tmpstr+") 悟性("+tmpint+") 根骨("+tmpcon+") 身法("+tmpdex+")"NOR+ZJBR"真的想重新分配先天属性吗？"ZJBR+"请慎重选择！最后一次提醒！一旦洗点，将不可恢复，造成严重后果概不负责！"NOR"\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);		
		str += sprintf("确定:xidian -yes " +tmpstr+" "+ tmpint+" "+ tmpcon+" "+ tmpdex+ ZJSEP);
		str += sprintf("取消:look");
		tell_object(me, str + "\n");
	    } else 
		me->force_me("xidian");
	return 1;
}


int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
