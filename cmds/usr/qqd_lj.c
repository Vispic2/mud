#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string pts;
	if( !arg || !sscanf(arg, "%s", pts))  
	return notify_fail(INPUTTXT("你想将此账号绑定哪个QQ号？","qqd_lj $txt#")+"\n");
	me->set("qqd_key_qq",pts);
	write("绑定QQ："+pts+"，前往QQ群认证游戏即可。\n");
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
