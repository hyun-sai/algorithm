#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
class Stack
{
public: // 외부에서 접근 가능하도록 설정
	int size;
	char * tItem;
	int TOP;
	void CreateStack(int _size);
	int is_Empty();
	int is_FUll();
	void push(int item);
	int pop();
	int top();
	void ReleaseStack() {
		free(tItem);
	}
};
int Stack::top()
{
	if (is_Empty())
	{
		return -1;
	}
	return tItem[TOP - 1];
}
int Stack::pop()
{
	if (is_Empty())
	{
		return -1;
	}
	TOP--;
	return tItem[TOP];
}
void Stack::push(int item)
{
	if (is_FUll())
	{
		return;
	}
	tItem[TOP] = item;
	TOP++;
}
int Stack::is_FUll()
{
	return (TOP == size);
}
int Stack::is_Empty()
{
	return (TOP == 0);
}

void Stack::CreateStack(int _size)
{
	size = _size;
	tItem = (char*)malloc(sizeof(char) * size);
	TOP = 0;
}
bool solution(string s) {
	int size = s.size();
	Stack mystack;
	mystack.CreateStack(size); // 스택 생성

	for (int i = 0; i < size; i++) {
		if (s[i] == '(') {
			// 1. 열린 괄호면 스택에 쌓는다.
			mystack.push('(');
		}
		else {
			// 2. 닫힌 괄호면 스택에서 하나를 뺀다.
			if (mystack.pop() == -1) {
				// 3. 뺄 게 없다면? 이미 짝이 깨진 것 (예: ")")
				mystack.ReleaseStack();
				return false;
			}
		}
	}

	// 4. 루프가 다 끝났을 때 스택이 비어있어야 진짜 성공 (예: "(()" 방지)
	bool answer = mystack.is_Empty();

	mystack.ReleaseStack(); // 메모리 해제
	return answer;
}
