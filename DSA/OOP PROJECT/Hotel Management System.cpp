#include<iostream>
#include<conio.h>				//CONSOLE INPUT OUTPUT
#include<fstream>				//FILEHANDLING
#include<string>				//FOR USING STRING
#include<sstream>				//STRINGSTREAM FOR SEPARATING STRING LINE
using namespace std;

class HotelManagementSystem		//INTERFACE FOR SHOW TO CLIENTS 
{
public:

	virtual void mainMenu() = 0;
	virtual void add() = 0;
	virtual void display() = 0;
	virtual void rooms() = 0;
	virtual int check(int) = 0;
	virtual void edit() = 0;
	virtual void delete_rec(int) = 0;
	virtual void bill() = 0;
};

class Hotel :public HotelManagementSystem
{

private:

	int RoomNo;
	string name;
	string address;
	int phone;

public:
	Hotel()														 //CONSTRUCTOR
	{
		RoomNo = 0;
		name = " ";
		address = " ";
		phone = 0;
	}
	int check(int rn)											//FOR CHECKING THE AVAILIBILITY OF ROOM
	{

		int flag = 0;

		ifstream fin("record.txt");								//FILE OPENING IN READ ONLY MODE

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[4];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ','))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			RoomNo = stoi(str_arr[0]);							//TURNING STRING TO INTEGER
			name = str_arr[1];
			address = str_arr[2];
			phone = stoi(str_arr[3]);
			if (RoomNo == rn)
			{
				flag = 1;
				break;

			}
		}

		fin.close();
		return flag;

	}
	void add()													//FOR GETTING & WRITING THE DATA
	{
		system("cls");		
		int rn, flag;
		ofstream fout("record.txt", ios::app);					//OPENING FILE IN WRTIE MODE WITH APPEND FUCNTIONALITY

		cout << endl << " <--------------Customer Detalis-------------->" << endl;
		cout << endl << " Total no. of Rooms are 50";
		cout << endl << " Economy Rooms from 1 to 20";
		cout << endl << " Double Beds Rooms from 21 to 45";
		cout << endl << " Luxuary Rooms from 46 to 50";
		cout << endl << " Please enter the Room no you want to stay in: " << endl;
		cin >> rn;

		flag = check(rn);										//CHECKING IF THE ROOM IS ALREADY BOOKED OR NOT

		if (flag==1)
		{
			cout << endl << "This Room is already booked, You can choice from other rooms.";
		}
		else if(rn < 51)										//LIMITING ROOM NO TO MAX 50 ONLY
		{

			RoomNo = rn;
			cout << " Name: ";
			getline(cin, name);
			getline(cin, name);
			cout << " Address: ";
			getline(cin, address);
			cout << " Phone No: ";
			cin >> phone;

			fout << RoomNo << "," << name << "," << address << "," << phone << "\n"; //WRITING THE DATA INTO THE FILE
			cout << endl << "Your Room is booked!";

		}
		else
		{
			cout << "Please enter a valid room no....!";
		}

		cout << endl << endl << endl << "Press any key to continue!";

		_getch();											//HOLDS THE SCREEN UNTIL ANY KEY IS PRESSED
		fout.close();
	}
	void display()											//DISPLAYS SPECIFIC DATA OF THE ROOM ENTERED
	{

		system("cls");

		ifstream fin("record.txt");
		int rn, flag = 0;

		cout << endl << "Please enter the customer's Room No. which you want to check: ";
		cin >> rn;
		string line;
		while (!fin.eof())
		{
			getline(fin, line);							     //GETTING COMPLETE LINE FROM THE FILE
			string str_arr[4];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ','))				//SEPARATING LINE ON THE BASES OF COMMA
			{
				str_arr[i] = sngl_word;
				i++;
			}
			RoomNo = stoi(str_arr[0]);						//TURNING STRING TO INTEGER
			name = str_arr[1];
			address = str_arr[2];
			phone = stoi(str_arr[3]);
			if (RoomNo == rn)
			{

				system("cls");
				cout << "<--------------Customer Detalis-------------->";
				cout << endl << endl << " Room no: " << RoomNo;
				cout << endl << " Name: " << name;
				cout << endl << " Address: " << address;
				cout << endl << " Phone no: " << phone;
				flag = 1;
				break;

			}

		}

		if (flag == 0)									//FLAG IS ZERO IF THE ROOMNO IS NOT FOUND IN FILE
		{
			cout << endl << "No records found! The selected Room is available for Booking!";
		}
		cout << endl << endl << endl << "Press any key to continue!";

		_getch();
		fin.close();
	}
	void rooms()										//READING AND DISPLAYING ALL THE DATA
	{

		system("cls");

		ifstream fin("record.txt");
		cout << endl << "\t\t\t<--------------Record of All the Booked Rooms-------------->" << endl;
		cout << endl << endl << " Room No.\tName\t\t\t\tAddress\t\t\t\t\t\tPhone No." << endl;
		string line;
		while (!fin.eof())
		{
			getline(fin, line);							//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[4];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ','))		//SEPARATING LINE ON THE BASES OF COMMA
			{
				str_arr[i] = sngl_word;
				i++;
			}
			RoomNo = stoi(str_arr[0]);				//TURNING STRING TO INTEGER
			name = str_arr[1];
			address = str_arr[2];
			phone = stoi(str_arr[3]);
			cout << endl << endl << " " << RoomNo << "\t" << name;
			cout << "\t\t\t\t" << address << "\t\t\t" << phone;

		}

		cout << endl << endl << endl << "Press any key to continue!";
		_getch();
		fin.close();

	}
	void delete_rec(int n)
	{
		system("cls");

		int flag = 0;
		char ch;

		int rn = n;
		
		if (n == 0)
		{
			cout << endl << "Please enter the customer's Room No. which you want to Delete: ";
			cin >> rn;
		}

		ifstream fin("record.txt");
		ofstream fout("temp.txt");
		string line;

		while (!fin.eof())
		{
			getline(fin, line);			//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[4];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ','))		//SEPARATING LINE ON THE BASES OF COMMA
			{
				str_arr[i] = sngl_word;
				i++;
			}
			RoomNo = stoi(str_arr[0]);			//TURNING STRING TO INTEGER
			name = str_arr[1];
			address = str_arr[2];
			phone = stoi(str_arr[3]);
			if (RoomNo == rn)					//EVERY LINE FROM RECORDS.TXT IS COPIED TO TEMP.TXT EXCEPT WHEN THE ROOM NO MATCHES
			{
				cout << "<--------------Customer Detalis-------------->";
				cout << endl << endl << " Room no: " << RoomNo;
				cout << endl << " Name: " << name;
				cout << endl << " Address: " << address;
				cout << endl << " Phone no: " << phone;
				cout << "\n\n Do you want to delete this record(y/n): ";
				cin >> ch;
				
				if (ch == 'n' || ch == 'N')				//IF USER ENTERS 'n' THE LINE IS WRITTEN IN THE TEMP FILE ELSE ITS SKIPPED
				{
					fout << RoomNo << "," << name << "," << address << "," << phone << "\n";
					flag = 2;
				}
				else if (ch == 'y' || ch =='Y')
				{
					flag = 1;
				}
				else
				{
					fout << RoomNo << "," << name << "," << address << "," << phone << "\n";
					cout << "Invalid option selected....!";
					_getch();
					delete_rec(0);
				}
			}

			else
				fout << RoomNo << "," << name << "," << address << "," << phone << "\n";

		}

		fin.close();
		fout.close();

		if (flag == 0)
		{
			cout << endl << "No records found! The selected Room is available for Booking!";
		}
		else if (flag == 2)
		{
			cout << endl << "The selected Room's data is still available.!";
		}
		else
		{
			cout << endl << "The selected Room's records are deleted and is available for Booking!";
			remove("record.txt");
			rename("temp.txt", "record.txt");
		}
		_getch();
	}
	void edit()
	{
		system("cls");

		int flag = 0;
		char ch;
		int rn;

		cout << endl << "Please enter the customer's Room No. which you want to Modify: ";
		cin >> rn;

		ifstream fin("record.txt");
		ofstream fout("temp.txt");
		string line;

		while (!fin.eof())
		{
			getline(fin, line);			//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[4];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ','))		//SEPARATING LINE ON THE BASES OF COMMA
			{
				str_arr[i] = sngl_word;
				i++;
			}
			RoomNo = stoi(str_arr[0]);			//TURNING STRING TO INTEGER
			name = str_arr[1];
			address = str_arr[2];
			phone = stoi(str_arr[3]);
			if (RoomNo == rn)
			{
				cout << " Enter new Name: ";
				getline(cin, name);
				getline(cin, name);
				cout << " Enter new Address: ";
				getline(cin, address);
				cout << " Enter new Phone No: ";
				cin >> phone;
				fout << RoomNo << "," << name << "," << address << "," << phone << "\n";

				flag = 1;																//FLAG WILL BE 1 WHEN THE RECORD IS EDITED

			}

			else
				fout << RoomNo << "," << name << "," << address << "," << phone << "\n";

		}

		fin.close();
		fout.close();

		if (flag == 0)													//IF FLAG STILL 0 THEN THE DATA IS NOT EDITED
		{
			cout << endl << "No records found! The selected Room is available for Booking!";
		}
		else
		{
			cout << endl << "The selected Room's records are changed.";
			remove("record.txt");
			rename("temp.txt", "record.txt");
		}
		_getch();
	}
	void bill()
	{
		ifstream f1;
		f1.open("record.txt");

		int rn;
		int days;
		int flag;
		cout << endl << "Please enter the customer's Room No. which he stayed in: ";
		cin >> rn;
		string line;
		while (!f1.eof())
		{
			getline(f1, line);			//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[4];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ','))		//SEPARATING LINE ON THE BASES OF COMMA
			{
				str_arr[i] = sngl_word;
				i++;
			}
			RoomNo = stoi(str_arr[0]);			//TURNING STRING TO INTEGER
			name = str_arr[1];
			address = str_arr[2];
			phone = stoi(str_arr[3]);

			if (RoomNo == rn)		//CHECKING IF ROME IS AVAILABLE
			{
				cout << endl << "Please enter the days customer stayed in the Room: "; //MULTIPLE ROOMS HAVE SEPARATE PRICE TAGS
				cin >> days;

				if (RoomNo >= 1 && RoomNo <= 20)
					cout << "Your bill is  " << 10000 * days << endl << "Thanks a lot for Staying at TRANSYLVANIA!";

				else if (RoomNo >= 21 && RoomNo <= 45)
					cout << "Your bill is  " << 15000 * days << endl << "Thanks a lot for Staying at TRANSYLVANIA!";

				else
					cout << "Your bill is  " << 20000 * days << endl << "Thanks a lot for Staying at TRANSYLVANIA!";
				flag = 1;
				break;

			}
			else
			{
				flag = 0;
			}

		}
		if (flag == 0)                         //IF FLAG IS ZERO THEN THIS MEANS THE ROOM IS NOT FOUND
		{
			cout << endl << "No records found! The selected Room is available for Booking!";
			_getch();
			mainMenu();
		}

		f1.close();
		_getch();
		mainMenu();
	}

	void mainMenu()
	{
		int choice = 0;
		while (choice != 7)		//WHILE LOOP IS USED SO WE CAN CONTINUE LOOPING IN THE MAIN MENU UNTIL USER TYPES 7 TO EXIT
		{

			system("cls");
			cout << endl << "\t\t\t <---------------------Hotel Transylvania Management---------------------> ";
			cout << endl << "\t\t\t\t  	             <--- MAIN MENU --->";

			cout << endl << endl << endl << "\t\t\t1) Book A Room";
			cout << endl << "\t\t\t2) Customer Records";
			cout << endl << "\t\t\t3) Rooms Allotted";
			cout << endl << "\t\t\t4) Delete Record";
			cout << endl << "\t\t\t5) Modify the records";
			cout << endl << "\t\t\t6) Checkout/Bill";
			cout << endl << "\t\t\t7) Exit";
			cout << endl << "\n\t\t\tEnter Your Choice: ";
			cin >> choice;

			switch (choice)
			{

			case 1:	add();
				break;

			case 2: display();
				break;

			case 3: rooms();
				break;

			case 4:	delete_rec(0);
				break;
			case 5: edit();
				break;
			case 6: bill();
				break;
			case 7: break;
			default:
			{

				cout << endl << "\t\t\tPlease enter a Valid Choice between 1-5:";
				cin >> choice;
			}

			}

		}
	}


};
int main()
{
	cout << "  ============================================================================================" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||            WELCOME TO HOTEL TRANSYLVANIA MANAGMENT SYSTEM                              ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||             BY:                                                                        ||" << endl;
	cout << "  ||                 MUHAMMAD FAHAD SHAFIQUE      29006                                     ||" << endl;
	cout << "  ||                 RANA ALI MURAD               28948                                     ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                  PRESS ANY KEY TO CONTINUE........!                                    ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ============================================================================================" << endl;	
	_getch();


	HotelManagementSystem* h = new Hotel();					//CREATED OBJECT OF INTERFACE CLASS POINTING TOWARDS CONCERETE CLASS
	h->mainMenu();


	system("CLS");
	cout << "  ============================================================================================" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                  THANKS FOR STAYING AT HOTEL TRANSYLVANIA                              ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                     HOPE YOU'LL VIST AGAIN SOON.                                       ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ||                  PRESS ANY KEY TO EXIT.....!                                           ||" << endl;
	cout << "  ||                                                                                        ||" << endl;
	cout << "  ============================================================================================" << endl;
}