#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    struct process
    {
        int number;
        int index;
    };
    deque <process> prior;
    for (int i = 0; i < priorities.size(); i++)
    {
        prior.push_back({ priorities[i],i });
    }
    while (!prior.empty())
    {
        int max = prior.front().number;
        bool excute = true;
        for (int i = 0; i < prior.size(); i++)
        {
            if (prior[i].number > max)
            {
                excute = false;
                break;
            }
        }
        if (excute == true)
        {
            answer++;
            if (location == prior.front().index)
            {
                return answer;
            }
            prior.pop_front();

        }
        else
        {
            prior.push_back(prior.front());
            prior.pop_front();
        }
    }
}