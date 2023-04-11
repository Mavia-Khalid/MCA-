#include<iostream> 
using namespace std;  
class Bank_Account 
{ 
    string Name; 
    int Acc_No; 
    string Type; 
    double Bal; 
    public :  
    Bank_Account(string name , int acc_No , string acc_Type , double Balance) 
    { 
        Name = name; 
        Acc_No = acc_No; 
        Type = acc_Type; 
        Bal = Balance; 
    } 
    void Deposit(double amount) 
    { 
        cout << "\n\t Current Balance : " << Bal;
        Bal+=amount; 
        cout << "\n\t Amount of " << amount << " Has been Deposited in your Account "; 
        cout << "\n\t Updated Balance : " << Bal;
        cout << endl; 
        return ; 
    } 
    void Withdraw(double amount) 
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
  
    void Display() 
    { 
        cout << "\n\t Name : " << Name;
        cout << "\n\t Account No. : " << Acc_No;
        cout << "\n\t Type : " << Type;
        cout << "\n\t Balance : "<< Bal << endl;
    } 
};  
int main() 
{ 
    int n , acc , amount;
    char choice;
    Bank_Account Bank = Bank_Account("MAVIA KHALID" , 30434 , "SAVINGS" , 56785);
    do
    {
        cout << "\n\t Enter 1 to Deposit ";
        cout << "\n\t Enter 2 to Withdraw ";
        cout << "\n\t Enter 3 to Display ";
        cout << "\n\t Enter 4 to Exit \n\t ";
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
