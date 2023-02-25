//Map here功能  By JackyBoy 1999/11/19
//由于严重影响速度（递归调用导致！），所以进行此命令的使用应该减少玩家的精力或者气息
#include <ansi.h>

#define MaxX 11
#define MaxY 22
#define MinX 5
#define MinY 10
inherit F_CLEAN_UP;

nosave int X,Y;
nosave mixed m;
nosave string *rfile;
nosave mapping *data;
int draw_room(int,int,object);
void set_room(int,int,object);
void set_x_y(int,int,int);

// 转换颜色
string clean_color(string arg)
{
	if(!arg)       return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK,"");
	return arg;
}

int main(object me, string arg)
{
	object where;
	int i,j,k,l,n,p;
	int lineu,lined,linef;
	string *text;
	string tmp, line="";

	if (me->query_temp("maphere_time") > time())
		return notify_fail("别着急，先休息一下吧！\n");
	
	if ( arg && arg == "-min" )
	{
			X=MaxX;
			Y=MaxY;
	}
	else
	{
	
		if(arg && arg == "-m")
		{
			X=MaxX;
			Y=MaxY;
		}
		else
		{
			X=MinX;
			Y=MinY;
		}
	}

	line=ZJMAPTXT;
	//line=ZJOBLONG;
	tmp = HIC+MUD_NAME+HIY"即时地图显示："NOR+ZJBR;
	m=allocate(2*X+1);
	data=allocate((2*X+1)*(2*Y+1));
	rfile=({});
	for(i=0;i<2*X+1;i++)
	{
		m[i]=allocate(2*Y+1);
		for(j=0;j<2*Y+1;j++)
			m[i][j]=" ";
	}

	where=environment(me);
	if(!objectp(where))
		return notify_fail("对不起，不知道你到底在哪里呀！找巫师吧！\n");

	draw_room((2*X+1)/2,(2*Y+1)/2,where);

	for(l=0,linef=1;l<2*Y+1;l++)
	{
		for(n=0;n<2*X+1;n++)
		{
			if( m[n][l]!=" ")
				p++;
		}
		if(!p && linef)
		{
			lineu++;
			linef=1;
		}
		else linef=0;
		p=0;
	}
	for(l=2*Y,linef=1;l>=0;l--)
	{
		for(n=0;n<2*X+1;n++)
		{
			if( m[n][l]!=" ")
				p++;
		}
		if(!p && linef)
		{
			lined++;
			linef=1;
		}
		else linef=0;
		p=0;
	}

	for(i=lineu;i<2*Y+1-lined;i++)
	{
		for(j=0;j<2*X+1;j++)
		{
			if( m[j][i]==" " && i%2 && j%2 )
				tmp+="        ";
			else
			{
				//如果此项为空，并且此时j为偶数列，则输出空格
				if( m[j][i]==" " && !(j%2) )
					tmp+="  ";
				else
				{
					if( m[j][i]==" " )
						tmp+="        ";
					else
						tmp+=m[j][i];
				}
			}
		}
		tmp+=ZJBR;
	}
	text=explode(tmp, ZJBR);
	for(i=k; k<sizeof(text); k++) {

		line += (text[k] + ZJBR);
	}
	
	line += (HIC"温磬提示："ZJBR+HIG"\t亮绿色的代表你目前所处房间"+ZJBR+HIY"\t黄色的代表有不规则出口的房间"NOR);
	write(line+"\n");
//	//log_files("d/a1", sprintf("%s\n",line));
	
	me->set_temp("maphere_time", time() + 3);
	return 1;
}

object find_room(string path)
{
	object ob;
	if( objectp(ob=find_object(path)) || objectp(ob=load_object(path)) )
		return ob;
	return 0;
}

//←↑→↓↖↗↘↙
int draw_path(int x,int y,string direc)
{
	string str;
	int xx=0,yy=0;
	switch(direc)
	{
		case "south":
		case "north":              	str="   ｜   ";	break;
		case "southdown":          str="   ↓   ";	break;
		case "northup":           	str="   ↑   ";	break;
		case "southup":            	str="   ↑   ";	break;
		case "northdown":          str="   ↓   ";	break;
		case "east":
		case "west":               	str="—";		break;
		case "eastdown":
		case "eastup":             	str="→";		break;
		case "westdown":
		case "westup":             	str="←";		break;           
		case "southeast":
		case "northwest":          	str="＼";		break;
		case "southwest":
		case "northeast":          	str="／";		break;
		default:
			return 0;
	}
	if(sscanf(direc,"%*ssouth%*s"))
		yy++;
	if(sscanf(direc,"%*snorth%*s"))
		yy--;
	if(sscanf(direc,"%*seast%*s"))
		xx++;
	if(sscanf(direc,"%*swest%*s"))
		xx--;
	if( x+xx<=0 || y+yy<=0 || x+xx>=2*X || y+yy>=2*Y )
		return 0;
	m[x+xx][y+yy]=HIW+str+NOR;
	return 1;
}

