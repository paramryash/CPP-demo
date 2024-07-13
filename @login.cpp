#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <cmath>
#include <cstring>
using namespace std;


void login();
void registration();
void forgot();

int main()
{

    int c;
    cout << "                        ____________________________________________________________________________\n";
    cout << "                        ______________________WELCOME TO THE LOGIN PAGE __________________________\n ";
    cout << "                       ______________________          MENU            ___________________________\n";
    cout << endl;
    cout << "                        PRESS 1 TO LOGIN                     |\n";
    cout << "                        PRESS 2 TO RAGISTER                  |\n";
    cout << "                        PRESS 3 IF YOU FORGOT YOUR PASSWORD  |\n";
    cout << "                        PRESS 4 TO EXIT                      |\n";
    cout << endl;
    cout << "                        PLEASE ENTER YOUR CHOICE :";
    cin >> c;
    cout << endl;

    switch (c)
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
        cout << "                       THANK YOU !                                                                   \n";
        break;

    default:
        system("clear");

        cout << "                       PLEASE SELECT FROM THE OPTIONS GIVEN ABOVE                                      \n";
        main();

        
    }

}

void login()
{
    int count;
    string userid, password, id, pass;
    system("clear");
    cout << "                          PLEASE ENTER THE USERNAME AND PASSWORD :\n";
    cout << "                          USERNAME :";
    cin >> userid;
    cout << "                          PASSWORD :";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass)
    {

        if (id == userid && pass == password)
        {
            count = 1;
            system("clear");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userid << "\n YOUR LOGIN IS SUCESSFUL \n THANKS FOR LOGGING IN \n";
        main();
    }
    else
    {
        cout << "  \n                  LOGIN ERROR " << endl;
        cout << "  \n                  PLEASE CHAKE USERNAME AND PASSWORD" << endl;
        main();
    }
}

void registration()
{
    string ruserid, rpassword, rid, rpass;
    system("clear");

    cout << "                          ENTER THE USERNAME :";
    cin >> ruserid;
    cout << "                          ENTER THE PASSWORD :";
    cin >> rpassword;

    ofstream outputt("records.txt", ios::app);
    outputt << ruserid << ' ' << rpassword << endl;
    system("clear");

    cout << "                         REGISTRATION IS SUCCESSFULL" << endl;
    main();
}

void forgot()
{

    int option;
    system("clear");

    cout << "                            YOU FORGOT THE PASSWORD ? KOYI NA " << endl;
    cout << "                            PRESS 1 TO SEARCH YOUR ID BY USERNAME " << endl;
    cout << "                            PRESS 2 TO GO BACK TO THE MAIN MANU  " << endl;
    cout << "                            ENTER THE CHOICE :";
    cin >> option;
    system("clear");

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserid, sid, spass;
        cout << "                      ENTER THE USERNAME WHICH YOU REMEMBERSD :";
        cin >> suserid;

        ifstream outputt2("records.txt");
        while (outputt2 >> sid >> spass)
        {
            if (sid == suserid)
            {
                count = 1;
            }
        }
        outputt2.close();
        if (count == 1)
        {
            cout << "                      YOUR ACCOUNT IS FOUND " << endl;
            cout << "                      YOUR PASSWORD IS :" << spass<<endl;
            main();
        }
        else
        {
            cout << "                     SORRY !YOUR ACCOUNT IS NOT FOUND " << endl;
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }

    default:
        cout << "                        WORNG CHOICE ! PLEASE TRY AGIAN " << endl;
        forgot();
        break;
    }
}