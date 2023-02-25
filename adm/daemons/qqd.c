//BY Name
//QQ：21315491
/*
下载MiraiAndroid
https://github.com/mzdluo123/MiraiAndroid/releases/
下载之后安装到你的手机上，并且完成登录；登录方法在主屏幕右上角的自动登录里，登录过程中需要验证请在通知栏内点击通知完成验证
登录成功后到左边菜单内找到高级功能，选择你得账号之后导出设备文件(device.json)发送到电脑，并覆盖电脑版文件，再次login QQ 密码即可成功登陆
*/
#include <ansi.h>
#define STREAM 1
#define EESUCCESS 1
// QQ消息API服务器配置
nosave string host = "127.0.0.1";
nosave string addr = "127.0.0.1 8080";
nosave string mirai_authKey = "1234567890";
nosave string mirai_qq = "3068998046";
// 游戏消息转发到指定的QQ群
nosave string group = "1074716854";
nosave mapping status = ([]);
nosave string session;
private void verify();
private void websocket();
private void control(string id,string msg,string qq);
void msg(string msg);
//void img(string msg);
string tribar_graph(int val, int eff, int max, string color);
string tribar_graph2(int val, int eff, int max, string color);
string tribar_graph3(int a);
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string bar_string = "■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□";
string blank_string3 = "□□□□□□□□□□□□";
string blank_string2 = "　　　　　　　　　　　　";
private void http(int fd)
{
    socket_write(fd, status[fd]["http"]);
}

