// 宝箱

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
string *box_object=({
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"clone/good/1/d1_arrmor",
"clone/good/1/d1_boots",
"clone/good/1/d1_cloth",
"clone/good/1/d1_finger",
"clone/good/1/d1_hands",
"clone/good/1/d1_head",
"clone/good/1/d1_neck",
"clone/good/1/d1_pants",
"clone/good/1/d1_shield",
"clone/good/1/d1_surcoat",
"clone/good/1/d1_waist",
"clone/good/1/d1_wrists",
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"item/20",
"item/21",
"item/22",
"item/23",
"item/24",
"item/25",
"item/26",
"item/27",
"item/28",
"item/29",
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"item/20",
"item/21",
"item/22",
"item/23",
"item/24",
"item/25",
"item/26",
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"item/20",
"item/21",
"item/22",
"item/23",
"item/24",
"item/25",
"item/26",
"item/51",
"item/52",
"item/53",
"item/54",
"item/55",
"item/56",
"item/57",
"item/58",
"item/59",
"item/60",
"item/61",
"item/62",
"item/63",
"item/64",
"item/65",
"item/66",
"item/67",
"item/68",
"item/69",
"item/70",
"item/71",
"item/72",
"item/73",
"item/74",
"item/75",
"item/76",
"item/77",
"item/78",
"item/79",
"item/80",
"item/81",
"item/82",
"item/83",
"item/84",
"item/85",
"item/86",
"item/87",
"item/88",
"item/89",
"item/90",
"item/91",
"item/92",
"item/93",
"item/94",
"item/95",
"item/96",
"item/97",
"item/98",
"item/99",
"item/100",
"item/101",
"item/102",
"item/103",
"item/104",
"item/105",
"item/106",
"item/107",
"item/108",
"item/109",
"item/110",
"item/111",
"item/112",
"item/113",
"item/114",
"item/115",
"item/116",
"item/117",
"item/118",
"item/119",
"item/120",
"item/121",
"item/122",
"item/123",
"item/124",
"item/125",
"item/126",
"item/127",
"item/128",
"item/129",
"item/130",
"item/131",
"item/132",
"item/133",
"item/134",
"item/135",
"item/136",
"item/137",
"item/138",
"item/139",
"item/140",
"item/141",
"item/142",
"item/143",
"item/144",
"item/145",
"item/146",
"item/100",
"item/101",
"item/102",
"item/103",
"item/104",
"item/105",
"item/106",
"item/107",
"item/108",
"item/109",
"item/110",
"item/111",
"item/112",
"item/113",
"item/114",
"item/115",
"item/116",
"item/117",
"item/118",
"item/119",
"item/120",
"item/121",
"item/122",
"item/123",
"item/124",
"item/125",
"item/126",
"item/127",
"item/128",
"item/129",
"item/130",
"item/131",
"item/132",
"item/133",
"item/134",
"item/135",
"item/136",
"item/137",
"item/138",
"item/139",
"item/140",
"item/141",
"item/142",
"item/143",
"item/144",
"item/145",
"item/146",
"item/136",
"item/137",
"item/138",
"item/139",
"item/140",
"item/141",
"item/142",
"item/143",
"item/144",
"item/145",
"item/146",
});

