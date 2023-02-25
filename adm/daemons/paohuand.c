//by name 2021.5.28
//qq 21315491
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
public int main(object me,string arg);
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "跑环任务");
	CHANNEL_D->do_channel( this_object(), "sys", "跑环任务精灵开始运行。");
    set_heart_beat(10);
}
void heart_beat(){
object ob,*obs=users();
mixed *sj=localtime(time());
if(query("cisha_timesss")<time()){
write_file("/log/adm/cisha",sprintf(""));	
call_out("jiazai",1);
set("cisha_timesss",time()+1800);  //30分钟刷新一次
}

foreach(ob in obs){
if(mapp(ob->query("cisha"))&&ob->query("cisha/time")<time()){
tell_object(ob,"很遗憾，你并没有在5分钟内击杀"+ob->query("cisha/name")+"，系统以为你自动放弃改任务。\n");
tell_object(ob,ZJOBLONG"很遗憾，你并没有在5分钟内击杀"+ob->query("cisha/name")+"，系统以为你自动放弃改任务。\n");
ob->delete("cisha");
}
}
}
void jiazai(){
object ob,*obs=users();
foreach(ob in obs){
ob->delete("cisha");
}
main(this_object(),"init");
CHANNEL_D->do_channel( this_object(), "sys", "刺杀任务刷新。");
}
public int main(object me,string arg)
{
mapping where = ([
"苟读":"/d/xiaoyao/xiaodao4",
"康广陵":"/d/xiaoyao/muwu1",
"苏星河":"/d/xiaoyao/qingcaop",
"逍遥子":"/d/xiaoyao/shishi",
"薛慕华":"/d/xiaoyao/muwu2",
"澄观":"/d/shaolin/luohan1",
"澄知":"/d/shaolin/luohan2",
"澄明":"/d/shaolin/luohan3",
"澄净":"/d/shaolin/luohan4",
"澄坚":"/d/shaolin/luohan5",
"澄行":"/d/shaolin/luohan6",
"澄寂":"/d/shaolin/luohan7",
"澄灭":"/d/shaolin/luohan8",
"澄和":"/d/shaolin/luohan9",
"澄心":"/d/shaolin/banruo1",
"澄意":"/d/shaolin/banruo2",
"澄思":"/d/shaolin/banruo3",
"澄识":"/d/shaolin/banruo4",
"澄志":"/d/shaolin/banruo5",
"澄信":"/d/shaolin/banruo6",
"澄灵":"/d/shaolin/banruo7",
"澄欲":"/d/shaolin/banruo8",
"澄尚":"/d/shaolin/banruo9",
"达摩老祖":"/d/shaolin/damodong",
"道尘禅师":"/d/shaolin/wuqiku",
"道成禅师":"/d/shaolin/wuchang3",
"道果禅师":"/d/shaolin/twdian",
"道觉禅师":"/d/shaolin/wuchang",
"道品禅师":"/d/shaolin/zoulang3",
"道相禅师":"/d/shaolin/fangjuku",
"道象禅师":"/d/shaolin/yaopinku",
"道一禅师":"/d/shaolin/cjlou",
"道正禅师":"/d/shaolin/dxbdian",
"渡厄":"/d/shaolin/fumoquan",
"渡劫":"/d/shaolin/fumoquan",
"渡难":"/d/shaolin/fumoquan",
"慧合尊者":"/d/shaolin/hsyuan1",
"慧洁尊者":"/d/shaolin/hsyuan6",
"慧空尊者":"/d/shaolin/guangchang4",
"慧名尊者":"/d/shaolin/hsyuan5",
"慧如尊者":"/d/shaolin/houdian",
"慧色尊者":"/d/shaolin/hsyuan3",
"慧修尊者":"/d/shaolin/hsyuan2",
"慧虚尊者":"/d/shaolin/hsyuan4",
"慧真尊者":"/d/shaolin/cjlou1",
"空见":"/d/shaolin/houdian",
"清法比丘":"/d/shaolin/guangchang1",
"清观比丘":"/d/shaolin/qfdian",
"清乐比丘":"/d/shaolin/fzlou1",
"清善比丘":"/d/shaolin/guangchang2",
"清为比丘":"/d/shaolin/guangchang1w",
"清闻比丘":"/d/shaolin/gulou7",
"清无比丘":"/d/shaolin/guangchang1e",
"清晓比丘":"/d/shaolin/zhonglou7",
"清缘比丘":"/d/shaolin/jianyu",
"无名老僧":"/d/shaolin/cjlou",
"虚明":"/d/shaolin/shanmen",
"虚通":"/d/shaolin/shanmen",
"玄悲大师":"/d/shaolin/dmyuan2",
"玄慈大师":"/d/shaolin/fzlou2",
"玄寂大师":"/d/shaolin/putiyuan",
"玄苦大师":"/d/shaolin/luohan5",
"玄难大师":"/d/shaolin/banruo5",
"玄痛大师":"/d/shaolin/jlyuan",
"矮老者":"/d/huashan/chaoyang",
"成不忧":"/d/huashan/jzroad6",
"丛不弃":"/d/huashan/shangu",
"封不平":"/d/huashan/xiaowu",
"风清扬":"/d/huashan/luoyan",
"高老者":"/d/huashan/chaoyang",
"令狐冲":"/d/huashan/sgyhole1",
"岳不群":"/d/huashan/qunxianguan",
"岳夫人":"/d/huashan/jushi",
"陈玄风":"/d/huanghe/shidong",
"梅超风":"/d/huanghe/shidong",
"黄药师":"/d/taohua/dating",
"陆乘风":"/d/guiyun/shufang",
"曲灵风":"/d/taohua/shufang",
"黄蓉":"/d/taohua/wofang",
"陈志益":"/d/gumu/baoziyan",
"程瑶迦":"/d/quanzhen/nairongdian",
"崔志方":"/d/quanzhen/huizhentang",
"房志起":"/d/quanzhen/datang3",
"郝大通":"/d/quanzhen/guangning",
"姬清虚":"/d/gumu/juyan",
"李志常":"/d/quanzhen/cetang",
"刘处玄":"/d/quanzhen/jingxiushi",
"马钰":"/d/quanzhen/shiweishi",
"皮玄青":"/d/gumu/daxiaochang",
"丘处机":"/d/quanzhen/laojundian",
"孙不二":"/d/quanzhen/qingjing",
"谭处端":"/d/quanzhen/rongwutang",
"王重阳":"/d/quanzhen/shandong",
"王处一":"/d/quanzhen/wanwutang",
"尹志平":"/d/quanzhen/shijianyan",
"张志光":"/d/quanzhen/xianzhentang",
"赵志敬":"/d/quanzhen/jiaobei",
"周伯通":"/d/quanzhen/jiaobei",
"李莫愁":"/d/quanzhou/nanhu",
"林朝英":"/d/gumu/mishi8",
"小龙女":"/d/gumu/zhengting",
"杨过":"/d/gumu/zhengting",
"慕容龙城":"/d/guanwai/huandi1",
"慕容博":"/d/yanziwu/shangyu",
"慕容复":"/d/yanziwu/canheju",
"梅剑":"/d/lingjiu/damen",
"虚竹":"/d/lingjiu/dating",
"卓不凡":"/d/lingjiu/yan",
"阿紫":"/d/xingxiu/tianroad3",
"出尘子":"/d/xingxiu/xxroad5",
"丁春秋":"/d/xingxiu/riyuedong",
"狮吼子":"/d/xingxiu/tianroad2",
"天狼子":"/d/xingxiu/xxh3",
"摘星子":"/d/xingxiu/xxh1",
"范遥":"/d/mingjiao/dadian",
"韦一笑":"/d/mingjiao/dadian",
"小昭":"/d/mingjiao/neishi",
"杨逍":"/d/mingjiao/dadian",
"殷天正":"/d/mingjiao/dadian",
"张无忌":"/d/mingjiao/dadian",
"东方不败":"/d/heimuya/neishi",
"范松":"/d/heimuya/shijie1",
"王诚":"/d/heimuya/shidao2",
"向问天":"/d/quanzhou/chating",
"杨莲亭":"/d/heimuya/chengdedian",
"张乘风":"/d/heimuya/up1",
"张乘云":"/d/heimuya/shimen",
"赵鹤":"/d/heimuya/shijie2",
"宝象":"/d/xuedao/shandong2",
"血刀老祖":"/d/xuedao/shandong3",
"善勇":"/d/xuedao/wangyougu",
"胜谛":"/d/xuedao/sroad9",
"洪安通":"/d/shenlong/dating",
"陆高轩":"/d/shenlong/xiaowu",
"胖头陀":"/d/city/duchang",
"苏荃":"/d/shenlong/jushi",
"无根道长":"/d/shenlong/dating",
"许雪亭":"/d/shenlong/kongdi",
"殷锦":"/d/shenlong/houting",
"张淡月":"/d/shenlong/zoulang",
"程灵素":"/d/xiangyang/huapu",
"胡斐":"/d/guanwai/xiaowu",
"胡逸之":"/d/dali/paifang",
"平四":"/d/guanwai/xiaoyuan",
"欧阳锋":"/d/baituo/dating",
"欧阳克":"/d/city/beidajie1",
"达尔巴":"/d/xueshan/cangjingge",
"金轮法王":"/d/xueshan/dating",
"葛伦布":"/d/xueshan/shanmen",
"贡唐仓国师":"/d/xueshan/bieyuan",
"嘉木活佛":"/d/xueshan/cedian1",
"鸠摩智":"/d/xueshan/neidian",
"拉章活佛":"/d/xueshan/dadian",
"灵智上人":"/d/xueshan/cangjing",
"萨木活佛":"/d/xueshan/cedian2",
"谷虚道长":"/d/wudang/sanqingdian",
"莫声谷":"/d/wudang/nanyanfeng",
"清虚道长":"/d/wudang/chaotiangong",
"宋远桥":"/d/wudang/sanqingdian",
"张松溪":"/d/wudang/donglang1",
"俞岱岩":"/d/wudang/gaotai",
"殷梨亭":"/d/wudang/caolianfang",
"俞莲舟":"/d/wudang/houyuan",
"张三丰":"/d/wudang/xiaoyuan",
"贝锦仪":"/d/emei/duguangtai",
"道静师太":"/d/emei/cangjingge",
"方碧琳":"/d/emei/yunufeng",
"静慧师太":"/d/emei/qfadadian",
"静迦师太":"/d/emei/wanxingan",
"静空师太":"/d/emei/wnadian",
"李明霞":"/d/emei/huayanding",
"赵灵珠":"/d/emei/lianhuashi",
"灭绝师太":"/d/emei/hcahoudian",
"静闲师太":"/d/emei/qingyinge",
"静心师太":"/d/emei/hcazhengdian",
"静虚师太":"/d/emei/hcaguangchang",
"静玄师太":"/d/emei/woyunan",
"周芷若":"/d/emei/qinggong",
"劳德诺":"/d/huashan/laojun",
"洪七公":"/d/city/gbxiaowu",
"段正淳":"/d/dali/neitang",
]);

string *npc=({
"出尘子",
"慕容龙城",
"澄信",
"澄心",
"洪七公",
"道果禅师",
"段正淳",
"岳夫人",
"澄灵",
"梅剑",
"李莫愁",
"摘星子",
"杨过",
"曲灵风",
"道成禅师",
"慧真尊者",
"金轮法王",
"慕容博",
"黄药师",
"苏星河",
"孙不二",
"虚通",
"道静师太",
"道相禅师",
"欧阳克",
"胡逸之",
"静玄师太",
"清虚道长",
"达摩老祖",
"王诚",
"澄和",
"澄志",
"韦一笑",
"嘉木活佛",
"陆乘风",
"清闻比丘",
"欧阳锋",
"慕容复",
"矮老者",
"无根道长",
"陈玄风",
"周芷若",
"程灵素",
"慧合尊者",
"薛慕华",
"赵志敬",
"道品禅师",
"玄慈大师",
"无名老僧",
"陆高轩",
"丁春秋",
"康广陵",
"平四",
"崔志方",
"天狼子",
"澄知",
"澄观",
"道象禅师",
"玄痛大师",
"莫声谷",
"玄悲大师",
"清缘比丘",
"胜谛",
"葛伦布",
"虚明",
"血刀老祖",
"静闲师太",
"慧名尊者",
"李明霞",
"东方不败",
"宋远桥",
"张无忌",
"方碧琳",
"皮玄青",
"许雪亭",
"张三丰",
"澄欲",
"劳德诺",
"丘处机",
"陈志益",
"丛不弃",
"善勇",
"周伯通",
"程瑶迦",
"玄寂大师",
"令狐冲",
"慧空尊者",
"清善比丘",
"慧虚尊者",
"郝大通",
"林朝英",
"玄难大师",
"道尘禅师",
"贡唐仓国师",
"向问天",
"卓不凡",
"道一禅师",
"玄苦大师",
"张淡月",
"静迦师太",
"殷梨亭",
"道觉禅师",
"岳不群",
"虚竹",
"房志起",
"胖头陀",
"殷天正",
"静慧师太",
"高老者",
"王处一",
"张松溪",
"萨木活佛",
"刘处玄",
"达尔巴",
"宝象",
"范松",
"澄意",
"清为比丘",
"慧色尊者",
"清法比丘",
"谷虚道长",
"澄净",
"清无比丘",
"灵智上人",
"小龙女",
"赵鹤",
"胡斐",
"澄明",
"清晓比丘",
"杨莲亭",
"风清扬",
"慧洁尊者",
"澄灭",
"俞岱岩",
"赵灵珠",
"渡厄",
"范遥",
"静心师太",
"俞莲舟",
"澄思",
"洪安通",
"谭处端",
"王重阳",
"逍遥子",
"梅超风",
"慧修尊者",
"张乘云",
"澄坚",
"贝锦仪",
"渡劫",
"清乐比丘",
"灭绝师太",
"阿紫",
"渡难",
"小昭",
"道正禅师",
"张乘风",
"狮吼子",
"马钰",
"尹志平",
"李志常",
"成不忧",
"张志光",
"静空师太",
"空见",
"澄寂",
"杨逍",
"静虚师太",
"鸠摩智",
"苏荃",
"封不平",
"澄识",
"殷锦",
"苟读",
"清观比丘",
"黄蓉",
"澄行",
"姬清虚",
"慧如尊者",
"澄尚",
"拉章活佛",
"出尘子",
});
string msg,cisha,*line,name,room,mubiao,n1,n2,n3,n4,n5,n6,n7,n8;
object *obns,obn;
int exp,pot,yuanbao,iii;
if(arg=="main"){
iii=file_size("/log/adm/cisha");
if(iii<1){
write(HIR"刺杀任务暂时还未刷新！\n"NOR);	
return 1;
}
cisha = read_file("/log/adm/cisha");	
line = explode(cisha,"\n");
msg=ZJOBLONG"你目前可以随机领取到如下循环任务"ZJBR"这些任务将在"+CHINESE_D->chinese_time(query("cisha_timesss")-time())+"钟后刷新"ZJBR
""HIC"≡"HIY"一一一一一一一一一一一一一一一一一一一一"HIC"≡"+NOR+ZJBR;
foreach(mubiao in line){
sscanf(mubiao,"刺杀%s=%s",name,room);
msg+="【"+(1+random(3))+"级】"+ZJSIZE(27)+ZJURL("cmds:walk "+name+"")+HIC+"刺杀"+name+NOR+" ("+me->query("cisha/"+name+"_ok")+"/1"+") "+"["+(me->query("cisha/"+name)?""HIY"已领取"NOR"":""HIR"未领取"NOR"")+"]"+ZJBR;
}
msg+=""HIC"≡"HIY"一一一一一一一一一一一一一一一一一一一一"HIC"≡"+NOR+ZJBR;
if(mapp(me->query("cisha"))){
msg+="你已领取了刺杀"+HIR+me->query("cisha/name")+NOR+"任务"ZJBR;
msg+="距离次任务结束还有："+CHINESE_D->chinese_time(me->query("cisha/time")-time())+""ZJBR;
msg+="你可以执行如下操作："ZJBR;
}else{
msg+="你可以执行如下操作："ZJBR;
}

msg+=""HIC"≡"HIY"一一一一一一一一一一一一一一一一一一一一"HIC"≡"NOR"\n";
msg+=ZJOBACTS2+ZJMENUF(3,3,9,33)
"领取随机任务:cisha stat"ZJSEP
"提交完成任务:cisha ok";
tell_object(me,msg+"\n");
return 1;
}
if(arg=="init"){
n1 = npc[random(sizeof(npc))];
n2 = npc[random(sizeof(npc))];
n3 = npc[random(sizeof(npc))];
n4 = npc[random(sizeof(npc))];
n5 = npc[random(sizeof(npc))];
n6 = npc[random(sizeof(npc))];
n7 = npc[random(sizeof(npc))];
n8 = npc[random(sizeof(npc))];
write_file("/log/adm/cisha","刺杀"+n1+"="+where[n1]+"\n刺杀"+n2+"="+where[n2]+"\n刺杀"+n3+"="+where[n3]+"\n刺杀"+n4+"="+where[n4]+"\n刺杀"+n5+"="+where[n5]+"\n刺杀"+n6+"="+where[n6]+"\n刺杀"+n7+"="+where[n7]+"\n刺杀"+n8+"="+where[n8]+"\n",1);
me->delete("cisha");
return 1;
}
if(arg=="stat"){
if(me->query("cisha_time")>time()){
write("每1分钟才能行刺一次，还有"+(me->query("cisha_time")-time())+"秒\n");
write(ZJOBLONG"每1分钟才能行刺一次，还有"+(me->query("cisha_time")-time())+"秒\n");
return 1;
}
if(mapp(me->query("cisha"))){
write("你已经领取过任务了，先把他完成了吧\n");
write(ZJOBLONG"你已经领取过任务了，先把他完成了吧\n");
return 1;
}
cisha = read_file("/log/adm/cisha");	
line = explode(cisha,"\n");
sscanf(line[random(3)],"刺杀%s=%s",name,room);
me->set("cisha/name",name);
load_object(room+".c");
obns=all_inventory(find_object(room+".c"));
foreach(obn in obns){
if(obn->name()==me->query("cisha/name")){
obn->set("cisha/"+obn->name()+"_ok",1);
}
}
me->set("cisha/time",time()+300);  //限时5分钟
me->set("cisha/name",name);
me->set("cisha/"+name+"",1);
write("恭喜你随机抽取到了"HIR"刺杀"+name+"的任务"NOR"，任务要求在五分钟内完成，否则自动放弃本次任务，请抓紧时间吧！\n");
write(ZJOBLONG"恭喜你随机抽取到了"HIR"刺杀"+name+"的任务"NOR"，任务要求在五分钟内完成，否则自动放弃本次任务，请抓紧时间吧！\n");
return 1;

}
if(arg=="ok"){
if(!mapp(me->query("cisha"))){
write("你还是先去领取一个任务吧，不然你想提交什么?\n");
write(ZJOBLONG"你还是先去领取一个任务吧，不然你想提交什么?\n");
return 1;
}
if(!me->query("cisha/"+me->query("cisha/name")+"_ok")){
write("你还没完成这个任务呢，怎么想白嫖？\n");
write(ZJOBLONG"你还没完成这个任务呢，怎么想白嫖？\n");
return 1;
}
exp=500+random(500);
pot=200+random(200);
me->delete("cisha");
me->set("cisha_time",time()+60);
me->add("cisha_zs",1);  //刺杀轮总数
me->add("combat_exp",exp);
me->add("potential",pot);
me->add("yuanbaos",1);
write("恭喜你完成了本轮刺杀任务，你获得："+exp+"点"HIC"经验"NOR"，"+pot+"点"HIM"潜能"NOR"，1点"YEL"元宝票"NOR"！\n");
write(ZJOBLONG"恭喜你完成了本轮刺杀任务，你获得："+exp+"点"HIC"经验"NOR"，"+pot+"点"HIM"潜能"NOR"，1点"YEL"元宝票"NOR"！\n");
return 1;
}
return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
