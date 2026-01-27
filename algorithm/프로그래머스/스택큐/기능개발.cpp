#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> day;
    for (int i = 0; i < progresses.size(); i++)
    {
        int x = 1;
        while ((progresses[i] + (speeds[i] * x)) < 100)
        {
            x++;
        }
        day.push_back(x);
        cout << x;
    }
    while (day.empty() != true)
    {
        int count = 0;
        int a = day.front();
        day.pop_front();
        count++;
        while (!day.empty() && day.front() <= a)
        {
            day.pop_front();
            count++;
        }
        answer.push_back(count);
    }
    return answer;
}