#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node * NODE;

NODE getnode() {
    NODE p;
    p = (NODE) malloc(sizeof(struct node));
    if (p != NULL) return p;
    else {
        printf("No Memory \n");
        return NULL;
    }
}

NODE deletefront(NODE head) {
	NODE p = head;
	if (head == NULL) {
		printf("Empty \n");
		return head;
	}
	printf("Deleted \n");
	head = p -> next;
	free(p);
	return head;
}

NODE deleterear(NODE head) {
	NODE p = head, prev;
	if (head == NULL) {
		printf("Empty \n");
		return NULL;
	}
	if (head -> next == NULL) {
		printf("Deleted \n");
		return NULL;
	}
	while (p -> next != NULL) {
		prev = p;
		p = p -> next;
	}
	free(p);
	prev -> next = NULL;
	return head;
}

NODE deleteval(NODE head, int val) {
	NODE curr = head, prev = NULL;
	int flag = 1;
	if (head == NULL) {
			printf("Empty \n");
			return head;
	}
	if (curr != NULL && curr -> data == val) { // val is in head
		head = curr -> next;
		free(curr);
		printf("Deleted \n");
		curr = head;
		return head;
	}

	while (curr -> next != NULL) {
		prev = curr;
		curr = curr -> next;
		if (curr -> data == val) {
			prev -> next = curr -> next;
			free(curr);
			flag = 0;
			printf("Deleted \n");
			return head;
		}
	} 
	if (flag == 1) {
		printf("Not Found \n");
		return head;
	}	
}

void display (NODE head) {
    	NODE p;
	if (head == NULL) {
		printf("Empty List \n");
		return;
	}
	p = head;
	while (p != NULL) {
		printf("%d \t", p -> data);
		p = p -> next;
	}
	printf("\n");
}

int main() {
	NODE head = getnode();
	NODE p = getnode();
	NODE q = getnode();
	head -> data = 5;
	head -> next = p;
	p -> data = 10;
	p -> next = q;
	q -> data = 15;
	q -> next = NULL;
	
	int choice, val;
    
	do {
		printf("1. Delete from Front \n");
		printf("2. Delete from End \n");
		printf("3. Enter Value \n");
		printf("4. Display \n");
		printf("5. Exit \n");
		printf("Enter Choice \n");
		scanf("%d", &choice);
		printf("\n\n");
		
		switch (choice) {
		    case 1: head = deletefront(head);
		            break;
		    
		    case 2: head = deleterear(head);
		            break;
		            
		    case 3: printf("Enter Value\n");
		            scanf("%d", &val);
		            head = deleteval(head, val);
		            break;
		            
		    case 4: display(head);
		            break;

		    case 5: exit(0);
		            break;
		    
		    default: printf("Invalid Choice \n");
		}
		
		
	    } while (choice != 5);

	return 0;
}
