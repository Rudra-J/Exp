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
        cout<<"Insert at the front:1\nInsert at the back:2\nInsert after specific node:3\nDelete from the front:4\nDelete from the back:5\nDelete specific node:6\nDisplay:7\nDisplay rev:8\nExit:9"<<endl;
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
                        n->next=head;
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
                        prev->next=n;
                        prev=n;                        
                    }
                    break; }
            case 3: 
                   { cout<<"Enter node number: \n";int num=0;cin >> num;
                    node *t=head;
                    while(t!=NULL)
                    {
                        if(num==1) break;
                        else
                        {
                            t=t->next;
                            num--;
                        }
                    }
                    if(num!=1) cout<<"Entered node out of range\n";
                    else
                    {
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        n->pre=t;
                        n->next=t->next;
                        t->next->pre=n;
                        t->next=n;
                    }
                    break;}
            case 4:
                    {if(head==NULL) cout<<"List is empty! \n";
                    else if(prev->pre==NULL)
                    {
                        head=NULL;
                        delete prev;
                    }
                    else
                    {
                        struct node* u=head;
                        head=u->next;
                        head->pre=NULL;
                        delete u;
                    }
                    delete n;
                    break;}
            case 5:
                   { if(head==NULL) cout<<"List is empty! \n";
                    else if(prev->pre==NULL)
                    {
                        head=NULL;
                        delete prev;
                    }
                    else
                    {
                        struct node* v=prev;
                        prev=v->pre;
                        delete v;
                        prev->next=NULL;
                    }
                    delete n;
                    break;}
            case 6:
                    {cout<<"Enter node number: \n";int num1=0;cin >> num1;
                    node *w=head;
                    while(w!=NULL)
                    {
                        if(num1==1) break;
                        else
                        {
                            w=w->next;
                            num1--;
                        }
                    }
                    if(num1!=1) cout<<"Entered node out of range\n";
                    else
                    {
                        w->pre->next=w->next;
                        w->next->pre=w->pre;
                        delete w;
                    }
                    delete n;
                    break; }
            case 7:
                   {if(head==NULL) cout<<"List is empty! \n";
                   else
                   {
                       cout<<endl;
                       struct node* x=head;
                       while(x!=NULL)
                       {
                           cout<<x->no<<endl;
                           x=x->next;
                       }
                       cout<<endl;
                   }
                   delete n; 
                   break;}
            case 8:
                   {if(head==NULL) cout<<"List is empty! \n";
                   else
                   {
                       cout<<endl;
                       struct node* y=prev;
                       while(y!=NULL)
                       {
                           cout<<y->no<<endl;
                           y=y->pre;
                       }
                       cout<<endl;
                   } 
                   delete n;
                   break;}
            case 9: exit(0);
        }
    }
}