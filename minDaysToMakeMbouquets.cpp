#include <bits/stdc++.h>
using namespace std;
class test
{
private:
    int noOfBouquets(vector<int> a, int mid, int k, int n){
        vector<int> hash(a.size(), 0); //flower bloomed/ not

        for(int i=0; i<n; i++){
            if(mid>= a[i]) hash[i]=1; 
        }
        int BouquesCreated=0, flowersCollected=0;
        for(int i=0; i<n; i++){
            if(hash[i]==1) flowersCollected++;
            else{
                BouquesCreated+= flowersCollected/k;
                flowersCollected=0;
            }
        }
        BouquesCreated+= flowersCollected/k;
        return BouquesCreated;
    }
public:
    int roseGarden(vector<int> a, int k, int m)
    {
        // m bouquets and k adjacent flowers to make a bouquets
        // arr contains after how many days each flower(element of arr) will bloom
        int maxi= *max_element(a.begin(), a.end());
        int n=a.size();
        if((m*k) > n) return -1;
        int low=1, high= maxi; 
        while(low<= high){
            int mid= (low+high)/2;
            int collectB= noOfBouquets(a, mid, k, n); //no of bouquets collected in 'mid' day;
            if(collectB>= m){
                high= mid-1;
            }
            else low= mid+1;
        }
        return low;
    }
};
int main()
{
    test tst;
    vector<int> arr = {1, 2 ,1 ,2, 7 ,2 ,2 ,3, 1};
    int k = 3;
    int m = 2;
    int ans = tst.roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}