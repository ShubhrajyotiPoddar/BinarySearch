#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    
    public:
    int rotatedSortedSmallest(vector<int> a, int n){
	int low=0, high= n-1, ans= INT_MAX;
        while (low<= high)
        {
            int mid= (low+high)/2;
            if(a[low]<= a[mid]){
                ans= min(ans, a[low]);
                low= mid+1;
            }
            else if(a[mid]<= a[high]){
                ans= min(ans, a[mid]);
                high= mid-1;
            }
        }
        return ans;
    }
};
int main()
{
    test tst;
    
    return 0;
}