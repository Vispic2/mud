inherit ITEM;
#include <ansi.h>

// 如果字符串被设置成这个值，表示输入的字符串具有非法的格式
#define	ILLEGAL_STR	"."
// 在convert时看看要不要去掉彩色
#define	NOCOLOR		1
#define COLORABLE	0

// 判断是否是合法的汉字，可带中文标点符号
private int legal_chinese(string str)
{
return is_chinese(str);
}

// 转换字符串中的颜色标志
protected string converts(string arg, int max_len, int no_color)
{
	int i;

	// 去除字符串中的空格，引号，避免被别人利用做破坏
	arg = replace_string(arg, " ", ""); 
	arg = replace_string(arg, "\"", "'");

	for (i = 0; i < strlen(arg) - 1; i++)
	{
		if (arg[i] == '\\' && arg[i + 1] != 'n')
		{
			write("字符'\\'后面只能跟随n字符表示回车！\n");
			return ILLEGAL_STR;
		}
	}

	arg = replace_string(arg, ",", "，");
	arg = replace_string(arg, ":", "：");
	arg = replace_string(arg, "?", "？");

	if (no_color)
	{
		arg = replace_string(arg, "$BLK$", "");
		arg = replace_string(arg, "$RED$", "");
		arg = replace_string(arg, "$GRN$", "");
		arg = replace_string(arg, "$YEL$", "");
		arg = replace_string(arg, "$BLU$", "");
		arg = replace_string(arg, "$MAG$", "");
		arg = replace_string(arg, "$CYN$", "");
		arg = replace_string(arg, "$WHT$", "");
		arg = replace_string(arg, "$HIR$", "");
		arg = replace_string(arg, "$HIG$", "");
		arg = replace_string(arg, "$HIY$", "");
		arg = replace_string(arg, "$HIB$", "");
		arg = replace_string(arg, "$HIM$", "");
		arg = replace_string(arg, "$HIC$", "");
		arg = replace_string(arg, "$HIW$", "");
		arg = replace_string(arg, "$NOR$", "");
	} else
	{
		arg = replace_string(arg, "$BLK$", BLK);
		arg = replace_string(arg, "$RED$", RED);
		arg = replace_string(arg, "$GRN$", GRN);
		arg = replace_string(arg, "$YEL$", YEL);
		arg = replace_string(arg, "$BLU$", BLU);
		arg = replace_string(arg, "$MAG$", MAG);
		arg = replace_string(arg, "$CYN$", CYN);
		arg = replace_string(arg, "$WHT$", WHT);
		arg = replace_string(arg, "$HIR$", HIR);
		arg = replace_string(arg, "$HIG$", HIG);
		arg = replace_string(arg, "$HIY$", HIY);
		arg = replace_string(arg, "$HIB$", HIB);
		arg = replace_string(arg, "$HIM$", HIM);
		arg = replace_string(arg, "$HIC$", HIC);
		arg = replace_string(arg, "$HIW$", HIW);
		arg = replace_string(arg, "$NOR$", NOR);
		if (strlen(arg) < strlen(NOR) ||
		    arg[strlen(arg) - strlen(NOR)..<1] != NOR)
		{
			// append NOR at tail
			arg += NOR;
		}
	}
	if (strlen(arg) > max_len + 30 ||
	    strlen(filter_color(arg)) > max_len)
	{
		write("对不起，这个字符串太长了，请不要输入超过" + chinese_number(max_len) +
		      "个字符长的字符串。\n");
		// 表示非法的输入
		return ILLEGAL_STR;
	}
	return arg;
}

