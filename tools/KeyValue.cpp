//分割key value
#include<iostream>
#include<string>
#include<map>

using namespace std;

class KeyValue
{
public:
    static void ParseKeyValue(map<string,string>& mapResult,const string& str);

};

void KeyValue::ParseKeyValue(map<string,string>& mapResult,const string& str)
{
    mapResult.clear();
    const char* ptr = str.c_str();
    string key = "";
    string value = "";
    bool valueFlag = false;
    while('\0' != *ptr)
    {
        if('&' == *ptr)
        {
            if(!key.empty())
            {
                mapResult.insert(make_pair(key,value));
            }
            key = "";
            value = "";
            valueFlag = false;
        }
        else if('=' == *ptr)
        {
            valueFlag = true;
        }
        else
        {
            if(valueFlag)
            {
                value += *ptr;
            }
            else
            {
                key += *ptr; 
            }
        }
        ++ptr;
    }
    if(!key.empty())
    {
        mapResult.insert(make_pair(key,value));
    }

}

int main()
{
    string str = "ab=1&cd=2&ef=3";
    map<string,string> result;
    KeyValue::ParseKeyValue(result,str);
    for(map<string,string>::iterator it = result.begin();
            it != result.end();++it)
    {
        cout<<"key:"<<it->first<<" value:"<<it->second<<endl;
    }
    return 0;
}
