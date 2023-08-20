/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
    vector<int> unique;
    unordered_map<int, int> count_map;

    int partition(int left, int right, int pivot) {
        int pivot_freq = count_map[unique[pivot]];

        // move pivot to the end
        swap(unique[pivot], unique[right]);

        int index = left;
        for (int i = left; i <= right; ++i) {
            // swap front if ele freq is less than pivot freq
            if (count_map[unique[i]] < pivot_freq) {
                swap(unique[i], unique[index]);
                index++;
            }
        }
        swap(unique[index], unique[right]);

        return index;
    }

    void quick_select(int left, int right, int k_smallest) {
        if (left == right) {
            return;
        }

        int pivot = left + rand() % (right - left + 1);

        pivot = partition(left, right, pivot);

        if (pivot == k_smallest) {
            return;
        } else if (pivot < k_smallest) {
            // k_smalleset on the right
            quick_select(pivot + 1, right, k_smallest);
        } else { // pivot > k_smalleset
            // k_smalleset on the left
            quick_select(left, pivot - 1, k_smallest);
        }
    }

  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        for (int num : nums) {
            count_map[num]++;
        }

        for (auto &p : count_map) {
            unique.push_back(p.first);
        }
        int n = unique.size();

        // quick selct first n-k elemetns to be the n-k least freqeuent elements
        quick_select(0, n - 1, n - k);

        vector<int> res(k);
        copy(unique.begin() + n - k, unique.end(), res.begin());

        return res;
    }
};
// @lc code=end
