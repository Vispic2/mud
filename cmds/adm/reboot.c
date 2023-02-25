//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// reboot.c

#include <login.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string wiz_status;
   object npc;

   if( me != this_player(1) ) return 0;
   
   wiz_status = SECURITY_D->get_status(me);
   if( wiz_status != "(admin)")
     return notify_fail("只有(admin)权限者才能重新启动" + MUD_NAME + "\n");

   seteuid(getuid());

   npc = new(NPC_DEMOGORGON);
   npc->move(START_ROOM);
   npc->start_shutdown();

   write("Ok。\n");

   return 1;
}

int help (object me)
{
        write(@HELP
指令格式: reboot
 
重新起动游戏, 系统会开始倒数计时, 十五分钟后重新起动。
 
HELP
);
        return 1;
}
 
