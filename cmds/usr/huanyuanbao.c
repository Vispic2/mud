// enforce.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || !sscanf(arg, "%d", pts))  
		return notify_fail(INPUTTXT("元宝转换元宝票为单向转换，比例为1:1。你目前元宝："+me->query("yuanbao")+"个，目前元宝票"+me->query("yuanbaos")+"。请注意一旦转换无法撤回。你要把多少元宝转换为元宝票？","huanyuanbao $txt#")+"\n");
		if( pts < 0 || pts >(int)me->query("yuanbao") )
		return notify_fail("你的元宝不足。\n");
		me->add("yuanbao", -pts);
		me->add("yuanbaos", pts);
		write("你把"+arg+"元宝转换为元宝票。你现有元宝票："+me->query("yuanbaos")+"个；元宝："+me->query("yuanbao")+"个。\n");
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
