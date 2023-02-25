// story:laojun

#include <ansi.h>

string give_gift();

static mixed *story = ({
	"玉皇大帝：老君，你那儿有没有治笨病的药？",
	"太上老君：有，有，我这儿新研制了一种仙丹，可以使人变聪明。",
	"玉皇大帝大喜道：好，快给我两颗。",
	"太上老君疑惑道：莫非......",
	"玉皇大帝长叹一声：不是不是，我们家那口子是越来越不行了，蟠桃园亏惨了！还不及弼马温管呢。", 
	"太上老君掏出一葫芦：喏，这儿。",
	"玉皇大帝：" HIC "哎呀！" NOR,
	"太上老君：不好，怎么掉了，马上派人去找找。",
	"玉皇大帝：算了算了，不就一仙丹嘛，再给我一颗就是了。",
	(: give_gift :)
});

void create()
{
	seteuid(getuid());
}

mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
	STORY_D->give_gift("/clone/vip/dan_int", 1,
			   HIM "\n“啪”的一声一枚仙丹掉到你面前。"NOR"\n");
	return HIM "听说天庭遗落了一枚仙丹。" NOR;
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
