//by name
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
#include <dbase.h>
mapping wupin=([
"a1":"下品冲脉丹","b1":"下品冲脉丹","c1":"下品冲脉丹",
"a2":"小元宝","b2":"小元宝","c2":"小元宝",
"a3":"小元宝","b3":"小元宝","c3":"小元宝",
"a4":"小元宝","b4":"小元宝","c4":"小元宝",
"a5":"小元宝","b5":"小元宝","c5":"小元宝",
"a6":"小元宝","b6":"小元宝","c6":"小元宝",
"a7":"小元宝","b7":"小元宝","c7":"小元宝",
"a8":"小元宝","b8":"小元宝","c8":"小元宝",
"a9":"小元宝","b9":"小元宝","c9":"小元宝",
"a10":"小元宝","b10":"小元宝","c10":"小元宝",
"a11":"小元宝","b11":"小元宝","c11":"小元宝",
"a12":"小元宝","b12":"小元宝","c12":"小元宝",
"a13":"小元宝","b13":"小元宝","c13":"小元宝",
"a14":"小元宝","b14":"小元宝","c14":"小元宝",
"a15":"小元宝","b15":"小元宝","c15":"小元宝",
"a16":"小元宝","b16":"小元宝","c16":"小元宝",
"a17":"小元宝","b17":"小元宝","c17":"小元宝",
"a18":"小元宝","b18":"小元宝","c18":"小元宝",
"a19":"小元宝","b19":"小元宝","c19":"小元宝",
"a20":"小元宝","b20":"小元宝","c20":"小元宝",
"a21":"小元宝","b21":"小元宝","c21":"小元宝",
"a22":"小元宝","b22":"小元宝","c22":"小元宝",
"a23":"小元宝","b23":"小元宝","c23":"小元宝",
"a24":"小元宝","b24":"小元宝","c24":"小元宝",
"a25":"小元宝","b25":"小元宝","c25":"小元宝",
"a26":"小元宝","b26":"小元宝","c26":"小元宝",
"a27":"小元宝","b27":"小元宝","c27":"小元宝",
"a28":"小元宝","b28":"小元宝","c28":"小元宝",
"a29":"小元宝","b29":"小元宝","c29":"小元宝",
"a30":"小元宝","b30":"小元宝","c30":"小元宝",
]);
//数量
mapping wupin_sl=([
"a1":"10","b1":"20","c1":"30",
"a2":"10","b2":"20","c2":"30",
"a3":"10","b3":"20","c3":"30",
"a4":"10","b4":"20","c4":"30",
"a5":"10","b5":"20","c5":"30",
"a6":"10","b6":"20","c6":"30",
"a7":"10","b7":"20","c7":"30",
"a8":"10","b8":"20","c8":"30",
"a9":"10","b9":"20","c9":"30",
"a10":"10","b10":"20","c10":"30",
"a11":"10","b11":"20","c11":"30",
"a12":"10","b12":"20","c12":"30",
"a13":"10","b13":"20","c13":"30",
"a14":"10","b14":"20","c14":"30",
"a15":"10","b15":"20","c15":"30",
"a16":"10","b16":"20","c16":"30",
"a17":"10","b17":"20","c17":"30",
"a18":"10","b18":"20","c18":"30",
"a19":"10","b19":"20","c19":"30",
"a20":"10","b20":"20","c20":"30",
"a21":"10","b21":"20","c21":"30",
"a22":"10","b22":"20","c22":"30",
"a23":"10","b23":"20","c23":"30",
"a24":"10","b24":"20","c24":"30",
"a25":"10","b25":"20","c25":"30",
"a26":"10","b26":"20","c26":"30",
"a27":"10","b27":"20","c27":"30",
"a28":"10","b28":"20","c28":"30",
"a29":"10","b29":"20","c29":"30",
"a30":"10","b30":"20","c30":"30",
]);
//物品路径
mapping wupin_lv=([
"下品冲脉丹":"/clone/shizhe/dan_chongmai1",
"小元宝":"/clone/money/yuanbao",
]);
mapping get_wupin() { return wupin; }
mapping get_wupin_lv() { return wupin_lv; }
mapping get_wupin_sl() { return wupin_sl; }
void create()
{
	seteuid(getuid());
	set("channel_id", "战令精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "NAME战令精灵系统开始运行。");
    set_heart_beat(1);
}
string query_save_file() { return DATA_DIR + "zhanlingd"; }
int heart_beat()
{
mixed *sj;
sj=localtime(time());
return 1;
}
string add_exp(object ob,int jy)
{
int level;
string exp;
mixed *sj;
sj=localtime(time());
exp="exp/"+(sj[4]+1)+"-"+sj[5]+""; //每月战令经验刷新一次！
ob->add(exp,jy);
return "战令经验+"+jy+"点。\n";
}
int main(object me,string arg)
{
/*
"+sj[4]+" 月
"+sj[5]+" 年
*/
int i,level;
string msg,exp;
mixed *sj;
sj=localtime(time());
exp="exp/"+(sj[4]+1)+"-"+sj[5]+""; //每月战令经验刷新一次！
level=me->query(exp);
if(arg=="main"){
msg=ZJOBLONG+CYN+"◇◇◇◇◇◇◇◇◇"HIR"【"HIW"战令系统"HIR"】"CYN"◇◇◇◇◇◇◇◇◇"+NOR+ZJBR
WHT"≡━━━━━━━━━━━━━━━━━━━━━━≡"NOR+ZJBR
//100点经验1级
"〖当前战令等级〗："+HIY+(level/100)+NOR+"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"+ZJSIZE(25)+ZJURL("cmds:zhanlin main")+"刷新"NOR"/"+ZJSIZE(25)+ZJURL("cmds:zhanlin task")+"任务"NOR+ZJBR
"〖战令升级所需〗："+HIY+level+"/"+(100+level/100*100)+"经验值"NOR+ZJBR
WHT"等级"NOR" "HIG"  〖初级奖励〗"NOR+HIW"   〖中级奖励〗"HIR"   〖高级奖励〗"NOR+ZJBR+ZJBR;
for(i=1;i<=30;i++){
msg+="\t"+i+"：  "+ZJURL("cmds:zhanlin a"+i)+wupin["a"+i]+"×"+wupin_sl["a"+i]+NOR"   "+ZJURL("cmds:zhanlin b"+i)+wupin["b"+i]+"×"+wupin_sl["b"+i]+NOR"   "+ZJURL("cmds:zhanlin c"+i)+wupin["c"+i]+"×"+wupin_sl["c"+i]+NOR+ZJBR+ZJBR;
}
msg+="\n";
write(msg+"\n");
return 1;
}
return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
