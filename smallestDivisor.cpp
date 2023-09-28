#include <bits/stdc++.h>
using namespace std;
class test
{
private:
    int quotient(vector<int> a, int mid){
        int cnt=0;
        for(auto it: a){
            cnt+= ceil((double)it/(double)mid);
        }
        return cnt;
    }
public:
    int smallestDivisor(vector<int> &a, int limit)
    {
        int maxi= *max_element(a.begin(), a.end());
        int n= a.size(), low=1, high= maxi;
        while(low<= high){
            int mid= (low+high)/2;
            int qtotal= quotient(a, mid);
            if(qtotal<= limit) high= mid-1;
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