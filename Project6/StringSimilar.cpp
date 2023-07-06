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
	int getScore(string str1, string str2)
	{
		size_t longLength;
		size_t shortLength;

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
			return 60;
		}
		else if(longLength > shortLength * 2)
		{
			return 0;
		}
		else
		{
			size_t gap = longLength - shortLength;
			return (int)((1 - ((double)gap / shortLength)) * 60);
		}		
	}	
};
