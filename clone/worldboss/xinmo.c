// cui.c 崔员外

inherit NPC;

void create()
{
	set_name("心魔", ({ "xin mo", "mo" }));
	set("gender", "男性");
	set("age", 55);

	set("max_qi",500);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);

	set("combat_exp", 25000);
	set("shen_type", -1);
	setup();
	add_money("silver", 5);
	carry_object("/clone/misc/cloth")->wear();
}
	
void die()
{
        object nvh;
         object ob;
            object *players,wp;
         int w,x,i;         
       //  if(!ob) return;

        if (objectp(ob = query_last_damage_from()))
	{
	        ob->start_busy(1);
        if (!sizeof(players = ob->query_team()))
        {
        wp = new("/clone/vip/jinsha");
        wp->set_amount(5);
        wp->move(ob);        
        tell_object(ob,HIR"你击败了心魔，赢得5个金砂.\n"NOR); 
        }
        else
        {        
       for(i = 0; i<sizeof(players); i++)
         {
        wp = new("/clone/vip/jinsha");
         wp->set_amount(2);
        wp->move(players[i]);       
       tell_object(players[i],HIR"由于你与队友配合击败了心魔，赢得2个金砂.\n"NOR); 
       }
       }
       }
  //          message("channel:chat",HBYEL"【江湖百晓生】"HIR"："+ob->query("name")+"神功盖世，击杀了"+name()+"，事迹震惊江湖，在线共计"+w+"名玩家瞻仰！\n"NOR,users());
       ::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
