#include<bits/stdc++.h>
#include<conio.h>
#include <ctime>
#include <random>
#include<windows.h>
#define num_of_vaccine 1000
using namespace std;


int password();
void menu();
void show();



class vaccine
{
    int age;
    int temperature;
    int blood_pressure;
    char gender;
    string name;
    string NID;
    string profession;
    string address;
    string mobile_number;
    int dt,mo,ye;
public:
    void search_data();
    void add_new();
    void setdata();
    void view_vaccine();
    void showdata();
    void search_by_NID();
    void search_by_age();
    void search_by_profession();
    void search_by_gender();
    void search_by_blood_pressure();
    void show_list();
};
void show()
{
    cout<<setw(20)<<setiosflags(ios::left)<<"Name ";
    cout<<setw(20)<<"NID No.";
    cout<<setw(10)<<"Age";
    cout<<setw(18)<<"Profession";
    cout<<setw(8)<<"B.P.";
    cout<<setw(15)<<"Temperature";
    cout<<setw(7)<<"gender";
    cout<<setw(15)<<"Mobile No.";
    cout<<setw(10)<<"Address";
    cout<<setw(12)<<"Fast Doge";
    cout<<setw(12)<<"Next Doge"<<endl;
}
void vaccine ::view_vaccine()
{
    ifstream ind;
    int i=0;
    ind.open("vaccinetrial.txt");
    ind.seekg(0,ios::beg);
    while(ind.read((char*)this,sizeof(vaccine)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s=num_of_vaccine-i;
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\tVACCINE STATISTICS";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"\t\t 1. Add more        \t\t\t2.View available \n\t\t\t\t\t 3. Back"<<endl;
    cin>>ch;
    int add_vec=0;
    fstream file("count.txt");
    file>>add_vec;
    switch(ch)
    {
    case 1:
        int m;
        cout<<"\t Enter number of vaccines you want to add "<<endl;
        cin>>m;
        add_vec=add_vec+m;
        file.seekg(0,ios::beg);
        file<<add_vec;
        cout<<"\t\t Now total number of vaccines are : "<<add_vec+s;
        break;
    case 2:
        cout<<"\n\nAvailable number of vaccines are "<<s+add_vec;
        break;
    case 3:
        system("cls");
        menu();
    default:
        system("cls");
        cout<<"\nEnter valid option "<<endl;
        menu();
    }
    file.close();
    getch();
}
void vaccine::show_list()
{
    cout<<"\n";
    cout<<setw(20)<<setiosflags(ios::left)<<name;
    cout<<setw(20)<<NID;
    cout<<setw(10)<<age;
    cout<<setw(18)<<profession;
    cout<<setw(8)<<blood_pressure;
    cout<<setw(15)<<temperature;
    cout<<setw(7)<<gender;
    cout<<setw(15)<<mobile_number;
    cout<<setw(10)<<address;
    cout<<dt<<'/'<<mo<<'/'<<ye;
    cout<<"\t"<<dt<<'/'<<mo+1<<'/'<<ye<<endl;
}
void vaccine::search_data()
{
    vaccine item;
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\tSEARCHING STATISTICS";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"From which option you want to perform searching "<<endl;
    cout<<"\n\t\t 1. By NID \t\t\t 2. By Age "<<endl;
    cout<<"\n\t\t 3. By profession \t\t 4. By gender "<<endl;
    cout<<"\n\t\t 5. By Blood Pressure"<<endl;
    cout<<"\n\n\t\tEnter your choice ...............";
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        search_by_NID();
        getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        getch();
        break;
    case 3:
        system("cls");
        search_by_profession();
        getch();
        break;
    case 4:
        system("cls");
        search_by_gender();
        getch();
        break;
    case 5:
        system("cls");
        search_by_blood_pressure();
        getch();
        break;
    default:
        system("cls");
        cout<<"ENTER VALID OPTION"<<endl;
        menu();
    }
}
void vaccine::search_by_NID()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    string nid_num;
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t NID NUMBER SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter your NID number "<<endl;
    fflush(stdin);
    getline(cin,nid_num);
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(nid_num.compare(NID)==0)
        {
            showdata();
            flag=1;
            break;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"NID number not found "<<endl;
    }
    in.close();
}
void vaccine::search_by_age()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    int a,p=0;
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t AGE SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"enter Age by which you want to search "<<endl;
    cin>>a;
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(a==age)
        {
            show_list();
            flag=1;
            p++;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"Age you entered is not found"<<endl;
    }
    cout<<"\n\n\n\nNO of people vaccinated  by this age "<<p;
    in.close();

}
void vaccine::search_by_profession()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    int p=0;
    string prof;
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t PROFESSION SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"enter Profession by which you want to search "<<endl;
    fflush(stdin);
    getline(cin,prof);
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(prof.compare(profession)==0)
        {
            show_list();
            flag=1;
            p++;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"The profession you have Enter does not exist"<<endl;
    }
    cout<<"\n\n\n NO of people vaccinated by this profession "<<p<<endl;
    in.close();
}
void vaccine::search_by_gender()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    char g;
    int p=0;
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t GENDER SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter gender by which you want to search "<<endl;
    cin>>g;
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(toupper(g)==toupper(gender))
        {
            show_list();
            flag=1;
            p++;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"The gender you entered does not exist "<<endl;
    }
    cout<<"\n\n\n NO. of people vaccinated by this gender "<<p<<endl;
    in.close();
}

