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

NODE insertfront(NODE head, int item) {
    NODE p;
    p = getnode();
    p -> data = item;
    p -> next = head;
    head = p;
    printf("Inserted \n");
    return head;
}

void sort(NODE head){
	NODE p = head, q = NULL;
	int temp;
	if (head == NULL) return;
	while (p -> next != NULL) {
		q = p -> next;
		while (q != NULL) {
			if (p -> data > q -> data) {
				temp = p -> data;
				p -> data = q -> data;
				q -> data = temp;
			}
			q = q -> next;
		}
		p = p -> next;
	}
}

NODE reverse(NODE head) {
	NODE curr = head, prev = NULL, nextn = NULL;
	if (head == NULL) return head;
	if (head -> next == NULL) return head;
	while (curr != NULL) {
		nextn = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = nextn;
	}
	head = prev;
	return head;
}

NODE concatenate(NODE first, NODE sec) {
	NODE p = first;
	if (first == NULL) return sec;
	if (sec == NULL) return first;
	while (p -> next !=  NULL) p = p -> next;
	p -> next = sec;
	return first;
}

void display (NODE head) {
    NODE p;
    if (head == NULL) {
        printf("Empty List \n");
        return;
    }
    p = head;
    while (p != NULL) {
        printf("%d -> ", p -> data);
        p = p -> next;
    }
    printf("\n");
}

int main() {
    int ch, count = 0, ele1,ele2;
    NODE head1 = NULL, head2 = NULL;
    
    while(1){
	
        printf("1. Insert for head 1\n");
        printf("2 insert for head 2\n");
        printf("3. Sort \n");
        printf("4. Reverse \n");
        printf("5. Concatenate \n");
		printf("6. Display \n");
		printf("7. Exit \n");
        printf("Enter Choice \n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: printf("Enter Element for head 1 \n");
                    scanf("%d", &ele1);
                    head1 = insertfront(head1, ele1);
                    break;
                    	                  
                    
                    
            case 2:
            		printf("Enter Element for head 2 \n");
                    scanf("%d", &ele2);
            		head2 = insertfront(head2, ele2);
                    break;
            	 	
                    
            
            case 3: 
					
					sort(head1); 		
            		sort(head2);
                    break;
                    
            case 4: 
					
					head1 = reverse(head1);
            		head2 = reverse(head2);
                    break;
                   
            case 5: head1 = concatenate(head1, head2);
            		break;
                    
            case 6: 
					printf("HEAD 1\n");
					display(head1);
            		printf("HEAD 2\n");
            		display(head2);
                    break;

	    	case 7: exit(0);
                    break;
            
            default: printf("Invalid Choice \n");
        }
        
        
    }

    return 0;
}
