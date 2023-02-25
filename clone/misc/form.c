// clone/misc/form
// Mud收费的调查问卷
// Creat by Shure@tomud.com 2002-04-11
/*************************************
   database structure:
   ([
   id_1 : ([ step_1 : ({choice_1, choice_2,choice_3, ... }),
	     step_2 : ({choice_1, choice_2,choice_3, ... }),
	     ... ]),
   id_2 : ([ step_1 : ...
	     ... ]),
   ... ])
*************************************/

#include <ansi.h>

inherit COMBINED_ITEM;
inherit F_SAVE;

static mapping form = ([

	"你接触文字mud有多长时间了？" : ({
		"一年以下。",
		"两年以下。",
		"三年以下。",
		"三年以上。" }),
		
	"你现在和文字mud是一种什么样的关系？" : ({
		"现在还沉浸在其中的玩家。",
		"曾经很热情地玩过，但是现在已经淡出了。",
		"曾经很热情地玩过，但是现在已经腻烦，投身入图形网络游戏的怀抱了。",
		"压根没有认真玩过，只是通过其他渠道有些了解。",
		"以前是资深的玩家，现在在mud里担任巫师。",
		"以前也没怎么太深入玩mud，莫名其妙地就当了巫师。" }),
		
	"你玩过现在市场上非常流行的角色扮演类图形界面的网络游戏（如魔力宝贝、传奇类）吗？" : ({
		"玩过1-2款，了解一点。",
		"热门的图形界面的网络游戏我都去尝试过。",
		"我是图形界面的网络游戏的发烧级玩家。",
		"没有玩过。" }),
		
	"现在图形界面的网络游戏非常流行，这种情况下，你为什么要选择玩文字mud？" : ({
		"操作简便而且直接。",
		"我接触网络游戏就是从玩文字mud开始的，已经习惯并且喜欢上这种方式了。",
		"文字mud与图形游戏相比更好玩。",
		"因为文字mud是免费的。",
		"如果上述列项都不符合，请输入你的看法。" }),
		
	"与图形界面的网络游戏相比，你觉得文字mud的劣势主要在哪里？" : ({
		"文字mud上手太难了，熟悉数百的指令以及学习zmud使用就需要很长时间。",
		"文字mud的界面太单调，很难从第一印象吸引新玩家。",
		"文字mud的巫师管理混乱，没有约束。",
		"现在的文字mud没有太多的新意，都是老一套的升级打点的方式。",
		"数据没有保证，一旦因为事故数据损坏或因服务器变动而关站，无可挽回且无处投诉。",
		"后期开发没有保证，开发与否完全看巫师的心情，没有督促力量约束。",
		"如果上述列项都不符合，请输入你的看法。" }),
		
	"如果有下面几组关系来形容文字mud与图形网络游戏，你觉得哪组关系最合适？" : ({
		"DOS系统和windows系统。",
		"门槛高而体系完备的unix系统和操作直观但漏洞多的win9x。",
		"同父异母的两个孩子。",
		"萝卜和青菜。",
		"如果上述列项都不符合，请输入你的看法。" }),
		
	"现在的文字mud需要实现哪些方面的主要变革才是你理想中的情况？" : ({
		"巫师管理透明化，程序开发与游戏管理者严格分开，建立监督体制。",
		"建立持续的后期开发保障，确保游戏得到及时的更新。",
		"玩家遇到的所有问题和提出的建议在24小时内得到管理层的回复。",
		"数据确保每日备份，尽量加强安全保障。",
		"尽快开发出新型的游戏机制。",
		"降低文字mud的门槛，使操作方式尽量简便直接。",
		"客户端（如tomud或zmud）更加漂亮并且人性化，使之看起来更象一个游戏。",
		"如果上述列项都不符合，请输入你的看法。" }),
		
	"如果在上述条件都能满足的情况下，文字mud采取收费制运行，你会采取什么态度。" : ({
		"为文字mud交费？老兄你有没有发烧？",
		"虽然条件不错，但是现在免费mud的服务也能忍受，还是选择免费的凑合玩吧。",
		"如果价格低而且交费方便，可以考虑接受。",
		"如果真的可以提供正规而有保证的服务，我会花钱玩我喜欢的mud。",
		"如果上述列项都不符合，请输入你的看法。" }),
		
	"如果你所在的文字mud新开了收费站，你会在何种情况下去尝试？" : ({
		"巫师管理尽心而且公正，同时后期开发和bug订正都很及时。",
		"如果收费合理并且开站正规，有持续保障，我就选择尝试。",
		"如果附赠与我所在的mud形象相关的网络增值服务（如E-mail信箱或主页空间），我就会选择。",
		"无论如何我也不会放弃免费站点，去交费玩mud。",
		"除非能把我所在的mud里的玩家数据都转档到新站。",
		"如果上述列项都不符合，请输入你的看法。" }),
		
	"如果你决定尝试你所在的mud新开的收费站，你觉得以下何种收费方式可以接受：" : ({
		"按游戏时间的长短实行点数收费制度。",
		"定量的点数卡换取月费卡。",
		"只可能接受月费卡" }),
		
	"你希望通过何种方式交纳费用？" : ({
		"通过汇款方式进行帐户充值。",
		"网上直接划卡交费，购买虚拟帐号。",
		"在住处附近的书店报刊亭购买游戏点数卡。",
		"从网上商城购买实物点数卡，送货上门。" }),	
	]);

