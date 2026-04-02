class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            while (!maxDeque.empty() && nums[right] > maxDeque.back())
                maxDeque.pop_back();
            maxDeque.push_back(nums[right]);

            while (!minDeque.empty() && nums[right] < minDeque.back())
                minDeque.pop_back();
            minDeque.push_back(nums[right]);

            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[left] == maxDeque.front())
                    maxDeque.pop_front();
                if (nums[left] == minDeque.front())
                    minDeque.pop_front();
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
