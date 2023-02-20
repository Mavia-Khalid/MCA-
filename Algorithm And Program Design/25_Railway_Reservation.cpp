#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int pnr[30] = {0};
string stations[5] = {"NDLS","CNB","LKO","GD","GKP"};

class Trains
{
    private:                                // Variables Declared Here Can Only Be Accessed By Member Functions Inside Class
	int seat[30] = {0};
	string name[30];        			    // Stores Name of Ticket Holder
	string age[30];						    // Stores Age of Ticket Holder
	string coach_ac[3] = {"B1","B2","B3"};
	string coach_sl[3] = {"S1","S2","S3"};
	string source_user[30];                 // Stores Source of Ticket Holder         
	string dest_user[30];				    // Stores Destination of Ticket Holder
	int pnr[30] = {0};
	public:
	int train_no;
	string train_name;
	int ac;
	int sl;
	int source_id;
	int dest_id;
	string source;
	string dest;
	int ac_fare;
	int sl_fare;
	Trains(int no , string name , int acc , int slp , string sources , string desti , int sources_id , int desti_id) 
	// Parameterized Constructor To Initialise Objects 
	{
		train_no = no;
		train_name = name;
		ac = 1;
		sl = 1;
		source = sources;
		dest = desti;
		ac_fare = acc;
		sl_fare = slp;
		source_id = sources_id;
		dest_id = desti_id;
	}
	int available();                                       // Checks for Available Trains
	int book_window(int i, char classs , int s, int d);    // Function to Book Tickets
	void book(int i, char classs , int s , int d);         // Function to Book Tickets
	int display(int i);                                    // Function to Display Ticket Details
	void cancel(int j);                                    // Function to Cancel Ticket
	
};

int check_pnr(int pnr);
int is_available(int train_num, Trains train[]);              // Object as an Parameter
int check_available_seat_sl(int id , Trains train[]);         // Object as an Parameter
int check_available_seat_ac(int id , Trains train[]);         // Object as an Parameter
int Trains::available()             // Checks for Available Trains
{
	if(ac+sl == 0)
	{
		return 1;
	}		
	cout << "\n\n\t Train No. : " << train_no;
	cout << "\n\t Train Name : " << train_name;
	cout << "\n\t Train Source : "<< source;
	cout << "\n\t Train Destination : "<< dest;
	cout << "\n\t Seats Available In AC : " << ac << "\n\t AC Fare = " << ac_fare;
	cout << "\n\t Seats Available In Sleeper : " << sl << "\n\t Sleeper Fare = " << sl_fare;
	return 0;
}

int Trains::book_window(int i, char classs , int s, int d) // Function to Book Tickets
{
	for(int k=4; k<30; k+=4) // Loop To Search First Empty Positon to Store PNR and Details
	{
		if(pnr[k] == 0)
		{
			cout << "\n\t Enter Name : ";
			cin >> name[k];
			cout << "\t Enter Age : ";
			cin >> age[k];
			seat[k] = k+1;
			cout << "\n\t Your Seat No. is : " << seat[k]<<" WS ";
			if(classs == 'A' || classs == 'a')
			{
				cout << "\n\t Your AC Coach No. : " << coach_ac[k%3];
				pnr[k]=i*1000+(k+1);                  // PNR Encoding for AC Class
				cout << "\n\t Fare : " << ac_fare; 
				cout << "\n\t Total Amount for Ticket : " << ac_fare+((ac_fare/100)*4);
				ac--;								  // Seats Reduction From System
			}
			if(classs == 'S' || classs == 's')
			{
				cout << "\n\t Your Sleeper Coach No. : " << coach_sl[k%3];
				pnr[k] = i*1000+(k+51);                 // PNR Encoding for Sleeper Class
				cout << "\n\t Fare : " << sl_fare; 
				cout << "\n\t Total Amount for Ticket : " << sl_fare+((sl_fare/100)*4);
				sl--;                         		  // Seats Reduction From System
			}
			source_user[k] = stations[s];
			dest_user[k] = stations[d];
			cout << "\n\t Source : " << source_user[k];
			cout << "\n\t Destination : " << dest_user[k];
			cout << "\n\t Your PNR is  : " << pnr[k];
			cout << "\n\t         Ticket Booked Successfully in " << train_no << " " << train_name;
			cout << "\n\t ***************************************************************";
			cout << endl;
			return 1;
		}
	}
	return 0;
}

