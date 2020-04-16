/*case 4:Program to demonstrate access specifiers*/
/*purpose	:Program to demonstrate access specifiers
  filename	:case4_accessspecifiers
  Author 	:Naga sravani
  Date   	:07/04/2020 */
#include<iostream>
#include<string.h>
using namespace std;
class a                                         //base class a
{
	private:
		int iX;
		int iL;
	public:
		static int iY;
		int test()                              //test function for accessing private variable
		{
			iX=30;
			cout<<"-------------------------------------------------------------------------"<<endl;
			cout<<"accessing the private variable 'x' using function"<<endl; 
			cout<<"value of x is : "<<iX<<endl;
		}
		friend int sum();                       //friend function for accessing the members outside the class
	protected:
	     int iZ=500;	
};
int a::iY=10;
int sum()                                       //calling function sum
{
	int iL=100;
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"Declared the sum function as friend of class 'a' and printing the value 'l'"<<endl;
	cout<<"value of l is : "<<iL<<endl;
	return iL;
}
class b:protected a                             //derived class b
{
    public:
    void display()                              //display function for accessing protected variable of class a
    {
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"accessing the protected variable of class 'a'"<<endl;
        cout<<"value of z is : "<<iZ<<endl;
    }
};
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)				//if loop for comparing the input string with "-h"
	    {
            cout<<"help"<<endl;
	    }
    }
    else
    {
	    a obj;
	    //obj.iX;		                        //cannot access the private variable from class a
	    cout<<"x is not accessible because it is private variable of class a"<<endl;
	    obj.iY;
	    cout<<"value of y is : "<<obj.iY<<endl;
	    //obj.iZ;		                        //cannot access the protected variable of class a
	    cout<<"z is not accessible because it is protected variable of class a"<<endl;
	    obj.test();
	    sum();
	    b obj2;
	    obj2.display();
    }
}
