// 宝箱

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
string *box_object=({
"/clone/magic/obj/book11",
"/clone/magic/obj/book12",
"/clone/magic/obj/book13",
"/clone/magic/obj/book21",
"/clone/magic/obj/book22",
"/clone/magic/obj/book23",
"/clone/magic/obj/book31",
"/clone/magic/obj/book32",
"/clone/magic/obj/book33",
"/clone/magic/obj/book41",
"/clone/magic/obj/book42",
"/clone/magic/obj/book43",
"/clone/magic/obj/book62",
"/clone/magic/obj/book63",
"/clone/magic/obj/book61",
"/clone/magic/obj/book52",
"/clone/magic/obj/book53",
"/clone/magic/obj/book51",
"/clone/magic/obj/book11",
"/clone/magic/obj/book12",
"/clone/magic/obj/book13",
"/clone/magic/obj/book21",
"/clone/magic/obj/book22",
"/clone/magic/obj/book23",
"/clone/magic/obj/book31",
"/clone/magic/obj/book32",
"/clone/magic/obj/book33",
"/clone/magic/obj/book41",
"/clone/magic/obj/book42",
"/clone/magic/obj/book43",
"/clone/magic/obj/book62",
"/clone/magic/obj/book63",
"/clone/magic/obj/book61",
"/clone/magic/obj/book52",
"/clone/magic/obj/book53",
"/clone/magic/obj/book51",
"/clone/magic/obj/cloth",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item15",
"/clone/magic/obj/item16",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item25",
"/clone/magic/obj/item26",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item33",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item36",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item15",
"/clone/magic/obj/item16",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item25",
"/clone/magic/obj/item26",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item33",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item36",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item15",
"/clone/magic/obj/item16",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item25",
"/clone/magic/obj/item26",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item33",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item36",
"/clone/magic/obj/s1",
"/clone/magic/obj/s1",
"/clone/magic/obj/s1",
"/clone/magic/obj/s10",
"/clone/magic/obj/s11",
"/clone/magic/obj/s12",
"/clone/magic/obj/s13",
"/clone/magic/obj/s14",
"/clone/magic/obj/s15",
"/clone/magic/obj/s16",
"/clone/magic/obj/s17",
"/clone/magic/obj/s18",
"/clone/magic/obj/s19",
"/clone/magic/obj/s2",
"/clone/magic/obj/s2",
"/clone/magic/obj/s2",
"/clone/magic/obj/s20",
"/clone/magic/obj/s21",
"/clone/magic/obj/s22",
"/clone/magic/obj/s23",
"/clone/magic/obj/s24",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s9",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s9",
"/clone/magic/obj/sword",
"/clone/magic/obj/w1",
"/clone/magic/obj/w1",
"/clone/magic/obj/w1",
"/clone/magic/obj/w10",
"/clone/magic/obj/w11",
"/clone/magic/obj/w12",
"/clone/magic/obj/w13",
"/clone/magic/obj/w14",
"/clone/magic/obj/w15",
"/clone/magic/obj/w16",
"/clone/magic/obj/w17",
"/clone/magic/obj/w18",
"/clone/magic/obj/w19",
"/clone/magic/obj/w2",
"/clone/magic/obj/w2",
"/clone/magic/obj/w2",
"/clone/magic/obj/w20",
"/clone/magic/obj/w21",
"/clone/magic/obj/w22",
"/clone/magic/obj/w23",
"/clone/magic/obj/w24",
"/clone/magic/obj/w3",
"/clone/magic/obj/w4",
"/clone/magic/obj/w5",
"/clone/magic/obj/w6",
"/clone/magic/obj/w7",
"/clone/magic/obj/w8",
"/clone/magic/obj/w9",
"/clone/magic/obj/w3",
"/clone/magic/obj/w4",
"/clone/magic/obj/w5",
"/clone/magic/obj/w6",
"/clone/magic/obj/w7",
"/clone/magic/obj/w8",
"/clone/magic/obj/w3",
"/clone/magic/obj/w4",
"/clone/magic/obj/w5",
"/clone/magic/obj/w6",
"/clone/magic/obj/w7",
"/clone/magic/obj/w8",
"/clone/magic/obj/water1",
"/clone/magic/obj/water2",
"/clone/magic/obj/water3",
"/clone/magic/obj/water4",
"/clone/magic/obj/s1",
"/clone/magic/obj/s1",
"/clone/magic/obj/s1",
"/clone/magic/obj/s10",
"/clone/magic/obj/s11",
"/clone/magic/obj/s12",
"/clone/magic/obj/s13",
"/clone/magic/obj/s14",
"/clone/magic/obj/s15",
"/clone/magic/obj/s16",
"/clone/magic/obj/s17",
"/clone/magic/obj/s18",
"/clone/magic/obj/s19",
"/clone/magic/obj/s2",
"/clone/magic/obj/s2",
"/clone/magic/obj/s2",
"/clone/magic/obj/s20",
"/clone/magic/obj/s21",
"/clone/magic/obj/s22",
"/clone/magic/obj/s23",
"/clone/magic/obj/s24",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s9",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s9",
"/clone/magic/obj/sword",
});

