// Room: /city3/tidufu.c
// Date: Feb.14 1998
inherit ROOM;

void create()
{
	set("short", "提督府");
	set("long", @LONG
这里便是提督大人办公事的地方。正前方 (front)大红楠木案桌
后正经端坐着的，就是成都提督吴天德。两边站立纹风不动的是他的
亲兵侍从，看上去都十分彪悍。
LONG );
	set("exits", ([ /* sizeof() == 1 */
	    "south" : __DIR__"tidugate",
	]));
	set("objects", ([ /* sizeof() == 1 */
	     __DIR__"npc/wutiande" : 1,
	     __DIR__"npc/shicong"  : 2,
	     __DIR__"npc/qinbing" : 4,
	]));
	set("item_desc",([
	    "front" : "
		###########################
		#			 #
		#    民   安   境   靖    #
		#			 #
		###########################
			    !~A~!
		      @~~~~~!(O)!~~~~~@
			   (.@ @.)
			    . ~ .
			 /   ~.你奶奶的...你这刁民...还瞧甚麽? 不认得老爷麽? ...
			#	   #
	     HHHH     #	       #
	     HHHH   #    n	 n    #
	  |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
	   ```````````````````````````````````````
		  ()		      ()
		 ()			()
		()			  ()
	       ()			    ()\n"
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