string *w_object=({
"new/ar1",
"new/ar10",
"new/ar11",
"new/ar12",
"new/ar13",
"new/ar14",
"new/ar15",
"new/ar16",
"new/ar17",
"new/ar18",
"new/ar2",
"new/ar3",
"new/ar4",
"new/ar5",
"new/ar6",
"new/ar7",
"new/ar8",
"new/ar9",
"new/ar2",
"new/ar3",
"new/ar4",
"new/ar5",
"new/ar6",
"new/ar7",
"new/ar8",
"new/ar9",
"new/ar2",
"new/ar3",
"new/ar4",
"new/ar5",
"new/ar6",
"new/ar7",
"new/ar8",
"new/ar9",
"new/bt1",
"new/bt10",
"new/bt11",
"new/bt12",
"new/bt13",
"new/bt14",
"new/bt15",
"new/bt16",
"new/bt17",
"new/bt18",
"new/bt2",
"new/bt3",
"new/bt4",
"new/bt5",
"new/bt6",
"new/bt7",
"new/bt8",
"new/bt9",
"new/h1",
"new/h10",
"new/h11",
"new/h12",
"new/h13",
"new/h14",
"new/h15",
"new/h16",
"new/h2",
"new/h3",
"new/h4",
"new/h5",
"new/h6",
"new/h7",
"new/h8",
"new/h9",
"new/h2",
"new/h3",
"new/h4",
"new/h5",
"new/h6",
"new/h7",
"new/h8",
"new/h9",
"new/hd1",
"new/hd10",
"new/hd11",
"new/hd12",
"new/hd13",
"new/hd14",
"new/hd15",
"new/hd16",
"new/hd17",
"new/hd18",
"new/hd2",
"new/hd3",
"new/hd4",
"new/hd5",
"new/hd6",
"new/hd7",
"new/hd8",
"new/hd9",
"new/nk1",
"new/nk10",
"new/nk11",
"new/nk12",
"new/nk13",
"new/nk14",
"new/nk15",
"new/nk16",
"new/nk17",
"new/nk18",
"new/nk2",
"new/nk3",
"new/nk4",
"new/nk5",
"new/nk6",
"new/nk7",
"new/nk8",
"new/nk9",
"new/sc1",
"new/sc10",
"new/sc11",
"new/sc12",
"new/sc13",
"new/sc14",
"new/sc15",
"new/sc16",
"new/sc17",
"new/sc18",
"new/sc2",
"new/sc3",
"new/sc4",
"new/sc5",
"new/sc6",
"new/sc7",
"new/sc8",
"new/sc9",
"new/sc2",
"new/sc3",
"new/sc4",
"new/sc5",
"new/sc6",
"new/sc7",
"new/sc8",
"new/sc9",
"new/sd1",
"new/sd10",
"new/sd11",
"new/sd12",
"new/sd13",
"new/sd14",
"new/sd15",
"new/sd16",
"new/sd17",
"new/sd18",
"new/sd2",
"new/sd3",
"new/sd4",
"new/sd5",
"new/sd6",
"new/sd7",
"new/sd8",
"new/sd9",
"new/wi1",
"new/wi10",
"new/wi11",
"new/wi12",
"new/wi13",
"new/wi14",
"new/wi15",
"new/wi16",
"new/wi17",
"new/wi18",
"new/wi2",
"new/wi3",
"new/wi4",
"new/wi5",
"new/wi6",
"new/wi7",
"new/wi8",
"new/wi9",
"new/wt1",
"new/wi2",
"new/wi3",
"new/wi4",
"new/wi5",
"new/wi6",
"new/wi7",
"new/wi8",
"new/wi9",
"new/wt10",
"new/wt11",
"new/wt12",
"new/wt13",
"new/wt14",
"new/wt15",
"new/wt16",
"new/wt17",
"new/wt18",
"new/wt2",
"new/wt3",
"new/wt4",
"new/wt5",
"new/wt6",
"new/wt7",
"new/wt8",
"new/wt9",
"baowu/01",
"baowu/02",
"baowu/03",
"baowu/04",
"baowu/05",
"baowu/06",
"baowu/07",
"baowu/08",
"baowu/09",
"baowu/10",
"baowu/11",
"baowu/12",
"baowu/13",
"baowu/14",
"baowu/15",
"baowu/16",
"baowu/17",
"baowu/18",
"baowu/19",
"baowu/20",
"baowu/21",
"baowu/22",
"baowu/23",
"baowu/24",
"baowu/25",
"baowu/26",
"baowu/27",
"baowu/28",
"baowu/29",
"baowu/30",
"baowu/31",
"baowu/32",
"baowu/33",
"baowu/34",
"baowu/35",
"baowu/36",
"baowu/37",
"baowu/38",
"baowu/39",
"baowu/40",
"baowu/41",
"baowu/42",
"baowu/43",
"baowu/44",
"baowu/45",
"baowu/46",
"baowu/47",
"baowu/48",
"baowu/49",
"baowu/50",
"baowu/51",
"baowu/52",
"baowu/53",
"baowu/54",
"baowu/55",
"baowu/56",
"baowu/57",
"baowu/58",
"baowu/59",
"baowu/60",
"baowu/61",
"baowu/62",
"baowu/63",
"baowu/64",
"new2/0",
"new2/1",
"new2/2",
"new2/3",
"new2/4",
"new2/5",
"new2/0",
"new2/1",
"new2/2",
"new2/3",
"new2/4",
"new2/5",
"new2/6",
"new2/7",
"new2/8",
"new2/9",
"new2/10",
"new2/11",
"new2/12",
"new2/13",
"new2/14",
"new2/15",
"new2/16",
"new2/17",
"new2/18",
"new2/19",
"new2/20",
"new2/10",
"new2/11",
"new2/12",
"new2/13",
"new2/14",
"new2/15",
"new2/16",
"new2/17",
"new2/18",
"new2/19",
"new2/20",
"new2/21",
"new2/22",
"new2/23",
"new2/24",
"new2/25",
"new2/26",
"new2/27",
"new2/28",
"new2/29",
"new2/30",
"new2/31",
"new2/32",
"new2/33",
"new2/34",
"new2/35",
"new2/36",
"new2/37",
"new2/38",
"new2/39",
"new2/40",
"new2/41",
"new2/42",
"new2/43",
"new2/44",
"new2/45",
"new2/46",
"new2/47",
"new2/48",
"new2/49",
"new2/50",
"new2/51",
"new2/52",
"new2/53",
"new2/54",
"new2/55",
"new2/56",
"new2/57",
"new2/58",
"new2/59",
"new2/60",
"new2/61",
"new2/62",
"new2/63",
"new2/64",
"new2/65",
"new2/66",
});

