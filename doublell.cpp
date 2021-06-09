#include<iostream>
using namespace std;
/* we are making our own doubly linked list with help of classes
 1. we perform insertation at tail, head and also at any postion.
 2. DELETION at any POstioN
 3. DISPLAY the val of node and printing the whole Linked list
 4.  ALSO REVERSE the linked list.
 */

class node{
	
	public:
	int data;
	node* prev, *next;
	
	node(int data){
		this->data=data;
		this->prev=NULL;
		this->next=NULL;
	}
	~node(){
	};
	
};
 void insertattail(node* &head,int val)
 {                                             // INSERTITION AT TAIL
 	node* n=new node(val);
 	if(head==NULL)
 	{
 		head=n;
 		return;
	 }
	 
	 node*temp=head;
	 while(temp->next!=NULL)
	 {
	 	temp=temp->next;
	 }
	 temp->next=n;
	 n->prev=temp;
	 
	 
 }
 
 void display(node*head){                    // DISPLAY THE WHOLE LINKED LIST
 	while(head!=NULL)
 	{
 		cout<<head->data<<" ";
 		head=head->next;
	 }
 }
 void insertatpos( node* &head,int val,int a)       //INSERT AT ANY POSTION
 {
 	node* temp=head;
 	while(a--)
 	{
 		if(temp==NULL){
 			return;
		 }
		 temp=temp->next;
 		
	 }
	  node*n=new node(val);
	  node*temp2=temp->prev;
	  temp2->next=n;
	  n->prev=temp2;
	  n->next=temp;
	  temp->prev=n;
 }
 node* del(node* &head,int pos)              //DELETE NODE AT ANY POSTION
 {                                            // and print not possible if out of range postion is given by user.
 	node* temp=head;
 	if(pos==0)
 	{
 	  node* todel=temp;
	   temp->next->prev=NULL;
	   head=temp->next;
	   delete todel; 
	   return head;	
	}
	int a=0;
 	while( a!=pos )
 	{
 		temp=temp->next;
 		a++;
	}
	if(temp==NULL){
		cout<<"not possible"<<endl;
		return head;
	}
  else	if(temp->next==NULL)
	{
		node* todel=temp;
		temp->prev->next=NULL;
		delete todel;
		return head;
	}
 else{
 	node *todel=temp;
 	temp->next->prev=temp->prev;
 	temp->prev->next=temp->next;
 	delete todel;
 	return head;
}
 }
 node* reverse(node* &head)              // reverse the linked list
 {
 	node* temp= head;
 	node* pre=NULL;
 	node * newnode;
 	while(temp!=NULL)
 	{
 		temp->prev=temp->next;
 		temp->next=pre;
 		if(temp->prev!=NULL)
 		pre=temp->prev->prev;
 		newnode=temp;
 		temp=temp->prev;
	 }
	 return newnode;
 }
 
 int main(){                                   //  MAIN PROGRAM
 	node* head = NULL;
 	insertattail(head,1);
 	insertattail(head,10);
 	insertattail(head,15);
 	insertattail(head,14);
 	insertattail(head,12);
 	insertatpos(head,11,2);
 	display(head);
 //	node* newnode=reverse(head);
 //	display(newnode);
    del(head,6);
	display(head);	
 }
