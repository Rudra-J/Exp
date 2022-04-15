#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct node
{
    int n;
    node* nxt=NULL;
    node* prev=NULL;
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

int main()
{
    cout<<"Enter the number of nodes: \n";
    int a;cin>>a;
    cout<<"Enter the node values: \n";
    int v[a];
    for(int i=0;i<a;i++) cin>>v[i];

    int mat[a][a]={};
    int c=0;
    while(c<a)
    {
        cout<<"Enter num of nodes "<<v[c]<<" is connected to"<<endl;
        int in;
        cin>>in;
        for(int i=0;i<in;i++)
        {
            int o;
            cin>>o;
            cout<<"weight: ";
            int w;
            cin>>w;
            mat[c][o-1]=w;
        }
        c++;
    }
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<a;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    int vis[a]={};
    int sh[a]={};
    int prev[a]={};
    for (int i=0;i<a;i++) vis[i]=0;
    for (int i=0;i<a;i++) prev[i]=0;
    cout<<"Enter the source element: ";
    int source;
    cin>>source;
    for (int i=0;i<sizeof(v)/sizeof(v[0]);i++)
    {
        if(i!=source-1) sh[i]=999999999;
        else sh[i]=0;
    }

    push(source-1);
    vis[source-1]=1;

    while(head!=NULL)
    {
        int l=pop();
        for (int i=0;i<a;i++)
        {
            if(mat[l][i]!=0)
            {
                if(sh[i]>(sh[l]+mat[l][i])) { sh[i]=sh[l]+mat[l][i]; prev[i]=l+1; }
                if(vis[i]==0) { push(i); vis[i]=1; }
            }
            
        }
    }
    for (int i=0;i<a;i++)
    {
        cout<<i+1<<" at a dist of "<<sh[i]<<" Through "<<prev[i]<<endl;
    }
}