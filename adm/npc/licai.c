
inherit NPC;
#include <ansi.h>
int ask_baibao();
int ask_character(string arg);
int ask_characters(string arg);
#include <licai.h>
void create()
{
        set_name(HIY "理财钱老板"NOR,({  "lc", "lc" }) );
        set("gender", "男性" );
        set("age", 20);
        set("long", HIY "他一脸笑嘻嘻，脸上的肥肉微微抖动着，他正是钱庄的老板！"NOR"\n");
        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("shen_type", 1);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

        set("inquiry", ([
             
          // "购买理财": (:ask_character:),
            "购买理财": ""+HIR+ZJSIZE(24)+ZJURL("cmds:washme")+"购买理财"NOR"。",
            "领取理财": (: ask_baibao :),

        ]) );

        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	add_action("ask_character","washme");
}




int ask_character(string arg)
{
	object me = this_player();
	string msg, type, cs,lx,lxz;

			if (me->query(LCPD) == 1) {
				tell_object(me, "你已经买了理财了。\n");
				return 1;
			}
			
	if (!arg || arg == 0) {
//if(!arg){
		msg = ZJOBLONG+
	            CYN"『"HIC+ZJURL("cmds:help licai")ZJSIZE(20)"理财详解"CYN"』"
			HIG"请选择你的理财档次："NOR"\n";
		
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += HIW"一档理财:washme 一档理财";
		msg += ZJSEP"二挡理财:washme 二挡理财";
		msg += ZJSEP"三档理财:washme 三档理财";
		msg += ZJSEP"四档理财:washme 四档理财";
		msg += ZJSEP"五档理财:washme 五档理财";
		msg += ZJSEP"六档理财:washme 六档理财";
		write(msg + "\n");
		return 1;
	} 
	else if(arg=="一档理财"||arg=="二挡理财"||arg=="三档理财"||arg=="四档理财"||arg=="五档理财"||arg=="六档理财")
	{
		msg = ZJOBLONG+
			HIG"请选择你的理财类型："NOR"\n";
		
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += HIW"元宝理财"NOR":washme "+arg+" yuanbao";
     	write(msg + "\n");
		return 1;
	}
	else {
		if(sscanf(arg,"%s %s %s", type,lx,cs) == 3)
		{
			if(lx!="yuanbao")
			{
				tell_object(me, "类型错误1。\n");
				return 1;
			}
		if(lx=="yuanbao")lxz="元宝";
		//else if(lx=="tydbl")lxz="元宝票";
		
			if (me->query(LCPD) == 1) {
				tell_object(me, "你已经买了理财了。\n");
				return 1;
			}

			if (cs == "yes") {
				if (type == "一档理财") {
				if (me->query(""+lx+"")<5000){
				 command("say 你连5000元宝都没有！");
                   return 1;
				} 
					me->add(""+lx+"", -5000);
					me->set(LCDC,1);
					tell_object(me, "你成功购买了一档理财。\n");
				} else if (type == "二挡理财") {
					if (me->query(""+lx+"")<10000){
				 command("say 你连10000"+lxz+"都没有！");
                   return 1;
				} 
					me->add(""+lx+"", -10000);
					me->set(LCDC,2);
					tell_object(me, "你成功购买了二档理财。\n");
				}
				else if (type == "三档理财") {
				if (me->query(""+lx+"")<15000){
				 command("say 你连15000"+lxz+"都没有！");
                   return 1;
				} else if (me->query("zjvip/all_pay")<100&&lxz!="元宝票"){
				 command("say 这个档次只有充值100才能购买！");
                   return 1;
				}
					me->add(""+lx+"", -15000);
					me->set(LCDC,3);
					tell_object(me, "你成功购买了三档理财。\n");
				}
				else if (type == "四档理财") {
				if (me->query(""+lx+"")<20000){
				 command("say 你连20000"+lxz+"都没有！");
                   return 1;
				} else if (me->query("zjvip/all_pay")<300&&lxz!="元宝票"){
				 command("say 这个档次只有充值300才能购买！");
                   return 1;
				}
					me->add(""+lx+"", -20000);
					me->set(LCDC,4);
					tell_object(me, "你成功购买了四档理财。\n");
				}
				else if (type == "五档理财") {
				if (me->query(""+lx+"")<30000){
				 command("say 你连30000"+lxz+"都没有！");
                   return 1;
				} else if (me->query("zjvip/all_pay")<500&&lxz!="元宝票"){
				 command("say 这个档次只有充值500才能购买！");
                   return 1;
				}
					me->add(""+lx+"", -30000);
					me->set(LCDC,5);
					tell_object(me, "你成功购买了五档理财。\n");
				}
				else if (type == "六档理财") {
				if (me->query(""+lx+"")<50000){
				 command("say 你连50000"+lxz+"都没有！");
                   return 1;
				} else if (me->query("zjvip/all_pay")<1000&&lxz!="元宝票"){
				 command("say 这个档次只有充值1000才能购买！");
                   return 1;
				}
					me->add(""+lx+"", -50000);
					me->set(LCDC,6);
					tell_object(me, "你成功购买了六档理财。\n");
				}
				me->set(LCPD,1);
				me->set(LCTS,7);
				me->set(LCLX,lx);
				} 
		} else {
			sscanf(arg,"%s %s",type,lx);
		    if(lx=="yuanbao")lxz="元宝";
		//    else if(lx=="tydbl")lxz="元宝票";
			msg = ZJOBLONG+HIW"你确定选择理财为"+HIY+type+"『"+lxz+"』"+NOR"吗？\n";			
			msg += ZJOBACTS2+ZJMENUF(1,2,9,30);
			msg += "确定:washme "+arg + " yes";
			msg += ZJSEP"取消: ";
			
			write(msg + "\n");
		}
	}
	
	return 1;
}


