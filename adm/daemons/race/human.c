// human.c
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
([      "action":	       "$N挥拳攻击$n的$l",
	"damage_type":  "瘀伤",
]),
([      "action":	       "$N往$n的$l一抓",
	"damage_type":  "抓伤",
]),
([      "action":	       "$N往$n的$l狠狠地踢了一脚",
	"damage_type":  "瘀伤",
]),
([      "action":	       "$N提起拳头往$n的$l捶去",
	"damage_type":  "瘀伤",
]),
([      "action":	       "$N对准$n的$l用力挥出一拳",
	"damage_type":  "瘀伤",
]),
});

void create()
{
	seteuid(getuid());
}

void setup_human(object ob)
{
	mapping my;
	int s;
	int x, y;
	int f;
	int level, level_old;
        f = (int)ob->query_skill("force", 1);
	my = ob->query_entire_dbase();

	ob->set_default_action(__FILE__, "query_action");
	if (! stringp(my["unit"])) my["unit"] = "位";
	if (! stringp(my["gender"])) my["gender"] = "男性";
	if (undefinedp(my["can_speak"])) my["can_speak"] = 1;
	if (! stringp(my["attitude"])) my["attitude"] = "peaceful";
	if (! pointerp(my["limbs"])) my["limbs"] = ({
		"头部", "颈部", "胸口", "后心", "左肩", "右肩", "左臂",
		"右臂", "左手", "右手", "腰间", "小腹", "左腿", "右腿",
		"左脚", "右脚"
	});

	if (undefinedp(my["age"])) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 10 + random(21);
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);

	if (userp(ob) || undefinedp(my["max_jing"]))
	{
		s = ob->query_int();
		my["max_jing"] = 200;
		if (undefinedp(my["born"]))
		; else
		if (my["age"] < 14)
			my["max_jing"] = 50 + my["age"] * s * 2 / 3;
		else
		if (my["age"] < 24)
			my["max_jing"] += (my["age"] - 14) * s * 2 / 3;
		else
			my["max_jing"] += (24 - 14) * s * 2 / 3;

		if ((int)my["max_jingli"] > 0)
			my["max_jing"] += (int)my["max_jingli"] / 3;

		if (my["breakup"])
			my["max_jing"] += my["max_jing"];

		if (my["animaout"])
			my["max_jing"] += my["max_jing"];

		if(my["max_jing"]>10000000)
			my["max_jing"] = 10000000;
			
			

	}
	
		if (undefinedp(my["max_neili"]))
	{
		    my["max_neili"] = 200;
		
	}
		if (undefinedp(my["max_jingli"]))
	{
		    my["max_jingli"] = 100;
		
	}

	if (userp(ob) || undefinedp(my["max_qi"]))
	{
		s = ob->query_con() + ob->query_str();
		my["max_qi"] = 800;
		if (undefinedp(my["born"]))
			; else
		if (my["age"] < 14)
			my["max_qi"] = 60 + my["age"] * my["con"] / 2;
		else
		if (my["age"] < 27)
			my["max_qi"] += (my["age"] - 14) * s * 2 / 3;
		else
			my["max_qi"] += (27 - 14) * s * 2 / 3;

		if ((int)my["max_neili"] > 0)
			my["max_qi"] += (int)my["max_neili"] / 4;

		// 武当太极加气
		if ((x = (int)ob->query_skill("taoism", 1)) > 39 && (y = (int)ob->query_skill("taiji-shengong", 1)) > 39)
		{

			my["max_qi"] += (x + 100 ) * (y + 100) / 100;
		}

		// 全真先天功加气
		if ((x = (int)ob->query_skill("taoism", 1)) > 39 &&   (y = (int)ob->query_skill("xiantian-gong", 1)) > 39)
		{
			my["max_qi"] += (x + 100 ) * (y + 100) / 100;
		}
		
		///天赋

          if (ob->query("special_skill/energy"))
          my["max_jing"] += 50 + f * 2;

		if (my["breakup"])
			my["max_qi"] += my["max_qi"];
		if (my["con"]>30)
			my["max_qi"] += 200*(my["con"]-30);
		if(my["max_qi"]>10000000)
			my["max_qi"] = 10000000;
		if (ob->query("special_skill/ghost"))
			my["max_qi"] = my["max_qi"] * 7 / 10;
	}


	// 为什么要乘以0.7？这是因为背人只需要70%的负重。
	if (! ob->query_weight())
		ob->set_weight((BASE_WEIGHT + (my["str"] - 10) * 2000) * 7 / 10);
	 level_old = ob->query_temp("mark/hubo");
	if ((level = ob->query_skill("zuoyou-hubo", 1)) > 0 && level_old != level)
	 {
		ob->set_temp("mark/hubo",level);
		ob->add_temp("apply/parry", -(level - level_old) / 4);
	 }
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
