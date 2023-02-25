// Room: /city/kedian.c

#include <room.h>

inherit CREATE_CHAT_ROOM;
int fly(string arg);
string do_fly();
void create()
{
	set("short", "宝昌客栈");
	set("long", @LONG
这里是生意兴隆的宝昌客栈，附近的外地游客多选择在此落脚。一个年轻
的店小二里里外外忙得团团转，接待着南腔北调的客人。客店的主人从不露面，他究竟是谁，江湖中流传着各种各样的猜测。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"【牌子】" : "楼上雅房，每夜十两白银，如果你想上二楼休息，你需要交给小二足够的银子。\n"
		ZJOBACTS2+ZJMENUF(2,3,9,28)"付钱住店:give 10 silver to xiao er\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		"/adm/npc/shizhe" : 1,
		"/adm/npc/xnshizhe" : 1,
		"/d/city/npc/jieyin-shi" : 1,
//"/adm/npc/youxun" : 1,
//"/quest/job/anran" :1,
//"/adm/npc/beichou" :1,
//"/adm/npc/nanxian" :1,
	  
	]));
	set("action_list", ([
		HIY"新手拜师"NOR:"do_fly",
	]));
	set("exits", ([
	
		"west" : __DIR__"beidajie1",
		"up"   : __DIR__"kedian2",
		"north": __DIR__"liaotian",
		"east": __DIR__"bgs",
		"south": __DIR__"bgss",
		"northwest": "/d/jfjwm/jinwumen",
	]));

	setup();
}

void init()
{
	add_all_action();
    add_action("fly","fly2");
    add_action("do_fly","do_fly");    
}

string do_fly()
{
	write(ZJOBLONG"推荐萌新体验的四个门派：\n"
		ZJOBACTS2+ZJMENUF(1,1,8,30)+
		"华山派(新手推荐-悟性流):fly2 huashan"ZJSEP
		"逍遥派(新手推荐-悟性流):fly2 xiaoyao"ZJSEP
		"血刀门(新手推荐-臂力流):fly2 xuedao"ZJSEP
		"灵柩宫(新手推荐-臂力流):fly2 lingjiu\n");
		return "。。。";
}
int fly(string arg)
{
	object me=this_player();
	if (arg=="huashan") me->move("/d/huashan/qunxianguan");
	else if (arg=="xiaoyao") me->move("/d/xiaoyao/muwu3");
	else if (arg=="xuedao") me->move("/d/xuedao/wangyougu");
	else if (arg=="lingjiu") me->move("/d/lingjiu/damen");
	else write(HIR"\n输入错误"NOR"\n");
	return 1;
}


int valid_leave(object me, string dir)
{

	if (! me->query_temp("rent_paid") && dir == "up")
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if (me->query_temp("rent_paid") && dir == "west")
		return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！旁人还以为小店伺候不周呢！\n");
    // if (!me->query("guibing_room") && dir == "south")
		//return notify_fail(HIY"你不是本MUD的贵宾玩家，贵宾玩家100R一位，访问http://"+NAME_PAY+"/进行购买卡密。\n"HIR"贵宾特权："+NOR+HIG+"每秒获得高额经验潜能奖励，并且增加研究，练习，读书，静修，汲取提升200%的效率。"NOR"\n");



	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
