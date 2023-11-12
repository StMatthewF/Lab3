#include "pch.h"
#include "../Lab3/Sorts.cpp"
#include <vector>
#include <string>
using namespace std;

TEST(QuickSortTest, EmptyArray) {
	vector<int> data = {};
	vector<int> expected = {};
	QuickSort(data.data(), data.data() + data.size(), [](const int& a, const int& b) { return a < b; });
	ASSERT_EQ(data, expected);
}

TEST(QuickSortTest, OneElementArray) {
	vector<int> data = { 1 };
	vector<int> expected = { 1 };
	QuickSort(data.data(), data.data() + data.size(), [](const int& a, const int& b) { return a < b; });
	ASSERT_EQ(data, expected);
}

TEST(QuickSortTest, SameElementsArray) {
	vector<int> data = { 2, 2, 2, 2, 2 };
	vector<int> expected = { 2, 2, 2, 2, 2 };
	QuickSort(data.data(), data.data() + data.size(), [](const int& a, const int& b) { return a < b; });
	ASSERT_EQ(data, expected);
}

TEST(QuickSortTest, NaturalElementsArray) {
	vector<int> data = { 3, 2, 12, 5, 1 };
	vector<int> expected = { 1, 2, 3, 5, 12 };
	QuickSort(data.data(), data.data() + data.size(), [](const int& a, const int& b) { return a < b; });
	ASSERT_EQ(data, expected);
}

TEST(QuickSortTest, MixedValuesArray) {
	vector<int> data = { 5, -2, 8, -10, 4 };
	vector<int> expected = { -10, -2, 4, 5, 8 };
	QuickSort(data.data(), data.data() + data.size(), [](const int& a, const int& b) { return a < b; });
	ASSERT_EQ(data, expected);
}

TEST(QuickSortTest, ReverseOrderIntegersArray) {
	vector<int> data = { 5, 2, 8, 1, 4 };
	vector<int> expected = { 8, 5, 4, 2, 1 };
	QuickSort(data.data(), data.data() + data.size(), [](const int& a, const int& b) { return a > b; });
	ASSERT_EQ(data, expected);
}

TEST(QuickSortTest, SortStringByBibliographicOrder) {
	vector<string> data = { "chack", "eva", "baby", "doom", "aaa" };
	vector<string> expected = { "aaa", "baby", "chack", "doom", "eva" };
	QuickSort(data.data(), data.data() + data.size(), [](const string& a, const string& b) { return a < b; });
	ASSERT_EQ(data, expected);
}

TEST(QuickSortTest, SortStringsByLength) {
	vector<string> data = { "chack", "eva", "ba", "d", "aaaa" };
	vector<string> expected = { "d", "ba", "eva", "aaaa", "chack" };
	QuickSort(data.data(), data.data() + data.size(), [](const string& a, const string& b) { return a.size() < b.size(); });
	ASSERT_EQ(data, expected);
}