void Trains::book(int i, char classs , int s , int d)     // Function to Book Tickets
{
	for(int k = 0; k < 30; k++)         // Loop To Search First Empty Positon to Store PNR and Details
	{
		if(pnr[k] == 0)
		{
			cout << "\n\t Enter Name : ";
			cin >> name[k];
			cout << "\t Enter Age : ";
			cin >> age[k];
			seat[k] = k+1;
			if(k%4 == 0 && k!=0 )
			{
				cout << "\n\t Your Seat No. is : " << seat[k]<<" WS ";
			}
			else
			{
				cout << "\n\t Your Seat No. is : " << seat[k];
			}
			if(classs == 'A' || classs == 'a')
			{
				cout << "\n\t Your AC Coach No. : " << coach_ac[k%3];
				pnr[k]=i*1000+(k+1);                              // PNR Encoding for AC Class
				cout << "\n\t Fare : "<<ac_fare; 
				cout << "\n\t Total Amount for Ticket : " << ac_fare+((ac_fare/100)*4);
				ac--;                                             // Seats Reduction From System
			}
			if(classs == 'S' || classs == 's')
			{
				cout << "\n\t Your Sleeper Coach No. : " << coach_sl[k%3];
				pnr[k]=i*1000+(k+51);                             // PNR Encoding for Sleeper Class
				cout << "\n\t Fare : " << sl_fare; 
				cout << "\n\t Total Amount for Ticket : " << sl_fare+((sl_fare/100)*4);
				sl--;                                             // Seats Reduction From System
			}
			source_user[k] = stations[s];
			dest_user[k] = stations[d];
			cout << "\n\t Source : " << source_user[k];
			cout << "\n\t Destination : " << dest_user[k];
			cout << "\n\t Your PNR is  : " << pnr[k];
			cout << "\n\t         Ticket Booked Successfully in " << train_no << " " << train_name;
			cout << "\n\t ***************************************************************";
			cout << endl;
			break;
		}
	}
}

int Trains::display(int i) // Function to Display Ticket Details
{
	cout << "\n\t Train No. : "<<train_no;
	cout << "\n\t Train Name : "<<train_name;
	cout << "\n\t Name : "<<name[i];
	cout << "\n\t Age : "<<age[i];
	cout << "\n\t Source : "<<source_user[i];
	cout << "\n\t Destination : "<<dest_user[i];
	if(i%4==0 && i!=0)
	{
		cout << "\n\t Seat No. : " << seat[i]<<" WS ";
	}    
	else    
	{    
		cout << "\n\t Seat No. : " << seat[i];
	}
	if(pnr[i]%1000>50)                // PNR Decoding to Determine Class Booked
	{
		cout << "\n\t Sleeper Coach No. : " << coach_sl[i%3];
		cout << "\n\t Total Amount for Ticket : " << sl_fare+((sl_fare/100)*4);
	}
	else
	{
		cout << "\n\t AC Coach No. : " << coach_ac[i%3];
		cout << "\n\t Total Amount for Ticket : " << ac_fare+((ac_fare/100)*4);
	}
	cout << "\n\t Your PNR : " << pnr[i];
	return 0;
}

void Trains::cancel(int j) // Function to Cancel Ticket
{
	int fare;
	name[j] = "0";
	age[j] = "0";
	seat[j] = 0;
	if(pnr[j]%1000>50)               // PNR Decoding to Determine Class Booked
	{
		fare = sl_fare-100;
		cout << "\n\t PNR No. " <<pnr[j]<< " Has Been Cancelled Successfully and Refund of " <<fare<< " has been Processed After Deductions of Rs.100 as Cancellation Charge \n";
		sl++;
	}
	else
	{
		fare = ac_fare-100;
		cout << "\n\t PNR No. " <<pnr[j]<< " Has Been Cancelled Successfully and Refund of " <<fare<< " has been Processed After Deductions of Rs.100 as Cancellation Charge \n";
		ac++;
	}
	pnr[j] = 0;
}

