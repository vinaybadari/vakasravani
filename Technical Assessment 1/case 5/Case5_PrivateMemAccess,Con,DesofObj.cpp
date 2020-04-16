/*case 5:Program to demonstrate the different ways of initializing the private variables and order of constructing and destructing objects with and without virtual*/
/*filename	:Case5_PrivateMemAccess&con&desofobj
  Author 	:Naga sravani
  Date   	:09/04/2020 */
#include<iostream>
#include<string.h>
using namespace std;
class a                                         //base class a
{
	private:
		int iX;
		int iL;
	public:
		int test()                      //test function for accessing private variable
		{
			iX=30;
			cout<<"accessing the private variable 'x' using function"<<endl; 
			cout<<"value of x is : "<<iX<<endl;
		}
		friend int sum();               //friend function for accessing the members outside the class
	protected:
	    int iZ=500;	
};
int sum()                                       //calling function sum
{
	int iL=100;
	cout<<"Declared the sum function as friend of class 'a' and printing the private variable 'l'"<<endl;
	cout<<"value of l is : "<<iL<<endl;
	return iL;
}
class base					//base class			
{
    public:
        base()					//base class constructor
        {
            cout<<"base class constructor"<<endl;
        }
        virtual void function()			//virtual member function
        {
            int iV=10;
            cout<<"base class function value:"<<iV<<endl;
        }
        virtual ~base()				//virtual destructor
        {
            cout<<"base class destructor"<<endl;
        }
};
class derived:public base			
{
    public:
        derived()				//derived class constructor
        {
            cout<<"derived class constructor"<<endl;
        }
        void function()
        {
           int iL=20;
           cout<<"derived class function value:"<<iL<<endl;
        }
        ~derived()				//derived destructor
        {
            cout<<"derived class destructor"<<endl;
        }
};
int main(int argc,char *argv[])
{
    	if(argc>=2)
    	{
	    if(strcmp(argv[1],"-h")==0)	  	//if loop for comparing the input string with "-h"				
	    {
            cout<<"                                    USAGE                                          "<<endl;
            cout<<"	This program demonstrates the different ways to initialize	"<<endl;
            cout<<"	the private variables in a class and usage of constructing 	"<<endl;
            cout<<" 	and destructing objects with and without virtual "<<endl;
	    }
    	}
    	else
	{   
        	a obj;
	    	//obj.iX;		         //cannot access the private variable from class a
	    	cout<<"***** DIFFERENT WAYS TO INITIALIZE THE PRIVATE VARIABLES IN A CLASS *****"<<endl;
	    	cout<<"------------------------------------------------------------------------"<<endl;
	    	cout<<"x is not accessible because it is private variable of class a"<<endl;
	    	cout<<"L is not accessible because it is private variable of class a"<<endl;
	    	//obj.iZ;		         //cannot access the protected variable of class a
	    	cout<<"z is not accessible because it is protected variable of class a"<<endl;
	   	obj.test();
	    	sum();
	    	cout<<"------------------------------------------------------------------------"<<endl;
	    	cout<<"***** ORDER OF THE CONSTRUCTION AND DESTRUCTION OF OBJECTS WITH AND WITHOUT VIRTUAL ****"<<endl;
        	base *b=new derived();		//creating the derived class dynamically using base pointer
        	b->function();
        	derived d;			//derived object creation
        	d.function();
        	delete b;			//freeing the allocated memory
	}
}
