#include <iostream>
using namespace std;

struct node
{
    int n;
    node* prev;
    node* right=NULL;
    node* left=NULL;

};

node* head = NULL;

void post(node* a)
{ 
    if (a==NULL) return;
    post(a->left);
    post(a->right);
    cout<<a->n<<" ";
}

void pre(node* a)
{ 
    if (a==NULL) return;
    cout<<a->n<<" ";
    pre(a->left);
    pre(a->right);
    
}

void ino(node* a)
{ 
    if (a==NULL) return;
    ino(a->left);
    cout<<a->n<<" ";
    ino(a->right);
}

node* search(int a)
{
    int cond=0,counter=0;
    node* t=head;
    while(t!=NULL and cond==0)
    {
        if(a<t->n) t=t->left;
        else if (a>t->n) t=t->right;
        else if (a==t->n) 
        {
            cond=1;
            break;
        }
    }
    if (cond==1)
    {
        cout<<"Element found at memory address "<<t<<endl;
        return t;
    }
    else
    {
        cout<<"Element not found \n";
    }
    return NULL;
}

int cnt(node* a)
{
    if(a==NULL) return 0;
    else
    {
        return cnt(a->left)+1+cnt(a->right);
    }
} 

void insert(int a)
{
    node* n=new node; 
    n->n=a;
    node* t=head;
    while(t!=NULL)
    {
        if(a<t->n)
        {
            if(t->left==NULL)
            {
                t->left=n;
                n->prev=t;
                break;
            }
            else t=t->left;
        }
        else if (a>t->n)
        {
            if(t->right==NULL)
            {
                t->right=n;
                n->prev=t;
                break;
            }
            else t=t->right;
        }
        else 
        {
            cout<<"Element exists";
            break;
        }
    }
}

void dlt(node* a)
{
    if(a->left==NULL and a->right==NULL) 
    {
        if(a==head) {head=NULL;delete a;}
        if(a->prev->right->n=a->n) a->prev->right=NULL;
        else a->prev->left=NULL;
        delete a;
    }
    else if ( (a->left==NULL and a->right!=NULL) or (a->right==NULL and a->left!=NULL) )
    {
        if(a->left!=NULL)
        {
            a->n=a->left->n;
            a->prev->left==NULL;
            delete a->left;
        }
        else
        {
            a->n=a->right->n;
            a->prev->right==NULL;
            delete a->right;
        }
    }
    else
    {
        node* n=a;
        while(n->left!=NULL) n=n->left;
        n->prev->left=NULL;
        a->n=n->n;
        delete n;
    }
}

int main()
{
    node* prev = NULL;
    while(0<1)
    {
        cout<<endl;
        cout<<"Insert element:1  \t Nodes:"<<cnt(head)<<"\nSearch element:2 \nDisplay:3 \nDelete Element:4 \nExit: anything else \n";
        int in ;
        std::cin >> in;
        cout<<endl;
        switch(in)
        {
            case 1:
                    {
                        cout<<"Enter the element \n";
                        int a;
                        std::cin >> a;
                        if(head==NULL)
                        {
                            node* n=new node;
                            head=n;
                            n->n=a;
                        }
                        else
                        {
                            insert(a);
                        }
                        break;
                    }
            case 2:
                    {
                        cout<<"Enter element you want to search";
                        int a;
                        std::cin>>a;
                        node* ch=search(a); 
                        if(ch==NULL) cout<<"Error: Search failed";
                        else cout<<"Element found at "<<ch;  
                        break;
                    }
            case 3:
                    {
                        if(head!=NULL)
                        {
                            cout<<"\nPost-order: \n";
                            post(head);
                            cout<<"\nPre-order: \n";
                            pre(head);
                            cout<<"\nIn-order: \n";
                            ino(head);
                            cout<<endl;
                        }
                        else cout<<"Sow a seed first\n";
                        
                        break;
                    }
            case 4:
                    {
                        cout<<"Enter the element you want to delete:\n";
                        int a;
                        std::cin>>a;
                        node* point=search(a);
                        if(point!=NULL)
                        {
                            dlt(point);
                        }
                        break;                        
                    }
            default:
                    exit(0);
        }
    }
}