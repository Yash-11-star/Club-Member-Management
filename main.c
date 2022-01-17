#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int roll;
    int prn;
    char name[20];
    struct node *next;
    
};
struct node* create()
{
  struct node * head;
  int p,r;
  char na[20];
  head=(struct node *)malloc(sizeof(struct node ));
  printf("ENTER YOU PRN NO, ROLL NO & NAME:\n");
  scanf("%d%d%s",&p,&r,na);
  head->prn=p;
  head->roll=r;
  strcpy(head->name,na);
  head->next =NULL;
  return head;
}
void add_member(struct node *head)
{
  int a;
  struct node *temp,*q;
  q=head;
  printf("HOW MANY MEMBERS YOU WANT TO ADD?\n");
  scanf("%d",&a);
  for(int i=0;i<a;i++)
  {
    temp=(struct node *)malloc(sizeof(struct node));
    printf("ENTER YOU PRN NO, ROLL NO & NAME:\n");
    scanf("%d %d %s",&temp->prn,&temp->roll,temp->name);
    q->next=temp;
    q=temp;
  }


}
void display(struct node *head)
{
  while(head!=NULL)
  {
    printf("\nPRN NO:%d\n",head->prn);
    printf("ROLL NO:%d\n",head->roll);
    printf("NAME:%s\n",head->name);
    head=head->next;
  }
}
void delete_president(struct node *head)
{
  struct node *q;
  q=head->next;
  free(head);
}
void add_secratary(struct node * head)
{
struct node *s;
char ja[30];
s=(struct node *)malloc(sizeof(struct node));
printf("ENTER YOU PRN NO, ROLL NO & NAME:\n");
scanf("%d%d",&s->prn,&s->roll);
scanf("%s",ja);
strcpy(s->name,ja);
while(head!=NULL && head->next!=NULL)
{
head=head->next;
}
head->next=s;
s->next=NULL;

}
void delete_secratary(struct node *head)
{
  while(head!=NULL&& head->next!=NULL)
  {
    head=head->next;
  }
  free(head);
}

void delete_member(struct node *head)
{ int n;
  struct node *p;

   printf("ENTER PRN NO TO DELETE:\n");
   scanf("%d",&n);

  while(head->prn!=n)
  {
    p=head;
    head=head->next;      
  }

  p->next=head->next;
  free(head);
}




int main()
{   
  int a;
    char ch;
    struct node *head;
  do{
  printf("\n1)ADD PRESIDENT\n2)ADD MEMBERS\n3)ADD SECRATERY\n4)DELETE PRESIDENT\n5)DELETE SECRATERY\n6)DELETE MEMBERS\n7)DISPLAY\n8)exit\n\n");
  printf("enter your choice\n");
  scanf("%d",&a);
  switch(a)
  {
    case 1:
    head=create();  //HEAD IS PRESIDENT
    break;
    case 2:
    add_member(head);
    break;
    case 3:
    add_secratary(head);
    break;
    case 4:
    delete_president(head);
    break;
    case 5:
    delete_secratary(head);
    break;
    case 6:
    delete_member(head);
    break;
    case 7:
    display(head);
    break;

  }

  }while(a!=8);

}