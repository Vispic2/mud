//by name 2021.5.28
//qq 3468713544 
//刺杀任务
#include <ansi.h>
inherit F_CLEAN_UP;
string generate_information(object knower, object who, string topic);
int main(object me, object arg)
{
if(!arg){
write(generate_information(me,me,"消息")+"\n");
}else{
write("执行结果："+arg+"\n");
me->set_temp("last_asked_quest",arg);
write(generate_information(me,me,me->query_temp("last_asked_quest")->name())+"\n");
}
return 1;
}
string generate_information(object knower, object who, string topic)
{
	mapping total;
	object *obs;
	object *dest;
	string name, title;
	object last_ob;
	mixed answer;
	string msg;

	total = QUEST_D->query("information");
    if (! mapp(total))
	return "当前系统没有任何任务。\n";
	
	
	if (topic == "rumor" || topic == "消息")
	{
	obs = keys(total);
	obs = filter_array(obs, (: objectp($1) :));
	if (! sizeof(obs))
	return "当前系统没有任何任务。\n";
	
		msg=ZJOBLONG+"目前有以下任务：\n";
		msg+=ZJOBACTS2+ZJMENUF(1,1,9,31);
		foreach(last_ob in obs){
		msg+=last_ob->name()+":quest_renwu "+last_ob+""+ZJSEP;
		}
		write(msg+"\n");
		return "目前任务：";
		if (answer = last_ob->query_prompt(knower, who))
		return answer;	
	}

	if (! mapp(total))
		return 0;

    obs = keys(total);
	obs = filter_array(obs, (: objectp($1) :));

	// 查看是否问某一个任务的某一个条目
	if (sscanf(topic, "%s.%s", name, title) == 2)
	{
		dest = filter_array(obs, (: $1->name() == $(name) :));
		if (! sizeof(dest))
			return 0;

		last_ob = dest[0];
	} else
	{
		// 查看是否问某一个任务
		dest = filter_array(obs, (: $1->name() == $(topic) :));
		if (sizeof(dest) > 0)
		{
			last_ob = dest[0];
			knower->set_temp("last_asked_quest", last_ob);
			answer = last_ob->query_introduce(knower, who);
			if (stringp(answer))
				return answer;
			return "你说的是" HIY + knower->name() +
			       HIY "那件事情吗？你问我算是问对人了。" NOR;
		} else
		// 查看最后一次被询问的任务消息中是否有该条目
		{
			last_ob = knower->query_temp("last_asked_quest");
			if (! objectp(last_ob) || ! mapp(total[last_ob]))
				return 0;

			title = topic;
		}
	}

	// 返回有关某个任务的某个条目的消息
	knower->set_temp("last_asked_quest", last_ob);
	answer = total[last_ob];

	if (! mapp(answer))
		return 0;

	// 这个任务登记了具体的信息
	answer = answer[title];
	if (functionp(answer))
		return evaluate(answer, knower, who, topic);

	if (stringp(answer))
		return answer;

	return 0;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
