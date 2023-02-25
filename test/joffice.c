//edit by jerry
//2008.11.17
/*
增加了单人副本的接口
by 笑世
*/
#include <ansi.h>
inherit NPC;

#define J_SYS "/test/j_sys"
int ask_job();
string ask_mj();

void create()
{

        set_name(HIW"一眉道人"NOR, ({ "yi mei", "dao shi" }));
        set("title", HIW"丧尸清理者"NOR);

        set("gender", "男性");
        set("age", 26);
        set("long","茅山派传人 一位小有名气的道士。\n");

	set("inquiry", ([ 
        	"幻心密洞" : (: ask_job :),
        	"仙武秘境" : (: ask_mj :),
   
            ])); 

        setup();
}

int ask_job()
{
	object me;
	object *team,jmem;
	int i,size;	
	me = this_player();
	team = me->query_team();//队伍的阵列
	size = sizeof(team);//取个数
	//删除旧的副本
	jmem = me->query_temp("room/jfbb_jmem");
	if(objectp(jmem))//清除标识
	{
		jmem->delete("user_id");
	}
	if(size > 1)//是否是队伍
	{
		tell_object(me,"幻心密洞只能单人进入。\n");
	}
		J_SYS->jfbb(me);//创建新的副本
	    return 1;
}

string ask_mj()
{
object me = this_player();
"adm/daemons/mjd"->playermove(me);
return "\n";
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
