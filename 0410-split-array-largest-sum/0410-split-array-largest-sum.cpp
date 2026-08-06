class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);

        while (left < right) {

            int mid = left + (right - left) / 2;

            int count = 1;
            long long sum = 0;

            for (int num : nums) {

                if (sum + num > mid) {
                    count++;
                    sum = 0;
                }

                sum += num;
            }

            if (count <= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};