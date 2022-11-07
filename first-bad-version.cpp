#include <iostream>

using namespace std;

bool isBadVersion(int version);  // API which returns whether version is bad.
int firstBadVersion(int n);

int main(int argc, char const *argv[]) {
  return 0;
}

// find out the first bad version
// n = number of versions
int firstBadVersion(int n) {
  int start = 1;
  int end = n;
  int mid = (end - start) / 2;

  if (n == 0)
    return 0;
  if (n == 1)
    return isBadVersion(n);

  while ((end - start) >= 0) {
    mid = (end - start) / 2;
    if ((isBadVersion(start) == false) && (isBadVersion(start + 1) == true)) {
      return start;
    }

    if ((isBadVersion(end) == true) && (isBadVersion(end - 1) == false)) {
      return (end - 1);
    }
    if (isBadVersion(mid) == true) {
      // mid version is bad that means our first bad version is
      // between the start and mid
      start++;
      end = mid - 1;
    } else {
      // mid version is good that means our first bad version is
      // between mid and end
      start = mid + 1;
      end--;
    }
  }
}

// API which returns whether version is bad.
// returns true if the version is bad
// returns false if the version is good
bool isBadVersion(int version) {
  if (version < 20)
    return false;
  else
    return true;
}