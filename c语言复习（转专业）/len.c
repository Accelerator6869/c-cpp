#include<stdio.h>
#include<string.h>
int length(const char *a)
{
	int n=0,idx=0;
	//while (*a!= '\0')
	while(a[idx]!='0')
	{
		n++;
		//a++;
		idx++;
	}
	return n;
}
int main()
{
	char a[] = "hello";
	printf("%d\n",strlen(a));
	printf("%d\n",length(a));
	return 0;
}