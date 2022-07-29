#include <iostream>
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
 void getLastElement(){
    if(head!=NULL){
        while(head->getNext()!=NULL){
            head=head->getNext();
        }
        
    }
    cout<<head->getData();
}
 
 void printAllElements()
{   
    if(!isEmpty()){
    Node* temp=head;
    while (temp != NULL) {
        cout << temp->getData() <<"-->";
        temp = temp->getNext();
    }
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
  void removeFromLast()
  {
      Node *t1=head; //t1=head; it will move to next nodes to reach last node
      Node *t2=t1->getNext();// t2=second last Node 
      while(t2->getNext()!=NULL)
      {
          t1=t1->getNext();
          t2=t2->getNext();
          delete t2; //last Node
      }
      t1->setNext(NULL);//setting t1->NULL
  }
};
int main() {
   LinkedList l1;
  cout<<l1.isEmpty();//returning true 1 
  cout<<endl;
  l1.insertAtBeginning(22);
  l1.insertAtBeginning(28);
  l1.insertAtBeginning(10);
  l1.insertAtBeginning(40);
  l1.insertAtBeginning(20);
  l1.getLength();//5
  cout<<endl;
   cout<<l1.isEmpty();
   cout<<endl;
   l1.printAllElements();
  l1.removeFromBegin();
   l1.get1stElement();
   cout<<"\nLast Element is:"<<endl;
   l1.getLastElement();
   l1.insertNodeAtEnd(70);
   l1.insertNodeAtEnd(60);
   cout<<endl;
   l1.getLength();
   cout<<endl;
   l1.removeFromLast();
   return 0;
}
