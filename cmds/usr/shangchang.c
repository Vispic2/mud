
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    string str;
	if(!arg)
	{
		str = ZJOBLONG+HIY"                     【  随  身  商  店  】"NOR""ZJBR
		HIG"目前元宝："+me->query("yuanbao")+"，目前元宝票："+me->query("yuanbaos")+""NOR""ZJBR
        HIW"抽奖系统搏一搏单车变摩托"+ZJURL("cmds:choujiang")+HIY+"【点击抽奖】"NOR"\n";
		str += ZJOBACTS2+ZJMENUF(2,2,10,28);
		str +=
		HIY"元宝商场:myshop"ZJSEP
	    HIW"元宝票商场"NOR":myshop1";
		message("vision", str+"\n", me);		
	}	
	return 1;
}

/*


#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    string str;
	if(!arg)
	{
		str = ZJOBLONG+HIY+"                     【  随  身  商  店  】"ZJBR
		""HIW"目前元宝："+me->query("yuanbao")+"，目前元宝票："+me->query("yuanbaos")+""ZJBR
        ""HIC"抽奖系统搏一搏单车变摩托"+ZJSIZE(24)+HIM+ZJURL("cmds:choujiang")+"[点击抽奖]"NOR"\n";
		str += ZJOBACTS2+ZJMENUF(2,2,10,28);
		str +=
		HIY"元宝商场:myshop"ZJSEP
	    HIW"元宝票商场"NOR":myshop1";
		message("vision", str+"\n", me);		
	}	
	return 1;
}

*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
