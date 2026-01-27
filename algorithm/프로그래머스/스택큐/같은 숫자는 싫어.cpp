#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((answer.empty() == true) || (arr[i] != answer.back()))
        {
            answer.push_back(arr[i]);
        }
        else
        {
            continue;
        }
    }
    return answer;
}