// Frantic solution as I only had about 10 minutes to come up with the idea and code it. Remember to RTFP!

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> robA(2), robB(2), tot(2);
  while (n--) {
    cin >> robA[0] >> robA[1] >> robB[0] >> robB[1] >> tot[0] >> tot[1];
    bool found = false;
    int aCount = 0, bCount = 0;

    int botOneCount = 1, currArmVal = robA[0];
    while (currArmVal < tot[0]) {
      if ((tot[0]-currArmVal)%robB[0] == 0) {
        int botTwoCount = (tot[0]-currArmVal)/robB[0];
        if (botOneCount*robA[1] + botTwoCount*robB[1] == tot[1]) {
          if (found) {
            found = false;
            break;
          }
          found = true;
          aCount = botOneCount;
          bCount = botTwoCount;
        }
      }

      botOneCount++;
      currArmVal = robA[0] * botOneCount;
    }

    if (found) {
      cout << aCount << " " << bCount << endl;
    } else {
      cout << "?" << endl;
    }
  }
  return 0;
}
