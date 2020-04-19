/* case 2:Find the formula for given expression and write the program for the given input expression: 1+4+9+16+....+100 */

/*purpose	        : Program for calculating the sum of the squares of a given number
  filename	        : case2_Sumofsquares
  Author 	        : Naga sravani
  Creation Date   	: 07/04/2020
  Modified Data     	: 16/04/2020 */
  
#include<iostream>
#include<string.h>
using namespace std;
int sumofsquares(int iNum)
{
	//intialialized the required variables
        int iI,iSum=0;	
	//for loop to calculate the sum of series up to the nth term
        for(iI=1;iI<=iNum;iI++) 						
	{
            iSum+=iI*iI;							
        }
        return iSum;  
}
int main(int argc,char *argv[])
{
    if(argc==2)
    {
	    //if loop for comparing the input string with "-h"
	    if(strcmp(argv[1],"-h")==0)					
	    {
            	cout<<"                                                         USAGE                                                           "<<endl;
            	cout<<"The main purpose of this program is to calculate the sum of the squares of a given number which is the following format:\n(1*1)+(2*2)+(3*3)+......(n*n) "<<endl;
            	cout<<"input : 4"<<endl;
            	cout<<"output: 30"<<endl;
	    }
    }
    else
    {
	int iNum,iTotal;
	cout<<"calculating the sum of the series (1*1)+(2*2)+(3*3)+(4*4)+(5*5)+...+(n*n):"<<endl;
        cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"Enter the input:";
	cin>>iNum;
        iTotal=sumofsquares(iNum); 
        cout<<"The sum of the above series is:"<<iTotal<<endl; 
    }
}
