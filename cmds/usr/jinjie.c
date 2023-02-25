//by  寒江雪
/*
练体境，突破要求。2w内力，1w精力。加成：2k内力，1k精力。
练气境，突破要求。4w内力，2w精力。加成：4k内力，2k精力。
筑基境，突破要求。6w内力，3w精力。加成：6k内力，3k精力。
金丹境，突破要求。8w内力，4w精力。加成：8k内力，4k精力。
元婴境，突破要求。10w内力，5w精力。加成：1w内力，5k精力。
合体境，突破要求。12.5w内力，6.5w精力。加成：1w气血，四维加10点。
渡劫境，突破要求。15w内力，8w精力。加成：2w气血，四维加10点。
人仙境，突破要求。前往渡劫谷突破境界，20w内力，10w精力。加成：3w气血，四维加10点。
注意：特殊加成不影响使用左右互博。
*/
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string *jingjie = ({"肉体","炼体","炼气","筑基","金丹","元婴","合体","渡劫","人仙","人仙"});
     string str;
     if(!arg)
	{
	    str = ZJOBLONG +HIW "问世间谁人无忧，唯神仙逍遥无忧。大罗金仙居于大罗天，不老不死永生不灭，仙境极乐无所忧愁。红尘凡人居于地界，顺生应死繁衍不息，得失苦乐情欲交炽。"ZJBR
		""HIM+ZJSIZE(25)+"当前境界:"+jingjie[me->query("jingjie")]+NOR"\n";
		if(me->query("jingjie") >8)
		{
		str += ZJOBACTS2+ZJMENUF(2,2,9,31)+HIR"完成突破"":jinjie "+ (me->query("jingjies"))+ZJSEP+HIR"境界称号"NOR":jinjie ch";					
		}else
		{
		str += ZJOBACTS2+ZJMENUF(2,2,9,31)+HIR"突破"+jingjie[me->query("jingjie")+1]+":jinjie "+ (me->query("jingjie")+1)+ZJSEP+HIR"境界称号"NOR":jinjie ch";				
		}
		tell_object(me, str+"\n");
		return 1;
	}
	else
	 if(arg=="1") 
	{	  
	if (me->query("lt") == 1)
		return notify_fail(HIR"你的已经突破了练体境，没必要再突破一次 ！\n"NOR);		    
		if (me->query("max_neili") < 20000||me->query("max_jingli") < 10000)
		return notify_fail(HIR"你的内力不足2w或精力不足1w！不能突破当前境界！\n"NOR);				
        me->add("max_neili",2000);
        me->add("max_jingli",1000);
        me->set("lt",1);
        me->set("jingjie",1);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 体 境\n"NOR);
        CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"的境界突破到了练体境！");
}else
	if(arg=="2") 
	{	
	    if (me->query("lt") < 1 )
		return notify_fail(HIR"你连上一个境界都没突破还想跳级不成?！\n"NOR);	
		if (me->query("lq") == 1)
		return notify_fail(HIR"你的已经突破了练气境，没必要再突破一次 ！\n"NOR);	
		if (me->query("max_neili") < 40000||me->query("max_jingli") < 20000)
		return notify_fail(HIR"你的内力不足5w或精力不足2w！不能突破当前境界！\n"NOR);				
        me->add("max_neili",4000);
        me->add("max_jingli",2000);
        me->set("lq",1);
        me->set("jingjie",2);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        write(HIY"恭 喜 您 突 破 了 练 气 境\n"NOR);
        CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"的境界突破到了练气境！");
}else
	 if(arg=="3")
	{
	if (me->query("lq") < 1 )
	return notify_fail(HIR"你连上一个境界都没突破还想跳级不成?！\n"NOR);	
	 if (me->query("zj") == 1)
	return notify_fail(HIR"你的已经突破了筑基境，没必要再突破一次 ！\n"NOR);	
		if (me->query("max_neili") < 60000||me->query("max_jingli") < 30000)
		return notify_fail(HIR"你的内力不足6w或精力不足3w！不能突破当前境界！\n"NOR);				
        me->add("max_neili",6000);
        me->add("max_jingli",3000);
      me->set("zj",1);
    me->set("jingjie",3);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 筑 基 境\n"NOR);
    CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"的境界突破到了筑基境！");
}else
	 if(arg=="4")
	{
	if (me->query("zj") < 1 )
	return notify_fail(HIR"你连上一个境界都没突破还想跳级不成?！\n"NOR);	
    if (me->query("jd") == 1)
	return notify_fail(HIR"你的已经突破了金丹境，没必要再突破一次 ！\n"NOR);	
	if (me->query("max_neili") < 80000||me->query("max_jingli") < 40000)
	return notify_fail(HIR"你的内力不足8w或精力不足4w！不能突破当前境界！\n"NOR);				
    me->add("max_neili",8000);
    me->add("max_jingli",4000);
    me->set("jd",1);
    me->set("jingjie",4);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 金 丹 境\n"NOR);
    CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"的境界突破到了金丹境！");
}
else
	 if(arg=="5")
	{
	if (me->query("jd") < 1 )
	return notify_fail(HIR"你连上一个境界都没突破还想跳级不成?！\n"NOR);	
	if (me->query("yy") == 1)
	return notify_fail(HIR"你的已经突破了元婴境，没必要再突破一次 ！\n"NOR);	
    if (me->query("max_neili") < 100000||me->query("max_jingli") < 50000)
	return notify_fail(HIR"你的内力不足10w或精力不足5w！不能突破当前境界！\n"NOR);				
    me->add("max_neili",10000);
    me->add("max_jingli",5000);
    me->set("yy",1);
    me->set("jingjie",5);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 元 婴 境\n"NOR);
    CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"的境界突破到了元婴境！");
}else
	 if(arg=="6")
	{
	if (me->query("yy") < 1 )
	return notify_fail(HIR"你连上一个境界都没突破还想跳级不成?！\n"NOR);	
	if (me->query("ht") == 1)
	return notify_fail(HIR"你的已经突破了合体境，没必要再突破一次 ！\n"NOR);		
	if (me->query("max_neili") < 125000||me->query("max_jingli") < 65000)
	return notify_fail(HIR"你的内力不足12.5w或精力不足6.5w！不能突破当前境界！\n"NOR);				
	me->add("qi",me->query("max_qi"));
	me->add("max_qi",10000);
	me->add("gain/max_qi",10000);
	me->add("int",3);
    me->add("con",3);
    me->add("str",3);
    me->add("dex",3);
     me->add("htsss",3);
    me->set("ht",1);
    me->set("jingjie",6);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 合 体 境\n"NOR);
    CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"的境界突破到了合体境！");
    	me->save();
}else
	 if(arg=="7")
	{
	if (me->query("ht") < 1 )
	return notify_fail(HIR"你连上一个境界都没突破还想跳级不成?！\n"NOR);	
    if (me->query("dj") == 1)
	return notify_fail(HIR"你的已经突破了渡劫境，没必要再突破一次 ！\n"NOR);	
    if (me->query("max_neili") < 150000||me->query("max_jingli") < 80000)
	return notify_fail(HIR"你的内力不足15w或精力不足8w！不能突破当前境界！\n"NOR);				
	me->add("qi",me->query("max_qi"));
	me->add("max_qi",20000);
	me->add("gain/max_qi",20000);
	me->add("int",4);
    me->add("con",4);
    me->add("str",4);
    me->add("dex",4);
    me->add("djsss",4);
    me->set("dj",1);
    me->set("jingjie",7);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 渡 劫 境\n"NOR);
    CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"的境界突破到了渡劫境！");
}else
	 if(arg=="8")
	{
	if (me->query("dj") < 1 )
	return notify_fail(HIR"你连上一个境界都没突破还想跳级不成?！\n"NOR);	
    if (me->query("rx") == 1)
	return notify_fail(HIR"你的已经突破了人仙境，没必要再突破一次 ！\n"NOR);		
	if (me->query("lp") < 1)
	return notify_fail(HIR"你还没有被雷劈过，感觉总是少了点什么，心想还是等等吧！\n"NOR);	    	
	if (me->query("max_neili") < 200000||me->query("max_jingli") < 100000)
	return notify_fail(HIR"你的内力不足20w或精力不足10w！不能突破当前境界！\n"NOR);				
	me->add("qi",me->query("max_qi"));
	me->add("max_qi",30000);
	me->add("gain/max_qi",30000);
	me->add("int",5);
    me->add("con",5);
    me->add("str",5);
    me->add("dex",5);
     me->add("rxsss",5);
	me->set("fl",1); //判断是否可以使用法力
	me->set("rx",1);  
	me->set("jingjie",8);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    write(HIY"恭 喜 您 突 破 了 人 仙 境\n"NOR);
    CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"的境界突破到了人仙境！");
}else
if(arg=="ch")
{

		str = ZJOBLONG"境界称号：\n";
		str += ZJOBACTS2+ZJMENUF(2,2,9,31);
		str +=
		HIG"称号《练体境》"NOR":jinjie -ch lt"ZJSEP
		HIG"称号《练气境》"NOR":jinjie -ch lq"ZJSEP
		HIG"称号《筑基境》"NOR":jinjie -ch zj"ZJSEP
		HIG"称号《金丹境》"NOR":jinjie -ch jd"ZJSEP
		HIG"称号《元婴境》"NOR":jinjie -ch yy"ZJSEP
	        HIG"称号《合体境》"NOR":jinjie -ch ht"ZJSEP
	        HIG"称号《渡劫境》"NOR":jinjie -ch dj"ZJSEP
		HIG"称号《人仙境》"NOR":jinjie -ch rx"ZJSEP
		HIG"取消佩戴称号"NOR":jinjie -ch qx"ZJSEP	
					HIR"返回"NOR":look";	
		message("vision", str+"\n", me);		
	}
