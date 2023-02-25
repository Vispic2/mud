
//#include <fb_copy.h>
#include "/d/fuben/npc/fb_copy.h"

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
void set_martial()
{
        string weapon = "null";
        switch(random(13))
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

                     set("chat_chance_combat", 80);
                     set("chat_msg_combat", ({
                          (: exert_function, "powerup" :),
                          (: perform_action, "sword.lian" :),
                          (: perform_action, "sword.chan" :),
                          (: perform_action, "sword.sui" :),
                          (: perform_action, "unarmed.zhen" :),
                          (: exert_function, "recover" :),
                     }) );
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
                        weapon = "changjian";
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

                     set("chat_chance_combat", 80);
                     set("chat_msg_combat", ({
                          (: perform_action, "strike.hua" :),
                          (: perform_action, "hand.xian" :),
                          (: exert_function, "powerup" :),
                          (: exert_function, "recover" :),
                     }));

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

                     set("chat_chance_combat", 80);
                     set("chat_msg_combat", ({
                          (: exert_function, "powerup" :),
                          (: exert_function, "recover" :),
                          (: perform_action, "staff.chan" :),
                          (: perform_action, "staff.ban" :),
                     }) );
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

                     set("chat_chance_combat", 80);
                     set("chat_msg_combat", ({
                          (: exert_function, "powerup" :),
                          (: perform_action, "sword.qing" :),
                          (: perform_action, "sword.tianwai" :),
                          (: perform_action, "hand.fuxue" :),
                          (: perform_action, "finger.jinglei" :),
                          (: exert_function, "recover" :),
                     }) );
                        weapon = "changjian";
                        break;
                case 6: //古墓
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

                        weapon = "changjian";
                        break;
                case 7: //雪山寺
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

                     set("chat_chance_combat", 100);
                     set("chat_msg_combat", ({
                          (: perform_action, "staff.chan" :),
                          (: perform_action, "staff.qianshe" :),
                          (: perform_action, "staff.wuji" :),
                          (: perform_action, "cuff.rou" :),
                          (: exert_function, "powerup" :),
                          (: exert_function, "recover" :),
                     }) );
                        weapon = "gangzhang";
                        break;
                case 10: //全真
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

                     set("class", "taoist");

                     set("chat_chance_combat", 80);
                     set("chat_msg_combat", ({
                          (: perform_action, "blade.ruyi" :),
                          (: perform_action, "hand.jiubu" :),
                          (: perform_action, "strike.jiutian" :),
                          (: exert_function, "recover" :),
                          (: exert_function, "powerup" :),
                     }));
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

                     set("chat_chance_combat", 80);
                     set("chat_msg_combat", ({
                          (: perform_action, "blade.shendao" :),
                          (: perform_action, "blade.xueyu" :),
                          (: perform_action, "hand.jingang" :),
                          (: perform_action, "cuff.chen" :),
                          (: exert_function, "powerup" :),
                          (: exert_function, "recover" :),
                     }));
                     weapon = "gangdao";
                        break;
                default: // others      BUG!!!
                        set("long","武功设置错误，BUG！！！");
        }
        set("weapon", weapon);
        if (weapon != "null")
        if (weapon == "yinlun")
                carry_object("/d/xueshan/obj/yinlun")->wield();
        else
                carry_object("/clone/weapon/" + weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void check_fight()
{
        object ob = this_object();
        string weapon;

        weapon = ob->query("weapon");
        if (stringp(weapon) && weapon != "null" && !ob->query_temp("weapon"))
        {
                message_vision("$N又拿出一把兵器握在手中。\n", ob);
                if (weapon == "yinlun")
                        carry_object("/d/xueshan/obj/yinlun")->wield();
                else
                        carry_object("/clone/weapon/" + weapon)->wield();
        }
        call_out("check_fight", 1);
}

void do_clone(object me, int lvl)
{
        set_martial();
        do_copy_player(me, this_object(), lvl);
        set_temp("do_clone", 1);
}
