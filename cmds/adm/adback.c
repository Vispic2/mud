//adback

#include <net/daemons.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
        string src, src_l, dst, dst_l;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
                return notify_fail("只有 (admin) 以上的巫师才能手动备份" + MUD_NAME + "\n");

        message( "system", HIW"\n游戏手动备份启动，请稍候。\n"NOR, users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
                if( !environment(user[i]) || !objectp(user[i]) ) continue;
                src = (string)user[i]->query_save_file();
                dst = src + ".a.o";  // 与玩家自己的备份文件(.oo.o)区分开
               if( user[i]->save() ) cp(src + ".o", dst);
		link_ob = user[i]->query_temp("link_ob");
                src_l = (string)link_ob->query_save_file();
                dst_l = src_l + ".a.o";
                if( objectp(link_ob) ) { if ( link_ob->save() ) cp(src_l + ".o", dst_l);}
	}


        message( "system", HIW"游戏手动备份完毕，请继续挖泥巴。\n"NOR, users() );
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: adback
 
马上备份玩家数据。
 
HELP
);
        return 1;
}
 
