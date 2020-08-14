// https://leetcode.com/problems/valid-parentheses/

/* SHORT EXPLAINATION - 
Whenever you encounter a opening bracket, push it into stack.
whenever you encounter closing bracket, check the top element of stack. 
If the top element is opening bracket of same type pop it, 
else in all conditions push the bracket in stack.
After iterating the string, the stack must be empty.
*/

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')st.push(s[i]);
            else 
            {
                if(st.empty())st.push(s[i]);
                else
                {
                    if(s[i] == ')' and st.top() == '(')st.pop();
                    else if(s[i] == ']' and st.top() == '[')st.pop();
                    else if(s[i] == '}' and st.top() == '{')st.pop();
                    else st.push(s[i]);
                }
            }
        }
        return st.empty();
    }
};
