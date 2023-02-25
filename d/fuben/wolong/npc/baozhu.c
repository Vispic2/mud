// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

mixed ask_yinguo();

//可爆出物品列表
string *random_ob = ({
    "/clone/vip/putao",
    "/clone/vip/putao",
    "/clone/vip/putao",
    "/clone/vip/putao1",
    "/clone/vip/fushougao",
    "/clone/vip/fushougao",
    "/clone/vip/fushougao",
    "/clone/vip/dan_jiuzhuan",
    "/clone/vip/dan_chongmai1",
    "/clone/vip/dan_chongmai1",
     "/clone/vip/dan_chongmai1",
    "/clone/money/gold",
    "/clone/shizhe/dalibao",
});

void create()
{
	set_name(HIR"周啸天"NOR, ({ "zhou xiaotian"}) );
	set("gender", "男性");
	set("age", 45);
	set("long", "这就是卧龙堡的主人。\n");

	set("combat_exp", 1000000+random(3000000));

	set("attitude", "peaceful");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("inquiry", ([
		"因果": (: ask_yinguo :),
	]) );

	set_basic();
	setup();

	add_money("gold", 1+random(10));
}

void init(object me)
{
	object ob;
	me = this_player();
	ob = this_object();
	::init();

	if (userp(me)&&!me->query_temp("zxt_again")) {
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 100);
		if (!random(3))
			ob->do_clone(me, 100);
		command("say 敢闯进我的卧龙堡？哼~~当我好说话吗！！\n");
		kill_ob(me);
		me->kill_ob(this_object());
	}
}

mixed ask_yinguo()
{
	int exp,gold;
	object me,ob;

	ob = this_object();
	me = this_player();

	if(me->is_fighting(ob)||!me->query_temp("zxt_again"))
	{
		command("say 废话少说，打败我再说！！\n");
		kill_ob(me);
		me->kill_ob(this_object());
		return 1;
	}
	tell_object(me,"周啸天开始向你仔细述说当年的往事。。。\n");
	tell_object(me,"原来周啸天在年轻的时候，一味地快意恩仇，结果结下了许多仇家，其中有一位神秘人就想法设下了这个局：
故意制造出一枚卧龙令，吸引武林人士前来探秘，以达到借刀杀人的目的。
至此，事情真相大白。你不禁哭笑不得。
你最后决定放过周啸天，离开卧龙堡。\n");


	exp = ob->query_skill("force",1)*5;
	me->add("combat_exp",exp);
      gold=1+random(10);
      me->add("balance",gold*10000);
	tell_object(me,ZJOBLONG+ZJBR+ZJBR"你勇闯卧龙堡，获得"+exp+"点经验和"+gold+"两黄金。"ZJBR+ZJBR"\n");
	destruct(ob);
	return 1;
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object me,killer,ob;
	int exp;

	me = this_object();

	if (objectp(killer = query_last_damage_from()))
	{
		if(!killer->query_temp("zxt_again"))
		{
			me->remove_killer(killer);
			killer->remove_killer(me);
			killer->set_temp("zxt_again",1);
			tell_object(killer,"你正欲将周啸天杀死，却见他瞥见你身上的卧龙令牌，呼喊道："+RANK_D->query_respect(killer)+"请手下留情！容我辩说几句。\n");
			tell_object(killer,"你是不予理会直接杀死周啸天，还是上前询问一下？\n");
			tell_object(killer,ZJSIZE(20)+ZJURL("cmds:kill zhouxiaotian")+"直接杀死"NOR"    "+ZJSIZE(20)+
					ZJURL("cmds:ask zhou xiaotian about 因果")+"上前询问"NOR"\n");
			ob = new(base_name(me));
			ob->move(environment(me));
			destruct(me);
			return;
		}
		exp = this_object()->query_skill("force",1)*10;
		
		if(killer->query("djexp")){
		exp=exp*3;
		}
		killer->add("combat_exp",exp);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你勇闯卧龙堡，杀死了"+name()+"，获得"+exp+"点经验。"ZJBR+ZJBR"\n");
	}

	switch (random(10))
	{
		case 0 : 
		case 5 :
		case 9 :
			new(id)->move(this_object());
		break;
	}
	::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
