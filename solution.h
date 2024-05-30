#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL) {};
};
class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();

    vector<int> twoSum_v1(vector<int>& nums, int target);// 1
    vector<int> twoSum_v2(vector<int>& nums, int target);// 1

    ListNode* addTwoNumbers_v1(ListNode* l1, ListNode* l2);//2
    ListNode* addTwoNumbers_v2(ListNode* l1, ListNode* l2);//2

    int lengthOfLongestSubstring(string s);//3
    //分治和二分查找
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);//4

    //查找回文，用动态规划来解问题
    //std::string longestPalindrome(std::string s);//5


    //爬楼梯
    int climbStairs(int n);//70

    //杨辉三角(动态规划)
    vector<vector<int>> generate(int numRows);  //118


    //杨辉三角2(动态规划)
    vector<int> getRow_v1(int rowIndex); //119
    vector<int> getRow_v2(int rowIndex); //119

    int maxProfit(vector <int>& price);//121


    /*这个问题可以使用动态规划的思想来解决。我们可以发现一个规律，即对于所有的正整数 x，x 的二进制中 1 的个数等于 (x/2) 的二进制中 1 的个数 + x mod 2。*/
    vector <int> countBits(int n);//338

    bool isSubsequence_v1(string s, string t);//392 存在漏洞；当s存在相同的成员时会失效
    bool isSubsequence_v2(string s, string t);//392

    int fib(int n);//509 斐波那契数

    int minCostClimbingStairs(vector<int>& cost);//746:最小代价爬楼梯

    bool divisorGame(int n);//1025 除数博弈

    int tribonacci(int n);//1137://第N个泰波那契数

    int maxRepeating(string sequence, string word);//1668:最大重复子串 暴力解决法;动态规划并不适合。

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups);//2900:最长相邻不相等子序列1

    int removeDuplicates(vector<int>& nums);//26:删除有序数组中的重复项

    int removeElement(vector<int> &nums, int val);//27:移除元素

    int numWays(int n, vector<vector<int>>& relation, int k);

};


