// chan_cler 中国挑战者

inherit NPC;

// internal functions
private void from_wudang();
private void from_shaolin();
private void from_huashan();
private void from_ouyang();
private void from_gaibang();
private void from_taohua();
private void from_gumu();
private void from_xingxiu();
private void from_xueshan();
private void from_xuedao();
private void from_xiaoyao();
private void from_shenlong();
private void from_quanzhen();

// external functions
public void setup_family(string family);

mapping init_family = ([
	"少林寺"   : (: from_shaolin :),
	"武当派"   : (: from_wudang :),
	"丐帮"     : (: from_gaibang :),
	"全真教"   : (: from_quanzhen :),
	"华山派"   : (: from_huashan :),
	"雪山寺"   : (: from_xueshan :),
	"桃花岛"   : (: from_taohua :),
	"神龙教"   : (: from_shenlong :),
	"古墓派"   : (: from_gumu :),
	"星宿派"   : (: from_xingxiu :),
	"逍遥派"   : (: from_xiaoyao :),
	"血刀门"   : (: from_xuedao :),
	"欧阳世家" : (: from_ouyang :),
	 ]);


void create()
{
	string *fams;

	NPCS_D->generate_cn_name(this_object());
	set("long", "一个人。\n");
	set("gender", "男性");
	set("age", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	// the follow 5 setting has no use	
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 100);

	set("combat_exp", 3000000);

	setup();

	fams = keys(init_family);
	setup_family(fams[random(sizeof(fams))]);
}

void setup_family(string family)
{
	function f;
	mapping skills;
	string *fams,skill;

	family = FAMILY_D->query_family_name(family);
	if(undefinedp(init_family[family]))
	{
		fams = keys(init_family);
		family = fams[random(sizeof(fams))];
	}
	if (! functionp(f = init_family[family]))
		return;

	if (mapp(skills = query_skills()))
	{
		// remove all skill
		foreach (skill in keys(skills))
			delete_skill(skill);

	}

	// set family information
	set("family/family_name", family);
	set("family/generation", 0);

	evaluate(f);
}

private void from_wudang()
{
	set("scale", 200);
	set("from", ({
		"据说此人出自武当，是武当派的高手，然而修武不修德，可惜啊可惜。",
		"听闻此人本是武当山下一农夫，耳渎目染，居然练就成非凡武功。",
		"据说此人乃武当弃徒，当年犯了杀戒逃至东洋，不想今日返回中原！",
	}));

	set_skill("force", 1);
	set_skill("taiji-shengong", 1);
	set_skill("parry", 1);
	set_skill("dodge", 1);
	set_skill("tiyunzong", 1);
	set_skill("sword", 1);
	set_skill("taiji-jian", 1);
	set_skill("hand", 1);
	set_skill("paiyun-shou", 1);
	set_skill("unarmed", 1);
	set_skill("taiji-quan", 1);

	map_skill("parry", "taiji-jian");
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("sword", "taiji-jian");
	map_skill("hand", "paiyun-shou");
	map_skill("unarmed", "taiji-quan");

	prepare_skill("hand", "paiyun-shou");
	prepare_skill("unarmed", "taiji-quan");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: exert_function, "recover" :),
	}) );

	set("class", "taoist");

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

