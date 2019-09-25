#include<iostream>
#include<fstream>
using namespace std;
string convert(string s)
{
		for(int i=0;i<s.length();i++)
		{
				if(s[i]>=97)
				{
						s[i]-=32;
				}
		}
		return s;
}
int main(int argc,char * argv[])
{
		char c[26][26];
		for(int i=0;i<26;i++)
		{
				int count=0;
				for(int j=i;j<26+i;j++)
				{
						if((j+65)>90)
						{
								int p=(j+65)%91;
								c[i][count]=char(p+65);
						}
						else
						{
								c[i][count]=char(j+65);

						}
						count++;

				}
		}
		ifstream i;
		ofstream of;
		i.open(argv[1]);
		of.open(argv[2]);
		int present=0;
		string key=argv[3];
		key=convert(key);
		string x;
		string p="";
		if(!i)
		{
				cerr<<"Unable to locate file";
		}
		else
		{
				while(i>>x)
				{
						p="";
						for(int i=0;i<x.length();i++)
						{
								if(x[i]<=91)
									p+=c[key[present]-65][x[i]-65];
								else
										p+=char(c[key[present]-65][x[i]-97]+32);
								present++;
								present%=key.length();
						}
						of<<p;
						of<<" ";
				}
		}
}
