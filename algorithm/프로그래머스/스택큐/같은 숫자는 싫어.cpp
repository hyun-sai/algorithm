#include <stdio.h>
#include <cstdlib>
class Stack
{
public: // 외부에서 접근 가능하도록 설정
	int size;
	int* tItem;
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
	tItem = (int*)malloc(sizeof(int) * size);
	TOP = 0;
}
 
int * solution(int arr[])
{
	int i;
	Stack mystack;
	int size = sizeof(arr) / sizeof(arr[0]);
	mystack.CreateStack(size);
	for (i = 0; i < size; i++)
	{
		if (mystack.is_Empty() || mystack.top() != arr[i])
		{
			mystack.push(arr[i]);
		}
	}
	int arr[1000000];
	for (i = 0; i < mystack.TOP; i++)
	{
		arr[i]=mystack.tItem[i];
	}
	mystack.ReleaseStack();
	return arr;
}
