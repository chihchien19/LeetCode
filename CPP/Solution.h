#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	vector<int> twoSum(vector<int>&, int);
	ListNode* addTwoNumbers(ListNode*, ListNode*);
	int lengthOfLongestSubstring(string);
	string multiply(string ,string);
	vector<vector<int>> permute(vector<int>&);
	vector<vector<int>> permuteUnique(vector<int>&);
	int maxSubArray(vector<int>&);
	void rotate(vector<vector<int>>&);
	vector<vector<string>> groupAnagrams(vector<string>&);
	double myPow(double,int);
	vector<int> spiralOrder(vector<vector<int>>&);
	bool canJump(vector<int>&);
	vector<vector<int>> generateMatrix(int);
	string getPermutation(int,int);


private:
	void assign(vector<vector<int>>&, vector<int>, vector<int>,bool);
	void readEdge(vector<vector<int>>&, vector<int>&);
	void rotateMatrix(vector<vector<int>>&,bool);


};

#endif 