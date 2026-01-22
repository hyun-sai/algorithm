#include <string>
#include <vector>
#include <deque>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    struct number
    {
        int high;
        int index;
    };
    vector <number> numbers(priorities.size());
    for (int i = 0; i < priorities.size(); i++)
    {
        numbers[i].high = priorities[i];
        numbers[i].index = i;
    }
    deque <number> q;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push_back({ numbers[i].high ,numbers[i].index});
    }
    while (true)
    {
        number compare = q.front();
        bool excute = true;
        for (int j = 1; j < q.size();j++)
        {
            if (q.front().high < q[j].high)
            {
                excute = false;
                q.push_back(q.front());
                q.pop_front();
                break;
            }
        }
        if (excute == true)
        {
            answer++;
            if (q.front().index == location)
            {
                break;
            }
            q.pop_front();
        }
            
    }
    return answer;
}
