#include <ansi.h>
inherit F_CLEAN_UP;
int weeky(int time1, int time2);
int main(object me, string arg)
{
	int lvl;
	string msg;
    if(!arg)
	return 1;
    lvl = me->query_skill("zuoyou-hubo", 1);
//	if(lvl==360)
//	{
		msg = ZJOBLONG+""HIY"是否将这项招式("+arg+")设定为使用左右互博？"NOR"\n";			
	    msg += ZJOBACTS2;
	    msg += "是:mycmds reset "+arg+" twice"+ZJSEP;
	    msg += "否:mycmds reset "+arg+""+ZJSEP;
	    write(msg + "\n");
	   return 1;
//	}else
	tell_object(me,ZJFORCECMD("mycmds reset "+arg+""));
    return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
