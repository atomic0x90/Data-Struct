#include <stdio.h>
#include <stdlib.h>


void Push_Queue(int data)
{
}

int Pop_Queue()
{
}

int Search_Number(int data)
{
}
void Print_Queue()
{
}

void Initialization_Queue()
{
}

void Peek_Front_Queue()
{
}

void Peek_Rear_Queue()
{
}

int menu_screen()
{
	int num;

	printf("-------------------------------------------------------------\n");
	printf("\t\t-------------------------\n");
	printf("\t\t       Linear Queue\n");
	printf("\t\t-------------------------\n\n");

	printf("\t\tPlease select an activity\n");
	printf("\t\t--Please enter a number--\n\n");

	printf("\t1.Push Number\t\t2.Pop Number\n");
	printf("\t3.Search Number\t\t4.Print Queue\n");
	printf("\t5.Queue Initialization\t6.Peek Front Queue\n");
	printf("\t7.Peek Rear Queue\t0.Exit Program\n");
	printf("-------------------------------------------------------------\n");

	scanf("%d",&num);
	getchar();

	return num;
}

void push_screen()
{
	int num;

	for(;;)
	{
		printf("\nPlease enter a number to push into the Queue\n");
		printf("The range of numbers is a positive integer\n");

		scanf("%d",&num);
		getchar();

		if(num < 1)
			printf("Please check the range of numbers ! ! !\n\n");
		else
			break;
	}

	Push_Queue(num);
	printf("Successfully Push ! ! !\n");

	return;
}

void pop_screen()
{
	int check_NULL = Pop_Queue();
	
	if(check_NULL != 0)
	{
		printf("Successfully pop ! ! !\n");
		printf("Pop result : %d\n",check_NULL);
	}
	else
		printf("Queue is NULL...(Not POP)\n");

	return;
}

void search_screen()
{
	int num,check_search;

	printf("\nPlease enter a number to search Queue\n");
	
	scanf("%d",&num);
	getchar();

	check_search = Search_Number(num);

	if(check_search != 0)
		printf("Successfully searched! (search number = %d)\n",check_search);
	else
		printf("This number does not exist Queue...\n");

	return;
}

void print_screen()
{
	printf("\nPrint Queue---------------\n");
	Print_Queue();
	printf("\nfront<--------------->rear\n\n");

	return;
}

void initialization_screen()
{
	char answer;
	for(;;)
	{
		printf("Are you sure you want to INITIALIZATION QUEUE?\n");
		printf("\tPlease answer y/n\n");

		scanf("%c",&answer);
		getchar();

		if(answer == 'y' || answer == 'Y')
		{
			Initialization_Queue();
			printf("Successfully initialized Queue!\n");
			break;
		}
		else if(answer == 'n' || answer == 'N')
		{
			printf("Not initialized Queue\n");
			break;
		}
		else
			printf("Please enter y or n\n\n");
	}

	return;
}

void peek_front_screen()
{
	Peek_Front_Queue();

	return;
}

void peek_rear_screen()
{
	Peek_Rear_Queue();

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

	while(1)
	{
		num = menu_screen();
		
		if(num == 1)	//Push Number
			push_screen();

		else if(num == 2)	//Pop Number
			pop_screen();

		else if(num == 3)	//Search Number
			search_screen();

		else if(num == 4)	//Print Queue
			print_screen();

		else if(num == 5)	//Queue Initialization
			initialization_screen();

		else if(num == 6)	//Peek front Queue
			peek_front_screen();

		else if(num == 7)	//Peek rear Queue
			peek_rear_screen();

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
