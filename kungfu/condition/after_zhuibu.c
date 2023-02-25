// after_zhuibu.c

// by QingP



#include <condition.h>



inherit F_CLEAN_UP;



int update_condition(object me, int duration)

{

	if ( duration < 1 ) return 0;

	

	me->apply_condition("after_zhuibu", duration - 1);

	

	return 1;

}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