private void from_shaolin()
{
	set("scale", 150);
	set("from", ({
		"据说此人出自少林，是少林的俗家高手，可却没有半点慈悲之心，唉！",
		"听闻此人偷师于少林，练就了一身超凡脱俗的本领。",
		"据说此人乃少林的火工头陀，偷学武艺后被发现，竟然打死"
		+ "达摩院长老出逃西域，想不到今日返回中原！",
		"据说此人当年犯了少林的戒律，被迫离寺，想不到隐居多年"
		+ "以后居然重出江湖。"
	}));

	set_skill("force", 1);
	set_skill("hunyuan-yiqi", 1);
	set_skill("parry", 1);
	set_skill("dodge", 1);
	set_skill("shaolin-shenfa", 1);
	set_skill("sword", 1);
	set_skill("damo-jian", 1);
	set_skill("finger", 1);
	set_skill("nianhua-zhi", 1);
	set_skill("strike", 1);
	set_skill("sanhua-zhang", 1);

	map_skill("parry", "damo-jian");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("sword", "damo-jian");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "sword.sanjue" :),
		(: perform_action, "strike.san" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set("class", "bonze");

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

private void from_huashan()
{
	set("scale", 130);
	set("from", ({
		"据说此人出自华山，无恶不作，后来行迹忽然不见，想不到今日又出头。",
		"听闻此人本是华山长老，因剑气之争远投异地，不知何故返回中原！",
		"据说此人本是别派卧底到华山去的，偷学本领以后没回本派"
		+ "反而觅地苦修，今日终于得出江湖。",
	}));

	set_skill("force", 1);
	set_skill("zixia-shengong", 1);
	set_skill("parry", 1);
	set_skill("dodge", 1);
	set_skill("feiyan-huixiang", 1);
	set_skill("sword", 1);
	set_skill("huashan-sword", 1);
	set_skill("cuff", 1);
	set_skill("poyu-quan", 1);
	set_skill("strike", 1);
	set_skill("hunyuan-zhang", 1);

	map_skill("parry", "huaxian-sword");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("sword", "huashan-sword");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jianzhang" :),
		(: perform_action, "sword.jie" :),
		(: perform_action, "cuff.leidong" :),
		(: perform_action, "cuff.poshi" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set("class", "fighter");

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

private void from_ouyang()
{
	set("scale", 130);
	set("from", ({
		"据说此人原是当今武林宗师欧阳锋的兄长，不知何故失踪，今"
		+ "日居然又出现了。",
		"听闻此人偷学了西域白驼山庄欧阳世家的武功，后来被欧阳"
		+ "锋发现打成重伤，此人带伤而走，竟然活到今日，不可思议！",
	}));

	set_skill("force", 1);
	set_skill("hamagong", 1);
	set_skill("parry", 1);
	set_skill("dodge", 1);
	set_skill("chanchu-bufa", 1);
	set_skill("staff", 1);
	set_skill("lingshe-zhangfa", 1);
	set_skill("cuff", 1);
	set_skill("lingshe-quan", 1);
	set_skill("finger", 1);
	set_skill("shedu-qiqiao", 1);

	map_skill("force", "hamagong");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("dodge", "chanchu-bufa");
	map_skill("staff", "lingshe-zhangfa");
	map_skill("cuff", "lingshe-quan");
	map_skill("finger", "shedu-qiqiao");

	prepare_skill("cuff", "lingshe-quan");
	prepare_skill("finger", "shedu-qiqiao");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "staff.chan" :),
		(: perform_action, "staff.qianshe" :),
		(: perform_action, "staff.wuji" :),
		(: perform_action, "cuff.rou" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

private void from_gaibang()
{
	set("scale", 130);
	set("from", ({
		"据说此人原是丐帮长老，武功高绝，后因欺辱良家女子而被"
		+ "逐出帮外，今日重现江湖比如又起血雨腥风。"
	}));

	set_skill("force", 1);
	set_skill("huntian-qigong", 1);
	set_skill("parry", 1);
	set_skill("dodge", 1);
	set_skill("feiyan-zoubi", 1);
	set_skill("staff", 1);
	set_skill("dagou-bang", 1);
	set_skill("strike", 1);
	set_skill("dragon-strike", 1);

	map_skill("force", "huntian-qigong");
	map_skill("parry", "dagou-bang");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("staff", "dagou-bang");
	map_skill("strike", "dragon-strike");

	prepare_skill("strike", "dragon-strike");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "staff.chan" :),
		(: perform_action, "staff.ban" :),
	}) );

	set("class", "begger");

	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

private void from_taohua()
{
	set("scale", 135);
	set("from", ({
		"据说此人和桃花岛主黄药师有些关系。",
	}));

	set_skill("force", 1);
	set_skill("bibo-shengong", 1);
	set_skill("parry", 1);
	set_skill("dodge", 1);
	set_skill("anying-fuxiang", 1);
	set_skill("sword", 1);
	set_skill("yuxiao-jian", 1);
	set_skill("hand", 1);
	set_skill("lanhua-shou", 1);
	set_skill("finger", 1);
	set_skill("tanzhi-shentong", 1);

	map_skill("parry", "yuxiao-jian");
	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("sword", "yuxiao-jian");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");

	prepare_skill("hand", "lanhua-shou");
	prepare_skill("unarmed", "tanzhi-shentong");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: perform_action, "sword.qing" :),
		(: perform_action, "sword.tianwai" :),
		(: perform_action, "hand.fuxue" :),
		(: perform_action, "finger.jinglei" :),
		(: exert_function, "recover" :),
	}) );

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

