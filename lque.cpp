#include <iostream>
using namespace std;

int top=-1;
int f=-1;

int* nq(int a[])
{
    if(top==-1) f++;
    top++;
    cin >> a[top];
    return a;
}

int* dq(int a[])
{
    if(top==f and f==sizeof(a)-1) {top=-1;f=-1;}
    else f++;
    return a;
}

int main()
{
    cout<<"Enter the que length\n";
    int l;
    cin >> l;
    int a[l];
    while (f<l)
    {
        cout<<"Enque:1 , deque:2 , display:3 , exit:4"<<endl;
        int in ;
        cin >> in;
        switch (in)
        {
            case 1:
                    if(top<l-1) nq(a);
                    else cout<<"Que Full\n";
                    break;
            case 2:
                    if (top==-1) cout<<"Que Empty\n";
                    else dq(a);
                    break;
            case 3:
                    for(int i=f; i<=top;i++)
                    {
                        cout<<a[i]<<" ";
                    }
                    cout<<endl;
                    break;
            case 4: exit(0);
        }
    }
}