static string *k_form  = ({
	"你接触文字mud有多长时间了？",
	"你现在和文字mud是一种什么样的关系？",
	"你玩过现在市场上非常流行的角色扮演类图形界面的网络游戏（如魔力宝贝、传奇类）吗？",
	"现在图形界面的网络游戏非常流行，这种情况下，你为什么要选择玩文字mud？",
	"与图形界面的网络游戏相比，你觉得文字mud的劣势主要在哪里？",
	"如果有下面几组关系来形容文字mud与图形网络游戏，你觉得哪组关系最合适？",
	"现在的文字mud需要实现哪些方面的主要变革才是你理想中的情况？",
	"如果在上述条件都能满足的情况下，文字mud采取收费制运行，你会采取什么态度。",
	"如果你所在的文字mud新开了收费站，你会在何种情况下去尝试？",
	"如果你决定尝试你所在的mud新开的收费站，你觉得以下何种收费方式可以接受：",
	"你希望通过何种方式交纳费用？",
	});     
	
static string *index   = ({ "A", "B", "C", "D", "E", "F", "G", "H" });
static mapping answers = ([]);
static string *options;
mapping sheet;

void setup();
void set_amount(int i);
int  do_start();
void QA_step( int step );
void decide_choice( string answer, object me, int step );
void do_refer( string yn, object me );
void done_self_opinion( object me, int step, string text );
void query_site( string site, object me );
void save_sheet( object me, mapping answers );
mixed query_sheet();

void create()
{
	set_name(YEL"文字MUD调查问卷"NOR, ({ "questionary", "wenjuan" }) );
	set("long", "这是一张有关文字mud发展的调查问卷。\n"
		    "文字mud就是文字表现的网络游戏了，说得简单些，也就是你现在玩的这种游戏。\n"
		    "暂时并没有什么用，不过原版有，就保留下来了。\n"
		    "输入"HIR"start"NOR"指令，开始进入问题回答。\n" );
	set_weight(1);
	set( "base_weight", 1 );
	set("unit","张");
	set("base_unit","张");
	set_amount(1);
	setup();
}

void setup()
{
	if ( !clonep() )
		restore();
}

void init()
{
	if ( clonep() )
		add_action( "do_start", "start" );
}

string query_save_file()
{
	return DATA_DIR + "questionary";
}
/*
void set_amount( int i )
{
	if ( i < 0 )
		error( "set_amount as null!\n" );
	if ( i == 0 )
		destruct( this_object() );
	else
		amount = 1;
}
*/
int do_start()
{
	sheet = copy( base_name( this_object() )->query_sheet() );
	if ( mapp( sheet ) && !undefinedp( sheet[this_player()->query( "id" )] ) )
	{
		write( "对不起，你已经填写过调查问卷了，感谢你的一贯支持！\n" );
		destruct( this_object() );
		return 1;
	}
	QA_step(0);
	return 1;
}

