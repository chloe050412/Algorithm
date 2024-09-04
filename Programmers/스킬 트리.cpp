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
		// ��ųƮ���� �����ϴ� ��ų�� ã�Ƽ� �ֱ� 
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