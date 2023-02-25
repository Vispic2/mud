// paym.c

#include <ansi.h>

int main(object me, string arg)
{
    int rmb;
    string id;
	object ob;
	if (!SECURITY_D->valid_grant(me, "(admin)"))
	return 0;
	seteuid(ROOT_UID);
	if(!arg||sscanf(arg,"%s %d",id,rmb)!=2)
	return notify_fail("格式错误，正确格式为：paym ID 金额\n");
    if(ob=find_player(id)){
    ob->add("yuanbao",100*rmb);
    ob->add("zjvip/all_pay",rmb);
    "/adm/daemons/tuiguangd"->chongzhi(me,rmb);
    tell_object(me,HIY"你为"+ob->name()+"("+ob->query("id")+")充值了："+rmb+"元，他目前拥有元宝："+ob->query("yuanbao")+"个"NOR"\n");
    tell_object(ob,HIY+me->name()+"("+me->query("id")+")"+"巫师给你手动充值了"+rmb+"元，你目前拥有元宝："+ob->query("yuanbao")+"个"NOR"\n");
    log_file("cmds/adm/paym", sprintf(me->query("id")+"在%s：给%s(%s)赞助%d元。\n",ctime(time()),ob->name(),ob->query("id"),rmb));
	VIP_D->add_paym(sprintf("%d",time()),(["id":ob->query("id"),"num":rmb]));
    return 1;
    }else{
    write("充值对象("+id+")目前不在线，请稍后再试！\n");
    return 1;    
    }    
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
