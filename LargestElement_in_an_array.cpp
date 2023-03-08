#include<bits/stdc++.h>
using namespace std;

// void lsOptimized(vector<int> &vac)
// {
// 	int largest = INT_MIN;
// 	for(int &val : vac)
// 	{
// 		if( val>largest)
// 			largest =val;
// 	}

// 	cout<<largest<<endl;
// }
void lsBruteFA(vector<int> &vac)
{
	sort(vac.begin(),vac.end());//O(N*log(n))
	cout<<vac[vac.size()-1]<<endl;
}
int main(){
	vector<int> vac;
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		vac.push_back(x);
	}

	// ls - largest element
	lsBruteFA(vac);
	lsBruteFA(vac);
}