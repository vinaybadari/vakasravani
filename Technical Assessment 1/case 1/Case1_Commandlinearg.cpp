/* CASE 1 : Parse the given command line and display in the below format
Input     : parser.exe 1 a sss 4.5643
Output    :
Type         Value    Sizeof
Char          A        X
Int           1        X
String        Sss      X
Float/double  4.5643   X
Note: X means are actual sizeof() value depends on the OS */

/* Purpose	    : program for calculating the type,value and size of the value by using command line arguments
  filename	    : case1_Commandlinearg
  Author 	    : Naga sravani
  Creation Date     : 07/04/2020
  Modified date     : 16/04/2020 */
  
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(int argc,char *argv[])
{
    if(argc==2)
    {
            //if loop for comparing the input string with "-h"
	    if(strcmp(argv[1],"-h")==0)							
	    {
            	cout<<"                                     USAGE                                               "<<endl;
            	cout<<"The main purpose of this program is to calculate the datatype,value and sizeof the value"<<endl;
	    }
    }
    else
    {
	    cout<<"output:"<<endl;								
	    cout<<"type"<<"\t"<<"value"<<"\t"<<"size"<<endl;
	    for(int iI=1;iI<argc;iI++)                                      
	    {
	            //atoi function for converting string to int
		    int iInt=atoi(argv[iI]);
		    //if the 'if' loop is true then char and string will be displayed
		    if(iInt==0)										
		    {
		            //condition for checking whether the datatype is char or string
			    if(strlen(argv[iI])==1)                     
				    cout<<endl<<"char";
			    else
				    cout<<endl<<"string";
				    cout<<"\t"<<argv[iI]<<"\t"<<strlen(argv[iI]);
		    }
		    //else case for displaying int and float values
		    else											
		    {
		        //converting string to float
			    float fFloat=atof(argv[iI]);                
			    if(iInt==fFloat)
			    {
				    cout<<endl<<"int"<<"\t"<<iInt<<"\t"<<sizeof(iInt);
			    }
			    else
				    cout<<endl<<"float"<<"\t"<<fFloat<<"\t"<<sizeof(fFloat);
		    }
	    }
    }
}
