#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Insert_End(int);
void Insert_Front(int);
void Equalize();
void Number_Nodes();
void Display();
void Make_Linklist(char a[]);
void reverse();
void Addition();
void Display_Addition();

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node NODE;

NODE *start1 = NULL;
NODE *start2 = NULL;
NODE *start3 = NULL;
NODE *p, *q, *r , *p1, *p2, *p3, *q1, 	*q2, *q3, *first, *second;
NODE *temp1 , *temp2, *temp3 ,*temp4,*temp5;
int num_of_nodes1, num_of_nodes2;
int carry;
int count;
int count1;

int main(){
	char first[50], second[50];
	printf("Enter first number: ");
	scanf("%s",first);
	if(first[0] == '-'){
		printf("\n\n\terror!\nNEGATIVE NUMBER ENTERED\n\n");
		return;
	}
	Make_Linklist(first);
	Display();

	printf("Enter Second Number: ");
	scanf("%s",second);
	if(second[0] == '-'){
		printf("\n\n\terror!\nNEGATIVE NUMBER ENTERED\n\n");
		return;
	}
	Make_Linklist(second);
	Display();

	Number_Nodes();
	Equalize();
	reverse();
	Addition();
	Display_Addition();	
}

void Make_Linklist(char a[]){
	count++;
	int i = 0;
	while(a[i] != '\0'){
		Insert_End(a[i] - '0');
		i++;
	}
}

void Insert_End(int element){	
	if(count == 1){
		temp1 = (NODE *) malloc(sizeof(NODE));
		temp1 -> data = element;
		temp1 -> next = NULL;

		if(start1 == NULL){
			start1 = temp1;
			return;
		}

		else{
			p = start1;
			while(p -> next != NULL){
				p = p -> next;
			}
			p -> next = temp1;
		}
	}
	else if (count == 2){
		temp2 = (NODE *) malloc(sizeof(NODE));
		temp2 -> data = element;
		temp2 -> next = NULL;

		if(start2 == NULL){
			start2 = temp2;
			return;
		}

		else{
			q = start2;
			while(q -> next != NULL){
				q = q -> next;
			}
			q -> next = temp2;
		}	
	}

	else{
		temp5 = (NODE *) malloc(sizeof(NODE));
		temp5 -> data = element;
		temp5 -> next = NULL;

		if(start3 == NULL){
			start3 = temp5;
			return;
		}

		else{
			r = start3;
			while(r -> next != NULL){
				r = r -> next;
			}
			r -> next = temp5;
		}	
	}



}

void Display(){
	if(count == 1){
		printf("\n\tFirst link list\n");
		p = start1;
		while(p != NULL){
			printf("%d -> ",p -> data);
			p = p -> next;
		}
		printf("NULL\n");
		printf("\n\n");
	}
	else{
		printf("\n\tSecond link list\n");
		q = start2;
		while(q != NULL){
			printf("%d -> ",q -> data);
			q = q -> next;
		}
		printf("NULL\n");
		printf("\n\n");
	}
}

void Insert_front(int element){
	if(count1 == 1){
		temp3 = (NODE *) malloc(sizeof(NODE));
		temp3 -> data = element;
		temp3 -> next = NULL;

		if(start2 == NULL){
			temp3 = start2;
			return;
		} 
		else{
			temp3->next = start2;
			start2 = temp3;
		}
	}
	
	else{
		temp4 = (NODE *) malloc(sizeof(NODE));
		temp4 -> data = element;
		temp4 -> next = NULL;

		if(start1 == NULL){
			temp4 = start1;
			return;
		} 
		else{
			temp4->next = start1;
			start1 = temp4;
		}	
	}	
}

void Number_Nodes(){
	p = start1;
	while(p != NULL){
		num_of_nodes1++;
		p = p->next;
	}
	q = start2;
	while(q != NULL){
		num_of_nodes2++;
		q = q->next;
	}
}

void Equalize(){
	
	int a, b , i = 0 , j = 0;
	if(num_of_nodes1 == num_of_nodes2){
		return;
	}

 	if(num_of_nodes1 > num_of_nodes2){
 		count1 = 1;
 		a = num_of_nodes1 - num_of_nodes2;	
 		while(i != a){
 			Insert_front(0);
 			i++;
 		}	
 		//Display();
 	}

 	else if(num_of_nodes2 > num_of_nodes1){
 		count = 1;
 		count1 = 2;
 		b = num_of_nodes2 - num_of_nodes1;
 		while(j != b){
 			Insert_front(0);
 			j++;
 		}
 		//Display();
 	}
 		
}
int label;
void reverse(){
	if(label == 2){
		if(start3-> next == NULL){
			return;
		}
		p1 = start3;
		p2 = p1->next;
		p3 = p2->next;

		p1->next = NULL;
		p2->next = p1;

		while(p3 != NULL){
			p1 = p2;
			p2 = p3;

			p3 = p3->next;
			p2->next = p1;
		}
		start3 = p2;
	}	

	else{
		if(start1-> next == NULL){
			return;
		}
		p1 = start1;
		p2 = p1->next;
		p3 = p2->next;

		p1->next = NULL;
		p2->next = p1;

		while(p3 != NULL){
			p1 = p2;
			p2 = p3;

			p3 = p3->next;
			p2->next = p1;
		}
		start1 = p2;

		if(start2-> next == NULL){
			return;
		}
		q1 = start2;
		q2 = q1->next;
		q3 = q2->next;

		q1->next = NULL;
		q2->next = q1;

		while(q3 != NULL){
			q1 = q2;
			q2 = q3;

			q3 = q3->next;
			q2->next = q1;
		}
		start2 = q2;
	}	
}
void Addition(){
	int sum;
	first = start1;
	second = start2;


	while(first != NULL || second != NULL){
		temp1 = (NODE *)malloc(sizeof(NODE));
		sum =  sum = carry + (first? first->data: 0) + (second? second->data: 0);
		first = first -> next; second = second -> next; 
		 if(sum >= 10 ){
		 	carry = 1;
		 }
		 else carry = 0;
		 sum = sum % 10;
		 temp1 -> data = sum;
		
		count = 10;
		Insert_End(temp1 -> data);
	}	
	if(carry > 0){
		count = 10;
		Insert_End(carry);
	}
}


void Display_Addition(){
	printf("\n\t ----- ADDITION -----\n");
	label = 2;
	reverse();
	p = start3;
	while(p != NULL){
		printf("%d -> ",p->data);
		p = p -> next;
	}
	printf("NULL\n");
	printf("\n\n");

}