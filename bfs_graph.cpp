#include <iostream>
using namespace std;

struct node 
{
    int n;
    node* nxt=NULL;
};

node* head=NULL;

void push(int b)
{
    if(head==NULL)
    {
        node* n=new node;
        n->n=b;  
        head=n;      
    }
    else
    {
        node* n=new node;
        node *c=head;
        while(c->nxt!=NULL) c=c->nxt;
        c->nxt=n;
        n->n=b;
    }    
}

int pop()
{
    if(head->nxt==NULL) 
    {
        node* n=head;
        head=NULL;
        return n->n;
    }
    else 
    {
       node* r=head;
       head=head->nxt;
       return r->n;
    }
}

void dsp()
{
    node * n=head;
    while(n !=NULL) {cout<<n->n<<" ";n=n->nxt;}
    cout<<endl;
}

int main()
{
    cout<<"Enter the number of nodes:\n";
    int a ;
    cin >> a;
    int v[a]={};
    cout<<"Enter node values:\n";
    for (int i=0; i<a; i++) 
    {
        cin>>v[i];
    }
    int in[a][a]={};
    cout<<"Enter connection matrix:\n";
    for (int i =0;i<a;i++)
    {
        for (int j =0;j<a;j++)
        {
            cin >> in[i][j];
        }
    }
    int vis[a]={};

    for (int i=0;i<a;i++) vis[i]=0;
 
    int c=0;
    push(c);
    vis[c]=1;
    cout<<endl;
    while(head!=NULL)
    {
        int i=pop();
        cout<<v[i]<<" ";
        for (int j=0;j<a;j++)
        {
            if(in[i][j]==1 and vis[j]==0)
            {
                vis[j]=1;
                push(j);
            } 
        }
    }
}