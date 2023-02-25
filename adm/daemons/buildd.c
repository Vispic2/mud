// buildd.c

#pragma optimize
#pragma save_binary

#include <ansi.h>

void create() { seteuid(getuid()); }

string get_file_code(object env)
{
	return read_file(base_name(env)+".c");
}

int build_file(object me,string file,string text)
{
	assure_file(file);
	write_file(file,text,1);
	return 1;
}

int del_file(object me,string file)
{
	rm(file);
	return 1;
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
