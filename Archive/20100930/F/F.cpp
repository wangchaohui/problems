#include <stdio.h>

int R[2][12]={
31,28,31,30,31,30,31,31,30,31,30,31,
31,29,31,30,31,30,31,31,30,31,30,31,
};

int isleap(int year)
{
	return year%4==0 && (year%100 || year%400==0);
}

void nextday(int &year,int &month,int &day)
{
	int L=isleap(year);
	day++;
	if(day>R[L][month-1])
	{
		day=1;
		month++;
		if(month>12)
		{
			month=1;
			year++;
		}
	}
}

char *zodiac(int month,int day)
{
	switch(month)
	{
	case 1:
		if(day<=20)return "capricorn";
		return "aquarius";
		break;
	case 2:
		if(day<=19)return "aquarius";
		return "pisces";
		break;
	case 3:
		if(day<=20)return "pisces";
		return "aries";
		break;
	case 4:
		if(day<=20)return "aries";
		return "taurus";
		break;
	case 5:
		if(day<=21)return "taurus";
		return "gemini";
		break;
	case 6:
		if(day<=21)return "gemini";
		return "cancer";
		break;
	case 7:
		if(day<=22)return "cancer";
		return "leo";
		break;
	case 8:
		if(day<=21)return "leo";
		return "virgo";
		break;
	case 9:
		if(day<=23)return "virgo";
		return "libra";
		break;
	case 10:
		if(day<=23)return "libra";
		return "scorpio";
		break;
	case 11:
		if(day<=22)return "scorpio";
		return "sagittarius";
		break;
	case 12:
		if(day<=22)return "sagittarius";
		return "capricorn";
		break;
	}
}

int main()
{
	int T,C=0,year,month,day,i;
	scanf("%d",&T);
	while(++C<=T)
	{
		scanf("%2d%2d%4d",&month,&day,&year);
		for(i=0;i<280;i++)nextday(year,month,day);
		printf("%d %02d/%02d/%04d %s\n",C,month,day,year,zodiac(month,day));
	}
	return 0;
}