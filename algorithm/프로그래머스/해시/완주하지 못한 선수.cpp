#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int index = -1;
    for (int i = 0; i < completion.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        index = participant.size() - 1;
    }
    answer = participant[index];
    return answer;
}