// by name QQ：3468713544
//矿区 2021.5.27
inherit ROOM;
void create()
{
	set("short", CYN"私人树林"NOR);
	set("long", "这里四周都是百年大树，一颗便有百丈之高！\n");
	set("exits", ([	
	"south" : __DIR__"kqjd",
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
		msg = "只听轰动一声原来是"+obs->name()+"把一颗大树砍断了。\n";
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
