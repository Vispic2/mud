#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
static int flag;
int out(int i);
int boss_hb();
int overtime(string type);
int dz_boss_hb(string type,string from,string name,string text);
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "红包系统");
	CHANNEL_D->do_channel( this_object(), "sys", "红包精灵开始运行。");
  //  set_heart_beat(15);
}
int heart_beat()
{
if(!flag){
boss_hb();
flag=1;
}else
flag=0;
return 1;
}
int dz_boss_hb(string type,string from,string name,string text)
{
if(query("hb")) overtime(type);
set("hb_from",from);  //红包是谁发的？
set("hb_type",type); //此次红包是BOSS死亡后产生的
//message("shout",HIG"各单位注意，红包来啦！"NOR"\n", users(), this_object());
shout(HIG"各单位注意，红包来啦！"NOR"\n");
//message("shout",HIY"本轮红包发送者："HIG+name+NOR+HIY"，"+text+"，发个小红包庆祝一下！"NOR"\n", users(), this_object());
shout(HIY"本轮红包发送者："HIG+name+NOR+HIY"，"+text+"，发个小红包庆祝一下！"NOR"\n");
//message("shout",HIM+name+NOR+HIY"的红包倒计时：10"NOR"\n", users(), this_object());
shout(HIM+name+NOR+HIY"的红包倒计时：10"NOR"\n");
call_out("out",1,9);
return 1;
}

int boss_hb()
{
if(query("hb")) overtime("boss");
set("hb_from","系统");  //红包是谁发的？
set("hb_type","boss"); //此次红包是BOSS死亡后产生的
shout(HIG"各单位注意，红包来啦！"NOR"\n");
shout(HIY"本轮红包发送者："HIG"系统"NOR+HIY"，挑衅者被赶走了，发个小红包庆祝一下！"NOR"\n");
shout(HIM"系统"NOR+HIY"的红包倒计时：10"NOR"\n");
call_out("out",1,9);
return 1;
}
int out(int i)
{
string key;
mixed *to;
to=allocate(4,0);
if(i==0){
to[random(4)]=1;
if(to[0]==0) to[0]="陷阱";
else to[0]="打开";
if(to[1]==0) to[1]="陷阱";
else to[1]="打开";
if(to[2]==0) to[2]="陷阱";
else to[2]="打开";
if(to[3]==0) to[3]="陷阱";
else to[3]="打开";
key="6761"+random(100000000);
set("fg_key",key); //防止指令抢
shout("抢啦^_^："+ZJSIZE(22)+ZJURL("cmds:hbd "+key+":"+to[0])+to[0]+NOR" "+ZJSIZE(22)+ZJURL("cmds:hbd "+key+":"+to[1])+to[1]+NOR" "+ZJSIZE(22)+ZJURL("cmds:hbd "+key+":"+to[2])+to[2]+NOR" "+ZJSIZE(22)+ZJURL("cmds:hbd "+key+":"+to[3])+to[3]+NOR"\n");
//message("shout","抢啦^_^："+ZJSIZE(22)+ZJURL("cmds:hbd "+key+":"+to[0])+to[0]+NOR" "+ZJSIZE(22)+ZJURL("cmds:hbd "+key+":"+to[1])+to[1]+NOR" "+ZJSIZE(22)+ZJURL("cmds:hbd "+key+":"+to[2])+to[2]+NOR" "+ZJSIZE(22)+ZJURL("cmds:hbd "+key+":"+to[3])+to[3]+NOR"\n", users(), this_object());
remove_call_out("out");
return 1;
}
//message("shout",HIM"系统"NOR+HIY"的红包倒计时："+i+NOR"\n", users(), this_object());
shout(HIM"系统"NOR+HIY"的红包倒计时："+i+NOR"\n");
call_out("out",1,i-1);
return 1;
}

int overtime(string type)
{
delete("hb_yqw");   //运气王
delete("hb_type");  //红包类型
delete("hb_from"); //红包来着谁
delete("hb"); //累计抢了多少人与数量
return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
