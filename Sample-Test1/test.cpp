#include "pch.h"
#include "../Project6/StringSimilar.cpp"

#include <string>
using namespace std;

TEST(SimilarTest, CheckLength) {
	StringSimilar ss;
	vector<string> strs = { "abc", "def" };

	EXPECT_EQ(60, ss.GetScoreWithLength(strs));  
}