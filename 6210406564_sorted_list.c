// 6210406564 Natthapol Promkheeree
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

void printlist(node **head){
    node *tmp=*head;
    while(tmp!=NULL){
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }
}

void insert_node(node **head,int value){
    int i=0,j=0,q=0;
    node *new_node,*tmp=*head,*a=*head,*b=*head;
    new_node = (node *)malloc(sizeof(node));
    new_node->data=value;
    new_node->next=NULL;
    if(tmp!=NULL){
        b=b->next;
        if(b==NULL){
            if(value >= (*head)->data){
                new_node->next=tmp->next;
                tmp->next=new_node;
            }else{
            new_node->next=*head;
            (*head)=new_node;}
        }else{
            while(value >= a->data && a->next!=NULL){
            i++;a=a->next;j++;}
            while(i>1){
            tmp=tmp->next;i--;}
            if(j==0){
                new_node->next=*head;
                (*head)=new_node; 
            }else if(i==1 && a->data<=value){
                tmp=tmp->next;
                new_node->next=tmp->next;
                tmp->next=new_node;
            }else{
                new_node->next=tmp->next;
                tmp->next=new_node;
            }
        }
    }else{
        *head=new_node;
    }
}

int main(){
    node *head = NULL;
    int value;
    scanf("%d",&value);
    if(value>-1){
        while(1){
        insert_node(&head,value);
        scanf("\n%d",&value);
        if(value<=-1)break;
    }
    printlist(&head);
    }
}