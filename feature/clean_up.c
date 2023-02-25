// clean_up.c

int clean_up()
{
	object *inv;
	int i;

	if (! clonep() && this_object()->query("no_clean_up")) return 1;

	if (interactive(this_object())) return 1;

	if (this_object()->query_temp("quest_ob"))
		return 1;

	if (environment()) return 1;

	inv = all_inventory();
	for (i = sizeof(inv) - 1; i >= 0; i--)
		if (interactive(inv[i]) ||
		    inv[i]->query_temp("quest_ob") ||
		    inv[i]->is_stay_in_room()) return 1;

	destruct(this_object());
	return 0;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
