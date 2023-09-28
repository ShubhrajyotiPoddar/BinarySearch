// given arr(2 3 4 7 11), k= 5 
// missing 1 5 6 8 9 10 return 5th ele i.e. 9
#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    
    public:
    int missingKthEle(vector<int> a,int n, int k){
        for(int i=0; i<n; i++){
            if(a[i]<= k){
                k++;
            }
            else break;
        }
        return k;
    }
    int missingKthEle2(vector<int> a,int n, int k){
        //find the adjacent indexes between which the number will be present
        //in the vec 5th ele will be present between 7, 11 because:
        // 0 ele: 2- (0+1) => 1 ele missing
        // 3 ele: 7- (index+1) => 3 ele missing
        // therefore, 11- 5 => 6 ele missing, k==5 so number between 7,11
        int low= 0, high=n-1, ans=0;
        while(low<= high){
            int mid= (low+high)/2;
            int miss= a[mid]- (mid+1);
            if(miss>= k){
                ans=mid;
                high= mid-1;
            }   
            else{
                low= mid+1;
            }
        }
        // int x= a[ans-1]- (ans);
        // int y = k-x;
        // return a[ans-1]+ y;
        int missEleOfH= a[high]-(high+1);
        return a[high]+(k-missEleOfH);
    }
};
int main()
{
    test tst;
    vector<int> vec = {2,3,4,7,11};
    int n = vec.size(), k = 5;
    int ans = tst.missingKthEle2(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}