void vaccine::search_by_blood_pressure()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    int b,p=0;
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t Blood Pressure SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"enter Blood Pressure by which you want to search "<<endl;
    cin>>b;
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(b==blood_pressure)
        {
            show_list();
            flag=1;
            p++;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"Blood Pressure you entered is not found"<<endl;
    }
    cout<<"\n\n\n\nNO of people vaccinated  by this Blood Pressure "<<p;
    in.close();

}

void vaccine::setdata()
{
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t VACCINE TAKER INFORMATION ";
    cout<<"\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cout<<"\n\t\t Enter your name :-  ";
    getline(cin,name);
    cout<<"\n\t\t Enter your NID :-  ";
    getline(cin,NID);
    cout<<"\n\t\t Enter your gender (M|F) :-  ";
    cin>>gender;
    cout<<"\n\t\t Enter your age:- ";
    cin>>age;
    fflush(stdin);
    cout<<"\n\t\t Enter your profession :-  ";
    getline(cin,profession);
    cout<<"\n\t\t Enter your B.P. :-  ";
    cin>>blood_pressure;
    cout<<"\n\t\t Enter your Body temperature:-  ";
    cin>>temperature;
    fflush(stdin);
    cout<<"\n\t\t Enter your permanent address :-  ";
    getline(cin,address);
    cout<<"\n\t\t Enter your Mobile number :- ";
    getline(cin,mobile_number);
    cout<<"\n\t\t Enter Vaccine Taken Date :- ";
    cin>>dt>>mo>>ye;
}
void vaccine::showdata()
{
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t DETAILS  ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"\t\t Name is: "<<name<<endl;
    cout<<"\t\t NID number is: "<<NID<<endl;
    cout<<"\t\t Your age is "<<age<<endl;
    cout<<"\t\t Profession is : "<<profession<<endl;
    cout<<"\t\t Gender is : "<<gender<<endl;
    cout<<"\t\t Blood pressure is :"<<blood_pressure<<endl;
    cout<<"\t\t Body temperature is : "<<temperature<<endl;
    cout<<"\t\t Address is "<<address<<endl;
    cout<<"\t\t Mobile number is: "<<mobile_number<<endl;
    cout<<"\t\t Fast Doge Taken: "<<dt<<'/'<<mo<<'/'<<ye<<endl;
    cout<<"\t\t Next Doge Date: "<<dt<<'/'<<mo+1<<'/'<<ye<<endl;
}
void vaccine::add_new()
{
    fstream outin;
    outin.open("vaccinetrial.txt",ios::app|ios::in);
    setdata();
    outin.write((char*)this,sizeof(vaccine));
    cout<<"YOUR DATA HAS BEEN SUCCESSFULLY INSERTED "<<endl;
    getch();
    outin.close();
}

void menu()
{
    system("cls");
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\tPowered By:- Team ERROR "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t\tMENU";
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\n\t\t1: Add NEW Record\t\t\t 2: View VACCINE DATA"<<endl;
    cout<<"\n\t\t3: search   \t\t\t\t 4: Play Games"<<endl;
    cout<<"\n\t\t5: Exit"<<endl;
}


