#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i].size() <= phone_book[i + 1].size())
        {
            int count = 0;
            for (int j = 0; j < phone_book[i].size(); j++)
            {

                if (phone_book[i][j] == phone_book[i + 1][j])
                {
                    count++;
                }
                if (count == phone_book[i].size())
                {
                    answer = false;
                    break;
                }

            }
        }
    }

    return answer;
}