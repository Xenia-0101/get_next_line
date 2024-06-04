
#include <stdio.h>
/*
A static int variable remains in memory while the program is
running. A normal or auto variable is destroyed when a
function call where the variable was declared is over.

Static variables are allocated memory in the data segment,
not the stack segment.

Static variables (like global variables) are initialized
as 0 if not initialized explicitly.
*/

int counter(void)
{
	static int count;
	count++;
	printf("%d\n", count);
	return (count);
}

void increase(int *num)
{
	(*num)++;
}

int main(void)
{
	counter();
	counter();
	counter();

	static int num;
	printf("init: %d\n", num);

	increase(&num);
	increase(&num);
	increase(&num);
	printf("final: %d\n", num);

	return (0);
}
