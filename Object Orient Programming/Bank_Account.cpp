#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Bank_Account
{
    vector<string> name;
    vector<string> type;
    vector<long> bal;
    vector<long> acc_no;
    vector<long> password;
    public:
    int Open_Account();
    void Deposit(int acc , int amount);
    void Withdraw(int acc , int amount);
    int Display(int acc);
    bool Login(long User_ID , long Pass);
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
    bal.push_back(bal1);

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
            cout<<"\n\t Current Balance : "<<bal[i];
            bal[i]+=amount;
            cout<<"\n\t Updated Balance : "<<bal[i];
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
            cout<<"\n\t Current Balance : "<<bal[i];
            if(amount<=bal[i])
            {
                bal[i]-=amount;
                cout<<"\n\t Amount Withdrawn : "<<amount;
                cout<<"\n\t Updated Balance : "<<bal[i];
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
            cout << "\n\t Balance : "<< bal[i];
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
bool Bank_Account::Login(long User_ID , long Pass)
{
    for(int i=0;i<acc_no.size();i++)
    {
        if(acc_no[i]==User_ID&&password[i]==Pass)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n , acc , amt , log;
    long id , pass;
    char choice;
    Bank_Account Bank;
    Bank.Open_Account();
    cout<<"\n\t Enter User ID : ";
    cin>>id;
    cout<<"\n\t Enter Passsword : ";
    cin>>pass;
    log = Bank.Login(id , pass);
    if(log)
    {
        do
        {
            cout << "\n\t Enter 1 to Open Account ";
            cout << "\n\t Enter 2 to Deposit ";
            cout << "\n\t Enter 3 to Withdraw ";
            cout << "\n\t Enter 4 to Display ";
            cout << "\n\t Enter 5 to Logout \n\t ";
            cin>>choice;
            switch(choice)
            {
            case '1':
            {
                Bank.Open_Account();
                break;
            }
            case '2':
            {
                cout << "\n\t Enter Amount : ";
                cin >> amt;
                Bank.Deposit(id , amt);
                break;
            }
            case '3':
            {
                cout << "\n\t Enter Amount : ";
                cin >> amt;
                Bank.Withdraw(id , amt);
                break;
            }
            case '4':
            {
                Bank.Display(id);
                break;
            }
            default:
                cout << "\n\t  Logout Successful ";
                break;
            }
            cout << "\n\t Enter 1 to Continue or Any Other Key To Exit : ";
            cin >> n;
            cout << endl;
        }
        while (n==1);
    } 
    cout << endl << endl;
    return 0;
}
