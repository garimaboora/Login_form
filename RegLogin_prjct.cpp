#include <iostream>
#include <string>
#include<fstream>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choice;
    cout << "    ***************Welcome to the Login page***************    " << endl;
    cout << "                         MENU                       " << endl;
    cout << "Press 1 to LOGIN" << endl;
    cout << "Press 2 to REGISTER" << endl;
    cout << "Press 3 if you forgot your password" << endl;
    cout << "Press 4 to EXIT" << endl;
    cout << "Please enter your choice : " << endl;
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "Thank you!!";
        break;

    default:
        system("cls");                   // used to clean the screen
        cout << "Please select from the options given above " << endl;
        main();
    }
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout<<"Please enter the username and password: "<<endl;
    cout<<"USERNAME ";
    cin>>userId;
    cout<<endl;
    cout<<"PASSWORD ";
    cin>>password;
    cout<<endl;

    ifstream input("records.txt");    // help to read the data --->check if pass and username already exist in records

    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();                  // close the file

    if(count==1)
    {
        cout<<userId<<endl<<"Your LOGIN is successfull"<<endl<<"Thanks for logging in"<<endl;
        main();                      // shift the control to the main
    } 
    else
    {
        cout<<"LOGIN ERROR"<<endl<<"Please check your username and password"<<endl;
        main();
    }

}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout<<"Enter the username: ";
    cin>>ruserId;
    cout<<"Enter the password: ";
    cin>>rpassword;
    cout<<endl;

    ofstream f1("records.txt", ios::app);     // help to write the data inside the file
                                              // app will open the file and append the output in the end
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"Registration is successfull"<<endl;
    main();                                          

}

void forgot()
{
    int option;
    system("cls");
    cout<<"You forgot the password??"<<endl;
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cout<<"Enter your choice "<<endl;
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserId,spass,sId;
            cout<<"Enter the username which you remembered : ";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sId>>spass)
            {
                if(sId==suserId)
                {
                    count=1;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"Your account is found!!"<<endl;
                cout<<"Your password is: "<<spass;
                main();
            }
            else
            {
                cout<<"Sorry, your account is not found!"<<endl;
                main(); 
            }
            break;
        }
        
        case 2:
        {
            main();
        }
        default:
        cout<<"Wrong choice, Try again "<<endl;
        forgot();

    }
}