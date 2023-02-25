#include <ansi.h>
inherit F_CLEAN_UP;
#define HB_D "/adm/daemons/hongbaod"
int main(object me, string arg)
{
int i,num;
mixed to;
string yqw,name;
if(!arg) return 1;
if(HB_D->query("hb_type")=="boss"){
if(strsrch(arg,HB_D->query("fg_key"))==-1){
me->add("kg_hb",1);
write(HIR"不可以使用指令抢红包，你的ID已经被记录，超过3次将会删除同IP下所有账号！"NOR"\n");
return 1;
}
if(me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n");
if(strsrch(sprintf("%O",HB_D->query("hb")),me->name())!=-1){
write("这个红包你已经领取过了！\n");
return 1;
}
arg=replace_string(arg,HB_D->query("fg_key")+":","");
if(arg=="打开"){
to=allocate(5,1+random(50));
num=to[random(5)];
//name="/adm/daemons/random_name.c"->random_name();
if(mapp(HB_D->query("hb"))){
sscanf(HB_D->query("hb_yqw"),"%s:%d",yqw,i);
if(i<=num)
HB_D->set("hb_yqw",me->name()+":"+num);
}else
HB_D->set("hb_yqw",me->name()+":"+num);
HB_D->set("hb/"+me->name(),({num}));
write(HIG+me->name()+NOR+HIY+"抢到"+HB_D->query("hb_from")+"的红包，获得"+HIR+num+HIY+"元宝"NOR"\n");
shout(HIM+me->name()+NOR+HIY+"抢到"+HB_D->query("hb_from")+"的红包，获得"+HIR+num+HIY+"元宝"NOR"\n");
me->add("yuanbao",num);
log_file("cmds/hbd","时间："+ctime()+"----"+me->name()+"抢到"+HB_D->query("hb_from")+"的红包，获得"+num+"元宝\n");
if(sizeof(keys(HB_D->query("hb")))>=5){
sscanf(HB_D->query("hb_yqw"),"%s:%d",yqw,i);
write(HIY+HB_D->query("hb_from")+"的红包已被拆光，本轮人气王："HIM+yqw+NOR"\n");
shout(HIY+HB_D->query("hb_from")+"的红包已被拆光，本轮人气王："HIM+yqw+NOR"\n");
HB_D->overtime("boss");
HB_D->remove_call_out("overtime");
return 1;
}
}else{
me->start_busy(3);
write("选择红包错误！\n");
return 1;
}
return 1;
}
write("现在没有红包！\n");
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
