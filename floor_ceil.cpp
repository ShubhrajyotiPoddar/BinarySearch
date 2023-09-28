#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    
    public:
    pair<int, int> floor_ceil(vector<int> a, int n, int t){
        int fl=-1, cl=n;
        int low=0, high= n-1;
        while (low<= high)
        {
            int mid= (low+high)/2;
            if(a[mid]>= t) {
                cl= a[mid];
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        low=0; high= n-1;
        while (low<= high)
        {
            int mid= (low+high)/2;
            if(a[mid]<= t) {
                fl= a[mid];
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return {fl, cl};
    }
};
int main()
{
    test tst;
    vector<int> a = {3, 4, 6, 7, 9, 9, 12, 16, 17};
    int target = 8;
    pair<int,int>  ind = tst.floor_ceil(a,a.size(), target);
    cout<<ind.first<<" "<<ind.second;
    return 0;
}