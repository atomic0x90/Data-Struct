#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *link;
}Node;

typedef struct Queue
{
	Node *front;
	Node *rear;
}Queue;

Queue* Create_Queue()
{
	Queue* queue;
	queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	
	return queue;
}

void Push_Queue(Queue *q,int data)
{
	Node *push_node = (Node*)malloc(sizeof(Node));

	push_node->value = data;
	push_node->link = NULL;

	if(q->front == NULL)
	{
		q->front = push_node;
		q->rear = push_node;
	}
	else
	{
		push_node->link = q->front;
		q->front = push_node;
	}

	return;
}

int Pop_Queue(Queue *q)
{
	if(q->front == NULL)
		return 0;
	
	int pop_data;

	Node *pop_node = q->front;

	if(q->front == q->rear)
	{
		pop_data = q->front->value;
	
		q->front = NULL;
		q->rear = NULL;
	
		free(pop_node);
	
		return pop_data;
	}
	else
	{
		while(pop_node->link != q->rear)
			pop_node = pop_node->link;

		q->rear = pop_node;
		pop_node = pop_node->link;

		pop_data = pop_node->value;

		q->rear->link = NULL;

		free(pop_node);

		return pop_data;
	}
}

int Search_Number(Queue *q,int data)
{
	if(q->front == NULL)
		return 0;

	Node *temp = q->front;

	while(1)
	{
		if(temp->value != data)
		{
			if(temp->link == NULL)
				return 0;
			else
				temp = temp->link;
		}
		else if(temp->value == data)
			return temp->value;
	}
}

void Print_Queue(Queue *q)
{
	if(q->front == NULL)
		return;

	Node *temp = q->front;

	while(1)
	{
		printf("%d ",temp->value);
		
		if(temp->link == NULL)
			break;
		temp = temp->link;
	}

	return;
}

void Initialization_Queue(Queue *q)
{
	q->front = NULL;
	q->rear = NULL;

	return;
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
	printf("\nfront<--------------->rear\n\n");

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
