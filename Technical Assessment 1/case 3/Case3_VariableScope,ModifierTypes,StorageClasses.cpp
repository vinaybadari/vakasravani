/*case 3: Write your own program that explains the below
1.Variable scope
2.Modifier types
3.Storage classes */
        
/*purpose	        : Program to demonstrate the variable scope,modifier types and storage classes
  filename	        : Case3_VariableScope,ModifierTypes,Storageclasses
  Author 	        : Naga sravani
  Creation Date   	: 09/04/2020
  Modified Date     : 16/04/2020 */

#include<iostream>
#include<string.h>
using namespace std;
//global variable
int iGlobal=3;                          
int iExtern;
extern int iExtern1=20;
//local scope function
void localscope()                        	
{
    //local variable
	int iLocal=20;                      	
	{
	    //local variable within the block
	    int iLocal=10;
	    cout<<"                     VARIABLE SCOPE                        "<<endl;
	    cout<<"Local variable with in the block     : "<<iLocal<<endl;
	}
	cout<<"local variable outside the block     : "<<iLocal<<endl;
}
//global scope function
void globalscope()
{
    int iGlobal=10;
    iGlobal++;
    cout<<"Global variable with in the function : "<<iGlobal<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
}
//modifier types function
void modifier()                     
{
	//initialization of modifier types
	signed int iSigned=-30;
	unsigned int iUnsigned=40;
	unsigned int iUnsigned1=-2;
	unsigned char cUnsigned2=65;
	long lLong=123456789;
	short sShort=100;
	cout<<"                     MODIFIER TYPES                         "<<endl;
	cout<<"signed int                           : "<<iSigned<<endl;
	cout<<"unsigned int as normal value         : "<<iUnsigned<<endl;
	cout<<"unsigned int as negative value       : "<<iUnsigned1<<endl;
	cout<<"unsigned int as character value      : "<<cUnsigned2<<endl;
	cout<<"long ldata                           : "<<lLong<<endl;
	cout<<"short sdata                          : "<<sShort<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
}
//storage class function
void storage()                      	 
{
	int iVar=12;
    float fVar=4.5;
    //addition of two variable with auto storage class as return type
    auto  fVar1=iVar+fVar;           		 
    cout<<"                     STORAGE CLASSES                         "<<endl;
    cout<<"value of auto variable fVar1 is                                      : "<<fVar1<<endl;
    //register storage classes initialization
    register int iReg=11;             	
    cout<<"address of register variable iReg is                                 : "<<&iReg<<endl;
    //extern storage class declaration
    extern int iExtern;                 		
    cout<<"extern storage value before initialization is                        : "<<iExtern<<endl;
    iExtern=20;
    cout<<"extern storage value after initialization is                         : "<<iExtern<<endl;
    int iTotalExtern=iExtern1+iExtern;
    cout<<"value of totalextern after adding extern global & local variable is  : "<<iTotalExtern<<endl;
    
}
//static storage class function
void staticstorage()                	
{
    static int iStatic=100;          
    iStatic++;
    cout<<"static variable  iStatic is                                          : "<<iStatic<<endl;
}
//mutable class
class number                        	
{	
	mutable int iNum;
	public:
	    //getdata function which is kept as const
		void getdata() const        	
		{
			iNum=10;
			iNum++;
		}
		//display function for displaying the mutable number
		void display()              
		{
			getdata();
			cout<<"mutable num                                                          : "<<iNum<<endl;
			cout<<"------------------------------------------------------------"<<endl;
		}
};
int main(int argc,char *argv[])
{
    if(argc==2)
    {
        //if loop for comparing the input string with "-h"		
	    if(strcmp(argv[1],"-h")==0)	  					
	    {
            cout<<"                                     USAGE                                          "<<endl;
            cout<<"This program explains the usage of variable scope,modifier types & storage classes"<<endl;
	    }
    }
    else
    {
        //calling functions
	    localscope();
	    iGlobal++;
	    cout<<"Global Variable outside the function : "<<iGlobal<<endl;
	    globalscope();
	    modifier();
	    storage();
	    staticstorage();
	    cout<<"*** staticstorage variable after incrementation is ***"<<endl;
	    staticstorage();
	    number n;
	    n.display();
    }
}
