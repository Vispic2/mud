// tufei.c
inherit NPC;
/*
int do_miaosha(string arg){
	object me=this_player();
	
	if(arg == query("id")){
		set("miaosha",1);
		
		message_vision(HIM"只见$n突然使出大杀器，拿出一把"HIY"『菜刀』"HIM"狠狠地砸向了$N。\n"NOR,this_object(), me);
		
		receive_damage("qi", 9999999999, this_player());
		return 1;
	}
	return 0;
}
*/
void do_woht(){
	set("neili",query("max_neili"));
	tell_object(this_object(),HIW"你握住和田玉，玉石内灵气迅速进入你的丹田，顿觉一阵畅快!瞬息之间丹田便己补满。"NOR"\n");
}

int do_usebmd(){
    object me = this_object();
	
	if (me->is_busy())
        return notify_fail("你正忙着呢。\n");

	if (me->query("eff_qi")*100/ (me->query("max_qi"))>99 
		&& me->query("eff_jing")*100/ (me->query("max_jing"))>99)
		return notify_fail("你现在不需要服用天王保命丹。\n");
	else {
		if( me->query_condition("medicine")>0 )
			return notify_fail("你上一次服药的药性还没有过呢！\n");

		me->set("eff_qi",me->query("max_qi"));
		me->set("eff_jing",me->query("max_jing"));

		message_vision("$N服下一" + query("unit") + "天王保命丹，顿时伤势痊愈了。\n", me);
		me->apply_condition("medicine",4);
		me->start_busy(2);
	}
}

void copy_status(object me,int xs)
{
	float lvl;
	
 	lvl =(700+xs*3) * 1.15 / 1000.0;
	
	set("max_qi", 		to_int(me->query("max_qi")*lvl*1.0));
	set("eff_qi", 		to_int(me->query("max_qi")*lvl*1.0));
	set("qi", 			to_int(me->query("max_qi")*lvl*1.0));
	
	set("max_jing", 	to_int(me->query("max_jing")*lvl));
	set("eff_jing", 	to_int(me->query("max_jing")*lvl));
	set("jing", 		to_int(me->query("max_jing")*lvl));
	
 	set("max_neili", 	to_int(me->query("max_neili")*lvl));
 	set("neili",  		to_int(me->query("max_neili")*lvl));
 	set("max_jingli",  	to_int(me->query("max_jingli")*lvl));
 	set("eff_jingli", 	to_int(me->query("max_jingli")*lvl));
 	set("jingli", 		to_int(me->query("max_jingli")*lvl));
 	set("combat_exp",	to_int(me->query("combat_exp")*lvl));

}

int copy_skills(object me,int xs)
{
	int i,lvl,skill=0;
	mapping skills;
	string *sk;

	skill=(int)me->query_skill("force",1);	
	// skills = me->query_skills();
	// if (mapp(skills))
	// {
		// sk = keys(skills);

		// for (i = 0;i < sizeof(sk);i++){
			// if(skill < (int)me->query_skill(sk[i],1)) skill = (int)me->query_skill(sk[i],1);	
		// }
	// }	
	
	lvl = to_int(skill * (700+xs*3) * 1.15 / 1000.0);
	
	skills = query_skills();
	if (mapp(skills))
	{
		sk = keys(skills);

		for (i = 0;i < sizeof(sk);i++)
			skills[sk[i]] = lvl;
	}
	
	set_temp("apply/attack", to_int(lvl*1)); 			//战斗攻击
	set_temp("apply/defense", to_int(lvl*1));			//战斗防御
	set_temp("apply/damage", to_int(lvl*1));			//武器伤害
	set_temp("apply/unarmed_damage", to_int(lvl*1));	//空手伤害
	set_temp("apply/armor", to_int(lvl*1.5));			//装备防御	
		
	return lvl;
}

