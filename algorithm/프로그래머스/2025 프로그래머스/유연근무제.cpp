#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    

    //step1) startday가 x일때 늦어도 되는 인덱스 a,b 구하기
    int sat_idx = 0;
    int sun_idx = 0;
    sat_idx = 6 - startday;
    sun_idx = sat_idx + 1;
    if (startday == 7)
    {
        sat_idx = 0;
        sun_idx = 6;
    }
    //step2) timelogs크기의 1으로 찬 2차원 배열만들기
    int length = timelogs.size();
    int width = timelogs[0].size();
    vector <vector <int>> table(length, vector<int>(width, 1));
    
    //step3) scehdules 10분 늦추기
    for (int i = 0; i < length; i++)
    {
        schedules[i] += 10;
        if (schedules[i] % 100 > 59)
        {
            schedules[i] += 100;
            schedules[i] -= 60;
        }
        
    }

    //step4)비교해서 지각했으면 0으로 바꾸기
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (schedules[i] < timelogs[i][j])
            {
                table[i][j] = 0;
            }

        }

    }
    for (int i = 0; i < length; i++)

    {
        table[i][sat_idx] = 1;
        table[i][sun_idx] = 1;
    }
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (table[i][j] == 0)
            {
                count++;
                break;
            }
        }
    }
    answer = length - count;
    cout << answer;
    return answer;
}
int main(void)
{
    vector<int> schedules = { 730, 855, 700, 720 };
    vector<vector<int>> timelogs = { {710, 700, 650, 735, 700, 931, 912},{908, 901, 805, 815, 800, 831, 835},{705, 701, 702, 705, 710, 710, 711},{707, 731, 859, 913, 934, 931, 905} };
    int startday=7;
    int answer;
    answer = solution(schedules, timelogs, startday);
}