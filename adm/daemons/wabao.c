//by name
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
int load_room();
int update();
static int flag;
static int flaga;
static int flagb;
mapping room_place = ([
	"白驼山"		: "/d/baituo/",
	"北京"			: "/d/beijing/",
	"长安" 			: "/d/changan/",	
	"扬州"			: "/d/city/",
	"成都"			: "/d/city3/",
	"大理"			: "/d/dali/",
	"峨嵋山" 		: "/d/emei/",
	"佛山"			: "/d/foshan/",
	"丐帮" 			: "/d/gaibang/",
	"福州"			: "/d/fuzhou/",
	"关外"			: "/d/guanwai/",
	"归云山庄"	: "/d/guiyun/",
	"古墓" 			: "/d/gumu/",
	"杭州"			: "/d/hangzhou/",
	"黑木涯"		: "/d/heimuya/",
	"衡山" 			: "/d/hengshan/",
	"恒山"			: "/d/henshan/",
	"黄河"			: "/d/huanghe/",
	"华山派"		: "/d/huashan/",
	"灵鹫宫"			: "/d/lingjiu/",
	"灵州"			: "/d/lingzhou/",
	"梅庄"			: "/d/meizhuang/",
	"明教" 			: "/d/mingjiao/",
	"青城山"		: "/d/qingcheng/",
	"全真派" 		: "/d/quanzhen/",
	"泉州" 			: "/d/quanzhou/",
	"少林寺" 		: "/d/shaolin/",
	"神龙岛"		: "/d/shenlong/",
	"嵩山"			: "/d/songshan/",
	"苏州"			: "/d/suzhou/",
	"泰山"			: "/d/taishan/",
	"桃花岛"		: "/d/taohua/",
	"天龙寺"		: "/d/tianlongsi/",
	"万劫谷"		: "/d/wanjiegu/",
	"武当山"		: "/d/wudang/",
	"侠客岛"		: "/d/xiakedao/",
	"襄阳"			: "/d/xiangyang/",
	"逍遥派"		: "/d/xiaoyao/",
	"五毒教"		: "/d/wudu/",
]);
string *allroom_file,room_file,*allplace_name,place_name;
void create()
{
	seteuid(getuid());
	set("channel_id", "挖宝精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "NAME挖宝精灵系统开始运行。");
    set_heart_beat(20);
}
void heart_beat()
{
mixed *sj;
string props;
object obname;
object ob=this_object();
object me=this_player();
sj = localtime(time());
write_file("/log/adm/wabao",sprintf(""));	
if(sj[1]%10==0&&!flag){
//if(1){
while (1){
load_room();
if (!load_object(room_file)->query("no_search"))	
break;
}
if(!mapp(load_object(room_file)->query("exits")))
return;
props=element_of(get_dir("/clone/vip/"));
props=replace_string(props,".c","");
room_file->set("wabao_props/"+props+"",1);
obname=load_object("/clone/vip/"+props+".c");
if(sj[1]%58==0&&!flaga){
update();  
flaga=1;
}
if(sj[1]%11==0) flaga=0;

if(sj[1]%59==0&&!flagb){
rm("/log/adm/wabao"); 
message("channel:chat",HIY"【挖宝】挖宝系统""："HIR"宝物刷新完成！"+NOR+"\n",users());			
flagb=1;
}else{
flagb=0;
}
write_file("/log/adm/wabao", sprintf("%s=%s\n",room_file,props));	
message("channel:chat",HIY"【挖宝】挖宝系统""："HIR"听说有人遗失了他的【"+obname->name()+""HIR"】，具体有人在"+place_name+"的"+room_file->short()+"看见过它，快去那里碰碰运气吧！"+NOR+"\n",users());		
//QQ_D->msg("【挖宝】挖宝系统""：听说有人遗失了他的【"+no_color(obname->name())+"】，具体有人在"+no_color(place_name)+"的"+no_color(room_file->short())+"看见过它，快去那里碰碰运气吧！");	
flag=1;
}else{
flag=0;
}
}

int load_room()
{
allplace_name=keys(room_place);
place_name=allplace_name[random(sizeof(allplace_name))];
allroom_file=stat(room_place[place_name]);
foreach (room_file in allroom_file){
if (strsrch(room_file,".c")==-1)
allroom_file-=({room_file});
}
room_file=room_place[place_name]+allroom_file[random(sizeof(allroom_file))];
}
int update()
{
int i,ii,iii;
string is,obj,*line;
object room,where;
iii=file_size("/log/adm/wabao");
if(iii<1)
return 1;	
is = read_file("/log/adm/wabao");	
line = explode(is,"\n");
for(i=0;i<sizeof(line);i++){
sscanf(line[i],"%s=%s",room,obj);
room=load_object(""+room+"");
room->delete("wabao_props");
}
message("channel:chat",HIY"【挖宝】挖宝系统""："HIR"宝物刷新中..."+NOR+"\n",users());			
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
