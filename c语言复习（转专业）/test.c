//�ҳ���һ���ַ����ڵڶ����ַ����г��ֵ�λ�ã������Щλ�ã�����Ҳ����������-1
#include<stdio.h>
#include<math.h>
int main(void)
{
	int i, j,k = 0,len_a = strlen(a),len_b = strlen(b);
	int out[10000];
	char a[10000], b[10000];
	printf("�������ַ���a[]\n");
	gets(a);
	printf("�������ַ���b[]\n");
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