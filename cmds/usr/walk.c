// walk.c
inherit F_CLEAN_UP; 
#include "/d/rw.h"
#define PATH_D  "/adm/daemons/pathd.c"

int walk(object me,string *walks,string arg,mixed br,int i);
int main(object me, string arg)
{
        mixed a;
        mixed br;
        string str = "",*walks;
        	if (! me->query("born"))
		return notify_fail("你还没有出生呐？\n");
		//if(me->query("youkun") <1)
//	return notify_fail("涉世未深，还不能寻路。\n");

		if( !arg) 
		return notify_fail(INPUTTXT("自动寻路，输入地名或者人名，目前只有部分位置库","walk $txt#")+"\n");

if (where[arg]&&!me->is_busy()||arg=="师傅")
{
string name;
if(arg=="师傅"&&me->query("family/master_name"))
name= where[me->query("family/master_name")];
else
name = where[arg];
me->move(name);
me->start_busy(1);
tell_object(me,"你因为长期赶路，已气喘吁吁，忙乱不已！\n");
return 1;
}
        if( environment(me)->is_chat_room() ) 
        return notify_fail("聊天室内不能使用寻路功能！\n");
        if( sscanf(base_name(environment(me)), "/fuebn/%*s") )
        return notify_fail("副本里禁止使用walk寻路功能 ....\n");
        if( !is_chinese(arg) )
        return notify_fail("指令格式：walk <中文地址>\n");
        if(me->query_temp("start_walk")==1)
        return notify_fail("正在寻路中，请等待执行完成\n");
        if (me->is_ghost())
		return notify_fail("你还是等还了阳再说吧。\n");
        if (me->is_busy())
        return notify_fail("你还是先停下手头里的事情再说吧！\n");
        me->set_temp("last_walk", time());
        a = PATH_D->search_for_path(me, arg);
        if( !a || a == 1) {
                me->set_temp("last_walk", time()+10);
                write("没有这个地方，或者这个地方离这里超过规定的距离限制。\n");
                return 1;
        }
        write(arg+"路径搜索完成，共"+sizeof(a[1])+"步，路线为：\n");
        for( int i = 0;i < sizeof(a[1]);i++ ){
                str    += a[1][i] + ";";
        }
        str = str[0..<2]; 
        write(str+"\n");//输出路线
        br = me->query("env/brief");
        me->set("env/brief", 1);
        me->set_temp("start_walk",1);
        walks = explode(str,";");
        call_out("walk",1,me,walks,arg,br,0);
        return 1;
}
//by name 延迟寻路
int walk(object me,string *walks,string arg,mixed br,int i)
{
if(i>(sizeof(walks)-1)){
me->delete_temp("start_walk");
write("已抵达指定房间"+arg+"......\n");
return 1;
}
tell_object(me,ZJFORCECMD(walks[i]));
i+=1;
me->set("env/brief", br);
call_out("walk",1,me,walks,arg,br,i);
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
