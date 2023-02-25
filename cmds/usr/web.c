int main(object me,string arg)
{
string str;

	if(!arg)
	{
		str = ZJOBLONG"请选择你登陆的方式 为你展示更好的排版"ZJBR"目前排版"+(me->query("web")?"【客户端】":"【网页端】")+"模式\n";
		str+=ZJOBACTS2+ZJMENUF(2,2,10,28);
		str +=
		HIR"客户端:web app"ZJSEP
        HIR"网页端"NOR":web js";         
		message("vision", str+"\n", me);		
	}

if(arg=="app"){
me->set("web",1);
write("切换客户端成功。\n");
}
if(arg=="js"){
me->delete("web");
write("切换网页端成功。\n");
}

return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
