#include <vector>
#include <xstring>

#include <string>
using namespace std;

class StringSimilar
{
public:
	int GetScoreWithLength(const vector<string>& strs)
	{
		string str1 = strs[0];
		string str2 = strs[1];

		if (str1.length() == str2.length()) return 60;

		return 0;
	}
};
