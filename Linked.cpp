# Labt1.cpp
//question 1
#include <iostream>
using namespace std;
// OUTER CLASS NODE OF THE LINKED LIST
class Node{
public:
    int data; //TO TAKE VALUES OF NODE
    Node*next; //TO POINT TO NEXT NODE
// INITIALISATION OF NODE CONTENTS
    Node(){
        data=0;
        next=NULL;
    }
};

//CLASS DECLARATION FOR LINKED LIST
class LinkedList{
private:
    Node *head; //FOR STARTING VALUES
    Node *tail; //FOR ENDING VALUES
    int n; //TO TAKE SIZE SIZE OF LinkedList
public:
//INITIALISATION OF LINKEDLIST
    LinkedList(){
    head=NULL;
    tail=NULL;
    n=0;
}
//FOR INSERTING NODE AT THE END
    void Insert(int x){     //X IS THE VALUE ENTERED BY USER TO BE INSERTED
        Node *temp=new Node;
        temp->data=x;
        temp->next=NULL;
        ++n;
        //TO CHECK IF THE LIST IS EMPTY OR NOT
        if (head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
//FOR INSERTING NODE AT GIVEN POSITION
    void InsertAt(int x, int y){        //X=DATA AND Y=POSITION
        if (y>n+1)  
          {  cout<<"Not enough nodes."<<endl;
        }
        else if (y==n+1){
            Insert(x);
            ++n;
        }
        else if (y==1){
            Node *temp=new Node;
            temp->data=x;
            temp->next=head;
            head=temp;
            ++n;
        }
        else {
            Node *locate;    //TO FIND THE POSITION WHERE THE NODE IS TO BE INSERTED
            locate=head;
            for (int i=1;i<y-1;i++){
                locate=locate->next;
            }
            Node *temp=new Node;
            temp->data=x;
            temp->next=locate->next;
            locate->next=temp;
            ++n;
        }
    }
//DELETING AN ELEMENT FROM END
    void Delete()
    {
        Node *locate;  //TO FIND THE LAST NODE
        locate=head;
        while (locate->next!=tail){
            locate=locate->next;
        }
        delete tail;
        tail=locate;
        locate->next=NULL;
        --n;          //TO DECREMENT THE NUMBER OF NODES OF LinkedList
    }
//DELETING AN ELEMENT FROM A GIVEN POSITION
    void DeleteAt(int x){
        if (x>n)
            cout<<"Not enough elements."<<endl;
        else if(x==1){
            Node *temp;   
            temp=head;
            head=temp->next;
            delete temp;
        }
        else {
            Node *locate;         //TO FIND THE POSITION OF THE NODE TO BE DELETED
            locate=head;
            for (int i=1;i<x-1;i++){
                locate=locate->next;
            }
            Node *temp;
            temp=locate->next;
            locate->next=temp->next;
            delete temp;
        }
        }
//TO COUNT THE NUMBER OF ELEMENTS IN THE  LinkedList
    int Count(){
    Node *count;
    count=head;
    while(count!=NULL){
     count=count->next;
     n++;
    }
    return n;
   }
//DISPLAY THE ELEMENTS OF LinkedList
    void Display(){
        Node *disp;
        disp=head;
        while (disp!=NULL){
            cout<<endl<<endl<<disp->data<<endl;
            disp=disp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList List1;
    int s;
    do {
    cout<<"Choose one of the following: \n 1.Insert \n 2.InsertAt \n 3.Delete \n 4.DeleteAt\n 5.Count \n 6. Display \n 7.Exit\n\n";
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cin>>s;
    switch(s)
    {
     case 1:
        cout<<"Enter the element to be added:\n"<<endl;
        int x;
        cin>>x;
        List1.Insert(x);
        break;
    case 2:
        cout<<"Enter the element to be inserted and it's position: \n"<<endl;
        int a,b;
        cin>>a>>b;
        List1.InsertAt(a,b);
        break;
    case 3:
        List1.Delete();
        break;
    case 4:
        cout<<"Enter the position of the element to be deleted:"<<endl;
        int c;
        cin>>c;
        List1.DeleteAt(c);
        break;
    case 5:
        cout<<"The number of elements in the LinkedList is: "<<List1.Count()<<endl;
        break;
    case 6:
        List1.Display();
        break;
    default:
        s=7;
        cout<<"\nPlease enter correct choice(1-6)!!";
        break;
    }
} while (s!=7);
return 0;
}
