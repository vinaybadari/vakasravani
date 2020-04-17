/*case 7:notes.ini configuration operations*/
/*filename	:Case7_notesconfig.cpp
  Author 	:Naga sravani
  Date   	:16/04/2020*/
#include<iostream>
#include<list>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
class note
{
private:
    char cKey[500];
    char cValue[100];
public:
	void getkey()
    	{
        	cout<<"Enter key:";
        	getchar();
        	cin.get(cKey,500,'\n');
    	}
	void getvalue()
    	{
        	cout<<"Enter value:";
        	getchar();
        	cin.get(cValue,100,'\n');
    	}
	char* outkey()
    	{
        	return cKey;
   	}
	char* outvalue()
    	{
        	return cValue;
    	}
    	void display()                                     //function for displaying key and value
    	{
        	cout<<cKey<<"\t"<<cValue<<endl;
    	}
};
void removefile()
{
    note s;
    int iCount;
    ifstream in("notes.ini",ios::in);                     //opens the file for input operations
    while(1)
    {
        in.read((char*)&s,sizeof(s));                     //reading the contents in file
        iCount++;
        if(in.eof())break;                                //checking for end of file
    }
    if(iCount==0)
    {
        cout<<"file is removed"<<endl;
        remove("notes.ini");                             //removes the file
    }
}
int searchupdate(list<note> &std,char* cOption)
{
    note s;
    list<note>:: iterator it;                            
    ofstream outfile("notes.ini",ios::trunc|ios::out);       
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(strcmp(s.outkey(),cOption)==0)
        {
            std.erase(it);                                  
            cout<<"Enter value to update"<<endl;
            s.getvalue();
            std.push_back(s);                               
            return 1;
        }
    }
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        outfile<<s.outkey()<<"="<<s.outvalue()<<endl;
    }
    outfile.close();                                
}
void addtofile(list<note> &std)
{
    note s;
    list<note>:: iterator it;
    char cOption='y';
    while(cOption=='y')
    {
        ofstream outfile("notes.ini",ios::trunc|ios::out);
        s.getkey();
        if(searchupdate(std,s.outkey())==1)         
            cout<<"updated"<<endl;
        else
        {
            s.getvalue();
            std.push_back(s);
            for(it=std.begin();it!=std.end();it++)
            {
                s=*it;
                outfile<<s.outkey()<<"="<<s.outvalue()<<endl;
            }
        }
        cout<<"Do you want to append notes data(y/n)?";
        cin>>cOption;
        outfile.close();
    }
}
void deletefromfile(list<note> &std)
{
    char ckey[500];
    note s;
    list<note>:: iterator it;
    ofstream outfile("notes.ini",ios::trunc|ios::out);
    cout<<"Enter the key to delete:";
    getchar();
    cin.get(ckey,500,'\n');
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(strcmp(s.outkey(),ckey)==0)
        {
            std.erase(it);
            cout<<"Deleted successfully"<<endl;
        }
    }
    removefile();
    for(it=std.begin();it!=std.end();it++)
    {
            s=*it;
            outfile<<s.outkey()<<"="<<s.outvalue()<<"\n";
    }
    outfile.close();
}
void showfromfile()
{
    note s;
    ifstream in("notes.ini",ios::in);                   //Opens for input operations.
    char cdata[500];
    if(!in.eof())
    {
        in.getline(cdata,500);
        cout<<cdata<<endl;
    }
}
void searching(list<note> &std)
{
    note s;
    char cCheck;
    char cSearch_key[500];
    char cSearch_value[100];
    list<note>:: iterator it;
    ifstream in("notes.ini",ios::in);                   //Opens for input operations.
    cout<<"do u want search key or value(k/v):";
    cin>>cCheck;
    if(cCheck=='k')
    {
        cout<<"Enter key u want to search:";
        getchar();
        cin.get(cSearch_key,500,'\n');
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(strcmp(cSearch_key,s.outkey())==0)
                cout<<s.outkey()<<"="<<s.outvalue()<<endl;
        }
    }
    else if(cCheck=='v')
    {
        cout<<"Enter the value you want to search:";
        getchar();
        cin.get(cSearch_value,100,'\n');
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(strcmp(cSearch_value,s.outvalue())==0)
                cout<<s.outkey()<<"="<<s.outvalue()<<endl;
        }
    }
    else
        cout<<"Enter k or v:"<<endl;
}
int main(int argc,char* argv[])
{
    if(argc==2)
    {
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<"notes.ini file configuration operations"<<endl;
        }
    }
    else
    {
        list<note> std;
        list<note>:: iterator it;
        char cOpt;
        while(1)
        {
            cout<<"Select your option 1.add 2.delete 3.display 4.search 5.exit"<<endl;
            cin>>cOpt;
            switch(cOpt)
            {
                case '1':
                        addtofile(std);
                        break;
                case '2':
                        deletefromfile(std);
                        break;
                case '3':
                        showfromfile();
                        break;
                case '4':
                        searching(std);
                        break;
                case '5':
                        exit(0);
                default:
                        return 0;
            }
        }
    }
    return 0;
}
