#include<stdio.h>
#include<stdlib.h>
struct node
{

	int data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node *NODE;

NODE getnode(int item)
{
	NODE p;
	p = (NODE)malloc(sizeof(struct node));
	p->data = item;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}


NODE insert(NODE root,int item)
{

	if(root == NULL)
		return getnode(item);
	if(item < root->data)
		root->lchild = insert(root->lchild,item);
	else if(item > root->data)
		root->rchild = insert(root->rchild,item);
	return root;
}



void inorder(NODE root){

	if(root == NULL){
		return;	
	}
	inorder(root->lchild);
	printf("%d\t",root->data);
	inorder(root->rchild);
}


void preorder(NODE root)
{
	if(root == NULL)
		return;
	printf("%d\t",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

void postorder(NODE root)
{
	if(root == NULL)
		return;
	
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\t",root->data);
}

int main()
{
	
	NODE root = NULL;
	int ch,elem;
	
	while(1){
	
	

	printf("\n 1 - insert \n");
	printf("2 - inorder\n");
	printf("3 - postorder\n");
	printf("4 - preoder\n");
	printf("5 exit\n");
	printf("Enter your choise: \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the elemnet to be inserted : \n");
			scanf("%d",&elem);
			root = insert(root,elem);
			break;
			
		case 2:printf(" inorder traversal \n");
			 inorder(root);
			break;
			
		case 3:printf("postotder traversal\n");
			 postorder(root);
			break;
	
		case 4:
			printf("preorder traversal\n");
			 preorder(root);
			break;
	
	        case 5:exit(0);
		
		default: 
			printf("INvalid choise !!!!\n");
			break;
	
	
	}
	
	}
	

}
