#include <iostream>
#include <stack>
#include <string>

int evaluateExpression(std::string expression) {
    std::stack<int> st;
    
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int operand2 = st.top();
            st.pop();
            
            int operand1 = st.top();
            st.pop();
            
            switch(ch) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
            }
        }
    }
    
    return st.top();
}