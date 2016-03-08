//¸ù¾ÝÄ³¸ö×Ö·û·Ö¸î×Ö·û´®
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>

using namespace std;

class SplitString
{
public:
	static void Split(string& str,string pattern,vector<string>& result);
};

void SplitString::Split(string& str,string pattern,vector<string>& result)
{
	char buf[4096];
	snprintf(buf,sizeof(buf),"%s",str.c_str());
	char* tmpstr = buf;
	const char* tmppattern = pattern.c_str();
	char* token = NULL;
	token = strsep(&tmpstr,tmppattern);
	while(NULL != token)
	{
		result.push_back(token);
		token = strsep(&tmpstr,tmppattern);
	}
}


int main()
{
	string str = "abf&sadsa&dasda";
	vector<string> result;
	SplitString::Split(str,"&",result);
	for(size_t i = 0;i < result.size();++i)
	{
		cout<<result[i]<<endl;
	}
	return 0;
}














