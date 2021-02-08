#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
int turn=1;
int choice;
void switch_turn()
{
	turn=1-turn;
}

class node{
public:
	int val;
	node* next;
	
};
class list{
public:
 node* head=NULL;
 node* tail=NULL;
 public:
 list()
 {
 	
 }
 void insert_node(int d)
 {  node* t=new node();
   t->val=d;
 	if(head==NULL)
 	{
 		head=t;
 		tail=t;
 		tail->next=NULL;
	 }
	 else{
	 	  tail->next=t;
	 	  tail=t;
	 	  tail->next=NULL;
	 }
 }
 void display()
 { node* t=new node();
   t=head;
   int i=1;
   int n=0;
   cout<<endl;
   while(t!=NULL)
   
   	
   	 { if(t->val==-1)
   {
   	cout<<"\t\t"<<"("<<n<<") *";
   }
   else 
   	cout<<"\t\t"<<t->val;
   	if(i%3==0)
   	{
   		cout<<endl<<endl;
	}
	   ++i;
	   ++n;
	   t=t->next;
   	
   }
 
 	
 }
 void place(int turn,int choice)
 { node *temp=new node();
   node *prev=new node();
   node *curr=new node();
   curr=head;
   int i=1;
  	        while(i<=choice)
  	        { 
			  prev=curr;
			  curr=curr->next;
  	        	++i;
			  }
			  if(curr->val==-1)
			  
			  {
			    curr->val=turn;
			    
	            }
	            else{
	            	cout<<"invalid choice,enter again: ";
	            	cin>>choice;
	            	place(turn,choice);
				}
 }
 int get_specific(int pos)
 {
 	node *temp=new node();
   node *prev=new node();
   node *curr=new node();
   curr=head;
   int i=1;
  	        while(i<=pos)
  	        { 
			  prev=curr;
			  curr=curr->next;
  	        	++i;
			  }
return curr->val;
 
 }
 
 
 
};
bool win_check(list l1)
 {
 	
 	bool chk=false,chk2=false,chk3=false; int i=0;
 	//checking rows
if(l1.get_specific(0)==turn&&l1.get_specific(1)==turn&&l1.get_specific(2)==turn||l1.get_specific(3)==turn&&l1.get_specific(4)==turn&&l1.get_specific(5)==turn||l1.get_specific(6)==turn&&l1.get_specific(7)==turn&&l1.get_specific(8)==turn)
 	
 	{
 		chk=true;
	 }
	 //checking col
else if(l1.get_specific(0)==turn&&l1.get_specific(3)==turn&&l1.get_specific(6)==turn||l1.get_specific(1)==turn&&l1.get_specific(4)==turn&&l1.get_specific(7)==turn||l1.get_specific(2)==turn&&l1.get_specific(5)==turn&&l1.get_specific(8)==turn)
	 {
	 	chk2=true;
	 }
	//checking diagonals
 else if(l1.get_specific(0)==turn&&l1.get_specific(4)==turn&&l1.get_specific(8)==turn||l1.get_specific(2)==turn&&l1.get_specific(4)==turn&&l1.get_specific(6)==turn)
	{
		chk3=true;
	}
	if(chk==true||chk2==true||chk3==true)
	{
		return true;
	}
	else 
	return false;
}

int main()
{
	list l;
	  system("color f1");
	for(int i=1;i<=9;i++)
	{
		l.insert_node(-1);
	}
	l.display();
	int n=9;
while(n >0)
	{ 
	  switch_turn();
	  cout<<"player "<<turn<<" 's turn,enter choice: ";
	  do
	  {
	  cin>>choice;
	  if(choice>=9)
	  {
	  	cout<<"you enter the wrong choise enter Again";
	  }
   else
	  {
	  
		l.place(turn,choice);
		system("cls");
		l.display();
	bool result=win_check(l);
	if(result == true)
	{
		cout<<"\nGameOver!\nPlayer "<<turn<<" Won !";
		break;
	}
	continue;
	}
	}while(choice>=9);
	bool result=win_check(l);
	if(result == true)
	{
		break;
	}
	else 
	--n;
}

		
		
	
	if(n==0)
	{
		cout<<"\n Match Draw\n ";
		system("pause");
	}



}

