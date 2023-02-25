// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	if(!arg)
	{
		str = ZJOBLONG"请选择升级类型：\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "角色等级:uplv -l"ZJSEP"技能等级:uplv -s"ZJSEP"角色天赋:uplv -t"ZJSEP"放弃经验:abandon exp"
		ZJSEP"奇经八脉:beat"ZJSEP"建立家园:crroom"ZJSEP"扩建家园:crroom"ZJSEP"修改家园:edroom"ZJSEP"增加功能:edroom"ZJSEP"拆除场景:delroom"ZJSEP"家园开关:closeroom"ZJSEP"修改绰号:nick"ZJSEP"结拜兄弟:brothers"ZJSEP"武功排行:combat"ZJSEP"【本MUD目前所有武功排行】:syskill";
		
		message("vision", str+"\n", me);
	}
	else if(arg=="-l"){		
	F_LEVEL->improve_level(me);		
	}else 
	if(arg=="-t"){
	str = ZJOBLONG"请选择提升天赋：\n";
	str += ZJOBACTS2+ZJMENUF(4,4,9,31);
	str += "提升根骨:uplv con"ZJSEP;
	str += "提升臂力:uplv str"ZJSEP;
	str += "提升悟性:uplv int"ZJSEP;
	str += "提升身法:uplv dex";
	write(str+"\n");
	}else 
	if(arg=="-s"){	
	F_LEVEL->up_skills(me);
	}else
	if(arg=="con"){	
	F_LEVEL->up_tianfu(me,arg);
	}else
	if(arg=="int"){	
	F_LEVEL->up_tianfu(me,arg);
	}else
	if(arg=="str"){	
	F_LEVEL->up_tianfu(me,arg);
	}else
	if(arg=="dex"){	
	F_LEVEL->up_tianfu(me,arg);
	}
	
	
		
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: uplv [-s]

这个指令让你消耗经验提升等级。

HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
