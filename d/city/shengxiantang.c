// by ranger_游侠
// JuYiTing.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "圣贤堂");
	seteuid(ROOT_UID);
	set("channel_id", "圣贤堂");
	set("long", "江湖高手和新手同时聚集于此。在这里你可以申请成为新人的师傅，也可以寻找一位热情的师傅带你闯荡江湖。");
	set("exits", ([

                               	"southwest" : __DIR__"guangchang",
	]));
	set("action_list", ([
		HIG"寻求师傅"NOR:"xunshi",
		HIM"导师认证"NOR:"daoshizg",
		HIC"行出师礼"NOR:"chushili",
		HIY"管理弟子"NOR:"quzhu",
		HIR"脱离关系"NOR:"tuoli",
	]));
	set("no_fight","1");
        set("no_sleep_room",1);
	setup();
}

void init()
{
	add_action("do_baishi","baishi");
	add_action("do_chushili","chushili");
	add_action("do_shoutu","shoutu");
	add_action("do_quzhu","quzhu");
	add_action("do_tuoli","tuoli");
	add_action("do_xunshi","xunshi");
	add_action("do_daoshizg","daoshizg");
}

int do_quzhu(string arg)
{
	int tm,i,last_on;
	string *dizi,str,err;
	object ob,obj,me=this_player();
	mapping user;

	if(!arg)
	{
		if(!mapp(user=me->query("p_dizi")))
			return notify_fail("你还没有弟子呢！\n");
		dizi = sort_array(keys(user),1);
		if(!sizeof(dizi))
			return notify_fail("你还没有弟子呢！\n");
		str = ZJOBLONG"你现在有以下这些弟子，你可以点击选择驱逐某个弟子：\n";
		str += ZJOBACTS2+ZJMENUF(2,2,6,30);
		for(i=0;i<sizeof(dizi);i++)
		{
			last_on = FINGER_D->get_last_on(dizi[i]);
			str += FINGER_D->get_name(dizi[i])+"（"HIG+dizi[i]+NOR"）"ZJBR"上次登录："ZJBR+CHINESE_D->chinese_date(last_on,2)+":quzhu "+dizi[i]+ZJSEP;
		}
		tell_object(me,str+"\n");
		return 1;
	}

	if(sscanf(arg,"%s yes",arg)!=1)
	{
		if(!FINGER_D->get_name(arg))
			return notify_fail("你要驱逐谁？\n");
		tell_object(me,ZJOBLONG"你确定要驱逐"+FINGER_D->get_name(arg)+"这个弟子么？\n"ZJOBACTS2"确定:quzhu "+arg+" yes\n");
		return 1;
	}

	if(!objectp(obj=find_player(arg)))
	{
		ob = new(LOGIN_OB);
		ob->set("id",arg);
		ob->set("body", USER_OB);
		obj = LOGIN_D->make_body(ob);
		destruct(ob);
		if(obj->restore())
		{
			obj->setup();
			if(!me->query("p_dizi/"+obj->query("id")))
			{
				tell_object(me,"你没有这个徒弟！\n");
			}
			else
			{
				obj->delete("p_master");
				obj->delete("zjvip/master");
				obj->save();
				me->delete("p_dizi/"+obj->query("id"));
				me->save();
				tell_object(me,HIR"逐出弟子"+obj->query("name")+"("+obj->query("id")+")"+"成功！"NOR"\n");
			}
		}else
			tell_object(me,"玩家数据错误！\n");

		destruct(obj);
	}
	else
	{
		if(!me->query("p_dizi/"+obj->query("id")))
		{
			tell_object(me,"你没有这个徒弟！\n");
		}
		else
		{
			obj->delete("p_master");
			obj->delete("zjvip/master");
			obj->save();
			me->delete("p_dizi/"+obj->query("id"));
			me->save();
			tell_object(me,HIR"逐出弟子"+obj->query("name")+"("+obj->query("id")+")"+"成功！"NOR"\n");
			tell_object(obj,HIR+me->query("name")+"("+obj->query("id")+")"+"将你驱逐出师门了！"NOR"\n");
		}
	}

	return 1;
}

