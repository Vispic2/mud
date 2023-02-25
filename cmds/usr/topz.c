#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        object *list,*ob;
        int i;
        string msg;

        ob = filter_array(children(USER_OB),(: userp($1) :));
        list = sort_array(ob, (: top_list :));


      msg =  "\n            ┏ "+BCYN HIR+MUD_NAME+"在线高手排行榜"NOR" ┓\n"HIG;
      msg += "┏━━━━━━━━━━━━━━━━━━━━━━┓\n";
      msg += "┃ 名次 │    高     手      │ 门  派 │ 得  分    \n";
      msg += "┠──────────────────────│\n";
      for (i = 0 ;i < 15 ; i++){
      if( i >= sizeof(list)) {  
      msg += HIG+"┃暂时空缺。 "NOR"\n";
      }else{
     if(list[i] == me){
     msg +=BCYN;
     }else{
     msg +=HIG;
     }
     msg += sprintf("┃  %-5s %-22s%-10s %5d   "NOR"\n",chinese_number(i+1),list[i]->query("name")+"("+capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"普通百姓",get_score(list[i]));
     }
    }
     msg += HIG+"┗━━━━━━━━━━━━━━━━━━━━━━┛"NOR"\n";   
     msg +=  "            ┏ "+BCYN HIC+MUD_NAME+":你现在的评价如下："NOR" ┓\n"+HIC;
     msg += "┏━━━━━━━━━━━━━━━━━━━━━━┓\n";
     for (i = 0 ;i < 1 ; i++){
     if( i >= sizeof(list)){
     msg += HIC+"暂时空缺。 \n";
     }else{
     if(list[i] == me){
     msg +=HIR;
     }else{
     msg +=HIC;
     }
     msg += sprintf("┃  %-5s %-22s%-10s %5d   "NOR"\n",chinese_number(i+1),me->query("name")+"("+capitalize(me->query("id"))+")", me->query("family")?  me->query("family/family_name"):"普通百姓",get_score(me));
     }
     }
     msg += HIC+"┗━━━━━━━━━━━━━━━━━━━━━━┛\n";
     msg += HIG+"  " + NATURE_D->game_time() + "记。\n"+NOR;
 	 msg = replace_string(msg,"\n",ZJBR)+"\n";
	 write(ZJOBLONG+msg+"\n");
     return 1;

}
int top_list(object ob1, object ob2)
{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);

      return score2 - score1;
}
int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;
        object me=this_player();
        reset_eval_cost();
        skills = ob->query_skills();
        if (!sizeof(skills))
        return 1;
        ski  = keys(skills);
        for(i = 0; i<sizeof(ski); i++){
        tlvl += skills[ski[i]];
        }
        score = tlvl;        
        score += ob->query("max_neili")/1;
        score += ob->query("max_qi")/1;
        score += ob->query("max_jingli")/1;    
        score += ob->query("str") + ob->query("int") + ob->query("dex") + ob->query("con")*100;
        score += (int)ob->query("combat_exp")/1000;
    
        return score;
}
int help(object me)
{
write(@HELP
指令格式 : top
这个指令可以让你知道在线十大高手是哪些，别去惹他们。
HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
