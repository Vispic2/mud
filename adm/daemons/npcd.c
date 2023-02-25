// npcd.c

#pragma optimize
#pragma save_binary

#include <command.h>
#include <npc/name.h>
#include <npc/chinese.c>
#include <npc/japanese.c>
#include <npc/european.c>
#include <npc/masia.c>
#include <npc/indian.c>

#define HUANG_SHANG	     "/kungfu/class/ultra/huang"
#define DUGU_QIUBAI	     "/kungfu/class/ultra/dugu"
#define KUIHUA_TAIJIAN	  "/kungfu/class/ultra/kuihua"
#define NANHAI_SHENNI	   "/kungfu/class/ultra/shenni"

mapping levels = ([
//      combat_exp   skill_level
	50000      : 50,		// level 1
	100000     : 70,		// level 2
	200000     : 90,	       // level 3
	400000     : 115,	       // level 4
	800000     : 140,	       // level 5
	1200000    : 165,	       // level 6
	1600000    : 190,	       // level 7
	2000000    : 215,	       // level 8
	2500000    : 240,	       // level 9
	2700000    : 265,	       // level 10
	3000000    : 290,	       // level 11
	5000000    : 340,	       // level 12
	7500000    : 390,	       // level 13
	9000000    : 440,	       // level 14
	12000000   : 490,	       // level 15
	16000000   : 540,	       // level 16
	21000000   : 590,	       // level 17
	27000000   : 640,	       // level 18
	34000000   : 690,	       // level 19
	40000000   : 740,	       // level 20
	50000000   : 790,	       // level 21
	61000000   : 840,	       // level 22
	72000000   : 890,	       // level 23
	85000000   : 940,	       // level 24
]);
mapping levelss = ([
//      combat_exp   skill_level
	50000      : 100,		// level 1
	100000     : 120,		// level 2
	200000     : 140,	       // level 3
	400000     : 165,	       // level 4
	800000     : 190,	       // level 5
	1200000    : 205,	       // level 6
	1600000    : 240,	       // level 7
	2000000    : 265,	       // level 8
	2500000    : 260,	       // level 9
	2700000    : 315,	       // level 10
	3000000    : 340,	       // level 11
	5000000    : 360,	       // level 12
	7500000    : 440,	       // level 13
	9000000    : 490,	       // level 14
	12000000   : 540,	       // level 15
	16000000   : 590,	       // level 16
	21000000   : 640,	       // level 17
	27000000   : 690,	       // level 18
	34000000   : 740,	       // level 19
	40000000   : 790,	       // level 20
	50000000   : 840,	       // level 21
	61000000   : 890,	       // level 22
	72000000   : 940,	       // level 23
	85000000   : 990,	       // level 24
	//98000000   : 1000,	       // level 25
]);

