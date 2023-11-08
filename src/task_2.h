#include <iostream>
#include <stack>
#include <string>

bool isValidExpression(int n, std::string brackets) {
    std::stack<char> st;
    
    for (int i = 0; i < n; i++) {
        char bracket = brackets[i];
        
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            st.push(bracket);
        } else {
            if (st.empty()) {
                return false;
            }
            
            char top = st.top();
            st.pop();
            
            if ((bracket == ')' && top != '(') ||
                (bracket == ']' && top != '[') ||
                (bracket == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return st.empty();
}