// suicide.c

#include <ansi.h>

inherit F_CLEAN_UP;

private int slow_suicide(object me);
private int halt_suicide(object me);
private void check_password(string passwd, object me, int forever);

int main(object me, string arg)
{
	object *inv;
	int i;
	//if (!wizardp(me))
	//	return notify_fail("修正中，等待开放。\n");
	if (me->is_busy())
		return notify_fail("你上一个动作还没完成。\n");

	inv = deep_inventory(me);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (! userp(inv[i]) && ! playerp(inv[i])) continue;
		return notify_fail("你身上还有个大活人呢，想不开也别急呀？\n");
	}

	if( me->query("combat_exp") > 20000000 )
	{
		return notify_fail("山穷水尽疑无路，柳暗花明又一村。这位" + RANK_D->query_respect(me) +"不要意气用事，还是先冷静一下再说吧！提示：你的经验超出范围（2000w）。\n");
	}

	if (! arg)
	{
		write(ZJOBLONG"您选择了直接删档的自杀方式，这个人物的资料将被永久删除，且无法恢复，请慎重考虑。"ZJBR"你确定要自杀么？\n"
			ZJOBACTS2+ZJMENUF(3,3,8,30)+"确定:suicide -f"ZJSEP"取消:shake\n");
		return 1;
	}
	else if (arg == "-f") 
	{
		check_password("YES",me,1);
	}
	else
		return notify_fail("你要干什么？\n");
	return 1;
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("ad_password");
	if (passwd!="YES")
	{
		write(HIR "你想了想决定先不自杀了。"NOR"\n");
		return;
	}

	if (forever)
	{
		tell_object(me, HIR "\n你决定要自杀了，如果三十秒钟内不后悔，就真的永别了。"NOR"\n");
		me->set_temp("suicide/time", time());
		me->set_temp("suicide/last", 0);
		me->set_temp("suicide/from", query_ip_number(me));
		me->start_busy(bind((: call_other, __FILE__, "slow_suicide", me :), me),
			       bind((: call_other, __FILE__, "halt_suicide", me :), me));
	}
}

int slow_suicide(object me)
{
	object link_ob;
	int t;

	if (! objectp(me) || previous_object() != me)
		return 0;

	t = time() - me->query_temp("suicide/time");
	if (t < me->query_temp("suicide/last"))
	{
		me->delete_temp("suicide/");
		return 0;
	}

	if (t < 30)
	{
		if (t - me->query_temp("suicide/last") < 5)
			return 1;

		tell_object(me, HIR"你还有" + chinese_number(30 - t) +
			    "秒钟仔细考虑("ZJURL("cmds:halt")+ ZJSIZE(20)+ HIC "停止自杀" NOR+HIR")。"NOR"\n");
		me->set_temp("suicide/last", t / 5 * 5);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if (! link_ob || ! interactive(me)) return 0;

	log_file("cmds/suicide",
		 sprintf("%s %s commits a suicide from %s\n",
			log_time(), log_id(me),
			me->query_temp("suicide/from")));
    me->set("yuanbao",0);
        me->set("yuanbaos",0);
            me->set("cjj",0);
                me->set("cjjs",0);
                me->set("zjvip/times",0);
	VIP_D->save_vdata(me);
	seteuid(getuid());
	write("\n好吧，永别了:)。\n\n");
	
	
	//write_file("/d/register/regmail.txt",replace_string(read_file("/d/register/regmail.txt"),me->query("data_email"),""),1);	
	if(me->query("combat_exp") > 0)
	{
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s自杀了，以后你再也看不到这个人了。",me->name()));
	}
	tell_room(environment(me), me->name() +	"在你的面前化作轻烟，渐渐消失了...\n", ({me}));

	UPDATE_D->remove_user(me->query("id"));
	return 0;
}

int halt_suicide(object me)
{
	if (! objectp(me) || previous_object() != me)
		return 0;

	tell_object(me, HIG "你打消了寻死的念头。"NOR"\n");
	me->delete_temp("suicide");
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: suicide [-f]
 
如果因为某种原因你不想活了, 你可以选择自杀.
自杀分两种:
 
suicide    : 重新投胎
suicide -f : 永远的除去玩家资料, 系统会要求你
	     输入密码以确认身份.
 
请慎重选择 :)
 
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
