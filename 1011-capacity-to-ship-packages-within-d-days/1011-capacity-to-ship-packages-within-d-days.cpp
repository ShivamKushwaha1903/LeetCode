class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {

            int mid = left + (right - left) / 2;

            int need = 1;
            int load = 0;

            for (int w : weights) {

                if (load + w > mid) {
                    need++;
                    load = 0;
                }

                load += w;
            }

            if (need <= days)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};