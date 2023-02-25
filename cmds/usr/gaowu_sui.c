//by name 2021.5.28
//qq 3468713544 
//刺杀任务
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string gw,*book,msg;
object ob;
if(!arg){
msg=ZJOBLONG"请选择要购买的高武碎片，当前选择机会："+me->query("gaowu/suipian")+"\n";
msg+=ZJOBACTS2+ZJMENUF(3,3,9,31);
book=get_dir("/d/city/book/");
foreach(gw in book){
msg+=load_object("/d/city/book/"+gw)->name()+":gaowu_sui "+gw+""+ZJSEP;
}
write(msg+"\n");
return 1;
}else{
if(!me->query("gaowu/suipian"))
return notify_fail("你没有兑换次数不足，请去购买。\n");
ob=new("/d/city/book/"+arg);
ob->move(me);
me->add("gaowu/suipian",-1);
write("你选择是是："+arg+"\n");
}
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
