#include<stdio.h>
#include<stdlib.h>

#define SIZE 7

typedef struct node{
  int value;
  struct node* link;
}node;

node* newnode=NULL;
node* chain[SIZE];

void initialize(){
  int i;
  for(i=0;i<SIZE;i++)
    chain[i]=NULL;
}

void insert(int val){
  int hash;
  newnode=(node*)malloc(sizeof(node));
  newnode->value=val;
  newnode->link=NULL;
  hash=val%SIZE;
  if(chain[hash]==NULL)
    chain[hash]=newnode;
  else{
    node* temp=chain[hash];
    while(temp->link!=NULL)
      temp=temp->link;
    temp->link=newnode;
  
  }
}


int search(int key){
  int hash=key%SIZE;
  node* temp=chain[hash];
  while(temp!=NULL){
    if(temp->value==key)
      return 1;
    temp=temp->link;
  }
  return 0;
}


void display(){
  int i;
  for(i=0;i<SIZE;i++){
    node*temp=chain[i];
    printf("array[%d]-->",i);
    while(temp!=NULL){
      printf("%d-->",temp->value);
      temp=temp->link;}
    printf("NULL\n");
  }
}


int main(){
  int k,val,key,s;
  while(1){
    printf("\n0.Exit\n1.Insert\n2.Search\n3.Display\nEnter your choice: ");
    scanf("%d",&k);
    switch(k){
    case 0:
      exit(0);
      break;
    case 1:
      printf("\nEnter value to be inserted: ");
      scanf("%d",&val);
      if(search(val)==1)
	printf("Value already exists");
      else
	insert(val);
      break;
    case 2:
      printf("\nEnter the value to be searched: ");
      scanf("%d",&key);
      s=search(key);
      if(s==1)
	printf("\nElement found");
      else
	printf("\nElement not found!!!!");
      break;
    case 3:
      display();
      break;
    default:
      printf("\nEnter a valid choice !!!!");
      continue;
      
    }
  }
}