void create()
{
	set_name(HIG"宝箱"NOR, ({"bao xiang", "bao", "xiang"}));
        set("no_get",1);
	set("vendetta/authority",1);
	set_weight(100000);
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用红木制作而成的"+HIG"宝箱，"NOR+"似乎可以"ZJURL("cmds:openbox")ZJSIZE(15)""HIW"打开""\n");
		set("unit", "个");
		set("value", 0);
	}
}


void init()
{
   add_action("do_open","openbox");
}



int do_open(string arg)
{
object env,envt;
mapping exit;
object me=this_player(),ob,corpse,obj;
int maxpot;
env = environment(me);
/*
if( mapp(exit = env->query("exits"))
&& !env->query("no_npc"))
{
if( mapp(exit = env->query("exits")) && !undefinedp(exit["west"]) )
env->set_temp("exite",env->query("exits/east"));
env->set_temp("exitw",env->query("exits/west"));
env->set("exits/east", env->query_temp("exitw"));
env->set("exits/west", env->query_temp("exite"));
if (random(3)==0  && undefinedp(exit["south"]))
{
env->delete("exits/west");
env->set("exits/south", env->query_temp("exitw"));
//    tell_object(me,"w,变s,\n");
}
if (random(2)==0  && undefinedp(exit["north"]))
{
env->delete("exits/east");
env->set("exits/north", env->query_temp("exite"));
//    tell_object(me,"e,变n,\n");
}
//    tell_object(me,"这里有w,e,\n");
}

if( mapp(exit = env->query("exits")) && !undefinedp(exit["south"])
&& !undefinedp(exit["north"]) ) {
env->set_temp("exits",env->query("exits/south"));
env->set_temp("exitn",env->query("exits/north"));
env->set("exits/north", env->query_temp("exits"));
env->set("exits/south", env->query_temp("exitn"));
if (random(4)==0  && undefinedp(exit["west"]))
{
env->delete("exits/north");
env->set("exits/west", env->query_temp("exitn"));
//    tell_object(me,"n,变w,\n");
}
if (random(5)==0  && undefinedp(exit["east"]))
{
env->delete("exits/south");
env->set("exits/east", env->query_temp("exits"));
//    tell_object(me,"s,变e,\n");
}
//    tell_object(me,"这里有s,n，\n");
}
if( mapp(exit = env->query("exits")) && !undefinedp(exit["west"])
&& !undefinedp(exit["east"])
&& undefinedp(exit["south"])
&& undefinedp(exit["north"])  )
{
env->set_temp("exite",env->query("exits/east"));
env->set_temp("exitw",env->query("exits/west"));
if (random(4)==0)
env->set("exits/north", env->query_temp("exite"));
if (random(5)==0)
env->set("exits/south", env->query_temp("exitw"));
//    tell_object(me,"加s,n，\n");
}
if( mapp(exit = env->query("exits")) && undefinedp(exit["west"])
&& undefinedp(exit["east"])
&& !undefinedp(exit["south"])
&& !undefinedp(exit["north"])  )
{
env->set_temp("exits",env->query("exits/south"));
env->set_temp("exitn",env->query("exits/north"));
if (random(5)==0)
env->set("exits/west", env->query_temp("exits"));
if (random(4)==0)
env->set("exits/east", env->query_temp("exitn"));
//    tell_object(me,"加w,e，\n");
}

if( mapp(exit = env->query("exits")) && !undefinedp(exit["west"])
&& !undefinedp(exit["east"])
&& !undefinedp(exit["south"])
&& !undefinedp(exit["north"])  )
{
env->set_temp("exits",env->query("exits/south"));
env->set_temp("exitn",env->query("exits/north"));
env->set_temp("exitw",env->query("exits/west"));
env->set_temp("exite",env->query("exits/east"));
if (random(4)==0)
env->set("exits/west", env->query_temp("exits"));
if (random(4)==0)
env->set("exits/east", env->query_temp("exitn"));
if (random(4)==0)
env->set("exits/south", env->query_temp("exitw"));
if (random(4)==0)
env->set("exits/north", env->query_temp("exite"));

if (random(4)==0)
env->set("exits/west", env->query_temp("exite"));
if (random(4)==0)
env->set("exits/east", env->query_temp("exitw"));
if (random(4)==0)
env->set("exits/south", env->query_temp("exitn"));
if (random(4)==0)
env->set("exits/north", env->query_temp("exits"));

if (random(4)==0)
env->set("exits/westsouth", env->query_temp("exite"));
if (random(4)==0)
env->set("exits/eastnorth", env->query_temp("exitw"));
if (random(4)==0)
env->set("exits/southwest", env->query_temp("exitn"));
if (random(4)==0)
env->set("exits/northeast", env->query_temp("exits"));

//    tell_object(me,"加w,e，\n");
}
*/


        if(me->query("gender")=="男性")
    tell_object(me,"你迫不及待地将"+HIG+"宝箱"NOR+"打开，\n");
        else
    tell_object(me,"你小心翼翼地将"+HIY+"宝箱"NOR+"打开，\n");

    if( me->over_encumbranced() )
    return notify_fail("身上带的东西太多了，拿不动了。\n");

    if( me->is_busy() )
    return notify_fail("你正忙着呢。\n");
    if( me->is_fighting() )
    return notify_fail("你正忙着呢。\n");
    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
if (random(40) == 1 && environment(me)->query("short")!=CYN"石洞"NOR
&& !environment(this_object())->query("alrd")
)
{
       int rand;
       rand=random(sizeof(w_object));
           ob=new(__DIR__+w_object[rand]);
 if(ob)
{
        ob->move(me);
        tell_object(me,"找到了"+HIY":"+ob->query("name")+"."NOR+"。\n"NOR);
environment(this_object())->set("alrd",1);
}
else            tell_object(me,"结果什么也没有!"NOR+"。\n"NOR);

}
}


    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
