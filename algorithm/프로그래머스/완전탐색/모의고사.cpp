#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct a_student
{
    vector<int> pattern = { 1,2,3,4,5 };
    int size = 5;
    int count=0;
};
struct b_student
{
    vector<int> pattern = { 2,1,2,3,2,4,2,5};
    int size = 8;
    int count=0;
};
struct c_student
{
    vector<int> pattern = { 3,3,1,1,2,2,4,4,5,5 };
    int size = 10;
    int count=0;
};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int size = answers.size();
    int i;
    a_student a;
    b_student b;
    c_student c;
    for (i = 0; i < size; i++)
    {
        if (a.pattern[i % a.size] == answers[i])
        {
            a.count++;
        }
        if (b.pattern[i % b.size] == answers[i])
        {
            b.count++;
        }
        if (c.pattern[i % c.size] == answers[i])
        {
            c.count++;
        }
    }
    int x = std::max({ a.count, b.count, c.count });
    if (x == a.count)
    {
        answer.push_back(1);
    }
    if (x == b.count)
    {
        answer.push_back(2);
    }
    if (x == c.count)
    {
        answer.push_back(3);
    }
    
    return answer;
}
