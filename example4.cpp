#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller values from the back of deque
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current index to deque
            dq.push_back(i);

            // Add the max of the current window to result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

// Sample main() function to test
int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> output = sol.maxSlidingWindow(nums, k);

    cout << "Max in each window of size " << k << ":\n";
    for (int num : output) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
