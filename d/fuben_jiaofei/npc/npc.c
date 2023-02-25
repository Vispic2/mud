inherit NPC;
void finish(object who);

void create()
{
	set_name("匪徒", ({"fei"}));
	set("combat_exp", 1000);
	
	setup();
}

void init()
{
	object who = this_player();
	
	if(interactive(who))
	{
		this_object()->kill_ob(who);
		who->kill_ob(this_object());
	}
}

void die()
{
	object fb_mem, who, temp;
	object *team;
	
	who = this_object()->query_last_damage_from();
	fb_mem = who->query_temp("fb_mem");
	team = who->query_team();
	
	foreach(temp in team)
	{
		if(environment(temp) != environment(this_object()))
		{
			fb_mem->set("have_noplayer", 1);
			fb_mem->fuben_finish(who);
			::die();
			return ;
		}
	}
	if (!fb_mem->query("have_noplayer"))
    {
    	fb_mem->add("kill_count", 1);
    	message("shout", "你的队伍已经累计杀了" + fb_mem->query("kill_count") + "个匪徒。\n", team);
    	if(fb_mem->query("kill_count") == fb_mem->query("npc_amount"))
    	{
    		fb_mem->fuben_finish(who);
    	}
	}
	
	::die();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
