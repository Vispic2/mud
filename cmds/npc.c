#include <ansi.h>
inherit CLASS_D("generate") + "/chinese";

void create()
{
	
	::create();
	set("gender", "男性" );
	set("age", 18);
	set("long", "这是名人堂其中一个高手！");
	
	
}

int accept_kill(object ob)
{
    object me=this_player();
	set("mrt/sj",time());
	command("say 那就来吧！。");
	return 1;
}

int accept_fight(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_hit(object ob)
{

   return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_ansuan(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_touxi(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}

void die()
{
int times;
int exp,pot,mar;
object me,obj;
me=this_object()->query_last_damage_from();
times=time()-query("mrt/sj");

//me->set("mrt/sj",times);
me->add("mrt/nd",1);  //增加强度

exp=10000+random(1000);
me->add("combat_exp", exp);
pot=10000+random(500);
me->add("potential", pot);
mar=10000+random(250);
me->add("experience", mar);	
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，你获得了："+exp+"点经验，"+pot+"点潜能，"+mar+"点实战！\n");

if(me->query("mrtnd")>3&&1==random(2)){
if(3==random(10)){
obj=new("/d/city/book/jin_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}else
if(6==random(10)){
obj=new("/d/city/book/yan_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}else
if(9==random(10)){
obj=new("/d/city/book/chun_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}
}else
if(me->query("mrtnd")>5&&1==random(2)){
if(2==random(10)){
obj=new("/d/city/book/yuan_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}else
if(4==random(10)){
obj=new("/d/city/book/wan_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}else
if(6==random(10)){
obj=new("/d/city/book/ba_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}else
if(8==random(10)){
obj=new("/d/city/book/zui_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}else
if(10==random(12)){
obj=new("/d/city/book/yin_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}else
if(11==random(11)){
obj=new("/d/city/book/bumieti_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}else
if(12==random(14)){
obj=new("/d/city/book/ru_sui");
obj->move(me);
tell_object(me,"恭喜你挑战名人堂第"+me->query("mrtnd")+"层成功，意外的获得了："+obj->name()+"！！！\n");
}
}



write_file("/log/adm/mrt",sprintf("%s=%d\n",me->name(),times));	
me->move("/d/city/mingrt");
message("channel:chat",HBRED"【名人堂】"HBRED""+me->name()+"挑战本轮名人堂胜利！\n"NOR,users());	
shout(HBRED""+me->name()+"挑战本轮名人堂胜利！"NOR"\n");	
return ::die();
}

void unconcious()
{
	die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
