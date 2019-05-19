#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* link;
}Node;

Node* head = NULL;

Node* Insert_Number(Node* head,int data)
{
	if(head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->link = NULL;
		head->value = data;

		return head;
	}
	else
	{
		Node* tail = (Node*)malloc(sizeof(Node));
		Node* New = (Node*)malloc(sizeof(Node));
		tail = head;
		New->value = data;
		New->link = NULL;
		while(tail->link != NULL)
			tail = tail->link;
		tail->link = New;
		return head;
	}
}

Node* Delete_Number(Node* head,int data)
{
	if(head == NULL)
		return NULL;

	Node* temp1 = (Node*)malloc(sizeof(Node));
	Node* temp2 = (Node*)malloc(sizeof(Node));
	temp1 = temp2 = head;

	if(head->value == data && head->link == NULL)
		return NULL;
	else if(head->value == data && head->link != NULL)
	{
		head = head->link;
		return head;
	}
	
	temp2 = temp2->link;
	
	while(temp2->value != data)
	{
		temp1 = temp1->link;
		temp2 = temp2->link;
	}
	
	if(temp2->link != NULL)
		temp1->link = temp2->link;
	else
		temp1->link = NULL;

	free(temp2);
	return head;
}

void Sort_Ascending_Order(Node* head)
{

	if(head == NULL)
		return;
	int temp_data,check_length = 1;
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1 = head;

	if(head->link == NULL)
		return;
	else
	{
		while(temp1->link != NULL)
		{
			check_length++;
			temp1 = temp1->link;
		}
		temp1 = head;
		while(check_length)
		{
			while(temp1->link != NULL)
			{
				if(temp1->value > temp1->link->value && temp1->link != NULL)
				{
					temp_data = temp1->value;
					temp1->value = temp1->link->value;
					temp1->link->value = temp_data;
				}
				if(temp1->link == NULL)
					break;
				temp1 = temp1->link;
			}
			temp1 = head;
			check_length--;
		}

	}
}

void Sort_Descending_Order(Node* head)
{
	if(head == NULL)
		return;
	int temp_data,check_length = 1;
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1 = head;

	if(head->link == NULL)
		return;
	else
	{
		while(temp1->link != NULL)
		{
			check_length++;
			temp1 = temp1->link;
		}
		temp1 = head;
		while(check_length)
		{
			while(temp1->link != NULL)
			{
				if(temp1->value < temp1->link->value && temp1->link != NULL)
				{
					temp_data = temp1->value;
					temp1->value = temp1->link->value;
					temp1->link->value = temp_data;
				}
				if(temp1->link == NULL)
					break;
				temp1 = temp1->link;
			}
			temp1 = head;
			check_length--;
		}
	}
}
int Search_Number(Node* head,int data)
{
	if(head == NULL)
		return 0;
	while(1)
	{
		if(head->value != data && head->link != NULL)
			head = head->link;
		else if(head->value != data && head->link == NULL)
			return 0;
		else if(head->value == data)
			return head->value;
	}
	return 0;
}

void Print_List(Node* head)
{
	if(head == NULL)
	{
		printf("List is NULL...");
		return;
	}
	while(head != NULL)
	{
		printf("%d ",head->value);
		head = head->link;
	}
}
int main()
{
	int num1,num2,check_duplicated;
	char answer;
	while(1)
	{
		printf("-------------------------------------------------------------\n");
		printf("\t\t-------------------------\n");
		printf("\t\t    Singly_Linked_List\n");
		printf("\t\t-------------------------\n\n");
			
		printf("\t\tPlease select an activity\n");
		printf("\t\t--Please enter a number--\n\n");
	
		printf("\t1.Insert Number\t\t2.Delete Number\n");
		printf("\t3.Search Number\t\t4.Print List\n");
		printf("\t5.List Initialization\t6.Sort Ascending Order\n");
		printf("\t7.Sort Descending Order\t0.Exit Program\n");
		printf("-------------------------------------------------------------\n");
		
		scanf("%d",&num1);
		getchar();

		if(num1 == 1)	//Insert Number
		{
			for(;;)
			{
				printf("\nPlease enter a number to insert into the Singly Linked List\n");
				printf("The range of numbers is a positive integer\n");
				scanf("%d",&num2);
				getchar();
				
				if(num2 < 1)
					printf("Please check the range of numbers ! ! !\n\n");
				else
					break;
			}
			check_duplicated = Search_Number(head,num2);
			
			if(check_duplicated == 0)
			{
				head = Insert_Number(head,num2);
				printf("Successfully inserted ! ! !\n");
			}
			else
				printf("The number entered already exists..! (Not Inserted...)\n");

		}
		else if(num1 == 2)	//Delete Number
		{
			printf("\nPlease enter a number to delete the Singly Linked List\n");

			scanf("%d",&num2);
			getchar();

			check_duplicated = Search_Number(head,num2);

			if(check_duplicated != 0)
			{
				head = Delete_Number(head,num2);
				printf("Successfully deleted ! ! !\n");
			}
			else
				printf("This number does not exist Linked List...\n");
		}
		else if(num1 == 3)	//Search Number
		{
			printf("\nPlease enter a number to search Linked List\n");

			scanf("%d",&num2);
			getchar();

			if(Search_Number(head,num2))
				printf("Successfully searched! (search number = %d)\n",num2);
			else
				printf("This number doese not exist Linked List...\n");
		}
		else if(num1 == 4)	//Print List
		{
			printf("Print Linked List------------------------------------\n");
			Print_List(head);
			printf("\n-----------------------------------------------------\n\n");
		}
		else if(num1 == 5)	//List Initialization
		{
			for(;;)
			{
				printf("Are you sure you want to INITIALIZATION LIST?\n");
				printf("\tPlease answer y/n\n");

				scanf("%c",&answer);
				getchar();

				if(answer == 'y' || answer == 'Y')
				{
					head = NULL;
					printf("Successfully initialized List!\n");
					break;
				}
				else if(answer == 'n' || answer == 'N')
				{
					printf("Not initialized List\n");
					break;
				}
				else
					printf("Please enter y or n\n\n");
			}
		}
		else if(num1 == 6)	//Sort Ascending Order
		{
			Sort_Ascending_Order(head);
			printf("Successfully Sort Ascending Order!\n");
		}
		else if(num1 == 7)	//Sort Descengin Order
		{
			Sort_Descending_Order(head);
			printf("Successfully Sort Descending Order!\n");
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
		else		//Enter a charater,not number OR out of range
		{
			printf("---------------------------------------------------------\n");
			printf("\tPlease enter a number (non-character)\n");
			printf("\tPlease enter a number in the range (0 ~ 7)\n");
			printf("---------------------------------------------------------\n");
		}
	}
	return 0;
}
