/**********************************************************
 * Author        : Zhang He
 * Email         : zhanghe901126@163.com
 * Last modified : 2014-11-18 14:54
 * Filename      : cpp4.cpp
 * QQ            : 935949330
 * Description   : the exersise of question 4 in chapter 8 p306; 
 * *******************************************************/

#include "head.h"


//Initialize of static menber data
int Student::sum = 0;
int Student::nos = 0;
double Student::ave = 0;


void cpp4()
{
	Student * pt , * pt_pri;
	Student * pt_head;
	int i=1,j=1;

	Student stu1(0,0);
	pt_head=&stu1;
	
	cout<<"//////////////////////////////////////////////////"<<endl;
	cout<<"////////Enter the score of every students/////////"<<endl;
	cout<<"//////////////////////////////////////////////////"<<endl;
	//setnumber: "space" ends the input of one student; "enter" ends all the inputs
	do{
		pt=new Student;
		pt_head->point_net=pt;
		pt->point_pre=pt_head;
		pt_head=pt->setnum( i , pt );
		i++;								//point to the prior Student

	}while(getchar()!=32);

												//the last student od the link is the head

	cout<<endl;
	cout<<"/////////////////////////"<<endl;
	cout<<"////////Display//////////"<<endl;
	cout<<"/////////////////////////"<<endl;
	//display:
	pt=pt_head;
	for(j=1;j<=i-1;j++)
	{
		pt->display();
		pt=pt->point_pre;							//point to prior student
	}

	
	cout<<endl;
	cout<<"/////////////////////////"<<endl;
	cout<<"///////Ranking///////////"<<endl;
	cout<<"/////////////////////////"<<endl;	
	//ranking...............................
	
	pt=pt_head;

	for(j=1;j<=i-1;j++)
	{
		pt->disrank(j);
		pt=pt->point_pre;
	}
		
	cout<<endl;
	cout<<"/////////////////////////"<<endl;
	cout<<"///////Searching//////////"<<endl;
	cout<<"/////////////////////////"<<endl;	
	cout<<"Please enter the number of the student you want to search :";
	int a;
	cin>>a;
	pt=pt_head;

	for(j=1;j<=i-1;j++)
	{
		pt->info(a);
		pt=pt->point_pre;	
	}
	
			
	cout<<endl;
	cout<<"/////////////////////////"<<endl;
	cout<<"///////Deleting//////////"<<endl;
	cout<<"/////////////////////////"<<endl;	

	pt=pt_head;

	for(j=1;j<=i-1;j++)
	{
		pt=pt_head;
		delete pt_head;
		pt_head=pt->point_pre;	
	}
		

}
