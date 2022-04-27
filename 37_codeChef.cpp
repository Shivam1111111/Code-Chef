#include<iostream>
#include<stack>
using namespace std;

int isBalanced(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
            continue;
        }

        //found closing bracket and stack empty. hence string is not balanced
        if(st.empty()){
            return 0;
        }

        if(
            (s[i] == ')' && st.top() == '(') ||
            (s[i] == '}' && st.top() == '{') ||
            (s[i] == ']' && st.top() == '[')
        ) {
            st.pop();
        } else {
            return 0;
        }
    }
    return st.empty() ? 1 : 0;
}

int main(){

    string s;
    cin >> s;
    cout << isBalanced(s) << endl;
       

    return 0;
}