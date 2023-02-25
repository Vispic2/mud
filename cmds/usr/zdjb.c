// updateall.c
#include <ansi.h>

void runcmd(object me, string cmd){
	string *list;
	
	list = explode(cmd,"|");
	if(sizeof(list) == 4){
		
		if(to_int(list[3]) < 100 && (list[1]=="qi" || list[1]=="eff_qi" || list[1]=="jing" || list[1]=="eff_jing" || list[1]=="neili" || list[1]=="jingli")){
			
			if((list[2] == "<"||list[2] == "＜")  && to_int(me->query(list[1])*100.0/me->query("max_"+list[1])) < to_int(list[3])){
				
				me->force_me(list[0]);
				
			}else if((list[2] == ">"||list[2] == "＞") && to_int(me->query(list[1])*100.0/me->query("max_"+list[1])) > to_int(list[3])){
				me->force_me(list[0]);
			}			
		}else{
			
			if((list[2] == "<"||list[2] == "＜") && me->query(list[1]) < to_int(list[3])){
				
				me->force_me(list[0]);
				
			}else if((list[2] == ">"||list[2] == "＞") && me->query(list[1]) > to_int(list[3])){
				
				me->force_me(list[0]);
			}	
		}
	}else{
		me->force_me(cmd);
	}

}

void jiesu(object me,int zt){
	if(me->query_temp("damage")>0){
		if(zt==1){
			tell_object(me,HIR"你给对手造成了"+me->query_temp("damage")+"点伤害，同时自身陷入忙乱。"NOR"\n");
		}else if(zt==2){
			tell_object(me,HIG"战斗胜利，你给对手造成了"+me->query_temp("damage")+"点伤害。"NOR"\n");
		}else{
			tell_object(me,HIG"连番攻击，你给对手造成了"+me->query_temp("damage")+"点伤害。"NOR"\n");
		}
		me->set_temp("damage",0);			
	}else{
		if(zt==1){
			tell_object(me,HIR"你陷入忙乱中。"NOR"\n");
		}else if(zt==2){
			tell_object(me,HIG"战斗胜利，请调整状态迎接新的战斗。"NOR"\n");
		}else{
			tell_object(me,HIG"你完成了一番攻击。"NOR"\n");
		}		
	}
	me->set_temp("zdjb",0);	
}

int auto_zhandou(object me)
{
	string jb, *list, *mls;
	int i,j,zt,zt2;
	
	//jb = "use baoming dan|qi|<|50;wo he tian-b;exert recover|qi|<|50;jiali max;perform strike.bafang twice:12;jiali 0";
	
	jb = me->query("zdjb/s"+me->query("zdjb/def"));
	if(!stringp(jb)) return 0;
	
	list = explode(jb,";");
	
	for(i=0; i<sizeof(list); i++){ //第一时间回血回精
		if(strsrch(list[i], "exert recover") > -1 || strsrch(list[i], "exert regenerate") > -1){
			runcmd(me,list[i]);
		}
	}
	
	zt = me->query_temp("zdjb_zt");
	zt2 = me->query_temp("zdjb_zt2");
	
	if(zt2 > 0){
		tell_object(me,HIG"忙乱过后，你行云流水般地接着攻向对手。"NOR"\n");
	}else if(zt > 0){
		tell_object(me,HIG"忙乱过后，你好整以暇再次向对手发动攻击。"NOR"\n");
	}else{
		tell_object(me,HIG"你向对手发起新的攻击。"NOR"\n");
	}
	
	for(i=zt; i<sizeof(list); i++){
		
		if(! me->is_fighting()){
			me->set_temp("zdjb_zt",0);
			me->set_temp("zdjb_zt2",0);
			jiesu(me,2);
			return 0;
		}
		
		if(me->is_busy()){
			me->set_temp("zdjb_zt",i);
			me->set_temp("zdjb_zt2",0);
			jiesu(me,1);
			return 0;
		}
		
		mls = explode(list[i],":");
		if(sizeof(mls) == 2){
			
			for(j=zt2; j < to_int(mls[1]); j++){
				
				if(! me->is_fighting()){
					me->set_temp("zdjb_zt",0);
					me->set_temp("zdjb_zt2",0);
					jiesu(me,2);
					return 0;			
				}

				if(me->is_busy()){
					me->set_temp("zdjb_zt",i);
					me->set_temp("zdjb_zt2",j);
					jiesu(me,1);
					return 0;	
				}

				// if(j == to_int(mls[1])-1)
					// me->set_temp("zdjb_zt2",0);
				
				runcmd(me,mls[0]);
			}
			me->set_temp("zdjb_zt2",0); //小循环完了，小循环清零
			
		}else{
			runcmd(me,mls[0]);			
		}
		
		// if(i == sizeof(list)-1){
			// me->set_temp("zdjb_zt",0);
			// me->set_temp("zdjb_zt2",0);
		// }
			
	}
	
	me->set_temp("zdjb_zt",0); //大循环完了，双清零
	me->set_temp("zdjb_zt2",0);

	jiesu(me,0);
	return 1;
}

