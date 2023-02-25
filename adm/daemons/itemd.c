// itemd.c
//累积加魔力 
#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <command.h>


inherit F_DBASE;
inherit F_SAVE;
void create()
{ 
seteuid(getuid()); 
restore();
}
int remove()
{
	save();
	return 1;
}
mixed set_data(string prop, mixed data)
{
	if( !mapp(dbase ) ) dbase = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( dbase , explode(prop, "/"), data );

	dbase[prop] = data;
	return 1;
}

mixed query_data(string prop)
{
	mixed data;

	if( !mapp(dbase) ) return 0;

	if( undefinedp(dbase[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(dbase, explode(prop, "/"));
	else
	{
		data = dbase[prop];
	}

	return data;
}
void mud_shutdown()
{
	save();
}
public string *all_users()
{
	if(!dbase)
		return 0;
	return keys(dbase);
}

string query_save_file() { return DATA_DIR + "item"; }



// 可以用来浸透的物品列表：必须是物品的base_name
mapping imbue_list = ([
	"feicui lan":"翡翠兰",
	"puti zi":"菩提子",
	"ling zhi":"千年灵芝",
	"xian dan":"醍醐仙丹",
	"xisui dan":"洗髓丹",
	"shenli wan":"神力丸",
	"huohong xiandan":"火红仙丹",
	"jiuzhuan jindan":"九转金丹",
	"magic water":"天香玉露",
	"fushou gao":"福寿膏",
]);

// 浸入的次数的随机界限：如果每次IMBUE以后取0-IMBUE次数的随机
// 数大于这个数值，则IMBUE最终成功。
#define RANDOM_IMBUE_OK	 80
//80
// 每次浸入需要圣化的次数
#define SAN_PER_IMBUE	   5
//5
// 杀了人以后的奖励
void killer_reward(object me, object victim, object item)
{
	int exp;
	mapping o;
	string my_id;

	if (! me || ! victim)
		return;

	if (! victim->query("can_speak"))
		return;

	// record for this weapon
	if (victim->is_not_bad())  item->add("combat/WPK_NOTBAD", 1);
	if (victim->is_not_good()) item->add("combat/WPK_NOTGOOD", 1);
	if (victim->is_good())     item->add("combat/WPK_GOOD", 1);
	if (victim->is_bad())      item->add("combat/WPK_BAD", 1);

	if (userp(victim))
		item->add("combat/PKS", 1);
	else
		item->add("combat/MKS", 1);

	exp = (int)victim->query("combat_exp");
	if (exp < 10000 || me->query("combat_exp") < exp * 4 / 5 || exp < item->level_now()*300000 || item->item_owner()!=me->query("id"))
		return;

	if(random(2))
		return;

	exp /= 10000;
	if (exp > 250) exp = 100 + (exp - 250) / 16; 
	else if (exp > 50) exp = 50 + (exp - 50) / 4;
	if (exp>100) exp = 100;
	my_id = me->query("id");
	o = item->query("owner");
	if (! o) o = ([ ]);
	if (! undefinedp(o[my_id]) || sizeof(o) < 12)
		o[my_id] += exp;
	else
	{
		int i;
		int lowest;
		string *ks;

		lowest = 0;
		ks = keys(o);
		for (i = 1; i < sizeof(ks); i++)
			if (o[ks[lowest]] > o[ks[i]])
				lowest = i;
		map_delete(o, ks[lowest]);
		o += ([ my_id : exp ]);
	}
	item->set("owner", o);
}

// 召唤物品
int receive_summon(object me, object item)
{
	object env;
	object temp;
	int type;

	if ((env = environment(item)) && env == me)
	{
		tell_object(me, item->name() + "不就在你身上"
			    "嘛？你召唤个什么劲？\n");
		return 1;
	}

	if (me->query("neili") < 500)
	{
		tell_object(me, "你试图呼唤" + item->name() +
			    "，可是难以进入境界，看来是内力不济。\n");
		return 0;
	}
	me->add("neili", -500);

	message_vision(HIW "$N" HIW "突然大喝一声，伸出右手凌空"
		       "一抓，忽然乌云密布，雷声隐隐。"NOR"\n", me);

	if (env == environment(me))
	{
		message_vision(HIW "只见地上的" + item->name() +
			       HIW "应声而起，飞跃至$N" HIW
			       "的掌中！"NOR"\n", me);
	} else
	{
		type = random(3);
		if (env)
		{
			if (env->is_character() && environment(env))
					env = environment(env);

			switch (type)
			{
			case 0:
				message("vision", HIW "天空中传来隐隐的雷声"
					"，忽然电闪雷鸣，" + item->name() +
					HIW "腾空而起，"
					"消失不见！"NOR"\n", env);
				break;
			case 1:
				message("vision", HIC "一道神光从天而降"
					"，罩定了" + item->name() + HIC "，只见" +
					item->name() + HIC "化作长虹破空而"
					"走。"NOR"\n", env);
				break;
			default:
				message("vision", HIY "忽然间麝香遍地，氤氲弥漫，" +
					item->name() + HIY "叮呤呤的抖动数下，化作一"
					"道金光转瞬不见！"NOR"\n", env);
				break;
			}

			if (interactive(env = environment(item)))
			{
				tell_object(env, HIM + item->name() +
						 HIM "忽然离你而去了！"NOR"\n");
			}
		}

		switch (type)
		{
		case 0:
			message_vision(HIW "一声" HIR "霹雳" HIW "，"
				       "闪电划破长空，" + item->name() + HIW
				       "从天而降，飞入$N" HIW "的手中！"NOR"\n", me);
			break;
		case 1:
			message_vision(HIW "一道" HIY "长虹" HIW "扫过"
				       "天空，只见" + item->name() + HIW
					"落入了$N" HIW "的掌中！"NOR"\n", me);
			break;
		default:
			message_vision(HIW "只见" + item->name() + HIW "呤呤作响，大"
				       "放异彩，挟云带雾，突现在$N"
				       HIW "的掌中！"NOR"\n", me);
			break;
		}
	}

	// 取消no_get属性
	item->delete_temp("stab_by");
	item->delete("no_get");

	item->move(me, 1);
	if (environment(item) != me)
		return 1;

	if (item->query("armor_type"))
	{
		// is armor
		temp = me->query_temp("armor/" + item->query("armor_type"));
		if (temp) temp->unequip();
		WEAR_CMD->do_wear(me, item);
	} else
	if (item->query("skill_type"))
	{
		if (temp = me->query_temp("weapon"))
			temp->unequip();
		if (temp = me->query_temp("secondary_weapon"))
			temp->unequip();
		WIELD_CMD->do_wield(me, item);
	}

	return 1;
}

// 隐藏物品
int hide_anywhere(object me, object item)
{
	if (item->item_owner() != me->query("id"))
		return 0;

	if (me->query("jingli") < 100)
	{
		tell_object(me, "你试图令" + item->name() +
			    "遁去，可是精力不济，难以发挥它的能力。\n");
		return 0;
	}
	me->add("jingli", -100);

	message_vision(HIM "$N" HIM "轻轻一旋" + item->name() +
		       HIM "，已然了无踪迹。\n", me);
	destruct(item);
	return 1;
}

// 追寻物品
int receive_miss(object me, object item)
{
	object env;

	env = environment(item);

	if (me->is_busy())
	{
		write("你正忙，等有空了再说。\n");
		return 0;
	}

	if (me->is_fighting())
	{
		write("等你打完了架再说吧！\n");
		return 0;
	}

	if (env == environment(me))
	{
		write("你瞪着" + item->name() + "，看啥？\n");
		return 0;
	}

	if (env == me)
	{
		write("你摸着" + item->name() + "，发了半天的呆。\n");
		return 0;
	}

	if (! objectp(env) || userp(env) || environment(env))
	{
		write("你试图感应" + item->name() + "，但是感觉非常的渺茫。\n");
		return 0;
	}

	if (! wizardp(me) && ! env->query("outdoors"))
	{
		write("冥冥中你感应到" + item->name() + "，但是似乎难以到达那里。\n");
		return 0;
	}

	message("vision", me->name() + "在凝神思索，不知道要做些什么。\n",
		environment(me), ({ me }));
	if (me->query("jingli") < 400)
	{
		write("你觉得" + item->name() + "的感觉相当"
		      "飘忽，看来精力不济，难以感应。\n");
		return 0;
	}

	// 消耗精力
	me->add("jingli", -300 - random(100));
	message_vision(HIM "$N" HIM "口中念念有词，转瞬天际一道长虹划"
		       "过，$N" HIM "驾彩虹而走。"NOR"\n", me);
	tell_object(me, "你追寻" + item->name() + "而去。\n");
	me->move(environment(item));
	message("vision", HIM "一道彩虹划过天际，" + me->name() +
		HIM "飘然落下，有若神仙。"NOR"\n", environment(me), ({ me }));
	tell_object(me, HIM "你追寻到了" + item->name() +
		    HIM "，落下遁光。"NOR"\n");
	return 1;
}

// 插在地上
int do_stab(object me, object item)
{
	if (! item->is_weapon() && item->query("armor_type") != "hands")
		return notify_fail(item->name() + "也能插在地上？\n");

	if (! environment(me)->query("outdoors") &&
	    ! wizardp(me))
		return notify_fail("在这里乱弄什么！\n");

	if (! item->is_stay_in_room())
		return notify_fail("这" + item->name() + "就别放在这儿了。\n");

	item->set("no_get", bind((: call_other, __FILE__, "do_get_item", item :), item));
	item->set_temp("stab_by", me->query("id"));

	message_vision("$N随手将" + item->name() + "往地上一插，发出“嚓愣”一声响。\n", me);
	item->move(environment(me));
	return 1;
}

// 把取物品时检查
mixed do_get_item(object item)
{
	object me;

	if (! objectp(me = this_player()))
		return 1;

	if (me->query("id") != item->query_temp("stab_by") &&
	    me->query("id") != item->item_owner())
		return "你试图将" + item->name() + "拔起，却发现它仿佛是生长在这里一般，无法撼动。\n";

	message_vision("$N轻轻一拔" + item->name() + "，只听“咔”的一声响。\n", me);
	item->delete_temp("stab_by");
	item->delete("no_get");
	return 0;
}

// 发挥特殊功能
mixed do_touch(object me, object item)
{
	string msg;
	object ob;
	object *obs;
	mapping my;

	if (me->query("id") != item->item_owner())
	{
		message_vision("$N摸了一下" + item->name() + "，结果手被划破了，痛得大叫一声。\n", me);
		me->receive_damage("qi", 50 + random(50));
		return 1;
	}

	if (me->query("jingli") < 100)
	{
		me->set("jingli", 0);
		return notify_fail("你抱着" + item->name() + "摸了半天，口中念念有词。\n");
	}

	me->add("jingli", -80 - random(20));
	switch (random(3))
	{
	case 0:
		msg = HIM "$N" HIM "轻轻一弹$n"
		      HIM "，长吟道：“别来无恙乎？”"NOR"\n";
		break;
	case 1:
		msg = HIM "$N" HIM "轻轻抚过$n"
		      HIM "，感慨良深，作古风一首，$n"
		      HIM "铃铃作响，似以和之。"NOR"\n";
		break;
	default:
		msg = HIM "$N" HIM "抓着$n"
		      HIM "，沉思良久。"NOR"\n";
		break;
	}

	switch (random(3))
	{
	case 0:
		msg += HIM "$n" HIM "忽然闪过一道光华，飞跃而"
		       "起，散作千百流离。"NOR"\n";
		break;
	case 1:
		msg += HIM "$n" HIM "发出一声龙吟，悠悠不绝，"
		       "直沁入到你的心肺中去。"NOR"\n";
		break;
	default:
		msg += HIM "霎时$n" HIM "光芒四射，逼得你无法"
		       "目视，千奇百色，变幻无方。"NOR"\n";
		break;
	}

	msg = replace_string(msg, "$n", item->name());
	message_vision(msg, me);

	if (random(1000) == 1)
	{
		obs = filter_array(all_inventory(environment(me)), (: userp :));
		foreach (ob in obs)
		{
			my = ob->query_entire_dbase();
			my["jing"]   = my["eff_jing"] = my["max_jing"];
			my["qi"]     = my["eff_qi"]   = my["max_qi"];
			my["neili"]  = my["max_neili"];
			my["jingli"] = my["max_jingli"];
			ob->set_temp("nopoison", 1);
		}
		message("vision", HIY "你觉得浑身如同笼罩在阳光一般，暖洋洋的，说不出的舒服。"NOR"\n", obs);
	} else
	if (me->query("neili") < me->query("max_neili"))
	{
		me->set("neili", me->query("max_neili"));
		tell_object(me, HIY "你觉得一股热气从丹田冉冉升起。"NOR"\n");
	}
	return 1;
}

// 圣化物品
int do_san(object me, object item)
{
	string my_id;
	string ss,*sss;
	int count;
	int san;
/*
	if (! item->query("skill_type") && item->query("armor_type") != "hands")
		// 是装备类？
		return notify_fail("装备现在还无法圣化...\n");
*/
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");


	 if(item->item_owner() != me->query("id") )
		  return notify_fail(item->name() + "不需要你来操心吧！\n");
	// 武器类的圣化
	if (item->query("magic/power") > 0)
		return notify_fail("现在" + item->name() + "的威力已经得到了充分的发挥了。\n");

	if (item->query("magic/imbue_ok"))
		return notify_fail("现在" + item->name() + "的潜力已经充分挖掘了，现在只是需要最后一步融合。\n");

	my_id = me->query("id");

	if (item->query("magic/imbue_name")&&item->query("magic/imbue_ob"))
		return notify_fail("现在" + item->name() + "已经被充分的圣化了，需要浸入"+ item->query("magic/imbue_name")+ "以进一步磨练。\n");

	if (me->query("neili") < me->query("max_neili") * 9 / 10)
		return notify_fail("你现在内力并不充沛，怎敢贸然运用？\n");

	if (me->query("jingli") < me->query("max_jingli") * 9 / 10)
		return notify_fail("你现在精力不济，怎敢贸然运用？\n");

	if (me->query_skill("force") < 100)
		return notify_fail("你的内功根基不够扎实，不能贸然圣化。\n");

	if (me->query("max_neili") < 5000)
		return notify_fail("你尝试运了一下内力，无法顺利运足一个周天，难以施展你的能力。\n");

	if (me->query("max_jingli") < 1000)
		return notify_fail("你试图凝神运用精力，但是感觉尚有欠缺。\n");

	message_sort(HIM "$N" HIM "轻轻抚过$n" HIM "，两指点于其上，同"
		     "时运转丹田内力，经由奇经\n八脉源源由体内流出，注"
		     "入$n" HIM "。\n忽的只见氤氲紫气从$n" HIM
		     "上腾然升起，弥漫在四周。"NOR"\n", me, item);

	if (me->query("max_neili") < me->query_neili_limit() - 200)
	{
		if (random(2) == 1)
		{
			// 内力未满警告
			message_vision(HIR "$N" HIR "脸色忽然变了变。"NOR"\n",me);
			tell_object(me, HIC "你忽然觉得丹田气息有些错乱。"NOR"\n");
		} else
		{
			message_vision(HIR "$N" HIR "忽然闷哼一声，脸上刹时大汗淋漓！"NOR"\n", me);
			tell_object(me, HIC "你感到可能是你的内力尚未锻炼到极至，结果损伤了你的内功根基。"NOR"\n");
			tell_object(me, HIC "你的基本内功下降了。\n");
			me->set_skill("force", me->query_skill("force", 1) - 10 - random(5));
			return 1;
		}
	}

	// 统计IMBUE过的次数，并用来计算本次MAX_NEILI/JINGLI的消耗
	san = item->query("magic/imbue");

	//me->add("max_neili", -(san + 5));
	me->add("neili", -(san * 10 + 100));
	me->add("max_jingli", -(san * 5));
	me->add("jingli", -(san * 5 + 50));
	me->add("magic_points", -(san * 5 + 50));
	me->start_busy(1);

	if (item->item_owner() == my_id)
	{
		tell_object(me, HIW "你凝神片刻，觉得" + item->name() +  HIW "似乎有了灵性，跳跃不休，不禁微微一笑。"NOR"\n");
		message("vision", HIW + me->name() + HIW "忽然微微一笑。\n" HIW, environment(me), ({ me }));

		// 选定一个需要imbue的物品
		sss=keys(imbue_list);
		ss = sss[random(sizeof(sss))];
		item->set("magic/imbue_ob", ss);
		item->set("magic/imbue_name", imbue_list[ss]);
		tell_object(me,"接下来用"+ imbue_list[ss] + "来浸透一下" +item->name() + "吧。\n");
	}
	return 1;
}

// 浸透物品
int do_imbue(object me, object item)
{
	object imbue;

	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	 if(item->item_owner() != me->query("id"))
		  return notify_fail(item->name() + "不需要你来操心吧！\n");
	if (item->query("magic/power") > 0)
		return notify_fail("现在" + item->name() + "的威力已经得到了充分的发挥了。\n");

	if (item->query("magic/imbue_ok"))
		return notify_fail("现在" + item->name() + "的潜力已经充分挖掘了，现在只是需要最后一步融合。\n");

	if (!item->query("magic/imbue_name")||!item->query("magic/imbue_ob"))
		return notify_fail("你必须先对" + item->name() + "进行充分的圣化才行。\n");

	if (!objectp(imbue = present(item->query("magic/imbue_ob"),me)))
		return notify_fail("你身上没有" + item->query("magic/imbue_name") + "，拿什么浸透？\n");
	 
	if (me->query("max_neili") < 6000)
		return notify_fail("你尝试运了一下内力，无法顺利运足一个周天，难以施展你的能力。\n");

	if (me->query("neili") < 4000)
		return notify_fail("你感觉内力还有点欠缺，无法施展你的能力。\n");

	if (me->query("max_jingli") < 1000)
		return notify_fail("你试图凝神运用精力，但是感觉尚有欠缺。\n");
	 
	if (me->query("jingli") < 500)
		return notify_fail("你现在无法集中精力做这件事。\n");

	message_sort(HIM "$N" HIM "深吸一口气，面上笼罩了一层白霜，只手握住$n" +
		     imbue->name() +
		     HIM "，忽然间融化在掌心，晶莹欲透！$N"
		     HIM "随手一挥，将一汪清液洒在$n" HIM
		     "上，登时化做雾气，须臾成五彩，奇光闪烁。"NOR"\n",
		     me, item);
	
	if (me->query("max_neili") < me->query_neili_limit() - 200)
	{
		if (random(2) == 1)
		{
			// 内力未满警告
			message_vision(HIR "$N" HIR "脸色忽然变了变。"NOR"\n",me);
			tell_object(me, HIC "你忽然觉得丹田气息有些错乱。"NOR"\n");
		} else
		{
			message_vision(HIR "$N" HIR "忽然闷哼一声，脸上刹时大汗淋漓！"NOR"\n", me);
			tell_object(me, HIC "你感到可能是你的内力尚未锻炼到极至，结果损伤了你的内功根基。"NOR"\n");
			tell_object(me, HIC "你的基本内功下降了。\n");
			me->set_skill("force", me->query_skill("force", 1) - 10 - random(5));
			if(imbue->query_amount())
				imbue->add_amount(-1);
			else
				destruct(imbue);
			return 1;
		}
		
	}
	
	//me->add("max_neili", -100);
	me->set("neili", 0);
	me->add("max_jingli", -100);
	me->add("jingli", -500);

	tell_object(me, "你将" + imbue->name() + "的效力浸入了" + item->name() + "。\n");

	item->delete("magic/do_san");
	item->delete("magic/imbue_ob");
	item->delete("magic/imbue_name");
	if(imbue->query_amount())
		imbue->add_amount(-1);
	else
		destruct(imbue);
	me->start_busy(1);

	item->add("magic/imbue", 1);
	if (random(item->query("magic/imbue")) >= RANDOM_IMBUE_OK || me->query("imbue_will_ok"))
	{
		// 浸透完成
		tell_object(me, HIG "你忽然发现手中的" + item->name() + HIG "有一种跃跃欲试的感觉，似乎期待着什么。"NOR"\n");
		item->set("magic/imbue_ok", 1);
		me->delete("imbue_will_ok");
	}

	return 1;
}

// 镶嵌物品
int do_enchase(object me, object item, object tessera)
{
	int lvl,pw;
int cs;
mapping info;
int sss;
string name,names;
object csss=this_object();
sss=item->query("id");
names=item->name();
//write("结果："+sss+"\n");
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	if(item->item_owner() != me->query("id"))
		  return notify_fail(item->name() + "不需要你来操心吧！\n");
	if (item->query("magic/power") > 0)
		return notify_fail("现在" + item->name() + "的威力已经得到了充分的发挥了。\n");
	if (! item->query("magic/imbue_ok"))
		return notify_fail("现在" + item->name() + "的潜力还没有充分的激发，未到镶嵌的时候。\n");
	if (! tessera->query("can_be_enchased"))
		return notify_fail(tessera->name() + "好象没法用来镶嵌吧。\n");
	if (! mapp(tessera->query("magic")))
		return notify_fail(tessera->name() + "不能发挥魔力，没有必要镶嵌在" + item->name() + "上面。\n");

	if (me->query_skill("certosina", 1) < (30+item->level_now()*30))
		return notify_fail("你觉得你的镶嵌技艺还不够娴熟，不敢贸然动手。\n");

	if (me->query("max_jingli", 1) < 5000)
		return notify_fail("你的精力太低了，不足以驾驭上帝之眼，无法镶嵌。\n");
	pw = tessera->query("magic/power");
if(me->query("xq/"+item->query("id")+"s")<1)
{
	if(pw==30)
	{
		lvl = 1 + random(31);
	}
	else if(pw==60)
	{
		if(item->level_now()<3)
			return notify_fail(tessera->name() + "的魔力太强，而" + item->name() + "等级不够，请强化装备或者用低级宝石强化。\n");
		lvl = 30 + random(31);
	}
	else if(pw==100)
	{
		lvl = 60 + random(41);
		if(item->level_now()<5)
			return notify_fail(tessera->name() + "的魔力太强，而" + item->name() + "等级不够，请强化装备或者用低级宝石强化。\n");
	}
	else if(pw==150)
	{
		if(item->level_now()<7)
			return notify_fail(tessera->name() + "的魔力太强，而" + item->name() + "等级不够，请强化装备或者用低级宝石强化。\n");
		lvl = 100 + random(51);
	}
	else if(pw==200)
	{
		if(item->level_now()<9)
		return notify_fail(tessera->name() + "的魔力太强，而" + item->name() + "等级不够，请强化装备或者用低级宝石强化。\n");
		lvl = 150 + random(151);
	}
	else 
	lvl = 1;
	}else
	{	
	if(random(10)==5)  //累计加魔力
	{
	lvl=me->query("xq/"+item->query("id")+"s")+5+random(6);
	}else
	{
	lvl=me->query("xq/"+item->query("id")+"s")+5;
	}
	}

	if (me->query("balance") < tessera->query("magic/power")*10000)
		return notify_fail("你钱庄存款不足，不能进行宝石镶嵌！\n");

	me->add("balance",-tessera->query("magic/power")*10000);
	if (me->query("magic_points")<90000)
		me->set("max_jingli",me->query_jingli_limit());

	message_sort(HIM "“喀啦”一声，$N" HIM "将" + tessera->name() + HIM "镶嵌到了$n" HIM "上面，只见$n" HIM "上隐隐的显过了一道奇异的光芒，随"
		     "即变得平静，说不出的平凡。"NOR"\n", me, item);

	tell_object(me, HIC "你感受" + item->name() + HIC "发生了不可言喻的变化。"NOR"\n");
	item->set("magic/power", lvl);
	
	
	
	name=me->query("id");
	info = ([]);
	info[sss] = lvl; //武器魔力
	info["name_"+sss] = names; //武器名字
	set(name,info);
	
	
	
	me->set("xq/"+item->query("id")+"s",lvl); //累计加魔力 by寒江雪
	me->set("xqmoli",lvl); 
	item->set("magic/type", tessera->query("magic/type"));
	item->set("magic/tessera", tessera->name());
	item->save();
	tessera->add_amount(-1);

	// 发布消息
	if(lvl>149 && me->query("magic_points")>90000)
		CHANNEL_D->do_channel(this_object(), "rumor","听说神品" + item->name() + HIM + "来到了人间。");
	else if(lvl>99 && me->query("magic_points")>90000)
		CHANNEL_D->do_channel(this_object(), "rumor","听说" + item->name() + HIM + "锋芒乍现，威力大增。");

	me->start_busy(1);
	return 1;
}

// 强化装备
int do_enhance(object me, object item, object obj)
{
	int exp;
	mapping o;
	string my_id;

	if (! me || ! obj)
		return 0;
	 if(item->item_owner() != me->query("id"))
		  return notify_fail(item->name() + "不需要你来操心吧！\n");
	if(item->level_now()>8)
		return notify_fail("装备强化已达到最高等级，不需要再强化了！\n");
	exp = obj->query("item_exp");

	my_id = me->query("id");
	o = item->query("owner");
	if (! o) o = ([ ]);
	if (! undefinedp(o[my_id]) || sizeof(o) < 12)
		o[my_id] += exp;
	else
	{
		int i;
		int lowest;
		string *ks;

		lowest = 0;
		ks = keys(o);
		for (i = 1; i < sizeof(ks); i++)
			if (o[ks[lowest]] > o[ks[i]])
				lowest = i;
		map_delete(o, ks[lowest]);
		o += ([ my_id : exp ]);
	}
	item->set("owner", o);
	if(item->query("skill_type"))
	{
		item->set("weapon_prop/damage",item->apply_damage());
	}
	else if(item->query("armor_type")=="hands")
	{
		item->set("armor_prop/unarmed_damage",item->apply_damage());
	}
	else if(item->query("armor_type"))
	{
		item->set("armor_prop/armor",item->apply_armor());
	}
	tell_object(me, HIW "一阵微弱的光芒闪过，你觉得" + item->name() + HIW "似乎更具威力了。"NOR"\n");
	obj->add_amount(-1);
	if(obj)
		tell_object(me, HIM+ZJSIZE(20)+ZJURL("cmds:enhance "+file_name(item)+" with "+file_name(obj))"继续强化"NOR"\n");
	return 1;
}
//十甲装备特效
mixed valid_damages(object ob, object me, int damage, object weapon)
{
//头盔 head 护甲 armor 腰带 waist 裤子 pants 鞋子 boots
string zb,head,armor,waist,pants,boots;
mixed result;
mapping zbp=me->query_temp("armor");
if(!keys(zbp)) return 1;
foreach(zb in keys(zbp)){
	if(zbp[zb]->query("armor_type")=="head"){
	    head=zbp[zb]->query("magic/power");
	}
	if(zbp[zb]->query("armor_type")=="cloth"){
		armor=zbp[zb]->query("magic/power");
	}
	if(zbp[zb]->query("armor_type")=="cloth"){
		waist=zbp[zb]->query("magic/power");
	}
	if(zbp[zb]->query("armor_type")=="cloth"){
		pants=zbp[zb]->query("magic/power");
	}
	if(zbp[zb]->query("armor_type")=="cloth"){
		boots=zbp[zb]->query("magic/power");
	}
}
//头盔减busy 加血
if(head){
if(me->query_busy()){
if(random(10)==5){
me->add("qi",to_int(head));
me->add("eff_qi",to_int(head));
me->add_busy(-to_int(head)/100);
}else{
me->add("qi",to_int(head)/2);
me->add("eff_qi",to_int(head)/2);
me->add_busy(-3);
}
}
}
//战甲减少伤害
if(armor){
if(random(10)==5){
if(damage>(to_int(armor)/5)){
result = (["damage": -to_int(armor)/5]);
}
}else{
if(damage>(to_int(armor)/10)){	
result = (["damage": -to_int(armor)/10]);	
}  
}
}
//腰带加内功经脉
if(waist){
if(me->query_temp("shijia/forces")){
me->set_temp("shijia/forces",to_int(waist)/5);
}
}
//裤子加招架经脉
if(pants){
if(me->query_temp("shijia/parrys")){
me->set_temp("shijia/forces",to_int(pants)/5);
}
}
//鞋子加轻功经脉
if(boots){
if(me->query_temp("shijia/dodges")){
me->set_temp("shijia/forces",to_int(boots)/5);
}
}

return 1;
}




void receive_damage(object attack, object victim, string type, int damage)
{
	damage = COMBAT_D->calc_damage(attack, victim, damage);
	victim->receive_damage(type, damage);
}
void receive_wound(object attack, object victim, string type, int damage)
{
	damage = COMBAT_D->calc_wound(attack, victim, damage);
	victim->receive_wound(type, damage);
}
// 降低耐久度
void reduce_consistence(object item)
{
	int st;
	int con;

	st = item->query("stable");
	if (st < 2) return;

	con = item->query("consistence");

	if (random(st) > (100 - con) / 12)
		return;
	
	if (item->add("consistence", -1) > 0)
		return;

	item->set("consistence", 0);
	if (environment(item))
		tell_object(environment(item), HIG "你的" + item->name() + "已经彻底损坏了。\n");
	item->unequip();
}

// 构造物品缺省的耐久度信息
void equip_setup(object item)
{
	int stable;
	mapping prop,dbase;
	int i,k;
	string *attr_list = ({
		"damage",
		"armor",
                "attack",
                "parry",
                "dodge",
                "strength",
                "intelligence",
                "constitution",
                "dexerity",
                "karma",
                "personality",
                "speed",
                "maxqi",
                "maxnei",
	});

	for(i=0;i<sizeof(attr_list);i++)
	{
		if(k=item->query("armor_prop/"+attr_list[i]))
			item->set("armor_prop/"+attr_list[i], k);
		if(k=item->query("weapon_prop/"+attr_list[i]))
			item->set("weapon_prop/"+attr_list[i], k);
	}

	dbase = item->query_entire_dbase();
	if (undefinedp(dbase["consistence"]))
		dbase["consistence"] = 100;

	if (undefinedp(item->query("stable")))
	{
		switch (item->query("material"))
		{
		case "cloth":
			// 永远不会损坏
			stable = 0;
			break;

		case "paper":
			stable = 3;
			item->set("no_repair", "这东西我可没法修理。\n");
			break;

		case "bone":
			stable = 8;
			item->set("no_repear", "修理这个？可别拿我寻开心。\n");
			break;

		case "bamboo":
		case "wood":
			stable = 10;
			item->set("no_repair", "这东西我咋修理？\n");
			break;

		case "stone":
			stable = 20;
			item->set("no_repair", "这个坏了就坏了，可修不了。\n");
			break;

		case "copper":
			stable = 40;
			break;

		case "silver":
			stable = 40;
			break;

		case "iron":
			stable = 45;
			break;

		case "gold":
			stable = 50;
			break;

		case "steel":
			stable = 75;
			break;

		default:
			stable = 100;
			break;
		}

		if (! item->is_item_make())
			stable /= 2;

		item->set("stable", stable);
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
