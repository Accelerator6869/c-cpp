#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct Date
{
	int year, month, day;
}Date;
typedef struct Person
{
	long id;
	char name[20];
	Date vdate[3];//3次接种疫苗的日期
}Person;
int read(Person* ps, const char* fname)
{
	int i = 0;
	FILE* fp;
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("source file error\n");
		exit(1);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%d%d%d%d%d%d%d%d%d", &ps[i].id, &ps[i].name,&ps[i].vdate[0].year, &ps[i].vdate[0].month,&ps[i].vdate[0].day,  &ps[i].vdate[1].year, &ps[i].vdate[1].month, &ps[i].vdate[1].day,&ps[i].vdate[2].year, &ps[i].vdate[2].month, &ps[i].vdate[2].day);
		i++;
	}
	return i;
}
int search(Person* ps, int n, long id)
{
	for (int i = 0; i < n; i++)
	{
		if (id == ps[i].id)
			return i;
	}
	return -1;
}
void vaccination(Person* ps, int k, Date cdate)//cdate是当前日期
{
	int i=0;
	int d1 = 21 - days(cdate, ps[k].vdate[1]);
	int d2= 180 - days(cdate, ps[k].vdate[2]);
	while (ps[k].vdate[i].year)
		i++;             //i即为接种次数
	switch (i)
	{
	case 0:printf("您可接种第1针");
		break;
	case 1://第一针接种过
		if (days(cdate, ps[k].vdate[1]) >= 21)
			printf("您可接种第2针");
		else
			printf("您今天还不能接种第2针，请您%d天后再来", &d1);
		break;
	case 2:if (days(cdate, ps[k].vdate[2]) >= 180)
		printf("您可接种第3针");
		  else
		printf("您今天还不能接种第3针，请您%d天后再来", &d2);
		break;
	case 3:printf("您已完成全程接种");
		break;
	}
}
int days(Date cdate, Date vdate)//cdate是当前日期，vdate是过去日期
{
	int differenceInDays;
		differenceInDays = (cdate.year - vdate.year) * 365 + (cdate.month - vdate.month) * 30 + (cdate.day - vdate.day);
	return differenceInDays;
}
int main(){
	Person ps[500];
	long id = 0;
	int n, k;
	Date cdate = { 2022,5,24 };
	n = read(ps, "E:\\vs code\\records.txt");
	while (id != -999)
	{
		printf("请输入人员编号：");
		scanf("%d", &id);
		k = search(ps, n, id);
		if (k < 0)continue;
		printf("%s: ", ps[k].name);
		vaccination(ps, k, cdate);
	}
	return 0;
}