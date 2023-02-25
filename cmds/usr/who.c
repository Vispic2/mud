




//by name 2021.3.15

//感谢24602818教我ZJ协议ZJOBACTS2
#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
#include <tomud.h>
#define ENGLISH_MUD_NAME INTERMUD_MUD_NAME
inherit F_CLEAN_UP;

void create();
nosave int busy=0;

	
mapping mlist = ([
"丐帮"	:"丐帮"     ,
"全真"	:"全真教"  ,
"峨眉"	:"峨嵋派"   ,
"古墓"	:"古墓派"  ,
"华山"	:"华山派"   ,
"灵鹫"	:"灵鹫宫"   ,
"少林"	:"少林派" ,
"神龙"	:"神龙教"  ,
"桃花"	:"桃花岛"   ,
"武当"	:"武当派"   ,
"逍遥"	:"逍遥派"   ,
"星宿"	:"星宿派"   ,
"血刀"	:"血刀门"   ,
"雪山"	:"雪山寺"   ,
"云龙"	:"云龙门"  ,
"段氏"	:"段氏皇族",
"慕容"	:"慕容世家" ,
"欧阳"	:"欧阳世家" ,
"胡家"	:"关外胡家" ,
"剑宗"	: "华山剑宗" ,
"玄冥"	: "玄冥谷" ,
"明教"	: "明教" ,
"日月"    : "日月神教" ,
"魔教"   : "魔教" ,
"移花"  : "移花宫" ,
"五毒"   : "五毒教",
"御剑"   : "飞天御剑流" ,
"唐门"   : "唐门" ,
"绝情"   : "绝情谷" ,
"雁荡"   : "雁荡派" ,
// "凌霄"   : "凌霄城" ,
"红花"   : "红花会" ,
]);

void create() { seteuid(getuid()); }
int familys(object me,string family);
void more_str(string tab, string str, int line, int page)
{
	int i, j, now, all;
	string show,*text,*topics,topic;
    object me;
    me=this_player();
	show = tab;
	

    
	text = explode(str,"\n");
	all = sizeof(text)/line;
	if(sizeof(text)%line) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*line;
	i = page*line;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;
	topics = explode(str,"/");	
	if(!sizeof(topics) == 0){
	topic = topics[sizeof(topics)-1];
	show += sprintf("◎ %s(Wulin)在线玩家(%d/%d页)：\n",CHINESE_MUD_NAME,page,all);
    if(me->query("web")){
	
	show += ZJOBACTS+ZJMENUF(1,9,12,35);
	show +=
	"剑宗"+ZJBR+""+familys(me,mlist["剑宗"])+"人:who 剑宗"ZJSEP
	"少林"+ZJBR+""+familys(me,mlist["少林"])+"人:who 少林"ZJSEP
	"武当"+ZJBR+""+familys(me,mlist["武当"])+"人:who 武当"ZJSEP
	"丐帮"+ZJBR+""+familys(me,mlist["丐帮"])+"人:who 丐帮"ZJSEP
	"全真"+ZJBR+""+familys(me,mlist["全真"])+"人:who 全真"ZJSEP
	"段氏"+ZJBR+""+familys(me,mlist["段氏"])+"人:who 段氏"ZJSEP
	"慕容"+ZJBR+""+familys(me,mlist["慕容"])+"人:who 慕容"ZJSEP
	"雪山"+ZJBR+""+familys(me,mlist["雪山"])+"人:who 雪山"ZJSEP
	"灵鹫"+ZJBR+""+familys(me,mlist["灵鹫"])+"人:who 灵鹫"ZJSEP
	"峨嵋"+ZJBR+""+familys(me,mlist["峨眉"])+"人:who 峨眉"ZJSEP
	"桃花"+ZJBR+""+familys(me,mlist["桃花"])+"人:who 桃花"ZJSEP
	"神龙"+ZJBR+""+familys(me,mlist["神龙"])+"人:who 神龙"ZJSEP
	"古墓"+ZJBR+""+familys(me,mlist["古墓"])+"人:who 古墓"ZJSEP
	"星宿"+ZJBR+""+familys(me,mlist["星宿"])+"人:who 星宿"ZJSEP
	"逍遥"+ZJBR+""+familys(me,mlist["逍遥"])+"人:who 逍遥"ZJSEP
	"血刀"+ZJBR+""+familys(me,mlist["血刀"])+"人:who 血刀"ZJSEP
	"欧阳"+ZJBR+""+familys(me,mlist["欧阳"])+"人:who 欧阳"ZJSEP
	"胡家"+ZJBR+""+familys(me,mlist["胡家"])+"人:who 胡家"ZJSEP
 	"魔教"+ZJBR+""+familys(me,mlist["魔教"])+"人:who 魔教"ZJSEP
//	"玄冥"+ZJBR+""+familys(me,mlist["玄冥"])+"人:who 玄冥"ZJSEP
	"明教"+ZJBR+""+familys(me,mlist["明教"])+"人:who 明教"ZJSEP
	"移花"+ZJBR+""+familys(me,mlist["移花"])+"人:who 移花"ZJSEP
//	"御剑"+ZJBR+""+familys(me,mlist["御剑"])+"人:who 御剑"ZJSEP
    "五毒"+ZJBR+""+familys(me,mlist["五毒"])+"人:who 五毒"ZJSEP
    "日月"+ZJBR+""+familys(me,mlist["日月"])+"人:who 日月"ZJSEP
    "唐门"+ZJBR+""+familys(me,mlist["唐门"])+"人:who 唐门"ZJSEP
	"华山"+ZJBR+""+familys(me,mlist["华山"])+"人:who 华山\n";
	
	}
	show +=	ZJOBACTS2+ZJMENUF(2,2,8,40);
	show += "上一页:who "+(page-1)+ZJSEP"下一页:who "+(page+1)+ZJSEP;
	show += implode(text[j..i], ZJSEP);
	write(show+"\n");
}else{

write(ZJOBLONG+HIG"该门派没有任何玩家！！！"NOR"\n");
}

}