else
if(arg=="-ch lt")
{
if (me->query("lt") < 1)
return notify_fail(HIR"你还没有突破练体境，不能激活该称号！\n"NOR);	
me->set("chlt",1);
write(HIY"佩戴境界称号成功\n"NOR);
}else
if(arg=="-ch lq")
{
if (me->query("lq") < 1)
return notify_fail(HIR"你还没有突破练气境，不能激活该称号！\n"NOR);	
me->set("chlq",1);
write(HIY"佩戴境界称号成功\n"NOR);
}else
if(arg=="-ch zj")
{
if (me->query("zj") < 1)
return notify_fail(HIR"你还没有突破筑基境，不能激活该称号！\n"NOR);	
me->set("chzj",1);
write(HIY"佩戴境界称号成功\n"NOR);
}else
if(arg=="-ch jd")
{
if (me->query("jd") < 1)
return notify_fail(HIR"你还没有突破金丹境，不能激活该称号！\n"NOR);	
me->set("chjd",1);
write(HIY"佩戴境界称号成功\n"NOR);
}else
if(arg=="-ch yy")
{
if (me->query("yy") < 1)
return notify_fail(HIR"你还没有突破元婴境，不能激活该称号！\n"NOR);	
me->set("chyy",1);
write(HIY"佩戴境界称号成功\n"NOR);
}else
if(arg=="-ch ht")
{
if (me->query("ht") < 1)
return notify_fail(HIR"你还没有突破合体境，不能激活该称号！\n"NOR);	
me->set("chht",1);
write(HIY"佩戴境界称号成功\n"NOR);
}else
if(arg=="-ch dj")
{
if (me->query("dj") < 1)
return notify_fail(HIR"你还没有突破渡劫境，不能激活该称号！\n"NOR);	
me->set("chdj",1);
write(HIY"佩戴境界称号成功\n"NOR);
}else
if(arg=="-ch rx")
{
if (me->query("rx") < 1)
return notify_fail(HIR"你还没有突破人仙境，不能激活该称号！\n"NOR);	
me->set("chrx",1);
write(HIY"佩戴境界称号成功\n"NOR);
}else
if(arg=="-ch qx")
{
//if (me->query("rx") < 1)
//return notify_fail(HIR"你还没有突破人仙境，不能激活该称号！\n"NOR);	
me->set("chlt",0);
me->set("chlq",0);
me->set("chzj",0);
me->set("chjd",0);
me->set("chyy",0);
me->set("chht",0);
me->set("chdj",0);
me->set("chrx",0);
write(HIY"取消佩戴境界称号成功\n"NOR);
}

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
