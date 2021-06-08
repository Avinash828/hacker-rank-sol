#include<iostream>
using namespace std;

  /* we are making our own node with the help of classes
   and implement basic  operation of linked lists  */

class node{
	public:
		int data;
		node* next;
		
		node(int val){           // prameterized constructor
			data=val;
			next=NULL;
		}
		~node(){                 // desctructor
		}
};
void insertatbot(node* &head, int val)      //  inserting the node at the last of linkek list;
{
	node* n=new node(val);
	if(head==NULL)    // taking care of empty linked list;
	{
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}
void display(node*head)                          // display the content of linked list
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
}
void insertat (node* &head,int val,int a)    // inserting the value=val atnparticular  postion 
{
	node* n=new node(val);
	node* temp=head;
	while(temp->data!=a)
	{
		temp=temp->next;
	}
	n->next=temp->next;
	temp->next=n;
}
 void delattop(node* &head)          // deleting the top node of list;
 {
 	node*todel= head;
 	head=head->next;
 	delete todel;
 }
 void del(node* &head,int a)          // deleting the list which have value=a;
 {
 	node* temp=head;
 	while(temp->next->data!=a)
 	{
 		temp=temp->next;
	 }
	 node* todel=temp->next;
	 temp->next=temp->next->next;
	 delete todel;
 }
 void dellast(node* &head)                   //  deleting the last node of linked list
 {
 	node* temp=head;
 	while(temp->next->next!=NULL)
 	{
 		temp= temp->next;
	 }
	 node* todel=temp->next;
	 temp->next=NULL;
	 delete todel;
 }
 
 bool comp (node* head1,node*head2){
 	                                               // we are comparing two linked list wheather they are same or not
 	node*temp1=head1;                              //  1-->2-->3-->null  and   1-->2-->3-->4-->null
 	node* temp2= head2;                            // they both are not equal;
 	while(temp1!=NULL and temp2!=NULL){
	 
 	if(temp1->data==temp2->data)
 	  {
 	  	temp1=temp1->next;
 	  	temp2=temp2->next;
 	  	if((temp1!=NULL and temp2==NULL) or (temp1==NULL and temp2!=NULL))
 	  	{
 	  		return false;
 	  		break;
		   }
	   }
	   else{
	   	return false;
	   	break;
	   }
 }
 return true;
 }
 void findmid(node*head)         // this is used to find mid
 {                               //  we are using same fast and slow pointer concept
 	node* temp1=head;
 	node* temp2=head;
 	while(temp2->next!=NULL)
     {
     	if(temp2->next->next!=NULL)
     	{
		 temp1=temp1->next;
     	
     	temp2=temp2->next->next;}
     	else
     	{
     	  break;	
		 }
	 }
	 cout<<"the mid is:"<<temp1->data<<endl;
}
 

int main()
{
	node* head=NULL;
	insertatbot(head,1);
	insertatbot(head,3);
	insertatbot(head,5);
	insertatbot(head,2);
//	display(head);
	//insertat(head,8,3);
	insertatbot(head,7);
	//display(head);
	//delattop(head);
	//del(head,5);
	//dellast(head);
	findmid(head);
	display(head);
}
