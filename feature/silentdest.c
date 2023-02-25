// silentdest.c

void reset()
{
	object env;
	object *obs;

	env = this_object();
	while (environment(env))
	{
		env = environment(env);
		if (env->is_character())
			return;
	}

	obs = filter_array(all_inventory(env), (: userp :));
	if (! sizeof(obs))
		destruct(this_object());
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
