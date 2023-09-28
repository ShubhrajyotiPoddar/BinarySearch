#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    
    public:
    int bs(vector<int> a, int n, int t){
        int low= 0, high= n-1;
        while(low<= high){
            int mid= (low+high)/2;
            if(a[mid]== t) return mid;
            else if(a[mid]<= a[high] ){
                if(a[mid]< t && a[high]>= t){
                    low= mid+1;
                }
                else high= mid-1;
            }
            else{
                if(a[low]<= t && a[mid]> t){
                    high= mid-1;
                }
                else low= mid+1;
            }
        }
        return -1;
    }
    int bsDublicates(vector<int> a, int n, int t){
        int low= 0, high= n-1;
        while(low<= high){
            int mid= (low+high)/2;
            if(a[mid]== t) return mid;
            else if(a[mid]== a[high]== a[low]){
                low++; 
                high--;
            }
            else if(a[mid]<= a[high] ){
                if(a[mid]< t && a[high]>= t){
                    low= mid+1;
                }
                else high= mid-1;
            }
            else{
                if(a[low]<= t && a[mid]> t){
                    high= mid-1;
                }
                else low= mid+1;
            }
        }
        return -1;
    }
};
int main()
{
    test tst;
    
    return 0;
}