/*case 1:Parsing the command line argument to main function for calculating the type,value and size of the value*/
/*Purpose	:program for calculating the type,value and size of the value by using command line arguments
  filename	:case1_Commandlinearg
  Author 	:Naga sravani
  Date   	:07/04/2020*/
#include<iostream>
#include<string.h>
#include"Case1_helpfun.cpp"
#include<stdlib.h>
using namespace std;
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)				//if loop for comparing the input string with "-h"
	    {
            	help();
	    }
    else
    {
	int iI=1;
	cout<<argv[0]<<endl;					//printing the filename.exe by using argv[0]
	cout<<"type"<<"\t"<<"value"<<"\t"<<"size"<<endl;
	while(iI<argc)                                      	//while loop for checking the argcount
	{
		int iA=atoi(argv[iI]);				//atoi function for converting string to int
		if(iA==0)					//if the 'if' loop is true then char and string will be displayed
		{
			if(strlen(argv[iI])==1)
				cout<<endl<<"char";
			else
				cout<<endl<<"string";
				cout<<"\t"<<argv[iI]<<"\t"<<strlen(argv[iI]);
		}
		else						//else case for displaying int and float values
		{
			 float fB=atof(argv[iI]);
			 if(iA==fB)
			 {
				 cout<<endl<<"int"<<"\t"<<iA<<"\t"<<sizeof(iA);
			 }
			 else
				 cout<<endl<<"float"<<"\t"<<fB<<"\t"<<sizeof(fB);
		}
		iI++;
	}
    }
    }
}
