//공간 할당을 신경써줘야하는 문제

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    vector <int> number; //바뀐 진수의 각 자리가 반대로 들어간 벡터 
    vector <int> number2; //소수를 판독할 숫자가 들어갈 자리
    //진수 바꾸기
    while (true)
    {
        if (n < k)
        {
            number.push_back(n);
            break;
        }
        number.push_back(n % k);
        n /= k;
        
    }
    //숫자넣기
    int sum = 0;
    for (int i = number.size() - 1; i >= 0; i--)
    {
        if (number[i] == 0&&(i!=number.size()-1))
        {
            number2.push_back(sum);
            sum = 0;
            continue;
        }
        if (i == 0 && number[i] != 0)
        {
            sum *= 10;
            sum += number[i];
            number2.push_back(sum);
            break;
        }
        sum *= 10;
        sum += number[i];
    }
    //숫자가 맞는지 확인하기
    for (int number : number2)
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
int main(void)
{
    int n =  110011;
    int k = 10;
    int a = 0;
    a=solution(n, k);
    cout << a;
}