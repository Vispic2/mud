//
// master.c
//
//#pragma optimize
//#pragma save_binary

#include <config.h>
#include <localtime.h>

object connect(int port)
{
	object login_ob;
	mixed err;
     if (port == 5003){
        set_encoding("GBK");
    }
	err = catch(login_ob = new(LOGIN_OB));
  	if (err)
	{
		write("现在有人正在修改使用者连线部份的程式，请待会再来。\n");
		write(err);
		destruct(this_object());
	}
	login_ob->set("port",port);
	return login_ob;
}

// compile_object: This is used for loading MudOS "virtual" objects.
// It should return the object the mudlib wishes to associate with the
// filename named by 'file'.  It should return 0 if no object is to be
// associated.
mixed compile_object(string file)
{
	object daemon;

	if (daemon = find_object(VIRTUAL_D))
		return daemon->compile_object(file);
	else
		return 0;
}

// This is called when there is a driver segmentation fault or a bus error,
// etc.  As it's static it can't be called by anything but the driver (and
// master).
static void crash(string error, object command_giver, object current_object)
{
#if INSTALL_CRASH_SAVE
	object ob;
	string dump_dir;
	string user;
	string flogin, fuser;
	mixed lt;
#endif

	efun::shout("系统核心发出一声惨叫：哇—哩—咧—\n");
	efun::shout("系统核心告诉你：要当机了，自己保重吧！\n");
	//log_files("static/CRASHES", MUD_NAME + " crashed on: " + ctime(time()) +
		// ", error: " + error + "\n");
	if (command_giver)
		//log_files("static/CRASHES",
			// sprintf( "this_player: %O\n", command_giver));
	if (current_object)
		//log_files("static/CRASHES",
			// sprintf( "this_object: %O\n", current_object));

#if INSTALL_CRASH_SAVE
	lt = localtime(time());
	lt[LT_MON]++;
	dump_dir = sprintf(DUMP_DIR "%d-%d-%d/", lt[LT_YEAR], lt[LT_MON], lt[LT_MDAY]);
	foreach (ob in users())
	{
		reset_eval_cost();

		// backup user data to dump
		user = geteuid(ob);
		if (! stringp(user))
			continue;
		flogin = "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__;
		fuser  = "user/"  + user[0..0] + "/" + user + __SAVE_EXTENSION__;
		if (file_size(DATA_DIR + flogin) > 0 &&
		    file_size(DATA_DIR + fuser) > 0)
		{
			// exist in data, I will backup it to dump
			assure_file(dump_dir + flogin);
			assure_file(dump_dir + fuser);
			cp(DATA_DIR + flogin, dump_dir + flogin);
			cp(DATA_DIR + fuser,  dump_dir + fuser);
			//log_files("static/dump",
				// sprintf("backup user(%s) to dump\n", user));
		}
		ob->save();
	}
#endif
}

// Function name:   update_file
// Description:     reads in a file, ignoring lines that begin with '#'
// Arguements:      file: a string that shows what file to read in.
// Return:	  Array of nonblank lines that don't begin with '#'
// Note:	    must be declared static (else a security hole)
static string *update_file(string file)
{
	string *list;
	string str;
	int i;

	str = read_file(file);
	if (!str)
		return ({});

	list = explode(str, "\n");
	for (i = 0; i < sizeof(list); i++)
		if (list[i][0] == '#')
			list[i] = 0;

	list -= ({ 0 });
	return list;
}

// Function name:       epilog
// Return:	      List of files to preload
string *epilog(int load_empty)
{
	string *items;

	items = update_file(CONFIG_DIR + "preload");
	return items;
}

// preload an object
void preload(string file)
{
	if (objectp(find_object(file)))
		return;

	if (file_size(file + ".c") == -1)
		return;

	catch(load_object(file));
}

// Write an error message into a log file. The error occured in the object
// 'file', giving the error message 'message'.
void log_error(string file, string message)
{


    if (strsrch(message, "Warning")!=-1)
    return;//屏蔽warning类报错
    
	if (this_player(1)) efun::write("\n编译时段错误：" + message); else
	if (this_player()) tell_object(this_player(), "\n编译时段错误：" + message);

	efun::write_file(LOG_DIR + "log", message);
	
}

// save_ed_setup and restore_ed_setup are called by the ed to maintain
// individual options settings. These functions are located in the master
// object so that the local admins can decide what strategy they want to use.
int save_ed_setup(object who, int code)
{
	string file;
  
	if (! intp(code))
		return 0;

	file = user_path(getuid(who)) + ".edrc";
	rm(file);
	return write_file(file, code + "");
}

// Retrieve the ed setup. No meaning to defend this file read from
// unauthorized access.
int retrieve_ed_setup(object who)
{
	string file;
	    int code;
  
	file = user_path(getuid(who)) + ".edrc";
	if (file_size(file) <= 0)
		return 0;

	sscanf(read_file(file), "%d", code);
	return code;
}

// When an object is destructed, this function is called with every
// item in that room.  We get the chance to save users from being destructed.
void destruct_env_of(object ob)
{
	if (! userp(ob)) return;
	tell_object(ob, "你所存在的空间被毁灭了。\n");
	ob->move(VOID_OB);
}

// make_path_absolute: This is called by the driver to resolve path names in ed.
string make_path_absolute(string file)
{
	file = resolve_path((string)this_player()->query("cwd"), file);
	return file;
}

// called if a user connection is broken while in the editor; allows
// the mudlib to save the changes in an alternate file without modifying
// the original
string get_save_file_name(string fname)
{
	return fname + "." + time();
}

string get_root_uid()
{
	return ROOT_UID;
}

string get_bb_uid()
{
	return BACKBONE_UID;
}

string creator_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}

