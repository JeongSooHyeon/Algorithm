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
            // 마지막 원소보다 크지 않을 경우,
            // ans 백터에서 최근 원소보다 크거나 같은 가장 작은 요소를 찾을 거임

            // 최근 숫자보다 작지 않은 첫번째 요소
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
           
            // 백터의 정렬된 순서 유지하며 요소 업데이트
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