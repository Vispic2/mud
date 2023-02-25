#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
int level;
string str,exp,dj;
object ob,obj;
mixed *sj;
mapping wupin,wupin_lv,wupin_sl;
ob=load_object(BO_D);
wupin=ob->get_wupin();
wupin_lv=ob->get_wupin_lv();
wupin_sl=ob->get_wupin_sl();
sj=localtime(time());
exp="exp/"+(sj[4]+1)+"-"+sj[5]+""; //每月战令经验刷新一次！
level=me->query(exp);
level=level/100;
if(!arg){
return 1;
}else
if(arg=="task"){
/*
在需要加战令经验的文件加上
write(BO_D->add_exp(me,需要加的经验值)+"\n");
*/
str=ZJOBLONG+"[距离本次战令结束时间还剩："+(30-sj[3])+" 天]"ZJBR"当前任务："ZJBR
"每日签到+10经验"ZJBR
"每次初/中/高副本+15经验"ZJBR
"\n";
write(str+"\n");
return 1;
}else
if(arg=="main"){
BO_D->main(me,arg);
}else{
dj=replace_string(arg,arg[0..0],"");
if(level<to_int(dj)){
write("没有达到对应等级，需要："+dj+"级！\n");
return 1;
}
//4月 5年
if(me->query("wupin/"+(sj[4]+1)+"-"+sj[5]+"-"+arg)){
write("你已经领取过此等奖励了。\n");
return 1;
}
if(arg[0..0]=="b"&&me->query("zhanling/b")<=0){
write("你没有中级战令限权。\n");
return 1;
}
if(arg[0..0]=="c"&&me->query("zhanling/c")<=0){
write("你没有高级战令限权。\n");
return 1;
}
me->set("wupin/"+(sj[4]+1)+"-"+sj[5]+"-"+arg,1);
if(obj=load_object(wupin_lv[wupin[arg]])){
obj=new(wupin_lv[wupin[arg]]);
if(obj->query_amount())
obj->set_amount(to_int(wupin_sl[arg]));
obj->move(me);
write("你获得了："+wupin[arg]+"×"+wupin_sl[arg]+"\n");
return 1;
}else{
write("道具路径错误，联系巫师处理！\n");
return 1;
}
}

return 1;
}
