#include<iostream> 
using namespace std;  
class Bank_Account 
{ 
    string Name; 
    int Acc_No; 
    string Type; 
    double Bal; 
    long Password;
    int user_id;
    public :  
    Bank_Account(string name , int acc_No , string acc_Type , double Balance  , int id , long Pass ) 
    { 
        Name = name; 
        Acc_No = acc_No; 
        Type = acc_Type; 
        Bal = Balance; 
        Password = Pass;
        user_id = id;
    } 
    void Withdraw(double amount);
    void Display(); 
    void Deposit(double amount);
    bool UserLogin(long User_ID , long Pass);
}; 
void Bank_Account::Deposit(double amount) 
{ 
    cout << "\n\t Current Balance : " << Bal;
    Bal+=amount; 
    cout << "\n\t Amount of " << amount << " Has been Deposited in your Account "; 
    cout << "\n\t Updated Balance : " << Bal;
    cout << endl; 
    return ; 
} 
void Bank_Account::Withdraw(double amount) 
{ 
    if(Bal-amount>=5000) 
    { 
        cout << "\n\t Current Balance : " << Bal;
        Bal-=amount; 
        cout<<"\n\t Amount of " << amount << " has been Debited from your Account "; 
        cout << "\n\t Updated Balance : " << Bal;
        cout << endl;   
    } 
    else 
    { 
        cout << "\n\t Amount is not sufficient "; 
        cout << "\n\t Max amount That can be withdrawn is : " << Bal-5000; 
    }  
} 

void Bank_Account::Display() 
{ 
    cout << "\n\t Name : " << Name;
    cout << "\n\t Account No. : " << Acc_No;
    cout << "\n\t Type : " << Type;
    cout << "\n\t Balance : "<< Bal << endl;
}  
bool Bank_Account::UserLogin(long ID , long Pass)
{
    if(user_id == ID && Password == Pass)
    {
        return true;
    }
    return false;
}
int main() 
{ 
    int n , amount , id , pass , count = 0;
    char choice;
    bool login;
    Bank_Account Bank = Bank_Account("MAVIA KHALID" , 30434 , "SAVINGS" , 56785 , 23456 , 54321);
    label:
    cout << "\n\t Enter User ID : ";
    cin >> id;
    cout << "\n\t Enter PAssword : ";
    cin >> pass;
    login = Bank.UserLogin(id , pass);
    if(login)
    {
        do
        {
            cout << "\n\t Enter 1 to Deposit ";
            cout << "\n\t Enter 2 to Withdraw ";
            cout << "\n\t Enter 3 to Display ";
            cout << "\n\t Enter 4 to Logout \n\t ";
            cin>>choice;
            switch(choice)
            {
            case '1':
            {
                cout << "\n\t Enter Amount : ";
                cin >> amount;
                Bank.Deposit(amount);
                break;
            }
            case '2':
            {
                cout << "\n\t Enter Amount : ";
                cin >> amount;
                Bank.Withdraw(amount);
                break;
            }
            case '3':
            {
                Bank.Display();
                break;
            }
            default:
                break;
            }
            cout << "\n\t Enter 1 to Continue or Any Other Key To Exit : ";
            cin >> n;
            cout << endl;
        }
        while (n == 1);
    }
    else
    {
        cout << "\n\t Wrong Password ";
        count++;
        if(count == 3)
        {
            cout << "\n\t Too Many Attempts to Login ";
            return 0;
        }
        goto label;
    }
} 
