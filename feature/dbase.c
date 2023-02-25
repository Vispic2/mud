// dbase.c

#include <dbase.h>

inherit F_TREEMAP;

mapping dbase;
static mapping tmp_dbase;

static mixed default_ob;

mixed query_default_object() { return default_ob; }
void set_default_object(mixed ob)
{
	if( !geteuid() ) seteuid(getuid());
	default_ob = ob;
	ob->add("no_clean_up", 1);
}

mixed set(string prop, mixed data)
{
	string name,*props;
	object ob,room;

	if( !mapp(dbase) ) dbase = ([]);

	if( strsrch(prop, '/')!=-1 )
	{
		props = explode(prop, "/");
		if(props[0]=="exits")
		{
			if(stringp(name=data->query("short")))
				tell_room(this_object(),ZJEXIT+props[1]+":"+name+"\n");
		}
		return _set( dbase, explode(prop, "/"), data );
	}

	dbase[prop] = data;

	return dbase[prop];
}

varargs mixed query(string prop, int raw)
{
	mixed data;

	if( !mapp(dbase) ) return 0;

	if( undefinedp(dbase[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(dbase, explode(prop, "/"));
	else
		data = dbase[prop];

	if( undefinedp(data) && default_ob )
		data = default_ob->query(prop, 1);

	if( raw ) return data;

	return evaluate( data, this_object() );
}

int delete(string prop)
{
	string *props;

	if( !mapp(dbase) ) return 0;

	if( strsrch(prop, '/')!=-1 )
	{
		props = explode(prop, "/");
		if(props[0]=="exits")
		{
			tell_room(this_object(),ZJEXITRM+props[1]+"\n");
		}
		return _delete(dbase, props);
	}
	else {
		map_delete(dbase, prop);
		return 1;
	}
}

mixed add(string prop, mixed data)
{
	mixed old;
/* 修改回来了 经验潜能复原
	if(prop=="combat_exp"||prop=="potential")
		data = data*5;
*/
	if( !mapp(dbase) || !(old = query(prop, 1)) )
		return set(prop, data);

	if( functionp(old) )
		error("dbase: add() - called on a function type property.\n");

	return set(prop, old + data);
}

mapping query_entire_dbase()
{
	return dbase;
}

mixed set_temp(string prop, mixed data)
{
	if( !mapp(tmp_dbase) ) tmp_dbase = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( tmp_dbase, explode(prop, "/"), data );

	return tmp_dbase[prop] = data;
}

varargs mixed query_temp(string prop, int raw)
{
	mixed data;

	if( !mapp(tmp_dbase) ) return 0;

	if( strsrch(prop, '/')!=-1 )
		data = _query(tmp_dbase, explode(prop, "/"));
	else
		data = tmp_dbase[prop];

	if( functionp(data) && !raw )
		return (*data)( this_object() );
	else 
		return data;
}

int delete_temp(string prop)
{
	if( !mapp(tmp_dbase) ) return 0;

	if( strsrch(prop, '/')!=-1 )
		return _delete(tmp_dbase, explode(prop, "/"));
	else {
		map_delete(tmp_dbase, prop);
		return 1;
	}
}

mixed add_temp(string prop, mixed data)
{
	mixed old;

	if( !mapp(tmp_dbase) || !(old = query_temp(prop, 1)) )
		return set_temp(prop, data);

	if( functionp(old) )
		error("dbase: add_temp() - called on a function type property.\n");

	return set_temp(prop, old + data);
}

mapping query_entire_temp_dbase()
{
//	if( (previous_object() != this_object())
//	&&	(geteuid(previous_object()) != ROOT_UID) )
//		error("dbase: query_entire_temp_dbase() - must has root euid or be this_object().\n");

	return tmp_dbase;
}

nomask void set_dbase(mapping data)
{
	if (! is_root(previous_object()))
		return;

	if (! mapp(data))
		return;

	dbase = data;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