string domain_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}

string author_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}

// simulate the old behavior of the driver
string standard_trace(mapping error, int caught)
{
	int i, s;
	string res;
	object me;
	mixed *cmds;

	res = (caught) ? "错误讯息被拦截：" : "";
	res = sprintf("%s\n执行时段错误：%s\n程式：%s 第 %i 行\n物件：%s\n",
    		      res, error["error"],
		      error["program"], error["line"],
		      error["object"] ? file_name(error["object"]) : "0");

	if (! error["object"] && (me = this_player()))
	{
		res += sprintf("当前玩家：%s(%s) - %O  所在环境：%O\n",
			       me->name(1), me->query("id"), me, environment(me));
		cmds = me->query_commands();
		res += me->name(1) + "身上及四周的物品与所在的环境提供以下指令：\n";
		for(i = 0; i<sizeof(cmds); i++)
			res += sprintf("%-15s  %2d %O\n",
				       cmds[i][0], cmds[i][1], cmds[i][2]);

		res += sprintf("当前的命令：%O\n", me->query_last_input());
	}

	i = 0;
	s = sizeof(error["trace"]);
	if (! this_player(1) && this_player())
	{
		// filter error trace of messaged & chat command
		for (; i < s; i++)
		{
			string prog;
			prog = "/" + error["trace"][i]["program"];
			if (
			    ! sscanf(prog, "/cmds/chat/%*s") &&
			    prog != "/clone/user/chatter.c" &&
			    prog != F_COMMAND)
				break;
		}
	}

	for (; i < s; i++)
	{
		res = sprintf("%s呼叫来自：%s 的 %s() 第 %i 行，物件： %O\n",
			      res,
			      error["trace"][i]["program"],
			      error["trace"][i]["function"],
			      error["trace"][i]["line"],
			      error["trace"][i]["object"]);
	}
	return res;
}

// The mudlib runtime error handler.
string error_handler(mapping error, int caught)
{

	
	if (this_player(1))
	{
		this_player(1)->set_temp("error", error);
		tell_object(this_player(1), standard_trace(error, caught));
	} else
	if (this_player())
		tell_object(this_player(), standard_trace(error, caught));

	// whatever we return goes to the debug.log
	return standard_trace(error, caught);
	
	
}

// valid_shadow: controls whether an object may be shadowed or not
int valid_shadow(object ob)
{
	object pre;

	pre = previous_object();
	if (geteuid(pre) == ROOT_UID ||
	    sscanf(file_name(pre), "/shadow/%*s"))
	{
		return 1;
	}

	//log_files("shadow", sprintf("%O try to shadow %O failed.\n", pre, ob));
	return 0;
}

// valid_override: controls which simul_efuns may be overridden with
//   efun:: prefix and which may not.  This function is only called at
//   object compile-time
int valid_override( string file, string name )
{
	// simul_efun can override any simul_efun by Annihilator
	if (file == SIMUL_EFUN_OB || file == MASTER_OB)
		return 1;

	// Must use the move() defined in F_MOVE.
	if ((name == "move_object") && file != F_MOVE && file != F_COMMAND)
		return 0;

	if ((name == "destruct") && ! sscanf(file, "/adm/simul_efun/%s", file))
		return 0;

	//  may also wish to protect destruct, shutdown, snoop, and exec.
	return 1;
}

// valid_seteuid: determines whether an object ob can become euid str
int valid_seteuid(object ob, string str)
{
	if (find_object(SECURITY_D))
		return (int)SECURITY_D->valid_seteuid( ob, str );
	return 1;
}

// valid_socket: controls access to socket efunctions
int valid_socket(object eff_user, string fun, mixed *info)
{
	return 1;
}

// valid_asm: controls whether or not an LPC->C compiled object can use
//   asm { }
int valid_asm(string file)
{
	return 1;
}

// valid_compile: controls whether or not an file can be compiled
int valid_compile(string file)
{
	return file_valid(file) == 1;
}

// valid_hide: controls the use of the set_hide() efun, to hide objects or
//   see hidden objects
int valid_hide(object who)
{
	return 1;
}

// valid_object: controls whether an object loaded by the driver should
//   exist
int valid_object(object ob)
{
	return (! clonep(ob)) || inherits(F_MOVE, ob);
}

// valid_link: controls use of the link() efun for creating hard links
//   between paths
int valid_link(string original, string reference)
{
	return 0;
}

// valid_save_binary: controls whether an object can save a binary
//   image of itself to the specified "save binaries directory"
//   (see config file)
int valid_save_binary(string filename)
{
	return 1;
}

// valid_write: write privileges; called with the file name, the object
//   initiating the call, and the function by which they called it. 
int valid_write(string file, mixed user, string func)
{
	object ob;

	if (ob = find_object(SECURITY_D))
		return (int)ob->valid_write(file, user, func);

	return 0;
}

// valid_read: read privileges; called exactly the same as valid_write()
int valid_read(string file, mixed user, string func)
{
	object ob;

	if (ob = find_object(SECURITY_D))
		return (int)ob->valid_read(file, user, func);

	return 1;
}

string object_name(object ob)
{
	if (ob) return ob->name();
}

void create()
{
	write("master: loaded successfully.\n");
}

void check_daemons()
{
	string *sp;
	int i;

	sp = epilog(0);
	if (! sp) return;

	for (i = 0; i < sizeof(sp); i++)
		if (stringp(sp[i])) preload(sp[i]);
}

int valid_bind(object binder, object old_owner, object new_owner)
{
	object ob;

	if (ob = find_object(SECURITY_D))
		return (int)ob->valid_bind(binder, old_owner, new_owner);

	return 1;
}


string valid_database(object ob, string action, mixed *info)
{	
return "123456";   
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
