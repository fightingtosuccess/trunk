//½«utf-8×ªÂëÎªUnicode±àÂë

#include<iostream>
#include<string>

using namespace std;

class Unicode
{
	public:
		static unsigned int UTF8toUnicode(const char *ch, unsigned int iLen, unsigned int &unicode);
};

unsigned int Unicode::UTF8toUnicode(const char *ch, unsigned int iLen, unsigned int &unicode)
{
	const char *p = ch;
	unsigned int e = 0, n = 0;
	if (p == NULL)
	{
		return n;
	}
	switch(*p)
	{
		case 252 ... 255:
			if(iLen >= 6)
			{
				e = (p[0] & 0x01) << 30;
				e |= (p[1] & 0x3f) << 24;
				e |= (p[2] & 0x3f) << 18;
				e |= (p[3] & 0x3f) << 12;
				e |= (p[4] & 0x3f) << 6;
				e |= (p[5] & 0x3f);
				n = 6;
			}
			break;
		case 248 ... 251:
			if(iLen >= 5)
			{
				e = (p[0] & 0x03) << 24;
				e |= (p[1] & 0x3f) << 18;
				e |= (p[2] & 0x3f) << 12;
				e |= (p[3] & 0x3f) << 6;
				e |= (p[4] & 0x3f);
				n = 5;
			}
			break;
		case 240 ... 247:
			if(iLen >= 4)
			{
				e = (p[0] & 0x07) << 18;
				e |= (p[1] & 0x3f) << 12;
				e |= (p[2] & 0x3f) << 6;
				e |= (p[3] & 0x3f);
				n = 4;
			}
			break;
		case 224 ... 239:
			if(iLen >= 3)
			{
				e = (p[0] & 0x0f) << 12;
				e |= (p[1] & 0x3f) << 6;
				e |= (p[2] & 0x3f);
				n = 3;
			}
			break;
		case 192 ... 223:
			if(iLen >= 2)
			{
				e = (p[0] & 0x1f) << 6;
				e |= (p[1] & 0x3f);
				n = 2;
			}
			break;
		default:
			if(iLen >= 1)
			{
				e = p[0];
				n = 1;
			}
			break;
	}
	unicode = e;
	return n;
}

int main()
{
	string str = "ºº×Ö";
	unsigned int len = str.size();
	unsigned int unicode;
	Unicode::UTF8toUnicode(str.c_str(),len,unicode);
	cout<<unicode<<endl;
	return 0;
}