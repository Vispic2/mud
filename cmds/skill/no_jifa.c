#include <ansi.h>
inherit F_CLEAN_UP;

#include <net/httpd.h>
#include <net/socket.h>
nosave int fd;
int main(object me, string arg)
{
    mapping valid_types = ([
	"unarmed":      "拳脚",
	"sword":	"剑法",
	"blade":	"刀法",
	"staff":	"杖法",
	"hammer":       "锤法",
	"club" :	"棍法",
	"throwing":     "暗器",
	"force":	"内功",
	"xinfa":	"心法",
	"parry":	"招架",
	"dodge":	"轻功",
	"magic":	"法术",
	"whip":	 	"鞭法",
	"dagger":       "短兵",
	"finger":       "指法",
	"hand":	 	"手法",
	"cuff":	 	"拳法",
	"claw":	 	"爪法",
	"strike":       "掌法",
	"medical":      "医术",
	"poison":       "毒技",
	"cooking":      "厨艺",
	"chuixiao-jifa" : "吹萧",
	"guzheng-jifa"  : "古筝",
	"tanqin-jifa"   : "弹琴",
]);
    string *skill=keys(valid_types);
    string name;
    foreach (name in skill)
	{
	me->force_me("jifa "+name+" none");				
	}		
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
