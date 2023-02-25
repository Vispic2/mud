inherit NPC;

string *dan_list = ({
	"/clone/shizhe/dan_dex",
	"/clone/shizhe/dan_int",
	"/clone/shizhe/dan_con",
	"/clone/shizhe/dan_str",
	"/clone/shizhe/dan_jiuzhuan",
	});
void create()
{
	set_name("草人", ({"cao ren"}));
	set("long", "草人。\n");
	set("combat_exp", 100000);
	set("shen",-10000);
	
	set("max_qi", 1000);
	set("qi", 1000);
	set("max_neili", 1000);
	set("neili", 1000);
	set("max_jing", 1000);
	set("jing", 1000);
	         
	set_skill("sword",100);
    set_skill("blade", 100);
    set_skill("whip", 100);
    set_skill("club", 100);
    set_skill("staff", 100);
    set_skill("throwing", 100);

    set_skill("force", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);

    set_skill("unarmed",100);
    set_skill("cuff", 100);
    set_skill("strike", 100);
    set_skill("finger", 100);
    set_skill("claw", 100);
    set_skill("hand", 100);

	setup();
}

void die()
{
	object who = this_player();
	string str;
	object gift;
	int random;
	int exps;
		if (objectp(who = query_last_damage_from()))
	{
	str = "你获得了";
	random = random(10);
	if(random < 3)
		gift = new("/clone/shizhe/putao");
	else if(random == 5)
		gift = new("/clone/shizhe/putao1");
	else if(random == 4)
	{
	    if(random == 4)
		gift = new(dan_list[random(sizeof(dan_list))]);
		
	}
	if (objectp(gift)&&objectp(who))
	{
		str += gift->query("name") + "、";
		gift->move(who);
	}
	exps=3000+random(200);
	who->add("combat_exp",exps);
	//who->add("potential", 20);
	
	str += ""+exps+"经验...\n";
	tell_object(who, str);
	}
	::die();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