mapping levelsss = ([
//      combat_exp   skill_level
	50000      : 130,		// level 1
	100000     : 150,		// level 2
	200000     : 180,	       // level 3
	400000     : 195,	       // level 4
	800000     : 220,	       // level 5
	1200000    : 245,	       // level 6
	1600000    : 270,	       // level 7
	2000000    : 295,	       // level 8
	2500000    : 320,	       // level 9
	2700000    : 345,	       // level 10
	3000000    : 370,	       // level 11
	5000000    : 420,	       // level 12
	7500000    : 470,	       // level 13
	9000000    : 520,	       // level 14
	12000000   : 570,	       // level 15
	16000000   : 620,	       // level 16
	21000000   : 670,	       // level 17
	27000000   : 720,	       // level 18
	34000000   : 770,	       // level 19
	40000000   : 820,	       // level 20
	50000000   : 850,	       // level 21
	61000000   : 920,	       // level 22
	72000000   : 970,	       // level 23
	85000000   : 1000,	       // level 24
]);
mapping place = ([
	"华山附近" : ({ "/d/huashan/pingxinshi", "/d/village/square",
			"/d/village/wexit", }),
	"扬州城"   : ({ "/d/city/beimen", "/d/city/nanmen",
			"/d/city/ximen", "/d/city/dongmen", }),
	"长安城"   : ({ "/d/changan/dong-chengmen", "/d/changan/nan-chengmen",
			"/d/changan/xi-chengmen", "/d/changan/bei-chengmen",
			"/d/changan/qinglong2", "/d/changan/baihu2", }),
	"武功镇"   : ({ "/d/quanzhen/xijie", "/d/quanzhen/nanjie", }),
	"佛山一带" : ({ "/d/foshan/street1", "/d/foshan/southgate", }),
	"南海一带" : ({ "/d/xiakedao/xkroad4" }),
	"汝州一带" : ({ "/d/shaolin/ruzhou" }),
	"嵩山一带" : ({ "/d/songshan/tianzhongge", "/d/shaolin/shijie1",
			"/d/shaolin/shijie8", }),
	"终南山"   : ({ "/d/quanzhen/shanlu1", "/d/quanzhen/shijie1",
			"/d/quanzhen/shijie9", "/d/quanzhen/cuipinggu",
			"/d/quanzhen/baishulin3", "/d/gumu/taiyi1",
			"/d/gumu/shenheyuan", "/d/quanzhen/banshanting", }),
	"成都城"   : ({ "/d/city3/southroad1", "/d/city3/qingyanggong",
			"/d/city3/northroad2", }),
	"星宿海"   : ({ "/d/xingxiu/tianroad2", }),
	"天山"     : ({ "/d/lingjiu/yan", }),
	"苏州城"   : ({ "/d/suzhou/xidajie2", "/d/suzhou/dongdajie2",
			"/d/suzhou/road5", "/d/suzhou/road1",
			"/d/suzhou/gumujiaohe", "/d/suzhou/zhenquting", }),
	"杭州城"   : ({ "/d/hangzhou/suti2", "/d/hangzhou/jujingyuan",
			"/d/hangzhou/liuzhuang", "/d/hangzhou/road19",
			"/d/hangzhou/huangniling", "/d/hangzhou/qinglindong", }),
	"襄阳城"   : ({ "/d/xiangyang/westjie2", "/d/xiangyang/southjie2",
			"/d/xiangyang/xiaorong1", "/d/xiangyang/zhonglie",
			"/d/xiangyang/guangchang", "/d/xiangyang/dingzi", }),
	"泉州城"   : ({ "/d/quanzhou/zhongxin", }),
	"福州城"   : ({ "/d/fuzhou/ximendajie", "/d/fuzhou/dongxiaojie",
			"/d/fuzhou/nanmen", }),
	"灵州"     : ({ "/d/lingzhou/xidajie", "/d/lingzhou/nanmen",
			"/d/lingzhou/dongdajie", }),
	"关外"     : ({ "/d/guanwai/baihe", "/d/guanwai/road8",
			"/d/guanwai/xuedi1", "/d/guanwai/beicheng",
			"/d/guanwai/shanshenmiao" }),
	"西域"     : ({ "/d/xingxiu/shamo5", "/d/baituo/gebi",
			"/d/xueshan/shenghu", "/d/xueshan/hubian4",
			"/d/xuedao/sroad3", "/d/xuedao/nroad6",
			"/d/mingjiao/gebitan5",
			"/d/xingxiu/nanjiang2" }),
	"大理一带" : ({ "/d/dali/northgate", "/d/dali/southgate",
			"/d/dali/shanlu2", "/d/dali/buxiongbu",
			"/d/dali/jinzhihe", "/d/dali/xiaodao1",
			"/d/dali/tianweijing", "/d/dali/wuding",
			"/d/dali/luwang", "/d/dali/gudao",
			"/d/dali/biluoxueshan", "/d/dali/zhenxiong",
			"/d/dali/yixibu", "/d/dali/cangshanzhong",
			"/d/dali/wumeng", "/d/dali/hongsheng", }),
]);

// return the character(ob) 's level, 0 is lowest
int check_level(object ob)
{
	int *exp;
	int i;

	exp = sort_array(keys(levels), 1);
	for (i = 0; i < sizeof(exp); i++)
		if (ob->query("combat_exp") < exp[i]) break;
	return i;
}

