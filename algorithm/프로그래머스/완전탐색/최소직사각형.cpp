#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int i;
    int temp = 0;
    int name_paper_count = sizes.size();
	printf("%d\n", name_paper_count);
    //가로와 세로중 더 긴 것을 앞으로 뺀다
    int name_width_max = 0;
    int name_length_max = 0;
    for (i = 0; i < name_paper_count; i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
            //가로가 더 긴 상태로 바꾸고 가로,세로 각각 max에 집어넣어준다.
            if (name_width_max < sizes[i][0])
            {
                name_width_max = sizes[i][0];
            }
            if (name_length_max < sizes[i][1])
            {
                name_length_max = sizes[i][1];
            }

        }

    }
    answer = name_width_max * name_length_max;

    return answer;
}
