#include "pch.h"
#include "../Project6/StringSimilar.cpp"

#include <string>
using namespace std;

TEST(SimilarTest, CheckScoreForSameLength) {
	StringSimilar ss;
	vector<string> strs = { "abc", "def" };

	EXPECT_EQ(60, ss.GetScoreWithLength(strs));  
}

TEST(SimilarTest, CheckScoreForDoubleLength) {
	StringSimilar ss;
	vector<string> strs = { "a", "bb" };

	EXPECT_EQ(0, ss.GetScoreWithLength(strs));
}

TEST(SimilarTest, CheckScoreForDiffrentLength) {
	StringSimilar ss;
	vector<string> strs = { "aaabb", "baa" };

	EXPECT_EQ(0, ss.GetScoreWithLength(strs));
}