
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIY"洗点丹"NOR, ({"xidian dan", "dan"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("base_unit", "张");
		set("unit", "张");
		set("base_value", 1);
		set("base_weight", 1);
		set("value", 1);
		set("channel_id","系统");
		set("no_sell",1);
		set("no_steal",1);
		set("no_shop", 1);
		set("long","这是一"+query("base_unit") +name()+"，可以重新分配你的先天属性点"ZJBR+
							HIR"只能使用一次，使用后一旦有不符合先天的技能将直接被删除，慎用！"ZJURL("cmds:usesxidian")ZJSIZE(20)"使用"NOR"使用指令：usesxidian"NOR"\n" );
		set("yuanbao", 1000);
	}
	set("action_list", ([
		"使用" : "usesxidian",
	]));
	set_amount(1);
	setup();
}
void init()
{
	add_action("do_uses", "usesxidian");
}

varargs int do_uses(string arg)
{
	mapping shuxing=([]), my;
	string *sname, str, line;
	int i;
	int max_sx, max_sx2;
	int tmpstr, tmpint, tmpcon, tmpdex;
	object me = this_player();
		
	if (me->query("usesxidian", 1)) {
		tell_object(me, "你已经使用过一次洗点丹了，不可以再使用。\n");
		return 1;
	}
	if(!arg) {
		str = ZJOBLONG+ "你真的想重新分配先天属性吗？"ZJBR+HIR+ZJSIZE(24)
										+"请慎重选择！"NOR"\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		
		str += sprintf("确定:usesxidian -yes" + ZJSEP);
		str += sprintf("取消: ");
		tell_object(me, str + "\n");
		return 1;
	} else if(arg == "-yes") {
		max_sx = (me->query("con") + me->query("dex")+me->query("int")+me->query("str"))
					-(me->query("gift/shenliwan") + me->query("gift/xiandan")+me->query("gift/unknowdan")+me->query("gift/lighting") +me->query("gift/xisuidan"))
					-(me->query("level")/10-me->query("tianfu_point"));
		
		write(INPUTTXT(HIR"注：值必须在13-100之间"ZJBR"总和不能超过你现有的先天"+max_sx+"点。"
											+NOR+ZJBR+HIW+"(臂力 悟性 根骨 身法)"
											+NOR+ZJBR+HIY+"(例：20 20 20 20，中间以空格隔开)"+NOR+
												ZJBR+"请输入四项先天点数：","usesxidian $txt#")+"\n");
	} else if(sscanf(arg, "-yes %d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) == 4) {
		if (tmpstr < 13 || tmpstr >100
			|| tmpint < 13 || tmpint >100
			|| tmpcon < 13 || tmpcon >100
			|| tmpdex < 13 || tmpdex >100) {
				write(HIR"你有一项输入不在(13-100)范围之内。"NOR"\n");
				return 1;
			}
		my = me->query_entire_dbase();
		max_sx = (my["con"] + my["dex"]+my["int"]+my["str"])
					-(me->query("gift/shenliwan") + me->query("gift/xiandan")+me->query("gift/unknowdan")+me->query("gift/lighting") +me->query("gift/xisuidan"))
					-(my["level"]/10-my["tianfu_point"]);
			
		if (tmpstr+ tmpint+ tmpcon+ tmpdex != max_sx) {
			write(HIR"你想分配的先天点数不等于目前的总先天属性。"NOR"\n");
			return 1;
		}
		
		line = sprintf("str(%d)int(%d)con(%d)dex(%d)", tmpstr, tmpint, tmpcon, tmpdex);
		
		tmpstr += me->query("gift/shenliwan");
		tmpint += me->query("gift/xiandan");
		tmpcon += me->query("gift/unknowdan")+me->query("gift/lighting");
		tmpdex += me->query("gift/xisuidan");
		max_sx2 = tmpstr+ tmpint+ tmpcon+ tmpdex;
		
		my["str"]= tmpstr;
		my["int"]= tmpint;
		my["con"]= tmpcon;
		my["dex"]= tmpdex;
		my["tianfu_point"] = my["level"] /10;
		
		CHANNEL_D->do_channel( this_object(), "chat", "据说"+me->name()+"用洗点丹重塑了身体！");
		message_vision(HIY"$N使用了一"+query("unit") + name() + HIY "，重塑了身体！"NOR"\n", me);
		tell_object(me, HIY"身体重塑成功，请再操作升级一次天赋！"NOR"\n");
		
		//检查分配先天后的技能是否符合要求，不符合的删除
		UPDATE_D->check_skill(me);
		me->set("usesxidian", time());
		me->save();
		//log_files("/cmds/xidian", sprintf("%s  洗点=%s  总计=str(%d)int(%d)con(%d)dex(%d) 总共(%d/%d点) 洗点时间：%s\n", 
											//me->name()+"("+my["id"]+")", line, tmpstr, tmpint, tmpcon, tmpdex, max_sx, max_sx2, CHINESE_D->chinese_date(time(), 2)));
		add_amount(-1);
	} else if(sscanf(arg, "%d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) == 4) {
		
		str = ZJOBLONG+ HIC"你的设置："HIG"臂力("+tmpstr+") 悟性("+tmpint+") 根骨("+tmpcon+") 身法("+tmpdex+")"NOR
				+ZJBR"真的想重新分配先天属性吗？"ZJBR+HIR+ZJSIZE(24)
										+"请慎重选择！最后一次提醒！一旦洗点，将不可恢复！"NOR"\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		
		str += sprintf("确定:usesxidian -yes " +tmpstr+" "+ tmpint+" "+ tmpcon+" "+ tmpdex+ ZJSEP);
		str += sprintf("取消: ");
		tell_object(me, str + "\n");
	} else 
		me->force_me("usesxidian");
	return 1;
}	 

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
