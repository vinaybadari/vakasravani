/*case 3:program to demonstrate the variable scope,modifier types and storage classes*/
/*purpose	:Program to demonstrate the variable scope,modifier types and storage classes
  filename	:Case3_VariableScope,ModifierTypes,Storage classes
  Author 	:Naga sravani
  Date   	:09/04/2020*/
#include<iostream>
#include<string.h>
using namespace std;
int iA=10;                          	//global variable
int iE;
extern int iEx=20;
void scope()                        	//variable scope function
{
	int iB=20;                      //local variable
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"                     VARIABLE SCOPE                        "<<endl;
	cout<<"global variable a:"<<iA<<endl;   
	cout<<"local variable  b:"<<iB<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
}
void modifier()                     	//modifier types function
{
	//initialization of modifier types
	signed int iData=-30;
	unsigned int iUdata=40;
	long lData=12345678;
	short sData=100;
	cout<<"                     MODIFIER TYPES                         "<<endl;
	cout<<"signed int idata   : "<<iData<<endl;
	cout<<"unsigned int uidata: "<<iUdata<<endl;
	cout<<"long ldata         : "<<lData<<endl;
	cout<<"short sdata        : "<<sData<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
}
void storage()                      	 //storage class function
{
	int iX=10;
    	float fY=3.5;
    	auto fZ=iX+fY;           	//addition of two variable with auto storage class as return type
    	cout<<"                     STORAGE CLASSES                         "<<endl;
    	cout<<"value of auto variable z is                               : "<<fZ<<endl;
    	register int iR=10;             //register storage classes initialization
    	cout<<"address of register variable r is                         : "<<&iR<<endl;
    	extern int iE;                 	//extern storage class declaration
    	cout<<"extern storage value before initialization is             : "<<iE<<endl;
    	iE=20;
    	cout<<"extern storage value after initialization is              : "<<iE<<endl;
    	int iAe=iEx+iE;
    	cout<<"value of ae after adding extern global & local variable is: "<<iAe<<endl;
    
}
void staticstorage()                	//static storage class function
{
    static int iS=100;          
    iS++;
    cout<<"static variable s is                                      :"<<iS<<endl;
}
class number                        	//mutable class
{	
	mutable int iNum;
	public:
		void getdata() const    //getdata function which is kept as const
		{
			iNum=10;
			iNum++;
		}
		void display()          //display function for displaying the mutable number
		{
			getdata();
			cout<<"mutable num                                               :"<<iNum<<endl;
			cout<<"------------------------------------------------------------"<<endl;
		}
};
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)	 //if loop for comparing the input string with "-h"				
	    {
            	cout<<"                                     USAGE                                          "<<endl;
            	cout<<"This program explains the usage of variable scope,modifier types & storage classes"<<endl;
	    }
    }
    else
    {
        //calling functions
	scope();
	modifier();
	storage();
	staticstorage();
	cout<<"*** staticstorage variable after incrementation is ***"<<endl;
	staticstorage();
	number n;
	n.display();
    }
}