class tic_tac
{
public:
    void gamesview();
    char board[9] = {' ', ' ',' ',' ',' ',' ',' ',' ',' '};
    void show_board();
    void get_x_player_choice();
    void get_o_player_choice();
    void get_computer_choice();
    int count_board(char symbol);
    char check_winner();
    void computer_vs_player();
    void player_vs_player();
    void instructions();
};
void tic_tac::gamesview()
{
    system("Color 02");
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t Loading ";
    char x = 219;
    for(int i = 0; i<=35; i++)
    {
        cout << x;
        if(i<10)
            Sleep(300);
        if(i>=10 && i<20)
            Sleep(150);
        if(i>=10)
            Sleep(25);
    }

    // check mode == -1 for first time run and skip wait for next key
    // else wait for next key so that it can show win result.
    int mode=-1;
    do
    {
        if(mode!=-1)
        {
            cout << "Enter any key to continue";
            getche();
        }
        system("cls");
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\tHi! Welcome To Tic-Tac-Toe Game.\n " << endl;
        cout<<"\t\t\t\t\t\tPowered By:- Team ERROR \n\n"<<endl;

        cout << "\t\t\t\t\t1. Computer VS Player." << endl;
        cout << "\t\t\t\t\t2. Player VS Player." << endl;
        cout << "\t\t\t\t\t3. Instructions." << endl;
        cout << "\t\t\t\t\t4. Quit." << endl;
        cout << "\t\t\t\t\tSelect Game Mode.==>";

        // for each time board array should be clear.
        for(int k=0; k<9; k++)
            board[k] = ' ';
        mode = getche();

        if( mode=='1')
            computer_vs_player();
        else if( mode=='2')
            player_vs_player();
        else if( mode=='3')
            instructions();
        else if( mode=='4')
            exit(0);
    }
    while (1);
}
void tic_tac::computer_vs_player()
{
    string player_name;
    cout << "\n\n\n\t\t\t\t\tEnter Your Name: ";
    cin >> player_name;
    while(true) {
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << player_name << "'s Turn." << endl;
            get_x_player_choice();
        }
        else{
            get_computer_choice();
        }
        char winner = check_winner();
        if(winner == 'X') {
            system("cls");
            show_board();
            cout << player_name << " Won The Game.Congratulations!!!" << endl;
            break;
        }
        else if(winner == 'O') {
            system("cls");
            show_board();
            cout << "Computer Won The Game." << endl;
            break;
        }
        else if(winner == 'D') {
            cout << "Game is Draw....!" << endl;
            break;
        }
    }
}

void tic_tac::get_computer_choice()
{
   srand(time(0));
    int choice;
    do{
        choice = rand()%10;
    }while(board[choice] !=  ' ');
    board[choice] = 'O';
}

void tic_tac::get_x_player_choice()
{
    while(true) {
        cout << "Select Your Position (1 - 9): " ;
        int choice;
        cin >> choice;
        choice--;
        if(choice < 0 || choice > 8) {
            cout << "Please Select Your Choice From (1 - 9)." << endl;
        }
        else if(board[choice] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice] = 'X';
            break;
        }
    }
}

void tic_tac::get_o_player_choice()
{
    while(true) {
        cout << "Select Your Position (1 - 9): " ;
        int choice;
        cin >> choice;
        choice--;
        if(choice < 0 || choice > 8) {
            cout << "Please Select Your Choice From (1 - 9)." << endl;
        }
        else if(board[choice] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice] = 'O';
            break;
        }
    }
}

void tic_tac::player_vs_player()
{
    string x_player_name , o_player_name;
    cout << "\n\n\n\t\t\t\t\tEnter X Player Name: " ;
    cin >> x_player_name;
    cout << "\n\n\n\t\t\t\t\tEnter O Player Name: " ;
    cin >> o_player_name;
    while(true) {
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << x_player_name << "'s Turn." << endl;
            get_x_player_choice();
        }
        else{
            cout << o_player_name << "'s Turn." << endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if(winner == 'X') {
            system("cls");
            show_board();
            cout << x_player_name << " Won The Game.Congratulations!!!" << endl;
            break;
        }
        else if(winner == 'O') {
            system("cls");
            show_board();
            cout << o_player_name << " Won The Game.Congratulations!!!" << endl;
            break;
        }
        else if(winner == 'D') {
            cout << "Game is Draw....!" << endl;
            break;
        }
    }
}

