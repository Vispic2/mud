//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string file)
{
	string list;
	object env,npc;
if (! SECURITY_D->valid_grant(me, "(wizard)"))
		return 0;
    if(!file)
	 return notify_fail("格式错误。\n");
    env = environment(me);
	if (!objectp(npc=present(file,env)))
	return notify_fail(HIG"你身边没有这个NPC！"NOR"\n");
	file = base_name(npc);
	list = read_file(file+".c");
	me->force_me("update "+file);
	env->reset();
	write("更新"+file+"成功！\n");
	return 1;
}

int help (object me)
{

	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
