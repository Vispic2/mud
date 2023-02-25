//qing yunzi-yushu 2001.2.
#include <ansi.h>
#include "shushan.h"
inherit NPC;
void create()
{
       set_name("轻云子", ({"qing yunzi", "yunzi", "zi"}));
       set("title", "蜀山派第三代弟子");   
       set("gender", "女性");
       set("age", 32);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 40);
       set("con", 30);
       set("combat_exp", 500000);
       set("max_qi", 1000);
       set("max_jing", 1000);
       set("neili", 3600);
       set("max_neili", 1800);
       set("jiali", 90);
        set("max_jingli", 500);
        set("jingli", 500);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 500);
	set_skill("shushan-force", 150);
	set_skill("yujianshu", 140);
       set_skill("dodge", 160);
       set_skill("literate", 100);
       set_skill("sword", 140);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("zuixian-steps", 160);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "shushan-force");
       create_family("蜀山派", 3, "弟子");
       setup();
        carry_object("/clone/cloth/cloth")->wear();
      carry_object("/clone/weapon/changjian")->wield();
//       carry_object("d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="蜀山派" )
	{

		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
			else command("say 师姑见笑了。\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
			else command("say 师妹太客气了。\n");
		}
		else 
		{
			command("consider");
			command("say 是你自己要拜的，可别怪我啊!。\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say 好，我蜀山派一门人才辈出，你可得给师父争气。\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山派第四代弟子");
                       }
              return 0;
}