private void control(string id,string msg,string qq)
{
int fd,ret,vip,i;
string id1,name1,data,str;
string *skill_str,*msgs;
object ob;
mapping my,mci;
mapping oprank = ([
	"宗师"     : HIW "宗师境界  ",
	"登峰造极" : HIY "★★★★☆",
	"超凡脱俗" : HIY "★★★★  ",
	"臻至化境" : HIR "★★★☆  ",
	"炉火纯青" : HIR "★★★    ",
	"已有大成" : HIC "★★☆    ",
	"非同凡响" : HIC "★★      ",
	"出类拔萃" : HIG "★☆      ",
	"身手不凡" : HIG "★	",
	"已有小成" : HIM "☆	",
]);
if(sscanf(id,"%s (%s)",name1,id1)!=2&&sscanf(id,"%s(%s)",name1,id1)!=2&&sscanf(id,"%s （%s）",name1,id1)!=2&&sscanf(id,"%s（%s）",name1,id1)!=2) return;
if(msg||
msg=="教程菜单"||
msg=="连接游戏"||
msg=="断开游戏"||
msg=="托管师门"||
msg=="查看属性"||
msg=="执行命令模式"||
msg=="退出命令模式"){
ob = LOGIN_D->find_body(id1);
if(ob){
if(msg=="MUD功能菜单"){
str= "QQ操作MUD人物系统V1.0";
str+="当前可用指令：\n";
str+="1、连接游戏\n"
"2、断开游戏\n"
"3、查看属性\n"
"4、托管师门\n"
"5、执行命令模式\n"
"6、退出命令模式\n"
"指南：首先将QQ群名字改成特定格式：游戏名字+空格+(游戏ID) 注：括号用英文 --> 前往游戏内使用指令qqd_lj修改绑定QQ --> 到QQ群里发送连接游戏即可。";
msg(str);
}else
if(msg=="执行命令模式"){
if(to_int(ob->query("qqd_key_qq"))!=to_int(qq)){
msg("请前往游戏输入指令：qqd_lj进行账号绑定，再来连接游戏！");
return;
}
if(!ob->query("qqd_start")){
msg("你目前还没有连接游戏，请连接游戏有再试！");
return;
}
if(ob->query("qqd_cmd_ok")){
msg("你目前已经开启了执行命令模式，退出此模式请输入退出命令模式\n当前模式状态："+(ob->query("qqd_cmd_ok")?"开启":"关闭")+"");
}else{
ob->set("qqd_cmd_ok",1);
msg("执行命令模式开启成功，当前模式下会将你发送的字符当成命令让人物执行，退出此模式请输入退出命令模式\n当前模式状态："+(ob->query("qqd_cmd_ok")?"开启":"关闭")+"");
}
}else

if(msg=="退出命令模式"){
if(to_int(ob->query("qqd_key_qq"))!=to_int(qq)){
msg("请前往游戏输入指令：qqd_lj进行账号绑定，再来连接游戏！");
return;
}
if(!ob->query("qqd_start")){
msg("你目前还没有连接游戏，请连接游戏有再试！");
return;
}

if(ob->query("qqd_cmd_ok")){
ob->delete("qqd_cmd_ok");
msg("退出命令模式成功，当前模式下不会将你发送的字符当成命令让人物执行，继续开启请输入执行命令模式\n当前模式状态："+(ob->query("qqd_cmd_ok")?"开启":"关闭")+"");
}else{
msg("你目前已经开退出了执行命令模式，继续开启请输入执行命令模式\n当前模式状态："+(ob->query("qqd_cmd_ok")?"开启":"关闭")+"");
}
}else

if(msg=="查看属性"){
if(to_int(ob->query("qqd_key_qq"))!=to_int(qq)){
msg("请前往游戏输入指令：qqd_lj进行账号绑定，再来连接游戏！");
return;
}
if(!ob->query("qqd_start")){
msg("你目前还没有连接游戏，请连接游戏有再试！");
return;
}
my = ob->query_entire_dbase();
mci = my["combat"];
if (! mci) mci = ([ ]);
if (playerp(ob) && (! stringp(my["born"]) || ! my["born"])){
msg("你的人物还没有出生呐");
return;
}
vip=ob->query("zjvip/level")*100;
str=RANK_D->query_rank(ob)+" "+ob->short(1)+"\n";
str+="━━━━━━━━━━━━━━━━━━━━━━━\n";		
str += sprintf( YEL  "【种族】" HIW"%-26.8s\n",ob->query("race"));		
str += sprintf( YEL  "【性别】" HIW "%-26.8s\n",ob->query("gender"));		
str += sprintf( YEL  "【性格】" HIW "%-28.28s\n",ob->query("character")?ob->query("character"):"暂无性格");
if (my["born_family"] && my["born_family"] != "没有"){
str += YEL "【家族】"HIG + my["born_family"]+" \n";
}else
if (stringp(my["born"]) && my["born"]){
str += YEL "【人氏】" HIG+ my["born"] +" \n";
}else{
str += HIG " 暂无人氏";
}	
str += sprintf( YEL  "【门派】" HIG "%-18.8s\n",ob->query("family/family_name")?ob->query("family/family_name"):"暂无门派" );
str += sprintf( YEL  "【师承】" HIG"%-18.18s\n",ob->query("family/master_name")?ob->query("family/master_name"):"暂无师傅" );
str += sprintf( YEL  "【帮派】" HIG"%-18.18s\n",ob->query("banghui/names")?ob->query("banghui/name"):"暂无帮会");
str += sprintf( YEL  "【坐骑】" HIG"%-18.18s\n",ob->query("huanshou")?ob->query("beast/beast_name"):"暂无坐骑");        
str += sprintf( YEL  "【随从】" HIG"%-18.18s\n",ob->query("scs")?ob->query("namesuicong"):"暂无随从");
str += sprintf( YEL  "【宠物】" HIG"%-18.18s\n",ob->query("petname")?ob->query("petname"):"暂无宠物");
if (playerp(ob)){
int age = ob->query("age");
int month = ob->query("mud_age");
if (age >= 60){
month -= (age - 60) * 86400 * 4;
month = (month - 118 * 86400) / 7200 / 4 + 1;
} else
if (age >= 30){
month -= (age - 30) * 86400 * 3;
month = (month - 28 * 86400) / 7200 / 3 + 1;
} else
if (age >= 18){
month -= (age - 18) * 86400 * 2;
month = (month - 4 * 86400) / 7200 / 2 + 1;
} else {
month -= (age - 14) * 86400;
month = month / 7200 + 1;
}              
if (month > 12 || month < 1)
month = 1;        
str += sprintf( YEL "【年龄】"MAG"%-24s\n",chinese_number(age) + "岁" +chinese_number(month) + "个月");
str += sprintf( YEL "【生辰】\n "MAG"%-28.28s\n",CHINESE_D->chinese_date(ob->query("birthday")));           
skill_str=keys(ob->query("special_skill"));
str +=YEL"【天赋技能】\n"NOR;
for(i=0; i<sizeof(skill_str); i++){
str +=HIC" -"+SPECIAL_D(skill_str[i])->name()+"-\n"NOR"";
}
} 
if(ob->query("zjvip/level")){
str += HIY "【会员等级】"+ob->query("zjvip/level")+ ""NOR"\n";
}else{
str += HIY "【会员等级】无"NOR"\n";
}
if ((int)ob->query("zhuanshi") > 0){
str += HIY "【转世次数】" + (ob->query("zhuanshi")) + ""NOR"\n";  		
}else{
str += HIY "【转世次数】无"NOR"\n";
}
if(ob->query("zjvip/all_pay") <1){
str += sprintf( HIY "【充值贡献】%s"HIY"\n"NOR,ob->query("zjvip/all_pay")?ob->query("zjvip/all_pay"):"暂无贡献");        
}else{
str += sprintf( HIY "【充值贡献】%d"HIY"\n"NOR,ob->query("zjvip/all_pay")?ob->query("zjvip/all_pay"):"暂无贡献");
}
if ((int)ob->query("yuanbao") > 0){
str += HIY "【目前元宝】" + (ob->query("yuanbao")) + ""NOR"\n";
}else{
str += HIY "【目前元宝】暂无元宝"NOR"\n";
}
if ((int)ob->query("balance") > 0){
str += HIY "【目前存款】" + MONEY_D->money_str((int)ob->query("balance")) + ""NOR"\n";
}else{
str += HIY "【目前存款】暂无存款"NOR"\n";
}		
if ((int)ob->query("zjvip/times") > 0){
str += HIY "【会员时间】\n "+CHINESE_D->short_time(ob->query("zjvip/times"))+ ""NOR"\n";
}
str += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );                
str += sprintf( HIY "【膂力】：" HIW "%d | %d " HIY "\n【悟性】：" HIW "%d | %d" NOR+YEL "\n" NOR ,ob->query("str"),ob->query_str(), ob->query("int"),ob->query_int());
str += sprintf( HIY "【根骨】：" HIW "%d | %d " HIY "\n【身法】：" HIW "%d | %d" NOR+YEL "\n" NOR ,ob->query("con"),ob->query_con(), ob->query("dex"),ob->query_dex());                
// if(ob->query("max_qi") >1&&ob->query("jing") >1&&ob->query("max_neili") >1){
// str += sprintf( HIC   "【气血】： %s  ",tribar_graph(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) );
// str += sprintf( HIC "\n【内力】： %s  ",tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
// str += sprintf( HIC "\n【精神】： %s  ",tribar_graph(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])));
// str += sprintf( HIC "\n【食物】： %s  ",tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), HIC));
// str += sprintf( HIC "\n【饮水】： %s  ",tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), HIC));
// }                     
str += sprintf( YEL "\n┣━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );	        
if (playerp(ob)){
string op;		
str += HIY "【拳脚功夫】" NOR;
if (op = ob->query("opinion/unarmed"))
str += oprank[op] + "	\n";
else
str += CYN "暂无评价	 \n";
str += NOR HIY "【兵器运用】" NOR;
if (op = ob->query("opinion/weapon"))
str += oprank[op] + "	\n";
else
str += CYN "暂无评价\n";
str += NOR HIY "【内家功夫】" NOR;
if (op = ob->query("opinion/force"))
str += oprank[op] + "	\n";
else
str += CYN "暂无评价   \n";
str += NOR HIY "【轻身功夫】" NOR;
if (op = ob->query("opinion/dodge"))
str += oprank[op] + "	\n";
else
str += CYN "暂无评价\n";	
}	
str += sprintf( YEL "" MAG "【杀生次数】" NOR HIR" %d位"NOR,(int)mci["MKS"] + (int)mci["PKS"]);
str += sprintf( YEL "" MAG "\n【杀死玩家】" NOR HIR" %d位"NOR,(int)mci["PKS"]);
str += sprintf( YEL "" MAG "\n【有意杀害】" NOR HIR" %d位"NOR,(int)mci["WPK"]);
str += sprintf( YEL "" MAG "\n【击晕玩家】" NOR HIR" %d位"NOR,(int)mci["DPS"]);
str += sprintf( YEL "" MAG "\n【正派人士】" NOR HIR" %d位"NOR,(int)mci["DPS_GOOD"]);
str += sprintf( YEL "" MAG "\n【邪派人士】" NOR HIR" %d位"NOR,(int)mci["DPS_BAD"]);
str += YEL "\n" NOR;
str += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━┫" NOR );
if (playerp(ob)){		
str += sprintf(HIC"\n【阅   历】 %7d",my["score"]);
str += sprintf(HIC"\n【贡   献】 %7d",my["gongxian"]);
str += sprintf(HIC"\n【威   望】 %7d",my["weiwang"]);
str += sprintf(HIC"\n【灵   慧】 %s%7d",my["magic_points"] < 100 ? HIC : HIC, (my["magic_points"] - my["magic_learned"]));
}		
if (my["shen"] >= 0)
str += sprintf(HIM "\n【正   气】 %7d", my["shen"]);
else
str += sprintf(HIM "\n【邪   气】 %7d", -ob->query("shen"));
str += sprintf(HIM "\n【戾   气】 %7d", my["total_hatred"]);
str += HIM "\n【容   貌】  ("+ob->query_per()+"/"+ob->query("per")+")\n【福   源】  ("+ob->query("kar")+"/"+ob->query("kar")+")"NOR"";
if ((int)mci["dietimes"]){
str += sprintf(HIR "你到目前为止总共到黑白无常那里串门%s次。"NOR"\n", chinese_number(mci["dietimes"]));
str += sprintf(HIR "上次遇害是%s。"NOR"\n", ob->query("combat/last_die"));
str += "";
} else
if (playerp(ob))
str += HIC "\n你到目前为止尚无死亡记录。"NOR"\n";
if (ob->query("birthday"))
str += HIG "注册时间：\n "+CHINESE_D->chinese_date(ob->query("birthday"),2)+NOR+"\n";
str += YEL "┗━━━━━━━━━━━━━━━【个人档案】━┛\n" NOR;
str += sprintf( HIW "现在的时间是：\n " + ctime( time() ) + ""NOR);
         	   
msg(no_color(str));
   
}else

if(msg=="托管师门"){
if(to_int(ob->query("qqd_key_qq"))!=to_int(qq)){
msg("请前往游戏输入指令：qqd_lj进行账号绑定，再来连接游戏！");
return;
}
if(!ob->query("qqd_start")){
msg("你目前还没有连接游戏，请连接游戏有再试！");
return;
}

if(ob->query("shimen/today")==(vip+5000)){
msg("你本周师门已经全部完成，下周再来吧！");
return;
}
if(ob->query("yqq")){
ob->force_me("set sign5 zdsm;yqq");
ob->force_me("set sign1 1");
}else{
ob->force_me("set sign5 zdsm");
ob->force_me("set sign1 1");
}
msg("开启托管师门成功\n目前状态：\n剩余师门次数："+(((5000+vip)-ob->query("shimen/today")))+"次\n当前师门难度："+(ob->query("shimen/nan")?ob->query("shimen/nan"):"初级")+"\n秒杀师门限权："+(ob->query("yqq")?"有":"无")+"\n离线任务限权："+(ob->query("lixian2")?"有":"无")+"");
}else
if(msg=="连接游戏"){
if(to_int(ob->query("qqd_key_qq"))!=to_int(qq)){
msg("请前往游戏输入指令：qqd_lj进行账号绑定，再来连接游戏！");
return;
}
//首次使用QQ连接MUD有奖励
if(!ob->query("qqd_duijie_ok")){  //先判断玩家是否已经接受过标记
data=read_file("/log/adm/qqd");
if(strsrch(""+data+"",""+qq+"") == -1){  //判断当前QQ是否已经绑定过游戏账号
ob->set("qqd_duijie_ok",1);
ob->set("qqd_qq",qq);
ob->add("potential",666666);
ob->add("yuanbao",1000);
write_file("/log/adm/qqd",qq+"\n");  //绑定成功，此QQ将不能绑定其他游戏账号。
msg("恭喜你首次对接成功，你获得了：\n潜能：66.6666万\n元宝：1000个！");
}else{
msg("该QQ账号已经对接过其他游戏账号了！");
}
}
if(ob->query("qqd_start")){
msg(name1+"("+ob->query("id")+")"+"\n目前已经连接上游戏了，连接状态："+(ob->query("qqd_start")?"成功":"失败")+"");
}else{
ob->set("qqd_start",1);
msg(name1+"连接成功\n你的游戏名字："+ob->name()+"\n游戏ID："+ob->query("id")+"");
}
}else
if(msg=="断开游戏"){
if(ob->query("qqd_start")){
ob->delete("qqd_start");
msg(name1+"断开连接成功\n你的游戏名字："+ob->name()+"\n游戏ID："+ob->query("id")+"");
}else{
msg(name1+"("+ob->query("id")+")"+"\n目前已经断开连接游戏了，连接状态："+(ob->query("qqd_start")?"成功":"失败")+"");
}
}else{
if(ob->query("qqd_cmd_ok")){
if(to_int(ob->query("qqd_key_qq"))!=to_int(qq)){
msg("请前往游戏输入指令：qqd_lj进行账号绑定，再来连接游戏！");
return;
}
if(!ob->query("qqd_start")){
msg("你目前还没有连接游戏，请连接游戏有再试！");
return;
}
i=ob->force_me(msg);
msg("执行命令："+msg+"\n执行结果：完成");
}
}
}else{
if(LOGIN_D->find_body(id1)==0) return;
msg(name1+"连接失败\n可能是你没有注册本MUD或者你的群名称格式不对\n格式：游戏名字 (游戏ID)");
}
}

}



