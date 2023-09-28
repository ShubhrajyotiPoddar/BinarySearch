#include <bits/stdc++.h>
using namespace std;
class test
{
private:
    int totDays(vector<int> a, int mid){
        int cnt=1, load= mid;
        for(auto it: a){
            if(load>= it){
                 load-= it;
            }
            else{
                cnt++;
                load= mid-it;
            }
        }
        return cnt;
    }
public:
    int leastWeightCapacity(vector<int> &a, int d)
    {
        int n= a.size(), aSum=0, maxi=0;
        for(auto it: a){
             aSum+=it;
             maxi= max(it, maxi);
        }
        int low= maxi, high= aSum;
        while(low<= high){
            int mid =(low+high)/2;
            int days= totDays(a,mid);
            if(days<= d) high= mid-1;
            else low= mid+1;
        }
    return low;
    }
};
int main()
{
    test tst;

    return 0;
}