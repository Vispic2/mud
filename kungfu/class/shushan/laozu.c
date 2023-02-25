//【蜀山派】mhxy-yushu 2001/2
#include <ansi.h>
#include "shushan.h"
inherit NPC;
inherit F_MASTER;
int ask_back();
#define BHUOZHU       "/d/shushan/zhenyaota/obj/huozhu"
void create()
{
       set_name(HIW "静虚老祖" NOR, ({"master jingxu","jingxu", "master"}));
       set("title",HIC"蜀山派开山祖师"NOR);
       set("gender", "男性");
       set("age", 220);
	set("class", "xiake");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
	set("long", "他玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。\n");
	set("int", 30);
       set("max_qi", 500000);
       set("max_jing", 50000);
       set("neili", 500000);
       set("max_neili", 25000);
   set("neili", 20000000);
       set("jiali", 1500);
       set("max_mana", 250000);
       set("mana", 250000);
       set("combat_exp", 300000000);
       set_skill("literate", 2000);
       set_skill("dodge", 2000);
       set_skill("parry", 2000);
       set_skill("unarmed", 2000);
        set_skill("fumozhang", 2000); 
        set_skill("songhe-sword", 2000);
        set_skill("spells", 2000);
        set_skill("xianfeng-spells", 2000);
       set_skill("yujianshu", 2000);
       set_skill("shushan-force", 2000);
	set_skill("sword", 2000);
	set_skill("force", 2000);
     set_skill("zuixian-steps", 2000);
      map_skill("spells", "xianfeng-spells");
       map_skill("force", "shushan-force");
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 10);
       set("chat_msg_combat", ({
	  (: perform_action, "sword." :),
                (: perform_action, "sword." :),
        }) );
        set("inquiry", ([
         "回去" : (: ask_back :),
	  "万剑决" : "如果你能帮我找到火灵珠我就教你！\n",
         ]) );
        create_family("蜀山派", 1, "弟子");
        setup();

       carry_object("/clone/cloth/cloth")->wear();
carry_object("/d/shushan/obj/qixing")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
       if( (string)ob->query("family/family_name")=="蜀山派") {
        if ((int)ob->query("combat_exp") < 300000000 ) {
  	command("say 你的exp还不够，对我的招法难以领悟。\n");
	return;
	}
 if( (int)ob->query_skill("zuixian-steps", 1) < 1000 ) {
command("say 这位" + RANK_D->query_respect(ob) + "你的醉仙望月步还不到火候,你还是找剑圣他们练着吧!\n")
;
	command("sigh");
	return;
	}
       if( (int)ob->query_skill("force", 1) < 1000 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "你的基本内功还不到火候,你还是找剑圣他们练着吧!\n");
	command("sigh");
	return;
	}
       if( (int)ob->query_skill("sword", 1) < 1000 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "你的基本剑法还不到火候,你还是找剑圣他们练着吧!\n");
	command("sigh");
	return;
	}
       command("smile");
       command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
       command("recruit " + ob->query("id") );
       return;
	}
       command("shake");
       command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山静虚老祖传人");

}

        return 0;
}
int ask_back()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "蜀山派")
    {
    command("say 你又不是蜀山派的，你问这个干吗！");
    return 1;
    }
    if(ob->query("shushan/tuoqiao_cast"))
    { 
    command("say 你不是知道了吗? ");
    return 1;
    }
    if(ob->query("family/master_name") == "静虚老祖" )
    {
    command("say 你想出去啊！好吧!我教你一招「金蝉脱壳」!");
    command("say 用(cast tuoqiao)就能出去!");
    command("say 下次进来时就不要那么麻烦了,去藏经阁(push 书架)就可以了。");
    ob->set("shushan/tuoqiao_cast",1);
    return 1;
    }
}


int accept_object(object me, object obj)
{
object huozhu;
if(base_name(obj)!=BHUOZHU)
{
                command("say 我要的是火灵珠!其他的我没兴趣。\n");
                return 0;
}
	me->set("shushan/wanjian_perform", 1);
	command("say 看在你那么有心的份上，我就教你「万剑决」。\n");
destruct(obj);
return 1;

}

