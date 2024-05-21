#include<stdio.h>
#include<math.h>
bool judge(int n)
{
	for (int i = 2; i <n; i++)
	{
		if (!(n % i))
			return 0;
	}
	return 1;
}
int main()
{
	int i, n, count = 0;
	double s = 0;
	scanf_s("%d", &n);
	for (i = 2;; i++)
	{
		if (judge(i))
		{
			s += 1.0 / i;
			count++;
		}
		if (count == n)
			break;
	}
	printf("%lf", s);
	return 0;
}
