#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

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

Node* Insert_Number(Node* root,int data)
{
}

Node* Delete_Number(Node* root,int data)
{
}

void Print_AVL_tree_Preorder(Node* root)
{
	if(root == NULL)
		return;

	printf("%d ",root->value);
	Print_AVL_tree_Preorder(root->left);
	Print_AVL_tree_Preorder(root->right);
}
void Print_AVL_tree_Inorder(Node* root)
{
	if(root == NULL)
		return;

	Print_AVL_tree_Inorder(root->left);
	printf("%d ",root->value);
	Print_AVL_tree_Inorder(root->right);
}
void Print_AVL_tree_Postorder(Node* root)
{
	if(root == NULL)
		return;

	Print_AVL_tree_Postorder(root->left);
	Print_AVL_tree_Postorder(root->right);
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
		printf("\t\t         AVL_Tree\n");
		printf("\t\t-------------------------\n\n");

		printf("\t\tPlease select an activity\n");
		printf("\t\t--Please enter a number--\n\n");
		
		printf("\t1.Insert Number\t\t2.Delete Number\n");
		printf("\t3.Search Number\t\t4.Print Preorder\n");
		printf("\t5.Print Inorder\t\t6.Print Postorder\n");
		printf("\t7.Tree Initialization\t0.Exit Program\n");
		printf("-------------------------------------------------------------\n");

		scanf("%d",&num);
		getchar();

		if(num == 1)	//Insert Number
		{
			for(;;)
			{
				printf("\nPlease enter a number to insert into the AVL tree\n");
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
			printf("\nPlease enter a number to delete the AVL tree\n");

			scanf("%d",&enter_number);
			getchar();

			check_duplicated = Search_Number(root,enter_number);
			if(check_duplicated != 0)
			{
				root = Delete_Number(root,enter_number);
				printf("Successfully deleted ! ! !\n");
			}
			else
				printf("This number does not exist AVL tree...\n");
		}
		else if(num == 3)	//Search Number
		{
			printf("\nPlease enter a number to search AVL tree\n");

			scanf("%d",&enter_number);
			getchar();

			check_duplicated = Search_Number(root,enter_number);

			if(check_duplicated != 0)
				printf("Successfully searched! (search number = %d)\n",enter_number);
			else
				printf("This number does not exist AVL tree...\n");
		}
		else if(num == 4)	//Preorder
		{
			printf("Print_AVL_tree_Preorder-------------------------\n");
			Print_AVL_tree_Preorder(root);
			printf("\n-------------------------------------------\n\n");
		}
		else if(num == 5)	//Inorder
		{
			printf("Print_AVL_tree_Inorder--------------------------\n");
			Print_AVL_tree_Inorder(root);
			printf("\n-------------------------------------------\n\n");
		}
		else if(num == 6)	//Postorder
		{
			printf("Print_AVL_tree_Postorder------------------------\n");
			Print_AVL_tree_Postorder(root);
			printf("\n-------------------------------------------\n\n");
		}
		else if(num == 7)	//Tree Initialization
		{
			for(;;)
			{
				printf("Are you sure you want to INITIALIZE AVL TREE?\n");
				printf("\tPlease answer y/n\n");
	
				scanf("%c",&answer);
				getchar();
				
				if(answer == 'y' || answer == 'Y')
				{
					root = NULL;
					printf("Successfully initialized AVL tree!\n");
					break;
				}
				else if(answer == 'n' || answer == 'N')
				{
					printf("Not initialized AVL tree\n");
					break;
				}
				else
					printf("Please enter y or n\n\n");
			}
		}
		else if(num == 0)	//Exit Program
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
			printf("\tPlease enter a number in the range (0 ~ 7)\n");
			printf("---------------------------------------------------------\n");
		}
	}

	return 0;
}
