// by name QQ：3468713544
//矿区 2021.5.27
inherit ROOM;
void create()
{
	set("short", HIW"铁料矿洞"NOR);
	set("long", "这里铁料矿洞，工人们拿着铁镐在凿击着坚硬的铁矿！\n");
	set("exits", ([	
	"west" : __DIR__"kqjd",
	]));
	set("no_fight", 1);
	set_heart_beat(1);
	setup();
}

void heart_beat()
{

string obs,msg;
object *ob=all_inventory();
foreach(obs in ob){
if(!obs->query("puyi")) continue;
if(random(2)) continue;
switch (random(6))
{
	case 0:
		msg = obs->name()+"奋力的工作着。\n";
		break;
	case 1:
		msg = obs->name()+"奋力的工作着。。\n";
		break;
	case 2:
		msg = obs->name()+"奋力的工作着。。。\n";
		break;
	case 3:
		msg = obs->name()+"奋力的工作着。。。。\n";
		break;
	case 4:
		msg = obs->name()+"奋力的工作着。。。。。\n";
		break;
	default:
		msg = obs->name()+"挥舞的铁镐向一块铁矿砸去。\n";
		break;
}
}
tell_room(this_object(),msg+"\n");
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
