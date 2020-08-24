/* Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5 */


class Solution {
public:
    int precedence(char c){
        switch (c){
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
        }
        return -1;
    }
    
    int performOperation(stack<int>& numbers, stack<char>& operations) {
        int a = numbers.top();
        numbers.pop();
        int b = numbers.top();
        numbers.pop();
        char operation = operations.top();
        operations.pop();
        switch (operation) {
            case '+':
                return a + b;
            case '-':
                return b - a;
            case '*':
                return a * b;
            case '/':
                if (a == 0)
                    return 0;
                return int (b / a);
        }
        return 0;
    }
    int calculate(string s) {
        if (s.empty())
            return 0;
        stack<int> operands;
        stack<char> operators;
        int result=0;
        int tmp=0;
        for (char ch: s)
        {
            if (isdigit(ch))
            {
                tmp = 10*tmp + (ch-'0');       
            }
            else if (ch == '+' or ch == '-' or ch == '/' or ch == '*')
            {
                operands.push(tmp);
                tmp = 0;
                if (operators.empty())
                {
                    operators.push(ch);
                }
                else
                {
                    while (!operators.empty() and precedence(operators.top()) >= precedence(ch))
                    {
                        result = performOperation(operands, operators);
                        operands.push(result);
                    }
                    operators.push(ch);
                }
            }
        }
        
        {
            if (operators.empty())
                return tmp;
            else
                operands.push(tmp);
        }
        while (!operands.empty())
        {
            result = performOperation(operands, operators);
            if (!operators.empty())
            {
                operands.push(result);
            }
        }
        return result;
    }