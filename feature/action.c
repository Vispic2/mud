// action.c
static mixed busy, interrupt;
static mapping override;

void add_busy(int new_busy)
{
	if (!intp(new_busy))
		error("action: Invalid busy action type.\n");
	if (intp(busy))
	{
		if (new_busy > 1 && random(10) < 4 && this_object()->query("character") == "狡黠多变")
			new_busy--;
		busy += new_busy;
	}
	set_heart_beat(1);
}

void delete_busy(int new_busy)
{

	if (!intp(new_busy))
		error("action: Invalid busy action type.\n");
	if (intp(busy))
	{
		busy=0;
	}
	set_heart_beat(1);
}


void set_busy(int new_busy)
{

	if (!intp(new_busy))
		error("action: Invalid busy action type.\n");
	if (intp(busy))
	{
	busy=new_busy;
	}
	set_heart_beat(1);
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	int hubo;
	object me;

	if (! new_busy) return;
	if (! intp(new_busy) && ! functionp(new_busy))
		error("action: Invalid busy action type.\n");

	if (! objectp(me = this_object())) return;
	if (intp(new_busy))
	{
		if (functionp(busy))
			//error("action: busy conflit.\n");

		if (new_busy > 1 && random(10) < 4 &&
		    me->query("character") == "狡黠多变")
			new_busy--;
	}

	if(intp(new_busy)&&intp(busy)&&new_busy<busy);
	else busy = new_busy;
	if (! intp(new_interrupt) && ! functionp(new_interrupt))
		error("action: Invalid busy action interrupt handler type.\n");
	interrupt = new_interrupt;
	set_heart_beat(1);
}

nomask mixed query_busy() { return busy; }
nomask int is_busy() { return busy != 0; }

void continue_action()
{
	if (intp(busy) && (busy > 0))
	{
		busy--;
		if(playerp(this_object()))
		
			tell_object(this_object(),""HIW+"忙乱中，剩余("+busy+")秒\n"NOR);
		return;
	} else
	if (functionp(busy))
	{
		if (! evaluate(busy, this_object()))
		{
			busy = 0;
			interrupt = 0;
		}
	} else
	{
		busy = 0;
		interrupt = 0;
	}
}

void interrupt_me(object who, mixed how)
{
	mixed bak;

	bak = busy;
	busy = 0;

	if (! bak) return;

	if (intp(bak) && intp(interrupt))
	{
		if (bak < interrupt)
			return;

		if (intp(how) && how > 0)
		{
			// reduce busy
			bak -= how;
			if (bak < 0) return;
		}
	} else
	if (functionp(interrupt))
	{
		if (evaluate(interrupt, this_object(), who, how))
		{
			bak = 0;
			interrupt = 0;
		}
	} else
	{
		bak = 0;
		interrupt = 0;
	}

	busy = bak;
}

int start_call_out(function fun, int delay)
{
	if (wiz_level(this_object()) > 0)
		call_out("eval_function", delay, fun);
	else
		call_out("eval_function", delay, bind(fun, this_object()));
	return 1;
}

void eval_function(function fun) { evaluate(fun); }

nomask int set_override(string index, function fun)
{
	if (! override)
		override = ([ ]);

	override[index] = bind(fun, this_object());
	return 1;
}

// only root & (admin) can called me
nomask mixed query_override(string index)
{
	if (! index) return override;
	if (! override) return 0;
	return override[index];
}

// others call me to run the override function, when I return
// zero, the caller will run old execution continue.
nomask int run_override(string index)
{
	function fun;

	if (! override || ! functionp(fun = override[index]))
		return 0;

	map_delete(override, index);
	if (! sizeof(override)) override = 0;
	return (*fun)(this_object());
}

// remove override function
nomask void delete_override(string index)
{
	if (! override) return;
	map_delete(override, index);
	if (! sizeof(override)) override = 0;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
