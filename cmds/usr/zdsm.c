// 自动师门 by name
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob,*obs;
	mapping q;
	string area;
	
	if (me->is_ghost()) 
    return notify_fail("等你还了阳再说吧。\n");                 
    if (me->is_in_prison())   
    return notify_fail("你正在做牢呢。\n");
    if( me->query("doing") )
    return notify_fail("你还想干什么？！\n");
    me->force_me("accept quest");    
    //by name 如果没有师门任务，自动回门派并且领取任务！
	if(!mapp(q=me->query("quest"))){
	me->force_me("recalle");
	me->force_me("quest cancel");
	foreach(ob in all_inventory(environment(me))){
	if(ob->is_quester()){
	me->force_me("quest "+ob->query("id"));
	return 1;
	}
	}
	return 1;
    }	   
	if (me->is_fighting()) 
	return notify_fail("你现在正在战斗！\n");
	if(q["type"]!="kill"){
    return notify_fail("你现在没有师门杀人任务，无需使用。\n");  
	}
	if(ob=find_living(q["id"])){
    sscanf(base_name(environment(ob)),"/d/%s/%*s",area);
    me->move(environment(ob));
    me->force_me("kill " + me->query("quest/id"));
    if(me->query("yqq")){
    me->force_me("yqq");
    tell_object(me,HIG"───────────────────────"NOR"\n");
    tell_object(me,HIG"───────秒杀师门限权 : "+(me->query("yqq")?"有":"无")+"────────"NOR"\n");
    tell_object(me,HIG"─────已开启自动使用(秒杀师门)──────"NOR"\n");
    tell_object(me,HIG"───────────────────────"NOR"\n");
    }else{
    tell_object(me,HIG"───────────────────────"NOR"\n");
    }
	}else
	tell_object(me,"无法自动到目标人物，可能是目标人物已被杀死或者消失了。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quest  这个指令可以用来向你的门派的掌门或世家长辈
领取任务，如果不加任何参数则显示出你当前的任务。
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