void tic_tac::instructions()
{
    system("cls");
        cout << " Instructions";
        cout << "\n----------------";
        cout << "\n Tic-tac-toe is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3x3 grid. \n The player who succeeds in placing three of their marks in a diagonal, horizontal, or vertical row is the winner. \n It is a solved game with a forced draw assuming the best play from both players.";
        cout << "\n\n \n Strategy:";
        cout << "\n \n 1. In tic-tac-toe, the first player to draw three symbols in a row wins.  ";
	    cout << "\n 2. The best move is to move into the center to maximize your chances of winning. Keep alternating moves until \none of the players has drawn a row of three symbols or until no one can win.";
	    cout << "\n 3. If both players are playing with optimal strategy, then there's a good chance that no one will win because \nyou will have blocked all of each other's opportunities to create a row of three.";
	    cout << "\n 4. If you're going first, then the best move to make the most out of the game is to go into the middle.";
	    cout << "\n\nPress any key to go back to menu";
        getch();
}

int tic_tac::count_board(char symbol)
{
    int total = 0;
    for(int i=0; i<9; i++) {
        if(board[i] == symbol)
            total += 1;
    }
    return total;
}

char tic_tac::check_winner()
{
    // checking winner in horizontal/row
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    // checking winner in vertical/column
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    // checking winner in diagonal
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    if(count_board('X') + count_board('O') < 9)
        return 'C';
    else
        return 'D';
}

void tic_tac::show_board()
{
    cout <<"\n\n\tTic-Tac-Toe\n\n"<< endl;
    cout << "\t   " << "   |   " << "   |   " << endl;
    cout << "\t   " << board[0] << "  |   " << board[1] << "  |   " << board[2] << endl;
    cout << "\t   " << "   |   " << "   |   " << endl;
    cout << "\t------+------+------" << endl;
    cout << "\t   " << "   |   " << "   |   " << endl;
    cout << "\t   " << board[3] << "  |   " << board[4] << "  |   " << board[5] << endl;
    cout << "\t   " << "   |   " << "   |   " << endl;
    cout << "\t------+------+------" << endl;
    cout << "\t   " << "   |   " << "   |   " << endl;
    cout << "\t   " << board[6] << "  |   " << board[7] << "  |   " << board[8] << endl;
    cout << "\t   " << "   |   " << "   |   " << endl;
}


int main()
{   tic_tac.show_board();
    vaccine obj;
    tic_tac games;
    int k=3;
    int num_vac;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t Powered By:- Team ERROR "<<endl;
    cout<<"\t\n\n Press any key to continue.............  "<<endl;
    getch();
B:
    system("cls");
    cout<<"\n\n\t\t\t\t*********************************************";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t*********************************************\n";
    while(k>=1)
    {
        int c = password();
        if(c==1)
            break;
        else
            cout<<"\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only "<<k-1<<" times more";
        k--;
        if(k<1)
        {
            for(int i=59; i>=0; i--)
            {
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
                cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
                Sleep(1000);
            }
            k=3;
            goto B;
        }
    }
    int ch;
    do
    {
        cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 CORONA VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
        cout<<"\t\t\t\t\t\t Powered By:- Team ERROR "<<endl;
        menu();
        cout<<"\n\t\n\tChoose according to your need : ";
        cin>>ch;
        vaccine v1;
        switch(ch)
        {
        case 1:
            system("cls");
            obj.add_new();
            break;
        case 2:
            system("cls");
            obj.view_vaccine();
            break;
        case 3:
            system("cls");
            obj.search_data();
            break;
        case 4:
            system("cls");
            games.gamesview();
            break;
        case 5:
            system("cls");
            exit(0);
        default:
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
            cout<<"\n\n\t\t\t\t\t****HAVE A NICE DAY*****";
            Sleep(3000);
            exit(0);
        }
    }
    while(ch!=0);

    return 0;
}
int password()
{
    char uname[30],pass[20];
    int ch, i=0,cap=0,capt=0;
    cout<<"\n\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(uname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    while((ch=getch()) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap=rand();
    cout<<"\n\t\t\t\t\t CAPTURE:->  "<<cap<<endl;
    cout<<" Please enter the valid capture :-   ";
    cin>>capt;
    if( (strcmp(uname,"teamerror")==0) && (strcmp(pass,"1234")==0) && cap==capt)
        return 1;
    else
        return 0;
}

