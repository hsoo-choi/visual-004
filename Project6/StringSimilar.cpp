#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

class StringSimilar
{
public:
	int GetScoreWithLength(const vector<string>& strs)
	{
		assertIllegalArgument(strs);		

		return getScore(strs[0], strs[1]);
	}

	void assertIllegalArgument(const vector<string>& strs)
	{
		if(strs.size() > 2)
		{
			throw invalid_argument("Must be two strings");
		}
	}

private:
	size_t getLongLength(string str1, string str2)
	{
		if (str1.length() >= str2.length())
		{
			return str1.length();
		}
		return str2.length();
	}

	size_t getShortLength(string str1, string str2)
	{
		if (str1.length() >= str2.length())
		{
			return str2.length();
		}
		return str1.length();
	}

	int getPartialLengthPonint(size_t longLength, size_t shortLength)
	{
		size_t gap = longLength - shortLength;
		return (int)((1 - ((double)gap / shortLength)) * 60);
	}

	int getScore(string str1, string str2)
	{
		size_t longLength = getLongLength(str1, str2);
		size_t shortLength = getShortLength(str1, str2);

		if (longLength == shortLength)
		{
			return MAX_LENGTH_SCORE;
		}

		if(longLength > shortLength * 2)
		{
			return MIX_LENGTH_SCORE;
		}

		return getPartialLengthPonint(longLength, shortLength);
	}

	const int MAX_LENGTH_SCORE = 60;
	const int MIX_LENGTH_SCORE = 0;
};
