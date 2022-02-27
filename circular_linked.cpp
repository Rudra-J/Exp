#include <iostream>
using namespace std;

struct node 
{
    int no=0;
    struct node* next=NULL;
    struct node* pre=NULL;
};

node* head =NULL;

int main()
{
    struct node* prev=NULL;
    while (0<1)
    {
        struct node* n=new node;
        cout<<head<<endl;
        cout<<prev<<endl;
        cout<<"Insert at the front:1\nInsert at the back:2 \nDelete from the front:3\nDelete from the back:4\nDisplay:5\nDisplay rev:6\nExit:7"<<endl;
        int in;
        cin >> in;
        switch(in)
        {
            case 1:
                    {if(head==NULL) 
                    {
                        head=n;
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        prev=n;
                    }
                    else
                    {
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        head->pre=n;
                        prev->next=n;
                        n->next=head;
                        n->pre=prev;
                        head=n;                                  
                    }
                    break;}
            case 2:
                    {if(head==NULL)
                    {
                        head=n;
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        prev=n;
                    }
                    else
                    {
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        n->pre=prev;
                        n->next=head;
                        prev->next=n;
                        prev=n;
                        head->pre=prev;                        
                    }
                    break;} 
            case 3:
                    {if(head==NULL) cout<<"List is empty! \n";
                    else if(head->next==head)
                    {
                        node* t=head;
                        head=NULL;
                        delete t;
                    }
                    else
                    {
                        struct node* t=head;
                        head=t->next;
                        head->pre=prev;
                        prev->next=head;
                        delete t;
                    }
                    break;}
            case 4:
                    {if(head==NULL) cout<<"List is empty! \n";
                    else if(prev->pre==prev)
                    {
                        head=NULL;
                        delete prev;
                    }
                    else
                    {
                        struct node* t=prev;
                        prev=t->pre;
                        prev->next=head;
                        head->pre=prev;
                        delete t;
                    }
                    break;}
            case 5:
                   {if(head==NULL) cout<<"List is empty! \n";
                   else
                   {
                       cout<<endl;
                       struct node* t=head;
                       cout<<t->no<<endl;
                       t=t->next;
                       while(t!=head)
                       {
                           cout<<t->no<<endl;
                           t=t->next;
                       }
                       cout<<endl;
                   } 
                   break;}
            case 6:
                   {if(head==NULL) cout<<"List is empty! \n";
                   else
                   {
                       cout<<endl;
                       struct node* t=prev;
                       cout<<t->no<<endl;
                       t=t->pre;
                       while(t!=prev)
                       {
                           cout<<t->no<<endl;
                           t=t->pre;
                       }
                       cout<<endl;
                   } 
                   break;}
            case 7: exit(0);
        }
    }
}