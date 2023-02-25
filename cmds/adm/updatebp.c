#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *zhudi_allroom,*all_bangpai,zhudi_room,bangpai;
	zhudi_allroom=list_dirs("/d/bangpai/map/");
		all_bangpai=list_dirs("/data/bangpai/");
		//复制有点操蛋
			foreach(zhudi_room in zhudi_allroom)
		{
		   foreach (bangpai in all_bangpai)
		   {
		 if (!write_file("/data/bangpai/"+bangpai+"/map/"+zhudi_room,read_file("/d/bangpai/map/"+zhudi_room),1))
			return notify_fail(bangpai+"的"+file_size("/d/bangpai/map/"+zhudi_room)+"号帮会驻地创建出错，建立失败，请联系管理员！\n"); 			
			tell_object(me,bangpai+"的"+zhudi_room+"成功导入...\n");
			"/cmds/wiz/update"->main(me,"/data/bangpai/"+bangpai+"/map/"+zhudi_room);
			}
    	}
			return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
