#include <vector>
#include <string>
using namespace std;

class StringSimilar
{
public:
	StringSimilar()
	{
		for (int& i : checkAlphabet) i = 0;
	}

	int GetScoreWithAlphabet(const vector<string>& strs)
	{
		int SameCnt = 0;
		int TotalCnt = 0;

		TotalCnt += GetTotalCnt(strs[0]);
		SameCnt += GetSameCnt(strs[1]);
		TotalCnt += GetTotalCnt(strs[1]);

		if (SameCnt == TotalCnt)
		{
			return MAX_MATCHING_SCORE;
		}
		if (SameCnt == 0)
		{
			return MIN_MATCHING_SCORE;
		}
		return SameCnt * 40 / TotalCnt;
	}

private:
	int GetTotalCnt(string str)
	{
		int TotalCnt = 0;
		for (char ch : str)
		{
			if(checkAlphabet[ch - 'A'] == 0)
			{
				checkAlphabet[ch - 'A'] = 1;
				TotalCnt++;
			}			
		}

		return TotalCnt;
	}

	int GetSameCnt(string str)
	{
		int SameCnt = 0;
		for (char ch : str)
		{
			if (checkAlphabet[ch - 'A'] == 1)
			{
				SameCnt++;
				checkAlphabet[ch - 'A']++;
			}
		}
		return SameCnt;
	}	
	
	const int MAX_MATCHING_SCORE = 40;
	const int MIN_MATCHING_SCORE = 0;
	int checkAlphabet[26];
};
