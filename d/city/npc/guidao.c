// guidao.c
// by cleansword
// 96-02-16 YZC disabled NPC killing, & "unknown" problem when revealed

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("王五", ({ "wang wu", "wang" }) );
	set("title", "酒客");
	set("gender", "男性" );
	set("shen_type", -1);
	set("age", 40);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long",
		"这是个喝得醉醺醺的酒鬼，正盯着手中的酒杯喃喃地念叨着什麽。\n" );

	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"王五说道: 你当真吃了豹子胆啦 ? 敢跟大爷较量 ! \n",
		"王五忽然挥出一刀，招数精奇，但刀到中途却又急忙收招。\n",
		"王五说道: 快滚 ! 算我输了还不行 ?....\n"
	}) );

	set("inquiry", ([
		"王老五" : "哈哈哈! 有趣有趣，可惜你认错人了。" ,
		"鬼刀"   : (: ask_me :),
	]) );

	set_skill("blade", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 30);
	set_skill("parry", 50);
	
	setup();
	
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if( query("revealed") ) {
		if( is_killing(who->query("id")) ) return "你既然知道了我的身分，今日休想活命！\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "老子就是鬼刀王五，鬼刀王五就是你老子！纳命来吧！\n";
		}
	}

	if( (random(10) < 5) || is_fighting() )
		return "我…不知道。\n";

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",  20);

	set("title", HIR "鬼刀" NOR);

	message("vision",
		HIY "王五眼中突然放出异样的光芒，颤声说道，看来...你都知道了？\n"
		"王五大喝一声，叫道，既然如此，老子今天反正豁出去，跟你拼了。\n" 
		"王五使开单刀，招数精奇，沉猛狠辣，和刚才的醉鬼简直判若两人。"NOR"\n",
		environment(), this_object() );

	set("pursuer", 1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);
	set("chat_msg_combat", ({
		(: random_move :)
	}) );
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("bellicosity", 10000);
	set("combat_exp", 80000);
	set_skill("blade", 80);
	set_skill("dodge", 70);
	set_skill("unarmed", 60);
	set_skill("parry", 80);
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
	add_money("silver", 50);
	set("revealed", 1);
	return "老子就是鬼刀王五，鬼刀王五就是你老子！纳命来吧！\n";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
