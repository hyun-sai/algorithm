#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    // step1 2차원 배열 초기화 하기
    const int width = w;
    const int length = ceil(double(n) / w);
    vector < vector<int>> boxes(length, vector<int>(width, 0));
    // step2 2차원 배열에 상자 집어넣기
    int do_switch = 1;
    int row = 0;
    int col = 0;
    int oddoreven=1;
    int i = 1;
    while (i <= n)
    {
        if (do_switch > width)
        {
            row++;
            col = 0;
            do_switch = 1;
            oddoreven *= -1;
        }
        if (oddoreven == 1)
        {
            boxes[row][col] = i;
            col++;
        }
        if (oddoreven == -1)
        {
            boxes[row][width-col-1] = i;
            col++;
        }
        do_switch++;
        i++;
    }
    //step3 위치 찾기
    vector <int> location;
    for (int i=0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (num == boxes[i][j])
            {
                location.push_back(i);
                location.push_back(j);
                goto step4;
            }
        }
    }

    step4:
    //step4; 상자 계산하기
    int answer = 0;
    if (boxes[length-1][location[1]]==0)
    {
        answer = length - location[0] - 1;
    }
    else
    {
        answer = length - location[0];
    }
    cout << answer;
    return answer;
}
int main(void)
{
    int a;
    a = solution(13, 3, 6);
}