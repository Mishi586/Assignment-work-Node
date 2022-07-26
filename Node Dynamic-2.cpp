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
    void setNext(Node *next)
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
 
 void printing1stElement(Node* head)
 {
     cout<<"\nPrinting 1st element:"<<endl;
     cout<<head->getData()<<endl; 
 }

void printNodeObjects(Node* temp)
{
    while (temp != NULL) {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
}
int getLength(Node *head)
{
   Node *temp=head;
   int i=0;
   while(temp!=NULL)
   {
       temp=temp->getNext();
       i++;
   }
   cout<<i;
}

int GetNthElement(Node* head, int index)
{
  
    Node *pos = head;
    int count = 0;
    while (pos != NULL) {
        if (count == index)
            return (pos->getData());
        count++;
        pos = pos->getNext();
    }
    return count;
}

void insertNodeAtEnd(Node *head, int val)
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
  

int main() {
  //Now creating objects dynamically
  Node *head,*n2,*n3,*n4,*n5,*n6,*n7,*n8;
  
  head=new Node(2);
  n2=new Node(3);
  n3=new Node(4);
  n4=new Node(5);
  n5=new Node(6);
  n6=new Node(7);
  n7=new Node(8);
  n8=new Node(9);
  head->setNext(n2);
  n2->setNext(n3);
  n3->setNext(n4);
  n4->setNext(n5);
  n5->setNext(n6);
  n6->setNext(n7);
  n7->setNext(n8);
 
 //for getting nth element in list:
  cout << "Element at index 2 is: " << GetNthElement(head, 2)<<endl;
  
  //printing the entire collection of node objects
  
 cout<<"Total Elements are:"<<endl;   
 printNodeObjects(head);
  printing1stElement(head);
  //printing the length of Node Elements
  
  cout<<"Total Length of node class is:"<<endl;
  getLength(head);
  
  
 //inserting new nodeat the end
  insertNodeAtEnd(head,8);
  
  //de-Allocating memory of pointers
 delete head;
 delete n2;
 delete n3;
 delete n4;
 delete n5;
 delete n6;
 delete n7;
 delete n8;
     return 0;
}
