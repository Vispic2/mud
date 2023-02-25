// who3.c

#include <ansi.h>
#include <getconfig.h>
inherit F_CLEAN_UP;
#define PAT "/log/adm/wabao"
int main(object me, string arg)
{
int i,iii;
string is,msg,obj,rooms,*line;
object room,where,obname;
string *colors = ({HIW,HIG,HIY,MAG,HIM,RED,HIR,CYN,HIC});
iii=file_size(PAT);
write_file("/log/adm/wabao",sprintf(""));	
if(iii<1)
return notify_fail(HIR"宝物暂时还未刷新！"NOR"\n");		
is = read_file(PAT);	
line = explode(is,"\n");
msg="目前存在宝物：\n";
msg+=ZJOBACTS2+ZJMENUF(1,1,9,31);
for(i=0;i<sizeof(line);i++){
sscanf(line[i],"%s=%s",rooms,obj);
room=load_object(""+rooms+"");
obname=load_object("/clone/vip/"+obj+".c");
msg+=NOR+colors[random(8)]+"在"+room->short()+"处有一个"+NOR+obname->name()+NOR+":walk "+room->short()+""ZJSEP;
}
msg=ZJOBLONG+msg;
msg+="\n";
write(msg+NOR);
return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
