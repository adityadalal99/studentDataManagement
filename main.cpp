// Pharmacy Management System System CodeWithC

#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
using namespace std;

// Global Variable
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
// Global Variable End

class dbconnection
{
public:
    static void initdb()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout<<"Connected";
            system("cls");
        }
        else
            cout << "Error:" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "i", 0, NULL, 0);
        if (conn)
        {
            cout << "Connected To MySql" << conn << endl;
            //cout << "Press any key to continue..." << endl;
            // getch();
            system("cls");
        }
        else
            cout << "Connection Failed" << mysql_errno(conn) << endl;
    }
};

void display();
void inserti();
int main()
{
    // Initial Load
    system("cls");
    system("title Student Database Management System");
    //system("color 0f");
    // Initial Load End

    // Call Methods
    dbconnection::initdb();
    // Call Methods End

    // Variables
    int chooseOneFromMenu = 0;
    //char exitSurity;
    int num = 1;
    int fin = 0;

    //Welcome();
    while(1) {
        fin = num;
        cout << fin << ". Display Students" << endl;
        fin += num;
        cout << fin << ". Add Student Details" << endl;
        fin += num;
        cout << fin << ". Find Item From List" << endl;
        fin += num;
        cout << fin << ". Add Item in Stock" << endl;
        fin += num;
        cout << fin << ". Update Stock Item" << endl;
        fin += num;
        cout << fin << ". Delete Stock Item" << endl;
        fin += num;
        cout << fin << ". Exit" << endl;
        cout << "Choose One: ";
        cin >> chooseOneFromMenu;
    switch(chooseOneFromMenu)
    {
       case 1:
        if(conn)
          {display();}
        else{
            cout<<"Connection not established";
        }
       break;
       case 2:
        if(conn)
        {
            inserti();
        }
        else{ cout<<"ERROR";}
        break;
        case 7:
        exit(1);
        break;
    }

    }


    return 0;
}
void display(){


  qstate=mysql_query(conn,"select * from student");
  if(!qstate)
  {

      res=mysql_store_result(conn);
      while(row=mysql_fetch_row(res))
      {

          cout<<"\nRollNo:"<<row[0]<<endl;
          cout<<"Name:"<<row[1]<<endl;
          //cout<<"\n";
      }
  }
  else
  {

      cout<<"Query not executed:"<<endl;
  }

}
void inserti(){

 string n,r,q;
 cout<<"\n Enter roll no:";
 cin>>r;
 cout<<"Enter Name:";
 cin>>n;

 q="insert into student(RollNo,Name) values('"+r+"','"+n+"')";
 const char * qu=q.c_str();
 cout<<"query:"<<qu;

 qstate=mysql_query(conn,qu);
 if(!qstate)
 {
     display();
 }
 else
 {
     cout<<"FAILED";
 }


}
