#include<bits/stdc++.h>

using namespace std;

vector<char> digit;
vector<char> operand;

/*Each of the following k lines consists of an arithemtic expression. 
This expression consists of numbers (0-9) seperated by 
one of the two operators '*' and '+'. 
There are no spaces between the characters.

	TPO is game changer in your career.
	

*/


int dp[1001][1001];
int  count1=0;
int partition(int s,int e)
{
	//cout<<count1<<"---"<<s<<" to "<<e<<endl;;
	count1++;
	if(s==e){ return digit[s-1]-'0'+0;}

	if(dp[s][e]!=-1){return dp[s][e];}

	int low=100000;

	for(int k=s;k<e;k++)
	{
		int ans;
		if(operand[k-1]=='+')
		{
			ans=partition(s,k)+partition(k+1,e);
		}
		else{
			ans=partition(s,k)*partition(k+1,e);
		}

		low=min(ans,low);

	}

	dp[s][e]=low;
	return dp[s][e];

}



void f1()
{
	string s;
	cin>>s;

	digit.clear();
	operand.clear();

	// Separate digits and operand
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			digit.push_back(s[i]);		
		}
		else
		{
			operand.push_back(s[i]);
		}
	}


	for(int i=1;i<=digit.size();i++)
	{
		for(int j=1;j<=digit.size();j++)
		{
			dp[i][j]=-1;
		}
	}

	int ans=partition(1,digit.size());
	cout<<ans<<endl;

}

int main()
{
	int t;cin>>t;

	while(t--)
	{f1();}



	return 0;
}
