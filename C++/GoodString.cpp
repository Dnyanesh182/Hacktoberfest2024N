#include < bits/stdc++.h>
using namespace std;
int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int good = 0;
    vector< int> a;
    for(auto i:s1) {
        a.push_back((int)i);
    }
    sort(a.begin(),a.end());
    int res = 0;
    int prev = (int)s1[0];
    for(auto i:s2) {
        int b = (int) i;
        int l = 0,r=a.size()-1;
        int good = INT_MAX;
        int curr = -1;
        while(l< =r) {
            int mid = (l+r)/2;
            if(a[mid] == b) {
                curr = prev;
                good = 0;
                break;
            }
            else if(a[mid] < b) {
                if(abs(a[mid]-b) < good) {
                    good = abs(a[mid]-b);
                    curr = a[mid];
                }
                else if(abs(a[mid]-b) == good) {
                    if(abs(curr-prev) > abs(a[mid]-prev)) {
                        curr = a[mid];
                        good = abs(a[mid]-prev);
                    }
                    else {
                        good = abs(curr-prev);
                    }
                }
                l=mid+1;
            }
            else {
                if(abs(a[mid]-b) < good) {
                    good = abs(a[mid]-b);
                    curr = a[mid];
                }
                else if(abs(a[mid]-b) == good) {
                    if(abs(curr-prev) > abs(a[mid]-prev)) {
                        curr = a[mid];
                        good = abs(a[mid]-prev);
                    }
                    else {
                        good = abs(curr-prev);
                    }
                }
                r=mid-1;
            }
        }
        prev = curr;
        res+=good;
    }
    cout << res;
}