private void receive_auth(int fd, mixed result)
{
    int n = strsrch(result, "{");    
    if (n > 0){
        mixed json;
        json = json_decode(trim(result[n..]));
        session = json["session"];
    }
    if (stringp(session)){
        socket_close(fd);
        verify();
    }
}
private void receive_verify(int fd, mixed result)
{
    int n = strsrch(result, "{");    
    if (n > 0){
        mixed json;
        json = json_decode(trim(result[n..]));
        if (!json["code"]){
            socket_close(fd);
            websocket();
        }
    }
}

private void receive_msg(int fd, mixed result)
{
    socket_close(fd);
}
private void receive_data(int fd, mixed result)
{
    string res;
    int n = strsrch(result, "{");
 //   tell_object(find_player("name"),"执行结果："+result+"\n");
    
     //   if (n > 0){
          if (n == 4 && strsrch(result, "}}}") > 0){
        mixed json;
        mapping sender, messageChain;
        string type;
        res = trim(result[n..]);
        json = json_decode(res);
       // debug_message(sprintf("%O", json));   
        sender = json["sender"];
        type = json["type"];       
        messageChain = json["messageChain"][1];
        if (type == "GroupMessage"){
            string msg ="[其它类型消息]";
            if (messageChain["type"] == "Plain"){
                msg = messageChain["text"];
            }
            else if (messageChain["type"] == "Face"){
                msg = "[表情]" + messageChain["name"];
            } 
            message("channel:chat",HIW+"【QQ群】"+HIW+sender["memberName"]+NOR+HIW+"：" + msg +""NOR"\n",users());
            control(sender["memberName"],msg,sender["id"]);
            //img("https://t9.baidu.com/it/u=260955245,3883981307&fm=193&app=53&size=w828&n=0&g=0n&f=jpeg?sec=1627990763&t=d514e82f2e34d396710efa12180095ef");
     }
  }
}