int ask_baibao()
{
       int a,last,times;
	   string lx,lxz;
	   object me = this_player();
  	   a=me->query(LCTS);
	   lx=me->query(LCLX);
	   
		if(lx=="yuanbao")lxz="元宝";
	//	else if(lx=="tydbl")lxz="元宝票";
	
    if (me->query(LCPD) == 1){
    last = me->query("lc11");
	if(time()/86400 == last/86400){
		if(!lx||lx==0)
		{
        tell_object(me,HIW"类型错误。\n"NOR);
		return 1;
		}
    tell_object(me,HIW"你今天已经领取过理财了，你还可以领取"+HIY+"【"+HIY+a+"】"+NOR+HIW+"天。\n"NOR);
	 return 1;
	}else if(me->query(LCTS)<1)
	{
	tell_object(me, HIW"你已经把理财全部领完了。\n");
		 return 1;
	}else if (me->query(LCDC) == 1){
	if(lx=="tydbl")
	{
	me->add("yuanbao", 1072);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了一档理财,获得了1072元宝，你还能领取"+(a-1)+"次。\n");
	return 1;
	}
	else
	{
	me->add(""+lx+"", 1072);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了一档理财,获得了1072"+lxz+"，你还能领取"+(a-1)+"次。\n");
	return 1;
	}
	}else if (me->query(LCDC) == 2){
	if(lx=="tydbl")
	{
	me->add("yuanbao", 2143);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了二档理财,获得了2143元宝，你还能领取"+(a-1)+"次。\n");
	return 1;
	}
	else
	{
	me->add(""+lx+"", 2143);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了二档理财,获得了2143"+lxz+"，你还能领取"+(a-1)+"次。\n");
	return 1;	
	}
	}else if (me->query(LCDC) == 3){
	if(lx=="tydbl")
	{
	me->add("yuanbao", 3214);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了三档理财,获得了3214元宝，你还能领取"+(a-1)+"次。\n");
	return 1;
	}
	else
	{
	me->add(""+lx+"", 3214);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了三档理财,获得了3214"+lxz+"，你还能领取"+(a-1)+"次。\n");
	return 1;
	}
	}else if (me->query(LCDC) == 4){
	if(lx=="tydbl")
	{
	me->add("yuanbao", 4285);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了四档理财,获得了4285元宝，你还能领取"+(a-1)+"次。\n");
	return 1;
	}
	else
	{
	me->add(""+lx+"", 4285);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了四档理财,获得了4285"+lxz+"，你还能领取"+(a-1)+"次。\n");
	return 1;	
	}
	}
	else if (me->query(LCDC) == 5){
	if(lx=="tydbl")
	{
	me->add("yuanbao", 6429);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了五档理财,获得了6429元宝，你还能领取"+(a-1)+"次。\n");
	return 1;
	}	
	else
	{
	me->add(""+lx+"", 6429);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了五档理财,获得了6429"+lxz+"，你还能领取"+(a-1)+"次。\n");
	return 1;
	}
	}
	else if (me->query(LCDC) == 6){
	if(lx=="tydbl")
	{		
	me->add("yuanbao", 10715);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了六档理财,获得了10715元宝，你还能领取"+(a-1)+"次。\n");
	return 1;
	}		
	else
	{
	me->add(""+lx+"", 10715);
    me->add(LCTS,-1);
	me->set("lc11",time());
	times += 1;
	me->set("lc11time",times);
    tell_object(me, HIW"你成功领取了六档理财,获得了10715"+lxz+"，你还能领取"+(a-1)+"次。\n");
	return 1;	
	}
	}
	 }
	 else{
	     tell_object(me,CYN"你还没有购买理财!\n");
		 return 1;
	 }
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
