// arr contains gas station distance place k new gas station such that the min distance between them reduces
#include <bits/stdc++.h>
using namespace std;
class test
{
private:
public:
    long double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int n= arr.size();
        vector<int> StationBetween(n-1, 0);
        long double maxi= -1;
        for(int i=1; i<=k; i++){
            long double maxDist=0;
			int mInd= -1;
            for(int i=0; i<n-1; i++){
                long double diff= (long double)(arr[i+1]-arr[i])/(long double)(StationBetween[i]+1);
                if(diff> maxDist){
                    maxDist= diff;
                    mInd= i;
                }
            }
            StationBetween[mInd]++;
        }
        for(int i=0; i<n-1; i++){
            long double diff= (long double)(arr[i+1]-arr[i])/(long double)(StationBetween[i]+1);
            maxi= max(maxi, diff);
        }
        return maxi;
    }


    //Better Aproach
    
};
int main()
{
    test tst;
    vector<int> arr = {1,13,17,23};
    int k = 5;
    long double ans = tst.minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}