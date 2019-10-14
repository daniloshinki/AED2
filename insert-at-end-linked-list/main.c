#include<stdio.h>
#include<stdlib.h>

struct node *head=NULL;
struct node *end=NULL;
struct node{
    	int data;
    	struct node *next;
};
//Inserir o novo nó no fim da lista
void insertatend(int data){
    	struct node *temp = (struct node*)malloc(sizeof(struct node));
      //Insere o novo elemento e faz o ponteiro temp apontar para nulo
    	temp->data=data;
    	temp->next=NULL;
    	//Insere na cabeça se a lista estiver vazia
      if(head==NULL)
    	{
        		head=temp;
        		end=temp;
        		return;
    	}
    	end->next=temp;
      //faz o ultimo nó apontar para o novo nó criado
    	end=temp;	
      //faz o novo nó criado temp como ultimo nó
}
void print(){
    	struct node *temp=head;
    	printf("\nList:");
    	while(temp!=NULL)
    	{
        		printf("\n%d ",temp->data);
        		temp=temp->next;		
	    }
}
int main(){
    	insertatend(1);
    	print();
    	insertatend(2);
    	print();
    	return 0;
}