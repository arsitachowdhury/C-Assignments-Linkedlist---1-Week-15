#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void display()
    {
        Node *temp = head;
        while (temp!= NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtIdx(int val, int idx)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invaild";
            return;
        }
        else if (idx == 0)
            insertAtHead(val);
        else if (idx == size)
            insertAtEnd(val);
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            Node *t = new Node(val);
            t->next = temp->next;
            temp->next = t;
        }
        size++;
    }
    void deleteAtHead()
    {
        if (size == 0)
        {
            cout << "Invalid List";
            return;
        }
        head = head->next;
        size--;
    }
    void deleteAtEnd()
    {
        if (size == 0)
        {
            cout << "Invalid List";
            return;
        }
       Node*  temp=head;
       while(temp->next!=tail){
        temp=temp->next;
       }
       temp->next=NULL;
       temp=tail;
        size--;
    }
    void deleteAtIdx(int idx){
        if (idx<0||idx>size)
        {
            cout << "Invalid List";
            return;
        }
        else if(idx==1) deleteAtHead();
        else if(idx==size-1) deleteAtEnd();
        else{
            Node* temp=head;
            for(int i=0;i<idx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
        size--;
    }
    int getIdx(int idx){
        Node* temp=head;
        for(int i=0;i<=idx-1;i++){
            temp=temp->next;
        }
        return temp->val;
    }
};
int main(){
    LinkedList ll;
    ll.insertAtHead(10);
    ll.insertAtHead(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);
    ll.insertAtEnd(60);
    ll.insertAtEnd(70);
    ll.insertAtEnd(80);
    cout<<"LinkedList is Created"<<endl;
    cout<<"Display : ";
    ll.display();
    cout<<"Size : "<<ll.size<<endl;
    cout<<"Insert 150 at index 4 : ";
    ll.insertAtIdx(150,4);
    cout<<"Display : ";
    ll.display();
    cout<<"Size : "<<ll.size<<endl;
    cout<<"Delete at head : ";
    ll.deleteAtHead();
     cout<<"Display : ";
    ll.display();
    cout<<"Size : "<<ll.size<<endl;
    cout<<"Delete at end : ";
    ll.deleteAtEnd();
    cout<<"Display : ";
    ll.display();
    cout<<"Size : "<<ll.size<<endl;
    cout<<"Delete at index 3 : ";
    ll.deleteAtIdx(3);
    cout<<"Display : ";
    ll.display();
    cout<<"Size : "<<ll.size<<endl;
    cout<<"Get the value at index 3 : ";
    cout<<ll.getIdx(3);
    return 0;
}
