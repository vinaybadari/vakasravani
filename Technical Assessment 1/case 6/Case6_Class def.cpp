/*case 6:program to demonstrate the constructor/destructor/operator overloading and member functions using integer pointer and character array as private variables*/
/*filename	:Case6_Classdef
  Author 	:Naga sravani
  Date   	:09/04/2020 */
#include<iostream>
#include<string.h>
using namespace std;
class student
{
    	private:
	    int *iRollno;									//integer pointer declaration
	    char cName[20];									//char array declaration
	public:
	    student()										//default constructor
	    {
	        cout<<"default constructor is called"<<endl;
	    }
	    student(char *cStudname)								//parameterized constructor
	    {
	        strcpy(cName,cStudname);
	        cout<<"parameterized constructor is called"<<endl;
	    }
	    void display()
	    {
	        cout<<"student name:"<<cName<<endl;
	    }
	    student operator+(student s)							//+ operator overloading 
	    {
	        student temp=cName;
	        strcat(temp.cName,s.cName);
	        return temp;
	    }	
	    ~student()										//student destructor	
	    {
		    cout<<"student destructor"<<endl;
	    }
	    friend int increment();
};
//friend function declaration
int increment()
{   
    int iA[2]={1,2};
    int *iRollno;										
    iRollno=&iA[0];
    cout<<"student rollno before incrementation:"<<*iRollno<<endl;
    iRollno++;											//incrementing rollno
    cout<<"student rollno after incrementation: "<<*iRollno<<endl;
}
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)	 							//if loop for comparing the input string with "-h"			 				
	    {
            cout<<"                       		USAGE                                       "<<endl;
            cout<<" This program uses integer pointer,character array and describes them using "<<endl;
            cout<<"   constructor/destructor/operator overloading and member function   "<<endl;
	    }
    }
    else
    {
        student obj("  sravani");								//calling parameterized constructor
        student obj1("	vaka");
        student obj2;
        obj2=obj1+obj;										//concatenationg two objects
        obj2.display();
        increment();
    }
}