// 改用广度遍历寻路算法,使地图的显示更加合理
int draw_room(int x,int y,object room)
{
	int i,xx,yy;
	int front,rear;
	string *dirs;
	object froom,nroom;
	mapping dir,x_y;
	object *queue;
	front=0;rear=0;

	queue=allocate( (2*X+1)*(2*Y+1) );
	reset_eval_cost();
	if( x<0 || y<0 || !objectp(room) || x>2*X || y>2*Y )
		return 0;

	rfile=rfile + ({ base_name(room) });
	queue[rear]=room;
	set_room(x,y,room);
	set_x_y(x,y,rear);
	rear++;

        while( front < rear )
        {
                reset_eval_cost();
                froom=queue[front];
                x_y=data[front];
                front++;
                if( !objectp(froom) ) return 0;
        		dir=froom->query("exits");
                if( !mapp(dir) || sizeof(dir)<1 )
                        return 0;
                dirs=keys(dir);
                for(i=0;i<sizeof(dirs);i++)
                {
                        nroom=find_room(dir[dirs[i]]);
                        if(!objectp(nroom) || member_array(base_name(nroom),rfile)!=-1)
                                continue;
                        xx=0;yy=0;
                        if( sscanf(dirs[i],"%*ssouth%*s"))
                                yy+=2;
                        if( sscanf(dirs[i],"%*snorth%*s"))
                                yy-=2;
                        if( sscanf(dirs[i],"%*seast%*s"))
                                xx+=2;
                        if( sscanf(dirs[i],"%*swest%*s"))
                                xx-=2;
                        if( x_y["xst"]+xx<0 || x_y["yst"]+yy<0 || x_y["xst"]+xx>2*X || x_y["yst"]+yy>2*Y )
                                continue;
                        if( m[x_y["xst"]+xx][x_y["yst"]+yy]!=" ")
                                continue;
                        if( !draw_path(x_y["xst"],x_y["yst"],dirs[i]) || (xx==0&&yy==0))
                                continue;
                        rfile=rfile + ({ base_name(nroom) });
                        queue[rear]=nroom;
                        set_room(x_y["xst"]+xx,x_y["yst"]+yy,nroom);
                        set_x_y(x_y["xst"]+xx,x_y["yst"]+yy,rear);
                        rear++;
                }
        }
}

void set_room(int x,int y,object room)
{
	int i,d,xx,yy,flag;
	string name;
	mapping dir;
	string *dirs;

	// 求取无颜色的房间short描述
	name = clean_color(room->query("short"));
    //name =ZJURL("cmds:walk")+"点击";
	// 房间的短名字最好在4个汉字以内
	if(strlen(name)>8)  name=name[0..7];

	if(strlen(name)<7) //对不足4个汉字的房间名进行居中处理
	{
		d=8-strlen(name);
		if( d%2 )
		{
			name+=" ";
			d--;
		}
		for(i=0;i<d/2;i++)
			name=" "+name+" ";
	}

	dir=room->query("exits");
    
	if( !mapp(dir) || sizeof(dir)<1 ) 
	{
		flag=1;
	}
	else
	{
		dirs=keys(dir);
		for(i=0;i<sizeof(dirs);i++)
		{
			xx=0;yy=0;
			if( sscanf(dirs[i],"%*ssouth%*s"))
				yy+=2;
			if( sscanf(dirs[i],"%*snorth%*s"))
				yy-=2;
			if( sscanf(dirs[i],"%*seast%*s"))
				xx+=2;
			if( sscanf(dirs[i],"%*swest%*s"))
				xx-=2;
			if( xx==0 && yy==0 )
				flag=1;
		}
	}

	if((x==(2*X+1)/2)&&(y==(2*Y+1)/2))
		name=HBBLU+HIG+name;
	else if( flag )
		name=HIY+name;
		
		name+=NOR;
	//name = ZJURL("cmds:walk "+no_color(room->short()))+name+NOR;
	m[x][y] = name;
}

void set_x_y(int x,int y,int rear)
{
	data[rear]=([
		"xst":x,
		"yst":y,
	]);
}

int help(object me)
{
       write(@HELP
指令格式：maphere [-m]

本命令帮助玩家了解周围的房间地图的分布状况，并标志出房间之间的连接情况。
连接标志中箭头所指方向地势更高，有不规范出口的房间以黄色标志，你所处的
房间以蓝底亮绿色来标志！由于房间可能重叠的缘故，有些房间将无法显示出来。
本命令默认以x=7,y=14 的地图大小显示，使用-m选项将以最大化x=11,y=22 显示。
HELP);
       return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
