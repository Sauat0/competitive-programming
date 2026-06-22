#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // for speed in competitive programming
    cin.tie(nullptr);

    int target; // number that we want to find
    cin >> target;

    vector<int> a = {1, 2, 3, 4, 5, 10, 20, 40, 50}; // the array (vector), must be sorted!

    int l = 0, r = int(a.size()) - 1; // defining edges
    bool found = false; // flag for detecting

    while(l <= r) {
        int m = l + (r - l) / 2; // preventing integer overflow
        if(a[m] == target) {
            cout << "Found on index " << m << endl; // the number is found
            found = true;
            break;
        }
        else if(a[m] > target) {
            r = m - 1; // the number is on the left
        }
        else { // a[m] < target
            l = m + 1; // the number on the right
        }
    }

    if(!found) cout << "There is no such number in the array!\n"; // response if we did not find the number 
    
    return 0;
}