int checkjb(string jb){
	
	string *list, *mls,*no_com;
	int i,j,coms=0;
	 
	no_com = ({"get","accept","halt"});
	
	list = explode(jb,";");
	
	if(!sizeof(list)){
		write("脚本格式不合法，没有发现脚本命令。\n");
		return 0;		
	}
	
	// if(sizeof(list) > 6){
		// write("脚本格式不合法，命令条数不能超过6条。\n");
		// return 0;
	// }
	
	for(i=0; i<sizeof(list); i++){		
		
		for(j=0; j < sizeof(no_com); j++){
			if(strsrch(list[i],no_com[j]) == 0){
				write("命令不合法，战斗脚本不能设置 "+no_com[j]+" 命令。\n");
				return 0;			
			}
		}
		
		mls = explode(list[i],":");
		if(sizeof(mls) == 2){
			coms += to_int(mls[1]);
		}else{
			coms++;
		}
	}
	
	if(coms > 30){
		write("脚本格式不合法，总执行命令数不能大于30。\n");
		return 0;			
	}
	
	return 1;
}


int main(object me, string arg)
{
	string pops,com,jbtxt,def0="",def1="",def2="",def3="";
	

	if(!arg){
		
		if(me->query("zdjb/def") == 1){
			def1=HIG" 当前默认"NOR"";
		}else if(me->query("zdjb/def") == 2){
			def2=HIG" 当前默认"NOR"";
		}else if(me->query("zdjb/def") == 3){
			def3=HIG" 当前默认"NOR"";
		}else{
			def0=HIG" 当前默认"NOR"";
		}
		
		pops= ZJOBLONG"战斗脚本管理面板："+ZJURL("cmds:zdjb ?")+HIY"【查看脚本说明】"NOR""NOR"\n";
		pops+=ZJOBACTS2+ZJMENUF(1,1,10,28);
		
		pops += "设置战斗脚本1:zdjb s1" + ZJSEP; 
		pops += "设置战斗脚本2:zdjb s2" + ZJSEP; 
		pops += "设置战斗脚本3:zdjb s3" + ZJSEP; 
		
		pops += "战斗时自动循环使用脚本1 (zdjb 1)"+def1+":zdjb 1" + ZJSEP; 
		pops += "战斗时自动循环使用脚本2 (zdjb 2)"+def2+":zdjb 2" + ZJSEP; 
		pops += "战斗时自动循环使用脚本3 (zdjb 3)"+def3+":zdjb 3" + ZJSEP; 
		
		pops += "战斗时不自动使用脚本 (zdjb 0)"+def0+":zdjb 0" + "\n"; 
		
		write(pops);		
		
		return 0;
	}

	if(sscanf(arg,"%s %s", com, jbtxt) == 2){
		if(checkjb(jbtxt)){		
			if(com == "s1"){
				me->set("zdjb/s1",jbtxt);
				write("战斗脚本1设置成功，用命令 zdjb 1 可在战斗时自动使用此脚本。\n");
			}else if(com == "s2"){
				me->set("zdjb/s2",jbtxt);
				write("战斗脚本2设置成功，用命令 zdjb 2 可在战斗时自动使用此脚本。\n");				
			}else if(com == "s3"){
				me->set("zdjb/s3",jbtxt);
				write("战斗脚本3设置成功，用命令 zdjb 3 可在战斗时自动使用此脚本。\n");				
			}
		}
		return 1;
	}else{
		if(arg == "s1"){
			if(stringp(me->query("zdjb/s1"))){
				write(INPUTTXT("设置战斗脚本1："+ZJBR+"当前设置 (显示已换行处理，实际输入不能换行)："+ZJBR+ZJBR+replace_string(me->query("zdjb/s1"),";",";"+ZJBR)+ZJBR,"zdjb s1 $txt#")+"\n");
			}else{
				write(INPUTTXT("设置战斗脚本1：","zdjb s1 $txt#")+"\n");
			}
		}else if(arg == "s2"){
			if(stringp(me->query("zdjb/s2"))){
				write(INPUTTXT("设置战斗脚本2："+ZJBR+"当前设置 (显示已换行处理，实际输入不能换行)："+ZJBR+ZJBR+replace_string(me->query("zdjb/s2"),";",";"+ZJBR)+ZJBR,"zdjb s2 $txt#")+"\n");
			}else{
				write(INPUTTXT("设置战斗脚本2：","zdjb s2 $txt#")+"\n");
			}
		}else if(arg == "s3"){
			if(stringp(me->query("zdjb/s3"))){
				write(INPUTTXT("设置战斗脚本3："+ZJBR+"当前设置 (显示已换行处理，实际输入不能换行)："+ZJBR+ZJBR+replace_string(me->query("zdjb/s3"),";",";"+ZJBR)+ZJBR,"zdjb s3 $txt#")+"\n");
			}else{
				write(INPUTTXT("设置战斗脚本3：","zdjb s3 $txt#")+"\n");
			}
		}else if(arg == "1"){
			if(stringp(jbtxt=me->query("zdjb/s1")) && checkjb(jbtxt)){
				me->set("zdjb/def",1);
				write("你已设置在战斗时自动使用脚本1。\n");
			}else{
				write("没发现战斗脚本1，或者脚本格式不合法。\n");
			}
		}else if(arg == "2"){
			if(stringp(jbtxt=me->query("zdjb/s2")) && checkjb(jbtxt)){
				me->set("zdjb/def",2);
				write("你已设置在战斗时自动使用脚本2。\n");
			}else{
				write("没发现战斗脚本2，或者脚本格式不合法。\n");
			}		
		}else if(arg == "3"){
			if(stringp(jbtxt=me->query("zdjb/s3")) && checkjb(jbtxt)){
				me->set("zdjb/def",3);
				write("你已设置在战斗时自动使用脚本3。\n");
			}else{
				write("没发现战斗脚本3，或者脚本格式不合法。\n");
			}			
		}else if(arg == "0"){
			me->set("zdjb/def",0);
			write("你已设置在战斗时 不 使用脚本。\n");
		}else if(arg == "?"){
pops= ZJOBLONG+"战斗脚本说明："+ZJBR+ZJBR+
"1、战斗脚本是在战斗时能自动循环执行设置好的命令脚本，每条命令之间用 “;” 分隔。"+ZJBR+ZJBR+
"2、战斗脚本可以设置3条，用命令 zdjb 1、2、3 可即时切换默认使用的脚本，用命令 zdjb 0 可以停止使用战斗脚本。技巧：在脚本中使用脚本切换命令，就可实现三条脚本循环执行。"+ZJBR+ZJBR+
"3、每条命令后面可加 :N” (N代表执行次数)"+ZJBR+
"比如：perform strike.bafang twice:12"+ZJBR+
"表示：执行12次 perform strike.bafang twice 命令"+ZJBR+ZJBR+
"4、每个脚本的总执行命令次数不得超过30。"+ZJBR+ZJBR+
"5、每条命令还可以加入自身属性判断。需要注意的是其中的"HIY"小于号和竖线一定要是英文状态下的输入"NOR"。"+ZJBR+
"比如：use baoming dan|qi|<|5000"+ZJBR+
"表示：属性 qi<5000 时才执行 use baoming dan 命令"+ZJBR+
"各项自身属性的 id："+ZJBR+"qi=气血，eff_qi=有效气血，max_qi=最大气血"+ZJBR+"jing=精神，eff_jing=有效精神，max_jing=最大精神"+ZJBR+"neili=内力，max_neili=最大内力"+ZJBR+"jingli=精力，max_jingli=最大精力"+ZJBR+ZJBR+
"6、脚本执行中遇到busy时，会暂停执行脚本命令，等到busy过了会再继续执行后面命令。"+ZJBR+ZJBR+
"7、为了减少信息刷屏而造成玩家操作延迟，脚本命令中的技能攻击命令不会逐条显示攻击信息，会在每一轮攻击完成后，显示一个总的攻击伤害。"+ZJBR+ZJBR+
"8、一个完整的脚本例子："+ZJBR+
"use baoming dan|qi|<|50000;wo he tian-b;exert recover|qi|<|50000;jiali max;perform strike.bafang twice:12;jiali 0\n";
			write(pops);
		}else{
			write(arg+"：参数错误!\n");
		}
	}
	
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