int do_tuoli(string arg)
{
	int tm,i;
	string *dizi,str,err;
	object ob,obj,me=this_player();
	mapping user;

	if(!stringp(str=me->query("p_master/id")))
	{
		if(!stringp(str=me->query("zjvip/master")))
		{
			tell_object(me,"你还没有跟任何玩家保持师徒关系，无需脱离！\n");
			return 1;
		}
	}

	if(arg!="yes")
	{
		tell_object(me,ZJOBLONG"你确定要与"+FINGER_D->get_name(str)+"脱离师傅关系么？\n"ZJOBACTS2"确定:tuoli yes\n");
		return 1;
	}

	if(!stringp(me->query("p_master/id")))
	{
		me->delete("zjvip/master");
		tell_object(me,"你与"+FINGER_D->get_name(str)+"从此之后再无瓜葛！\n");
		return 1;
	}

	if(!objectp(obj=find_player(str)))
	{
		ob = new(LOGIN_OB);
		ob->set("id",str);
		ob->set("body", USER_OB);
		obj = LOGIN_D->make_body(ob);
		destruct(ob);
		if(obj->restore())
		{
			obj->setup();
			if(me->query("p_master/id")!=obj->query("id"))
			{
				tell_object(me,"你没有这个师傅！\n");
			}
			else
			{
				obj->delete("p_dizi/"+me->query("id"));
				obj->save();
				me->delete("p_master");
				me->delete("zjvip/master");
				me->save();
				tell_object(me,HIR"你与"+obj->query("name")+"("+obj->query("id")+")"+"脱离师徒关系了！"NOR"\n");
			}
		}else
			tell_object(me,"玩家数据错误！\n");

		destruct(obj);
	}
	else
	{
		if(me->query("p_master/id")!=obj->query("id"))
		{
			tell_object(me,"你没有这个师傅！\n");
		}
		else
		{
			me->delete("p_master");
			me->delete("zjvip/master");
			me->save();
			obj->delete("p_dizi/"+me->query("id"));
			obj->save();
			tell_object(me,HIR"你与"+obj->query("name")+"("+obj->query("id")+")"+"脱离师徒关系了！"NOR"\n");
			tell_object(obj,HIR+me->query("name")+"("+obj->query("id")+")"+"与你脱离了师徒关系！"NOR"\n");
		}
	}

	return 1;
}

int do_xunshi(string arg)
{
	string *str,strs,zige;
	int i,j,ye,yeall;
	object ob,*ob_list;

	if(!arg) arg = "1";
	str = ({});
	if( sscanf(arg, "%d", ye)==1)
	{
		ob_list = users();
		ob_list = sort_array(users(), "sort_user", this_object());
		for(i=0; i<sizeof(ob_list); i++)
		{
			ob = ob_list[i];
			if(ob->is_character()&&ob->query("zjvip/daoshizg"))
			{
				if(ob->query("zjvip/daoshizg")>5)
					zige = "一代圣贤";
				else if(ob->query("zjvip/daoshizg")==5)
					zige = "桃李天下";
				else if(ob->query("zjvip/daoshizg")==4)
					zige = "名满江湖";
				else if(ob->query("zjvip/daoshizg")==3)
					zige = "良师益友";
				else if(ob->query("zjvip/daoshizg")==2)
					zige = "高级师傅";
				else if(ob->query("zjvip/daoshizg")==1)
					zige = "初级师傅";
				str += ({sprintf("%s　%s:baishi %s",zige,ob->query("name"),ob->query("id"))});
			}
		}

		if(!sizeof(str))
			write("目前尚无"HIY"玩家导师"NOR"在线！\n");
		else
		{
			strs = ZJOBLONG"目前有以下导师在线收徒：\n";

			strs += ZJOBACTS2+ZJMENUF(2,2,9,30);

			yeall = sizeof(str)/10;
			if(sizeof(str)%10) yeall += 1;
			if(ye<1) ye = 1;
			if(ye>yeall) ye = yeall;
			j = (ye-1)*10;
			i = ye*10;
			if (i >= sizeof(str)) i = sizeof(str);
			i--;
			if(yeall>1)
				strs += "上一页:xunshi "+(ye-1)+ZJSEP"下一页:xunshi "+(ye+1)+ZJSEP;
			strs += implode(str[j..i], ZJSEP);
			write(strs+"\n");
		}
	}
}

