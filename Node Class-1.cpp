//Node Class
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
int main() {
   Node n1(2), n2(3), n3(4), n4(7), n5(10);
   cout<<"n1 data:"<<n1.getData()<<endl; //return 2
   cout<<"N1 next:"<<n1.getNext()<<endl; //return 0(NULL)
   //pointing n1->n2->n3->n4->n5->NULL
  n1.setNext(&n2);
  n2.setNext(&n3);
  n3.setNext(&n4);
  n4.setNext(&n5);
  n5.setNext(NULL);
  
  //printing values of objects
    cout<<"N1:"<<n1.getData()<<endl; //2
    cout<<"N2:"<<n2.getData()<<endl; //3
    cout<<"N3:"<<n3.getData()<<endl; //4
    cout<<"N4:"<<n4.getData()<<endl; //7
    cout<<"N5:"<<n5.getData()<<endl; //10
     
     return 0;
}
