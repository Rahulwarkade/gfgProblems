#include<bits/stdc++.h>
using namespace std;

string largestOddBF(string& s)
{
	int n = s.length();
	int mxOdd = INT_MIN;
	string ans = "";
	for(int i=0; i<n; i++)
	{
		int j;
		string temp = "";
		for(j =i; j<n; j++);
		{
			for(int k =i; k<=j; k++)
			{
				if(k==0)
				{
					char ch = s[k];
					temp += ch;
				}
				else{
					temp += s[k];
				}
				int num = stoi(temp);

				if(num%2!=0)
				{
					mxOdd = max(num,mxOdd);
				}
			}

		}
	}

	if(mxOdd!=INT_MIN) ans = to_string(mxOdd);

	return ans;
}

string maxOdd(string s) {
        int idx = s.size() - 1;
        while (idx >= 0) {
            if ((s[idx] - '0') % 2) break;
            idx--;
        }
        if (idx < 0) return "";
        return s.substr(0, idx + 1);
}

int main()
{
	string str;
	cin>>str;

	cout<<maxOdd```(str)<<endl;
}