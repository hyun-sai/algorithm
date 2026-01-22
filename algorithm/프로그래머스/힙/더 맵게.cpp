#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream> 
 // greater가 존나게 이해가 안된다

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    make_heap(scoville.begin(), scoville.end(), greater<int>());
    
    while (true)
    {
        bool stop = true;
        if (scoville.front() < K)
        {
            stop = false;
        }
        //
        for (int i : scoville)
        {
            if (i < K)
            {
                stop = false;
                break;
            }
        }
        //
        if (stop == true)
        {
            break;
        }
        if (scoville.size() < 2) //예외처리 브로
        {
            return -1;
        }
        int a = scoville.front();
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        scoville.pop_back();
        int b = scoville.front();
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        scoville.pop_back();
        scoville.push_back(a + b * 2);
        push_heap(scoville.begin(), scoville.end(), greater<int>());
        answer++;
    }
    return answer;
}
