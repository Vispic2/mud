//有英文字母返回 1 没有则0
int is_az(mixed str)
{
string i;
string *arr=({
"q","w","e","r","t","y","u","i","o","p","a","s","d","f","j","k","l","z","x","c","v","n","n","m",
});
if(!str)
return 0;
foreach(i in arr){
if(i==str) return 1;
}
return 0;
}
string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}
/*
int is_chinese(string str)
{
	int i;

	if (strlen(str) < 2 || strlen(str) % 2) return 0;

	for (i = 0; i < strlen(str); i += 2)
	{
		if (str[i] < 176 || str[i] >= 248) return 0;
		if (str[i + 1] < 161 || str[i + 1] == 255) return 0;
	}

	return 1;
}
*/
/*
int is_chinese(string str)
{
	int i;

	if (strlen(str) < 3 || strlen(str) % 3) return 0;

	for (i = 0; i < strlen(str); i += 3)
	{
		if (str[i] < 176 || str[i] >= 248) return 0;
		if (str[i + 1] < 128 || str[i + 1] == 255) return 0;
	}

	return 1;
}

*/
 int is_chinese(string str)
  {
      if (!str)
          return 0;

      return pcre_match(str, "^\\p{Han}+$");
  }
string cntime(int t)
{
	mixed *r;
	string *months = ({"01","02","03","04","05","06","07","08","09","10","11","12"});
	
	r = localtime(t);
	return sprintf("%d-%s-%02d %02d:%02d:%02d",
		r[5], 
		months[r[4]], 
		r[3], 
		r[2],
		r[1], 
		r[0]);
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
