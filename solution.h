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
    //���κͶ��ֲ���
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);//4

    //���һ��ģ��ö�̬�滮��������
    //std::string longestPalindrome(std::string s);//5


    //��¥��
    int climbStairs(int n);//70

    //�������(��̬�滮)
    vector<vector<int>> generate(int numRows);  //118


    //�������2(��̬�滮)
    vector<int> getRow_v1(int rowIndex); //119
    vector<int> getRow_v2(int rowIndex); //119

    int maxProfit(vector <int>& price);//121


    /*����������ʹ�ö�̬�滮��˼������������ǿ��Է���һ�����ɣ����������е������� x��x �Ķ������� 1 �ĸ������� (x/2) �Ķ������� 1 �ĸ��� + x mod 2��*/
    vector <int> countBits(int n);//338

    bool isSubsequence_v1(string s, string t);//392 ����©������s������ͬ�ĳ�Աʱ��ʧЧ
    bool isSubsequence_v2(string s, string t);//392

    int fib(int n);//509 쳲�������

    int minCostClimbingStairs(vector<int>& cost);//746:��С������¥��

    bool divisorGame(int n);//1025 ��������

    int tribonacci(int n);//1137://��N��̩��������

    int maxRepeating(string sequence, string word);//1668:����ظ��Ӵ� ���������;��̬�滮�����ʺϡ�

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups);//2900:����ڲ����������1

    int removeDuplicates(vector<int>& nums);//26:ɾ�����������е��ظ���

    int removeElement(vector<int> &nums, int val);//27:�Ƴ�Ԫ��

    int numWays(int n, vector<vector<int>>& relation, int k);

};


