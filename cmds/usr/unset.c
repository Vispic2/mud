// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	if( !arg || arg=="" ) return help();
	me->delete("env/" + arg);
	UPDATE_D->eval(me,arg);
	write("执行成功！\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：unset <变数名>

这个指令让你删除环境变数的设定。

修改变数设定请用 unset 指令。
TEXT
	);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