void create()
{
	set_name(HIR"装备修改卡"NOR, ({"zbxg card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1000000);
		set("yuanbao", 120);
		set("unit", "张");
		set("long","这是一张装备修改卡，"ZJURL("cmds:zbxg")ZJSIZE(18)+HIG+"使用"NOR"它可以修改打造装备的名称、描述、穿上描述、脱下描述，开光的装备只能开光者本人才能修改。\n");
        //set("no_sell",1);
		//set("no_drop",1);
		//set("no_shop",1);
	}
}

void init()
{
    if (environment()==this_player())
    	add_action("on_used","zbxg");
}

int chkob(object ob){
	if(ob->is_item_make()){
		return 1;
	}
	return 0;
}

int on_used(string arg)
{

	object me=this_player();
	object ob,*obs;	
	string id,ms,ms2,type,file,list,str,txt1,txt2,pops,oldname,oldlong,chk,tname;
	int i;
	mapping types = (["head":"头","neck":"脖子","cloth":"衣服","armor":"装甲","surcoat":"外套","waist":"腰部","wrists":"手腕","shield":"盾牌","hands":"手掌","finger":"手指","boots":"鞋","pants":"裤子","leg":"腿","sword":"剑","pin":"针","axe":"斧","dagger":"匕首","staff":"杖","club":"棍","blade":"刀","hammer":"锤","whip":"鞭","xsword":"萧",]);
	
	if(!arg){
		obs = all_inventory(me);
		obs = filter_array(obs,(: chkob :));
		
		if(sizeof(obs)){
			pops = ZJOBLONG"请选择要修改装备：\n" + ZJOBACTS2+ZJMENUF(2,2,8,30);
			
			for(i = 0; i < sizeof(obs); i++){
				
				if(! stringp(tname = obs[i]->query("armor_type"))){
					tname = obs[i]->query("skill_type");
				}

				if(i == sizeof(obs)-1){
					pops += obs[i]->query("name")+" ["+types[tname]+"]:zbxg " + obs[i]->query("id") + "\n";
				}else{
					pops += obs[i]->query("name")+" ["+types[tname]+"]:zbxg " + obs[i]->query("id") + ZJSEP;
				}
			}
			write(pops);
		}else{
			write("你的包裹里没有可以修改的装备。\n");
		}

		return 1;
	}
	
	if(sscanf(arg,"%s %s %s",id,type,ms) == 3){
		if (! objectp(ob = present(id, me))){
			return notify_fail("你身上没有这种东西。\n");
		}
		if (ob->query("equipped")){
			return notify_fail("你先解除" + ob->name() + "的装备再说！\n");
		}
		if(ob->query("kaiguang") && ob->query("kaiguang") != me->query("id")){
			return notify_fail("开光后的装备必须本人才能修改。\n");
		}		
		if(!ob->is_item_make()){
			return notify_fail("只有自制装备才能修改。\n");
		}
		
		file = base_name(ob);
		list = BUILD_D->get_file_code(ob);		
		
		if(type == "mc"){
			if ((ms = converts(ms, 14, COLORABLE)) == ILLEGAL_STR)
			{
				tell_object(me,"新名称格式不对！\n");
				return 1;
			}
			if (! legal_chinese(filter_color(ms)))
			{
				tell_object(me,"不会写中文字怎么的？\n");
				return 1;
			}
			if (strlen(filter_color(ms)) < 2)
			{
				tell_object(me,"我说你这也太短了吧，至少两个汉字！\n");
				return 1;
			}
			
			oldname = ob->query("name");
			str = replace_string(list,oldname,ms);

			ob->set("name",ms);
			ob->set_name(ms,({ ob->query("id") }));

			BUILD_D->build_file(me,file+".c",str);
			
			write("修改成功！新的名称是：\n"+ms+"\n");
			destruct(this_object());
			
		}else if(type == "cs"){
			if ((ms = converts(ms, 200, COLORABLE)) == ILLEGAL_STR)
			{
				tell_object(me,"新名称格式不对！\n");
				return 1;
			}
			
			chk = filter_color(ms);
			if (strlen(chk) >= 2 && chk[0..1] == "你" || strsrch(chk, "\\n你") != -1)
			{
				return notify_fail("对不起，描述不能以“你”字打头。\n");
			}

			chk = replace_string(chk, " ", "");
			chk = replace_string(chk, "\\n", "");
			chk = replace_string(chk, "$N", "");
			chk = replace_string(chk, "$n", "");
			chk = replace_string(chk, "，", "");
	chk = replace_string(chk, "。", "");
	chk = replace_string(chk, ",", "");
	chk = replace_string(chk, ".", "");
	chk = replace_string(chk, "？", "");
	chk = replace_string(chk, "?", "");
	chk = replace_string(chk, "！", "");
	chk = replace_string(chk, "!", "");
	chk = replace_string(chk, "$n", "");
	chk = replace_string(chk, "：", "");
	chk = replace_string(chk, ":", "");
	chk = replace_string(chk, "【", "");
	chk = replace_string(chk, "】", "");
	chk = replace_string(chk, "[", "");
	chk = replace_string(chk, "]", "");
	chk = replace_string(chk, "(", "");
	chk = replace_string(chk, ")", "");
	chk = replace_string(chk, "+", "");
	chk = replace_string(chk, "-", "");
	chk = replace_string(chk, "_", "");
	chk = replace_string(chk, "|", "");
	chk = replace_string(chk, "=", "");
	chk = replace_string(chk, "<", "");
	chk = replace_string(chk, ">", "");
	chk = replace_string(chk, "\"", "");
			if (! legal_chinese(chk))
			{
				return notify_fail("对不起，描述必须使用汉字和系统规定可以使用的代表符号。\n");
			}

			if (strlen(chk) < 2)
			{
				tell_object(me,"我说你这也太短了吧，至少两个汉字！\n");
				return 1;
			}
			
			if(sscanf(list,"%sset(\"wear_msg\"%*s);\n%s",txt1,txt2)==3)
			{
				str = txt1 + "set(\"wear_msg\", \""+ms+"\\n\");\n" + txt2;

				ob->set("wear_msg",replace_string(ms, "\\n", "\n")+"\n");
				BUILD_D->build_file(me,file+".c",str);

				write("修改成功！新的穿上描述是：\n"+ms+"\n");
				destruct(this_object());
			}else if(sscanf(list,"%sset(\"wield_msg\"%*s);\n%s",txt1,txt2)==3){
				str = txt1 + "set(\"wield_msg\", \""+ms+"\\n\");\n" + txt2;

				ob->set("wield_msg",replace_string(ms, "\\n", "\n")+"\n");
				BUILD_D->build_file(me,file+".c",str);

				write("修改成功！新的穿上描述是：\n"+ms+"\n");
				destruct(this_object());				
			}
		}else if(type == "tx"){
			if ((ms = converts(ms, 200, COLORABLE)) == ILLEGAL_STR)
			{
				tell_object(me,"新名称格式不对！\n");
				return 1;
			}
			
			chk = filter_color(ms);
			if (strlen(chk) >= 2 && chk[0..1] == "你" || strsrch(chk, "\\n你") != -1)
			{
				return notify_fail("对不起，描述不能以“你”字打头。\n");
			}

			chk = replace_string(chk, " ", "");
			chk = replace_string(chk, "\\n", "");
			chk = replace_string(chk, "$N", "");
			chk = replace_string(chk, "$n", "");
			chk = replace_string(chk, "，", "");
	chk = replace_string(chk, "。", "");
	chk = replace_string(chk, ",", "");
	chk = replace_string(chk, ".", "");
	chk = replace_string(chk, "？", "");
	chk = replace_string(chk, "?", "");
	chk = replace_string(chk, "！", "");
	chk = replace_string(chk, "!", "");
	chk = replace_string(chk, "$n", "");
	chk = replace_string(chk, "：", "");
	chk = replace_string(chk, ":", "");
	chk = replace_string(chk, "【", "");
	chk = replace_string(chk, "】", "");
	chk = replace_string(chk, "[", "");
	chk = replace_string(chk, "]", "");
	chk = replace_string(chk, "(", "");
	chk = replace_string(chk, ")", "");
	chk = replace_string(chk, "+", "");
	chk = replace_string(chk, "-", "");
	chk = replace_string(chk, "_", "");
	chk = replace_string(chk, "|", "");
	chk = replace_string(chk, "=", "");
	chk = replace_string(chk, "<", "");
	chk = replace_string(chk, ">", "");
	chk = replace_string(chk, "\"", "");
			if (! legal_chinese(chk))
			{
				return notify_fail("对不起，描述必须使用汉字和系统规定可以使用的代表符号。\n");
			}

			if (strlen(chk) < 2)
			{
				tell_object(me,"我说你这也太短了吧，至少两个汉字！\n");
				return 1;
			}			
			
			if(sscanf(list,"%sset(\"remove_msg\"%*s);\n%s",txt1,txt2)==3)
			{
				str = txt1 + "set(\"remove_msg\", \""+ms+"\\n\");\n" + txt2;
				ob->set("remove_msg",replace_string(ms, "\\n", "\n")+"\n");
				BUILD_D->build_file(me,file+".c",str);

				write("修改成功！新的脱下描述是：\n"+ms+"\n");
				destruct(this_object());
			}else if(sscanf(list,"%sset(\"unwield_msg\"%*s);\n%s",txt1,txt2)==3){
				str = txt1 + "set(\"unwield_msg\", \""+ms+"\\n\");\n" + txt2;
				ob->set("unwield_msg",replace_string(ms, "\\n", "\n")+"\n");
				BUILD_D->build_file(me,file+".c",str);

				write("修改成功！新的脱下描述是：\n"+ms+"\n");
				destruct(this_object());
			}			
		}else if(type == "ms"){
			
			if(sscanf(list,"%*s炼制而成的%*s。%s刻着:炼器宗师%*s",txt1)==4)
			{
				// ILLEGAL_STR = "." 表示非法的输入
				if ((ms = converts(ms, 200, COLORABLE)) == ILLEGAL_STR)
				{
					tell_object(me,"新名称格式不对！\n");
					return 1;
				}
				
				chk = filter_color(ms);
				if (strlen(chk) >= 2 && chk[0..1] == "你" || strsrch(chk, "\\n你") != -1)
				{
					return notify_fail("对不起，描述不能以“你”字打头。\n");
				}
				
				chk = replace_string(chk, " ", "");
				chk = replace_string(chk, "\\n", "");
				
				if (! legal_chinese(chk))
				{
					tell_object(me,"不会写中文字怎么的？\n");
					return 1;
				}
				if (strlen(chk) < 2)
				{
					tell_object(me,"我说你这也太短了吧，至少两个汉字！\n");
					return 1;
				}
				
				txt1 = replace_string(txt1, "\\n", "\n");
				ms = replace_string(ms, "\\n", "\n");
				
				list = replace_string(list,txt1,"\n"+ms+"\n上面");
				BUILD_D->build_file(me,file+".c",list);
				
				oldlong = ob->query("long");				
				
				ob->set("long",replace_string(oldlong,txt1,"\n"+ms+"\n上面"));

				write("修改成功！新的描述是：\n"+ms+"\n");
				destruct(this_object());
			}			
		}	
	
		return 1;
	}
	
	if(sscanf(arg,"%s %s",id,type) == 2){
		if (! objectp(ob = present(id, me))){
			return notify_fail("你身上没有这种东西。\n");
		}
		if (ob->query("equipped")){
			return notify_fail("你先解除" + ob->name() + "的装备再说！\n");
		}
		if(ob->query("kaiguang") && ob->query("kaiguang") != me->query("id")){
			return notify_fail("开光后的装备必须本人才能修改。\n");
		}		
		if(!ob->is_item_make()){
			return notify_fail("只有自制装备才能修改。\n");
		}
		
		if(type == "mc"){
			write(INPUTTXT("设置新的名称，与打造装备时一样："ZJBR"可以使用$HIY$等色码符号","zbxg "+id+" mc $txt#")+"\n");
		}else if(type == "cs"){
			write(INPUTTXT("设置新的穿上描述，与打造装备时一样："ZJBR"可以使用$HIY$等色码和$N、$n符号与\\n换行符","zbxg "+id+" cs $txt#")+"\n");
		}else if(type == "tx"){
			write(INPUTTXT("设置新的脱下描述，与打造装备时一样："ZJBR"可以使用$HIY$等色码和$N、$n符号与\\n换行符","zbxg "+id+" tx $txt#")+"\n");
		}else if(type == "ms"){
			write(INPUTTXT("设置新的描述，与打造装备时一样："ZJBR"可以使用$HIY$等色码符号和\\n换行符","zbxg "+id+" ms $txt#")+"\n");
		}else{
			return notify_fail("不明白你的指令。\n");
		}
		
		return 1;
	}
	
	if (! objectp(ob = present(arg, me))){
		return notify_fail("你身上没有这种东西。\n");
	}
		
	if (ob->query("equipped")){
		return notify_fail("你先解除" + ob->name() + "的装备再说！\n");
	}
	if(ob->query("kaiguang") && ob->query("kaiguang") != me->query("id")){
		return notify_fail("开光后的装备必须本人才能修改。\n");
	}		
	if(!ob->is_item_make()){
		return notify_fail("只有自制装备才能修改。\n");
	}

	pops = ZJOBLONG"你正在修改装备："+ob->name()+ZJBR+"请选择你要修改的项目：\n" + ZJOBACTS2+ZJMENUF(2,2,8,30);
	pops += "修改装备名称:zbxg "+arg+" mc" + ZJSEP + "修改装备描述:zbxg "+arg+" ms" + ZJSEP + "修改穿上描述:zbxg "+arg+" cs" + ZJSEP + "修改脱下描述:zbxg "+arg+" tx\n";
	write(pops);

	return 1;
}

int query_autoload() { return 1; }

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
