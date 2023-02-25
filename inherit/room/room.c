// room.c
#pragma save_binary

#include <dbase.h>
#include <room.h>
#include <config.h>
#define ENABLE_OPTIMIZE	 1
inherit F_DBASE;
inherit F_CLEAN_UP;
static mapping doors;

#if ENABLE_OPTIMIZE
static string s_long;
static string s_short;
static mixed  s_fight;
#endif

int query_max_encumbrance() { return 100000000000; }

int is_room() { return 1; }

object make_inventory(string file)
{
	object ob;

	ob = new(file);
	if(ob->is_character())
	{
		ob->set("startroom", base_name(this_object()));
		ob->set("resetroom",this_object());
	}
	ob->move(this_object());
	return ob;
}

void load_npc(string file, int time)
{
	call_out("npc_come",time,file);
}

void npc_come(string file)
{
	make_inventory(file);
}

void reset()
{
	mapping ob_list, ob;
	string *list;
	int i,j;
	mapping guards;
	object *obs;

	//特殊场景不允许刷新
	if (query("no_clean_up_fb"))
		return;

	// remove the action done in this room
	delete_temp("been");
	if ((guards = query_temp("guarded")) && ! sizeof(guards))
	{
		delete_temp("guarded");
	}

	set("no_clean_up", 0);
	ob_list = query("objects");
	if (! mapp(ob_list)) return;

	if(query("reset_times")) return;
	add("reset_times",1);

	if (! mapp(ob = query_temp("objects")))
		ob = allocate_mapping(sizeof(ob_list));
	list = keys(ob_list);
	for (i = 0; i < sizeof(list); i++)
	{
		// Allocate an array if we have multiple same object specified.
		if (undefinedp(ob[list[i]]) &&
		    intp(ob_list[list[i]]) &&
		    ob_list[list[i]] > 1)
			ob[list[i]] = allocate(ob_list[list[i]]);

		switch (ob_list[list[i]])
		{
		case 1:
			if (! ob[list[i]]) ob[list[i]] = make_inventory(list[i]);
			if (environment(ob[list[i]]) != this_object() && ob[list[i]]->is_character())
			{
				if (! ob[list[i]]->return_home(this_object()))
					add("no_clean_up", 1);
			}
			break;
		default:
			for (j = 0; j < ob_list[list[i]]; j++)
			{
				// If the object is gone, make another one.
				if (! objectp(ob[list[i]][j]))
				{
					ob[list[i]][j] = make_inventory(list[i]);
					continue;
				}
				// Try to call the wandering npc come back here.
				if (environment(ob[list[i]][j]) != this_object() &&
				    ob[list[i]][j]->is_character())
				{
					if (! ob[list[i]][j]->return_home(this_object()))
						add("no_clean_up", 1);
				}
			}
		}
	}
	set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
	if (! mapp(doors) || undefinedp(doors[dir]))
		return "你要看什么？\n";
	if (doors[dir]["status"] & DOOR_CLOSED)
		return "这个" + doors[dir]["name"] + "是关着的。\n"ZJOBACTS2"开门:open "+dir+"\n";
	else
		return "这个" + doors[dir]["name"] + "是开着的。\n"ZJOBACTS2"关门:close "+dir+"\n";
}

varargs int open_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if (! mapp(doors) || undefinedp(doors[dir]))
		return notify_fail("这个方向没有门。\n");

	if (! (doors[dir]["status"] & DOOR_CLOSED))
		return notify_fail(doors[dir]["name"] + "已经是开着的了。\n");

	exits = query("exits");
	if (! mapp(exits) || undefinedp(exits[dir]))
		error("Room: open_door: attempt to open a door with out an exit.\n");

	if (from_other_side)
		message("vision", "有人从另一边将" + doors[dir]["name"] + "打开了。\n", this_object());
	else
	if (objectp(ob = find_object(exits[dir])))
	{
		if (! ob->open_door(doors[dir]["other_side_dir"], 1)) return 0;
	}

	doors[dir]["status"] &= (!DOOR_CLOSED);
	return 1;
}

