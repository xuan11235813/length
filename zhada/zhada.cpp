#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct reflect
{
	string chName;
	double dReflection;
};
class length_operator
{
private:
	vector<reflect> a;
	double sum;
public:
	length_operator()
	{
		sum=0;
	}
	~length_operator() {};
	int initial(string  p,double d)
	{
		reflect temp;
		temp.dReflection=d;
		temp.chName=p;
		a.push_back(temp);
		return 0;
	}
	int first_data(string p,double d)
	{
	
		vector<reflect>::iterator iter;
		for(iter=a.begin();iter!=a.end();iter++)
		{
			if((p[0]==(*iter).chName[0])&&(p[1]==(*iter).chName[1])||(((*iter).chName=="foot")&&(p=="feet")))
			{
				sum=d*((*iter).dReflection);
				break;
			}
		}
		return 0;
	}
	int add_data(char p1,string p2,double d)
	{
		double x=0;
		vector<reflect>::iterator iter;
		for(iter=a.begin();iter!=a.end();iter++)
		{
			if((p2[0]==(*iter).chName[0])&&(p2[1]==(*iter).chName[1])||(((*iter).chName=="foot")&&(p2=="feet")))
			{
				x=d*((*iter).dReflection);
				break;
			}
		}
		switch(p1)
		{
		case '+':
			sum+=x;
			break;
		case '-':
			sum-=x;
			break;
		default:
			cout<<"What? you son of bitch.."<<endl;
		}
		return 0;
	}
	double get_results()
	{
		return sum;
	}
	int show()
	{
		for(vector<reflect>::iterator iter=a.begin();iter!=a.end();iter++)
		{
			cout<<(*iter).chName<<endl;
		}
		return 0;
	}
};
int main()
{
	length_operator ope;
	double d;
	char ch;
	string chWord,temp;
	string strline;
	ifstream fin;
	ofstream fout;
	stringstream strin;
	fin.open("input.txt",ios_base::in);
	fout.open("output.txt",ios_base::out);
	fout<<"xuan11235813@gmail.com"<<endl;
	getline(fin,strline);
	while(strline.empty()!=1)
	{
		strin<<strline;
		strin>>temp;
		strin>>chWord;
		strin>>temp;
		strin>>d;
		strin>>temp;
		ope.initial(chWord,d);
		strin.clear();
		getline(fin,strline);
	}
	strin.clear();
	getline(fin,strline);
	//ope.show();
	while(strline.empty()!=1)
	{
		strin<<strline;
		strin>>d;
		strin>>chWord;
		ope.first_data(chWord,d);
		while(strin>>ch)
		{
			strin>>d;
			strin>>chWord;
			ope.add_data(ch,chWord,d);
		}
		d=ope.get_results();
		fout<<endl<<fixed<<setprecision(2)<<d<<" m";
		strin.clear();
		getline(fin,strline);
	}
	fin.close();
	fout.close();
	return 0;
}