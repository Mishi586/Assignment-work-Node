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
  void insertATBeginning(int val)
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
   /*To delete the last node of a linked list, find the second last node and make the next pointer of that node null. */
 int get1stElement()
 {
     cout<<"\nPrinting 1st element:"<<endl;
     return (head->getData()); 
 }
 int getLastElement(){
    while(head!=NULL){
        head=head->getNext();
        if(head->getNext()==NULL){
            return (head->getData());
        }
    }
}
 
 void printAllElements()
{
    Node* temp;
    while (temp != NULL) {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
}

int getLength()
{
    if(isEmpty())
    {
        int count=0;
        Node *temp=head;
        while(temp!=NULL)
        {
            temp=temp->getNext();
            count++;
        }
        return count;
    }
}   

  void insertNodeAtEnd(int val)
{
    Node *t1 = new Node(val);
    if (head == NULL) {
        head = t1;
        return;
    }
  
    Node *temp = head;
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
    }
    t1=temp->getNext();
}
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
   LinkedList l1,l2;
   cout<<l1.isEmpty();//returning true 1 
  
  l1.insertATBeginning(35);
  l2.insertATBeginning(22);
  l1.insertATBeginning(60);
   l2.insertATBeginning(6);
   cout<<l1.isEmpty();
   l1.get1stElement();
   cout<<"Last Element is:"<<endl;
   l1.getLastElement();
   l2.getLength();
  // cout<<"ALL Nodes in linked list are:"<<endl;
   l1.printAllElements();
   

    return 0;
}
