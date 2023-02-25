// updateall.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string room_type,str,list,*dirs,*attr;
	int i;
	object ling,env;
	mapping dir = ([
		"east":"东面",
		"west":"西面",
		"south":"南面",
		"north":"北面",
	]);
	mapping dir2 = ([
		"east":"west",
		"west":"east",
		"south":"north",
		"north":"south",
	]);	
	env = environment(me);


	if(!arg)
	{
		str = ZJOBLONG"请选择要创建场景的位置："ZJBR+ZJBR;
		str += "　　　　　　　　"ZJURL("cmds:room north")+ZJSIZE(15)"北面"NOR+ZJBR+ZJBR;
		str += "　"ZJURL("cmds:room west")+ZJSIZE(15)"西面"NOR"　　　　　　　　　　";
		str += ZJURL("cmds:room east")+ZJSIZE(15)"东面"NOR+ZJBR+ZJBR;
		str += "　　　　　　　　"ZJURL("cmds:room south")+ZJSIZE(15)"南面"NOR+ZJBR;
		write(str+"\n");
		return 1;
	}

	attr = explode(arg," ");

	if(sizeof(attr)==1)
	{
		if(!dir[arg])
			return notify_fail(HIY"方向选择有误！！"NOR"\n");
		if(env->query("exits/"+arg))
			return notify_fail(HIY"此方向已有场景了不能重复创建！！"NOR"\n");

		
		write(INPUTTXT("你选择在"HIY+dir[arg]+NOR"创建新场景"ZJBR"如确认无误请设定场景的名称(2-5纯中文字)：","room "+arg+" $txt#")+"\n");
		return 1;
	}
	else if(sizeof(attr)==2)
	{
		if(!is_chinese(attr[1]))
		return notify_fail(HIY"场景名字必须是纯中文！！"NOR"\n");
		if(strlen(attr[1])>12)
		return notify_fail(HIY"场景名字最多只能用6个汉字！！"NOR"\n");
		write(INPUTTXT("你所设定的场景名字是"HIY+attr[1]+NOR+ZJBR"确认无误的话，请设定场景的"HIG"英文代号"NOR+ZJBR"(id，纯小写字母和数字组合，尽量符合名称，例如：guangchang)：","room "+arg+" $txt#")+"\n");
		return 1;
	}
	else if(sizeof(attr)==3)
	{
		if(!dir[attr[0]])
		return notify_fail(HIY"方向选择有误！！"NOR"\n");
		if(env->query("exits/"+attr[0]))
		return notify_fail(HIY"此方向已有场景了不能重复创建！！"NOR"\n");
    	if(strlen(attr[1])>12)
		return notify_fail(HIY"场景名字最多只能用6个汉字！！"NOR"\n");
		if(!is_legal_id(attr[2]))
		return notify_fail(HIY"场景英文代号必须是纯小写英文或数字！！"NOR"\n");
		if(strlen(attr[2])>12)
		return notify_fail(HIY"场景英文代号最多只能用12个字符！！"NOR"\n");
		dirs = explode(base_name(env),"/");
		list = "//by name with yixiao\n";	
		list += "#include <ansi.h>\n";
		list += "inherit ROOM;\n\n";
		list += "void create()\n{\n";
		list += "	set(\"short\",\""+attr[1]+"\"NOR);\n";
     	list += "	set(\"long\",\"这里是"+attr[1]+"\");\n";
		list += "	set(\"exits\", ([\n";
		list += "		\""+dir2[attr[0]]+"\" : \""+base_name(env)+"\",\n";
		list += "	]));\n";
		list += "	setup();\n";
		list += "}\n";

		dirs = dirs[0..(sizeof(dirs)-2)];		
		str = sprintf("/cmds/d/%s",attr[2]);

		if(file_size(str+".c")>0)
		return notify_fail(HIY"同名文件已存在，请更改英文代号再次尝试！！"NOR"\n");
	
		BUILD_D->build_file(me,str+".c",list);
		list = BUILD_D->get_file_code(env);		
		list = replace_string(list,"set(\"exits\", ([","set(\"exits\", ([\n		\""+attr[0]+"\" : \""+str+"\",");
		BUILD_D->build_file(me,base_name(env)+".c",list);		
		env->set("exits/"+attr[0],str);
		write(HIY"生成完毕，请进入新场景通过控制台修改设定场景的其他属性..."NOR"\n");
	}
	else
	return notify_fail("格式错误！！请参考---名称："HIY"中心广场"NOR"，id："HIG"guangchang"NOR"，名字要用纯中文，英文id由小写字母或者数字组成。\n");
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