// set the the level of the npc's skill
void init_npc_skill(object ob, int lvl)
{
	int sk_lvl;
	string *ks;
	int i;
	int exp;
    object me=this_player();
	

	
	if(me->query("shimen/gaoji") >=1)
	{
	if (lvl < 1)
	lvl = 1;
	if (lvl >= sizeof(levelsss)) lvl = sizeof(levelsss) - 1;

	exp = sort_array(keys(levelsss), 1)[lvl - 1];
	ob->set("combat_exp", exp);
	sk_lvl = levelsss[exp];
	if (! ob->query_skills())
		return;
	ks = keys(ob->query_skills());
	for (i = 0; i < sizeof(ks); i++)
		ob->set_skill(ks[i], sk_lvl);
		
		}else
		if(me->query("shimen/zhongji") >=1)
		{
		if (lvl < 1)
	lvl = 1;
	if (lvl >= sizeof(levelss)) lvl = sizeof(levelss) - 1;
	exp = sort_array(keys(levelss), 1)[lvl - 1];
	ob->set("combat_exp", exp);
	sk_lvl = levelss[exp];
	if (! ob->query_skills())
		return;
	ks = keys(ob->query_skills());
	for (i = 0; i < sizeof(ks); i++)
	ob->set_skill(ks[i], sk_lvl);						
		}
		else{
		if (lvl < 1)
	lvl = 1;
	if (lvl >= sizeof(levels)) lvl = sizeof(levels) - 1;
	exp = sort_array(keys(levels), 1)[lvl - 1];
	ob->set("combat_exp", exp);
	sk_lvl = levels[exp];
	if (! ob->query_skills())
		return;
	ks = keys(ob->query_skills());
	for (i = 0; i < sizeof(ks); i++)
	ob->set_skill(ks[i], sk_lvl);						
		}
		
}

string *nations = ({ "中国", "日本", "龟慈", "荷兰", "天竺", "蒙古",
		     "俄罗斯", "英吉利", "法兰西", "西班牙", "葡萄牙",
		     "比利时", "塔吉克斯坦", "哈沙克斯坦", "乌兹别克斯坦" });

// generate a npc with nation & skill level
object create_npc(string nation, int lvl)
{
	object ob;

	switch (nation)
	{
	case "中国":
		ob = new(CLASS_D("generate") + "/chinese");
		NPC_D->generate_cn_name(ob);
		break;
	case "日本":
		ob = new(CLASS_D("generate") + "/japanese");
		NPC_D->generate_jp_name(ob);
		break;
	case "英吉利":
	case "法兰西":
	case "西班牙":
	case "葡萄牙":
	case "比利时":
	case "荷兰":
		ob = new(CLASS_D("generate") + "/european");
		NPC_D->generate_e_name(ob);
		break;
	case "天竺":
		ob = new(CLASS_D("generate") + "/indian");
		NPC_D->generate_in_name(ob);
		break;
	case "花剌子模":
	case "龟慈":
	case "俄罗斯":
	case "塔吉克斯坦":
	case "哈沙克斯坦":
	case "乌兹别克斯坦":
	case "蒙古":
		return 0;
	}

	ob->set("nation", nation);
	init_npc_skill(ob, lvl);

	return ob;
}

// generate challenger
object create_challenger()
{
	string *n;
	object *ob;
	int max_level;
	int i;
	int lvl;

	ob = all_interactive();
	max_level = 0;
	for (i = 0; i < sizeof(ob); i++)
		if (! wizardp(ob[i]) && max_level < check_level(ob[i]))
			max_level = check_level(ob[i]);

	max_level++;
	lvl = 1 + random(max_level);
	if (lvl < 3) lvl = max_level;

	n = ({ "日本", "日本", "日本",
	       "天竺",
	       "英吉利", "法兰西", "西班牙", "葡萄牙", "比利时", "荷兰", });
	return create_npc(n[random(sizeof(n))], lvl);
}

// set the basic parameter from me



