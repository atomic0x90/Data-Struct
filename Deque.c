#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node* previous;
	struct Node* next;
}Node;

typedef struct Deque
{
	Node* front;
	Node* rear;
}Deque;

Deque* Create_Deque()
{
	Deque* deque;

	deque = (Deque*)malloc(sizeof(Deque));
	deque->front = NULL;
	deque->rear = NULL;

	return deque;
}

void Push_Front_Deque(Deque *q,int data)
{
	Node* push_node = (Node*)malloc(sizeof(Node));
	push_node->previous = NULL;
	push_node->next = NULL;
	push_node->value = data;

	if(q->front == NULL)
	{
		q->front = push_node;
		q->rear = push_node;

		return;
	}
	else
	{
		push_node->next = q->front;
		q->front->previous = push_node;
		q->front = push_node;

		return;
	}
}

void Push_Rear_Deque(Deque *q,int data)
{
	Node* push_node = (Node*)malloc(sizeof(Node));
	push_node->previous = NULL;
	push_node->next = NULL;
	push_node->value = data;

	if(q->rear == NULL)
	{
		q->front = push_node;
		q->rear = push_node;

		return;
	}
	else
	{
		push_node->previous = q->rear;
		q->rear->next = push_node;
		q->rear = push_node;

		return;
	}
}

int Pop_Front_Deque(Deque *q)
{
	if(q->front == NULL)
		return 0;
	
	int pop_data;

	Node* temp = q->front;
	pop_data = temp->value;

	if(q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		q->front = temp->next;
		q->front->previous = NULL;
	}

	free(temp);

	return pop_data;
}

int Pop_Rear_Deque(Deque *q)
{
	if(q->rear == NULL)
		return 0;

	int pop_data;

	Node* temp = q->rear;
	pop_data = temp->value;

	if(q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		q->rear = temp->previous;
		q->rear->next = NULL;
	}

	free(temp);

	return pop_data;
}

int Search_Number(Deque *q,int data)
{
	if(q->front == NULL)
		return 0;

	Node* temp = q->front;

	while(1)
	{
		if(temp->value != data)
		{
			if(temp->next == NULL)
				return 0;

			temp = temp->next;
		}
		else
			return temp->value;
	}
}

void Print_Deque(Deque *q)
{
	if(q->front == NULL)
		return;

	Node* temp = q->front;

	while(1)
	{
		printf("%d ",temp->value);
		if(temp->next == NULL)
			break;
		temp = temp->next;
	}
}

void Initialization_Deque(Deque *q)
{
	q->front = NULL;
	q->rear = NULL;
	
	return;
}

void Peek_Front_Deque(Deque *q)
{
	if(q->front == NULL)
		printf("Deque is empty\n");
	else
		printf("Deque Front data -> %d\n",q->front->value);

	return;
}

void Peek_Rear_Deque(Deque *q)
{
	if(q->rear == NULL)
		printf("Deque is empty\n");
	else
		printf("Deque Rear data -> %d\n",q->rear->value);

	return;
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
	printf("\t7.Deque Initialization\t8.Peek Front Deque\n");
	printf("\t9.Peek Rear Deque\t0.Exit Program\n");
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
		printf("Deqeue is empty...(Not POP)\n");

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
		printf("Deque is empty...(Not POP)\n");

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

void peek_front_screen(Deque *q)
{
	Peek_Front_Deque(q);

	return;
}

void peek_rear_screen(Deque *q)
{
	Peek_Rear_Deque(q);

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

		else if(num == 3)	//Push Number(rear)
			push_rear_screen(deque);

		else if(num == 4)	//Pop Number(rear)
			pop_rear_screen(deque);

		else if(num == 5)	//Search Number
			search_screen(deque);

		else if(num == 6)	//Print Deque
			print_screen(deque);

		else if(num == 7)	//Deque Initialization
			initialization_screen(deque);
		
		else if(num == 8)	//Peek Front
			peek_front_screen(deque);

		else if(num == 9)	//Peek Rear
			peek_rear_screen(deque);

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