private void from_gumu()
{
	object ob;

	set("scale", 130);
	set("from", ({
		"据说此人是林朝英的弟子，被她逐出师门了。",
		"这人据说是古墓传人，和李莫愁颇有渊源。",
	}));

	set_skill("force", 1);
	set_skill("yunv-xinfa", 1);
	set_skill("parry", 1);
	set_skill("dodge", 1);
	set_skill("yunv-shenfa", 1);
	set_skill("unarmed", 1);
	set_skill("meinv-quan", 1);
	set_skill("strike", 1);
	set_skill("fireice-strike", 1);
	set_skill("tianluo-diwang", 1);
	set_skill("throwing", 1);
	set_skill("yufeng-zhen", 1);
	set_skill("sword", 1);
	set_skill("yunv-jian", 1);
	set_skill("quanzhen-jian", 1);

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");
	map_skill("strike", "tianluo-diwang");
	map_skill("throwing", "yufeng-zhen");

	prepare_skill("unarmed", "meinv-quan");
	prepare_skill("strike", "tianluo-diwang");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: perform_action, "strike.wang" :),
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "unarmed.you" :),
		(: perform_action, "throwing.wuying" :),
	}) );

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	ob = carry_object("/d/gumu/obj/yfzhen");
	ob->set_amount(300);
	set_temp("handing", ob);
}

private void from_quanzhen()
{
	object ob;

	set("scale", 130);
	set("from", ({
		"据说此人是全真派的弟子，被她逐出师门了。",
		"这人据说是全真派传人，和王重阳颇有渊源。",
	}));

	set_skill("force", 1);
	set_skill("quanzhen-xinfa", 1);
	set_skill("parry", 1);
	set_skill("dodge", 1);
	set_skill("jinyan-gong", 1);
	set_skill("strike", 1);
	set_skill("haotian-zhang", 1);
	set_skill("chongyang-shenzhang", 1);
	set_skill("finger", 1);
	set_skill("zhongnan-zhi", 1);
	set_skill("sword", 1);
	set_skill("quanzhen-jian", 1);

	map_skill("force", "quanzhen-xinfa");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "haotian-zhang");
	map_skill("strike", "haotian-zhang");
	map_skill("finger", "zhongnan-zhi");

	prepare_skill("strike", "haotian-zhang");
	prepare_skill("finger", "zhongnan-zhi");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.hua" :),
		(: perform_action, "strike.ju" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

private void from_xingxiu()
{
	set("scale", 130);
	set("from", ({
		"据说此人是星宿派弟子，因为得罪了老仙，只好逃出星宿派。",
	}));

	set_skill("force", 1);
	set_skill("huagong-dafa", 1);
	set_skill("guixi-gong", 1);
	set_skill("throwing", 1);
	set_skill("feixing-shu", 1);
	set_skill("dodge", 1);
	set_skill("zhaixinggong", 1);
	set_skill("strike", 1);
	set_skill("chousui-zhang", 1);
	set_skill("claw", 1);
	set_skill("sanyin-wugongzhao", 1);
	set_skill("whip", 1);
	set_skill("chanhun-suo", 1);
	set_skill("parry", 1);
	set_skill("staff", 1);
	set_skill("poison", 1);
	set_skill("tianshan-zhang", 1);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("whip", "chanhun-suo");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "staff.fugu" :),
		(: perform_action, "staff.xue" :),
		(: perform_action, "strike.biyan" :),
		(: perform_action, "strike.huolang" :),
		(: perform_action, "strike.huoqiu" :),
		(: perform_action, "strike.huoyan" :),
		(: perform_action, "claw.zhua" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

private void from_xueshan()
{
	set("scale", 135);
	set("from", ({
		"据说此人是雪山派的高手，独创中原，横行无忌，武功甚是了得。",
	}));

	set_skill("force", 1);
	set_skill("longxiang-gong", 1);
	set_skill("mizong-neigong", 1);
	set_skill("dodge", 1);
	set_skill("shenkong-xing", 1);
	set_skill("cuff", 1);
	set_skill("yujiamu-quan", 1);
	set_skill("hand", 1);
	set_skill("dashou-yin", 1);
	set_skill("parry", 1);
	set_skill("staff", 1);
	set_skill("xiangmo-chu", 1);
	set_skill("lamaism", 1);
	set_skill("hammer", 1);
	set_skill("riyue-lun", 1);

	map_skill("force", "longxiang-gong");
	map_skill("dodge", "shenkong-xing");
	map_skill("cuff", "yujiamu-quan");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "riyue-lun");
	map_skill("sword", "xiangmo-chu");
	map_skill("hammer", "riyue-lun");

	prepare_skill("hand", "dashou-yin");
	prepare_skill("cuff", "yujiamu-quan");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "hammer.poli" :),
		(: perform_action, "hammer.wulun" :),
		(: perform_action, "hand.jingang" :),
		(: perform_action, "cuff.chen" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));

	set("class", "bonze");

	carry_object("/d/xueshan/obj/yinlun")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

