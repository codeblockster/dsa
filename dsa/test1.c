#include<iostreaam>
using  namespace std;
int maxsize=4;
int stack[4];
int top=-1;
void isfull(){
if(top==maxsize-1)
    return 1;
else
    return 0;
}
void isempty(){
if(top==-1)
    return 1;
else
    return 0;
}
void peek(){
cout<<stack[top];
}
void pop()
{
    if(!isempty)
    {
        cout<<stack[top];
        top--;

    }
    else
        cout<<"stack is empty"<<endl;
}

void push()
{   int data;
    if(!isfull)
    {
        cin>>stack[top];
        top++;

    }
    else
        cout<<"stack is full"<<endl;
}

int main()
{
    cout<<"enter choice\n 1 for push\2for pop\n 3 for seek\n 4 for exit"<<endl;
    cin>>int a;
    if(a==1)
    {
        push();
    }
    else if(a==2)
    {
        pop();
    }
    else if(a==3)
    {
        peek();
    }
    else if(a==4)
    {
        break;
    }
    else{
        cout<<"invalid choice"<<endl;
    }
    return 0;
}
