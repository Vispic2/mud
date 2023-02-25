
#include <ansi.h>

inherit F_CLEAN_UP;
//by寒江雪
int main(object me, string arg)
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;
	string msg;
	string lx;
    string id=sprintf("%c",me->query("id")[0]);
    	
    if (me->is_fighting())
	    return notify_fail("忙乱中。\n");
	if (me->is_busy())
		return notify_fail("你正忙著呢。\n");
	if (me->is_ghost()) 
		return notify_fail("等你还了阳再说吧。\n"); 
	if (me->is_in_prison())   
		return notify_fail("你正在做牢呢。\n");
	if (! me->query("born"))
		return notify_fail("你还没有出生呢！\n");
	if (me->query("doing"))
		return notify_fail("你还想干什么？！\n");		
	if (environment(me)->query("no_magic"))
		return notify_fail("你发现这里有点古怪！\n");		
	
			
	if(!arg){						
    msg = ZJOBLONG+sprintf("你的房子有：\n");
    if(me->query("fangzi") < 1)
    {
    write("你还没有房子，可以前往天空城购买房子！\n");
    return 1;
    }else{
    msg +="\n"ZJOBACTS2+ZJMENUF(2,2,9,31);    
	files = list_dirs("/data/home/"+id+"/"+me->query("id")+"/hell/");	
	for(i=0;i<sizeof(files);i++)
	{
	file = "/data/home/"+id+"/"+me->query("id")+"/hell/"+files[i]+"";
		if (! (room = find_object(file)))
		{
		if (file_size(file)>=0)
		room = load_object(file);
		if(!room)
		{
	    tell_object(me,"你还没有房子"NOR"\n");
	    lx=HIW"你还没有房子";
		return 1;
		}
		}
		if(room)
		{			
		if(room->query("sleep_room")==1)
		lx=HIC"〖休息室〗";
	    else if(room->query("close_room")==1)
		lx=HIY"〖闭关室〗";
	    else if(room->query("practice_room")==1)
		lx=HIG"〖练功房〗";
	    else
		lx=HIW"〖普通房〗";
		msg +=""+room->query("short")+" "+lx+NOR":huijia "+room+""ZJSEP;
		}
	}		
	write(msg + "\n");	
	}
	return 1;
	}else{	
	if (me->is_fighting())
	    return notify_fail("忙乱中。\n");
	if (me->is_busy())
		return notify_fail("你正忙著呢。\n");
	if (me->is_ghost()) 
		return notify_fail("等你还了阳再说吧。\n"); 
	if (me->is_in_prison())   
		return notify_fail("你正在做牢呢。\n");
	if (! me->query("born"))
		return notify_fail("你还没有出生呢！\n");
	if (me->query("doing"))
		return notify_fail("你还想干什么？！\n");		
	if (environment(me)->query("no_magic"))
		return notify_fail("你发现这里有点古怪！\n");	
	if(!load_object(arg))
	    return notify_fail("没有这个对象！\n");	
	if(strsrch(file_name(load_object(arg)),"/data/")==-1)
	    return notify_fail("你不能去这里！\n");	
    me->move(arg);
    write("你来到了："+load_object(arg)->short()+"...\n");
    return 1;
	}
}

int help (object me)
{

	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
