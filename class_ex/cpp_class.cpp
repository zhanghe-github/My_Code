/**********************************************************
 * Author        : Zhang He
 * Email         : zhanghe901126@163.com
 * Last modified : 2014-11-15 16:07
 * Filename      : cpp_class.cpp
 * QQ            : 935949330
 * Description   : study and exercise the defination of class and object 
 * *******************************************************/
#include <iostream>
#include <stdio.h>

using namespace std;

class Student
{
	private:
	//The private Data and Member Functions
	
	public:
	//The public Data and Member Functions
	
};  //do not forget the ';'

Student stud1,stud2;  //the defination of object stud1 and object stud2

class Array_Max
{
	private:
	int *a;			//the initial of objedt is unavailable
	int max;
	int num;
	public:
	Array_Max(int ,int ,int * );
	void set_value();
	void print_value();
	void print_max();
};

//constructor function
Array_Max::Array_Max(int s1,int s2,int *s3 ):max(s1),num(s2)
{
	a=s3;
}

void Array_Max::set_value()
{
   	int i=0;

	do{
		cin>>a[i++];

	}while(getchar()!=10);
	num=i;
}

void Array_Max::print_value()
{
	int i=0;
	cout<<"the whole number you enter is : "<<num<<endl;
	for(i=0;i<=num-1;i++)
	{
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}

void Array_Max::print_max()
{
	int i=0;
	for(i=0;i<=num-1;i++)
	{
		max=(a[i]<=a[i+1])? a[i+1] : a[i];
	}

	cout<<"the max value is : "<<max<<endl;
}

int main()
{
	int s1[100]={0};
	Array_Max mymax(0,0,s1); 
	mymax.set_value();
	mymax.print_value();
	mymax.print_max();

return 0;
}


