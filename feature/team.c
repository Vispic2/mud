// team.c

// team.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

static object leader, *team;

int set_leader(object ob)
{
	if (objectp(ob) && ob == this_object())
		error("set_leader: Cannot set this_object() as leader.\n");

	leader = ob;
}

object query_leader() { return leader; }

int follow_path(string dir)
{
	reset_eval_cost();
	command("go " + dir);
}

int follow_me(object ob, string dir)
{
	object me;

	me = this_object();
	if (! living(me) || ob == me) return 0;

	if (ob == leader)
	{
		// 跟着别人走
		if (ob->query("env/no_follow") &&
		    (! arrayp(team) || ob != team[0]) &&
		    me->query_dex() / 2 + random(me->query_dex()) < ob->query_dex())
		{
			tell_object(me, ob->name() +
				    "走得好快，你一疏神就跟不上了。\n");
			return 0;
		}
		tell_object(me, "你跟着"+ob->name() + "一起走.....\n");
		return follow_path(dir);
	}
}

int fly_me(object ob, string dir)
{
	object me;

	me = this_object();
	if (! living(me) || ob == me) return 0;

	if (ob == leader)
	{
		if (ob->query("env/no_follow") && (! arrayp(team) || ob != team[0]))
		{
			tell_object(me, ob->name() + "飞得好快，你一疏神就跟不上了。\n");
			return 0;
		}
		tell_object(me, "你跟着"+ob->name() + "一起飞.....\n");
		me->force_me("fly " + dir);
		return 1;
	}
}
int flyto_me(object ob, string dir)
{
	object me;

	me = this_object();
	if (! living(me) || ob == me) return 0;

	if (ob == leader)
	{
		if (ob->query("env/no_follow") && (! arrayp(team) || ob != team[0]))
		{
			tell_object(me, ob->name() + "飞得好快，你一疏神就跟不上了。\n");
			return 0;
		}
		tell_object(me, "你跟着"+ob->name() + "一起飞.....\n");
		me->force_me("flyto " + dir);
		return 1;
	}
}
int recall_me(object ob, string dir)
{
	object me;

	me = this_object();
	if (! living(me) || ob == me) return 0;

	if (ob == leader)
	{
		if (ob->query("env/no_follow") && (! arrayp(team) || ob != team[0]))
		{
			tell_object(me, ob->name() + "飞得好快，你一疏神就跟不上了。\n");
			return 0;
		}
		tell_object(me, "你跟着"+ob->name() + "一起飞.....\n");
		me->move(dir);
		return 1;
	}
}


int add_team_member(object ob)
{
	if (ob == this_object()) return 0;

	if (arrayp(team))
	{
		team -= ({ 0 });
		if (member_array(ob, team) == -1)
		{
			team += ({ ob });
			for (int i = sizeof(team) - 1; i >= 0; i--)
				team[i]->set_team(team);
		} else
			return 0;
	} else
	{
		team = ({ this_object(), ob });
		ob->set_team(team);
	}

	return 1;
}

int have_team_member(object ob)
{
	return arrayp(team) && (member_array(ob, team) != -1);
}

int is_team_leader()
{
	if(!arrayp(team)) return 0;
	if(sizeof(team)<1) return 0;
	return team[0] == this_object();
}

int set_team(object *t)
{
	team = t;
	if (arrayp(t) && sizeof(t) > 1 && this_object() != t[0])
		set_leader(t[0]);
}

int set_team_leader(object ob)
{
	int i;
	if( !arrayp(team) || sizeof(team)<1 ) return 0;
	if (this_object()!=team[0]) return 0;	
	team -= ({ ob });
	team = ({ ob })+team;
	for(i=0;i<sizeof(team);i++)
	{
		team[i]->set_team(team);
	}
	return 1;
}

varargs int dismiss_team(object ob)
{
	int i;

	if (! arrayp(team)) return 0;
	
	if (! ob)
	{
		team -= ({ 0 });
		if (team[0] == this_object())
		{
			for (i = 1; i < sizeof(team); i++)
			{
				team[i]->set_team(0);
				team[i]->set_leader(0);
			}
		} else
		{
			for (i = 0; i < sizeof(team); i++)
			{
				team[i]->dismiss_team(this_object());
			}
		}
		team = 0;
	} else
	{
		if (ob->query_leader() == team[0])
			ob->set_leader(0);
		team -= ({ ob });
	}

	return 1;
}

object *query_team()
{
	return team;
}


/*
#include <command.h>
#include <dbase.h>
#include <origin.h>

static object leader, *team;

int set_leader(object ob)
{
	if (objectp(ob) && ob == this_object())
		error("set_leader: Cannot set this_object() as leader.\n");

	leader = ob;
}

object query_leader() { return leader; }

int follow_path(string dir)
{
	reset_eval_cost();
	command("go " + dir);
}

int follow_me(object ob, string dir)
{
	object me;

	me = this_object();
	if (! living(me) || ob == me) return 0;

	if (ob == leader)
	{
		// 跟着别人走
		if (ob->query("env/no_follow") &&
		    (! arrayp(team) || ob != team[0]) &&
		    me->query_dex() / 2 + random(me->query_dex()) < ob->query_dex())
		{
			tell_object(me, ob->name() +
				    "走得好快，你一疏神就跟不上了。\n");
			return 0;
		}
		return follow_path(dir);
	}
}

int add_team_member(object ob)
{
	if (ob == this_object()) return 0;

	if (arrayp(team))
	{
		team -= ({ 0 });
		if (member_array(ob, team) == -1)
		{
			team += ({ ob });
			for (int i = sizeof(team) - 1; i >= 0; i--)
				team[i]->set_team(team);
		} else
			return 0;
	} else
	{
		team = ({ this_object(), ob });
		ob->set_team(team);
	}

	return 1;
}

int have_team_member(object ob)
{
	return arrayp(team) && (member_array(ob, team) != -1);
}

int is_team_leader()
{
	if(!arrayp(team)) return 0;
	if(sizeof(team)<1) return 0;
	return team[0] == this_object();
}

int set_team(object *t)
{
	team = t;
	if (arrayp(t) && sizeof(t) > 1 && this_object() != t[0])
		set_leader(t[0]);
}

int set_team_leader(object ob)
{
	int i;
	if( !arrayp(team) || sizeof(team)<1 ) return 0;
	if (this_object()!=team[0]) return 0;	
	team -= ({ ob });
	team = ({ ob })+team;
	for(i=0;i<sizeof(team);i++)
	{
		team[i]->set_team(team);
	}
	return 1;
}

varargs int dismiss_team(object ob)
{
	int i;

	if (! arrayp(team)) return 0;
	
	if (! ob)
	{
		team -= ({ 0 });
		if (team[0] == this_object())
		{
			for (i = 1; i < sizeof(team); i++)
			{
				team[i]->set_team(0);
				team[i]->set_leader(0);
			}
		} else
		{
			for (i = 0; i < sizeof(team); i++)
			{
				team[i]->dismiss_team(this_object());
			}
		}
		team = 0;
	} else
	{
		if (ob->query_leader() == team[0])
			ob->set_leader(0);
		team -= ({ ob });
	}

	return 1;
}

object *query_team()
{
	return team;
}
*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
