#include <iostream>
#include <string>
using namespace std;

char p[]={'+','-','*','/','^'};
int pi[]={1,1,2,2,3};
char s[10000];
int top=-1;

int in(char a)
{
    for (int i =0;i<sizeof(p);i++)
    {
        if(a==p[i]) return pi[i];
    }
    return 0;
}

string fix(string a)
{
    int cond=0;
    string op="";
    for (int i=0; i<a.length(); i++)
    {
        if(in(a.at(i))!=0)
        {
            if(top==-1)
            {
                top++;
                s[top]=a.at(i);
            }
            else
            {
                cond=0;
                while(cond ==0 and top>=0)
                {
                    
                    if(in(s[top])>in(a.at(i)) or in(s[top])==in(a.at(i)))
                    {
                        op=op+s[top];
                        top--;
                    }
                    else if (in(s[top])<in(a.at(i)) or s[top]=='(' or (in(s[top])==3 and in(a.at(i))==3))
                    {
                        top++;
                        s[top]=a.at(i);
                        cond++;
                    }
                }
                if(cond ==0) {top++;s[top]=a.at(i);}
            }
        }
        else if (a.at(i)=='(') {top++;s[top]=a.at(i);}
        else if (a.at(i)==')')
        {
            while(s[top]!='(')
            {
                op=op+s[top];
                top--;
            }
            top--;
        }
        else op=op+a.at(i);
    }
    while(top>=0)
    {
        op=op+s[top];
        top--;        
    }
    return op;
}

int main()
{
    cout<<"Enter the infix equation:\n";
    string a;
    getline(cin, a);
    cout<<endl;
    string b;
    for (int i =a.length()-1; i>=0;i--)
    {
        if(a.at(i)=='(') b=b+")";
        else if (a.at(i)==')') b=b+"(";
        else b=b+a.at(i);
    }
    cout<<"Postfix expansion:\n";
    cout<<fix(a);               
    cout<<endl;
    cout<<"Prefix expansion:\n";
    string c=fix(b);
    for (int i =c.length()-1; i>=0;i--)
    {
        cout<<c.at(i);
    }
}