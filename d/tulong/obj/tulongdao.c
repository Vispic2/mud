#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name(CYN "屠龙刀" NOR, ({ "tulong blade" , "blade" ,"dao", "tulong" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", HIY "这便是号称武林至尊的屠龙宝刀，四尺来长的单刀，竟达一百多斤之重。相传其中藏有旷世的大秘密。"""ZJSIZE(22)+HIW+ZJURL("cmds:duikan yitian sword")"对砍"NOR"\n");
		set("no_sell", "这样东西不能卖。\n");
		set("no_give", 1);
		set("no_put", 1);
		set("rigidity",8000);   
		set("material", "steel");
		set("wield_msg", HIY "$N一声狂笑，从背后抽出那柄号称“"NOR+HIR"武林至尊"NOR+HIY"”的屠龙宝刀高高举起。"NOR"\n");
		set("unwield_msg", HIY "$N哈哈一笑，将屠龙宝刀插回背后。"NOR"\n");
	}
	set("action_list", ([
		"对砍" : "duikan yitian sword",
	]));
	init_blade(210);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("str");
	victim->receive_damage("jing",dam * 2);
	return HIM "屠龙刀夹带着刺耳的破空声划出一道道长虹，$n只感到心神意乱，勉强作出抵挡。"NOR"\n";
}

void init()
{
	object me = this_player();
	
	add_action("do_open", "duikan");
	if (!query("clone"))
	{
		set("clone", time());
		call_out("move_ob1", 9200);
	}
}
void move_ob1()
{
	object ob;
	object me;
	
	me = environment();
	if (! objectp(me))
		return;

	while (objectp(environment(me)) && ! playerp(me))
		me = environment(me);
		
	if (playerp(me)) {
		if (me->is_fighting())
		{
			call_out("move_ob1", 3);
			return;
		}
		
		if (ob = present("tulong blade", me)) {
			message_vision("只见$n化作一道光芒，从$N身上飞出，倏忽不见了！\n", me, ob);
			CHANNEL_D->do_channel( this_object(), "rumor",sprintf("听说武林至宝%s从%s身上消失了！", ob->name(), me->name(1)));
		}
	}
	destruct(ob);
}

int do_open(string arg, object me)
{
	object pai,ob;
	if(arg != "yitian sword" || !ob = present("yitian sword", environment(this_object()))) 
	{
		return notify_fail("你要砍什么？\n");
	}
	else if (this_player()->query("jiali") <= 200)
	return notify_fail(WHT "\n你提起屠龙刀对准倚天剑用力的砍了下去！"NOR+HIR"\n\n只听“镪”的一声脆响，飞溅出几点火星。"NOR"\n");
	{
		pai = new("/d/tulong/obj/duan1");
		pai->move(this_player());
		pai = new("/d/tulong/obj/duan2");
		pai->move(this_player());

		pai = find_object("/d/tulong/obj/zhenjing");
		if(!pai) pai = load_object("/d/tulong/obj/zhenjing");
		pai->move(this_player());

		pai = new("/d/tulong/obj/miji");
		pai->move(this_player());
		pai = new("/d/tulong/obj/yishu");
		pai->move(this_player());
		message_vision(WHT "\n$N提起屠龙刀对准倚天剑用力的砍了下去！\n"NOR"\n"+HIW"只听一声闷响，$N手臂一震，屠龙刀和倚天剑已经断了。你发现刀剑中竟然夹藏着几卷帛绢。"NOR"\n",this_player());
		destruct (ob);
		destruct(this_object());
		return 1;
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