varargs int close_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if (! mapp(doors) || undefinedp(doors[dir]))
		return notify_fail("这个方向没有门。\n");

	if ((doors[dir]["status"] & DOOR_CLOSED))
		return notify_fail(doors[dir]["name"] + "已经是关着的了。\n");

	exits = query("exits");
	if (! mapp(exits) || undefinedp(exits[dir]))
		error("Room: close_door: attempt to open a door with out an exit.\n");

	if (from_other_side)
		message("vision", "有人从另一边将" + doors[dir]["name"] + "关上了。\n", this_object());
	else
	if (objectp(ob = find_object(exits[dir])))
	{
		if (! ob->close_door(doors[dir]["other_side_dir"], 1)) return 0;
	}

	doors[dir]["status"] |= DOOR_CLOSED;
	return 1;
}

int check_door(string dir, mapping door)
{
	// If we have no responding door, assume it is correct.
	if (! mapp(doors) || undefinedp(doors[dir])) return 1;

	door["status"] = doors[dir]["status"];
	return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status)
{
	mapping d, exits, item_desc;
	object ob;

	exits = query("exits");
	if (! mapp(exits) || undefinedp(exits[dir]))
		error("Room: create_door: attempt to create a door without exit.\n");

	// Compact mode.
	if (stringp(data))
	{
		d = allocate_mapping(4);
		d["name"] = data;
		d["id"] = ({ dir, data, "door" });
		d["other_side_dir"] = other_side_dir;
		d["status"] = status;
	} else if (mapp(data))
		d = data;
	else
		error("Create_door: Invalid door data, string or mapping expected.\n");

	set("item_desc/【" + d["name"]+"】", (: look_door, dir :) );

	if (objectp(ob = find_object(exits[dir])))
	{
		if (! ob->check_door(other_side_dir, d))
			return;
	}

	if (! mapp(doors)) doors = ([ dir: d ]);
	else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
	if (! mapp(doors) || undefinedp(doors[dir])) return 0;
	else return doors[dir][prop];
}

int valid_leave(object me, string dir)
{
	if (mapp(doors) && !undefinedp(doors[dir]))
	{
		if (doors[dir]["status"] & DOOR_CLOSED)
			return notify_fail("你必须先把" + doors[dir]["name"] + "打开！\n");
	}
	return 1;
}

void setup()
{
	if (query("chat_room")) set("no_fight", 1);
	if (query("no_fight"))
	{
		set("no_steal", 1);
		set("no_beg", 1);
	}

	seteuid(getuid());
	this_object()->reset();
}

#if ENABLE_OPTIMIZE
varargs mixed set(mixed idx, mixed data)
{
	switch (idx)
	{
	case "short":
		return s_short = data;
	case "long":
		return s_long = data;
	case "no_fight":
		return s_fight = data;
	default:
		return ::set(idx, data);
	}
}

varargs mixed query(mixed idx, int raw)
{
	switch (idx)
	{
	case "short":
		return s_short;
	case "long":
		return s_long;
	case "no_fight":
		return s_fight;
	default:
		return ::query(idx, raw);
	}
}

varargs void delete(mixed idx)
{
	switch (idx)
	{
	case "short":
		s_short = 0;
		break;
	case "long":
		s_long = 0;
		break;
	case "no_fight":
		s_fight = 0;
		break;
	default:
		::delete(idx);
		break;
	}
}

varargs string short()
{
	return s_short;
}

varargs string long()
{
	return s_long;
}
#else
varargs string short()
{
	if (stringp(query("apply/short")))
		return query("apply/short");

	return query("short");
}

varargs string long()
{
	if (stringp(query("apply/long")))
		return query("apply/long");

       return query("long");
}
#endif

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
