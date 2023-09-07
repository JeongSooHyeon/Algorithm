#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    // Binary search approach
    int n = nums.size();
    vector<int> ans;

    // Initialize the answer vector with the
    // first element of nums
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
            // ������ ���Һ��� ũ�� ���� ���,
            // ans ���Ϳ��� �ֱ� ���Һ��� ũ�ų� ���� ���� ���� ��Ҹ� ã�� ����

            // �ֱ� ���ں��� ���� ���� ù��° ���
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
           
            // ������ ���ĵ� ���� �����ϸ� ��� ������Ʈ
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

// Driver program to test above function
int main()
{
    vector<int> nums = { 10, 22, 9, 33, 21, 50, 41, 60 };
    // Function call
    printf("Length of LIS is %d\n", lengthOfLIS(nums));
    return 0;
}