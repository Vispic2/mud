//edit by jerry
//2008.11.17
/*
增加了单人副本的接口
*/
#include <ansi.h>
inherit NPC;

#define J_SYS "/d/jfjwm/sys/j_sys"
string ask_job();

void create()
{

	set_name(HIW"陈真"NOR, ({ "chen zhen" }));
	//set("title", HIC"道高一尺"NOR);

	set("gender", "男性");
	set("age", 30);
	set("long","大侠霍元甲的徒弟，为发扬中华武术，特地联系了各大门派的精英弟子前来精武门，与各路英雄一起切磋武学技艺。\n");
	
	set("max_qi", 57500);
	set("max_jing", 55000);
	set("max_jingli", 54000);
	set("jingli", 54000);
	set("max_neili", 59999);
	set("neili", 59999);
	set("jiali", 150);
	set("combat_exp", 43200000);
	set("score", 1200000);

	set_skill("force", 600);
	set_skill("taiji-shengong", 600);
	set_skill("wudang-xinfa", 600);
	set_skill("dodge", 600);
	set_skill("tiyunzong", 600);
	set_skill("unarmed", 600);
	set_skill("taiji-quan", 600);
	set_skill("strike", 600);
	set_skill("wudang-zhang", 600);
	set_skill("hand", 600);
	set_skill("paiyun-shou", 600);
	set_skill("parry", 600);
	set_skill("sword", 600);
	set_skill("wudang-jian", 600);
	set_skill("taiji-jian", 600);
	set_skill("blade", 600);
	set_skill("taiji-dao", 600);
	set_skill("taoism", 600);
	set_skill("literate", 600);
	set_skill("medical", 600);
	set_skill("liandan-shu", 600);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("hand", "paiyun-shou");
	map_skill("strike", "wudang-zhang");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("blade", "taiji-dao");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");
	
	set("inquiry", ([ 
		"精武演练" : (: ask_job :),
		])); 

	setup();
}


string ask_job()
{	int vlv;
	object ob;
	object me = this_player();
	
	write(ZJOBLONG"精武演练每日只能进行一次。在非战斗状态可以通过【回客栈】按钮离开。如果"+RANK_D->query_respect(me)+"确定进入，请选择演练模式，然后输入一个适合自己的强弱系数：\n"
		ZJOBACTS2+ZJMENUF(1,1,8,30)+"被动攻击模式（弟子不主动攻击，经验会减半）:jwyl 0"+ZJSEP+"主动攻击模式（弟子主动攻击玩家）:jwyl 1\n");

	return "精武演练每日只能进行一次，不管进与不进，当天不能再次进入,切记切记！\n";
}

int do_decide(string arg)
{
	object me,ck,env;
	object *team,jmem;
	int i,size,wjjy=0;	
	int zd,xs;
	
	me = this_player();

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
	
	if (time()/86400 - me->query("jwm")/86400 ==0){
		if(me->query("id") != "xajha"){
			tell_object(me,HIW"陈真"CYN"摇了摇头对你说道：“精武演练一天只能试炼一次，你还是明天再来吧。”\n"NOR);
			return 1;
		}
	}
	
	if(sscanf(arg,"%d %d", zd, xs) == 2){
		
		if(zd != 0 && zd != 1 ){
			return notify_fail("参数错误，被动模式第二个参数为：0 ，主动模第二个参数为：1。\n");
		}
		
		if(xs<1 || xs > 200){
			return notify_fail(HIR"参数错误，弟子的强弱系数必须在1-200之间。\n"NOR);
		}
		
		team = me->query_team();	//队伍的阵列
		size = sizeof(team);		//取个数	
		
		if(size > 1){			
			if(!me->is_team_leader()) return notify_fail("组队模式要队长来找我交流，你还是一边待着吧。\n");
			env = environment();
			
			for(i=0; i<size; i++){
				if(time()/86400 - team[i]->query("jwm")/86400 == 0){
					message_vision(HIC"你队伍中的"+team[i]->query("name")+"今天已经演练过了，请重新组队。\n"NOR, this_object());
					return 1;
				}
				
				if(environment(team[i]) != env)
				{
					message_vision(HIR"你队伍中的"+team[i]->query("name")+"没有看到他人呢，必须所有队员在场才能进入。\n"NOR, this_object());
					return 1;
				}			
				
				if(!team[i] || !playerp(team[i]) || !living(team[i]))
				{
					message_vision(HIY"【一个江湖】正在为你制造副本时检查条件不满足，请调整队伍重试......\n"NOR, this_object());
					return 1;//continue;
				}
		
				if(wjjy < team[i]->query("combat_exp")){
					wjjy = team[i]->query("combat_exp");
					ck = team[i];
				}
			}
			
			for(i=0; i<size; i++){
				team[i]->set("jwm", time());
			}
			
			J_SYS->jfjwm(ck,team,zd,xs);//创建新的副本	
			
		}else{
			me->set("jwm", time());
			J_SYS->jfjwm(me,0,zd,xs);//创建新的副本			
		}
		return 1;
	}
	
	if(arg){
		if(arg == "0" || arg == "1" ){
			write(INPUTTXT("设置弟子的强弱系数：","jwyl "+arg+" $txt#")+"\n");
		}else{
			return notify_fail("参数错误，被动模式第二个参数为：0 ，主动模第二个参数为：1。\n");
		}		
	}
	
	return 1;
}

void init()
{	
	object ob;
	
	::init();
	
	add_action("do_decide", "jwyl");
	
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
	case 0:
		say(query("name")+"：我们中国人不是东亚病夫，我们中国一定能强大。\n");
		break;
	case 1:
		say(query("name")+"：历来强盗要侵入，最终必送命。万里长城永不倒，千里黄河水涛涛。\n");
		break;
	case 2:
		say(query("name")+"：江山秀丽叠彩锋岭，问我国家哪像染病。冲开血路挥手上吧，要致力国家中兴。\n");
		break;
	}
}


















/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
