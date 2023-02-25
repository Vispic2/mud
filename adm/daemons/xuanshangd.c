inherit F_DBASE;
inherit F_SAVE;

mapping xuanshang;

void create()
{
	seteuid(ROOT_UID);
	if( !restore() && !mapp(xuanshang) )
		xuanshang = ([]);
}

string query_save_file() { return DATA_DIR + "xuanshang"; }


mapping get_xuanshang() { return xuanshang; }

int add_xuanshang(string player_id, int money_amount)
{
	object player;

	player = find_player(player_id);

	if (!player && !userp(player))
		return 0;

	if (undefinedp(xuanshang[player_id]))
		xuanshang += ([ player_id : ({ player->query("name"), money_amount, }), ]);
	else
		xuanshang[player_id][1] += money_amount;

	save();
	return 1; 
}

void delete_xuanshang(string player_id)
{
	map_delete(xuanshang, player_id);
	save();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
