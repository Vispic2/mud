// color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
     object obj;
     object a;
     obj = present("hu lu",me);
     if (!objectp(obj))
	 return notify_fail("如果你能给我葫芦，我会告诉你一切的！\n");
	 destruct(obj);
	// a=new("/clone/book/xianglong");
//	 a->move(me);
    write("游鲲翼接过葫芦\n");
	write("游鲲翼对着你的耳朵小声的说着.........你顿时恍然大悟，去闯荡江湖的决心更深了！\n");
if(me->query("youkun") < 1)
	{
	    me->add("combat_exp",1000);
    	me->add("potential",1000);
    	me->set("youkun",1);
    	me->set("chusheng",1);
    	me->save();
	    write(HIC"干的不错，你被奖励了一千点经验，1千点潜能，你可以去车马行雇车去闯荡江湖了"NOR"\n");
	    }
//	write("谢谢这位小兄弟，以后你的事情就是我郭靖的事情，给这是一本秘籍送给你了！\n");
//	write("恭喜获得了："+CYN+"降龙十八掌秘籍一本\n"NOR);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
