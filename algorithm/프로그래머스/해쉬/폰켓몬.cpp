#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    sort(nums.begin(), nums.end());
    int count = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (count == (nums.size() / 2))
        {
            break;
        }
        if (nums[i] != nums[i + 1])
        {
            count++;
        }

    }
    answer = count;
    return answer;
}