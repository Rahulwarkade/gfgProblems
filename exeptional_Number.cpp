#include<bits/stdc++.h>
using namespace std; 


    int getOddOccurrence(int arr[], int n) {
        // code here
        int start = 0; 
        int end = n-1;
        int exep = 0;
        while(start<=end)
        {
            if(start==end)
                exep^=arr[start++];
            else
                exep ^= arr[start++]^arr[end--];
        }
        
        return exep;
    }

    int main()
    {
        int t; 
        cin>>t; 

        while(t--)
        {
            int n;
            cin>>n; 
            int arr[n];
            for(int i=0; i<n; i++)
                cin>>arr[i];

            cout<<getOddOccurrence(arr,n)<<endl;
        }
    }