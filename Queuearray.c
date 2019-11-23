#include <stdio.h>
#include<stdlib.h>
#define que_size 5

void insert_rear(int item,int *rear,int *q)
{
    
       if(*rear==que_size-1)
    	{ 
        	printf("queue overflow\n");
        	return;
        
    	}
   	*rear=*rear+1;
  	 q[*rear]=item;
}
int delete_front(int *front,int *rear,int *q)
{
     if(*front>*rear)
        return -1;
      return q[(*front)++];
}
void display(int front,int rear,int q[])
{
       int i;
       if(front>rear)
       {
           printf("queue is empty!!\n");
           return;
           
       }
   printf("Elements of queue are: \n");
   for(i=front;i<=rear;i++)
   {
       printf("%d\t\t",q[i]);
   }
   printf("\n");
}


int main()
{
       int choice,item,front,rear,q[10];
       front=0;
       rear=-1;
       while(1)
       {
           printf("1:insert\n 2:delete\n 3:display\n 4:exit\n");
           printf("enter choice\n");
           scanf("%d",&choice);
           
           switch(choice)
           {
               case 1:
                   printf("enter no to be inserted\n");
                   scanf("%d",&item);
                   insert_rear(item,&rear,q);
                   break;
                   
                case 2:
                     item=delete_front(&front,&rear,q);
                     if(item==-1)
                     printf("queue is empty\n");
                     else
                     printf("item deleted=%d\n",item);
                     break;
                case 3:
                    display(front,rear,q);
                    break;
                    default:
                    exit(0);
           }
           
       }
       
}
