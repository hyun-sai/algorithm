#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct genre_play {
    string genre;
    int genre_play;
};
struct box {
    string genre;
    int genre_play;
    int song_play;
    int uni_num;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //step1 어떤 장르가 얼마나 노래가 많이 재생됐는지 계산
    vector<genre_play> genre_plays;
    //sort된 genres랑 sort되지 않은 genres 두개가 필요했음
    vector<string> genres2;
    for (int i = 0; i < genres.size(); i++)
    {
        genres2.push_back(genres[i]);
    }

    sort(genres2.begin(), genres2.end());
    for (int i = 0; i < genres.size(); i++)
    {
        if (genre_plays.empty() || genre_plays.back().genre != genres2[i])
        {
            genre_plays.push_back({ genres2[i],0 });
        }
    }

    for (int i = 0; i < genres.size(); i++)
    {
        for (int j = 0; j < genre_plays.size(); j++)
            if (genres[i] == genre_plays[j].genre)
            {
                genre_plays[j].genre_play += plays[i];
                break;
            }
    }
    //step2 비교에 필요한 정보를 구조체로 합치기
    //data는 이름으로 사용 불가
    vector <box> boxes;
    for (int i = 0; i < genres.size(); i++)
    {
        for (int j = 0; j < genre_plays.size(); j++)
            if (genres[i] == genre_plays[j].genre)
            {
                boxes.push_back({ genres[i],genre_plays[j].genre_play,plays[i],i });
                break;
            }
    }
    //step3 sort하기
    sort(boxes.begin(), boxes.end(), [](const auto& a, const auto& b)
        {
            if (a.genre_play == b.genre_play)
            {
                if (a.song_play == b.song_play)
                {
                    return a.uni_num < b.uni_num;
                }
                return a.song_play > b.song_play;
            }
            return a.genre_play > b.genre_play;
        }
    );

    int count = 0;
    string s = "";
    for (int i = 0; i < genres.size(); i++)
    {
        if (s != boxes[i].genre)
        {
            count = 0;
        }
        count++;
        if (count > 2)
        {
            continue;
        }
        answer.push_back(boxes[i].uni_num);
        s = boxes[i].genre;
    }
    return answer;
}