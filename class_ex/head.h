/**********************************************************
 * Author        : Zhang He
 * Email         : zhanghe901126@163.com
 * Last modified : 2014-11-18 16:42
 * Filename      : head.h
 * QQ            : 935949330
 * Description   : head file for all the cpp about chapter 8 and chapter 9 
 * *******************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

//the defination of class Student for cpp4
class Student
{
	private:
	int num;						//the student number
	int grade;						//the student's score
	int rank;						//the student's ranking
	static int sum;				//the sum of all the score
	static double ave;			//the average score 
	static int nos;				//the number of students

	
	public:

	Student * point_pre;
	Student * point_net;				//the point for link list , point to the prior student

	Student(int n=999 ,int g=0):num(n),grade(g){}			//constructor

	~Student()
	{ cout<<"Destructor of num  "<<num<<"  is running"<<endl;}  //destructor 
	
	Student * setnum(int i, Student * point_self)  //
	{
		int k;
		Student * point_temp_p;
		Student * point_temp_pp;
		Student * point_temp_n;
		Student * point_head;

		point_temp_p = point_pre;
		point_temp_pp = point_pre->point_pre;
		point_temp_n = point_net;
		point_head = point_self;	//the new student is the default head

		num = i;
		cout<<"Please enter the score of student "<<num<<"  socre : ";
		cin>>grade;
		cout<<endl;
		sum=sum+grade;
		nos=nos+1;
		ave=sum/double(nos);

		if(num>=2)
		{
			for(k=1;k<=num-1;k++)
			{
				cout<<"k="<<k<<endl;
				if(grade>=(point_pre->grade)) 
				{   
					cout<<"biggggggg"<<endl;
					break;
				}
				else if(k==1)							//exchange the head point in the first
				{
					point_head=point_pre;					//the head point is the prior stufent
					cout<<"Exchanging the point head........."<<endl;
					//pre
					point_temp_p = point_pre;
					point_temp_pp = point_pre->point_pre;
					point_pre =point_pre->point_pre;
					point_temp_p->point_pre = point_self;
					//net
					point_temp_n = point_net;
					point_net = point_temp_p;
					point_temp_pp->point_net = point_self;

					cout<<point_pre->grade<<" "<<grade<<" "<<point_temp_p->grade<<endl;
	
				}
				else 
				{
					cout<<"Exchanging......."<<endl;
					//pre
					point_temp_p = point_pre;
					point_temp_pp = point_pre->point_pre;
					point_pre =point_pre->point_pre;
					point_temp_p->point_pre = point_self;
					//net
					point_temp_n = point_net;
					point_net->point_pre = point_temp_p;
					point_net = point_temp_p;
					point_temp_p->point_net = point_temp_n;
					point_temp_pp->point_net = point_self;
				
					cout<<point_pre->grade<<" "<<grade<<" "<<point_temp_p->grade<<endl;
				}
			}
    	}  
	return point_head;
	}

	void display()	
	{
		cout<<"the student num is "<<num<<"  grade is "<<grade<<endl;
	}
	
	void disrank(int i)
	{
		rank=i;
		cout<<"Ranking: " <<rank<<"  Student num: "<<num<<"  Sore: "<<grade<<endl;
	}

	void info(int i)
	{
		if(i==num)
		{
			cout<<"Student Number:  "<<num<<endl;
			cout<<"Score         :  "<<grade<<endl;
			cout<<"Average Score :  "<<ave<<endl;
			cout<<"Ranking       :  "<<rank<<endl;
			cout<<"Total Number  :  "<<nos<<endl;
		}
	}

};

//the defination of function cpp4
void cpp4();













