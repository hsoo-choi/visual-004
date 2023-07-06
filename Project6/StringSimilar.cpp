#include <vector>
#include <xstring>

#include <string>
using namespace std;

class StringSimilar
{
public:
	int GetScoreWithLength(const vector<string>& strs)
	{
		int score = -1;
		size_t longLength, shortLength;
		string str1 = strs[0];
		string str2 = strs[1];

		if (str1.length() >= str2.length())
		{
			longLength = str1.length();
			shortLength = str2.length();
		}
		else
		{
			longLength = str2.length();
			shortLength = str1.length();
		}
		
		if (str1.length() == str2.length())
		{
			score = 60;
		}
		else if(longLength >= shortLength * 2)
		{
			score = 0;
		}

		return score;
	}
};