void do_copy_player(object me,int xs)
{
	int lvl;
	
	set("xs",xs);
	
	copy_status(me,xs);
	lvl = copy_skills(me,xs);
	
	if(query_temp("mp") == 0){
		set_name("武当弟子", ({ "wu dang"+random(999) }));
		create_family("武当派",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;wield long sword;jiali max;perform unarmed.zhen;exert force.powerup;perform sword.sui;perform sword.zhenwu|qi|<|60;jiali 0;perform sword.sanhuan;perform sword.lian;usebmd|qi|<|30;woht|neili|<|50000");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 1){
		set_name("少林弟子", ({ "shao lin"+random(999) }));
		create_family("少林派",2, "弟子");
		set("zdjb/s1","woht;exert recover|qi|<|30;jiali max;perform strike.bafang:30;usebmd|qi|<|30");
		set("zdjb/def",1);
	
	}else if(query_temp("mp") == 2){
		set_name("华山弟子", ({ "hua shan"+random(999) }));
		create_family("华山派",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|25;unwield long sword;perform cuff.feng;exert force.powerup;perform cuff.leidong;wield long sword;jiali max;perform cuff.poshi;usebmd|qi|<|30;jiali 1;perform sword.jianzhang;woht|neili|<|50000;zdjb 2|qi|<|70");
		set("zdjb/s2","exert recover|qi|<|25;unwield long sword;perform cuff.feng;exert force.powerup;perform cuff.leidong;wield long sword;jiali max;perform cuff.poshi;usebmd|qi|<|30;jiali 1;perform sword.sanxian;woht|neili|<|50000;zdjb 3|qi|<|30");
		set("zdjb/s3","exert recover|qi|<|25;unwield long sword;perform cuff.feng;exert force.powerup;perform cuff.leidong;wield long sword;jiali max;perform cuff.poshi;usebmd|qi|<|30;perform sword.feilong|qi|<|20;perform sword.sanxian;woht|neili|<|50000;zdjb 1|qi|<|70");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 3){
		set_name("神龙弟子", ({ "shen long"+random(999) }));
		create_family("神龙教",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;woht|neili|<|50000;exert force.powerup;perform parry.chang1;jiali max;perform hand.huixiang;perform hand.huimou;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 4){
		set_name("丐帮弟子", ({ "gai bang"+random(999) }));
		create_family("丐帮",2, "弟子");
		set("zdjb/s1","wield gangzhang;perform staff.chan;exert force.powerup;woht;exert recover|qi|<|50;perform staff.wugou;unwield gangzhang;perform strike.xiang;usebmd|qi|<|50");
		set("zdjb/def",1);		
		
	}else if(query_temp("mp") == 5){
		set_name("桃花弟子", ({ "tao hua"+random(999) }));		
		carry_object("/d/taohua/obj/yuxiao")->wield();
		set("zdjb/s1","exert recover|qi|<|20;wield long sword;jiali max;exert force.powerup;perform finger.jinglei;perform sword.tianwai;usebmd|qi|<|30;woht|neili|<|50000");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 6){
		set_name("古墓弟子", ({ "gu mu"+random(999) }));
		create_family("古墓派",2, "弟子");
		set("couple/id",1);
		set_skill("martial-cognize", to_int(query_skill("martial-cognize",1)*0.3));
		set("zdjb/s1","exert recover|qi|<|20;woht|neili|<|50000;wield long sword;perform sword.juan;exert force.powerup;exert force.shield;jiali max;perform unarmed.sad;perform sword.luan;usebmd|qi|<|30");
		set("zdjb/def",1);		
		
	}else if(query_temp("mp") == 7){
		set_name("雪山弟子", ({ "xue shan"+random(999) }));
		create_family("雪山派",2, "弟子");
		carry_object("/d/xueshan/obj/sengmao")->wear();
		
		carry_object("/d/xueshan/obj/yinlun");
		carry_object("/d/xueshan/obj/yinlun");
		carry_object("/d/xueshan/obj/yinlun");
		carry_object("/d/xueshan/obj/yinlun");

		set("zdjb/s1","exert recover|qi|<|20;wield yin lun;woht|neili|<|50000;exert force.powerup;exert force.shield;perform parry.yuan;jiali max;perform cuff.chen;perform hammer.wulun;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 8){
		set_name("星宿弟子", ({ "xing xiu"+random(999) }));
		create_family("星宿派",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;woht|neili|<|99;exert force.powerup;jiali max;perform strike.huolang;perform parry.xue;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 9){
		set_name("欧阳弟子", ({ "ou yang"+random(999) }));
		create_family("欧阳世家",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;woht|neili|<|50000;exert force.powerup;exert force.reserve;bei none;jiali max;jifa unarmed hamagong;bei unarmed;perform unarmed.tui;perform staff.wanshi;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 10){
		set_name("全真弟子", ({ "quan zhen"+random(999) }));
		create_family("全真教",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;woht|neili|<|50000;wield long sword;jiali max;perform sword.chan;exert force.powerup;exert force.shield;perform strike.ju;perform sword.hua;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 11){
		set_name("逍遥弟子", ({ "xiao yao"+random(999) }));
		create_family("逍遥派",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;wield iron blade;woht|neili|<|50000;jifa dodge feiyan-zoubi;exert force.powerup;exert force.shield;jiali max;perform hand.hai;perform blade.ruyi;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 12){
		set_name("血刀弟子", ({ "xue dao"+random(999) }));
		create_family("血刀门",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|50;wield iron blade;perform blade.huan;exert force.powerup;exert force.jixue;jiali max;perform cuff.chen;jiali 1;perform blade.xueyu;usebmd|qi|<|30;woht|neili|<|50000");
		set("zdjb/def",1);
	}else if(query_temp("mp") == 13){
		set_name("明教弟子", ({ "ming jiao"+random(999) }));
		create_family("明教",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;jifa force jiuyang-shengong;wield long sword;exert force.powerup;exert force.shield;jifa force shenghuo-shengong;woht|neili|<|50000;perform cuff.qimai;perform sword.sui;jifa sword taiji-jian;perform sword.sui;jifa parry taiji-jian;perform sword.sanhuan;jifa sword shenghuo-ling;perform sword.canxue;jifa parry qiankun-danuoyi;usebmd|qi|<|30");
		set("zdjb/def",1);
	}else if(query_temp("mp") == 14){
		set_name("峨嵋弟子", ({ "e mei"+random(999) }));
		create_family("峨嵋派",2, "弟子");
		set("gender", "女性");
		set("zdjb/s1","exert recover|qi|<|20;woht|neili|<|50000;wield long sword;jiali max;exert force.powerup;perform strike.zhao;perform sword.hui;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 15){
		set_name("关外弟子", ({ "guan wai"+random(999) }));
		create_family("关外胡家",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;wield iron blade;hand long sword;jifa blade daojian-guizhen;jifa sword daojian-guizhen;jiali max;exert force.powerup;perform strike.huang;perform blade.xue;usebmd|qi|<|30;woht|neili|<|50000");
		set("zdjb/def",1);		
		
	}else if(query_temp("mp") == 16){
		set_name("慕容弟子", ({ "mu rong"+random(999) }));
		create_family("慕容世家",2, "弟子");
		set_skill("martial-cognize", to_int(query_skill("martial-cognize",1)*0.5));
		set("zdjb/s1","exert recover|qi|<|20;woht|neili|<|50000;jiali max;perform finger.lian;exert force.powerup;perform finger.canshang;perform finger.zhi|qi|<|70;perform parry.yi;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 17){
		set_name("段氏弟子", ({ "duan shi"+random(999) }));
		create_family("段氏皇族",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;woht|neili|<|50000;exert force.powerup;jiali max;perform strike.bian;perform sword.jue;usebmd|qi|<|30");
		set("zdjb/def",1);	
		
	}else if(query_temp("mp") == 18){
		set_name("日月弟子", ({ "ri yue"+random(999) }));
		create_family("日月神教",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;wield long sword;jifa force xixin-dafa;woht|neili|<|50000;perform sword.chan;exert force.powerup;jiali max;perform strike.huashen;perform sword.chuanxin|qi|<|70;perform sword.moxiao;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 19){
		set_name("昆仑弟子", ({ "kun lun"+random(999) }));
		create_family("昆仑派",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|20;wield long sword;woht|neili|<|50000;exert force.powerup;jiali max;perform strike.shi;perform sword.fanyin;usebmd|qi|<|30");
		set("zdjb/def",1);
		
	}else if(query_temp("mp") == 20){
		set_name("灵鹫弟子", ({ "ling jiu"+random(999) }));
		create_family("灵鹫宫",2, "弟子");
		set("zdjb/s1","exert recover|qi|<|25;unwield long sword;perform hand.zhe;exert force.powerup;exert force.shield;wield long sword;jiali 1;perform sword.zhu;perform sword.san;jiali max;perform strike.jiutian|qi|<|70;perform strike.zhong;usebmd|qi|<|30;woht|neili|<|50000");
		set("zdjb/def",1);
		
	}
	
	carry_object("/clone/weapon/changjian");
	carry_object("/clone/weapon/changjian");
	carry_object("/clone/weapon/changjian");
	carry_object("/clone/weapon/changjian");
	
	carry_object("/clone/weapon/gangdao");
	carry_object("/clone/weapon/gangdao");
	carry_object("/clone/weapon/gangdao");
	carry_object("/clone/weapon/gangdao");

}

void set_basic()
{       
	set_skill("literate",500);
	set_skill("strike", 500);
	set_skill("cuff", 500);
	set_skill("hand", 500);
	set_skill("dodge", 500);
	set_skill("sword", 500);
	set_skill("finger", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("blade", 500);
	set_skill("hammer", 500);
	set_skill("club", 500);
	set_skill("staff", 500);
	set_skill("whip", 500);
	set_skill("dagger", 500);
	set_skill("claw", 500);
	set_skill("unarmed", 500);
}

void set_martial(int mp)
{
        string weapon = "null";
		set_temp("mp",mp);
		
		switch(mp)
        {
                case 0:  // 武当
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

                        weapon = "changjian";
                        break;
                case 1: //少林
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

					 set_skill("shenzhang-bada", 1);
					 map_skill("strike", "shenzhang-bada");
					 
                     map_skill("parry", "damo-jian");
                     map_skill("force", "hunyuan-yiqi");
                     map_skill("dodge", "shaolin-shenfa");
                     map_skill("sword", "damo-jian");
                     map_skill("finger", "nianhua-zhi");
                     //map_skill("strike", "sanhua-zhang");

                     prepare_skill("finger", "nianhua-zhi");
                     prepare_skill("strike", "sanhua-zhang");

                        //weapon = "changjian";
						weapon = "null";
                        break;
                case 2:  //华山
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

                     map_skill("parry", "huashan-sword");
                     map_skill("force", "zixia-shengong");
                     map_skill("dodge", "feiyan-huixiang");
                     map_skill("sword", "huashan-sword");
                     map_skill("cuff", "poyu-quan");
                     map_skill("strike", "hunyuan-zhang");

                     prepare_skill("cuff", "poyu-quan");
                     prepare_skill("strike", "hunyuan-zhang");

                        weapon = "changjian";
                        break;
                case 3: //神龙
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


                        break;
                case 4:  //丐帮
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

                        weapon = "gangzhang";
                        break;
                case 5:  //桃花
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

                        //weapon = "changjian";
						weapon = "null";
                        break;
                case 6: //古墓
					set_skill("force", 290);
					set_skill("yunv-xinfa", 290);
					set_skill("surge-force", 290);
					set_skill("sword", 280);
					set_skill("yunv-jian", 280);
					set_skill("quanzhen-jian", 280);
					set_skill("xuantie-jian", 280);
					set_skill("dodge", 250);
					set_skill("yunv-shenfa", 250);
					set_skill("parry", 285);
					set_skill("unarmed", 285);
					set_skill("meinv-quan", 270);
					set_skill("strike", 280);
					set_skill("sad-strike", 280);
					set_skill("fireice-strike", 280);
					set_skill("tianluo-diwang", 260);
					set_skill("literate", 150);
					set_skill("taoism", 80);
					set_skill("medical", 180);
					set_skill("yunv-xinjing", 180);
					set_skill("throwing", 240);
					set_skill("yufeng-zhen", 240);
					set_skill("martial-cognize", 240);
					
					map_skill("force", "surge-force");
					map_skill("sword", "xuantie-jian");
					map_skill("dodge", "yunv-shenfa");
					map_skill("parry", "meinv-quan");
					map_skill("unarmed", "sad-strike");
					map_skill("strike", "tianluo-diwang");

					prepare_skill("unarmed", "sad-strike");

                        weapon = "changjian";
                        break;
                case 7: //雪山寺
				
					set_skill("force", 260);
					set_skill("longxiang-gong", 260);
					set_skill("mizong-neigong", 260);
					set_skill("dodge", 210);
					set_skill("shenkong-xing", 210);
					set_skill("cuff", 240);
					set_skill("yujiamu-quan", 240);
					set_skill("hand", 250);
					set_skill("dashou-yin", 250);
					set_skill("parry", 250);
					set_skill("staff", 220);
					set_skill("xiangmo-chu", 220);
					set_skill("lamaism", 210);
					set_skill("literate", 200);
					set_skill("hammer", 270);
					set_skill("riyue-lun", 270);
					set_skill("sword", 250);
					set_skill("mingwang-jian", 250);

					map_skill("force", "longxiang-gong");
					map_skill("dodge", "shenkong-xing");
					map_skill("cuff", "yujiamu-quan");
					map_skill("hand", "dashou-yin");
					map_skill("parry", "riyue-lun");
					map_skill("sword", "xiangmo-chu");
					map_skill("hammer", "riyue-lun");

					prepare_skill("hand", "dashou-yin");
					prepare_skill("cuff", "yujiamu-quan");				


                     weapon = "yinlun";
                     break;
                case 8: // 星宿
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

                        weapon = "gangzhang";
                        break;
                case 9: //欧阳世家
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

                        weapon = "gangzhang";
                        break;
                case 10: //全真
					set_skill("force", 280);
					set_skill("quanzhen-xinfa", 280);
					set_skill("xiantian-gong", 280);
					set_skill("sword", 260);
					set_skill("quanzhen-jian",260);
					set_skill("dodge", 260);
					set_skill("jinyan-gong", 260);
					set_skill("parry", 280);
					set_skill("jinguan-yusuo", 280);
					set_skill("strike", 260);
					set_skill("chongyang-shenzhang", 260);
					set_skill("haotian-zhang", 260);
					set_skill("literate", 200);
					set_skill("finger", 260);
					set_skill("taoism", 300);
					set_skill("finger", 260);
					set_skill("zhongnan-zhi", 260);
					set_skill("sun-finger", 260);
					set_skill("medical", 280);
					set_skill("liandan-shu", 280);

					map_skill("force", "xiantian-gong");
					map_skill("sword", "quanzhen-jian");
					map_skill("dodge", "jinyan-gong");
					map_skill("parry", "jinguan-yusuo");
					map_skill("finger","sun-finger");
					map_skill("strike", "haotian-zhang");

					prepare_skill("finger", "sun-finger");
					prepare_skill("strike", "haotian-zhang");

                        weapon = "changjian";
                        break;
                case 11: //逍遥
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

                     weapon = "gangdao";
                        break;
                case 12: //血刀
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

                     weapon = "gangdao";
                        break;
				case 13: //明教
					set_skill("force", 1);
					set_skill("unarmed", 1);
					set_skill("dodge", 1);
					set_skill("parry", 1);
					set_skill("cuff", 1);
					set_skill("sword", 1);
					set_skill("blade", 1);
					set_skill("strike", 1);
					set_skill("claw", 1);
					set_skill("throwing", 1);
					// set_skill("duoming-jinhua", 450);
					set_skill("jiuyang-shengong", 1);
					set_skill("shenghuo-xinfa", 1);
					set_skill("shenghuo-shengong", 1);
					set_skill("lingxu-bu", 1);
					set_skill("shenghuo-bu", 1);
					set_skill("qingfu-shenfa", 1);
					set_skill("qiankun-danuoyi", 1);
					set_skill("qishang-quan", 1);
					set_skill("taiji-quan", 1);
					set_skill("taiji-jian", 1);
					set_skill("taiji-dao", 1);
					set_skill("lieyan-dao", 1);
					set_skill("liehuo-jian", 1);
					// set_skill("yingzhua-shou", 450);
					// set_skill("hanbing-mianzhang", 450);
					set_skill("shenghuo-ling", 1);
					set_skill("guangming-zhang", 1);
					set_skill("medical", 1);
					set_skill("literate", 1);
					set_skill("martial-cognize", 1);
					set_skill("guangming-jing", 1);

					map_skill("force", "jiuyang-shengong");
					map_skill("dodge", "qingfu-shenfa");
					map_skill("unarmed", "jiuyang-shengong");
					map_skill("strike","guangming-zhang");
					map_skill("cuff", "qishang-quan");
					map_skill("sword","shenghuo-ling");
					map_skill("parry","qiankun-danuoyi");
					map_skill("blade","taiji-dao");
					// map_skill("claw", "yingzhua-shou");
					// map_skill("throwing", "duoming-jinhua");
					// map_skill("strike", "hanbing-mianzhang");

					prepare_skill("cuff", "qishang-quan");
					
					weapon = "null";
					break;
				case 14: //峨眉
				
					set_skill("persuading", 1);
					set_skill("throwing", 1);
					set_skill("force", 1);
					set_skill("dodge", 1);
					set_skill("finger", 1);
					set_skill("parry", 1);
					set_skill("strike", 1);
					set_skill("sword", 1);
					set_skill("blade", 1);
					set_skill("literate", 1);
					set_skill("mahayana", 1);
					set_skill("buddhism", 1);
					set_skill("jinding-zhang", 1);
					set_skill("tiangang-zhi", 1);
					set_skill("huifeng-jian", 1);
					set_skill("yanxing-dao", 1);
					set_skill("zhutian-bu", 1);
					set_skill("emei-xinfa", 1);
					set_skill("linji-zhuang", 1);
					set_skill("piaoxue-zhang", 1);

					map_skill("force", "linji-zhuang");
					map_skill("finger", "tiangang-zhi");
					map_skill("dodge", "zhutian-bu");
					map_skill("strike", "piaoxue-zhang");
					map_skill("sword", "huifeng-jian");
					map_skill("blade", "yanxing-dao");
					map_skill("parry", "huifeng-jian");

					prepare_skill("strike", "piaoxue-zhang");
					prepare_skill("finger", "tiangang-zhi");
					
					weapon = "changjian";
					break;
				case 15: //关外胡家			
					set_skill("force", 1);	    // 基本内功
					set_skill("lengyue-shengong", 1); // 冷月神功
					set_skill("blade", 1);	    // 基本刀法
					set_skill("hujia-daofa", 1);      // 胡家刀法
					set_skill("dodge", 1);	    // 基本躲闪
					set_skill("taxue-wuhen", 1);      // 踏雪无痕
					set_skill("sixiang-bufa", 1);     // 四象步法
					set_skill("parry", 1);	    // 基本招架
					set_skill("throwing", 1);	 // 基本暗器
					set_skill("mantian-xing", 1);     // 满天星
					set_skill("strike", 1);	   // 基本掌法
					set_skill("tianchang-zhang", 1);  // 天长掌法
					set_skill("cuff", 1);	     // 基本拳法
					set_skill("hujia-quan", 1);       // 胡家拳法
					set_skill("daojian-guizhen", 1);       // 刀剑归真
					

					map_skill("force", "lengyue-shengong");
					map_skill("blade", "daojian-guizhen");
					map_skill("dodge", "sixiang-bufa");
					map_skill("parry", "hujia-daofa");
					map_skill("throwing", "mantian-xing");
					map_skill("strike", "tianchang-zhang");
					map_skill("cuff", "hujia-quan");

					prepare_skill("strike", "tianchang-zhang");
					prepare_skill("cuff",   "hujia-quan");
					
					weapon = "gangdao";
					break;	
				case 16: //慕容世家		
					set_skill("force", 1);
					set_skill("literate", 1);
					set_skill("unarmed", 1);
					set_skill("cuff", 1);
					set_skill("finger", 1);
					set_skill("strike", 1);
					set_skill("hand", 1);
					set_skill("claw", 1);
					set_skill("club", 1);
					set_skill("sword", 1);
					set_skill("blade", 1);
					set_skill("staff", 1);
					set_skill("dodge", 1);
					set_skill("parry", 1);

					// murong skill
					set_skill("zihui-xinfa", 1);
					set_skill("douzhuan-xingyi", 1);
					set_skill("beidou-xianzong", 1);
					set_skill("canhe-zhi", 1);
					set_skill("qixing-quan", 1);
					set_skill("murong-sword", 1);
					set_skill("martial-cognize", 1);

					map_skill("force", "zihui-xinfa");
					map_skill("dodge", "beidou-xianzong");
					map_skill("cuff",  "qixing-quan");
					map_skill("parry", "douzhuan-xingyi");
					map_skill("finger", "canhe-zhi");
					map_skill("sword", "murong-sword");

					prepare_skill("finger", "canhe-zhi");
					prepare_skill("cuff", "qixing-quan");
					
					weapon = "null";
					break;
				case 17: //段氏皇族
					set_skill("force", 1);
					set_skill("dodge", 1);
					set_skill("parry", 1);
					set_skill("cuff", 1);
					set_skill("strike", 1);
					set_skill("sword", 1);
					set_skill("staff", 1);
					set_skill("finger", 1);
					set_skill("duanshi-xinfa", 1);
					set_skill("tiannan-step", 1);
					set_skill("jinyu-quan", 1);
					set_skill("wuluo-zhang", 1);
					set_skill("duanjia-sword", 1);
					set_skill("sun-finger", 1);
					set_skill("literate", 1);

					map_skill("force", "duanshi-xinfa");
					map_skill("dodge", "tiannan-step");
					map_skill("finger", "sun-finger");
					map_skill("cuff", "jinyu-quan");
					map_skill("strike", "wuluo-zhang");
					map_skill("parry", "sun-finger");
					map_skill("sword", "duanjia-sword");
					map_skill("staff", "duanjia-sword");
					
					prepare_skill("cuff", "jinyu-quan");
					prepare_skill("strike", "wuluo-zhang");				
				
					weapon = "null";
					break;
				case 18: //日月神教
					set_skill("force", 1);
					set_skill("unarmed", 1);
					set_skill("dodge", 1);
					set_skill("parry", 1);
					set_skill("sword", 1);
					set_skill("blade", 1);
					set_skill("strike", 1);
					
					set_skill("riyue-xinfa", 1);
					set_skill("tianmo-zhang", 1);
					set_skill("tianmo-dao", 1);
					set_skill("tianmo-jian", 1);
					set_skill("tianmo-gun", 1);
					set_skill("xuwu-piaomiao", 1);
					set_skill("piaomiao-shenfa", 1);
					set_skill("xixing-dafa", 1);
					set_skill("literate", 1);

					map_skill("force", "riyue-xinfa");
					map_skill("sword", "tianmo-jian");
					map_skill("blade", "tianmo-dao");
					map_skill("strike", "tianmo-zhang");
					map_skill("parry", "tianmo-gun");
					map_skill("unarmed", "xuwu-piaomiao");
					map_skill("dodge", "piaomiao-shenfa");			
				
					weapon = "changjian";
					break;
				case 19: //昆仑派
					set_skill("force", 1);
					set_skill("kunlun-xinfa", 1);
					set_skill("liangyi-shengong", 1);
					set_skill("dodge", 1);
					set_skill("chuanyun-bu", 1);
					set_skill("hand", 1);
					set_skill("sanyin-shou", 1);
					set_skill("cuff", 1);
					set_skill("zhentian-quan", 1);
					set_skill("parry", 1);
					set_skill("sword", 1);
					set_skill("kunlun-jian", 1);
					set_skill("xunlei-jian", 1);
					set_skill("zhengliangyi-jian", 1);
					set_skill("throwing", 1);
					set_skill("kunlun-qifa", 1);
					set_skill("tanqin-jifa", 1);
					set_skill("tieqin-yin", 1);
					set_skill("literate", 1);
					set_skill("martial-cognize", 1);

					map_skill("force", "liangyi-shengong");
					map_skill("dodge", "chuanyun-bu");
					map_skill("parry", "zhengliangyi-jian");
					map_skill("sword", "kunlun-jian");
					map_skill("cuff", "zhentian-quan");
					map_skill("hand", "sanyin-shou");
					map_skill("throwing", "kunlun-qifa");
					map_skill("tanqin-jifa", "tieqin-yin");

					prepare_skill("strike", "kunlun-zhang");
					prepare_skill("cuff", "zhentian-quan");		
				
					weapon = "changjian";
					break;
				case 20://灵鹫宫
					set_skill("force", 270);
					set_skill("dodge", 240);
					set_skill("parry", 270);
					set_skill("hand",250);
					set_skill("strike", 250);
					set_skill("sword", 240);

					set_skill("zhemei-shou", 250);
					set_skill("liuyang-zhang", 250);
					set_skill("yueying-wubu", 240);
					set_skill("bahuang-gong", 270);
					set_skill("tianyu-qijian", 240);
					set_skill("lingjiu-xinfa", 120);
					
					set_skill("hunyuan-yiqi", 220);
					set_skill("zhougong-jian", 230);
					set_skill("feiyan-zoubi", 210);
	
					map_skill("force", "bahuang-gong");
					map_skill("strike","liuyang-zhang");
					map_skill("dodge", "yueying-wubu");
					map_skill("hand", "zhemei-shou");
					map_skill("parry", "liuyang-zhang");
					map_skill("sword", "tianyu-qijian");

					prepare_skill("hand", "zhemei-shou");
					prepare_skill("strike", "liuyang-zhang");
					
					weapon = "null";
					break;
                default: // others      BUG!!!
                    set("long","武功设置错误，BUG！！！");
        }
		
        set("weapon", weapon);
		
        if (weapon != "null"){
			if (weapon == "yinlun")
				carry_object("/d/xueshan/obj/yinlun")->wield();
			else
				carry_object("/clone/weapon/" + weapon)->wield();			
		}

        carry_object("/clone/cloth/cloth")->wear();
}

void create()
{
	set_name("弟子", ({ "menpai dz" }) );
	set("gender", "男性");
	set("long", "这是一个门派精英弟子，是馆长专门请来与各路英雄切磋武艺、研究武学的。\n");
    //set("title", HIR "(武学精英)" NOR);
	set("age",20);
	set("env/combatd",5);//数字化精简显示战斗信息
	
	set("combat_exp", 100);
	set("attitude", "aggressive");
	set("gain/2dp",100);
	set("str", 30);
	set("con", 30);
	set("dex", 30);
	set("int", 30);
	set("no_fly",1);
	//set("auto_perform",1);
	set("fusheng",1);
	set("canmiaosha",1);
	
	set_basic();
	setup();

	add_action("do_woht","woht");
	add_action("do_usebmd","usebmd");
}

void init()
{
	object me,kuilei;
	
	me = this_player();
	kuilei = this_object();
	
	add_action("do_miaosha","miaosha");	
	
	if (playerp(me) && query("zd")) {
		command("say 这位英雄领教了！\n");

		kill_ob(me);
		me->kill_ob(kuilei);
		call_out("autokill",3,me,kuilei);
	}
	
	::init();
}

void autokill(object me, object kuilei){
	
	if(playerp(me) && environment(me) == environment(kuilei)) kill_ob(me);//主动攻击加入循环，可防止玩家退出重进不攻击问题	
	call_out("autokill",3,me,kuilei);
}

void unconcious()
{
	if(query_temp("zhuren_id"))
		force_me("fusheng huanyuan");
	::unconcious();
	die();
}

varargs int receive_damage(string type, int damage, mixed who)
{
	string id;
	int sjdam;

	sjdam = ::receive_damage(type,damage,who);
	
	if(objectp(who) && sjdam > 0)
	{
		add("boss/"+who->query("id"),sjdam);	
		add("all_recive_damage",sjdam);	
	}
	
	return sjdam;
}

int get_damage(string id){
	return (int)query("boss/"+id);
}
int sort_damage(string user1,string user2)
{
	return get_damage(user2)-get_damage(user1);
}
void die()
{
	object ob;
	mapping boss;
	string *killer;
	int i,rs,zjinyan;
	float shbl,xs;
	
	if(! boss=query("boss")) return;
	
	if(query("miaosha")){
		message_vision(HIC"$N说到：功夫再高，也怕菜刀，俺先走一步。。。。。。\n"NOR, this_object());

		destruct(this_object());	
		return;
	}
	
	killer = keys(boss);	
	if(! sizeof(killer)) return;
	killer = sort_array(killer, (: sort_damage :) );
	if(! sizeof(killer)) return;	
	
	if(query("zd")){
		xs = query("xs")/100.0;
	}else{
		xs = query("xs")/200.0;
	}
	
	if(query("all_recive_damage") > query("max_qi")*2){
		zjinyan = to_int(xs*query("max_qi")*2.0/100.0);
	}else{
		zjinyan = to_int(xs*query("all_recive_damage")/100.0);
	}
	
	rs = sizeof(killer);
	if(rs == 1){
		if(objectp(ob=find_player(killer[0]))){
			ob->add("combat_exp",zjinyan);
			tell_object(ob,HIM"你战胜"+name()+"，从这次比试中你给对方造成了"+boss[killer[0]]+"点伤害，获得了"+zjinyan+"点实战经验。"NOR"\n");
		}
		
		message_vision(HIC"$N说到：非常不错，你进步很快，希望继续努力钻研，把中华武学发扬光大。\n"NOR, this_object());

		destruct(this_object());	
		return ;
	}
	
	if(rs > 1){
		if(boss[killer[0]]/boss[killer[rs-1]] > rs){
			shbl = rs * 1.0;
		}else{
			shbl = boss[killer[0]]/boss[killer[rs-1]];
		}
		
		zjinyan = to_int(zjinyan * rs / shbl);
		
		if(objectp(ob=find_player(killer[0]))){
			ob->add("combat_exp",zjinyan);
			//tell_object(ob,HIM"你战胜"+name()+"，从这次比试中你给对方造成了"+boss[killer[0]]+"点伤害，获得了"+zjinyan+"点实战经验。"NOR"\n");
			message_vision(HIY"第1名:"+ob->query("name")+"-->"+boss[killer[0]]+"伤害，获得"+zjinyan+"经验\n"NOR, this_object());
		}
		
		for(i=1; i<rs; i++){			
			if(objectp(ob=find_player(killer[i]))){
				zjinyan = zjinyan * to_float(boss[killer[i]]) / to_float(boss[killer[0]]);
				ob->add("combat_exp",zjinyan);
				//tell_object(ob,HIM"你战胜"+name()+"，从这次比试中你给对方造成了"+boss[killer[i]]+"点伤害，获得了"+zjinyan+"点实战经验。"NOR"\n");
				message_vision(HIY"第"+(i+1)+"名:"+ob->query("name")+"-->"+boss[killer[i]]+"伤害，获得"+zjinyan+"经验\n"NOR, this_object());
			}			
		}
	}
	
	message_vision(HIC"$N说到：非常不错，你进步很快，希望继续努力钻研，把中华武学发扬光大。\n"NOR, this_object());

	destruct(this_object());

} 
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
