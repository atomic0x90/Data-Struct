#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct
{
	int value;
	struct NodeStruct* left;
	struct NodeStruct* right;
}Node;

Node* root = NULL;
int Search_Number(Node* root,int data)
{
	if(root == NULL)
		return 0;
	
	if(root->value == data)
		return root->value;

	else if(root->value > data)
		return Search_Number(root->left,data);

	else if(root->value < data)
		return Search_Number(root->right,data);
}

Node* Min_Node(Node* root)
{
	Node* Temp_Node = root;
	while(Temp_Node->left != NULL)
		Temp_Node = Temp_Node->left;
	return Temp_Node;
}

Node* Insert_Number(Node* root,int data)
{
	if(root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->value = data;

		return root;
	}
	else
	{
		if(root->value > data)
			root->left = Insert_Number(root->left,data);

		else if(root->value < data)
			root->right = Insert_Number(root->right,data);

	}

	return root;
}

Node* Delete_Number(Node* root,int data)
{
	if(root == NULL)
		return NULL;
	Node* TempNode = NULL;

	if(root->value > data)
		root->left = Delete_Number(root->left,data);

	else if(root->value < data)
		root->right = Delete_Number(root->right,data);

	else
	{
		if(root->right == NULL && root->left == NULL)
		{
			root = NULL;
			return root;
		}
		else if(root->right != NULL && root->left != NULL)
		{
			TempNode = Min_Node(root->right);
			root->value = TempNode->value;
			root->right = Delete_Number(root->right,TempNode->value);
		}
		else if(root->right != NULL && root->left == NULL)
		{
			root = root->right;
			return root;
		}
		else if(root->right == NULL && root->left != NULL)
		{
			root = root->left;
			return root;
		}
	}

	return root;
}

void Print_BST_Preorder(Node* root)
{
	if(root == NULL)
		return;

	printf("%d ",root->value);
	Print_BST_Preorder(root->left);
	Print_BST_Preorder(root->right);
}
void Print_BST_Inorder(Node* root)
{
	if(root == NULL)
		return;

	Print_BST_Inorder(root->left);
	printf("%d ",root->value);
	Print_BST_Inorder(root->right);
}
void Print_BST_Postorder(Node* root)
{
	if(root == NULL)
		return;

	Print_BST_Postorder(root->left);
	Print_BST_Postorder(root->right);
	printf("%d ",root->value);
}
int main()
{
	int num;
	int enter_number,check_duplicated;
	char answer;

	for(;;)
	{

		printf("-------------------------------------------------------------\n");
		printf("\t\t-------------------------\n");
		printf("\t\t   Binary_Search_Tree\n");
		printf("\t\t-------------------------\n\n");

		printf("\t\tPlease select an activity\n");
		printf("\t\t--Please enter a number--\n\n");
		
		printf("\t1.Insert Number\t\t2.Delete Number\n");
		printf("\t3.Search Number\t\t4.Print BST Preorder\n");
		printf("\t5.Print BST Inorder\t6.Print BST Postorder\n");
		printf("\t7.BST Initialization\t8.Exit Program\n");
		printf("-------------------------------------------------------------\n");

		scanf("%d",&num);
		getchar();

		if(num == 1)	//Insert Number
		{
			for(;;)
			{
				printf("\nPlease enter a number to insert into the BST\n");
				printf("The range of numbers is a positive integer\n");
				scanf("%d",&enter_number);
				getchar();

				if(enter_number < 1)
					printf("Please check the range of numbers\n\n");
				else
					break;
			}
			check_duplicated = Search_Number(root,enter_number);
			
			if(check_duplicated == 0)
			{
				root = Insert_Number(root,enter_number);
				printf("Successfully inserted ! ! !\n");
			}
			else
				printf("The number entered already exists..! (Not Inserted...)\n");
		}
		else if(num == 2)	//Delete Number
		{
			printf("\nPlease enter a number to delete the BST\n");

			scanf("%d",&enter_number);
			getchar();

			check_duplicated = Search_Number(root,enter_number);
			if(check_duplicated != 0)
			{
				root = Delete_Number(root,enter_number);
				printf("Successfully deleted ! ! !\n");
			}
			else
				printf("This number does not exist BST...\n");
		}
		else if(num == 3)	//Search Number
		{
			printf("\nPlease enter a number to search BST\n");

			scanf("%d",&enter_number);
			getchar();

			check_duplicated = Search_Number(root,enter_number);

			if(check_duplicated != 0)
				printf("Successfully searched! (search number = %d)\n",enter_number);
			else
				printf("This number does not exist BST...\n");
		}
		else if(num == 4)	//Preorder
		{
			printf("Print_BST_Preorder-------------------------\n");
			Print_BST_Preorder(root);
			printf("\n-------------------------------------------\n\n");
		}
		else if(num == 5)	//Inorder
		{
			printf("Print_BST_Inorder--------------------------\n");
			Print_BST_Inorder(root);
			printf("\n-------------------------------------------\n\n");
		}
		else if(num == 6)	//Postorder
		{
			printf("Print_BST_Postorder------------------------\n");
			Print_BST_Postorder(root);
			printf("\n-------------------------------------------\n\n");
		}
		else if(num == 7)	//BST Initialization
		{
			for(;;)
			{
				printf("Are you sure you want to INITIALIZE BST?\n");
				printf("\tPlease answer y/n\n");
	
				scanf("%c",&answer);
				getchar();
				
				if(answer == 'y' || answer == 'Y')
				{
					root = NULL;
					printf("Successfully initialized BST!\n");
					break;
				}
				else if(answer == 'n' || answer == 'N')
				{
					printf("Not initialized BST\n");
					break;
				}
				else
					printf("Please enter y or n\n\n");
			}
		}
		else if(num == 8)	//Exit Program
		{
			printf("--------------------------------------------------------\n");
			printf("\t\tThank you for using it ! ! !\n");
			printf("--------------------------------------------------------\n");
			break;
		}
		else					//Enter a character,not number OR Out of range
		{
			printf("---------------------------------------------------------\n");
			printf("\tPlease enter a number (non-character)\n");
			printf("\tPlease enter a number in the range (1 ~ 8)\n");
			printf("---------------------------------------------------------\n");
		}
	}

	return 0;
}
