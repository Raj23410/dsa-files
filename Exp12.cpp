#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;
const int maxrow = 10;
string EmpName[maxrow]={};
string EmpId[maxrow]={};

void OpenFile()
{
    string line;
    ifstream myfile("E:\\employee.txt");
      if(myfile.is_open())
        {
          int x=0;  
          while(getline(myfile,line))
           {
              int l=line.length();
                 EmpId[x]=line.substr(0,3);
                // EmpName[x]=line.substr(4,1,-4);
                 x++;
           }
        }   
      else
       {
           cout<<"Unable to open the file"<<endl;
       }
    

}

void AddRecord()
{
   char name[50];
   char empno[5];
   cin.ignore();  //to clear the characters from input buffer
   cout<<"Employee Id..:";
   cin.getline(empno,5);
   cout<<"Employee Name..:";
   cin.getline(name,50);
   for(int x=0;x<maxrow;x++)
     {
       if(EmpId[x] =="\0") //if array is empty following will be loaded
         {
            EmpId[x]=empno;
            EmpName[x]=name;

            break;
         }
     }
}

void ListRecord()
{
   system("CLS");  // to clear the screen
   
   cout<<"Current Records"<<endl;
  
   cout<<"==========================================="<<endl;
   int counter = 0;
   cout<<"No.     |  ID    |  NAME        "<<endl<<"---------------------------------------\n";
   for(int x=0;x<maxrow;x++)
     {
       if(EmpId[x]!="\0")
         {
           counter++;
           cout<<"    " <<counter <<"    " <<  EmpId[x] <<"        "<<  EmpName[x] << endl;
           //break;
         }
     }
         if(counter==0)
           {
              cout<<"No records to display"<<endl;

           }
              cout<<"----------------------------------------"<<endl;
}

void searchRecord(string search)
{
    system("CLS");
    cout<<"Current Record"<<endl;
    cout<<"======================================"<<endl;
    int counter=0;
    for(int x=0;x<maxrow;x++)
       {

          if(EmpId[x]==search)
            {
                counter++;
                cout<<"  " <<counter <<"  " <<EmpId[x] <<"            "<<EmpName[x] << endl;
                break;
            }
        }
          if(counter==0)
            {
                cout<<"No records found.."<<endl;

            }
                cout<<"----------------------------------";
}

void DeleteRecord(string search)
{
    int counter = 0;
    for (int x=0;x<maxrow;x++)
      {
        if (EmpId[x]==search)
        {
          counter++;
          EmpName[x]="";
          EmpId[x]="";
          cout<<"Successfully deleted.."<<endl;
          break;
        }
      }

    if (counter==0)
        {
           cout<<"ID Number does not exist!!";
        }
}

void SaveToFile()
{
  ofstream myfile;
  myfile.open("E:\\employee.txt");
    for(int x=0;x<maxrow;x++)
      {
         if (EmpId[x]=="\0")  //there is no data then terminate the loop
           {
              break;
           }
        else
           {
              myfile<< EmpId[x] + " , " + EmpName[x] <<endl;
           }
      }
}

int main()
{
    string eId;
    
    cout<<"Menu";
    int option;
    system("CLS");
    OpenFile();

    do{
        cout<<"1.Create"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"======================================"<<endl;
        cout<<"Select any option";
        cin>>option;

        switch(option)
          {
            case 1:AddRecord();
            system("CLS");
            break;

            case 2:
            cin.ignore();
            cout<<"Delete by ID >>";
            getline(cin,eId);
            DeleteRecord(eId);
            cin.ignore();
            system("CLS");
            break;

            case 3:
           
            cin.ignore();
            cout<<"Search by Id >>:";
            getline(cin,eId);
            searchRecord(eId);
            break;

            case 4:ListRecord();
            break;

            case 5:SaveToFile();
            //cout<<"Exit..Saving to file!!"<<endl;

        }
    }while (option!=5);

SaveToFile();
cout<<"Exit..Saving to file!!"<<endl;
return 0;
}