int sort_user(object ob1, object ob2)
{
	if(ob2->query("zjvip/daoshizg")==ob1->query("zjvip/daoshizg"))
		return ob2->query("combat_exp") - ob1->query("combat_exp");
	else 
		return ob2->query("zjvip/daoshizg") - ob1->query("zjvip/daoshizg");
}

int do_daoshizg()
{
	int i;
	string *dizi;
	string *dszg = ({HIW"初级师傅"NOR,HIG"高级师傅"NOR,HIB"良师益友"NOR,HIM"名满江湖"NOR,HIY"桃李天下"NOR,HIR"一代圣贤"NOR});
	object me=this_player();

	if(me->query("combat_exp")<500000)
		return notify_fail("你现在还没有做玩家导师的资格\n至少要"HIB"100w经验"NOR"才能收徒！\n");
	if(!me->query("zjvip/daoshizg"))
	{
		me->set("zjvip/daoshizg",1);
		return notify_fail("恭喜，你你的导师资格认证成功。。。\n你现在的导师资格是"HIW"【初级师傅】"NOR"！\n");
	}
	else if(me->query("zjvip/daoshi_exp")>49&&me->query("zjvip/daoshizg")<6&&!me->query("p_master"))
	{
		me->set("zjvip/daoshizg",6);
		return notify_fail("恭喜，你的导师资格晋升为"HIM"【一代圣贤】"NOR"！\n");
	}
	else if(me->query("zjvip/daoshi_exp")>19&&me->query("zjvip/daoshizg")<5&&!me->query("p_master"))
	{
		me->set("zjvip/daoshizg",5);
		return notify_fail("恭喜，你的导师资格晋升为"HIM"【桃李天下】"NOR"！\n");
	}
	else if(me->query("zjvip/daoshi_exp")>9&&me->query("zjvip/daoshizg")<4&&!me->query("p_master"))
	{
		me->set("zjvip/daoshizg",4);
		return notify_fail("恭喜，你的导师资格晋升为"HIM"【名满江湖】"NOR"！\n");
	}
	else if(me->query("zjvip/daoshi_exp")>4&&me->query("zjvip/daoshizg")<3&&!me->query("p_master"))
	{
		me->set("zjvip/daoshizg",3);
		return notify_fail("恭喜，你的导师资格晋升为"HIB"【良师益友】"NOR"！\n");
	}
	else if(me->query("zjvip/daoshi_exp")>2&&me->query("zjvip/daoshizg")<2 && !me->query("p_master"))
	{
		me->set("zjvip/daoshizg",2);
		return notify_fail("恭喜，你的导师资格晋升为"HIG"【高级师傅】"NOR"！\n");
	}
	else
	{
		if(!me->query("p_dizi"))
		{
			return notify_fail("你现在的导师资格是"+dszg[me->query("zjvip/daoshizg")-1]+"，你可以收"+(me->query("zjvip/daoshizg")*3+3)+"个弟子，你还没有徒弟！\n");
		}
		dizi = keys(me->query("p_dizi"));
		return notify_fail("你现在的导师资格是"+dszg[me->query("zjvip/daoshizg")-1]+"，你可以收"+(me->query("zjvip/daoshizg")*3+3)+"个弟子，你现有"+sizeof(dizi)+"个弟子。\n");
	}
}

int do_baishi(string arg)
{
	int i;
	string *dizi;
	object ob,me=this_player();
	mapping user;

	if(!arg)
		return notify_fail("你想要拜谁为导师？\n");
	else if(!(ob = find_player(arg)))
		return notify_fail("有这个导师么？\n");
	else if(ob==me)
		return notify_fail("自己拜自己啊？这想法不错！\n");
	else if(me->query("zjvip/out_master"))
		return notify_fail("你都已经出师，还拜什么师？\n");

	if(!ob->query("zjvip/daoshizg"))
	{
		return notify_fail("对方没有导师资格！\n");
	}
	else if(me->query("zjvip/daoshizg"))
	{
		return notify_fail("你也是有导师资格的人了，就不需要拜师了吧？\n");
	}
	else if(me->query("combat_exp")>500000)
	{
		return notify_fail("你现在的江湖阅历足够做别人的导师了还是去认证一下导师资格收些徒弟吧！\n");
	}
	else
	{
		me->set_temp("baishi",ob);
		if(environment(ob)!=this_object())
		{
			tell_object(ob,ZJSIZE(25)+HIC+me->query("name")+NOR"想要"ZJSIZE(25)+HIM"拜你为师"NOR"，如果同意的话赶紧去结缘殿确认关系。\n");
			return notify_fail("拜师请求已发出，请等待答复，如果收到导师答复，等导师来到这里再次发送拜师指令。\n");
		}
		else
		{
			tell_object(ob,ZJSIZE(25)+HIC+me->query("name")+NOR"想要"ZJSIZE(25)+HIM"拜你为师"NOR"，如果"ZJURL("cmds:shoutu "+me->query("id"))+ZJSIZE(22)+HIY"同意"NOR"的话赶紧给个确认。\n");
			return notify_fail("拜师请求已发出，请等待导师答复。\n");
		}
	}
	return 1;
}

