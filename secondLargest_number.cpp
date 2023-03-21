#include<bits/stdc++.h>
using namespace std;

void slnOptimized(vector<int> &vec)
{
	if(vec.size()==1){
		cout<<"-1"<<endl;
	}
	else{

		int largest = vec[0];
		int secondLargest = INT_MIN;
		int prev;
		for(int i=1; i<vec.size(); i++)
		{
			if(vec[i]>largest)
			{
				largest = vec[i];
				prev = vec[i-1];
			}
			if(prev<largest && prev>secondLargest)
			{
				secondLargest = prev;
			}
		}

		if(secondLargest==INT_MIN)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<secondLargest<<endl;
		}
	}	
}
void slnBruteFA(vector<int> &vec)
{
	if(vec.size()==1)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		sort(vec.begin(),vec.end());
		for(int i=vec.size()-2; i>0; i++)
		{
		if(vec[vec.size()-i]!=vec[vec.size()-1]){
			cout<<vec[vec.size()-2];
			break;
		}
		}
		cout<<"-1"<<endl;
	}
}
void print2largest(int arr[], int n) {
	    // code here
	    int firstLargest = INT_MIN;
	    int secondLargest = INT_MIN;
	    
	    for(int i=0; i<n; i++)
	    {
            if(arr[i]>firstLargest)
            {
                firstLargest = arr[i];
            }
	    }
	    for(int i=0; i<n; i++)
	    {
            if(arr[i]!= firstLargest && arr[i]>secondLargest)
            {
                secondLargest = arr[i];
            }
	    }
	    if(secondLargest==INT_MIN) secondLargest = -1;
	    cout<<secondLargest;
	}
int main(){
	int n;
	cin>>n;
	vector<int> vec;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		vec.push_back(x);
	}

	//sln - second largest number

	slnOptimized(vec);
}