void set_from_me(object tob, object fob, int scale)
{
    mapping my, hp_status;
    int i;
    int points;
    int tmpstr, tmpint, tmpcon, tmpdex;
    int reborn;
    reborn = 0;
    reborn = fob->query("reborn/count");
    tmpstr = tmpint = tmpcon = tmpdex = 10;

    hp_status = fob->query_entire_dbase();
    my = tob->query_entire_dbase();

    if (!scale)
    {
        if (undefinedp(my["scale"]))
            my["scale"] = 100 + reborn * 10;
        scale = my["scale"];
    }
    points = 80 - (tmpstr + tmpint + tmpcon + tmpdex);
    for (i = 0; i < points; i++)
    {
        switch (random(4))
        {
        case 0:
            if (tmpstr < 30)
                tmpstr++;
            else
                i--;
            break;
        case 1:
            if (tmpint < 30)
                tmpint++;
            else
                i--;
            break;
        case 2:
            if (tmpcon < 30)
                tmpcon++;
            else
                i--;
            break;
        case 3:
            if (tmpdex < 30)
                tmpdex++;
            else
                i--;
            break;
        }
    }
    my["str"] = tmpstr + reborn * 2;
    my["con"] = tmpcon + reborn * 2;
    my["dex"] = tmpdex + reborn * 2;
    my["int"] = tmpint + reborn * 2;
    my["per"] = 5 + random(25);

    my["max_qi"] = hp_status["max_qi"] * scale / 150;
    my["eff_qi"] = my["max_qi"];
    my["qi"] = my["max_qi"];
    my["max_jing"] = hp_status["max_jing"] * scale / 100;
    my["eff_jing"] = my["max_jing"];
    my["jing"] = my["max_jing"];
    my["max_neili"] = hp_status["max_neili"] * scale / 100;
    my["jiali"] = tob->query_skill("force") / 10 + random(tob->query_skill("force") / 4);
    my["neili"] = my["max_neili"];
    my["combat_exp"] = hp_status["combat_exp"];

    tob->set_from_me(fob, scale);
}
// select a random place
string random_place(string *not_place)
{
	string *kp;

	kp = keys(place);

	// exclude some place
	if (arrayp(not_place))
		kp -= not_place;

	// select a random place
	return kp[random(sizeof(kp))];
}

// place npc
void place_npc(object ob, string *not_place, string *in_place)
{
	string *kp;
	string p;
	string startroom;
	object pos;

	// select the place
	if (! arrayp(in_place))
		kp = keys(place);
	else
		kp = in_place;

	// exclude some place
	if (arrayp(not_place))
		kp -= not_place;

	// select the exact position
	for (;;)
	{
		p = kp[random(sizeof(kp))];
		startroom = place[p][random(sizeof(place[p]))];
		if (! objectp(pos = get_object(startroom)))
		{
			//log_files("log", sprintf("error to place npc to %s:%s\n",
				//		p, startroom));
			continue;
		}
		break;
	}

	// move to the position
	ob->move(pos);
	ob->set("place", p);
	ob->set("startroom", startroom);
	ob->set_temp("moved", ({ }));
	message_vision("$N走了过来。\n", ob);
}

#define MAX_MOVED       2

// random move
void random_move(object ob)
{
	mapping exits;
	string *moved;
	string dir;
	string *dirs;
	int i;

	moved = ob->query_temp("moved");
	if (! moved) moved = ({ });
	if (sizeof(moved) >= MAX_MOVED)
	{
		// out of range, move back
		dir = GO_CMD->query_reverse(moved[sizeof(moved) - 1]);
	} else
	{
		exits = environment(ob)->query("exits");
		dirs = keys(exits);
		for (i = 0; i < 12; i++)
		{
			if (! sizeof(dirs))
				return;
			dir = dirs[random(sizeof(dirs))];
			if (stringp(GO_CMD->query_reverse(dir)) &&
			    ! exits[dir]->query("no_fight"))
				break;
			dirs -= ({ dir });
		}
	}

	if (sizeof(moved) &&
	    GO_CMD->query_reverse(dir) == moved[sizeof(moved) - 1])
	{
		// move back
		moved = moved[0..<2];
	} else
		moved += ({ dir });
	ob->set_temp("moved", moved);

	GO_CMD->main(ob, dir);
}

// get all ultra master
object *query_ultra_master()
{
	return ({ get_object(HUANG_SHANG),
		  get_object(DUGU_QIUBAI),
		  get_object(KUIHUA_TAIJIAN),
		  get_object(NANHAI_SHENNI) });
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
