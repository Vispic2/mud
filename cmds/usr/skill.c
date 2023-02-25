//cpasswd.c by XiaoYao
// Modify by snowman@SJ 01/05/1999.

#include <ansi.h>
int main(object me, string arg)
{
    string type;
	int num,x,lvl;
	float y = 1.0 / 3.0;
//int x=10000000*10;

	if (!arg)
	{
		write(ZJOBLONG + "技能等级查需要经验\n" + ZJOBACTS2+ZJMENUF(1,1,10,30) + "技能查经验:skill skill"ZJSEP"经验查等级:skill exp\n");
		return 1;
	}
	
	if (arg == "skill")
	{
		write(INPUTTXT("输入技能等级查所需经验", "skill skill $txt#") + "\n");
		return 1;
	}
               if (arg == "exp")
	{
		write(INPUTTXT("输入经验查目标等级", "skill exp $txt#") + "\n");
		return 1;
	}
	
	            if (sscanf(arg, "%s %d", type, num) == 2)
	              {
		if (type == "skill" && num > 0)
		{
	
			me->set("skillsss",num*num*num/10);
			write(HIW"当前输入技能等级大概需要 " +HIM+ me->query("skillsss") +NOR+HIW+ "点经验支持。注：等级越高差距越大！\n"NOR);
			return 1;
		}
		else
                        if (type == "exp" && num > 0)
		{
		
		
		/*
		     for(x=0;num>(x/10)*x*x;x++)
     {
     lvl = x+1;
     }
     */
     num=num*10;
     x = to_int(pow(to_float(num), y));
	
			//me->set("skillsss",lvl);
			//write(HIW"当前输入经验最大大概可以学 " +HIM+ me->query("skillsss") +NOR+HIW+ "级，注：经验越高差距越大！\n"NOR);
			write(HIW"当前输入经验最大大概可以学 " +HIM+ x+NOR+HIW+ "级，注：经验越高差距越大！\n"NOR);
			
			return 1;
		}
		else
		{
			write("请输入大于0的数。\n");
			return 0;
		}
	                 }
	             else
	               {
		write("输入格式错误，请重新输入。\n");
		return 0;
	                }
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
