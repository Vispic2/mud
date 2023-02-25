// by name QQ：3468713544
inherit ROOM;
#define PAT "/log/adm/mrt"
static int ming;
void create()
{
	set("short", "名人堂"); 
	set("channel_id", "名人堂");
	set("long", "行走江湖实力为尊，亮出你的实力，讲实力载入武林史册吧！\n");
	set("no_fight", 1);
	set("exits", ([	
		"north" : __DIR__"wumiao",
		"east" : __DIR__"beidajie1",
		
	]));
	set("objects", ([ 
		"/d/city/npc/fuwuyuan.c" : 1, 
	  
	]));
	set("action_list",([
		HIY"江湖留名"NOR:"mrt",		
	]));	
	set("mrt",1);  //默认强度100%
	set_heart_beat(20);
	setup();
}
void init()
{
    add_action("mrt_kill","kills");
}
int mrt_kill(string arg)
{
mapping skill;
string skills,msg;
object where,npc,me,room;
int lvl,last,nd,i;

me=this_player();
last = me->query("mrt_day_time");	
where = environment(me);

if (!arg)
{
msg = "请选择挑战层次：\n";
msg += ZJOBACTS2+ZJMENUF(3,3,9,32);
for(i=0;i<=me->query("mrt/nd");i++){
msg+="第"+i+"层:kills "+i+""ZJSEP;		
}
msg=ZJOBLONG+msg;
msg+="\n";
write(msg);
}else{	

if(me->query("combat_exp")<1000000)
return notify_fail(HIR"你的经验不足100W，没有资格挑战名人堂高手。\n"NOR);	
if(me->query_skill("force",1)<180)
return notify_fail(HIR"你的内功等级不足180级，没有资格挑战名人堂高手。\n"NOR);	
 if(time()/3600 == last/3600)
	 return notify_fail("你刚才挑战过名人堂高手了，歇息一下再来吧！\n");	

// if(time()/86400 == last/86400)
// return notify_fail("你今天已经挑战过名人堂高手了，明天再来吧！\n");
/*
{
write("开始使用免费次数挑战。\n");
}else{
if(me->query("mingrt/cishu")){
me->add("mingrt/cishu",-1);  //扣次数
}else{
return notify_fail("你今天已经挑战过名人堂高手了，明天再来吧！\n");
}
}
*/



sscanf(arg,"%d",nd);
if(me->query("mrt/nd")<nd)
return notify_fail("你还没有挑战过这层呢。。\n");	
me->set("mrtnd",nd);
lvl=me->query_skill("force",1)+(me->query_skill("force",1)*query("mrt"))+(me->query_skill("force",1)*nd);
//NPC与ROOM	
npc=new("/cmds/npc");
room=new("/d/city/mrtroom");
skill=npc->query_skills();
//根据强度来设置高手等级，基本属性
    npc->set("qi",to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_qi", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("eff_qi", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("eff_jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));	
	npc->set("jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));	
	npc->set("neili", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_neili", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));    
	npc->set("jingli", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_jingli", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));		 
	npc->set("combat_exp", to_int(10000*me->query_skill("force",1)+((me->query_skill("force")*10000)*query("mrt"))));	
	npc->set_temp("apply/attack", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/damage", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/defence",to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/armor", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
    npc->set_temp("apply/unarmed_damage",to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));      
    //设置技能   
    foreach(skills in keys(skill)){
    npc->set_skill(skills,to_int(lvl));
   }
 npc->move(room);
 me->move(room);
 me->set("mrt_day_time",time());
 }
 return 1;

}
//30分钟随机一下强度
void heart_beat()
{
float qd;
mixed *sj;
sj = localtime(time());
qd=1+random(10);
if(!ming&&(sj[1]%30==0)){
ming=1;
set("mrt",qd/10);
}else
if(sj[1]==10||sj[1]==40){
ming=0;
}
//每轮7天
if(sj[3]%7==0&&sj[2]==1&&sj[1]==1&&sj[0]==1)
{
rm("/log/adm/mrt");
}  
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
