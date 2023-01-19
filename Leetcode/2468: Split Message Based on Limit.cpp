/*
My idea was to essentially split the problem into multiple sections:
  - Figure out the amount of characters that could be in the single digit section of the message parts (aka limit)
  - Figure out the total amount of parts based off of the limit found in the previous section (aka total)
  
Once both limit and total were calculated, I could then construct the parts that I could add into vector<string> res.
I found that the only issue with my solution was the first section, as I was not always calculating limit correctly. 

I started with limit -5 because I wanted to only keep track of the amount of characters used in each part, as the <4/7> 
  at the end of each part was consistent up until I needed to add a new digit with 10, 100, etc. In my incorrect solution, 
  my condition to stop was when the limit multiplied by the max amount of parts for that digit (ex: 9 numbers that were 1 digit, 
  99 numbers that were 2 digits, etc). This is incorrect though, because there aren't 99 numbers that are 2 digits, there are only 
  90, with 9 of those still being single digits. So I just needed to multiply by 10 for that variable. However, I also needed to 
  be updating the limit as well, since, for example, if a part has a limit of 3 characters per message for the first 9 part digits 
  (abc<1/14>, def<2/14>,...bcd<9/14>), then then limit needs to decrease to allow for the extra digit in the part number 
  (fg<10/14>, hi<11/14>...). I made a helper function for this calculation, and used that as the condition for the loop in my 
  findLimit function instead.

I did have to do some unusual things, such as starting with i = 2 in the for loop in findLimit and while (digit > 9) in calcHelp:
  - I had to start at 2 because I knew that the calculation would always be done for the first limit + digit of 9, and I wanted 
  to use the digit variable as the condition for my calcHelp function. This way, I could always update limit by the lower end 
  rather than the upper end, and discover whether limit was <= 0 at any point during my calculations  (Think of this like 
  checking whether the limit for the characters was 2 rather than at 3 first for the above example, it's just a faster way of 
  arriving at the conclusion of whether it's possible to reach this limit without going into the while loop). If this were to 
  happen, then the function would just get stuck, and intuitively a part with no character section would lead the answer to go 
  on infinitely, and the problem said to return an empty array in that case.
  - digit > 9 was because my findLimit function was using calcHelp as a condition, and I needed 9 to always be my base in order 
  to not update limit extra times. I was running into a lot of issues when I tried to make the condition digit > 0, because I 
  was updating limit for test cases that should have immediately been ok with the total in the single digits.
*/

class Solution {
public:
    int calcHelp(int & limit, int digit) {
        int calc = 0;
        while (digit > 9) {
            calc += (limit * digit);
            limit++;
            digit /= 10;
        }
        calc += (limit * digit);
        return calc;
    }
    
    int findLimit(int n, int limit) {
        int digit = 9;
        for (int i = 2; calcHelp(limit, digit) < n; i++) {
            limit -= i;
            if (limit < 1) break;
            digit *= 10;
        }
        return limit;
    }

    int findTotal(int n, int limit, set<int> &digits) {
        int total = 0;
        while (limit < n) {
            n -= limit;
            total++;
            if (digits.count(total)) {
                limit--;
                if (limit <= 0) return -1;
            }
        }
        return total+1;
    }

    vector<string> splitMessage(string message, int limit) {
        vector<string> res;
        int n = message.length();
        // cout << "Message Length = " << n << endl;
        limit -= 5;
        set<int> digits = {9, 99, 999, 9999};
        
        limit = findLimit(n, limit);
        if (limit < 1) return res;
        // cout << "Limit: " << limit << endl;

        int total = findTotal(n, limit, digits);
        if (total == -1) return res;
        // cout << "Total: " << total << endl;
        
        // Create parts
        string word;
        for (int i = 0, part = 1, digit = 10, limitCheck = 1; i < n; i++) {
            word += message[i];
            if (i+1 == n || limitCheck%limit == 0) {
                word += "<" + to_string(part) + 
                    "/" + to_string(total) + ">";
                res.push_back(word);
                word.clear();
                part++;
                if (part%digit == 0) {
                    limit--;
                    digit *= 10;
                }
                limitCheck = 0;
            }
            limitCheck++;
        }

        return res;
    }
};
