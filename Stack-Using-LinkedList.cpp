#include<iostream>

using namespace std;
class Node{
  private:
  int data;
  Node *next;
  public:
  Node()
  {
      data=0;
      next=NULL;
  }
  Node(int data)
  {
      this->data=data;
      next=NULL;
  }
  void setData(int data)
  {
      this->data=data;
  }
  void setNext(Node* next)
  {
      this->next=next;
  }
  int getData()
  {
      return this->data;
  }
  Node* getNext()
  {
      return this->next;
  }
  
};
class LinkedList{
  private:
  Node *head;
  public:
  LinkedList()
  {
      head=NULL;
  }
  bool isEmpty()
  {
      return (head==NULL);
  }
  void insertAtBeginning(int val)
  {
      if(isEmpty())
      {
          head=new Node(val); //creating new Node in linked-list and inserting value
      }
      else //if List is not empty
      {
          Node *t=new Node(val);
          t->setNext(head);
          head=t;
      }
  }
  void removeFromBegin()
  {
      if(!isEmpty())//if list is not empty
      {
         Node *t=head->getNext();//pointing head to next Node
         delete head; //deleting Node 
         head=t; 
         
         //Alternate code:
        /* Node *t;  
         t=head->getNext();
         delete t;
         head=t;*/
        }
  }
   
 void get1stElement()
 {
     cout<<"\nPrinting 1st element:"<<endl;
     cout<<(head->getData()); 
 }
 Node * getLastElement(){
     Node * temp = head;
     if(temp!=NULL){
        while(temp->getNext()!=NULL){
            temp=temp->getNext();
        }
    }
    return temp;
    // cout<<head->getData();
}
 
 void printAllElements()
{   
    if(!isEmpty()){
    Node* temp=head;
    while (temp != NULL) {
        cout << temp->getData() <<"->";
        temp = temp->getNext();
    }
    cout << "NULL\n";
}
}

void getLength()
{
    if(!isEmpty())
    {
        int i=0;
        Node *temp=head;
        while(temp!=NULL)
        {
            temp=temp->getNext();
            i++;
        }
        cout<<i;
    }
}   

  void insertNodeAtEnd(int val)
{
    Node *t1 = new Node(val);
   if(isEmpty()){
       head=t1;
   }
   else
   {
     Node *temp=head;
     while(temp->getNext()!=NULL)
     {
         temp=temp->getNext();
     }
     temp->setNext(t1);
   }
}
/*To delete the last node of a linked list, find the second last node and make the next pointer of that node null. */

    void removeFromLast(){
        Node * temp = head;
        Node * temp2 = head->getNext();
        
        while (temp2->getNext() != NULL){
            temp = temp->getNext();     // second last
            temp2 = temp2->getNext(); // last
        }
        delete temp2;
        temp->setNext(NULL);
    }

};

class Stack{ //LIFO
	private:
	LinkedList l1;
	public:
		void push(int val)
		{
			  l1.insertNodeAtEnd(val);
		}
			bool isEmpty()
		{
			return l1.isEmpty();
		}
		void print()
		{
		    l1.printAllElements();
		}
		
		int pop()
		{   

		    int x=l1.getLastElement()->getData();
			l1.removeFromLast();
			return x;
		
		}
		void insertAtBegin(int a)
		{
			return l1.insertAtBeginning(a);
		}
		
		int top() //for returning element it will not remove element from stack only return it.
		{
			int b;
			b=l1.getLastElement()->getData();
			return b;
		}
		void removeFromBeginning()
		{
		    return l1.removeFromBegin();
		}
};
int main()
{
   Stack S1;
//   cout<< S1.isEmpty();
//   cout<<endl;
   S1.push(30);
   S1.push(20);
   S1.push(40);
   S1.print();
   	cout<<S1.pop() << endl;
   	S1.print();
   	cout<<S1.top();
   	S1.insertAtBegin(50);
   	cout<<endl;
   	S1.print();
   	S1.removeFromBeginning();
   	S1.print();
   	
   	
   
   	
}