private void from_xuedao()
{
	set("scale", 135);
	set("from", ({
		"据说此人和西域血刀老祖是师兄弟，一般的心狠手辣。",
	}));

	set_skill("lamaism", 1);
	set_skill("force", 1);
	set_skill("parry", 1);
	set_skill("blade", 1);
	set_skill("xue-dao", 1);
	set_skill("sword", 1);
	set_skill("mingwang-jian", 1);
	set_skill("dodge", 1);
	set_skill("mizong-neigong", 1);
	set_skill("xuehai-mogong", 1);
	set_skill("shenkong-xing", 1);
	set_skill("hand", 1);
	set_skill("dashou-yin", 1);
	set_skill("cuff", 1);
	set_skill("yujiamu-quan", 1);

	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("cuff", "yujiamu-quan");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");
	map_skill("sword", "mingwang-jian");

	prepare_skill("cuff", "yujiamu-quan");
	prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "blade.shendao" :),
		(: perform_action, "blade.xueyu" :),
		(: perform_action, "hand.jingang" :),
		(: perform_action, "cuff.chen" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));

	set("class", "bonze");

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

private void from_xiaoyao()
{
	set("scale", 135);
	set("from", ({
		"据说此人和逍遥派无崖子本是同门弟子。后来不知何故翻脸成仇。",
	}));

	set_skill("force", 1);
	set_skill("xiaoyao-xinfa", 1);
	set_skill("beiming-shengong", 1);
	set_skill("dodge", 1);
	set_skill("feiyan-zoubi", 1);
	set_skill("liuyang-zhang", 1);
	set_skill("parry", 1);
	set_skill("blade", 1);
	set_skill("ruyi-dao", 1);
	set_skill("zhemei-shou", 1);
	set_skill("hand", 1);
	set_skill("strike", 1);
	set_skill("literate", 1);

	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingbo-weibu");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");

	set("class", "taoist");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "blade.ruyi" :),
		(: perform_action, "hand.jiubu" :),
		(: perform_action, "strike.jiutian" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

private void from_shenlong()
{
	set("scale", 135);
	set("from", ({
		"据说此人是神龙岛洪教主的亲传弟子，后来判出神龙教。独闯江湖。",
	}));

	set_skill("force", 1);
	set_skill("shenlong-xinfa", 1);
	set_skill("dodge", 1);
	set_skill("yixingbu", 1);
	set_skill("hand", 1);
	set_skill("shenlong-bashi", 1);
	set_skill("strike", 1);
	set_skill("huagu-mianzhang", 1);
	set_skill("parry", 1);
	set_skill("staff", 1);
	set_skill("sword", 1);
	set_skill("shedao-qigong", 1);
	set_skill("literate", 1);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-qigong");
	map_skill("staff", "shedao-qigong");

	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "strike.hua" :),
		(: perform_action, "hand.xian" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));

	carry_object("/clone/misc/cloth")->wear();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
