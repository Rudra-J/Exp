#include <iostream>
using namespace std;

int main()
{
    int n=0;
    int top=-1;
    cout<<"Enter the size of the stack:\n";
    int s;
    cin >> s;
    int st[s];
    while (n==0)
    {
        cout<<"Insert val:1 , delete val:2 , display:3 , exit :4 \n";
        int in;
        cin >> in;
        switch (in)
        {
            case 1:
                    if (top==s-1) 
                    {
                        cout<<"Stack overflow , cant insert \n";
                    }
                    else
                    {
                        top++;
                        cin >> st[top];
                    }
                    break;
            case 2:
                    if (top<0) 
                    {
                        cout<<"Stack underflow , cant delete \n";
                    }
                    else
                    {
                        top--;
                    }
                    break;
            case 3:
                    for (int i=0; i<=top;i++)
                    {
                        cout<<st[i]<<" ";
                    }
                    cout<<endl;
                    break;
            case 4: exit(0);
        }
    }
}