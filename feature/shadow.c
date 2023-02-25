// shadow.c

static object shadowing = 0;

object do_shadow(object ob, int flag)
{
	shadowing = ob;
	return shadow(ob, flag);
}

void remove_shadow(object ob)
{
	if (ob && ob != shadowing)
		return;

	destruct(this_object());
}

object query_shadow_now()
{
	return shadowing;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
