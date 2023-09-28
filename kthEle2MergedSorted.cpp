#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    
    public:
    int kthElement(vector<int> &a, vector<int>& b, int n, int m, int k){
        if(n>m) return kthElement(b, a, m, n, k);
        int reqELE= k;
        int low= max(0, k-m), high= min(n, k);
        while (low<=high)
        {
            int mid= (low+high)/2;
            int mid2= reqELE-mid;
            int l1= INT_MIN, l2= INT_MIN, r1= INT_MAX, r2=INT_MAX;
            if(mid<n) r1= a[mid];
            if(mid2<m) r2= b[mid2];
            if(mid-1>=0) l1= a[mid-1];
            if(mid2-1>=0) l2= b[mid2-1];
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }else if(l1>r2) high= mid-1;
            else low=mid+1;
        }
        return 0;

    }
};
int main()
{
    test tst;
    vector<int> a1 = {76, 94, 100 };
    vector<int> b1 = {5, 5, 9, 11, 31, 36, 68, 71, 75, 100};
    cout<<tst.kthElement(a1, b1, a1.size(), b1.size(), 12);
    return 0;
}