string *w_object=({
"/clone/box/new2/0",
"/clone/box/new2/1",
"/clone/box/new2/2",
"/clone/box/new2/3",
"/clone/box/new2/4",
"/clone/box/new2/5",
"/clone/box/new2/6",
"/clone/box/new2/7",
"/clone/box/new2/8",
"/clone/box/new2/9",
"/clone/box/new2/10",
"/clone/box/new2/11",
"/clone/box/new2/12",
"/clone/box/new2/13",
"/clone/box/new2/14",
"/clone/box/new2/15",
"/clone/box/new2/16",
"/clone/box/new2/17",
"/clone/box/new2/18",
"/clone/box/new2/19",
"/clone/box/new2/20",
"/clone/box/new2/21",
"/clone/box/new2/22",
"/clone/box/new2/23",
"/clone/box/new2/24",
"/clone/box/new2/25",
"/clone/box/new2/26",
"/clone/box/new2/27",
"/clone/box/new2/28",
"/clone/box/new2/29",
"/clone/box/new2/30",
"/clone/box/new2/31",
"/clone/box/new2/32",
"/clone/box/new2/33",
"/clone/box/new2/34",
"/clone/box/new2/35",
"/clone/box/new2/36",
"/clone/box/new2/37",
"/clone/box/new2/38",
"/clone/box/new2/39",
"/clone/box/new2/40",
"/clone/box/new2/41",
"/clone/box/new2/42",
"/clone/box/new2/43",
"/clone/box/new2/44",
"/clone/box/new2/45",
"/clone/box/new2/46",
"/clone/box/new2/47",
"/clone/box/new2/48",
"/clone/box/new2/49",
"/clone/box/new2/50",
"/clone/box/new2/51",
"/clone/box/new2/52",
"/clone/box/new2/53",
"/clone/box/new2/54",
"/clone/box/new2/55",
"/clone/box/new2/56",
"/clone/box/new2/57",
"/clone/box/new2/58",
"/clone/box/new2/59",
"/clone/box/new2/60",
"/clone/box/new2/61",
"/clone/box/new2/62",
"/clone/box/new2/63",
"/clone/box/new2/64",
"/clone/box/new2/65",
"/clone/box/new2/66",
"/clone/box/new/ar1",
"/clone/box/new/ar10",
"/clone/box/new/ar11",
"/clone/box/new/ar12",
"/clone/box/new/ar13",
"/clone/box/new/ar14",
"/clone/box/new/ar15",
"/clone/box/new/ar16",
"/clone/box/new/ar17",
"/clone/box/new/ar18",
"/clone/box/new/ar2",
"/clone/box/new/ar3",
"/clone/box/new/ar4",
"/clone/box/new/ar5",
"/clone/box/new/ar6",
"/clone/box/new/ar7",
"/clone/box/new/ar8",
"/clone/box/new/ar9",
"/clone/box/new/ar2",
"/clone/box/new/ar3",
"/clone/box/new/ar4",
"/clone/box/new/ar5",
"/clone/box/new/ar6",
"/clone/box/new/ar7",
"/clone/box/new/ar8",
"/clone/box/new/ar9",
"/clone/box/new/bt1",
"/clone/box/new/bt10",
"/clone/box/new/bt11",
"/clone/box/new/bt12",
"/clone/box/new/bt13",
"/clone/box/new/bt14",
"/clone/box/new/bt15",
"/clone/box/new/bt16",
"/clone/box/new/bt17",
"/clone/box/new/bt18",
"/clone/box/new/bt2",
"/clone/box/new/bt3",
"/clone/box/new/bt4",
"/clone/box/new/bt5",
"/clone/box/new/bt6",
"/clone/box/new/bt7",
"/clone/box/new/bt8",
"/clone/box/new/bt9",
"/clone/box/new/bt2",
"/clone/box/new/bt3",
"/clone/box/new/bt4",
"/clone/box/new/bt5",
"/clone/box/new/bt6",
"/clone/box/new/bt7",
"/clone/box/new/bt8",
"/clone/box/new/bt9",
"/clone/box/new/h1",
"/clone/box/new/h10",
"/clone/box/new/h11",
"/clone/box/new/h12",
"/clone/box/new/h13",
"/clone/box/new/h14",
"/clone/box/new/h15",
"/clone/box/new/h16",
"/clone/box/new/h2",
"/clone/box/new/h3",
"/clone/box/new/h4",
"/clone/box/new/h5",
"/clone/box/new/h6",
"/clone/box/new/h7",
"/clone/box/new/h8",
"/clone/box/new/h9",
"/clone/box/new/h2",
"/clone/box/new/h3",
"/clone/box/new/h4",
"/clone/box/new/h5",
"/clone/box/new/h6",
"/clone/box/new/h7",
"/clone/box/new/h8",
"/clone/box/new/h9",
"/clone/box/new/hd1",
"/clone/box/new/hd10",
"/clone/box/new/hd11",
"/clone/box/new/hd12",
"/clone/box/new/hd13",
"/clone/box/new/hd14",
"/clone/box/new/hd15",
"/clone/box/new/hd16",
"/clone/box/new/hd17",
"/clone/box/new/hd18",
"/clone/box/new/hd2",
"/clone/box/new/hd3",
"/clone/box/new/hd4",
"/clone/box/new/hd5",
"/clone/box/new/hd6",
"/clone/box/new/hd7",
"/clone/box/new/hd8",
"/clone/box/new/hd9",
"/clone/box/new/hd2",
"/clone/box/new/hd3",
"/clone/box/new/hd4",
"/clone/box/new/hd5",
"/clone/box/new/hd6",
"/clone/box/new/hd7",
"/clone/box/new/hd8",
"/clone/box/new/hd9",
"/clone/box/new/nk1",
"/clone/box/new/nk10",
"/clone/box/new/nk11",
"/clone/box/new/nk12",
"/clone/box/new/nk13",
"/clone/box/new/nk14",
"/clone/box/new/nk15",
"/clone/box/new/nk16",
"/clone/box/new/nk17",
"/clone/box/new/nk18",
"/clone/box/new/nk2",
"/clone/box/new/nk3",
"/clone/box/new/nk4",
"/clone/box/new/nk5",
"/clone/box/new/nk6",
"/clone/box/new/nk7",
"/clone/box/new/nk8",
"/clone/box/new/nk9",
"/clone/box/new/nk2",
"/clone/box/new/nk3",
"/clone/box/new/nk4",
"/clone/box/new/nk5",
"/clone/box/new/nk6",
"/clone/box/new/nk7",
"/clone/box/new/nk8",
"/clone/box/new/nk9",
"/clone/box/new/sc1",
"/clone/box/new/sc10",
"/clone/box/new/sc11",
"/clone/box/new/sc12",
"/clone/box/new/sc13",
"/clone/box/new/sc14",
"/clone/box/new/sc15",
"/clone/box/new/sc16",
"/clone/box/new/sc17",
"/clone/box/new/sc18",
"/clone/box/new/sc2",
"/clone/box/new/sc3",
"/clone/box/new/sc4",
"/clone/box/new/sc5",
"/clone/box/new/sc6",
"/clone/box/new/sc7",
"/clone/box/new/sc8",
"/clone/box/new/sc9",
"/clone/box/new/sc2",
"/clone/box/new/sc3",
"/clone/box/new/sc4",
"/clone/box/new/sc5",
"/clone/box/new/sc6",
"/clone/box/new/sc7",
"/clone/box/new/sc8",
"/clone/box/new/sc9",
"/clone/box/new/sd1",
"/clone/box/new/sd10",
"/clone/box/new/sd11",
"/clone/box/new/sd12",
"/clone/box/new/sd13",
"/clone/box/new/sd14",
"/clone/box/new/sd15",
"/clone/box/new/sd16",
"/clone/box/new/sd17",
"/clone/box/new/sd18",
"/clone/box/new/sd2",
"/clone/box/new/sd3",
"/clone/box/new/sd4",
"/clone/box/new/sd5",
"/clone/box/new/sd6",
"/clone/box/new/sd7",
"/clone/box/new/sd8",
"/clone/box/new/sd9",
"/clone/box/new/sd2",
"/clone/box/new/sd3",
"/clone/box/new/sd4",
"/clone/box/new/sd5",
"/clone/box/new/sd6",
"/clone/box/new/sd7",
"/clone/box/new/sd8",
"/clone/box/new/sd9",
"/clone/box/new/wi1",
"/clone/box/new/wi10",
"/clone/box/new/wi11",
"/clone/box/new/wi12",
"/clone/box/new/wi13",
"/clone/box/new/wi14",
"/clone/box/new/wi15",
"/clone/box/new/wi16",
"/clone/box/new/wi17",
"/clone/box/new/wi18",
"/clone/box/new/wi2",
"/clone/box/new/wi3",
"/clone/box/new/wi4",
"/clone/box/new/wi5",
"/clone/box/new/wi6",
"/clone/box/new/wi7",
"/clone/box/new/wi8",
"/clone/box/new/wi9",
"/clone/box/new/wt1",
"/clone/box/new/wt10",
"/clone/box/new/wt11",
"/clone/box/new/wt12",
"/clone/box/new/wt13",
"/clone/box/new/wt14",
"/clone/box/new/wt15",
"/clone/box/new/wt16",
"/clone/box/new/wt17",
"/clone/box/new/wt18",
"/clone/box/new/wt2",
"/clone/box/new/wt3",
"/clone/box/new/wt4",
"/clone/box/new/wt5",
"/clone/box/new/wt6",
"/clone/box/new/wt7",
"/clone/box/new/wt8",
"/clone/box/new/wt9",
"/clone/box/new/wt2",
"/clone/box/new/wt3",
"/clone/box/new/wt4",
"/clone/box/new/wt5",
"/clone/box/new/wt6",
"/clone/box/new/wt7",
"/clone/box/new/wt8",
"/clone/box/new/wt9",
});

