// refuse.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	function f;

	seteuid(getuid());

	if (! arg)
		//return notify_fail("你要拒绝谁？\n");
	return notify_fail(INPUTTXT("你要拒绝谁？？请输入对方的id","refuse $txt#")+"\n");


	notify_fail("这人没有向你提出什么要求啊？\n");
	if (! functionp(f = me->query_temp("pending/answer/" + arg + "/refuse", 1)))
		return 0;

	me->delete_temp("pending/answer/" + arg);
	return evaluate(f);
}

int help(object me)
{
   write( @HELP
指令格式: refuse <someone>

拒绝某人向你提出的要求。
HELP );
   return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
