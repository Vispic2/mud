// atoi.c
/*
mixed max_s(mixed arr)
{
mixed i,max;
foreach(i in arr){
i=to_int(i);
if(max<i)
max=i;
}
return max;
}
mixed min_s(mixed arr)
{
mixed i,min;
min=max_s(arr);
foreach(i in arr){
i=to_int(i);
if(min>i)
min=i;
}
return min;
}
*/
int atoi(string str)
{
	int v;

	if( !stringp(str) || !sscanf(str, "%d", v) ) return 0;
	return v;
}
/*
int time()
{
	return 28800+efun::time();
}
*/
int rand2(int seed,int lv)
{
	int k,m,n;

	k = pow(seed,lv);
	m = random(k);
	n = to_int(pow(k,1.0/lv)-pow(m,1.0/lv));
	return n;
}
/* *
* 同一周判断函数
* by luoyun 2016.12.9
*/
int same_week(int time1, int time2)
{
	int last, now;
	int week;
	int year_day1;
	int year_day2;
	
	if (!time1 && !time2)
		return 1;
	else
	/*取周一时间对比是否同一周*/
	if (localtime(time1)[7] != localtime(time2)[7]) {//不是同一天
		if (time1) {
			week = localtime(time1)[6];//上次是周几？
			if (week == 0)
				week = 7;
               /*反算周一是一年中的第几天*/
			now = time1 -week *86400;
			year_day1 = localtime(now)[7];
		}
		if (time2) {
			week = localtime(time2)[6];
			if (week == 0)
				week = 7;
			last = time2 -week *86400;
			year_day2 = localtime(last)[7];
		}
          /*周一是一年中的第几天对比判断*/
		if (year_day1 == year_day2)//同一周
			return 1;
		else
			return 0;
	} else
		return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
