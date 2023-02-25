// Room: /city/dangpu.c
inherit ROOM;
void create()
{
	//set("short", HIY"精武门"NOR);
	set("short", "精武门");

	set("long", @LONG
这是这是大侠霍元甲开设的精武门，现在由他的徒弟陈真在打理，凡是有励志报国之心的英雄侠士都会到这里来学习研究中华武术，武馆的目的是为了让中华武术发扬光大，永世传承。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"【说明】" : "欢迎光临\n中华武术博大精深，本武馆的宗旨是为了发扬中华武术，特给各路英雄提供一个修炼武学的场所。\n
1、精武试炼可单人试炼，也可以组队试炼，组好队后，全体队员都到精武门，由队长对话陈真开始。\n
2、单人时会有30个弟子，组队时，每增加一个队员，增加5个弟子，可选择主动攻击与被动攻击模式。\n
3、组队试炼时，必须所有队员当日都没有进行精武试炼才能全体传送进入。\n
4、组队试炼时，每人获得的经验数均会按照人数加成，但是必须队员对弟子的伤害要尽量均衡。\n
5、每次击败一个弟子，会计算最高伤队员与最低伤害队员的伤害比，组队倍数再除以伤害比。比如3人组队时：组队倍数 = 3/(最高伤害/最低伤害) 组队倍数最低不会低于1。\n
6、弟子强弱系数直接决定经验的高低，100的系数就等于能获得经验的100%，50系数就只能得经验的50%，200系数就能得到经验的200%。\n
7、比如ABC3人组队，击败一个120系数弟子，共造成90000的伤害，如果每人给弟子的伤害分别是A=40000、B=30000、C=20000，

每人经验计算：
A = 90000 * 0.01 * (120/100) * 3 / (40000/20000)
B = A *（30000/40000）
C = A *（20000/40000）

如果给弟子的伤害是一个造成的，那么单人经验：
单人 = 90000 * 0.01 * (120/100)

8、给弟子造成的伤害不能超过弟子血量的2倍，超过了也只能按2倍血量来计算经验。\n
9、注意，弟子会使用保命丹、和田玉(补满内力)，战斗脚本来与你比试，务必选择适合自己的系数进行试炼。"]));

	set("objects", ([
		"d/jfjwm/npc/chenzhen" : 1,
	]));
	
	set("exits", ([
		"southeast" : "/d/city/kedian",
	
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/