int main()
{
	char choice, choice1, ch, pref, clas;
	int count, return_id, train_num, source, dest, id, id_1, id_2, i, j, pnr1;
	cout << "\n\n";
	cout << "\t     ******************************************************\n";
	cout << "\t              Welcome to Railway Reservation System \n";
	cout << "\t     ******************************************************\n";
	Trains train[] = { Trains(12596,"Humsafar",1000,400,"NDLS","LKO",0,2) , Trains(12531,"Intercity",600,200,"LKO","GKP",2,4) , Trains(12555,"Express",800,300,"NDLS","GKP",0,4)};
	do
	{
        level1:
		cout << "\n\t Choose an Option : \n";
		cout << "\n\t 1 to View Avaiable Trains ";
		cout << "\n\t 2 to Book ";
		cout << "\n\t 3 to View Ticket Details ";
		cout << "\n\t 4 to Cancel ";
		cout << "\n\t 5 to Exit ";
		cout << "\n\n\t Enter Your Choice : ";
		cin >> choice;
		if(choice < '1' || choice > '5')
		{
			cout << "\n\t Wrong Choice , Try Again \n";
			goto level1;
		}
		switch(choice)
		{
			case '1':
				cout << "\n\t     ******************************************************\n";
				cout << "\t                       Available Trains \n";
				cout << "\t     ******************************************************\n";
				count = 0;
				for(i=0; i<3; i++) // Loop To Display Available Trains
				{
					return_id = train[i].available();
					if(return_id == 1 )
					{
						count++;
					}
				}
                if(count == 3)
                {
                cout << "\n\n";
				cout << "\n\t     ******************************************************\n";
				cout << "\t                       No Trains Available \n";
				cout << "\t     ******************************************************\n";
                }  
				cout << "\n\n";
				cout << "\n\t     ******************************************************\n";
				cout << "\t                          Section Ends \n";
				cout << "\t     ******************************************************\n";
				break;
			case '2':
				cout << "\n\t     ******************************************************\n";
				cout << "\t                       Booking Section \n";
				cout << "\t     ******************************************************\n";
				level2:
				id_2 = 0;
				cout << "\n\t Enter Train No. : ";
				cin >> train_num;
				id = is_available(train_num , train);
				// Function call to check Train No. Exists or not by Passing Object as Argument
				if(id)
				{
					cout<<"\n\t Enter Class A/a for AC or S/s For Sleeper : ";
					cin>>clas;
					id=id-1;
					if(clas == 'A' || clas == 'a')    // Condition To Check Entered Class
					{
						id_1 = check_available_seat_ac(id , train);     // Function call to check Available Seats          
					}
					else if(clas == 'S'||clas == 's')
					{
						id_1 = check_available_seat_sl(id , train);     // Function call to check Available Seats  
					}
					else
					{
						cout << "\n\t Wrong Class Entered ";
						id_1 = 0;
					}
				}
				if(id_1 == 1)
				{
					for(int k=train[id].source_id; k<=train[id].dest_id; k++)
						{
							cout << "\n\t Enter "<<(k+1)<<" for " << stations[k];
						}
						cout << "\n\t Enter Source : ";
						cin >> source;
						cout << "\n\t Enter Destination : ";
						cin >> dest;
						if((source-1) >= train[id].source_id && (dest-1) <= train[id].dest_id && source < dest)
						// Condition Matches Source And Destination with Chosen Train
						{
							cout << "\n\t Enter 1 For Window Seat or Any Key For No Preference : ";
							cin >> pref;
							if(pref == '1')
							{
								id_2 = train[id].book_window(id+1 , clas , (source-1) , (dest-1));    
								// Function call To Book Window Seat Ticket
							}
							if(id_2 == 0||pref!='1')    // Condition to book if no Preference CHosen or If Window not Available
							{
								train[id].book(id+1 , clas ,  (source-1) , (dest-1));      
								// Function call To Book Ticket
							}    			
						}
						else
						{
							cout << "\n\t Wrong Source or Destination ";
						}
				}
				cout << endl;
				cout << "\n\t Enter 1 to Book Again or Enter Exit Booking Section ";
				cin >> choice1;
				if(choice1 == '1')
				{
					goto level2;
				}
				cout << "\n\t     ******************************************************\n";
				cout << "\t                       Booking Section Ends \n";
				cout << "\t     ******************************************************\n";
				break;
			case '3':
				level4:
				cout << "\n\t     ******************************************************\n";
				cout << "\t                       View Tickets Details \n";
				cout << "\t     ******************************************************\n";
				cout << "\n\t Enter PNR : ";
				cin >> pnr1;
				j = check_pnr(pnr1);     // Checking if PNR Exists 
				if(j)
				{
					j = j-1;                  // Tells The Index Of All Data Stored
					i = (pnr1/1000)-1;        // Decoding PNR To Find Train No.
					train[i].display(j);           // Function Call to Display Ticket Details
				}
				cout << "\n\n\t Enter 1 to View Again or Any Key Exit Viewing Section : ";
				cin >> choice1;
				if(choice1 == '1')
				{
					goto level4;
				}			
				cout << "\n\t     ******************************************************\n";
				cout << "\t                            Section Ends \n";
				cout << "\t     ******************************************************\n";
				break;
			case '4':
				cout << "\n\t     ******************************************************\n";
				cout << "\t                       Cancellation Section \n";
				cout << "\t     ******************************************************\n";
				level6:
				cout << "\n\t Enter PNR to Cancel Booking : ";
				cin >> pnr1;
				j = check_pnr(pnr1); // Checking if PNR Exists 
				if(j)
				{
					j = j-1;
					i = (pnr1/1000)-1;
					train[i].display(j);           // Function Call to Display Ticket Details
					train[i].cancel(j); 		   // Function Call to Cancel Ticket
				}
				cout << "\n\t Enter 1 to Go Back to Cancellation Section or Any Key to Goto Main Menu ";
				cin>>choice1;
				if(choice1 == '1')
				{
					goto level6;
				}
				cout << "\n\t     ******************************************************\n";
				cout << "\t                            Section Ends \n";
				cout << "\t     ******************************************************\n";
				break;
			case '5':
				break;
			default:
				break;
		}
		cout << "\n\t Enter Any Key to go to Main Menu or 0 to Exit : ";
		cin>>ch;
	}
	while(ch != '0');
	
	cout << "\n\n\n";
	system("pause");
	return 0;
}
int check_pnr(int pnr_user)
{
	for(int i=0; i<30; i++)           // Loop To Check If Entered PNR Exist or Not
		{
			if(pnr_user == pnr[i])
			{
				return i+1;
			}
		}
	cout << "\n\t PNR Does Not Exist ";
	return 0;
}
int is_available(int train_num, Trains train[])
{
	for(int i=0; i<3; i++)                // Loop to Iterate According to No. of Trains in The System
		{
			if(train_num == train[i].train_no)      // Condition Checks if Entered Train No. Exists or Not
			{
				return i+1;
			}
		}
	cout << "\n\t Wrong Train No. ";
	return 0;
}
int check_available_seat_ac(int id , Trains train[])
{
	if(train[id].ac != 0)
	{
		return 1;
	}
	else
	{
		cout << "\n\t AC Seats Are Full in " << train[id].train_name;
		cout << endl;
		return 0;
	}
}
int check_available_seat_sl(int id , Trains train[])
{
	if(train[id].sl != 0)
	{
		return 1;
	}
	else
	{
		cout << "\n\t Sleeper Seats Are Full in " << train[id].train_name;
		cout << endl;
		return 0;
	}
}
	
