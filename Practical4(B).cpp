#include <iostream>
#include <stack>
#include <string>
using namespace std;

int p(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int main(){
    string s, post="";
    stack<char> op;
    cout<<"Enter Infix Expression: ";
    cin>>s;

    for(char c:s){
        if(isdigit(c))
            post+=c;
        else{
            while(!op.empty() && p(op.top())>=p(c)){
                post+=op.top();
                op.pop();
            }
            op.push(c);
        }
    }

    while(!op.empty()){
        post+=op.top();
        op.pop();
    }

    stack<int> st;
    for(char c:post){
        if(isdigit(c))
            st.push(c-'0');
        else{
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            if(c=='+') st.push(a+b);
            else if(c=='-') st.push(a-b);
            else if(c=='*') st.push(a*b);
            else if(c=='/') st.push(a/b);
        }
    }

    cout<<"Postfix = "<<post<<endl;
    cout<<"Result = "<<st.top();
    return 0;
}

