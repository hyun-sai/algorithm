#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 1; i <= prices.size(); i++)
    {
        int count = 0;
        bool onemoretime = true;
        for (int j = i; j < prices.size(); j++)
        {
            count++;
            if (prices[i - 1] > prices[j])
            {

                break;
            }

        }
        answer.push_back(count);
    }
    return answer;
}