int do_chushili()
{
	int i;
	string *dizi;
	object chushili,ob,ob1,me=this_player();
	mapping user;

	if(me->query("combat_exp")<1000000)
		return notify_fail(HIR"一百万经验才有资格出师。"NOR"\n");
	else if(me->query("zjvip/out_master"))
		return notify_fail(HIW"你都已经出师了，还来出什么师？"NOR"\n");
	else if(!me->query("p_master"))
	
	{
		return notify_fail("你有导师吗？\n");
	}
	else
	{
		me->delete("p_master");
		
	
		if(!me->query("zjvip/out_master"))
		
			ob1 = new("/clone/shizhe/masterbox");
                        ob1->move(me);
			tell_object(me,"出师仪式完成，你获得了一个"HIM"出师礼包"NOR"！\n");
			me->add("zjvip/out_master",1);
	
	}
	return 1;
}

int do_shoutu(string arg)
{
	int i;
	string *dizi;
	object obj,ob,me=this_player();
	mapping user;

	if(!arg)
		return notify_fail("你想要收谁为徒？\n");
	else if(!(ob = find_player(arg)))
		return notify_fail("有这个人么？\n");
	else if(ob==me)
		return notify_fail("你这是要逆天啊？\n");

	if(me->query("p_master"))
		return notify_fail("你还没出师就想收徒？！\n");

	if(me->query("p_dizi"))
	{
		dizi = keys(me->query("p_dizi"));
	}

	if(ob->query_temp("baishi")!=me)
	{
		return notify_fail(HIG"想收人做徒弟？人家没想拜你吧？\n"NOR);
	}
	else if((me->query("zjvip/daoshizg")*3+3)<=sizeof(dizi))
	{
		return notify_fail(HIR"你现在的弟子已经够多了，还是多照顾照顾未出师的弟子吧！\n"NOR);
	}
	else if(sizeof(dizi)&&member_array(ob->query("id"),dizi)!=-1)
	{
		return notify_fail(ob->query("name")+"早已是你的弟子了吧！\n");
	}
	else
	{
		ob->delete_temp("baishi");
		if(environment(ob)==this_object())
		{
			ob->set("p_master/name",me->query("name"));
			ob->set("p_master/id",me->query("id"));
			ob->set("p_master/qinmi",1);
			me->set("p_dizi/"+ob->query("id")+"/name",ob->query("name"));
			me->set("p_dizi/"+ob->query("id")+"/qinmi",1);
			if(!ob->query("baishi_times"))
			{
				tell_object(ob,HIY"拜师成功！赶紧向师傅学习一些江湖行走经验，问师傅要些行走江湖日用品行走江湖吧！\n"NOR);
			}
			else
				tell_object(ob,HIY"拜师成功！抽空赶紧多向导师请教请教吧！\n"NOR);
			ob->add("baishi_times",1);
			ob->set("zjvip/master",me->query("id"));
			CHANNEL_D->do_channel(me,"chat","pat "+ob->query("id"),1);
			CHANNEL_D->do_channel(this_object(),"chat","恭喜"HIM+me->query("name")+"和"+ob->query("name")+"结下师徒之缘"NOR"，祝"+ob->query("name")+"早日出师，名传江湖！");
			return notify_fail("恭喜你又新收到一名子弟，接下来多多指导他让他早日出师吧。\n");
		}
		else
		{
			tell_object(ob,HIR"拜师失败，你已经离开圣贤堂了！\n"NOR);
			return notify_fail(HIR"收徒失败，对方已不在这里。\n"NOR);
		}
	}
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
