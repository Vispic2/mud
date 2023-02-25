// time.c					  
#include <ansi.h>

int main(object me, string arg)
{   
    mapping lunjian = FAMILY_D->query_lunjian();
    string *title = keys(lunjian);
    object ob;
    string msg,str; 
    string cmd,name; 
    
    if (!arg)
    {
    msg = ZJOBLONG"这里是天下五绝的雕像，你可以查看：\n";
    msg += ZJOBACTS2+ZJMENUF(2,2,9,31);
    foreach (str in title) {
     if (objectp(ob =find_player(lunjian[str])))
     msg += sprintf("\t%s—%s:lunsword %s"ZJSEP,str,ob->query("name"),lunjian[str]);
     else 
     msg += sprintf("\t%s—不知所踪:look"ZJSEP,str);//by name 闪退处已修复
     }
     write(msg+"\t刷新信息:look\n");     
    }     
     else     
     if (objectp(ob = find_player(arg)))
     {
      msg = ZJOBLONG"这里是天下五绝的雕像，你可以查看："ZJBR;
      msg += "姓名："+ob->query("name")+ZJBR;
      msg += "门派："+ob->query("family/family_name")+ZJBR;
      msg += "帮会："+(ob->query("banghui/name")?""+ob->query("banghui/name")+"":"暂无")+ZJBR;
      msg += "年龄："+ob->query("age")+ZJBR;
      msg += "性别："+ob->query("gender")+ZJBR;
      msg += "收到鲜花："+ob->query("xianhua")+"       收到臭鸡蛋："+ob->query("choujidan")+"";
      msg += "\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
      msg += "膜拜:look "+getuid(ob)+ZJSEP;
      msg += "送鲜花:lunsword hua "+getuid(ob)+ZJSEP;
      msg += "丢臭鸡蛋:lunsword dan "+getuid(ob);
      write(msg+"\n");
     }else        
     //by name 2021.4.7
     {
     sscanf(arg,"%s %s",cmd,name);
     if(!objectp(ob = find_player(name)))
     return notify_fail("这位玩家目前不在线上。\n");
	 if(me->query("time/lunsword") > time())
	 return notify_fail("三分钟才能平均一次，目前剩余时间："+(me->query("time/lunsword")-time())+"秒。\n");
	
     
     if(cmd=="hua"){
     ob->add("xianhua",1);  //鲜花
     tell_object(me,"你拿出一束"+HIR+"鲜花"+NOR+"送给"+ob->name()+"。\n");
     tell_object(ob,"你收到了"+me->name()+"送来的一朵"+HIR+"鲜花"+NOR+"。\n");
     }else
     if(cmd=="dan")
     {
     ob->add("choujidan",1); //臭鸡蛋
     tell_object(me,"你拿出一个"+YEL+"臭鸡蛋"+NOR+"狠狠的向"+ob->name()+"砸去！\n");
     tell_object(ob,"你被"+me->name()+"扔来的"+YEL+"臭鸡蛋"+NOR+"炸了一身，顿时臭烘烘的！\n");
     }
     me->add("song/cjd",1); //臭鸡蛋
     me->add("song/hua",1); //鲜花
     me->set("time/lunsword",time()+180); //三分钟才能评价一次
    }

	return 1;	
}

int help(object me)
{
     write(@HELP
指令格式: lunsword，这个指令告诉你当前的天下五绝的信息。

HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
