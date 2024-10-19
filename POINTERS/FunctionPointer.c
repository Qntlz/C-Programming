#include <stdio.h>

// More Advance Pointer Utilization

// EXAMPLE 1:  
// A normal function with an int parameter
// and void return type
void fun(int a)
{
	printf("Value of a is %d\n", a);
}

int main()
{
	void (*fun_ptr)(int) = fun; // & removed

	fun_ptr(10); // * removed

	return 0;
}

// EXAMPLE 2:
/* Function pointer can be used in place of switch case. 
For example, in below program, user is asked for a choice between 0 and 2 to do different tasks*/

void add(int a, int b)
{
	printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
	printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
	printf("Multiplication is %d\n", a*b);
}

int main()
{
	// fun_ptr_arr is an array of function pointers
	void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	unsigned int ch, a = 15, b = 10;

	printf("Enter Choice: 0 for add, 1 for subtract and 2 "
			"for multiply\n");
	scanf("%d", &ch);

	if (ch > 2) return 0;

	(*fun_ptr_arr[ch])(a, b);

	return 0;
}