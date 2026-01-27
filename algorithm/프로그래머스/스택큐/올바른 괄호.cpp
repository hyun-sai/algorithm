#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector <char> stack;
    for (char i : s)
    {
        if (i == '(')
        {
            stack.push_back(i);
        }
        if (i == ')')
        {
            if (stack.empty())
            {
                answer = false;
                break;
            }
            stack.pop_back();
        }
    }
    if (!stack.empty())
    {
        answer = false;
    }

    return answer;
}