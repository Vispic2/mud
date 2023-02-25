// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	object obj;

	if(me->query("combat_exp")<10000)
			return notify_fail(HIR"江湖险恶，等你行走江湖一段时间有了一定能力再炫耀你的东西吧，不然小心被人盯上！\n"NOR);

	

	if(me->is_busy())
			return notify_fail("你现在正忙着呢！\n");

	

if(!wizardp(me)){
	if (time() - me->query_temp("last_use_channel") < 30)
	{
		return notify_fail("不要在短期内频繁使用展示频道发布信息。\n");
	} else
	{
		me->set_temp("last_use_channel", time());
	}
}
	if( !arg||!objectp(obj = present(arg,me)) )
			return notify_fail("你要展示什么？\n");
	
//禁止展示尸体及相关部件19.12.13风雨小妖
	if (obj->is_corpse() || obj->is_body_part()||obj->is_head())
	return notify_fail("你真是恶心到家了,禁止展示"+obj->query("name")+"。\n");
	me->start_busy(1);
	message("channel:bill", "【展示】"+me->query("name")+"：物品展示->"+ZJURL("cmds:look "+arg)+ZJSIZE(22)+filter_color(obj->query("name"))+NOR"。\n", users());
	return 1;
}

int help()
{
	write(@TEXT
指令格式：showitem <物品>
物品展示和查看。

TEXT
	);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
