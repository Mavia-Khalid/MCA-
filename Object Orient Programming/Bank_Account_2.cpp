#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Bank_Account
{
    long bal;
    string name1;
    string type1;
    vector<string> name;
    vector<string> type;
    vector<long> balance;
    vector<long> acc_no;
    vector<long> password;
    int Admin_ID  = 1234;
    int Admin_Pass = 2345;
    public:  
    int Open_Account();
    void Deposit(int acc , int amount);
    void Withdraw(int acc , int amount);
    int Display(int acc);
    bool UserLogin(long User_ID , long Pass);
    bool AdminLogin(long User_ID , long Pass);
    void AdminPanel();
};
int Bank_Account::Open_Account()
{
    string name1;
    string type1;
    long bal1;
    long password1;
    cout<<"\n\t Enter Name : ";
    cin>>name1;
    transform(name1.begin() , name1.end() , name1.begin(), :: toupper);
    cout<<"\n\t Enter Type : ";
    cin>>type1;
    transform(type1.begin() , type1.end() , type1.begin(), :: toupper);
    cout<<"\n\t Enter Amount : ";
    cin>>bal1;
    if(bal1<1000)
    {
        cout<<"\n\t Amount Not Sufficient ";
        return 0;
    }

    name.push_back(name1);
    type.push_back(type1);
    balance.push_back(bal1);

    int i=name.size()+10;
    password1=i*564312;

    password.push_back(password1);
    acc_no.push_back(78453*i);

    Display(78453*i);
    cout<<endl;
    return 0;
}
void Bank_Account::Deposit(int acc , int amount)
{
    for(int i=0;i<acc_no.size();i++)
    {
        if(acc_no[i]==acc)
        {
            cout<<"\n\t Current Balance : "<<balance[i];
            balance[i]+=amount;
            cout<<"\n\t Updated Balance : "<<balance[i];
            cout<<endl;
            return;
        }
    }
    cout<<"\n\t Account Does Not Exist ";
    cout<<endl;
}
void Bank_Account::Withdraw(int acc , int amount)
{
    for(int i=0;i<acc_no.size();i++)
    {
        if(acc_no[i]==acc)
        {
            cout<<"\n\t Current Balance : "<<balance[i];
            if(amount<=balance[i])
            {
                balance[i]-=amount;
                cout<<"\n\t Amount Withdrawn : "<<amount;
                cout<<"\n\t Updated Balance : "<<balance[i];
                cout<<endl;
                return;
            }
            cout<<"\n\t Not Enough Balance ";
            cout<<endl;
            return;
        }
    }
    cout<<"\n\t Account Does Not Exist ";
    cout<<endl;
}
int Bank_Account::Display(int acc)
{
    for(int i=0;i<acc_no.size();i++)
    {
        if(acc_no[i]==acc)
        {
            cout << "\n\t Name : " << name[i];
            cout << "\n\t Account No. : " << acc_no[i];
            cout << "\n\t Type : " << type[i];
            cout << "\n\t Balance : "<< balance[i];
            cout << "\n\t User ID : " << acc_no[i];
            cout << "\n\t Password : " << password[i];
            cout<<endl;
            return 0;
        }
    }
    cout<<"\n\t Account Number Does Not Exist "; 
    cout<<endl;  
    return 0;
}
bool Bank_Account::UserLogin(long User_ID , long Pass)
{
    for(int i=0;i<acc_no.size();i++)
    {
        if(acc_no[i] == User_ID && password[i] == Pass)
        {
            return true;
        }
    }
    return false;
}
bool Bank_Account::AdminLogin(long User_ID , long Pass)
{
    if(User_ID == Admin_ID && Pass == Admin_Pass)
    {
        return true;
    }
    return false;
}
void Bank_Account::AdminPanel()
{
    cout << "\n\t Name " << " Account No. " << " Type " << " Balance " << " User ID " << " Password " << endl;
    for(int i=0; i<name.size(); i++)
    {
        cout<<"\n\t " << name[i] << " " << acc_no[i] << "     " << type[i] << "  " << balance[i] << "   " << acc_no[i] << "    " << password[i];
    }
}
void UserPanel(int id , Bank_Account &Bank)
{
    int amt;
    char choice , n;
    do
    {
        cout << "\n\t Enter 1 to Deposit ";
        cout << "\n\t Enter 2 to Withdraw ";
        cout << "\n\t Enter 3 to Display ";
        cout << "\n\t Enter 4 to Logout \n\t ";
        cin >> choice;
        switch(choice)
        {
            case '1':
            {
                cout << "\n\t Enter Amount : ";
                cin >> amt;
                Bank.Deposit(id , amt);
                break;
            }
            case '2':
            {
                cout << "\n\t Enter Amount : ";
                cin >> amt;
                Bank.Withdraw(id , amt);
                break;
            }
            case '3':
            {
                Bank.Display(id);
                break;
            }
            default:
                cout << "\n\t  Logout Successful ";
                return;
        }
        cout << "\n\t Enter 1 to Continue or Any Other Key To Exit : ";
        cin >> n;
        cout << endl;
    }
    while (n == '1');

}
int main()
{
    bool log;
    char  n;
    long id , pass;
    char choice;
    Bank_Account Bank;
    do
    {
        cout << "\n\t Enter 1 to Open Account ";
        cout << "\n\t Enter 2 to Admin Login ";
        cout << "\n\t Enter 3 to User Login ";
        cin >> choice;
        switch(choice)
        { 
            case '1':
            {
                Bank.Open_Account();
                break;
            }
            case '2':
            {
                cout << "\n\t Enter Admin ID : ";
                cin >> id;
                cout << "\n\t Enter Passsword : ";
                cin>>pass;
                log = Bank.AdminLogin(id , pass);
                if(log)
                {
                    Bank.AdminPanel();
                }
                break;
            }
            case '3':
            {
                cout << "\n\t Enter User ID : ";
                cin >> id;
                cout << "\n\t Enter Passsword : ";
                cin>>pass;
                log = Bank.UserLogin(id , pass);
                if(log)
                {
                    UserPanel(id , Bank);
                }
                else
                {
                    cout << "\n\t Wrong ID or Password ";
                }
                break;
            }
            default:
                break; 
        }
        cout << "\n\t Enter 1 to Go to Menu or 0 to Exit : ";
        cin >> n;
    }
    while(n == '1');
    cout << endl << endl;
    return 0;
}
