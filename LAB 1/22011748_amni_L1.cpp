/*
ID = 22011748
Name = Nur Amni Syazwani Binti Mohamad Nasir
*/


#include <iostream>
using namespace std;

    struct Student{
        int id;
        string name;
        int contact;
        string email;
    };
    
int main()
{
    
    struct Student student[5];
    
    for (int i=0; i<5; i++){
        cout<<"Student "<<i+1<<"\n";
        cout<<"ID #"<<i+1<<" : ";
        cin>>student[i].id;
        cout<<"Name #"<<i+1<<" : ";
        cin>>student[i].name;
        cout<<"Contact #"<<i+1<<" : ";
        cin>>student[i].contact;
        cout<<"Email #"<<i+1<<" : ";
        cin>>student[i].email;
        cout<<"\n";
    }
    
    for(int i=0;i<5;i++){
        cout<<"*****************\n";
        cout<<"Student "<<i+1<<"\n";
        cout<<"ID : "<<student[i].id<<"\n";
        cout<<"Name : "<<student[i].name<<"\n";
        cout<<"Contact : "<<student[i].contact<<"\n";
        cout<<"Email : "<<student[i].email<<"\n";
        
        
    }
    
    return 0;
}