void msg(string msg)
{
    int fd;
    int ret;
    string path = "/sendGroupMessage";
    // 美化格式，不用转义
    string body = @RAW{
    "sessionKey": "%^session%^",
    "target": %^group%^,
    "messageChain": [
        {
            "type": "Plain",
            "text": "%^msg%^"
        }
    ]
}
RAW;
    body = terminal_colour(body, ([
        "session":session,
        "group":group,
        "msg":msg,
    ]));
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + sizeof(string_encode(body,"utf-8")) + "\r\n\r\n" + body;    
    ret = socket_connect(fd, addr, "receive_msg", "http");
    if (ret != EESUCCESS){        
        socket_close(fd);
    }    
}
private void receive_callback(int fd, mixed result)
{
}
private void socket_shutdown(int fd)
{
    socket_close(fd);
}
private void websocket()
{
    int fd;
    int ret;
    string path = "/message?sessionKey=" + session;
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "GET " + path + " HTTP/1.1\nHost: " + host + "\nUpgrade: websocket\nConnection: Upgrade\r\n\r\n";
    ret = socket_connect(fd, addr, "receive_data", "http");
    if (ret != EESUCCESS) {
    tell_object(find_player("name"),"错误：3\n");
    socket_close(fd);
    }
}

// 绑定session到QQ
private void verify()
{
    int fd;
    int ret;
    string path = "/verify";
    string body = "{\"sessionKey\":\"" + session + "\",\"qq\":\"" + mirai_qq + "\"}";    
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_verify", "http");
    if (ret != EESUCCESS){
       tell_object(find_player("name"),"错误：2\n");
       socket_close(fd);
    }
}
// 获取session
private void auth()
{
    int fd;
    int ret;
    string path = "/auth";
    string body = "{\"authKey\":\"" + mirai_authKey + "\"}";   
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_auth", "http");    
    if (ret != EESUCCESS){    
        //tell_object(find_player("name"),"错误：1\n");
        socket_close(fd);
    }   
}
void create()
{
auth();
set_heart_beat(180);
}

void heart_beat()
{
object qqd;
if(qqd = find_object("/adm/daemons/qqd")){
destruct(qqd);
}
load_object("/adm/daemons/qqd");
}

string status_color(int current, int max)
{
	int percent;

	if (max) percent = current * 100 / max;
	else percent = 100;

	if (percent > 100) return HIG;
	if (percent >= 90) return HIG;
	if (percent >= 60) return HIC;
	if (percent >= 30) return HIY;
	if (percent >= 10) return HIR;
	return RED;
}
string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph2(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string2[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph3(int a)
{
        return BLU + blank_string3[0..(23-a)] + NOR;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
