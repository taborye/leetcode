#include "solution.h"

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}
vector<int> Solution::twoSum_v1(vector<int>& nums, int target) {
    
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> Solution::twoSum_v2(vector<int>& nums, int target) {
    unordered_map <int, int> temp = {};
    for (int i = 0; i < nums.size(); i++) {
        if (temp.find(nums[i]) != temp.end()) 
            return {temp[nums[i]],i};
        temp[target - nums[i]] = i;          
    }
    return {};
}

ListNode* Solution::addTwoNumbers_v1(ListNode* l1, ListNode* l2) {
    
    ListNode *list = NULL;
    int b = 0;
    while (!(l1 || l2)) {
        int a = 0;
        if (l1 && l2) {
            a = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1) {
            a = l1->val;
            l1 = l1->next;
        } else {
           a = l2->val; 
           l2 = l2->next;
        }

        if (a >= 10) {
            a = a % 10;
            b++;
        }
        ListNode *t = new ListNode(a+b);
        b = 0;

        ListNode *head = list;
        if (head == NULL) {
            list = t;
             t->next = NULL;
             continue;
        }
        while(head->next == NULL) {
            head = head->next;
        }
        head->next = t;
        t->next = NULL;
        
    }
    return list;
    
}


ListNode* Solution::addTwoNumbers_v2(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(0); ListNode *p = head;
    int carry = 0;
    while (l1 || l2 || carry) {
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        p->next = new ListNode(carry % 10);
        carry /= 10;
        p = p->next;
    }


    return head->next;
}


/*哈希表 和 滑动窗口*/
int Solution::lengthOfLongestSubstring(string s) {
    
    unordered_map <char ,int> window;
    int left = 0,right = 0,res = 0;
    char c = ' ',d = ' ';
    while (right < s.size()) {
         c = s[right];
         window[c]++;
         right;

        while (window[c] > 1) {
            d = s[left];
            window[d]--;
            left++;            

        }
        res = std::max(res,right - left);
    }
    return res;

}


double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? -1000000 : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? 1000000 : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? -1000000 : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? 1000000 : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            } else {
                return std::max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    throw std::invalid_argument("Input arrays are not sorted");
}

/*如果楼梯有3阶以上，那么我们可以用一个一维的动态规划表来记录每一阶楼梯的爬法。对于第i阶楼梯，我们可以从第i-1阶爬1阶上来，也可以从第i-2阶爬2阶上来，所以第i阶楼梯的爬法就是第i-1阶和第i-2阶的爬法之和*/
int Solution::climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    std::vector <int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

}

vector<vector<int>> Solution::generate(int numRows) {
    std::vector <std::vector <int>> res (numRows);

    for (int i = 0; i < numRows; i++) {
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }
    return res;
}

vector<int> Solution::getRow_v1(int rowIndex) {
    std::vector <std::vector <int>> res (rowIndex+1);

    for (int i = 0; i <= rowIndex; i++) {
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }
    return res[rowIndex];

}
vector<int> Solution::getRow_v2(int rowIndex) {
    std::vector <int> res (rowIndex+1,1);

    for (int i = i; i < rowIndex; ++i) {
        for (int j = i; j > 0; --j) {
            res[j] = res[j] + res[j-1];
        }

    }
    return res;

}

int Solution::maxProfit (vector <int>& prices) {
    
    if (prices.empty()) {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i< prices.size(); ++i) {
        minPrice = std::min(minPrice,prices[i]);
        maxProfit = std::max(maxProfit,prices[i] - minPrice);
    }
    return maxProfit;
}

vector <int> Solution::countBits(int n) {
    std::vector <int> ans(n + 1);
    for (int i = 1; i<= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;

}
bool Solution::isSubsequence_v1(string s,string t) {
    std::unordered_map <char,bool> dp(s.size());
    for (int i = 0; i < s.size(); i++) {    
        dp[s[i]] = false;
        printf("%c\n",s[i]);
    }

    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        printf("%c = %c\n",s[j],t[i]);
        if (s[j] == t[i]) {
            dp[s[j]] = true;
            printf("%c = %d\n",s[j],true);
            j++;
        }
        if (j == s.size()) {
            break;
        }
    }
    for (auto it = dp.begin(); it != dp.end(); it++) {
        if (it->second == false) {
            return false;
        }
    }
    return true;

}
bool Solution::isSubsequence_v2(string s,string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            ++i;
        }
        ++j;
    }
    return i == s.size();

}

int Solution::fib(int n) {
    
    vector <int> res(n+1);
    for (int i = 0; i <= n; i++) {
        if (i == 0) res[i] = 0;
        else if (i == 1) res[i] = 1;
        else {
            res[i] = res[i-1] + res[i - 2];
            
        }
        printf("res[%d] = %d\n",i,res[i]);
    }
    return res[n];

}

int Solution::minCostClimbingStairs(vector<int> & cost) {
    int n = cost.size();

    std::vector <int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i <= cost.size(); i ++) {
        dp[i] = std::min(dp[i-1],dp[i - 2]) + (i == n ? 0 : cost[i]);

    }
    return dp[n];

}

bool Solution::divisorGame(int n) {
    std::vector <bool> dp(n + 1, false);

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0 && !dp[i - j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
int Solution::tribonacci(int n) {
    
    std::vector <int> dp(n + 1);
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

int Solution::maxRepeating(string sequence, string word) {
    int count = 0;
    std::string temp = word;
    while (sequence.find(temp) != std::string::npos) {
        count++;
        temp += word;
    }
    return count;


}
std::vector <string> Solution::getLongestSubsequence(vector<string>& words, vector<int>& groups) {

    std::vector <std::string> result;
    if (words.empty() || groups.empty()) {
        return result;
    }
    result.push_back(words[0]);
    for (int i = 1; i < groups.size(); i++) {
        if (groups[i] != groups[i - 1]) {
            result.push_back(words[i]);
        }

    }
    return result;
}

int Solution::removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[count++] = nums[i];
        }
    }
    return count;
}
int Solution::removeElement(vector<int> &nums, int val) {
    if (nums.empty()) {
        return 0;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
}


