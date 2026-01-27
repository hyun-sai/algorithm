#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue <int> bridge;
    queue <int> truck_weights_queue;
    for (int i = 0; i < truck_weights.size(); i++)
    {
        truck_weights_queue.push(truck_weights[i]);
    }

    for (int i = 0; i < bridge_length; i++)
    {
        bridge.push(0);
    }
    int count = 0;
    int present_weight = 0;
    while (!truck_weights_queue.empty())
    {
        present_weight -= bridge.front();
        bridge.pop();
        count++;
        if ((present_weight + truck_weights_queue.front()) <= weight)
        {
            present_weight += truck_weights_queue.front();
            bridge.push(truck_weights_queue.front());
            truck_weights_queue.pop();
        }
        else
        {
            bridge.push(0);
        }

    }
    answer = count + bridge_length;
    return answer;
}