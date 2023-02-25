// by俗称
#include <ansi.h>
inherit ROOM;
#define J_SYS "/test/j_sys"
int ask_job();
void create()
{
	set("short", HIY"渡劫谷"NOR);
	set("long", @LONG
这处神秘无比，四周都是云雾如仙境一般，前面似乎有个镜子?里面好像闪烁着奇光！
LONG );
	set("room_lp", 1);
	set("no_fight", 1);	
		set("item_desc",([
            HIY"虚空境" : HIY"				 
            ※※※※※※※※※※※※※※※※※※※※※※
            ※※※※※※※※※※※※※※※※※※※※※※
            ※※※※※     虚空境    ※※※※※※
            ※※※※   里面黑乎乎的   ※※※※
            ※※※※※※ 世界扭曲着   ※※※※※  
            ※※※※※※※※※※※※※※※※※※※※※※
            ※※※※※※※※※※※※※※※※※※※※※※"NOR"\n",
		]));
		
	set("action_list",([
		HIR"突破境界"NOR:"tupo",
		HIR"心魔幻境"NOR:"job",
	]));
	set("exits", ([
		"south" : __DIR__"dujie9",
	]));
	setup();
}
void init()
{
	add_action("ask_job","job");
	
}
int ask_job()
{
	object me;
	object *team,jmem;
	int i,size;	
	me = this_player();
	team = me->query_team();//队伍的阵列
	size = sizeof(team);//取个数
	//删除旧的副本
		if (me->query("yy") < 1 )
	return notify_fail(HIR"元婴都没突破，你想跳级？！\n"NOR);	
		if (me->query("xm") > 1 )
	return notify_fail(HIR"你已经挑战成功了，没必要再来一次了！\n"NOR);	
	jmem = me->query_temp("room/jfbb_jmem");
	if(objectp(jmem))//清除标识
	{
		jmem->delete("user_id");
	}
	if(size > 1)//是否是队伍
	{
		tell_object(me,"这是要挑战自己的心魔还是别人的心魔？。\n");
	}
		J_SYS->jfbb(me);//创建新的副本
	
	    return 1;	
	     
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
