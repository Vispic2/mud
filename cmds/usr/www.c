//#include <ansi.h>
inherit F_CLEAN_UP;
mapping status = ([]);
object ob;
int http(int fd){
    socket_write(fd, status[fd]["http"]); return 1;
}
int receive_data(int fd, mixed result){
    if(sizeof(explode(result,""))>1000000){
    write_file(__DIR__+"www.txt",result,1);
    tell_object(ob,"响应字符太多，已将响应结果保存至www.txt文件\n");
    socket_close(fd);
    return 1;
    }
    tell_object(ob,ZJOBLONG+replace_string(result,"\n",ZJBR)+"\n");    
    socket_close(fd);
    return 1;
}
int receive_callback(int fd, mixed result){
    socket_close(fd); return 1;
}
int socket_shutdown(int fd){
    socket_close(fd); return 1;
}
int send_request(string host,string port,string path){
    int fd;
    int ret;    
    fd = socket_create(1, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "GET " + path + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
    ret = socket_connect(fd, host+" "+port, "receive_data", "http");
    if (ret != 1) {
    socket_close(fd);
    }
    return 1;
}   
int main(object me,string arg)
{
string host,port,path;
ob=me;
if(sscanf(arg,"%s %s %s",host,port,path)==3){
send_request(host,port,path);
}else{
write("host por path\n");
return 1;
}
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
