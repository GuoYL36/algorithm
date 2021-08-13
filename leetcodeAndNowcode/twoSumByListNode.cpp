#include<iostream>
#include<string>

using namespace std;


int main()
{
	int count = 0;
	string a1="937";
	string a2="63";
	int length1=a1.size()-1;
	int length2=a2.size()-1;
	cout<<length1<<" "<<length2<<endl;
	string res="";
	while(length1>=0&&length2>=0){
		int tmp = (a1[length1]-'0')+(a2[length2]-'0')+count;
		count = tmp/10;
		res+=to_string(tmp%10);
		length1--;
		length2--;
	}
	cout<<res<<endl;
	while(length1>=0){
		int tmp = (a1[length1]-'0')+count;
		count = tmp/10;
		res+=to_string(tmp%10);
		length1--;
	}
	cout<<res<<endl;
	while(length2>=0){
		int tmp = (a2[length2]-'0')+count;
		count = tmp/10;
		res+=to_string(tmp%10);
		length2--;
	}
	if(count>0){
		res+=to_string(count);
	}
	cout<<res<<endl;
	
}



