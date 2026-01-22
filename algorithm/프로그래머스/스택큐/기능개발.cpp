#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class queue
{
public:
	int size;
	int* tItem;
	int rear, front;
	void CreateQueue(int _size);
	int is_Empty();
	int is_Full();
	void push(int item);
	int pop();
	int top();
	void Releasequeue() {
		free(tItem);
	}
};
int queue::top()
{
	if (is_Empty())
	{
		return -1;
	}
	return tItem[front + 1];
}
int queue::pop()
{
	if (is_Empty())
	{
		return -1;
	}
	return tItem[++front];
}
void queue::push(int item)
{
	if (is_Full())
	{
		return;
	}
	rear++;
	tItem[rear] = item;
}
void queue::CreateQueue(int _size)
{
	size = _size;
	tItem = (int*)malloc(sizeof(int) * size);
	rear = front = -1;
}
int queue::is_Empty()
{
	return (rear == front);
}
int queue::is_Full()
{
	return (rear == size - 1);
}

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
	queue q;
	int i,j;
	int count = 0;
	
	for (i = 0; i < progresses.size(); i++)
	{
		j = 0;
		while (true)
		{
			if (progresses[i] + speeds[i]*j >= 100)
			{
				q.push(j);
				break;
			}
			j++;
		}
	}
	if (!q.is_Empty()) {
		int max_day = q.pop(); // 첫 번째 작업의 완료일이 기준이 됩니다.
		int count = 1;         // 일단 첫 기능은 무조건 포함이니까 1부터 시작

		while (!q.is_Empty()) {
			int current_p = q.pop(); // 다음 기능을 하나 꺼냅니다.

			if (max_day >= current_p) {
				// 현재 기준일(max_day)보다 빨리 끝난다면? 같은 날 배포!
				count++;
			}
			else {
				// 기준일보다 늦게 끝난다면? 지금까지 쌓인 기능을 배포하고 새로 시작!
				answer.push_back(count);
				max_day = current_p; // 새로운 기준일 설정
				count = 1;           // 개수 초기화
			}
		}
		// [중요] 마지막에 남아있는 그룹을 배포 목록에 넣어줍니다.
		answer.push_back(count);
	}
	q.Releasequeue();
    return answer;
}