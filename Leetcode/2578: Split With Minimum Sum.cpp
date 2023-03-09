class Solution {
public:
    int splitNum(int num) {
        priority_queue<int> nums;
        while (num > 0) {
            nums.push(num%10);
            num /= 10;
        }
        int a = 0, b = 0, count = 1;
        while (!nums.empty()) {
            a += nums.top() * count;
            nums.pop();
            if (!nums.empty()) {
                b += nums.top() * count;
                nums.pop();
            }
            count *= 10;
        }

        return a + b;
    }
};
