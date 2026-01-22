#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    int n = id_list.size();
    vector<int> answer(n, 0);
    // n개의 행을 만들고, 각 행을 다시 n개의 0으로 채워진 열로 초기화합니다. 초기화가 개 중요하네 제발 이거 주의하고 공부해줘
    vector<vector<int>> game(n, vector<int>(n, 0));
    
    for (string name : report)
    {
        stringstream ss(name);
        string a, b;
        int index_a;
        int index_b;
        ss >> a >> b;
        for (int i = 0; i < id_list.size(); i++)
        {
            if (id_list[i] == a)
            {
                index_a = i;
            }
        }
        for (int i = 0; i < id_list.size(); i++)
        {
            if (id_list[i] == b)
            {
                index_b = i;
            }
        }
        game[index_a][index_b] = 1;
    }
    for (int i = 0; i < id_list.size(); i++)
    {
        for(int j=0;j< id_list.size(); j++)
            if (game[i][j] == 1)
            {
                int sum = 0;
                for (int k = 0; k < id_list.size(); k++)
                {
                    sum += game[k][j];
                }
                if (sum >= k)
                {
                    answer[i]++;
                }
            }
    }
    for (int i = 0; i < id_list.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return answer;
}
