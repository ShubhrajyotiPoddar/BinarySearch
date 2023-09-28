#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    public:
    int BinSearch(vector<int> a, int n, int t){
        int ans=n;
        int low=0, high= n-1;
        while (low<= high)
        {
            int mid= (low+high)/2;
            if(a[mid]>= t) {
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        
    // cout<< lower_bound(a.begin(),a.end(),t)- a.begin();
        return ans;
    }
};
int main()
{
    test tst;
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 8;
    int ind = tst.BinSearch(a,a.size(), target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}