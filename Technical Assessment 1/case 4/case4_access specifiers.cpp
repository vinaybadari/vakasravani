/* case 4: what is the purpose and difference in public,private and protected access specifiers.Illustrate a design example with this */

/*purpose			: Program to demonstrate access specifiers
  filename			: case4_accessspecifiers
  Author 			: Naga sravani
  creation Date   		: 09/04/2020 
  Modified Date			: 16/04/2020 */
  
#include<iostream>
#include<string.h>
using namespace std;
//base class
class base							
{
 	private:
        	int iPrivatedata;
    	public:
            int iPublicdata;
 	protected:
 	    	int iProtecteddata;
 	//base constructor
 	base() 							
 	{
 	   iPrivatedata=10;
 	   iPublicdata=20;
 	   iProtecteddata=30;
 	}
};
class derived:private base
{
 	public:
 	    void show()
 	    {
 	    	cout<<" ACCESSMODE AS PRIVATE "<<endl;
 	    	//cout<<" value of iPrivatedata is "<<iPrivatedata<<endl;
            	cout<<" iPrivatedata cannot be accessible because it is declared as private "<<endl;
            	cout<<" value of iPublicdata is     "<<iPublicdata<<endl;
            	cout<<" value of iProtecteddata is  "<<iProtecteddata<<endl;
            	cout<<"--------------------------------------------------------------------"<<endl;
 	    }
};
class derived1:protected base					
{
 	public:
 	    void show()
 	    {
 	        cout<<" ACCESSMODE AS PROTECTED "<<endl;
 	        //cout<<" value of iPrivatedata is "<<iPrivatedata<<endl;
            	cout<<" iPrivatedata cannot be accessible because it is declared as private "<<endl;
            	cout<<" value of iPublicdata is     "<<iPublicdata<<endl;
            	cout<<" value of iProtecteddata is  "<<iProtecteddata<<endl;
            	cout<<"--------------------------------------------------------------------"<<endl;
 	    }
};
class derived2:public base				 
{
 	public:
 	    void show()
 	    {
 	        cout<<" ACCESSMODE AS PUBLIC "<<endl;
 	        //cout<<" value of iPrivatedata is "<<iPrivatedata<<endl;
            	cout<<" iPrivatedata cannot be accessible because it is declared as private "<<endl;
            	cout<<" value of iPublicdata is     "<<iPublicdata<<endl;
            	cout<<" value of iProtecteddata is  "<<iProtecteddata<<endl;
            	cout<<"--------------------------------------------------------------------"<<endl;
 	    }
};
int main(int argc,char *argv[])
{
    if(argc==2)
    {
            //if loop for comparing the input string with "-h"	
	    if(strcmp(argv[1],"-h")==0)	 			 				
	    {
            cout<<"                       			USAGE                                       "<<endl;
            cout<<"		This program explains the usage of access specifiers	"<<endl;
	    }
    }
    else
    {
        //derived object creation
	derived a;						
    	derived1 b;
    	derived2 c;
    	//accessing data using object
    	a.show();						
    	b.show();
    	c.show();
    	return 0;
    }
}
