inherit ROOM;
int do_quit();
void create()
{
        set("short","心魔幻境");
        set("long", @LONG
里面黑乎乎的想是一面镜子似的，你映射才其中。
LONG
        );
        set("exits", ([ 
        ]));
        set("no_update", 1);
	set("action_list",([
		HIR"退出挑战"NOR:"quits",
	
	]));
        setup();
}
void init()
{
	add_action("do_quit","quits");

}
int do_quit()
{
object me;
me = this_player();
me->move("/d/city/kedian");
write("退出成功\n");
return 1;
}

//是镜像
int is_jfb()
 { 
 return 1;
  }


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
