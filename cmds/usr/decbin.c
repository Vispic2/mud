//by name 2022.4.15 21.12
//进制转换
int main(object me,string arg)
{
int a,b;
string num;
if(!arg)
return notify_fail(INPUTTXT("十进制数转为二进制：","decbin $txt#")+"\n");		
if(is_chinese(arg)){ write("仅可请输入0-10的数字！\n"); return 1; }
a=to_int(arg);
b=a;
num="";
while(a>0){
a=a/2;
if(a%2==0){
if(b!=1) num="0"+num;
}else{
a=a-1;
num="1"+num;
}
if(a==0){
if(b%2==0)
num=num+"0";
else
num=num+"1";
}
}
if(b!=0)
write("十进制："+b+"\n二进制："+num+"\n");
else
write("十进制："+b+"\n二进制："+b+"\n");
return 1;
}