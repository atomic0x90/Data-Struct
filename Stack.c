#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *link;
}Node;

typedef struct Stack
{
	Node *top;
}Stack;

Stack* Create_Stack()
{
	Stack* stack;
	stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}
void Push_Stack(Stack *s,int data)
{
	Node *push_node = (Node*)malloc(sizeof(Node));

	push_node->value = data;
	push_node->link = s->top;
	s->top = push_node;
}
/*
void Print_Stack(Stack *s)
{
	if(s->top == NULL)
		return;

	Stack *temp = s->top;
	while(1)
	{
		printf("%d\n",temp->top->value);
		if(temp->top->link == NULL)
			break;
		temp->top = temp->top->link;
	}
}
*/
int main()
{
	int num1,num2;
	char answer;

	Stack *stack;
	stack = Create_Stack();
	while(1)
	{
		printf("-------------------------------------------------------------\n");
		printf("\t\t-------------------------\n");
		printf("\t\t\t  Stack\n");
		printf("\t\t-------------------------\n\n");
		
		printf("\t\tPlease select an activity\n");
		printf("\t\t--Please enter a number--\n\n");
		
		printf("\t1.Push Number\t\t2.Pop Number\n");
		printf("\t3.Search Number\t\t4.Print Stack\n");
		printf("\t5.Stack Initialization\t0.Exit Program\n");
		printf("-------------------------------------------------------------\n");

		scanf("%d",&num1);
		getchar();
		
		if(num1 == 1)	//Push Number
		{
			for(;;)
			{
				printf("\nPlease enter a number to push into the Stack\n");
				printf("The range of numbers is a positibe integer\n");
			
				scanf("%d",&num2);
				getchar();

				if(num2 < 1)
					printf("Pleae check the range of numbers ! ! !\n\n");
				else
					break;
			}
			
			Push_Stack(stack,num2);
			printf("Successfully Push ! ! !\n");
		}
		else if(num1 == 2)	//Pop Number
		{
			printf("\nPlease enter a number to pop the Stack\n");

			scanf("%d",&num2);
			getchar();

			printf("Successfully pop ! ! !\n");
		}
		else if(num1 == 3)	//Search Number
		{
			printf("\nPlease enter a number to search Stack\n");

			scanf("%d",&num2);
			getchar();


		}
		else if(num1 == 4)	//Print Stack
		{
			printf("Print Stack----\n");
//			Print_Stack(stack);
			printf("\n---------------\n\n");
		}
		else if(num1 == 5)	//Stack Initialization
		{
			for(;;)
			{
				printf("Are you sure you want to INITIALIZATION STACK?\n");
				printf("\tPlease answer y/n\n");

				scanf("%c",&answer);
				getchar();

				if(answer == 'y' || answer == 'Y')
				{

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
		}
		else if(num1 == 0)	//Exit Program
		{
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
				break;
			}
			else
				continue;
		}
		else		//Enter a charater, not number OR out of range
		{
			printf("---------------------------------------------------------\n");
			printf("\tPlease enter a number (non-character)\n");
			printf("\tPlease enter a number in the range (0 ~ 5)\n");
			printf("---------------------------------------------------------\n");
		}

	}
	return 0;
}