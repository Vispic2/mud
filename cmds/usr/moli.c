#define ITME "/adm/daemons/itemtop"
#include <ansi.h>
inherit F_CLEAN_UP;
int max(int a,int b);
int main(object me, string arg)
{ 
mapping s;
string i,a;
int f,b;
int m;
string msg;
object *players;
players = users();

msg=HIY"\t\t\t\t\t\t\t\t\t\t\t[装备魔力排行榜]"+ZJBR+NOR;
for(b = 0; b<sizeof(players); b++)
{
m=mapp(players[b]->query("xq"));
if(!m!=1){
foreach(i in keys(players[b]->query("xq"))){
f=players[b]->query("xq/"+i+"");
msg+=""HIW"\t\t\t\t\t\t\t持有者名字："+HIG+players[b]->name()+NOR+HIW+" 装备魔力："+HIR+f+ZJBR+NOR;
  }
 }
}
write(ZJOBLONG+msg+"\n");
return 1;	 
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
