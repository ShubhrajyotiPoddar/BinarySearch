#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    
    public:
    int BinSearch(vector<int> arr, int n, int t){
        int low=0, high= n-1;
        while(low<= high){
            int mid= (low+high)/2;
            if(arr[mid]== t) return mid;
            else if(t> arr[mid]) low= mid+1;
            else high= mid-1;
        }
        return -1;
    }
};
int main()
{
    test tst;
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = tst.BinSearch(a,a.size(), target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}