#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *link;
}Node;

typedef struct Queue
{
}Queue;

Queue* Create_Queue()
{
	Queue* queue;
	queue = (Queue*)malloc(sizeof(Queue));
	return queue;
}
void Push_Queue(Queue *s,int data)
{
}

int Pop_Queue(Queue *s)
{
}

int Search_Number(Queue *s,int data)
{
}

void Print_Queue(Queue *s)
{
}

void Initialization_Queue(Queue *s)
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
	printf("\t5.Queue Initialization\t0.Exit Program\n");
	printf("-------------------------------------------------------------\n");

	scanf("%d",&num);
	getchar();

	return num;
}

void push_screen(Queue *s)
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

	Push_Queue(s,num);
	printf("Successfully Push ! ! !\n");

	return;
}

void pop_screen(Queue *s)
{
	int check_NULL = Pop_Queue(s);
	
	if(check_NULL != 0)
	{
		printf("Successfully pop ! ! !\n");
		printf("Pop result : %d\n",check_NULL);
	}
	else
		printf("Queue is NULL...(Not POP)\n");

	return;
}

void search_screen(Queue *s)
{
	int num,check_search;

	printf("\nPlease enter a number to search Queue\n");
	
	scanf("%d",&num);
	getchar();

	check_search = Search_Number(s,num);

	if(check_search != 0)
		printf("Successfully searched! (search number = %d)\n",check_search);
	else
		printf("This number does not exist Queue...\n");

	return;
}

void print_screen(Queue *s)
{
	printf("\nPrint Queue---------------\n");
	Print_Queue(s);
	printf("front<--------------->rear\n\n");

	return;
}

void initialization_screen(Queue *s)
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
			Initialization_Queue(s);
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
	printf("\tPlease enter a number in the range (0 ~ 5)\n");
	printf("---------------------------------------------------------\n");
	
	return;
}

int main()
{
	int num;
	char answer;

	Queue *queue;
	queue = Create_Queue();
	while(1)
	{
		num = menu_screen();
		
		if(num == 1)	//Push Number
			push_screen(queue);

		else if(num == 2)	//Pop Number
			pop_screen(queue);

		else if(num == 3)	//Search Number
			search_screen(queue);

		else if(num == 4)	//Print Queue
			print_screen(queue);

		else if(num == 5)	//Queue Initialization
			initialization_screen(queue);

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
