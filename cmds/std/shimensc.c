//随从任务
// by name 2021.4.19
//QQ：3468713544

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{    
    string *d,dd;
    object npc;
    int i;
      d = ({      
        "/d/dali/northgate", 
	    "/d/dali/southgate",
		"/d/dali/shanlu2", 
		"/d/dali/buxiongbu",
		"/d/dali/jinzhihe", 
		"/d/dali/xiaodao1",
		"/d/dali/tianweijing", 
		"/d/dali/wuding",
		"/d/dali/luwang", 
		"/d/dali/gudao",
	    "/d/dali/biluoxueshan",
		"/d/dali/zhenxiong",
		"/d/dali/yixibu", 
		"/d/dali/cangshanzhong",
		"/d/dali/wumeng", 
	    "/d/foshan/street1", 
	    "/d/foshan/southgate",
	    "/d/quanzhen/xijie", 
	    "/d/quanzhen/nanjie",
	    "/d/changan/dong-chengmen", 
	    "/d/changan/nan-chengmen",
		"/d/changan/xi-chengmen", 
		"/d/changan/bei-chengmen",
		"/d/changan/qinglong2", 
		"/d/changan/baihu2",
     	"/d/city/beimen", 
      	"/d/city/nanmen",
	    "/d/city/ximen", 
      	"/d/city/dongmen",
		"/d/huashan/pingxinshi", 
	    "/d/village/square",
	    "/d/village/wexit",	          
        //扬州
		"/d/city/beimen",
		"/d/city/nanmen",
		"/d/city/ximen",
		"/d/city/dongmen",		
		//泉州
		"/d/quanzhou/haigang",	
	    "/d/quanzhou/nanmen",	
	    "/d/quanzhou/ximen",	
	    "/d/quanzhou/beimen",	
	    //佛山
	    "/d/xiakedao/haibin",	
	    "/d/xiakedao/zhuwu",	
	    "/d/foshan/street1",	
	    "/d/foshan/street5",	
	    //襄阳
	    "/d/xiangyang/southgate1",	
	    "/d/xiangyang/eastgate1",	
	   "/d/xiangyang/westgate1",	
	   "/d/xiangyang/northgate1",	
	   //华山
	    "/d/huashan/path1",	
	    "/d/huashan/qingke",	
	   "/d/huashan/qianchi",	
	    "/d/huashan/laojun",	
	    //成都
	    "/d/city3/qingyanggong",		    	      	    	    	    			
    	});          
    	if(!me->query("sc") )
    	return notify_fail("这是随从专用任务，你不能使用。\n");
    	     
        if (me->is_busy())
        return notify_fail("你正忙著呢。\n");
        if (me->is_fighting())
        return notify_fail("你现在正在战斗！\n");
	npc = new("/clone/npc/sc-ren");
    dd = d[random(sizeof(d))];
	npc->move(dd);	
	me->move(dd);	
	me->kill_ob(npc);
	return 1;
}


/*
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
string *path=({
"/d/gumu/",
"/d/quanzhen/",
"/d/songshan/",
"/d/huanghe/",
"/d/xiangyang/",
"/d/hangzhou/",
"/d/xueshan/",
"/d/meizhuang/",
"/d/heimuya/",
"/d/foshan/",
"/d/beijing/",
"/d/qingcheng/",
"/d/emei/",
"/d/city3/",
"/d/hengshan/",
"/d/changan/",
"/d/yanziwu/",
"/d/xuedao/",
"/d/lingzhou/",
"/d/taohua/",
"/d/taishan/",
"/d/baituo/",
"/d/shaolin/",
"/d/wudang/",
"/d/huashan/",
"/d/guiyun/",
"/d/gaibang/",
"/d/xingxiu/",
"/d/suzhou/",
"/d/lingjiu/",
"/d/mingjiao/",
"/d/xiaoyao/",
"/d/guanwai/",
"/d/city/",
"/d/fuzhou/",
"/d/quanzhou/",
"/d/dali/",
"/d/tianlongsi/",
"/d/shenlong/",
"/d/henshan/",
"/d/xiakedao/",
"/d/wanjiegu/",
});
string *paths;
object room,npc;

//if(!me->query("sc"))   
//return notify_fail("这是随从专用任务，你不能使用。\n");
if(me->is_busy())
return notify_fail("你正忙著呢。\n");
if (me->is_fighting())
return notify_fail("你现在正在战斗！\n");
paths=deep_path_list(element_of(path));
room=load_object(element_of(paths)+".c");
if(!objectp(room))
return 1;
if(room->set_name()||room->query("age"))
return 1;
if(room->short()==0)
return 1;
if(room->query("no_fight"))	
return 1;
if(strsrch(room->short(),"无名氏") != -1)
return 1;
if(strsrch(element_of(paths),".h") != -1)
return 1;

npc=new("/clone/npc/sc-ren");
write("执行结果："+replace_string(element_of(paths),".c","")+"\n");
npc->move(replace_string(element_of(paths),".c",""));
me->move(replace_string(element_of(paths),".c",""));	
me->kill_ob(npc);
return 1;
}
*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
