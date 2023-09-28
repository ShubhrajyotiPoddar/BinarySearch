#include<bits/stdc++.h>
using namespace std;
class test{
    private:
    
    public:
    int singleNonDuplicate(vector<int>& a)
    {

	int n= a.size();
	if(n==1) return a[0];
	for(int i=0; i<n; i++){
		if(i==0 && a[i]!= a[i+1]){
			return a[i];
		}
		else if(i==n-1 && a[i]!= a[i-1]) return a[i];
		else if(a[i]!= a[i-1] && a[i]!= a[i+1]) return a[i];
	}
	return -1;
    }
    int singleNonDub(vector<int> a, int n){
        int low=1, high= n-2;
        if(n==1) return a[0];
        if(a[0]!= a[1]) return a[0];
        if(a[n-1]!= a[n-2]) return a[n-1];
        while(low<= high){
            int mid= (low+high)/2;
            if(a[mid]!= a[mid-1] && a[mid]!= a[mid+1]) return a[mid];
            else if(a[mid]== a[mid-1]){
                int ind= mid-1;
                if(ind%2==0) low= mid+1;
                else high= mid-1;
            }
            else if(a[mid]== a[mid+1]){
                int ind= mid;
                if(ind%2==0) low= mid+1;
                else high= mid-1;
            }
        }
        //if((a[mid]%2==1 && a[mid]== a[mid-1]) || (a[mid]%2==0 && a[mid]== a[mid+1 ])) low= mid+1
        // else high= mid-1;
        return -1;
    }
};
int main()
{
    test tst;
    
    return 0;
}