//	skill.c
//
// 	This is the standard skill daemon object. All objects defining a skill
//	should inherit this as its skeleton.

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

// Check if the user(me) has been ready for combininh some sub
// skills to this skill
int get_ready(object me)
{
	return 1;
}

// Check if the user(me) has finished to combine some sub skills
// to this skill
int get_finish(object me)
{
	return 1;
}

// All the sub skills for combine. Default is null indicating
// that the skill needn't combine from other skills.
mapping query_sub_skills()
{
	return 0;
}

//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill.

int valid_learn(object me) { return 1; }

//
// valid_research()
//
// This function is to check if a character should be able to 
// research the skill. 
int valid_research(object me) { return 1; }

// do effect when parry
int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
	return 1;
}

// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )。
// Currently we have only 2 types of skill: "martial" and "knowledge".

string type() { return "martial"; }

// When I learn from others, The max level I can learn.
int valid_learn_level(object me)
{
	return (type() == "martial") ? 200 : 999;
}

//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill.

void skill_improved(object me) {}

//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>]). When <target> is not present,
// use the character himself as default.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function. 

int exert_function(object me, string arg)
{
	string func, target, file,pfm;
	object target_ob;

	if (sscanf(arg, "%s %s", func, target) == 2)
	{
		target_ob = present(target, environment(me));
		if (! target_ob) return notify_fail("这里没有 " + target + "。\n");
	} else
	{
		func = arg;
		target_ob = me;
	}

	if (! stringp(file = (string)this_object()->exert_function_file(func)) ||
	    file_size(file + ".c") <= 0)
		return 0;

	pfm = replace_string(file,"/","|");

	if(file->query_cd())
	{
		if(me->query("skill_cd/"+pfm))
			return notify_fail("技能CD中，"+me->query("skill_cd/"+pfm)*2+"秒后冷却。。。\n");
	}
	if((int)call_other(file, "exert", me, target_ob))
	{
		if(file->query_cd())
		{
			me->set("skill_cd/"+pfm,file->query_cd());
		}
		return 1;
	}
	else
		return 0;
}

int perform_action(object me, string arg)
{
	string action, target, file,pfm;
	object target_ob;

	if (sscanf(arg, "%s %s", action, target) == 2)
	{
		target_ob = present(target, environment(me));
		if (! target_ob) return notify_fail("这里没有" + target + "。\n");
	} else
	{
		action = arg;
	}

	if (! stringp(file = (string)this_object()->perform_action_file(action)) ||  file_size(file + ".c") <= 0)
		return 0;

	if(me->query("skill_pcd"))
		return notify_fail(me->query("skill_pcd/name")+"的作用时间还没过，"+me->query("skill_pcd/num")*2+"秒之后才能使用外功绝技。\n");

	pfm = replace_string(file,"/","|");
	if(file->query_cd())
	{
		if(me->query("skill_cd/"+pfm))
			return notify_fail("技能CD中，"+me->query("skill_cd/"+pfm)*2+"秒后冷却。。。\n");
	}

	if((int)call_other(file, "perform", me, target_ob))
	{
		if(file->query_pcd())
		{
			me->set("skill_pcd/name",replace_string(file->query_name(),"$br#",""));
			me->set("skill_pcd/num",file->query_pcd());
		}
		if(file->query_cd())
		{
			me->set("skill_cd/"+pfm,file->query_cd());
		}
		return 1;
	}
	else
		return 0;
}

int clear_pfm_cd(object me, string arg)
{
	string action, target, file,pfm;
	object target_ob;

	if (sscanf(arg, "%s %s", action, target) == 2)
	{
		target_ob = present(target, environment(me));
	} else
	{
		action = arg;
	}

	if (! stringp(file = (string)this_object()->perform_action_file(action)) || file_size(file + ".c") <= 0)
		return 0;

	pfm = replace_string(file,"/","|");
	if(file->query_cd())
	{
		me->delete("skill_cd/"+pfm);
	}

	return 1;
}

varargs mapping query_pfm(string type)
{
	// 查询技能的 pfm 情况
	string dir,filename;
	string  *types,*all_file;
	int i,l;
	mapping pfms;

	dir = file_name(this_object())+"/";
	pfms = ([]);

	if (file_size(dir) == -2)
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
					pfms[filename] = (dir+filename)->query_name()+":perform";
				else
					pfms[filename] = filename+":perform";
			}
		}
	}
	return pfms;
}

int NewRandom(int n, int base, int d)
{
	int sum;
	int i;
	int k;

	k = 6;
	if (k > n) k = n;
	if (! k) return n;

	sum = 0;
	for (i = 0; i < k; i++) sum += i;
	sum = random(sum);
	for (i = 0; i < k; i++)
	{
		sum -= i;
		if (sum <= 0)
		{
			n = n - k + i;
			if (n <= 0) n = 0;
			break;
		}
	}
	return n;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
