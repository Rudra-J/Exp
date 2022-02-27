#include <iostream>
using namespace std;

int t=-1;
int f=-1;

int main()
{
    cout<<"Enter the length of the circular que:\n"; 
    int l;
    cin >> l;
    int a[l];
    int n=0;
    int count=0;
    while(n==0)
    {
        cout<<"Enque:1 , deque:2 , display:3 , exit:4"<<endl;
        int in ;
        cin >> in;
        switch (in)
        {
            case 1:
                    if((t+1)%l==f and f!=t) cout<<"Que Full! \n";
                    else
                    {
                        if(f==-1) f++;
                        t=(t+1)%l;
                        cin>>a[t];
                    }
                    break;
            case 2:
                    if(f==t)
                    {
                        f=-1;t=-1;
                    }
                    if (f==-1) cout<<"Que Empty! \n";
                    else
                    {
                        f=(f+1)%l;
                    }
                    break;
            case 3:
                    if (f!=-1){
                    for (int i=f;i!=t;i=(i+1)%l)
                    {
                        cout<<a[i]<<" ";
                    }
                    cout<<a[t];
                    cout<<endl;}
                    else cout<<"Que Empty! \n";
                    break;
            case 4: exit(0);
        }
    }
}