if (random(100) < 1 && environment(me)->query("short")!=CYN"石洞"NOR
&& !environment(this_object())->query("alrd")
)
{
             corpse=new("/clone/gem/gem"+random(8));
if (corpse->query("level") >4 && me->query("combat_exp") > 28000000)
{
        corpse=new("/clone/gem/gem"+random(8));
}
             message_vision("$N得到一颗亮晶晶的宝石。\n",me);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "在最终迷宫中找到了一颗"+corpse->query("name")+HIM"!"NOR"。\n", users());
             corpse->move(me);
environment(this_object())->set("alrd",1);
if( !environment(me)->query("no_fight")
&& random(4)==1 && me->query("combat_exp")> 6000000)
	
{
obj=new("/d/migong/obj/npct");

maxpot=me->query_temp("maxpot")+10;
	obj->do_copy(me,maxpot,2);
	obj->set("usename",me->query("name"));

obj->move(environment(me));
	message_vision(HIY"$N狂笑道：把你的宝物交出来! !\n"NOR, obj);
	me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}
	/*else 
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		me->set("startroom", "/d/wizard/robot_court");
		obj->test_robot(me);
			}*/
		
}

}
    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
if (random(70) < 1 && environment(me)->query("short")!=CYN"石洞"NOR
&& !environment(this_object())->query("alrd"))
{
             corpse=new("/clone/gem/ring"+random(10));
             message_vision("$N得到一颗亮晶晶的戒指。\n",me);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "在最终迷宫中找到了一枚"+corpse->query("name")+HIM"!"NOR"。\n", users());
             corpse->move(me);
