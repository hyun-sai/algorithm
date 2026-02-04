#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    vector <int> clothes_kind;
    sort(clothes.begin(), clothes.end(), [](const auto& a, const  auto& b) {return a[1] < b[1]; });
    string s = "";
    for (int i = 0; i < clothes.size(); i++)
    {

        if (clothes_kind.empty() || (clothes[i][1] != s))
        {
            clothes_kind.push_back(1);
        }
        else
        {
            clothes_kind.back()++;
        }
        s = clothes[i][1];
    }
    for (int i = 0; i < clothes_kind.size(); i++)
    {

        cout << clothes_kind[i];
    }
    return answer;
}