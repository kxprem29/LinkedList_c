#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
//For printing LL
void LLtrasversal(struct Node* ptr){
     while(ptr!=NULL){
        printf("element is %d \n", ptr-> data);
        ptr=ptr-> next;
     }
}

//Insertion at Beginning
struct Node* insertAtFirst(struct Node* head, int data){
     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
     ptr->next=head;
     ptr->data=data; 
     return ptr;
} 
//Isertion in between
struct Node* atIndex(struct Node* head, int data, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p= head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
} 

//Insertion at the End
struct Node* atEnd(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
      ptr->data=data;
    struct Node *p =head;
    
    while(p->next!=NULL){
        p=p->next;
        
    }
  
    p->next=ptr;
    ptr->next=NULL;
    
    return head;
}
//Insertion after a given Node
struct Node* afterNode(struct Node* head,struct Node* prevNode ,int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
      ptr->data=data;
    
    
   
  
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    
    return head;
}
//Deletion at First
struct Node* deleteAtFirst(struct Node* head){
    struct Node* ptr= head;
    head=head->next;
    free(ptr);
    return head;
}
//Deletion in Between
struct N0de* deleteInBetween(struct Node* head, int index){
    struct Node *p =head;
    struct Node*q= head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}

//Deletion of Node at End
struct Node* deleteAtEnd(struct Node* head){
    struct Node * p= head;
    struct Node* q= p->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    
}
//Deletion of Node with a given value
struct Node * deleteByValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}


int main(){
    /*struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;*/

  //Memory allocation dynamically
  struct Node*  head = (struct Node*)malloc(sizeof(struct Node));
   struct Node* second = (struct Node*)malloc(sizeof(struct Node));
   struct Node* third = (struct Node*)malloc(sizeof(struct Node));
   struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

   head -> data=7;
   head-> next=second;
   second -> data=70;
   second-> next=third;
   third-> data=77;
   third->next=fourth;
   fourth->data=96;
   fourth->next=NULL;
   printf("\n before deletion\n");
   LLtrasversal(head);
   //head= insertAtFirst(head,56); 
   //head= atIndex(head, 56,2);
   //head= atEnd(head,56);
   //head=afterNode(head,second,56);
   //printf("\n after insertion\n");
   printf("\n after deletion\n");
   //head= deleteAtFirst(head);
   //deleteInBetween(head, 2);
   //deleteAtEnd(head);
   deleteByValue(head,77);
   LLtrasversal(head);
   
   return 0;

}