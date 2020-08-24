/* Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23 */

class Solution {
public:
    int compute(int a, int b, char op)
    {
        if (op == '+')
            return a+b;
        if (op == '-')
            return b-a;
        return 0;
    }
    int precedence(char a, char b)
    {
        if (a=='-')
            return 1;
        return 0;
    }
    int calculate(string s) {
        stack<int> operands;
        stack<int> operators;
        int i=0;
        while (i< s.size())
        {
            if (s[i] == '(')
            {
                operators.push(s[i]);
                i++;
            }
            if (s[i] == '+' or s[i] == '-')
            {
                while (operators.size()>0 and precedence(operators.top(),s[i])>0)
                {
                    int a = operands.top(); operands.pop();
                    int b = operands.top(); operands.pop();
                    operands.push(compute(a, b, operators.top()));
                    operators.pop();
                }
                operators.push(s[i]);
                i++;
            }
            else if (isdigit(s[i]))
            {
                int num = 0;
                while (i<s.size() and isdigit(s[i]))
                {
                    num = num*10 + (s[i] - '0');
                    i++;
                }
                operands.push(num);
            }
            else if (s[i]==')')
            {
                while (operators.top()!='(')
                {
                    int a = operands.top(); operands.pop();
                    int b = operands.top(); operands.pop();
                    operands.push(compute(a, b, operators.top()));
                    operators.pop();
                }
                operators.pop();
                i++;
            }
            else
                i++;
            
        }
        while (!operators.empty())
        {
            int a = operands.top(); operands.pop();
            int b = operands.top(); operands.pop();
            operands.push(compute(a, b, operators.top()));
            operators.pop();
        }
        return operands.top();
    }
};