#include<iostream>
#include<fstream>
using namespace std;
string convert(string p)
{
		for(int i=0;i<p.length();i++)
		{
				if(p[i]>=97)
				{
						p[i]-=32;
				}
		}
		return p;
}
int main(int argc,char *argv[])
{
		ifstream i;
		i.open(argv[1]);
		ofstream o;
		o.open(argv[2]);
		string s="";
		string key=argv[3];
		key=convert(key);
		int present=0;
		string x;
		while(i>>x)
		{
				string k="";
				for(int i=0;i<x.length();i++)
				{
						if(x[i]>=97)
						{
								int p=(int)(x[i]-32-key[present]);
								if(p<0)
								{
										k+=char(123+p);
								}
								else
								{
										k+=char(p+97);
								}
						}
						else
						{
								int p=(int)(x[i]-key[present]);
								if(p<0)
								{
										k+=char(91+p);
								}
								else
								{
										k+=char(p+65);
								}
						}
						present++;
						present%=key.length();
				}
				o<<k;
				o<<" ";
		}
}
