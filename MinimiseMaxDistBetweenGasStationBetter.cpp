#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    int requiredGasStation(vector<int> arr, long double mid){
        int cnt=0;
        for(int i=0; i<arr.size()-1; i++){
            int InBetween2= (long double)(arr[i+1]-arr[i])/ mid;
            if(fmod((long double)(arr[i+1]-arr[i]),mid)==0) InBetween2--;
            cnt+= InBetween2;
        }
        return cnt;
    }
    public:
    long double minimiseMaxDistanceBetter(vector<int> &arr, int k)
    {
        int n= arr.size();
        vector<int> StationBetween(n-1, 0);
        priority_queue<pair<long double, int>> pq;
        for(int i=0; i<n-1; i++) pq.push({arr[i+1]-arr[i], i});
        for(int i=1; i<=k; i++){
            auto tp= pq.top(); pq.pop();
            int SecInd= tp.second;
            StationBetween[SecInd]++;
            long double SecDist= (long double)(arr[SecInd+1]- arr[SecInd])/(long double)(StationBetween[SecInd]+1);
            pq.push({SecDist, SecInd});
        }

        return pq.top().first;
    }

    long double minimiseMaxDistanceOptimal(vector<int> &arr, int k)
    {
        int n= arr.size();
        long double low=0, high=0;
        for(int i=0; i<n-1; i++){
            high= max(high,(long double)(arr[i+1]-arr[i]));
        }
        while(high-low> 1e-6){
            long double mid= (high+low)/2.0;
            int cnt= requiredGasStation(arr, mid);
            if(cnt> k) low= mid;
            else high= mid;
        }
        return high;
    }
};
int main()
{
    test tst;
    vector<int> arr = {1,13,17,23};
    int k = 5;
    long double ans = tst.minimiseMaxDistanceOptimal(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}