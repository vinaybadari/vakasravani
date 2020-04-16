/*case 2:Find the formula for given expression and write the program for the given input expression:1+4+9+16+....+100*/
/*purpose	:Program for calculating the sum of the squares of a given number
  filename	:case2_Sumofsquares
  Author 	:Naga sravani
  Date   	:07/04/2020*/
#include<iostream>
#include<string.h>
using namespace std;
int sumofsquares(int iN)
{
        int iI,iSum=0;							//intialialized the required variables							
        for(iI=1;iI<=iN;iI++) 						//for loop to calculate the sum of series up to the nth term
	    {
            iSum+=iI*iI;							
        }
        return iSum;  
}
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)					//if loop for comparing the input string with "-h"
	    {
            cout<<"Usage:The main purpose of this program is to calculate the sum of the squares of a given number which is the following format:\n(1*1)+(2*2)+(3*3)+......(n*n) "<<endl;
            cout<<"input:4"<<endl;
            cout<<"output:30"<<endl;
	    }
    }
	else
	{
		int iN,iTotal;
		cout<<"calculating the sum of the series (1*1)+(2*2)+(3*3)+(4*4)+(5*5)+...+(n*n):"<<endl;
        cout<<"---------------------------------------------------------------------"<<endl;
		cout<<"Enter the input:";
		cin>>iN;
        iTotal=sumofsquares(iN); 
        cout<<"The sum of the above series is:"<<iTotal<<endl; 
    }
    
}

