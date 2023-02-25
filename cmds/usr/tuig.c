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

	show += sprintf("��������Ҽ���������(%d/%dҳ)��\n",page,all); 
	show += ZJOBACTS2+ZJMENUF(2,2,9,32);
	show += "��һҳ:tuig xj "+(page-1)+ZJSEP"��һҳ:tuig xj "+(page+1)+ZJSEP;
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
		
		pops= ZJOBLONG"�ƹ�ϵͳ������壺"+ZJURL("cmds:tuig ?")+HIG"���鿴�ƹ�ϵͳ˵����"NOR""NOR""+ZJBR+ZJBR;

		if(stringp(mysj = GUIG->my_shangj(me))){
			if(objectp(sj=find_player(mysj))){
				pops += "�ҵ��ϼ��ǣ�"+ sj->name()+"��"+mysj+"��"+ZJBR+ZJBR;
			}else{
				pops += "�ҵ��ϼ��ǣ�"+ mysj+" (δ����)"+ZJBR+ZJBR;
			}
		}
		
		if(stringp(mycode = GUIG->my_code(me))){
		if(me->query("web"))
		pops += "�ҵ��ƹ��룺"+ ESC"[u:tel:"+mycode+"]"+mycode+NOR+HIY" [�������]"+ZJBR+NOR+ZJBR;
		else
		pops += "�ҵ��ƹ��룺"+ mycode+ZJBR+NOR+ZJBR;
		}else{
			pops += "�ҵ��ƹ��룺��"+ZJBR+ZJBR;
		}

		ljby=GUIG->getallby(me);
		pops += "�ۼƹ�������"+ ljby+" Ԫ��"+ZJBR+ZJBR;
		
		myyb=GUIG->my_yuanbao(me);
		pops += "��ǰԪ���أ�"+ myyb+" Ԫ��"+ZJBR+ZJBR;
	
		
		
		pops+="\n";
		
		pops+=ZJOBACTS2+ZJMENUF(2,2,10,30);
		
		if(myyb>0){
			pops += "��ȡ����Ԫ��:tuig lq" + ZJSEP; 
		}	
		
		if(stringp(mysj)){
			if(objectp(sj)) pops += "�鿴�ҵ��ϼ�:look "+ mysj + ZJSEP;
		}else{
			pops += "�ύ�ϼ��ƹ���:tuig tj" + ZJSEP; 
		}	
		
		pops += "�鿴�ҵ��¼�:tuig xj 1" + "\n"; 
		
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
			tell_object(me,HIY"���������ƹ�ϵͳ��ֵ��ɱ���Ϊ��"+code+"%\n���¼ҳ�ֵ100Ԫ���ϼһ��� "+code+" öԪ����"NOR"\n");
		}else if(com == "xj"){
			if(mapp(list=GUIG->getxj(me))){
				if(sizeof(lists=keys(list)))
				{
					for(i=0;i<sizeof(lists);i++)
					{
						obj = find_player(lists[i]);
						if(obj){
							str += sprintf("%s (%s)"ZJBR+HIY"����������%d Ԫ��"NOR":look %s\n",obj->query("name"),lists[i],list[lists[i]], lists[i]);
						}else{
							str += sprintf("δ���� (%s)"ZJBR+HIY"����������%d Ԫ��"NOR":look %s\n",lists[i],list[lists[i]], lists[i]);
						}
					}
				}
				more_str(ZJOBLONG, str, 10, to_int(code));
			}else{
				tell_object(me,HIR"��Ŀǰ��û��������ҡ�"NOR"\n");
			}
		}
		return 1;
	}else{
		if(arg == "tj"){
			write(INPUTTXT("�ύ���ϼҸ�����ƹ��루�ɻ���Ԫ������"+ZJBR+"ע�⣺һ��id����ֻ���ύһ���ƹ��룬������ɾ���ؽ���Ҳ�޷��ٴ��ύ�ƹ��룬Ҳ�޷�����Ԫ����","tuig tj $txt#")+"\n");
		}else if(arg == "lq"){
			GUIG->lingqu(me);
		}else if(arg == "?"){
pops= ZJOBLONG+"�ƹ�ϵͳ˵����"+ZJBR+ZJBR+
"1���ƹ�ϵͳ��Ϊ����������Ϸ�����������������ļ����ҵ�һ�ַ�ʽ��������ҿɷ�չ����������Ϊ�Լ���������ң�����������������ϼҾͿ��Ի���һ��������Ԫ����"+ZJBR+ZJBR+
"2������״δ��ƹ�ϵͳ�������ͻ�õ�һ�������Լ����ƹ��룬�����ƹ����ṩ������ң�����ҽ�����Ϸ�ύ���ƹ�����������Ҿͳ�Ϊ�������������ˡ�"+ZJBR+ZJBR+
"3���������������ϵͳҲ���������һ���ƹ�����㣬�����Ҳ�������ƹ�������չ�Լ���������ҡ�"+ZJBR+ZJBR+
"4��������������������ϵͳ�ᰴ�������Ķ��ٰ�����������һ��������Ԫ����������Ԫ�����������ƹ�Ԫ�����У����е�Ԫ�������ʱ��ȡ��"+ZJBR+ZJBR+
"5��������������������ʱ�򣬲������Լ���û����Ϸ�У�������Ԫ�������������ƹ�Ԫ�����У���������֮�󼴿���ȡ��"+ZJBR+ZJBR+
"6������㷢չ���������Խ�࣬��ô���õ�Ԫ�������ͻ�Խ�࣬��Ϊ�������Խ�������Ϳ���Խ�࣬��Ȼ���õ�Ԫ�������ͻ�Խ�ࡣ"+ZJBR+ZJBR+
"7����ҵõ����Լ����ƹ������ô�����Ҿͻ�����ӵ������ƹ��룬������ɾ���ؽ�����Ҳ������ʧ�����ƹ���������Ч��"+ZJBR+ZJBR+
"8����B��ҳɹ��ύ��A��ҵ��ƹ���֮����ôB���������A��ҵĵ�������ң�������AB˫����ɾ���ؽ�����Ҳ�ı䲻������֮��������߹�ϵ��"+ZJBR+ZJBR+
"9����Ҳ����ύ�Լ����ƹ��룬�������Լ��ƹ��Լ���Ϊ�Լ������ߣ�Ҳ�����ύ�Լ�������ҵ��ƹ��룬�������߲����໥�ƹ㡣\n";
			write(pops);
		}
	}
	return 1;
}

/*
BY��NAME
QQ��3468713544
DATE��2 0 2 2 . 0 2 . 0 3
*/
