//�ҳ���һ���ַ����ڵڶ����ַ����г��ֵ�λ�ã������Щλ�ã�����Ҳ����������-1
#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
	int i,j,k=0,l,idx;
	int d[100];
	char a[10000],  b[10000], c[10000];
	//char * a={"\0"}, * b = { "\0" }, * temp = { "\0" }, * c = { "\0" };
	printf("�������ַ���a[]\n");
	gets(a);
	printf("�������ַ���b[]\n");
	gets(b);
	for (i = 0; i < strlen(b); i++)
	{
		if (b[i] == a[1])
		{
			for (j = 0; j < strlen(a); j++)
			{
				idx = i;
				c[j] = b[idx];
				idx++;
			}
			if (strcmp(c, a) == 0)
			{
				d[k] = i;
				k++;
			}
			free(c);
		}
	}
	if (k > 0) {
		for (l = 0; l<k; l++)
			printf("%d ", d[l]);
	}
	else
		printf("-1");
	return 0;
}