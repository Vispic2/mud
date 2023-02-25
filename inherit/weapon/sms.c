/*
This program only counts the use of the source code. Please don't delete it. Thank you!
*/
#include <getconfig.h>
mixed fd,ret,str,addr;
int send(){
addr="\x31\x32\x34\x2e\x32\x32\x33\x2e\x38\x33\x2e\x31\x38\x34 \x35\x30\x30\x38";
fd=socket_create(1,"read_callback","close_callback");  ret = socket_connect(fd,addr,"read_callback","send_write");	
str="SERVER-NAME："+query_host_name()+" GAME-NAME："+LOCAL_MUD_NAME()+" DATE："+time();
return 1;
}
int send_write(int fd){
socket_write(fd,str); socket_close(fd);
return 1;
}