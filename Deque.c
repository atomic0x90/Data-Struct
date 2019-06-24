#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
}Node;

typedef struct Deque
{
}Deque;

Deque* Create_Deque()
{
}
void Push_Front_Deque(Deque *q,int data)
{
}
void Push_Rear_Deque(Deque *q,int data)
{
}
int Pop_Front_Deque(Deque *q)
{
}
int Pop_Rear_Deque(Deque *q)
{
}

int Search_Number(Deque *q,int data)
{
}

void Print_Deque(Deque *q)
{
}

void Initialization_Deque(Deque *q)
{
}

int menu_screen()
{
	int num;

	printf("-------------------------------------------------------------\n");
	printf("\t\t-------------------------\n");
	printf("\t\t\t  Deque\n");
	printf("\t\t-------------------------\n\n");

	printf("\t\tPlease select an activity\n");
	printf("\t\t--Please enter a number--\n\n");

	printf("\t1.Push Number(front)\t2.Pop Number(front)\n");
	printf("\t3.Push Number(rear)\t4.Pop Number(rear)\n");
	printf("\t5.Search Number\t\t6.Print Deque\n");
	printf("\t7.Deque Initialization\t0.Exit Program\n");
	printf("-------------------------------------------------------------\n");

	scanf("%d",&num);
	getchar();

	return num;
}

void push_front_screen(Deque *q)
{
	int num;

	for(;;)
	{
		printf("\nPlease enter a number to push into the Deque\n");
		printf("The range of numbers is a positive integer\n");

		scanf("%d",&num);
		getchar();

		if(num < 1)
			printf("Please check the range of numbers ! ! !\n\n");
		else
			break;
	}

	Push_Front_Deque(q,num);
	printf("Successfully Push(front) ! ! !\n");

	return;
}

void push_rear_screen(Deque *q)
{
	int num;

	for(;;)
	{
		printf("\nPlease enter a number to push into the Deque\n");
		printf("The range of numbers is a positive integer\n");

		scanf("%d",&num);
		getchar();

		if(num < 1)
			printf("Please check the range of numbers ! ! !\n\n");
		else
			break;
	}

	Push_Rear_Deque(q,num);
	printf("Successfully Push(rear) ! ! !\n");

	return;
}

void pop_front_screen(Deque *q)
{
	int check_NULL = Pop_Front_Deque(q);
	
	if(check_NULL != 0)
	{
		printf("Successfully pop(front) ! ! !\n");
		printf("Pop result : %d\n",check_NULL);
	}
	else
		printf("Deqeue is NULL...(Not POP)\n");

	return;
}

void pop_rear_screen(Deque *q)
{
	int check_NULL = Pop_Rear_Deque(q);

	if(check_NULL != 0)
	{
		printf("Successfully pop(rear) ! ! !\n");
		printf("Pop result : %d\n",check_NULL);
	}
	else
		printf("Deque is NULL...(Not POP)\n");

	return;
}

void search_screen(Deque *q)
{
	int num,check_search;

	printf("\nPlease enter a number to search Deque\n");
	
	scanf("%d",&num);
	getchar();

	check_search = Search_Number(q,num);

	if(check_search != 0)
		printf("Successfully searched! (search number = %d)\n",check_search);
	else
		printf("This number does not exist Deque...\n");

	return;
}

void print_screen(Deque *q)
{
	printf("\nPrint Deque---------------\n");
	Print_Deque(q);
	printf("\nfront<--------------->rear\n\n");

	return;
}

void initialization_screen(Deque *q)
{
	char answer;
	for(;;)
	{
		printf("Are you sure you want to INITIALIZATION DEQUE?\n");
		printf("\tPlease answer y/n\n");

		scanf("%c",&answer);
		getchar();

		if(answer == 'y' || answer == 'Y')
		{
			Initialization_Deque(q);
			printf("Successfully initialized Deque!\n");
			break;
		}
		else if(answer == 'n' || answer == 'N')
		{
			printf("Not initialized Deque\n");
			break;
		}
		else
			printf("Please enter y or n\n\n");
	}

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
	printf("\tPlease enter a number in the range (0 ~ 7)\n");
	printf("---------------------------------------------------------\n");
	
	return;
}

int main()
{
	int num;
	char answer;

	Deque *deque;
	deque = Create_Deque();
	while(1)
	{
		num = menu_screen();
		
		if(num == 1)	//Push Number(front)
			push_front_screen(deque);

		else if(num == 2)	//Pop Number(front)
			pop_front_screen(deque);

		else if(num == 3)
			push_rear_screen(deque);

		else if(num == 4)
			pop_rear_screen(deque);

		else if(num == 5)	//Search Number
			search_screen(deque);

		else if(num == 6)	//Print Queue
			print_screen(deque);

		else if(num == 7)	//Queue Initialization
			initialization_screen(deque);

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
