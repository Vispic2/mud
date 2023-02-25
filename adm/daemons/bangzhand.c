#include <ansi.h>
inherit F_SAVE;
inherit F_DBASE;
string query_save_file()
{
	return DATA_DIR "bangzhan";
}
static int bangzhan;
static int bangzhan_m;
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "帮战系统");
	CHANNEL_D->do_channel( this_object(), "sys", "帮战系统已经启动。");
//	set_heart_beat(20);
	restore();
	//set_heart_beat(20);
}
void heart_beat()
{
	mixed* r;
	object ob,a1;	
	int i;
	int exps,pots,mots;
	string short;
	object *inv;
	object *players;
	int time = time();
	r = localtime(time);
	if(r[1]==35&&r[2]==21&&!bangzhan)
	{
	a1= find_object("d/city/bang/a1");
	if(!a1) a1 = load_object("d/city/bang/a1");
	a1->set("bangzhan",1);
    ob=new("d/city/bang/npc/sho");
	ob->set("name","守护者");
	ob->move(a1);	
    CHANNEL_D->do_channel(this_object(), "chat", HIY"帮战开启，守护者降临！"NOR"");
	shout(HIY"帮战开启，守护者降临！"NOR"\n" );	
	bangzhan=1;
	}else{
	bangzhan=0;
	}
	if(r[1]==15&&r[2]==22&&!bangzhan_m)
	{
	a1= find_object("d/city/bang/a1");
	if(!a1) a1 = load_object("d/city/bang/a1");
	a1->delete("bangzhan");
    inv = all_inventory(a1);
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="sho"&&!userp(inv[i])&&inv[i]->query("bangzhansho")==1)
		{
           destruct(inv[i]);
		}
	}
	//获胜的帮派在线玩家获得奖励。by name
	if(short=a1->query("shendishohu")&&a1->query("shendishohu"))
	{	
	 players = users();              
     for(i = 0; i<sizeof(players); i++){     
     if(short==players[i]->query("banghui/name")){
     exps=10000+random(10000);
     pots=10000+random(5000);
     mots=5000+random(5000);
     players[i]->add("potentiexp",pots);
     players[i]->add("combat_exp",exps);
     players[i]->add("experience",mots);
     tell_object(players[i],HIW"恭喜你的帮派获得了帮派战的胜利，"+HIG+"因此"+players[i]->name()+"获得了："+exps+"经验，"+pots+"潜能，"+mots+"体会。\n"NOR);      
     //log_files("bangzhan", sprintf("%s："+short+"获得了胜利，帮派在线成员："+players[i]->name()+"，他是"+players[i]->query("banghui/name")+" 帮派成员。\n",ctime(time())));	
     }
     }		     
    CHANNEL_D->do_channel(this_object(), "chat", HIY""+short+"获得"+a1->query("short")+"所有权！"NOR"");
	shout(HIY""+short+"获得"+a1->query("short")+"所有权！"NOR"\n" );	
	}else{	
    CHANNEL_D->do_channel(this_object(), "chat", HIY""+a1->query("short")+"没有帮派获取！"NOR"");
	shout(HIY""+a1->query("short")+"没有帮派获取！"NOR"\n" );	
	}		
	bangzhan_m=1;		
	}else{
	bangzhan_m=0;
	}
}

public int zhaohuan(object me)//开启守护，召唤帮派守护
{
	string short;
	object *inv;
	int i;
	object ob,a1;
	a1=environment(me);
    inv = all_inventory(a1);
	if(!me)
	{
	tell_object(me,"格式错误！\n");
	return;
	}
	if(!(short=me->query("banghui/name")))
	{
	tell_object(me,"你有帮派吗？！\n");
	return;
	}
	if(environment(me)->query("bangzhan")!=1||!environment(me)->query("bangzhan"))
	{
	tell_object(me,"这是帮战的地方吗？\n");
	return;	
	}
    if(environment(me)->query("shendishohu")!=short)
	{
	tell_object(me,""+environment(me)->query("short")+"被你们夺下了？\n");
	return;		
	}
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="sho"&&!userp(inv[i]))
		{
	    tell_object(me,"此地已经有守护者！\n");
	    return;	
		}
	}
    ob=new("d/city/bang/npc/sho");
	ob->set("name",HIY+short+HIR"守护者"+NOR);
	ob->set("bangpai",short);
	ob->move(a1);
    CHANNEL_D->do_channel(ob, "chat", HIY""+short+"帮派召唤守护者！"NOR"");
	shout(HIY""+short+"帮派召唤守护者！"NOR"\n" );	
	return;
};

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
