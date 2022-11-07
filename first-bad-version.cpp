#include <iostream>

using namespace std;

bool isBadVersion(int version);  // API which returns whether version is bad.
int firstBadVersion(int n);

int main(int argc, char const *argv[]) {
  cout << "first bad version: " << firstBadVersion(1792997410) << endl;
  return 0;
}

// find out the first bad version
// n = number of versions
int firstBadVersion(int n) {
  int start = 1;
  int end = n;
  int mid = (end - start) / 2;

  // if there are no (0) versions
  if (n == 0)
    return 0;

  // if there is only 1 version
  if (n == 1)
    return isBadVersion(n);

  // if the very first version is bad
  if (isBadVersion(1) == true)
    return 1;

  while ((end - start) >= 0) {
    mid = ((end - start) / 2) + start;
    if (isBadVersion(mid)) {
      // cout << start << "-" << end << " mid: " << mid << " is bad" << endl;
      // mid is bad
      // check mid-1
      if (!isBadVersion(mid - 1)) {
        // mid-1 is good
        return (mid);
      }
      // the first bad is between start and mid
      start++;
      // TOD0: if new start is bad, return start-1
      end = mid - 1;
    } else {
      // mid is good
      // cout << start << "-" << end << " mid: " << mid << " is good" << endl;
      // check mid+1
      if (isBadVersion(mid + 1)) {
        // mid+1 is bad
        return (mid + 1);
      }
      // the first bad is between mid and end
      start = mid + 1;
      end--;
    }

    // is start bad
    if (isBadVersion(start)) {
      return start;
    }

    // is end good
    if (isBadVersion(end) == false) {
      return (end + 1);
    }
  }
  return -1;
}

// API which returns whether version is bad.
// returns true if the version is bad
// returns false if the version is good
bool isBadVersion(int version) {
  if (version >= 1240808008)
    return true;
  else
    return false;
}