#include "pch.h"
#include "../Project6/StringSimilar.cpp"

#include <string>
using namespace std;

class SimilarFixture : public testing::Test
{
public:
	StringSimilar ss;	
};

TEST_F(SimilarFixture, AllMatchingScore) {
	vector<string> strs = { "ASD", "DSA" };

	EXPECT_EQ(40, ss.GetScoreWithAlphabet(strs));
}

TEST_F(SimilarFixture, AllMatchingScore2) {
	vector<string> strs = { "AAABB", "BBA" };

	EXPECT_EQ(40, ss.GetScoreWithAlphabet(strs));
}

TEST_F(SimilarFixture, NoMatchingScore) {
	vector<string> strs = { "A", "BB" };

	EXPECT_EQ(0, ss.GetScoreWithAlphabet(strs));
}

TEST_F(SimilarFixture, PartialMatchingScore) {
	vector<string> strs = { "AA", "AAE" };

	EXPECT_EQ(20, ss.GetScoreWithAlphabet(strs));
}