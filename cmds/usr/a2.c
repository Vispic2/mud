#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
object eval_ob;
string filename, file;
if(me->query("wiz_start")){
filename="/tmp/debug_eval_file.c";
if(file_size(filename)!=-1) rm(filename);
if(eval_ob=find_object(filename)) destruct(eval_ob);
if(!arg) arg="write(\"ARG IS BLANK！\n\");";        
file = "#include <ansi.h>\nmixed eval(object me,string arg) { \n" + arg + "\nreturn 1; \n}\n";
write_file(filename, file, 1);
printf("Result = %O\n", filename->eval(me));
}
return 1;
}
