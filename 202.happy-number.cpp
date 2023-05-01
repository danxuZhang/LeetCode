/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
private:
    int next_number(int n) {
        int new_number = 0;
        while(n!=0){
            int num = n % 10;
            new_number += num * num;
            n = n / 10;
        }
        return new_number;
    }

public:
    bool isHappy(int n) {    
        if (n == 1) 
            return true;
        
        int slow_pointer = n;
        int fast_pointer = next_number(n);
        
        while (fast_pointer != 1 && slow_pointer != fast_pointer) {
            slow_pointer = next_number(slow_pointer);
            fast_pointer = next_number(next_number(fast_pointer));
        }

        return fast_pointer == 1;
    }
};
// @lc code=end