void QA_step( int step )
{
	int    i, j;
	string *choice, item;
		
	if ( step >= sizeof( form ) )
	{
		write( "表格已经填写完毕，请问你是否决定提交？(y/n)" );
		input_to( "do_refer", this_player() );
		return ;
	}
	item   = k_form[step];
	choice = form[item];
	j      = sizeof(choice);
	
	write( HIG + ( step + 1 ) + "、" + item + "\n\n" + NOR );
	for ( i = 0; i < j; i ++ )
		write( index[i] + " " + choice[i] +"\n" );

	write( "\n请输入你的选择(A、B、C、D)\n"
	       "如果多选请用分号隔开每个选项。(如：A、B、D)\n" );    
	input_to( "decide_choice", this_player(), step );
}

void decide_choice( string answer, object me, int step )
{
	int     i, j, error;
	string *v;
	
	answer  = replace_string( answer, " ", "" ); 
	v = form[ k_form[step] ];
	
	if (strsrch( answer, "、" ) == -1 )
	{
		j = member_array( answer, index );

		if ( j == -1 || ( j + 1 ) > sizeof( v ) )
		{
			write( "\n请"HIR"正确"NOR"输入你的选择(A、B、C、D)\n"
			       "如果多选请用分号隔开每个选项。(如：A、B、D)\n" );	      
			input_to( "decide_choice", me, step );
			return;
		}
		else
		{
			if ( v[ j ] == "如果上述列项都不符合，请输入你的看法。" )
				me->edit((: done_self_opinion, me, step :));
			else
			{
				options = ({ answer });
				answers[step] = options;
				QA_step( step + 1 );
			}
			return;
		}
	}
	options = explode( answer, "、" );
	error   = 0;	
	for ( i = 0; i < sizeof( options ); i ++ )
	{
		if ( ( j = member_array( options[i], index ) ) == -1
		     || ( j + 1 ) > sizeof( v )
		     || v[ j ] == "如果上述列项都不符合，请输入你的看法。" )
		{
			error ++;
			break;
		}
	}
	if ( error )
	{
		write( "\n请"HIR"正确"NOR"输入你的选择(A、B、C、D...)\n"
		       "如果多选请用分号隔开每个选项。（如：C、E、F）\n" );
		options = ({});    
		input_to( "decide_choice", me, step );
		return;
	}
	answers[step] = options;
	QA_step( step + 1 );
}

void do_refer( string yn, object me )
{
	if ( yn == "Y" || yn == "y" )
	{
		write( "请输入你目前所在的国家和城市（如：中国北京）" );
		input_to( "query_site", me );
		return;
	}
	if ( yn != "N" && yn != "n" )
	{
		write( "表格已经填写完毕，请问你是否决定提交？(y/n)\n" );
		input_to( "do_refer", me );
		return;
	}
	answers  = ([]);
	options = ({}); 
	write( "放弃提交。\n重新填写表格请输入start指令。\n" );
	return;
}

void done_self_opinion( object me, int step, string text )
{
	options = ({ "self_opinion: " + text });
	answers[step] = options;
	QA_step( step + 1 );
}

void query_site( string site, object me )
{
	if ( !stringp( site ) || site == "" )
	{
		write( "请输入你目前所在的国家和城市（如：中国北京）\n" );
		input_to( "query_site", me );
	       // return;
	}
	answers[ "site" ] = site;
	//me->save_sheet( me, answers );
	write( "答卷已提交，谢谢你的支持！\n" );
	destruct( this_object() );
	
}

void save_sheet( object me, mapping answers )
{
	if ( !clonep() )
	{
		sheet[ me->query("id") ] = copy(answers);
		save();
	}
}

mixed query_sheet()
{
	if ( !clonep() )
		return sheet;
	return 0;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
