1.
#include <stdio.h>
int main()
{
	int x = 1;
	int y = -1;
	int z = !--x - !++y;
 
	z += x += y;
 
	printf("%d%d%d", x, y, z);
 
	return 0;
}
------------------------------------------------------------------
2.
#include <stdio.h>
int main()
{
	int x = 10;
	int y = 20;

	int a = x+++y;

	printf("%d\n", -x + y + a);
}
------------------------------------------------------------------
3.
#include <stdio.h>
int main()
{
	int x = 999;

	printf("%d\n", printf("%d", printf("%d", ++x)));
}
------------------------------------------------------------------
4.
#include <stdio.h>
int main()
{
	int x, y, z;

	x = 2, y = 1, z = 0;
	x = x && y || z;
	printf("%d\n", x);

	printf("%d\n", x || !y && z);

	x = y = 1;
	z = x++ - 1;
	printf("%d\n", x);
	printf("%d\n", z);

	z += -x++ + ++y;
	printf("%d\n", x);
	printf("%d\n", z);

	return 0;
}
------------------------------------------------------------------
5.
#include <stdio.h>
int main()
{
	int x = 2, y, z;

	x *= 3 + 2;
	printf("%d\n", x);

	x *= y = z = 4;
	printf("%d\n", x);

	x = y == z;
	printf("%d\n", x);

	x == (y = z);
	printf("%d\n", x);
}
------------------------------------------------------------------
6.
#include <stdio.h>
int main()
{
	int x = -3 + 4 * 5 - 6;

	printf("%d\n", x);

	x = 3 + 4 % 5 - 6;

	printf("%d\n", x);

	x = -3 * 4 % -6 / 5;

	printf("%d\n", x);

	x = (7 + 6) % 5 / 2;

	printf("%d\n", x);
}
------------------------------------------------------------------
7.
#include <stdio.h>
int main()
{
	int a = 0;

	if (-1 < a-- < 0)
		printf("%d", --a);
	else
		printf("%d", ++a);
}
------------------------------------------------------------------
8.
#include <stdio.h>
int main()
{
	int x = 1;

	if (++x > 2,5)
		printf("%d", ++x);
	else
		printf("%d", x++);
}
------------------------------------------------------------------
9.
#include <stdio.h>
void func(int x)
{
	++x;
	printf("%d", x);
}

int main()
{
	int x = 10;

	func(++x);
	func(x++);

	printf("%d", x);
}
------------------------------------------------------------------
10.
#include<stdio.h>
int main()
{
	int num = 30;
	int ival = (num > 5 ? num <= 10 ? 10 : 20 : 50);

	printf("%d\n", ival);
}
