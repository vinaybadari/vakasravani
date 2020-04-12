/*case 4:Program to demonstrate access specifiers*/
/*purpose	:Program to demonstrate access specifiers
  filename	:case4_accessspecifiers
  Author 	:Naga sravani
  Date   	:09/04/2020 */
#include <iostream>
#include<string.h>>
using namespace std;
class base											//base class
{
 	private:
        int iJ;
 	protected:
 	    int iK;
 	public:
 	    int iL;
 	base() 											//base constructor
 	{
 	   iJ = 1;
 	   iK = 2;
 	   iL = 3;
 	}
};
class derived:private base							//k and l becomes private members of class derived and j remains as private 					
{
 	public:
 	    void showdata()
 	    {
 	        cout <<  "   *** Using Accessmode as private***    " << endl;
            cout <<  "   j cannot be not accessible because we declared as private " << endl;
            cout <<  "   value of k is   " << iK << endl;
            cout <<  "   value of l is   " << iL << endl;
            cout<<"---------------------------------------------------------------"<<endl;
 	    }
};
class derived1:protected base						//k and l becomes protected members of class derived1 and j remains as private 
{
 	public:
 	    void showdata()
 	    {
 	        cout<<   "   *** Using Accessmode as protected***  " << endl;
 	        cout <<  "   j is not Accessible because we declared as private " << endl;
            cout <<  "   value of k is   " << iK << endl;
            cout <<  "   value of l is   " << iL << endl;
            cout<<"----------------------------------------------------------------"<<endl;
 	    }
};
class derived2:public base							//k and l becomes public members of class derived2 and j remains as private 
{
 	public:
 	    void showdata()
 	    {
 	        cout<<   "   *** Using Accessmode as public*** " << endl;
 	        cout <<  "   j is not Accessible because we declared as private " << endl;
            cout <<  "   value of k is   " << iK << endl;
            cout <<  "   value of l is   " << iL << endl;
            cout<<"----------------------------------------------------------------"<<endl;
 	    }
};
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)	 			 	//if loop for comparing the input string with "-h"				
	    {
            cout<<"                       			USAGE                                       "<<endl;
            cout<<"		This program explains the usage of access specifiers	"<<endl;
	    }
    }
	else
	{
		derived a;									//derived object creation
    	derived1 b;
    	derived2 c;
    	a.showdata();								//accessing data using object
    	b.showdata();
    	c.showdata();
    	return 0;
	}
}	
	
    
