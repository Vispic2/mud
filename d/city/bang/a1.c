

inherit ROOM;

void create()
{
	set("short", HIC"帮"HIW"战"HIY"圣"HIG"地"NOR"");
	set("long", @LONG
武林各大帮派战斗的地方，每天9点35开始到10点15结束，获得胜利的帮派全体在线成员均可获得大量奖励！！！
LONG );
	set("outdoors", "city");
	set("exits", ([
	//	"east" : "d/city/kedian",
	 	"southwest" : "/d/city/beidajie1",
	 	
	]));
	set("action_list", ([
		"占据圣地" : "zaoh",
	]));	
	set("objects", ([
	]));
	setup();
}
void init()
{
	add_action("do_list", "zaoh");
}
int do_list()
{
	BANGZ->zhaohuan(this_player());
	return 1;
}
int start()
{
	object *inv;
	int i;
    inv = all_inventory(this_object());	
	for(i=0;i<sizeof(inv);i++)
    tell_object(inv[i],HIG"圣地封禁，20秒解禁！"NOR"\n");
    this_object()->set("no_fight",1);
	call_out("clear_bang",20);
	return 1;
}
int clear_bang()
{
	object *inv,ob;
	int i;
	string short;
	int k=0;
    inv = all_inventory(this_object());	
	this_object()->delete("no_fight");
	for(i=0;i<sizeof(inv);i++)
	{
    tell_object(inv[i],HIG"圣地解禁！厮杀开始！"NOR"\n");
	if(inv[i]->query("id")=="sho"&&!userp(inv[i])&&inv[i]->query("bangzhansho")==1&&this_object()->query("shendishohu"))
	k=1;
	}
	if(k==0&&short=this_object()->query("shendishohu"))
    {
    ob=new("d/city/bang/npc/sho");
	ob->move(this_object());
	this_object()->delete("shendishohu");
    CHANNEL_D->do_channel(ob, "chat", HIY""+short+"放弃召唤守护，"+this_object()->query("short")+"重置！"NOR"");
	shout(HIY""+short+"放弃召唤守护，"+this_object()->query("short")+"重置！"NOR"\n" );	
	return;
	}
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
