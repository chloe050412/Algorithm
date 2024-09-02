#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int CalculateRecordTime(string enter, string exit)
{
	int time1 = stoi(enter.substr(0, 2)) * 60 + stoi(enter.substr(3, 2));
	int time2 = stoi(exit.substr(0, 2)) * 60 + stoi(exit.substr(3, 2));


	return time2 - time1;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
	vector<int> answer;

	map<int, int> resultfee;
	map<string, string> enterRecord;
	string time, number, inout;

	for (auto record : records)
	{
		stringstream divide(record);
		divide >> time >> number >> inout;

		if (inout == "IN")
		{
			enterRecord[number] = time;
		}
		else
		{
			int recordTime = CalculateRecordTime(enterRecord[number], time);
			enterRecord.erase(number);

			if (resultfee.find(stoi(number)) != resultfee.end())
			{
				resultfee[stoi(number)] += recordTime;
			}
			else
			{
				resultfee[stoi(number)] = recordTime;
			}
		}
	}

	// 23:59에 나간 것으로 처리해야 하는 차량 처리
	for (auto record : enterRecord)
	{
		int recordTime = CalculateRecordTime(record.second, "23:59");
		int carNumber = stoi(record.first);
		if (resultfee.find(carNumber) != resultfee.end())
		{
			resultfee[carNumber] += recordTime;
		}
		else
		{
			resultfee[carNumber] = recordTime;
		}
	}

	for (auto result : resultfee) {
		int totalFee = 0;
		if (result.second > fees[0]) 
		{
			totalFee = fees[1] + ((result.second - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
		}
		else 
		{
			totalFee = fees[1];
		}
		answer.push_back(totalFee);
	}

	return answer;
}

int main()
{

	return 0;
}