#include<bits/stdc++.h>

vector<char> digit;
vector<char> operand;

/*Each of the following k lines consists of an arithemtic expression. 
This expression consists of numbers (0-9) seperated by 
one of the two operators '*' and '+'. 
There are no spaces between the characters.

	TPO is game changer in your career.
	

*/


void f1()
{
	string s;
	cin>>s;

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


	

}

int main()
{
	int t;cin>>t;

	while(t--)
	{f1();}



	return 0;
}