int familys(object me,string family)
{
int ts;
object *o;
object wan;
o=users();
foreach(wan in o){
if(wan->query("family/family_name")==family){
ts+=1;
}
}
return ts;
}



mixed main(object me, string arg, int remote)
{
	string str;
	object *ob;
	int page,i;
	string name, *option;
	object *list;
	int j, ppl_cnt,wiz_cnt;
	int opt_long, opt_id, opt_wiz;
	string mlists="";
	int SendInterMud=0;
	string HostName,strMsg;	
	
  	if(arg=="丐帮"||arg=="全真"||arg=="峨眉"||arg=="古墓"||arg=="华山"||arg=="灵鹫"||arg=="少林"||arg=="神龙"||arg=="桃花"||arg=="武当"||arg=="逍遥"||arg=="星宿"||arg=="血刀"||arg=="雪山"||arg=="云龙"||arg=="段氏"||arg=="慕容"||arg=="欧阳"||arg=="胡家"||arg=="剑宗"||arg=="玄冥"||arg=="明教"||arg=="日月"||arg=="魔教"||arg=="移花"||arg=="五毒"||arg=="御剑"||arg=="唐门"||arg=="绝情"||arg=="雁荡"||arg=="凌霄"||arg=="红花"){  	  	
	str="";
	i=0;
	wiz_cnt = 0;
	ppl_cnt = 0;
	if(remote && sizeof(arg)<2) arg="";
	if( !arg ){
		page = 1;
	}	
	else if(sscanf(arg,"%d",page)!=1)
	{
		page = 1;
	}					
	list = sort_array(children(USER_OB), "sort_user2", this_object());
	j = sizeof(list);
	while( j-- )
	{

		if( !environment(list[j]) ) continue;
		if(me && !me->visible(list[j]) ) continue;
		if(!me && (int)list[j]->query("env/invisibility")>0 ) continue;	
		if(list[j]->query("family/family_name")!=mlist[arg]){
		continue;
		}
       str += sprintf(HIW"【门派】"HIY"%s"+NOR+ZJBR+HIW+"【等级】%d级"ZJBR"%s%s"NOR":look %s\n",list[j]->query("family/family_name")?list[j]->query("family/family_name"):"无门无派",list[j]->query("level"),RANK_D->query_rank(list[j]),list[j]->name(),list[j]->query("id"));
	    ppl_cnt ++;
		wiz_cnt ++;
	}
	
	

	more_str(ZJOBLONG, str, 10, page);	
	return 1;		   	
	}else{
	str="";
	i=0;	
	wiz_cnt = 0;
	ppl_cnt = 0;
	if(remote && sizeof(arg)<2) arg="";
	if( !arg ){
		page = 1;
	}		
	else if(sscanf(arg,"%d",page)!=1){
		page = 1;
	}
		
	list = sort_array(children(USER_OB), "sort_user2", this_object());
	j = sizeof(list);
	while( j-- )
	{
		if( !environment(list[j]) ) continue;
		if(me && !me->visible(list[j]) ) continue;
		if(!me && (int)list[j]->query("env/invisibility")>0 ) continue;
 //       str += sprintf(""HIW"【门派】"HIY"%s"+NOR+ZJBR+""HIW"【等级】%d级"+ZJBR+HIC+"【姓名】"HIG"%s(%s)"NOR":look %s\n",list[j]->query("family/family_name")?list[j]->query("family/family_name"):"无门无派",list[j]->query("level"),list[j]->name(),wizardp(me)?list[j]->query("id"):"***",list[j]->query("id"));
	    str += sprintf(HIW"【门派】"HIY"%s"+NOR+ZJBR+HIW+"【等级】%d级"ZJBR"%s%s"NOR":look %s\n",list[j]->query("family/family_name")?list[j]->query("family/family_name"):"无门无派",list[j]->query("level"),RANK_D->query_rank(list[j]),list[j]->name(),list[j]->query("id"));
		ppl_cnt ++;
		wiz_cnt ++;	
	}
	more_str(ZJOBLONG, str, 10, page);
	return 1;		   	
	}
	return 1;	
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;

	if( wizardp(ob1) && wizardp(ob2) )
	return (int)SECURITY_D->get_wiz_level(ob2) 
		- (int)SECURITY_D->get_wiz_level(ob1);

	if( ob1->query("id") && !ob2->query("id") )
	return -1;
	if( ob2->query("id") && !ob1->query("id") )
	return 1;
	if( !ob1->query("id") && !ob2->query("id") )
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
	return strcmp(ob2->query("id"), ob1->query("id"));
}

int sort_user2(object ob1, object ob2)
{
	 return (int)ob1->query("combat_exp") - (int)ob2->query("combat_exp");
}

int help(object me)
{
write(@HELP
指令格式 : who [@<MudName>] [-l|-i|-w]

这个指令可以列出所有在线上或连线中的 Mud 的玩家及其等级。
@<MudName> [-l|-i|-w] 例：who @The.Master.Of.Hero -w

-l 选项列出较长的讯息。
-i 只列出玩家的英文代号。
-w 只列出线上所有的巫师。
 
相关指令： finger
HELP
	);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
