#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

char op[]={'+','-','*','/','^'};
int st[1000];
string n[1000];
int top=-1;
int stp=-1;

int in(char a)
{
    for (int i=0;i<sizeof(op)/sizeof(op[0]);i++)
    {
        if(a==op[i]) return 1;
    }
    return 0;
}

int sp(string a)
{
    string op="";
    for (int i=0;i<a.length();i++)
    {
        if(in(a[i])==1)
        {
            top++;
            op=op+a.at(i);
            n[top]=op;
            op="";
        }
        else if(a.at(i)==' ')
        {
            top++;
            n[top]=op;
            op="";
        }
        else
        {
            op=op+a.at(i);
        }
    }
    top++;
    n[top]=op;
    op="";
}

void push(int a)
{
    if(stp+1!=1000)
    {
        stp++;
        st[stp]=a;
    }
    else 
    {
        cout<<"Stack overflow";
        exit(0);
    }
}

int pop()
{
    if(stp>=0)
    {
        int r= st[stp];
        stp--;
        return r;
    }
    else 
    {
        cout<<"Stack underflow";
        exit(0);
    }
}

int main()
{
    cout<<"Enter the postfix notation space separated:\n";
    string a;
    int o=0;
    string opp="";
    getline(cin,a);
    sp(a);
    cout<<endl;
    for (int i=0;i<=top;i++)
    {
        if(in(n[i][0])==1)
        {
            int in1=pop();
            int in2=pop();
            switch(n[i][0])
            {
                case '+': 
                        push(in1+in2);
                        break;
                case '-': 
                        push(in1-in2);
                        break;
                case '*': 
                        push(in1*in2);
                        break;
                case '/': 
                        push(in1/in2);
                        break;
                case '^': 
                        push(pow(in1,in2));
                        break;                
            }
        }
        else if(n[i].length()!=0)
        {
            stringstream s(n[i]);
            int input=0;
            s>>input;
            push(input);
        }
    }
    cout<<st[stp];
}