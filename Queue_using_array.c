#include <stdio.h>

int front,rear,check_size;

void Push_Queue(int *q,int data)
{
	if(rear == check_size)
		printf("Queue is PULL !\n(Not Push)\n");
	else
	{
		q[rear] = data;
		rear++;
		printf("Successfully Push !\n");
	}

	return;
}

int Pop_Queue(int *q)
{
	int pop_data;

	if(rear == front)
		return 0;
	else
	{
		pop_data = q[front];
		rear--;

		for(int i = 0; i < rear; i++)
			q[i] = q[i+1];


		return pop_data;
	}
}

int Search_Number(int *q,int data)
{
	if(rear == front)
		return 0;
	for(int i = 0; i < rear; i++)
	{
		if(q[i] == data)
			return q[i];
	}

	return 0;
}

void Print_Queue(int *q)
{
	if(rear == front)
		printf("Queue is empty !");
	else
	{
		for(int i = rear-1 ; i >= 0 ; i--)
			printf("%d ",q[i]);
	}

	return;
}

void Initialization_Queue()
{
}

int Peek_Front_Queue(int *q)
{
	if(rear == front)
		return 0;
	else
		return q[rear-1];

}

int Peek_Rear_Queue(int *q)
{
	if(rear == front)
		return 0;
	else 
		return q[0];
}

int queue_size_setting()
{
	for(;;)
	{
		printf("-------------------------------------------------------------\n");
		printf("\t    Please enter the size of the Queue\n");
		printf("\tThe range of numbers is a positive integer\n");
		printf("-------------------------------------------------------------\n");

		scanf("%d",&check_size);
		getchar();

		if(check_size < 1)
			printf("Please check the range of numbers ! ! !\n\n");
		else
			break;
	}
	front = rear = 0;

	printf("Successfully Queue size setting ! ! !\n");

	return check_size;
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

void push_screen(int *q)
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

	Push_Queue(q,num);

	return;
}

void pop_screen(int *q)
{
	int check_NULL = Pop_Queue(q);
	
	if(check_NULL != 0)
	{
		printf("Successfully pop ! ! !\n");
		printf("Pop result : %d\n",check_NULL);
	}
	else
		printf("Queue is empty...(Not POP)\n");

	return;
}

void search_screen(int *q)
{
	int num,check_search;

	printf("\nPlease enter a number to search Queue\n");
	
	scanf("%d",&num);
	getchar();

	check_search = Search_Number(q,num);

	if(check_search != 0)
		printf("Successfully searched! (search number = %d)\n",check_search);
	else
		printf("This number does not exist Queue...\n");

	return;
}

void print_screen(int *q)
{
	printf("\nPrint Queue---------------\n");
	Print_Queue(q);
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

void peek_front_screen(int *q)
{
	int num = Peek_Front_Queue(q);

	if(num == 0)
		printf("Queue is empty\n");
	else
		printf("front of Queue is %d\n",num);

	return;
}

void peek_rear_screen(int *q)
{
	int num = Peek_Rear_Queue(q);

	if(num == 0)
		printf("Queue is empty\n");
	else
		printf("rear of Queue is %d\n",num);

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

	num = queue_size_setting();	//Queue size set
	int queue[num];

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
			initialization_screen();

		else if(num == 6)	//Peek front Queue
			peek_front_screen(queue);

		else if(num == 7)	//Peek rear Queue
			peek_rear_screen(queue);

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
