#include<stdio.h>
#include<string.h>
int check(char* s)
{
	int l = 0, r = 0;
	while (*s != '\0') 
	{
		if (*s == '(')
			l++;
		else if (*s == ')') 
		{
			r++;
			if (r>l)
				return 0;
		}
		if (l == r)return 1;
	}
	return 0;
}
int main()
{
	char c[80];
	int d;
	printf("input a string:");
	gets_s(c);
	d = check(c);
	printf("%s", d ? "yes" : "no");
}