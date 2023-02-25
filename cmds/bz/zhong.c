
#define BANGZHAN_D "/cmds/bz/bangzhand"
#include <ansi.h>
inherit ROOM;
int do_bmbz();
//报名参赛
int do_lookzy();
//查看目前本帮抢夺资源
void create()
{
	set("short", HIC"帮"HIW"派"HIY"之"HIG"巅"NOR);
	set("long", @LONG
这里是帮战之巅，每当晚上9点25-29分各个帮派成员均会聚集于此，只为争夺帮派之首。
LONG );
	set("outdoors", "city");
	set("exits", ([
	 	"north" : "/cmds/bz/north",	 
	 	"south" : "/cmds/bz/south",		
	 	"west" : "/cmds/bz/west",	
	 	"east" : "/cmds/bz/east",	
	 	"southwest" : "/d/city/beidajie1",
	]));
	set("action_list", ([
		"报名帮战" : "bmbz",
		"查看资源":"lookzy",
	]));	
	setup();
}
void init()
{
	add_action("do_bmbz", "bmbz");
	add_action("do_lookzy", "lookzy");
}
int do_bmbz()
{
object me=this_player();
BANGZHAN_D->bmbz(me);
return 1;
}
int do_lookzy()
{
string msg;
object me,room;
mapping bzbm;
me=this_player();
room=load_object("/cmds/bz/bangzhand");
if(!mapp(room->query("bzbm"))){
tell_object(me,"还没有任何帮派报名！\n");
return 1;
}
/*
if(!room->query("bangzhan_start")){
tell_object(me,"还没有任何帮派报名！\n");
return 1;
}*/
bzbm=BANGZHAN_D->get_bangzhand();
msg=ZJOBLONG"帮派之首抢夺战情况："ZJBR"抢夺资源率先达到1000则胜利！\n";
msg+=ZJOBACTS2+ZJMENUF(1,1,9,31);
for(int i=0;i<sizeof(keys(bzbm));i++){
msg+="帮派名称："+keys(bzbm)[i]+"------抢夺资源："+bzbm[keys(bzbm)[i]][0]+"/1000:look"ZJSEP;
}
tell_object(me,msg+"\n");
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
