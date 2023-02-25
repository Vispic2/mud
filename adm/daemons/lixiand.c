// closed.c

#pragma optimize
#pragma save_binary

#define LX_CMD	      "/cmds/usr/lixian"
inherit F_SAVE;

mapping closed_users = 0;

void load_all_users();

void create()
{
	seteuid(getuid());
	restore();
	set_heart_beat(10);
}

void remove()
{
	save();
}

void mud_shutdown()
{
	save();
}

string query_save_file()
{
	return DATA_DIR "lixiand";
}

mapping query_closed_users()
{
	return closed_users;
}

void user_closed(object user)
{

	if (! closed_users)
		closed_users = ([ ]);
	if (undefinedp(closed_users[user->query("id")]))
		closed_users += ([ user->query("id") : user->query("startroom") ]);
	else
		closed_users[user->query("id")] = user->query("startroom");
	save();
	user->save();
	set_heart_beat(3+random(3));
}

void user_opened(object user)
{
	user->delete("doings");
	if (mapp(closed_users))
	{
		map_delete(closed_users, user->query("id"));
		if (! sizeof(closed_users))
		{
			closed_users = 0;
			set_heart_beat(0);
		}
	}

	save();
	user->delete("startroom");
	user->save();
}

void heart_beat()
{
	load_all_users();
}

void continue_doing(object user_ob)
{
	int res;

	switch (user_ob->query("doings"))
	{
	
	case "lixian":
		res = LX_CMD->continue_breaking(user_ob);
		break;

	default:
		res = 0;
		return;
	}

	if (! res)
		user_opened(user_ob);
}

void load_all_users()
{
	string u;
	object login_ob;
	object user_ob;

	if (! mapp(closed_users))
		return;

	if (! LOGIN_D->can_login())
		return;

	set_heart_beat(3+random(3));
	foreach (u in keys(closed_users))
	{
		if (! objectp(user_ob = LOGIN_D->find_body(u)))
		{
			// load the user
			login_ob = new(LOGIN_OB);
			login_ob->set("id", u);
			if (! login_ob->restore())
			{
				destruct(login_ob);
				map_delete(closed_users, u);
				//log_files("log", sprintf("closed：没有玩家(%s)。\n", u));
				continue;
			}
	
			user_ob = LOGIN_D->make_body(login_ob);
			if (! user_ob)
			{
				destruct(login_ob);
				map_delete(closed_users, u);
				//log_files("log", sprintf("closed：无法生成玩家(%s)。\n", u));
				continue;
			}
	
			if (! user_ob->restore())
			{
				destruct(login_ob);
				destruct(user_ob);
				map_delete(closed_users, u);
				//log_files("log", sprintf("closed：无法读取玩家(%s)的档案。\n", u));
				continue;
			}

			// Setup the user and move he to the closing room
			catch(LOGIN_D->enter_world(login_ob, user_ob));
			if (! stringp(user_ob->query("doings")) || ! environment(user_ob))
			{
				destruct(login_ob);
				destruct(user_ob);
				map_delete(closed_users, u);
			}
			continue;
		}

		if (query_heart_beat(user_ob))
			continue;

		continue_doing(user_ob);
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
