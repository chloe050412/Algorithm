#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answercount = 0;
	bool isAnswer = true;
	string test = "";

	for (auto& skill_tree : skill_trees)
	{
		// 스킬트리에 존재하는 스킬만 찾아서 넣기 
		for (int i = 0; i < skill_tree.size(); ++i)
		{
			if (skill.find(skill_tree[i]) != string::npos)
			{
				test.push_back(skill_tree[i]);
			}
		}

		for (int i = 0; i < test.size(); ++i)
		{
			if (skill[i] != test[i])
			{
				isAnswer = false;
				break;
			}
		}

		if (isAnswer)
		{
			++answercount;
		}

		isAnswer = true;
		test.clear();
	}

	return answercount;
}