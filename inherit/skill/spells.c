// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me)
{
    	if ((int)me->query_skill("spells", 1) < 10)
		return notify_fail("你的基本法术火候不够，不能学习特殊法术。\n");

    	return 1;
}

varargs mapping query_pfm(string type)
{
	// 查询技能的 pfm 情况
	string dir,filename;
	string  *all_file;
	int i,l;
	mapping pfms;

	dir = file_name(this_object())+"/";
	pfms = ([]);

	if (file_size(dir + "exert/") == -2)
	{
		all_file = list_dirs(dir + "exert/");
		if (sizeof(all_file))
		{
			for (i = 0; i < sizeof(all_file); i++)
			{
				filename = all_file[i];
				l = strlen(filename);
				if (filename[l - 1] == 'c' && filename[l - 2] == '.')
					filename = filename[0..l - 3];

				if(type&&(dir + "exert/"+filename)->pfm_type()
					&&member_array(type,(dir + "exert/"+filename)->pfm_type())==-1)
					continue;

				if((dir + "exert/"+filename)->query_name())
					pfms[filename] = (dir + "exert/"+filename)->query_name()+":exert";
				else
					pfms[filename] = filename+":exert";
			}
		}
		all_file = list_dirs(dir + "perform/");
		if (sizeof(all_file))
		{
			for (i = 0; i < sizeof(all_file); i++)
			{
				filename = all_file[i];
				l = strlen(filename);
				if (filename[l - 1] == 'c' && filename[l - 2] == '.')
					filename = filename[0..l - 3];

				if(type&&(dir + "perform/"+filename)->pfm_type()
					&&member_array(type,(dir + "perform/"+filename)->pfm_type())==-1)
					continue;

				if((dir + "perform/"+filename)->query_name())
					pfms[filename] = (dir + "perform/"+filename)->query_name()+":perform";
				else
					pfms[filename] = filename+":perform";
			}
		}
	}
	else if (file_size(dir) == -2)
	{
		all_file = list_dirs(dir);
		if (sizeof(all_file))
		{
			for (i = 0; i < sizeof(all_file); i++)
			{
				filename = all_file[i];
				l = strlen(filename);
				if (filename[l - 1] == 'c' && filename[l - 2] == '.')
					filename = filename[0..l - 3];

				if(type&&(dir + filename)->pfm_type()
					&&member_array(type,(dir + filename)->pfm_type())==-1)
					continue;

				if((dir+filename)->query_name())
					pfms[filename] = (dir+filename)->query_name()+":cast";
				else
					pfms[filename] = filename+":cast";
			}
		}
	}
	return pfms;
}

// can I exercise force?
int do_effect(object me)
{
	return shaolin_check(me) || hatred_check(me);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
