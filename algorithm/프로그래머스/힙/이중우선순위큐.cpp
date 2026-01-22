#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> answer2;
    

    for (string s : operations)
    {
        if (s[0] == 'I')
        {
            if (s[2] == '-')
            {
                int sign = -1;
                int sum = 0;
                for (int i = 3; i < s.size(); i++) //여기서 stoi를 사용해보자
                {
                    sum *= 10;
                    sum += (s[i] - '0');
                }
                answer2.push_back(sum * sign);
            }
            else
            {
                int sign = 1;
                int sum = 0;
                for (int i = 2; i < s.size(); i++)
                {
                    sum *= 10;
                    sum += (s[i] - '0');
                }
                answer2.push_back(sum);
            }
            

        }
        if (s[0] == 'D' && s[2]=='1')
        {
            if (answer2.empty() == true)
            {
                continue;
            }
            make_heap(answer2.begin(), answer2.end());
            pop_heap(answer2.begin(), answer2.end());
            answer2.pop_back();
        }
        if (s[0] == 'D' && s[2] == '-')
        {
            if (answer2.empty() == true)
            {
                continue;
            }
            make_heap(answer2.begin(), answer2.end(), greater<int>());
            pop_heap(answer2.begin(), answer2.end(), greater<int>());
            answer2.pop_back();
        }
        
        
    }
    if (answer2.empty() == true)
    {
        return { 0,0 };
    }
    sort(answer2.begin(), answer2.end());
    answer.push_back(answer2[answer2.size() - 1]);
    answer.push_back(answer2[0]);
    return answer;
}
int main(void)
{
    vector <string> a = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};

    vector <int> b;
    b = solution(a);
    cout << b[0] << b[1];
}