void create()
{
	set_name(HIR"幻之宝箱"NOR, ({"bao xiang", "bao", "xiang"}));
        set("no_get",1);
	set("vendetta/authority",1);
	set_weight(100000);
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用红宝石制作而成的"+HIG"宝箱，"NOR+"似乎可以"ZJURL("cmds:openbox")ZJSIZE(15)""HIW"打开""\\n");
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

    if( me->is_busy() )
    return notify_fail("你正忙着呢。\n");
    if( me->is_fighting() )
    return notify_fail("你正忙着呢。\n");

    if( me->over_encumbranced() )
    return notify_fail("身上带的东西太多了，拿不动了。\n");


    if(environment(me)->query("magicroom")
)
{
if (random(50) < 1 && environment(me)->query("magicroom")
&& !environment(this_object())->query("alrd")
)
{
             corpse=new("/clone/gem/gem");
if (corpse->query("level") >4 && random(2)==0)
{
        corpse=new("/clone/gem/gem");
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
else 
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		obj->test_robot(me);
}
}
}
    if(environment(me)->query("magicroom")
)
{
if (random(70) < 1 && environment(me)->query("magicroom")
&& !environment(this_object())->query("alrd"))
{
             corpse=new("/clone/gem/ring"+random(10));
             message_vision("$N得到一颗亮晶晶的戒指。\n",me);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "在最终迷宫中找到了一枚"+corpse->query("name")+HIM"!"NOR"。\n", users());
             corpse->move(me);
environment(this_object())->set("alrd",1);

}
}
if (random(40) == 1 && environment(me)->query("magicroom")
&& !environment(this_object())->query("alrd")
)
{
       int rand;
       rand=random(sizeof(w_object));
           ob=new(w_object[rand]);

 if(ob)
{
        ob->move(me);
        tell_object(me,"找到了"+HIY":"+ob->query("name")+"."NOR+"。\n"NOR);
environment(this_object())->set("alrd",1);
}
else            tell_object(me,"结果什么也没有!"NOR+"。\n"NOR);
}


      if(random(100)>95)
      {
        ob=new("/clone/money/gold");
        ob->set_amount(random(100));
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"黄金"NOR+"。\n"NOR);
      }
      else if(random(100)>95)
      {
        ob=new("/clone/money/gold");
        ob->set_amount(random(100));
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"黄金"NOR+"。\n"NOR);
      }
      else if(random(200)>180)
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
      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你的经验增加了!!"NOR+"。\n"NOR);
	me->add("combat_exp", 1000);
      }
      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你的潜能增加了!!"NOR+"。\n"NOR);
	me->add("potential",500);
      }
      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+YEL"金光,你的内力增加了!!"NOR+"。\n"NOR);
	me->add("max_neili",50);
      }
      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+YEL"金光,你的经验,潜能内力都增加了!!"NOR+"。\n"NOR);
	me->add("combat_exp", 1000);
	me->add("potential",500);
	me->add("max_neili",50);
      }
      else if(random(100)>98
      && !environment(this_object())->query("alrd"))
      {
if (  environment(me)->query("magicroom")
      )
{
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗机会珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu7");
        ob->move(me);
        environment(this_object())->set("alrd",1);
}
      }
      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗力量珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu1");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("magicroom")
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗火灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/huozhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }
      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗悟性珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu2");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("magicroom")
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗雷灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/leizhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }

      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗根骨珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu3");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("magicroom")
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗土灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/tuzhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }

      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗身法珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu4");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("magicroom")
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗风灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/fengzhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }

      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗容貌珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu6");
        ob->move(me);
      }

      else if(random(100)>98 && environment(me)->query("magicroom"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗福缘珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"zhu5");
        ob->move(me);
      }
      else if(random(200)>198 && environment(me)->query("magicroom")
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"宝箱里发出一阵详和的"+HIY"金光,你获得一颗水灵珠!!"NOR+"。\n"NOR);
        ob=new(__DIR__"baowu/shuizhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }

      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"白银"NOR+"。\n"NOR);
      }
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"白银"NOR+"。\n"NOR);
      }
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"白银"NOR+"。\n"NOR);
      }
      else if(random(100)>95)
      {
        ob=new("/clone/money/coin");
        ob->set_amount(random(1000));
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"铜钱"NOR+"。\n"NOR);
      }
      else if(random(100)>95)
      {
        ob=new("/clone/money/coin");
        ob->set_amount(random(1000));
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"铜钱"NOR+"。\n"NOR);
      }
      else
      {
       int rand;
       rand=random(sizeof(box_object));
           ob=new(box_object[rand]);
 if(ob)
{
        ob->move(me);
        ob->move(me);
        tell_object(me,"发现了"+HIY":"+ob->query("name")+"."NOR+"。\n"NOR);
}
else            tell_object(me,"结果什么也没有!"NOR+"。\n"NOR);
      }
if (random(12)==0)
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		obj->test_robot(me);
me->set("startroom", "/d/wizard/robot_court");
me->start_busy(10);
}
	destruct(this_object());
        return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
