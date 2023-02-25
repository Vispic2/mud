// by name 2021.5.27
//QQ：3468713544
//仆役系统
//材料上限算法为基础100000点+宝盆等级*10000，超过的减少至上限...
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
int i,py,gain;
string msg;
object ob,*obs;
mapping my;
mapping kc=([
"shulin":"私人树林",
"guwu":"谷物工厂",
"shiliao":"石料矿场",
"tieliao":"铁料矿场",
]);
my = me->query_entire_dbase();
if(me->query("mucai_sl")>100000+(me->query("puyi_baozhen")*10000)) my["mucai_sl"]=100000+(me->query("puyi_baozhen")*10000);
if(me->query("liangshi_sl")>100000+(me->query("puyi_baozhen")*10000)) my["liangshi_sl"]=100000+(me->query("puyi_baozhen")*10000);
if(me->query("shiliao_sl")>100000+(me->query("puyi_baozhen")*10000)) my["shiliao_sl"]=100000+(me->query("puyi_baozhen")*10000);
if(me->query("tieliao_sl")>100000+(me->query("puyi_baozhen")*10000)) my["tieliao_sl"]=100000+(me->query("puyi_baozhen")*10000);
py=me->query("puyi_sl")-(me->query("puyi_tieliao")+me->query("puyi_shiliao")+me->query("puyi_guwu")+me->query("puyi_shulin"));
gain=me->query("puyi_baozhen")*2;
if(!arg){
msg=ZJOBLONG"你目前可以支配的仆役数："+(py>0?py:"0")+"人"ZJBR"你目前拥有的仆役总数量："+me->query("puyi_sl")+"人"+ZJBR
""HIC"≡"HIY"一一一一一一一一一一一一一一一一一一一一"HIC"≡"+NOR+ZJBR
"你目前拥有的材料如下："ZJBR
"木材数量："+me->query("mucai_sl")+ZJBR
"粮食数量："+me->query("liangshi_sl")+ZJBR
"石料数量："+me->query("shiliao_sl")+ZJBR
"铁料数量："+me->query("tieliao_sl")+ZJBR
""HIC"≡"HIY"一一一一一一一一一一一一一一一一一一一一"HIC"≡"+NOR+ZJBR
"你目前的各个矿场安排状况："ZJBR
"私人树林中工作的仆役："+me->query("puyi_shulin")+"人  (每分钟收益："+me->query("puyi_shulin")*10+"点)"ZJBR
"谷物工厂中工作的仆役："+me->query("puyi_guwu")+"人  (每分钟收益："+me->query("puyi_guwu")*10+"点)"ZJBR
"石料矿场中工作的仆役："+me->query("puyi_shiliao")+"人  (每分钟收益："+me->query("puyi_shiliao")*10+"点)"ZJBR
"铁料矿场中工作的仆役："+me->query("puyi_tieliao")+"人  (每分钟收益："+me->query("puyi_tieliao")*10+"点)"
"\n";
msg+=ZJOBACTS2+ZJMENUF(4,4,9,33)
"树林安排:puyi shulin"ZJSEP
"谷物安排:puyi guwu"ZJSEP
"石料安排:puyi shiliao"ZJSEP
"铁料安排:puyi tieliao"ZJSEP
"招募仆役:puyi zhaomu"ZJSEP
"聚灵宝阵:puyi baozhen"ZJSEP
"重新安排:puyi init";
write(msg+"\n");
return 1;
}
if(arg=="shulin"||arg=="guwu"||arg=="shiliao"||arg=="tieliao"){
msg=ZJOBLONG"是否安排仆役前往"+kc[arg]+"？\n";
msg+=ZJOBACTS2+ZJMENUF(4,4,9,33)
""+kc[arg]+"安排:puyi "+arg+" s"ZJSEP
"前往矿区:puyi "+arg+" goto";
write(msg+"\n");
return 1;
}
if(arg=="shulin s"||arg=="guwu s"||arg=="shiliao s"||arg=="tieliao s"){
if(!me->query("puyi_sl"))
return notify_fail(ZJOBLONG"你暂时没有一个仆役，可以试试招募仆役哦。\n");
if(py<1)
return notify_fail(ZJOBLONG"你目前没有可用仆役哦。\n");
me->add("puyi_"+replace_string(arg," s","")+"",1);
ob=new("/cmds/puyi");
ob->set_name(me->query("name")+"的仆役",({me->query("id")+" puyi"}));
ob->move("/d/kuangchang/"+replace_string(arg," s",""));
ob->set("owner",me->query("id"));
ob->set("owners",me->name());
write("派遣仆役前往《"+HIG+kc[replace_string(arg," s","")]+NOR+"》成功，收益：每分钟大概收益10点原料！\n");
write(ZJOBLONG"派遣仆役前往《"+HIG+kc[replace_string(arg," s","")]+NOR+"》成功，收益：每分钟大概收益10点原料！\n");
return 1;
}
if(arg=="shulin goto"||arg=="guwu goto"||arg=="shiliao goto"||arg=="tieliao goto"){
me->move("/d/kuangchang/"+replace_string(arg," goto",""));
me->start_busy(3);
write("前往《"+HIG+kc[replace_string(arg," goto","")]+NOR+"》成功。\n");
write(ZJOBLONG"前往《"+HIG+kc[replace_string(arg," goto","")]+NOR+"》成功。\n");
}
if(arg=="zhaomu"){
msg=ZJOBLONG"你确定花费1000元宝招募一个仆役吗？\n";
msg+=ZJOBACTS2+ZJMENUF(4,4,9,33)
"是:puyi zhaomu yes"ZJSEP
"否:puyi";
write(msg+"\n");
return 1;
}
if(arg=="zhaomu yes"){
if(me->query("yuanbao")<1000)
return notify_fail(ZJOBLONG"你的元宝不足，至少需要1000个元宝才能招募。\n");
if(me->query("puyi_sl")>=20)
return notify_fail(ZJOBLONG"目前最多只能招募20名仆役！\n");
me->add("puyi_sl",1);
me->add("yuanbao",-1000);
write("你花费1000元宝，招募仆役成功，目前仆役总数量："+me->query("puyi_sl")+"。\n");
write(ZJOBLONG"你花费1000元宝，招募仆役成功，目前仆役总数量："+me->query("puyi_sl")+"。\n");
}
if(arg=="init"){
msg=ZJOBLONG"你确定要取消所有仆役目前的工作安排吗？\n";
msg+=ZJOBACTS2+ZJMENUF(4,4,9,33)
"是:puyi init yes"ZJSEP
"否:puyi";
write(msg+"\n");
return 1;
}
if(arg=="init yes"){
obs = children("/cmds/puyi.c");
foreach(ob in obs){
if(ob->query("owner")!=me->query("id")) continue;
destruct(ob);
}
me->delete("puyi_shulin");
me->delete("puyi_guwu");
me->delete("puyi_shiliao");
me->delete("puyi_tieliao");
write("重新安排仆役成功，请重新安排仆役工作项目。\n");
write(ZJOBLONG"重新安排仆役成功，请重新安排仆役工作项目。\n");
return 1;
}
if(arg=="baozhen"){
if(!me->query("jlbz/"+me->query("puyi_baozhen")+"")){
me->set("jlbz/mucai",1000+1000*me->query("puyi_baozhen")+random(1000*me->query("puyi_baozhen")));
me->set("jlbz/tieliao",1000+1000*me->query("puyi_baozhen")+random(1000*me->query("puyi_baozhen")));
me->set("jlbz/shiliao",1000+1000*me->query("puyi_baozhen")+random(1000*me->query("puyi_baozhen")));
me->set("jlbz/"+me->query("puyi_baozhen")+"",1);
}
msg=ZJOBLONG"目前聚灵宝阵等级："+me->query("puyi_baozhen")+ZJBR
"聚灵宝阵目前的收益："+gain+" (经验和潜能及铜钱)"ZJBR
"目前升级聚灵宝阵需要："+ZJBR+me->query("jlbz/mucai")+"木材 "+me->query("jlbz/shiliao")+"石料 "+me->query("jlbz/tieliao")+"铁料"ZJBR
"目前可以对聚灵宝阵进行以下操作："
"\n";
msg+=ZJOBACTS2+ZJMENUF(4,4,9,33)
"升级:puyi level";
write(msg+"\n");
}
if(arg=="level"){
if(me->query("mucai_sl")<me->query("jlbz/mucai"))
return notify_fail(ZJOBLONG"你目前的木材不足提升聚灵宝阵！\n");
if(me->query("tieliao_sl")<me->query("jlbz/tieliao"))
return notify_fail(ZJOBLONG"你目前的铁料不足提升聚灵宝阵！\n");
if(me->query("shiliao_sl")<me->query("jlbz/shiliao"))
return notify_fail(ZJOBLONG"你目前的石料不足提升聚灵宝阵！\n");
me->add("shiliao_sl",-me->query("jlbz/shiliao"));
me->add("tieliao_sl",-me->query("jlbz/tieliao"));
me->add("mucai_sl",-me->query("jlbz/mucai"));
me->add("puyi_baozhen",1);
write("升级宝阵成功，目前聚灵宝阵等级："+me->query("puyi_baozhen")+"\n");
write(ZJOBLONG"升级宝阵成功，目前聚灵宝阵等级："+me->query("puyi_baozhen")+"\n");
}

return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
