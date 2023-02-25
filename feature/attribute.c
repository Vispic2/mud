// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
#include <ansi.h> 
#include <command.h>
#include <dbase.h>
#include <skill.h>

int query_str()
{
	mapping sk;
	int str;
	int improve = 0;
	int lx = 0;
	int num=0;
	str = query("str");
	if (! mapp(sk = query_skills()))
		return str;

	improve += (int)sk["unarmed"] /30;
	improve += (int)sk["cuff"] /30;
	improve += (int)sk["finger"] /30;
	improve += (int)sk["strike"] /30;
	improve += (int)sk["hand"] /30;
	improve += (int)sk["claw"] /30;
	improve += (int)query_temp("suit_skill/unarmed") /30;
	improve += (int)query_temp("suit_skill/cuff") /30;
	improve += (int)query_temp("suit_skill/finger") /30;
	improve += (int)query_temp("suit_skill/strike") /30;
	improve += (int)query_temp("suit_skill/hand") /30;
	improve += (int)query_temp("suit_skill/claw") /30;
	lx = (int)sk["longxiang-gong"] / 30;
	if (lx >= 13) lx = 15;

	  return str + improve + lx +query_temp("suit_eff/strength") + query_temp("apply/str");
	
}

int query_int()
{
	mapping sk;
	int str;
	int improve = 0;
	int num=0;
	
	str = query("int");
	if (! mapp(sk = query_skills()))
	return str;
	improve = (int)sk["literate"]+(int)query_temp("suit_skill/literate");
       
	    
	      return str + (improve / 10) + query_temp("apply/int")+query_temp("suit_eff/intelligence");   
}

int query_con()
{
	mapping sk;
	int str;
	int improve = 0;
	int num=0;

	str = query("con");
	if (! mapp(sk = query_skills()))
		return str;

	improve = (int)sk["force"]+(int)query_temp("suit_skill/force");
     
	   
	      return str + (improve / 10) + query_temp("apply/con")+query_temp("suit_eff/constitution");
}

int query_dex()
{
	mapping sk;
	int str;
	int improve = 0;
	int num=0;

	str = query("dex");
	if (! mapp(sk = query_skills()))
		return str;

	improve = (int)sk["dodge"]+(int)query_temp("suit_skill/dodge");
      
	    
	     return str + (improve / 10) + query_temp("apply/dex")+ query_temp("suit_eff/spirituality");     
}

int query_per(string arg)
{
	int per;
	int age;
	int ac;
	int num=0;
	per = (int)query("per") + query_temp("apply/per");
	if (query("special_skill/youth"))
		return per;

	age = query("age");

	ac = query_skill("art-cognize", 1);
	if (ac < 100)
	{
		if (age > 70) per -= 6; else
		if (age > 60) per -= 5; else
		if (age > 50) per -= 4; else
		if (age > 40) per -= 3; else
		if (age > 30) per -= 2;
	}
	 per += ac / 20 ;
     
	     
	      return per;  
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
