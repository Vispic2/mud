
#include <ansi.h>

inherit ITEM;

void clean_me()
{
	return;
}

mapping att_lv = ([
	"普通[1节爆竹]":1,
	"强力[5节爆竹]":5,
	"重击[25节爆竹]":25,
]);

string *ob_list = ({
    "/clone/shizhe/cagate",
	    "/clone/shizhe/cjade",
	    "/clone/shizhe/cdiamond",
	    "/clone/shizhe/ccrystal",
        "/clone/shizhe/cagate",
	    "/clone/shizhe/cjade",
	    "/clone/shizhe/cdiamond",
		"/clone/shizhe/ccrystal",
        "/clone/vip/hantie",
		"/clone/vip/wujins",		
		"/clone/shizhe/qiandai",
		"/clone/shizhe/qiandai",				
		"/clone/gift/jinkuai",
		"/clone/vip/puti-zi",
		"/clone/vip/puti-zi",		
		"/clone/vip/tianxiang",	
        "/clone/vip/tianxiang",        
		"/clone/vip/fushougao",
		"/clone/vip/fushougao",               
		"/clone/vip/hua5",
		"/clone/vip/hua5",              
        "/clone/vip/tianling",
        "/clone/vip/tianling",
        "/clone/vip/tianling",       
       "/clone/vip/jinsha",
       "/clone/vip/jinsha",
        "/clone/vip/jinsha",          
        "/clone/vip/putao",
        "/clone/vip/putao",
        "/clone/vip/putao",                
		"/clone/vip/dan_chongmai4",	
		"/clone/vip/dan_chongmai3",				
		"/clone/vip/dan_chongmai2",
		"/clone/vip/dan_chongmai2",		
		"/clone/vip/dan_chongmai1",
		"/clone/vip/dan_chongmai1",
		"/clone/vip/dan_chongmai1",				
		"/clone/vip/book_tianfu",
		"/clone/vip/book_tianfu",
		"/clone/vip/book_tianfu",		
		"/clone/vip/book_wuliang",
		"/clone/vip/book_wuliang",
		"/clone/vip/book_wuliang",		
		"/clone/vip/lingzhi",
		"/clone/vip/lingzhi",
		"/clone/vip/lingzhi",		
		"/clone/vip/lingzhi2",
		"/clone/vip/lingzhi2",
		"/clone/vip/lingzhi2",		
		"/clone/vip/build_ling",
		"/clone/vip/build_ling",
		"/clone/vip/cjj",
	    "/clone/vip/dan_chongmai1",
	    "/clone/vip/cjj",
	    "/clone/vip/dan_chongmai1",
	    "/clone/vip/dan_chongmai2",
	    "/clone/vip/dan_chongmai2",
	    "/clone/vip/dan_chongmai3",   
	    "/clone/vip/dan_chongmai3",
	});

string *ob_list1 = ({
	    "/clone/vip/butian",		
		"/clone/vip/tiancs",
		"/clone/vip/dan_str",
		"/clone/vip/dan_int",
		"/clone/vip/dan_con",
		"/clone/vip/dan_dex",
		"/clone/vip/dan_jiuzhuan",      
		"/clone/vip/dan_bianxing",
		"/clone/vip/dan_chongsu",
		"/clone/vip/avipcard",
		"/clone/vip/putao1",
		"/clone/vip/putao1",
		"/clone/vip/putao1",
	    "/clone/vip/jiuzhuan1",
        "/clone/gift/xuanhuang",
        "/clone/gift/xuanhuang",
       "/clone/shizhe/tianling4",
       "/clone/shizhe/tianling2",
       "/clone/vip/dan_chongmai4",
	
});

void create()
{
	set_name(HIR"年兽王"NOR, ({ "nian shou" }) );
	set_weight(99999999);
	set("long", "头长触角，尖牙利齿；目露凶光，凶猛异常。长年深居海底，每到活动才爬上岸，吞食牲畜伤害人命。"ZJBR
	""ZJSIZE(18)+HIR+ZJURL("cmds:duobao")+"驱赶"+NOR+"\n");
	set("unit", "只");
	set("no_get", 1);
	set("qi",5000);
	set("acts_list",([
		"驱赶":"duobao",
	]));
	set("max_qi",5000);
	setup();
}

void do_back()
{
message("channel:chat",HIW"【活动】：听说年兽王年兽王在人间肆虐一圈后不知所踪，请广大英雄豪杰留意年兽王的下次侵袭。\n"NOR,users());
	
	
destruct(this_object());
}

