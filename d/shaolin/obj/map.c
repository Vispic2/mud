#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "『少林旅游图』" NOR, ({ "luyou tu", "tu" }) );
	set_weight(10);
	set("icon","00919");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",
"\n		 『少林旅游图』\n\n"
"+----------------------+-----------------------+-----------------------+\n"
"|		      |		       |		       |\n"
"+------------+	 |	千佛殿	 |	  +------------+\n"
"|	    |	 |		       |	  |	    |\n"
"|  地藏殿    O	 +----------OO-----------+	  O  白衣殿    |\n"
"|	    |		   ====		     |	    |\n"
"+------------+		   广场		     +------------+\n"
"|			    +----OO----+			      |\n"
"|			    |	  |			      |\n"
"|			    |  达摩院 ?|			      |\n"
"|			    |	  |			      |\n"
"+------------+---------------+----OO----+-----------------+------------+\n"
"|############|###################====#####################|############|\n"
"|      竹-6  O    和-6    |		  |    和-3     O  竹-3     |\n"
"|	    |     ;      |		  |       ;     |	   |\n"
"+------+..o..+------O-----+		  +------O------+..o..+-----|\n"
"|  藏  |     |	    |		  |	     |    |  武  |\n"
"|  经  O林-5 O    尚-5    |     武   场      |      尚-2  O林-2 X  器  |\n"
"|  楼? |     |     ;      |	 (1)      |       ;     |    |  库  |\n"
"+------+..o..+-----O------+		  +------O------+.o..+------|\n"
"|	    |	    |		  |	     |	   |\n"
"|      竹-4  O    院-4    O		  O      院-1   O  竹-1     |\n"
"|	    |	    |		  |	     |	   |\n"
"+----O-------+------O-----+-------OO---------+------O------+-----O-----+\n"
"|	    |	    |		  |	     |	   |\n"
"|  走廊-5    O   走廊-6   O     方丈室  ?    O    走廊-7   O   走廊-8  |\n"
"|	    |	    |		  |	     |	   |\n"
"+----O-------+------------+-------OO---------+-------------+-----O-----+\n"
"|###===######|###################====######################|####===####|\n"
"|  般若-9    |					     |   罗汉-9  |\n"
"+----O-------+					     +-----O-----+\n"
"|  般若-8    |					     |   罗汉-8  |\n"
"+----O-------+					     +-----O-----+\n"
"|  般若-7    |					     |   罗汉-7  |\n"
"+----O-------+					     +-----O-----+\n"
"|  般若-6    |					     |   罗汉-6  |\n"
"+----O-------+					     +-----O-----+\n"
"|  般若-5    O	   练       武	场	     O   罗汉-5  |\n"
"+----O-------+					     +----O------+\n"
"|  般若-4    |					     |   罗汉-4  |\n"
"+----O-------+					     +-----O-----+\n"
"|  般若-3    |					     |   罗汉-3  |\n"
"+----O-------+					     +-----O-----+\n"
"|  般若-2    |					     |   罗汉-2  |\n"
"+----O-------+					     +-----O-----+\n"
"|  般若-1    |					     |   罗汉-1  |\n"
"+----O-------+-------------+-----------------+-------------+-----O-----+\n"
"|	    |	     |		 |	     |	   |\n"
"|  走廊-1    O    走廊-2   O    后    殿     O    走廊-3   O   走廊-4  |\n"
"|	    |	     |		 |	     |	   |\n"
"+------------+-------------+-------OO--------+-------------+-----------+\n"
"|############|####################====#################################|\n"
"				  ｜｜（通往后殿)\n"
"				  ｜｜\n"
"+------------+----------+---------O??O--------------------+-----------+\n"
"|############|####################====####################|###########|\n"
"|   厨房     |							|\n"
"|	    |		    广场-4			      |\n"
"|-----O------+------O---+-----------------------+----------------#----+\n"
"|	    |	  |		       |		     |\n"
"|   饭厅-2   |	  |      戒  律  院       |		     |\n"
"|	    |	  |		       |		     |\n"
"|-----O------+	  +---------O??O----------+		     |\n"
"|	    |		    ====				|\n"
"|   饭厅-1   O							|\n"
"|	    |		    广场-3			      |\n"
"|------------+	  +-----------------------+		     |\n"
"|		       |		       |		     |\n"
"|		       |	大雄宝殿       |		     |\n"
"|		       |		       |		     |\n"
"|-----------------------+---------O??O----------+---------------------|\n"
"|				 ====				|\n"
"|				 广场-2			      |\n"
"+---------+------------+			+---------------X-----+\n"
"|	 |	    |			|	   |	 |\n"
"|  鼓楼   O||  小院    O			O  小院   ||O  钟楼   |\n"
"|	 |	    |			|	   |	 |\n"
"+---------+  +---------+-----------OO-----------+-----------+  +------+\n"
"|	 |	     |		       |	   |	 |\n"
"|	 |    侧殿     O	天王殿	 O    侧殿   |	 |\n"
"|	 |	     |		       |	   |	 |\n"
"+---------+-------------+----------OO-----------+---------------------+\n"
"|#######################|#########====##########|#####################|\n"
"|		       |		       |		     |\n"
"|  I      i    碑林     O    碑	  林     O     碑林   i     I i|\n"
"|		       |		       |		     |\n"
"|       i    +----------+----------OO-----------+--------+   i	|\n"
"|	    |	  |		       |	|	    |\n"
"|  i	 |  侧殿    O	山门殿	 O  侧殿  |	 i  |\n"
"|	    |	  |		       |	|	    |\n"
"+==================================X?X================================+\n"
"|#######################|#########====##########|#####################|\n"
"	     |	  |		       |	     |\n"
"	     |	  |		       |	     |\n"
"	松林 O 石坊     O	寺前广场-1     O   石坊      O  松林\n"
"	     |	  |		       |	     |\n"
"	     |	  |		       |	     |\n"
"	     +----------+----------OO-----------+-------------+\n"
"注：?    检查站	 |	 ====	  |\n"
"    ##   高墙	   |		       |\n"
"    ==   台阶	   |	 石阶	  |\n"
"    O    开放	   |==========OO===========|\n"
"    X    关着的门\n");
		set("value", 50);
		set("material", "paper");
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
