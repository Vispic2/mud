#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "HTML精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "HTML精灵已经启动。");
	set_heart_beat(10);
}
int main(object me,string arg)
{
if(me->query("web"))
write(ZJOBLONG+ZJSIZE(25)+"http://"+NAME_PAY+":5004/mudh.html"+ZJBR+ZJSIZE(15)+HIG+ESA+"[u:http://"+NAME_PAY+":5004/mudh.html]MUD网站[点击跳转]"+NOR+"\n");
else
write(ZJOBLONG+ZJSIZE(25)+"hhttp://"+NAME_PAY+":5004/mudh.html "ZJBR"[MUD网站，游览器访问】"+NOR+"\n");
return 1;
}
void heart_beat()
{
string text;

printf(text+"\n");
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
