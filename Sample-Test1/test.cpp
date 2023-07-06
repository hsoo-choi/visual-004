#include "pch.h"
#include "../Project6/StringSimilar.cpp"

#include <string>
using namespace std;

class SimilarFixture : public testing::Test
{
public:
	StringSimilar ss;

	void assertIllegalArgument(vector<string> strs)
	{
		try
		{
			ss.GetScoreWithLength(strs);
			FAIL();
		}
		catch (exception e)
		{
		}
	}
};

TEST_F(SimilarFixture, ThrowExceptionWhenInvalidCase) {
	vector<string> strs = { "aaa", "bbb", "ccc" };
	assertIllegalArgument(strs);
}

TEST_F(SimilarFixture, CheckScoreForSameLength) {	
	vector<string> strs = { "abc", "def" };

	EXPECT_EQ(60, ss.GetScoreWithLength(strs));  
}

TEST_F(SimilarFixture, CheckScoreForDoubleLength) {
	vector<string> strs = { "a", "bb" };

	EXPECT_EQ(0, ss.GetScoreWithLength(strs));
}

TEST_F(SimilarFixture, CheckScoreForDiffrentLength1) {
	vector<string> strs = { "aaabb", "baa" };

	EXPECT_EQ(20, ss.GetScoreWithLength(strs));
}

TEST_F(SimilarFixture, CheckScoreForDiffrentLength2) {
	vector<string> strs = { "aa", "aae" };

	EXPECT_EQ(30, ss.GetScoreWithLength(strs));
}