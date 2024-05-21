//找出第一个字符串在第二个字符串中出现的位置，输出这些位置，如果找不到，则输出-1
#include<stdio.h>
#include<math.h>
int main(void)
{
	int i, j,k = 0,len_a = strlen(a),len_b = strlen(b);
	int out[10000];
	char a[10000], b[10000];
	printf("请输入字符串a[]\n");
	gets(a);
	printf("请输入字符串b[]\n");
	gets(b);
	for (i = 0; i < len_b; i++)
	{
		if (b[i] == a[0])
		{
			int flag_b = i+1;
			int flag_a = 1;
			while (flag_a < len_a)
			{
				if (b[flag_b++] == a[flag_a]) {

				}
			}
		}
		else
		{
			printf("-1");
		}
	}
	printf("%s", out);
	return 0;
}