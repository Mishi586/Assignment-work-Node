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
class Queue{
    private:
    LinkedList l2;
    public:
    bool isEmpty()
    {
        return l2.isEmpty();
    }
    void enqueue(int val)
    {
        l2.insertAtBeginning(val);
    }
    void printElements()
    {
        l2.printAllElements();
    }
    int dequeue()
    {
        int m;
        if(!l2.isEmpty())
        {
            m=l2.getLastElement()->getData();
            l2.removeFromLast();
        }
        return m;
    }
    int front()
    {
        int x;
        x=l2.getLastElement()->getData();
        return x;
    }
    
    
};
int main()
{
   
   	Queue q1;
   	cout<<q1.isEmpty();
   	cout<<endl;
   	q1.enqueue(15);
   	q1.enqueue(70);
   	q1.printElements();
   	cout<<q1.front();
   	cout<<endl;
     q1.dequeue();
   	cout<<"After Removing:"<<endl;
   	q1.printElements();
   	//cout<<q1.front();
   	
   
   	
}
