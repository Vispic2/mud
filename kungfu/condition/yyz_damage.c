//Cracked by Kafei
// by oyxb
// by acep

#include <ansi.h>
string* xuedao = ({
        "巨骨穴",
        "地仓穴",
        "肩井穴",
        "颊车穴",
        "承泣穴",
        "风池穴",
        "章门穴",
        "风府穴",
        "精促穴",
        "陶道穴",
        "强间穴",
        "少海穴",
        "犊鼻穴",
        "神门穴",
        "华盖穴",
        "大椎穴",
        "凤尾穴",
        "至阳穴",
        "劳宫穴",
        "百会穴",
        "灵台穴",
        "太阳穴",
        "膻中穴",
        "命门穴",
        "鸠尾穴",
        "三阴交",
        "天柱穴"
});


int update_condition(object me, int duration)
{
	object ob;
   if( duration < 1 ) return 0;
	if (!living(me)) {
		message("vision", me->name() + "闷哼了一声。\n", environment(me), me);
	}
		tell_object(me,HIR"你感到"+xuedao[random(sizeof(xuedao))]+"一阵酸麻，血气不畅，顿时动弹不得！\n"NOR);
  if( !me->is_busy() )
{ 
		me->start_busy(5);
}
                me->receive_damage("qi", duration*2 );
                me->receive_wound("qi", duration*2);
      me->apply_condition("yyz_damage", duration - 1);
      if( duration < 1 ) return 0;
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
