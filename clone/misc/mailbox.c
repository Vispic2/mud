// mailbox.c

inherit ITEM;
inherit F_SAVE;

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
	set_name("信箱", ({ "mailbox", "box" }) );
	set("long",
	HIG+"	      泥潭㊣精神：友情与爱情	  "+NOR+"\n\n"+HIC+"≡"+HIY+"──────────────────────────"+HIC+"≡"+NOR+"\n"+
		"  from		     :查看信箱中的信件。\n"+
		"  mail    <某人>	   :寄信给别人。\n"+
		"  forward <信件id> <某人>  :将某封信转寄给别人。\n"+
		"  read    <信件id>	 :阅读一封信件。\n"+
		"  discard <信件id>	 :丢弃一封信件。\n"+
 HIC+"≡"+HIY+"──────────────────────────"+HIC+"≡"+NOR+"\n \n");
	set("unit", "个");
	set("no_drop", 1);
	set("no_insert", 1);

	seteuid(getuid());
}

int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}

void init()
{

	if( this_player() && environment()==this_player() ) {
		set_owner( (string)this_player()->query("id") );
		this_player()->set_temp("mbox_ob", this_object());
		set_name( this_player()->name(1) + "的信箱", ({ "mailbox", "box" }) );
		add_action("do_mail", "mail");
		add_action("do_forward", "forward");
		add_action("do_from", "from");
		add_action("do_read", "read");
		add_action("do_discard", "discard");
	}
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
	if( !pointerp(mails) ) mails = ({ mail });
	else mails += ({ mail });
	save();
}

void send_mail(string rcvr, mapping mail)
{
       string *str01,base_dir,dir,rcvr1;
	object ppl, ob, mbx;
       rcvr1=rcvr;
       str01=explode(rcvr,"");
       base_dir=str01[0]; 
       dir="/data/user/"+base_dir+"/"+rcvr1+".o";       if(file_size(dir)<=0)
       {
	   write("没有这个人存在。\n");
		return;
       }
       else
       {
	    mbx=new(MAILBOX_OB);
	   if(find_player(rcvr1))
	   {
		ppl = find_player(rcvr1);
		mbx = ppl->query_temp("mbox_ob");
		mbx->set_owner(rcvr1);
		mbx->receive_mail(mail);
		tell_object(ppl,BOLD + "\n杜宽(Post officer)告诉你：有您的信！请到驿站来一趟...\n\n" + NOR);
	   }
	  else
	   {
		  mbx->set_owner(rcvr1);
		 
		  mbx->receive_mail(mail);
	   }
       }
}

int do_mail(string arg)
{
	mapping mail;

	if( this_player()!=environment() ) return 0;

	if( !arg || arg=="" )
		return notify_fail("你要寄信给谁？\n");

	mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": "无题",
		"to": arg,
		"time": time(),
		"text": ""
	]);
	write("信件标题：");
	input_to("get_mail_title", mail);
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("信件内容：\n");
	this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
	mail["text"] = str;
	write("您自己要留一份备份吗(y/n)？[n]");
	input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
	if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
	send_mail(mail["to"], mail);
	write("Ok.\n");
}

int do_from()
{
	int i;

	if( !pointerp(mails) || !sizeof(mails) ) {
		write("你的信箱中目前没有任何信件。\n");
		return 1;
	}
	write("你的信箱中现在共有 " + sizeof(mails) + " 封信件：\n\n");
	for(i=0; i<sizeof(mails); i++)
		printf("%4d %-50s 寄信人：%-20s\n",
			i+1, mails[i]["title"], mails[i]["from"] );
	write("\n");
	return 1;
}

int do_read(string arg)
{
	int num;
	num=file_size(query_save_file()+".o");
	this_player()->set("new_mail",num);
	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要读哪一封信？\n");

	if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	printf("信件标题：%s\n寄 信 人：%s\n\n%s\n",
		mails[num]["title"], mails[num]["from"], mails[num]["text"] );

	return 1;
}

int do_discard(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要丢弃哪一封信？\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("Ok.\n");

	return 1;
}

int do_forward(string arg)
{
	string dest;
	int num;
	mapping m;

	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("你要将哪一封信转寄给别人？\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"] + "/转寄自" + this_player()->query("name");
	m["to"] = dest;
	send_mail( dest, m );
	write("Ok.\n");

	return 1;
}

void owner_is_killed() { destruct(this_object()); }

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
