#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    std::sort(citations.begin(), citations.end());

    for (int i = 0; i < citations.size(); ++i)
    {
        if (citations[i] <= citations.size() - i)
            answer = i;
    }

    return answer;
}