void get_damage(object me, int damage, int type)
{
	object ob,obj;

	ob = this_object();

	me->add("potential",damage*60);
	tell_object(me,"只听噼里啪啦一阵声响，你对年兽王造成"+damage+"点伤害，获得"+damage*60+"点潜能。\n");
	if((damage > random(1001)) || (random(101)==51))
	{
		obj = new("/clone/vip/dan_jiuzhuan");
	message("channel:chat",HIW"【活动】："+me->query("name")+"("+me->query("id")+")重创"+HIR+"年兽王"+NOR+"王获得"+obj->short()+"。\n"NOR,users());
	tell_object(me,"你重创年兽王获得"+obj->short()+"。\n");
		obj->move(me);
	}
	
	if((damage > random(501)) || (random(51)==11))
	{
		obj = new(ob_list1[random(sizeof(ob_list1))]);
message("channel:chat",HIW"【活动】："+me->query("name")+"("+me->query("id")+")重创"+HIR+"年兽王"+NOR+"获得"+obj->short()+"。\n"NOR,users());
	
	
			tell_object(me,"你重创年兽王获得"+obj->short()+"。\n");
		obj->move(me);
	}
	if((damage > random(101)) || (random(6)==2))
	{
		obj = new(ob_list[random(sizeof(ob_list))]);
		message("channel:chat",HIW"【活动】："+me->query("name")+"("+me->query("id")+")重创"+HIR+"年兽王"+NOR+"获得"+obj->short()+"。\n"NOR,users());
	    tell_object(me,"你重创年兽王获得"+obj->short()+"。\n");
		obj->move(me);
	}
	ob->add("qi",-damage);
	message("vision", ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n", 
	filter_array(all_inventory(environment(ob)), (: interactive($1) :)) );
	if(ob->query("qi")<=0)
	{
		obj = new(ob_list[random(sizeof(ob_list))]);
	message("channel:chat",HIW"【活动】："+me->query("name")+"("+me->query("id")+")重创"+HIR+"年兽王"+NOR+"获得"+obj->short()+"。\n"NOR,users());
	 tell_object(me,"你对年兽王造成致命一击获得"+obj->short()+"。\n");
		obj = new("/clone/shizhe/fudai");
		obj->move(me);
		tell_object(me,"你对年兽王造成致命一击获得"+obj->short()+"。\n");
		obj->move(me);
		if(damage > random(501) || random(6)==2)
		{
			obj = new(ob_list1[random(sizeof(ob_list1))]);
		message("channel:chat",HIW"【活动】："+me->query("name")+"("+me->query("id")+")重创"+HIR+"年兽王"+NOR+"获得"+obj->short()+"。\n"NOR,users());
//	 message("channel:chat",HIW"【活动】："+me->query("name")+"("+me->query("id")+")重创"+HIR+"年兽王"+NOR"获得"+obj->short()+"。\n"NOR,users());
	
			tell_object(me,"你对年兽王造成致命一击获得"+obj->short()+"。\n");
			obj->move(me);
		}
		if(damage > random(200) || random(6)==2)
		{
			obj = new("/clone/vip/dan_jiuzhuan");
		
	message("channel:chat",HIW"【活动】："+me->query("name")+"("+me->query("id")+")重创"+HIR+"年兽王"+NOR+"获得"+obj->short()+"。\n"NOR,users());
	 	tell_object(me,"你对年兽王造成致命一击获得"+obj->short()+"。\n");
			obj->move(me);
		}
		destruct(ob);
	}
}

void init()
{
	object ob,me;

	me = this_player();
	ob = this_object();
	if(playerp(me))
	{
		tell_object(me,ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n");
		tell_object(me,ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n");
		add_action("do_duobao","duobao");
	}
}

int do_duobao(string arg)
{
	object me,ob;
	string *lvs,str;
	int lv;

	me = this_player();

	if(me->is_busy())
		return notify_fail("你正在忙着呢！\n");

	if(!objectp(ob=present("bao zhu",me)))
		return notify_fail("你身上没有爆竹，无法对年兽王造成有效伤害！\n");

	if(!arg)
	{
		str = ZJOBLONG"年兽王乃传说之物，只有用爆竹才能对其造成一定的伤害，寻常难以靠近半步"ZJBR"请选择攻击强度：\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "普通[1节爆竹]:duobao 普通[1节爆竹]"ZJSEP;
		str += "强力[5节爆竹]:duobao 强力[5节爆竹]"ZJSEP;
		str += "重击[25节爆竹]:duobao 重击[25节爆竹]";
		tell_object(me,str + "\n");
		return 1;
	}

	if(!att_lv[arg])
		return notify_fail("选择错误，请重新选择！\n");

	if(ob->query_amount() < att_lv[arg])
		return notify_fail("你身上没有那么多爆竹！\n");
	ob->add_amount(-att_lv[arg]);
	tell_object(me,HIG"你点燃一些爆竹向年兽王掷去！"NOR"\n");
	me->start_busy(1);
	get_damage(me,att_lv[arg]*10,2);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
