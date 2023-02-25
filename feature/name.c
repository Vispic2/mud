// name.c

#include <ansi.h>
#include <dbase.h>
#include <condition.h>

static string *my_id;

varargs void set_name(string name, string *id)
{
	string fullname;

	if (! stringp(name))
	{
		if (! stringp(fullname = query("surname")))
			fullname = "";

		if (stringp(query("purename")))
			fullname += query("purename");

		if (fullname == "")
			fullname = "无名氏";

		set("name", fullname);
	}
	else
	{
		set("name", name);
	}

	if (pointerp(id))
	{
		set("id", id[0]);
		my_id = id;
	}
}

int id(string str)
{
	string *applied_id;

	if (! str) return 0;
	if (this_object()->is_character() && this_player() &&
	    ! this_player()->visible(this_object())) return 0;

	if (my_id && member_array(str, my_id) != -1)
		return 1;
	else
		return 0;
}

string real_id()
{
	object *inv,obj;
	int i,j;

	obj=this_object();

	if(!environment(obj))
		return obj->query("id");

	inv = all_inventory(environment(obj));
	inv = filter_array(inv, (: $1->query("id")==$2->query("id") :),obj);
	
	for(i=0;i<sizeof(inv);i++)
	{ 
		if(obj== present(inv[i]->query("id")+" "+(i+1),environment(obj)))
		{
			j=i+1;
			break;
		}
	}
	if(j==1)
		return obj->query("id");
	else
		return obj->query("id")+" "+j;
}

string *parse_command_id_list()
{
	string *applied_id;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) )
		return applied_id;
	else
		return my_id;
}

varargs string name(int raw)
{
	string str, *mask;
	
	if (! raw && sizeof(mask = query_temp("apply/name")))
		return mask[sizeof(mask)-1];
	else
	{
		if (stringp(str = query("name")))
			return str;
		else
			return file_name(this_object());
	}
}

varargs string short(int raw)
{
	string str;
	
	if (raw || ! stringp(str = query("short")))
		str = name(raw) + "(" + capitalize(this_object()->real_id()) + ")";
	return str;
}

varargs string long(int raw)
{
	string str, extra, *mask;
	
	if (! raw && sizeof(mask = query_temp("apply/long")))
		str = mask[sizeof(mask)-1];
	else
	if (! stringp(str = query("long")))
		str = short(raw) + "。\n";

	if (stringp(extra = this_object()->extra_long()))
		str += extra;

	return str;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
