#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    public:
    int fastEater(vector<int> a, int n, int timer){
        int maxi= *max_element(a.begin(), a.end());
        int mAns=maxi;
        int low=1, high= maxi; 
        while(low<= high){
            int mid= (low+high)/2; // no of bananas/ hour
            // int Thours= ceiling(a, mid); //total hours taken
            int Thours=0;
            for(auto it: a){
                Thours= Thours+ ceil((double)it/(double)mid);
            }
            if(Thours<= timer){
                mAns= min(mid, mAns);
                high= mid-1;
                }
            else low= mid+1;
        }
        return mAns;
    }
};
int main()
{
    test tst;
    vector<int> v = {25 ,12, 8 ,14 ,19};
    int h = 5;
    int ans = tst.fastEater(v, v.size(), h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
    return 0;
}