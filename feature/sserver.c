// sserver.c

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
	me->clean_up_enemy();
	return me->select_opponent();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
