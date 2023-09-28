#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    int first(vector<int> a, int n ,int k){
        int high= n-1, low=0, first=-1;

        while(low<= high){
            int mid= (low+high)/2;
            if(a[mid]== k){
                first= mid; 
                high= mid-1;
            }
            else if(a[mid]>k) high= mid-1;
            else low= mid+1;
        }
        return first;
    }
    int last(vector<int> a, int n ,int k){
        int high= n-1, low=0, lastn=-1;
        while(low<= high){
            int mid= (low+high)/2;
            if(a[mid]== k){
                lastn= mid; 
                low= mid+1;
            }
            else if(a[mid]>k) high= mid-1;
            else low= mid+1;
        }
        return lastn;
    }
    
    public:
    pair<int, int> bs(vector<int> a, int n, int k){
        int f1= first(a, n, k);
        if(f1== -1) return {-1, -1};
        int l1= last(a, n, k);
        return {f1, l1};
    }
};
int main()
{
    test tst;
    
    return 0;
}