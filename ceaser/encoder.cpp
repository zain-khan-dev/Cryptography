#include<iostream>
#include<fstream>
using namespace std;
int convertnum(char *p)
{
		int k=0;
		for(int i=0;i<p[i]!='\0';i++)
		{
				k+=p[i]-48;
				k*=10;
		}
		k/=10;
		return k;
}
int main(int argc,char *argv[])
{
		ifstream in;
		ofstream of;
		in.open(argv[1]);
		of.open(argv[2]);
		if(!in)
		{
				cerr<<"Unable to locate file";
		}
		else
		{
				string x;
				int i=0;
				int n=convertnum(argv[3]);
				while(in>>x)
				{
						for(int i=0;i<x.length();i++)
						{
								if(x[i]>=65&&x[i]<=91)
								{
										if((int)(x[i]+n)>91)
										{
												int p=char((x[i]+n)%91)+65;
												x[i]=char(p);
										}
										else
										{
												x[i]=char(x[i]+n);
										}
								}
								else
								{
										if((int)(x[i]+n)>122)
										{
												int p=char((x[i]+n)%122)+97;
												x[i]=char(p);
										}
										else
										{
												x[i]=char(x[i]+n);
										}
								}
						}
						of<<x;
						of<<" ";
				}
		}

}
