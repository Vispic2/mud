// updateall.c
#include <ansi.h>

#define GUIG	   "/adm/daemons/tuiguangd"

void more_str(string tab, string str, int line, int page)
{
	int i,j,all;
	string show,*text;

	show = tab;
	text = explode(str,"\n");
	all = sizeof(text)/line;
	if(sizeof(text)%line) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*line;
	i = page*line;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;

	show += sprintf("你下线玩家及赞助获赠(%d/%d页)：\n",page,all); 
	show += ZJOBACTS2+ZJMENUF(2,2,9,32);
	show += "上一页:tuig xj "+(page-1)+ZJSEP"下一页:tuig xj "+(page+1)+ZJSEP;
	show += implode(text[j..i], ZJSEP);
	write(show+"\n");
}

int main(object me, string arg)
{
	string pops,com,code;
	string meid = me->query("id");
	string mycode;
	string mysj;
	string *lists;
	string str="";
	int myyb=0,ljby=0;
	int page,i;
	object sj;
	object obj;
	mapping list;
	
	if(!arg){
		
		if(! GUIG->my_code(me)){
			GUIG->create_code(me);
		}		
		
		pops= ZJOBLONG"推广系统管理面板："+ZJURL("cmds:tuig ?")+HIG"【查看推广系统说明】"NOR""NOR""+ZJBR+ZJBR;

		if(stringp(mysj = GUIG->my_shangj(me))){
			if(objectp(sj=find_player(mysj))){
				pops += "我的上家是："+ sj->name()+"（"+mysj+"）"+ZJBR+ZJBR;
			}else{
				pops += "我的上家是："+ mysj+" (未在线)"+ZJBR+ZJBR;
			}
		}
		
		if(stringp(mycode = GUIG->my_code(me))){
		if(me->query("web"))
		pops += "我的推广码："+ ESC"[u:tel:"+mycode+"]"+mycode+NOR+HIY" [点击复制]"+ZJBR+NOR+ZJBR;
		else
		pops += "我的推广码："+ mycode+ZJBR+NOR+ZJBR;
		}else{
			pops += "我的推广码：无"+ZJBR+ZJBR;
		}

		ljby=GUIG->getallby(me);
		pops += "累计共获赠："+ ljby+" 元宝"+ZJBR+ZJBR;
		
		myyb=GUIG->my_yuanbao(me);
		pops += "当前元宝池："+ myyb+" 元宝"+ZJBR+ZJBR;
	
		
		
		pops+="\n";
		
		pops+=ZJOBACTS2+ZJMENUF(2,2,10,30);
		
		if(myyb>0){
			pops += "领取池中元宝:tuig lq" + ZJSEP; 
		}	
		
		if(stringp(mysj)){
			if(objectp(sj)) pops += "查看我的上家:look "+ mysj + ZJSEP;
		}else{
			pops += "提交上家推广码:tuig tj" + ZJSEP; 
		}	
		
		pops += "查看我的下家:tuig xj 1" + "\n"; 
		
		write(pops);		
		
		return 1;
	}
	if(sscanf(arg,"%s %s", com, code) == 2){
		if(com == "tj"){
			GUIG->tijiao_code(me,code);
		}else if(com == "setbl"){
			if (! SECURITY_D->valid_grant(me, "(admin)"))
				return 0;
			
			GUIG->setbl(to_int(code));
			tell_object(me,HIY"你已设置推广系统充值提成比例为："+code+"%\n即下家充值100元，上家获赠 "+code+" 枚元宝。"NOR"\n");
		}else if(com == "xj"){
			if(mapp(list=GUIG->getxj(me))){
				if(sizeof(lists=keys(list)))
				{
					for(i=0;i<sizeof(lists);i++)
					{
						obj = find_player(lists[i]);
						if(obj){
							str += sprintf("%s (%s)"ZJBR+HIY"赞助获赠：%d 元宝"NOR":look %s\n",obj->query("name"),lists[i],list[lists[i]], lists[i]);
						}else{
							str += sprintf("未在线 (%s)"ZJBR+HIY"赞助获赠：%d 元宝"NOR":look %s\n",lists[i],list[lists[i]], lists[i]);
						}
					}
				}
				more_str(ZJOBLONG, str, 10, to_int(code));
			}else{
				tell_object(me,HIR"你目前还没有下线玩家。"NOR"\n");
			}
		}
		return 1;
	}else{
		if(arg == "tj"){
			write(INPUTTXT("提交你上家给你的推广码（可获赠元宝）："+ZJBR+"注意：一个id终身只能提交一次推广码，即便是删号重建后也无法再次提交推广码，也无法获赠元宝。","tuig tj $txt#")+"\n");
		}else if(arg == "lq"){
			GUIG->lingqu(me);
		}else if(arg == "?"){
pops= ZJOBLONG+"推广系统说明："+ZJBR+ZJBR+
"1、推广系统是为了提升本游戏人气，鼓励老玩家招募新玩家的一种方式，即老玩家可发展多个新玩家作为自己的下线玩家，当下线玩家赞助后，上家就可以获赠一定比例的元宝。"+ZJBR+ZJBR+
"2、玩家首次打开推广系统管理面板就会得到一个属于自己的推广码，将此推广码提供给新玩家，新玩家进入游戏提交此推广码后，这个新玩家就成为了你的下线玩家了。"+ZJBR+ZJBR+
"3、即便你是新玩家系统也会免费赠送一个推广码给你，新玩家也可以用推广码来发展自己的下线玩家。"+ZJBR+ZJBR+
"4、当你的下线玩家赞助后，系统会按赞助金额的多少按比例奖励你一定数量的元宝，奖励的元宝会存入你的推广元宝池中，池中的元宝你可随时领取。"+ZJBR+ZJBR+
"5、当你的下线玩家赞助的时候，不管你自己在没在游戏中，奖励的元宝都会存入你的推广元宝池中，当你上线之后即可领取。"+ZJBR+ZJBR+
"6、如果你发展的下线玩家越多，那么你获得的元宝奖励就会越多，因为下线玩家越多赞助就可能越多，固然你获得的元宝奖励就会越多。"+ZJBR+ZJBR+
"7、玩家得到了自己的推广码后，那么这个玩家就会终身拥有这个推广码，即便是删号重建人物也不会消失，此推广码终身有效。"+ZJBR+ZJBR+
"8、当B玩家成功提交了A玩家的推广码之后，那么B玩家终身都是A玩家的的下线玩家，即便是AB双方都删号重建人物也改变不了他们之间的上下线关系。"+ZJBR+ZJBR+
"9、玩家不能提交自己的推广码，即不能自己推广自己成为自己的下线，也不能提交自己下线玩家的推广码，即上下线不能相互推广。\n";
			write(pops);
		}
	}
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
