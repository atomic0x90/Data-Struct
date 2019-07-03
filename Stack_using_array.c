#include <stdio.h>


int check_size,top;

int stack_size_setting()
{
	for(;;)
	{
		printf("-------------------------------------------------------------\n");
		printf("\t    Please enter the size of the Stack\n");
		printf("\tThe range of numbers is a positive integer\n");
		printf("-------------------------------------------------------------\n");

		scanf("%d",&check_size);
		getchar();

		if(check_size < 1)
			printf("Please check the range of numbers ! ! !\n\n");
		else
			break;

	}
	top = 0;

	printf("Successfully Stack size setting ! ! !\n");

	return check_size;
}

void Push_Stack(int *stack,int data)
{
	if(top == check_size)
		printf("Stack is PULL !\n(Not Push)\n");
	else
	{
		stack[top] = data;
		top++;
		printf("Successfully Push !\n");
	}

	return;
}

int Pop_Stack()
{
}

int Search_Number(int data)
{
}
void Print_Stack(int *stack)
{
	if(top != 0)
	{
		for(int i = top-1;i >= 0;i--)
			printf("%d\n",stack[i]);
	}
	else
		printf("Stack is NULL\n");
	return;
}

void Initialization_Stack()
{
}

void Peek_Stack()
{
}

int menu_screen()
{
	int num;

	printf("-------------------------------------------------------------\n");
	printf("\t\t-------------------------\n");
	printf("\t\t\t  Stack\n");
	printf("\t\t-------------------------\n\n");

	printf("\t\tPlease select an activity\n");
	printf("\t\t--Please enter a number--\n\n");

	printf("\t1.Push Number\t\t2.Pop Number\n");
	printf("\t3.Search Number\t\t4.Print Stack\n");
	printf("\t5.Stack Initialization\t6.Peek Stack\n");
	printf("\t0.Exit Program\n");
	printf("-------------------------------------------------------------\n");

	scanf("%d",&num);
	getchar();

	return num;
}

void push_screen(int *stack)
{
	int num;

	for(;;)
	{
		printf("\nPlease enter a number to push into the Stack\n");
		printf("The range of numbers is a positive integer\n");

		scanf("%d",&num);
		getchar();

		if(num < 1)
			printf("Please check the range of numbers ! ! !\n\n");
		else
			break;
	}

	Push_Stack(stack,num);

	return;
}

void pop_screen()
{
	int check_NULL = Pop_Stack();
	
	if(check_NULL != 0)
	{
		printf("Successfully pop ! ! !\n");
		printf("Pop result : %d\n",check_NULL);
	}
	else
		printf("Stack is NULL...(Not POP)\n");

	return;
}

void search_screen()
{
	int num,check_search;

	printf("\nPlease enter a number to search Stack\n");
	
	scanf("%d",&num);
	getchar();

	check_search = Search_Number(num);

	if(check_search != 0)
		printf("Successfully searched! (search number = %d)\n",check_search);
	else
		printf("This number does not exist Stack...\n");

	return;
}

void print_screen(int *stack)
{
	printf("\nPrint Stack----\ntop\n\n");
	Print_Stack(stack);
	printf("\nbottom\n---------------\n\n");

	return;
}

void initialization_screen()
{
	char answer;
	for(;;)
	{
		printf("Are you sure you want to INITIALIZATION STACK?\n");
		printf("\tPlease answer y/n\n");

		scanf("%c",&answer);
		getchar();

		if(answer == 'y' || answer == 'Y')
		{
			Initialization_Stack();
			printf("Successfully initialized Stack!\n");
			break;
		}
		else if(answer == 'n' || answer == 'N')
		{
			printf("Not initialized Stack\n");
			break;
		}
		else
			printf("Please enter y or n\n\n");
	}

	return;
}

void peek_screen()
{
	Peek_Stack();

	return;
}


char exit_screen()
{
	char answer;

	for(;;)
	{
		printf("Are you sure you want to EIXT PROGRAM?\n");
		printf("\tPlease answer y/n\n");
		
		scanf("%c",&answer);
		getchar();
		
		if(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
			break;
		else
			printf("Please enter y or n\n\n");
	}

	if(answer == 'y' || answer == 'Y')
	{
		printf("--------------------------------------------------------\n");
		printf("\t\tThank you for using it ! ! !\n");
		printf("--------------------------------------------------------\n");
	}

	return answer;
}

void error_screen()
{
	printf("---------------------------------------------------------\n");
	printf("\tPlease enter a number (non-character)\n");
	printf("\tPlease enter a number in the range (0 ~ 6)\n");
	printf("---------------------------------------------------------\n");
	
	return;
}

int main()
{
	int num;
	char answer;

	num = stack_size_setting();
	int stack[num];

	while(1)
	{
		num = menu_screen();
		
		if(num == 1)	//Push Number
			push_screen(stack);

		else if(num == 2)	//Pop Number
			pop_screen();

		else if(num == 3)	//Search Number
			search_screen();

		else if(num == 4)	//Print Stack
			print_screen(stack);

		else if(num == 5)	//Stack Initialization
			initialization_screen();

		else if(num == 6)	//Peek Stack
			peek_screen();

		else if(num == 0)	//Exit Program
		{
			answer = exit_screen();
			if(answer == 'y' || answer == 'Y')
				break;
			else
				continue;
		}
		else		//Enter a charater, not number OR out of range
			error_screen();
	}
	return 0;
}