environment(this_object())->set("alrd",1);

}
}

      if(random(200)>180)
      {
        me->add("eff_jing",-50);
        me->add("eff_qi",-100);
        tell_object(me,"宝箱里发出数个"+HIR"暗器,你受了伤!"NOR+"。\n"NOR);
      }
      else if(random(200)>180)
      {
        me->add("eff_jing",-50);
        me->add("eff_qi",-100);
        tell_object(me,"宝箱里发出数个"+HIR"暗器,你受了伤!"NOR+"。\n"NOR);
      }
      else if(random(200)>198)
      {
        me->apply_condition("snake_poison",10);
        me->add("qi",-10);
        tell_object(me,"宝箱里发出数个"+RED"暗器,你中了毒!"NOR+"。\n"NOR);
      }
      else if(random(200)>198)
      {
        me->apply_condition("wugong_poison",10);
        me->add("qi",-10);
        tell_object(me,"宝箱里发出数个"+RED"暗器,你中了毒!"NOR+"。\n"NOR);
      }
      else if(random(200)>198)
      {
        me->apply_condition("wugong_poison",10);
        me->add("qi",-10);
        tell_object(me,"宝箱里发出数个"+RED"暗器,你中了毒!"NOR+"。\n"NOR);
      }
      else if(random(200)>198)
      {
        me->apply_condition("zhizhu_poison",10);
        me->add("qi",-10);
        tell_object(me,"宝箱里发出数个"+RED"暗器,你中了毒!"NOR+"。\n"NOR);
      }
      else if(random(200)>198)
      {
        me->apply_condition("xiezi_poison",10);
        me->add("qi",-10);
        tell_object(me,"宝箱里发出数个"+RED"暗器,你中了毒!"NOR+"。\n"NOR);
      }
      else if(random(200)>198)
      {
        me->apply_condition("chanchu_poison",10);
        me->add("qi",-10);
        tell_object(me,"宝箱里发出数个"+RED"暗器,你中了毒!"NOR+"。\n"NOR);
      }
      else if(random(100)>98 && environment(me)->query("short")==BLU"山洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你的经验增加了!!"NOR+"。\n"NOR);
	me->add("combat_exp", 1000);
      }
      else if(random(100)>98 && environment(me)->query("short")==WHT"钟乳石洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你的潜能增加了!!"NOR+"。\n"NOR);
	me->add("potential",500);
      }
      else if(random(100)>98 && environment(me)->query("short")==YEL"岩洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+YEL"金光,你的内力增加了!!"NOR+"。\n"NOR);
	me->add("max_neili",50);
      }
      else if(random(100)>98 && environment(me)->query("short")==RED"熔岩洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+YEL"金光,你的经验,潜能内力都增加了!!"NOR+"。\n"NOR);
	me->add("combat_exp", 1000);
	me->add("potential",500);
	me->add("max_neili",50);
      }
      else if(random(100)>98
      && !environment(this_object())->query("alrd"))
      {
if (  environment(me)->query("short")==RED"熔岩洞"NOR
      || environment(me)->query("short")==YEL"岩洞"NOR)
{
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗机会珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu7");
        ob->move(me);
        environment(this_object())->set("alrd",1);
}
      }
      else if(random(100)>98 && environment(me)->query("short")==BLU"山洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗力量珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu1");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("short")==BLU"山洞"NOR
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗火灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/huozhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }
      else if(random(100)>98 && environment(me)->query("short")==WHT"钟乳石洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗悟性珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu2");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("short")==WHT"钟乳石洞"NOR
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗雷灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/leizhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }

      else if(random(100)>98 && environment(me)->query("short")==YEL"岩洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗根骨珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu3");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("short")==YEL"岩洞"NOR
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗土灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/tuzhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }

      else if(random(100)>98 && environment(me)->query("short")==RED"熔岩洞"NOR      )
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗身法珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu4");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("short")==RED"熔岩洞"NOR
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗风灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/fengzhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }

      else if(random(100)>98 && environment(me)->query("short")==RED"熔岩洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗容貌珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu6");
        ob->move(me);
      }

      else if(random(100)>98 && environment(me)->query("short")==YEL"岩洞"NOR)
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗福缘珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu5");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("short")==YEL"岩洞"NOR
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗水灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/shuizhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }

      else
      {
       int rand;
       rand=random(sizeof(box_object));
           ob=new(__DIR__+box_object[rand]);
 if(ob)
{
        ob->move(me);
        ob->move(me);
        tell_object(me,"发现了"+HIY":"+ob->query("name")+"."NOR+"。\n"NOR);
}
else            tell_object(me,"结果什么也没有!"NOR+"。\n"NOR);
      }
/*if (random(12)==0)
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		me->set("startroom", "/d/wizard/robot_court");
		obj->test_robot(me);
me->start_busy(10);
}*/
	destruct(this_object());
        return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
