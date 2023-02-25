// by name QQ：3468713544
//矿区 2021.5.27
inherit ROOM;
void create()
{
	set("short", WHT"石料矿场"NOR);
	set("long", "这里石料矿场，到处是石石灰粉十分肮脏！\n");
	set("exits", ([	
	"east" : __DIR__"kqjd",
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
		msg = obs->name()+"慢慢悠悠的舞动着大锤砸下向地面，一小块石头飞了出来。\n";
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
