#include <iostream>
using namespace std;


struct node
{
    int no=0;
    struct node* ptr=NULL;
};

struct node* h=NULL;

int main()
{
    struct node* prev=NULL;
    while (0<1)
    {
        
        struct node* n=new node;
        cout<<h<<endl;
        cout<<prev<<endl;
        cout<<"Insert at the front:1, Insert at the back:2, Delete from the front:3, Delete from the back:4, Display:5, Exit:6"<<endl;
        int in;
        cin >> in;
        switch(in)
        {
            case 1:
                    if(h==NULL) 
                    {
                        h=n;
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        prev=n;
                    }
                    else
                    {
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        n->ptr=h; 
                        h=n;                                      
                    }
                    break;
            case 2:
                    if(h==NULL)
                    {
                        h=n;
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        prev=n;
                    }
                    else
                    {
                        cout<<"Enter the element to insert: \n";int a;cin >> a;
                        n->no=a;
                        prev->ptr=n;
                        prev=n;                        
                    }
                    break; 
            case 3:
                    if(h==NULL) cout<<"List is empty!";
                    else
                    {
                        struct node* t=h;
                        h=t->ptr;
                        delete t;
                    }
                    break;
            case 4:
                    if(h==NULL) cout<<"List is empty!";
                    else
                    {
                        struct node* t=h;
                        while(t->ptr!=prev) t=t->ptr;
                        prev=t;
                        delete t->ptr;
                        t->ptr=NULL;
                    }
                    break;
            case 5:
                   if(h==NULL) cout<<"List is empty!";
                   else
                   {
                       cout<<endl;
                       struct node* t=h;
                       while(t!=NULL)
                       {
                           cout<<t->no<<endl;
                           t=t->ptr;
                       }
                   } 
                   break;
            case 6: exit(0);
        }
    }
}
