#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
    int answer = 0;
    string numbers = "17";
    vector<int> v;
    vector<int> v2; //모든 경우의 수를 담을 vector
    for (char c : numbers)
    {
        int num = c - '0'; // c=c-'0'는 빼서 다시 char에다가 넣는 꼴 
        v.push_back(num);

    }
    
    int r = 1, size = v.size(); // 자릿수 cnt
    while (r <= size) {
        sort(v.begin(), v.end());
        do {
            int sum = 0;
            for (int i = 0; i < r; i++)
            {
                if (i == 0 && v[i] == 0)
                {
                    break;
                }
                sum *= 10;
                sum+=v[i];
            } 
            if (sum != 0)
            {
                v2.push_back(sum);
            }
            reverse(v.begin() + r, v.end());
        } while (next_permutation(v.begin(), v.end()));
        r++;
    }
    for (int number : v2)
    {
        if (number < 2) continue;
        bool primary = true;
        for (int j = 2; j <= sqrt(number); j++)
        {
            
            if (number % j == 0)
            {
                primary = false;
                break;
            }
            
        }
        if (primary == true)
        {
            answer++;
        }
    }
    
    return answer;
}
