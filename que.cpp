#include <iostream>
using namespace std;

int top=-1;
int* nq(int a[])
{
    top++;
    cin >> a[top];
    return a;
}

int* dq(int a[])
{
    for (int i = 1; i <=top; i++) 
    {
        a[i-1]=a[i];
    }
    top--;
    return a;
}
int main()
{
    cout<<"Enter the que length\n";
    int l;
    cin >> l;
    int a[l];
    int n=0;
    while (n==0)
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
                    if (top>=0) dq(a);
                    else cout<<"Que Empty\n";
                    break;
            case 3:
                    for(int i=0; i<=top;i++)
                    {
                        cout<<a[i]<<" ";
                    }
                    cout<<endl;
                    break;
            case 4: exit(0);
        }
    }
}