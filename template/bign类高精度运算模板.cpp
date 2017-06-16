#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstdlib>
using namespace std;
const int MAX=3000;
struct bign
{
	int length,s[MAX];
	bign(){memset(s,0,sizeof(s));/*s[0]=1;*/length=1;system("pause");}
	bign(int num)
	{
		*this=num;
	}
	bign(const char*num)
	{
		*this=num;														//bign x=100;做直接赋值运算 有实参的构造函数 
	}
	/*  bign(int num) {
    *this = num;
  }

  bign(const char* num) {
    *this = num;
  }*/
	void clean()
	{
		while(length>1&&!s[length-1])length--;
	}
	/*  void clean() {
    while(len > 1 && !s[len-1]) len--;
  }*/
	bign operator = (const char*num)
	{
		length=strlen(num);
		for(int i=0;i<length;i++)
		{
			s[i]=num[length-1-i]-'0';
		}
		return *this;
	}
	bign operator = (int num)
	{
		char s[MAX];
		sprintf(s,"%d",num);
		*this=s;
		return *this;
	}
	/*  bign operator = (int num) {
    char s[maxn];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
  }

  bign operator = (const char* num) {
    len = strlen(num);
    for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
    return *this;
  }*/
	string str()const
	{
		string res="";
		for(int i=0;i<length;i++)
		{
			res=char(s[i]+'0')+res;
		}
		if(res=="")res="0";
		return res;
	}
	/*
  string str() const {
    string res = "";
    for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
    if(res == "") res = "0";
    return res;
  }*/
	bign operator + (const bign& b) const
	{
		bign c;
		c.length=0;
		for(int i=0,g=0;g||i<max(length,b.length);i++)
		{
			int x=g;
			if(i<length)x+=s[i];
			if(i<b.length)x+=b.s[i];
			c.s[c.length++]=x%10;			//同时变化c.length 
			g=x/10;                         //直接覆盖原值的方法最好了。。。能覆盖最先想覆盖 
		}
		c.clean();
		return c;
	}
	/*  bign operator + (const bign& b) const{
    bign c;
    c.len = 0;
    for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
      int x = g;
      if(i < len) x += s[i];
      if(i < b.len) x += b.s[i];
      c.s[c.len++] = x % 10;
      g = x / 10;
    }
    return c;
  }*/
	bign operator * (const bign& b) const
	{
		bign c;c.length=length+b.length;
		for(int i=0;i<length;i++)
		{
			for(int j=0;j<b.length;j++)
			{
				c.s[i+j]+=s[i]*b.s[j];
				/*cout<<c.s[0];*/
			}
		}
		for(int i=0;i<c.length-1;i++)
		{	
			c.s[i+1]+=(c.s[i]/10);
			c.s[i]%=10;
			/*cout<<c.s[0];*/
		}
		c.clean();
		return c;
	}
/*	  bign operator * (const bign& b) {
    bign c; c.length = length + b.length;
    for(int i = 0; i < length; i++)
      for(int j = 0; j < b.length; j++)
        c.s[i+j] += s[i] * b.s[j];
    for(int i = 0; i < c.len-1; i++){
      c.s[i+1] += c.s[i] / 10;
      c.s[i] %= 10;
    }
    c.clean();
    return c;
  }
*/
	bign operator +=(const bign& b)
	{
		*this=*this+b;
		return *this;
	}
	/*  bign operator += (const bign& b) {
    *this = *this + b;
    return *this;
  }*/
	bign operator - (const bign& b) const
	{
		bign c;
		c.length=0;
		for(int i=0,g=0;i<length;i++)			//默认前边的数大 
		{
			int current=s[i]-g;
			g=0;
			if(i<b.length)current-=b.s[i];
			if(current<0)
			{
				current+=10;
				g=1;
			}
			c.s[c.length++]=current;
		}
		c.clean();
		return c;
	} 
	/*  bign operator - (const bign& b) {
    bign c; c.len = 0;
    for(int i = 0, g = 0; i < len; i++) {
      int x = s[i] - g;
      if(i < b.len) x -= b.s[i];
      if(x >= 0) g = 0;
      else {
        g = 1;
        x += 10;
      }
      c.s[c.len++] = x;
    }
    c.clean();
    return c;
  }*/
	bool operator < (const bign&b)const
	{
		if(length!=b.length)return length<b.length;							//无前导0时的比较 
		for(int i=length-1;i>=0;i--)
		{
			if(s[i]!=b.s[i])return s[i]<b.s[i]; 
		}
		return false;
	}
	/*  bool operator < (const bign& b) const{
    if(len != b.len) return len < b.len;
    for(int i = len-1; i >= 0; i--)
      if(s[i] != b.s[i]) return s[i] < b.s[i];
    return false;
  }*/
	bool operator > (const bign&b)const
	{
		return b<*this;
	}
	bool operator >=(const bign&b)const
	{
		return !(*this<b);
	}
	bool operator <=(const bign&b)const
	{
		return !(*this>b);
	}
	bool operator ==(const bign&b)const
	{
		return !(b>*this)&&!(b<*this);
	}
	/*  bool operator > (const bign& b) const{
    return b < *this;
  }

  bool operator <= (const bign& b) {
    return !(b < *this);
  }

  bool operator == (const bign& b) {
    return !(b < *this) && !(*this < b);
  }
*/		
};
istream& operator >>(istream& in,bign& x)
{
	string s;
	in>>s;
	x=s.c_str();
	return in;
}
ostream& operator <<(ostream& out,const bign& x)
{
	out<<x.str();
	return out;
}
/*istream& operator >> (istream &in, bign& x) {
  string s;
  in >> s;
  x = s.c_str();
  return in;
}

ostream& operator << (ostream &out, const bign& x) {
  out << x.str();
  return out;
}*/
int main()
{
	bign a;a="33333333333";
	bign b="333333333";
	bign c="12333333333333333333333333333333333333";
	bign g="012333333333333333333333333333333333333";
	bign e=1233333;
	e.str();
	bign f;
	bign d;cin>>d;
	cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl;
	d=a*b;cout<<"d=a*b"<<d<<endl;
	d=a+b;cout<<"d=a+b"<<d<<endl;
	d=a-b;cout<<"d=a-b"<<d<<endl;
	e+=e;cout<<"e+=e"<<e<<endl;
	c.clean();g.clean();
	cout<<"c<g"<<(c<g)<<endl;
	cout<<"c<=g"<<(c<=g)<<endl;
	cout<<"c>g"<<(c>g)<<endl;
	cout<<"c>=g"<<(c>=g)<<endl;
	cout<<"c==g"<<(c==g)<<endl;
	return 0;
}
