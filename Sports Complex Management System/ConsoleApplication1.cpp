#include<iostream>
#include<string>
#include <sstream>
#include <bits/stdc++.h> 
#include<windows.h>
#include"queue1.h"
#include"animation.h"
#include"Booking.h"

using namespace std;

int search(int);
int display();
string check(int);       //   for checking quantity
Queue member;


bool is_valid_integer(string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 48 || 57 < str[i])
			return false;
	}

	return true;

}

class node
{
public:
	int ID;
	string equipName;
	double equipPrice;
	int quantity;
	node* next;

	node()
	{
		ID = 0;
		equipPrice = 0;
		quantity = 0;
		next = NULL;
	}
};

 node* head = NULL;


void insertEquipment()
{
	system("cls");
	int id, quant;           //  quant    for equipment quantity
	string name;
	double pre;            //  pre for equipment price
	node* t = new node;
	node* p = head;

	cout << "\t\t\tEnter equipment ID : ";
	cin >> id;
	t->ID = id;
	cout << "\t\t\tEnter equipment Name : ";
	cin >> name;
	t->equipName = name;
	cout << "\t\t\tEnter equipment price : ";
	cin >> pre;
	t->equipPrice = pre;
	cout << "\t\t\tEnter equipment quantity : ";
	cin >> quant;
	t->quantity = quant;
	if (head == NULL)
	{
		t->next = head;
		head = t;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = t;
		t->next = NULL;

	}
	system("cls");
	cout << "\n\n\t\t\t\tThis equipment is Inserted!\n\n\n";

}

int search(int id)                     //    for search equipment in list
{
	int count = 1;
	node* p = head;
	while (p != NULL)
	{
		if (p->ID == id)
			break;
		else
			count++;
		p = p->next;
	}
	return count;
}

void deleteEquipment()
{
	system("cls");
	display();
	int id;
	node* cur = head;
	node* pre = head;
	cout << "\n\nEnter ID to delete that equipment : ";
	cin >> id;
	if (head == NULL)
	{
		system("cls");
		cout << "\nList is empty" << endl;
	}
	int pos = 0;
	int count = display();               //   to count no of nodes
	pos = search(id); //   for check weather desire node is exist or not
	if (cur == NULL)
	{

	}
	else
	{
		if (pos <= count) {
			while (cur->ID != id) {                //  for delete  equipments
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
			system("cls");
			cout << "\n<<Equipment is deleted>>\n";
		}
		else {
			cout << "\n<<<Not found>>\n\n";
		}
	}
}


void modify()
{
	int id;
	double pre;        //    pre for price
	string pName;
	int nid; int nq;     //   pName for new name
	if (head == NULL)
	{
		system("cls");
		cout << "\nList is empty" << endl;
	}
	else
	{
		display();
		cout << "\n\nEnter ID to modify equipment Name and its price : ";
		cin >> id;
		node* cur = head;
		int pos = 0;
		int count = display();               //   to count no of nodes
		pos = search(id);
		//   for check weather desire node is exists or not
		if (pos <= count)
		{
			while (cur->ID != id)
			{
				cur = cur->next;
			}
			cout << "Old ID       : " << cur->ID << endl;
			cout << "Old Name     : " << cur->equipName << endl;
			cout << "Old Price    : " << cur->equipPrice << endl;
			cout << "Old Quantity : " << cur->quantity << endl;

			cout << endl << endl;
			cout << "Enter new ID      : ";
			cin >> nid;
			cur->ID = nid;
			cout << "Enter new Name    : ";
			cin >> pName;
			cur->equipName = pName;
			cout << "Enter new Price   : ";
			cin >> pre;
			cur->equipPrice = pre;
			cout << "Enter new Quantity: ";
			cin >> nq;
			cur->quantity = nq;
		}

		else
		{
			cout << id << " is <<<Not found>>\n\n";
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////

int display()
{
	system("cls");
	int c = 0;             //   c to count equipments
	node* p = head;
	cout << "Existing equipment are:\n";
	cout << "ID\t\tEquipment Name\t\tPrice\t\tQuantity\n";
	cout << "=================================================================|\n";
	while (p != NULL)
	{
		cout << p->ID << "\t\t" << p->equipName << "\t\t\t" << p->equipPrice << "\t\t\t" << check(p->quantity) << "\n"; //    call   check func and pass quantity
		p = p->next;
		c = c + 1;
	}
	cout << "\nTotal available equipment in our Sports Complex is : " << c << "\n\n\n";
	return c;
}
////////////////////////////////////////////////////////////////////////////////////////
string check(int quant)

{              //        check function
	int a = quant;
	stringstream ss;
	ss << a;
	string quantity = ss.str();

	if (quant <= 0)
		return "Out of stock!";
	else
		return quantity;
}

///////////////////////////////////////////////////////////////////////
void buy()
{
	system("cls");
	display();
	string products[20];
	//   for display sold items
	double price, pay = 0;
	int no, c = 0,  id=0, i = 1;

	if (head == NULL)
	{
		cout << "\n<<<<There is no equipment to buy>>>>\n\n";
	}
	else
	{
		cout << "How many equipment you want to buy : ";
		cin >> no;
		int count = display();           //   for store no of nodes  in c
		while (i <= no)
		{
			node* cur = head;
			int quant;   a:        //   quant   for quantity  and cho for choice
			cout << "Enter id of equipment that you want to buy: ";
			int id, pos = 0;
			cin >> id;
			if (id == -1) 
			{ 
				system("cls"); 
				return; 
			}
			pos = search(id);
			if (pos <= count)
			{
				//     item is available in store
				while (cur->ID != id)
				{
					cur = cur->next;
				}
				cout << "How many quantities you want: ";
				cin >> quant;
				if (cur->quantity < quant)
				{
					cout << "\n\n\t\t\t---- The Quantity You Entered is not available ---" << endl;
					cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
					goto a;

				}
				products[c] = cur->equipName;   // this will conatin the items buy names in array; 
				c++;

				pay = pay + (cur->equipPrice * quant);         //     calculate the Bill
				cur->quantity = cur->quantity - quant;           //    change the quantity of the products
				i++;

			}
			else
			{

				cout << "\n<<<<<<<<< This item is not available in our Sports Complex at this time >>>>\n\n";

			}
		}
		
		string yourName;
		cout << "\n\t\t Enter Your Name : "; cin >> yourName;
		member.enqueue(yourName);
		system("cls");
		cout << "\n\n\n\n\t\t\tYou have bought : ";
		for (int i = 0; i < no; i++)
		{              //    show that item you have bought
			cout << products[i] << ",";
		}
		price = pay;
		cout << "\n\nTotal price for equipment : " << pay;
		cout << "\nThank you!\n\n";




	}
}

void removeMember( Queue& member)
{
	string t;
	cout << "Enter the member name you want to delete: ";
	cin >> t;
	
	Queue ref;  // Helper queue to store the elements temporarily.
	int s = member.size;
	int cnt = 0;

	// Finding the value to be removed
	while (member.front->cname != t and !member.isempty()) {
		ref.enqueue(member.front->cname);
		member.dequeue();
		cnt++;
	}

	// If element is not found
	if (member.isempty()) {
		cout << "Element not found!!" << endl;
		while (!ref.isempty()) {

			// Pushing all the elements back into queue
			member.enqueue(ref.front->cname);
			ref.dequeue();
		}
	}

	// If element is found
	else {
		member.dequeue();
		while (!ref.isempty()) {

			// Pushing all the elements back into queue
			member.enqueue(ref.front->cname);
			ref.dequeue();
		}
		int k = s - cnt - 1;
		while (k--) {

			// Pushing elements from front of queue to its back
			string p = member.front->cname;
			member.dequeue();
			member.enqueue(p);
		}
	}
}

void administator()
{
	system("cls");
	int ch;
	string temp;

	do {


		cout << "\t\t============================================" << endl;
		cout << "\t\t|          Administator Portal              |" << endl;
		cout << "\t\t============================================" << endl;

		cout << "\t\t     Enter 1 for Add a new equipment    " << endl;
		cout << "\t\t     Enter 2 for Display all available equipment   " << endl;
		cout << "\t\t     Enter 3 for Modify existing equipment" << endl;
		cout << "\t\t     Enter 4 for Delete a particular equipment" << endl;
		cout << "\t\t     Enter 5 for Member List " << endl;
		cout << "\t\t     Enter 6 for Dequeue member" << endl;
		cout << "\t\t     Enter 7 for Remove a specific member" << endl;
		cout << "\t\t     Enter 0 for Main Menu" << endl;


		cout << "\nEnter Your choice : ";   
		cin >> temp;
		cout << "\n";

		while (1) {

			if (is_valid_integer(temp))
				break;
			else {
				cout << "The entered choice is incorrect. Please enter again." << endl;
				cout << "\nEnter Your choice : ";
				cin >> temp;
			}
		}

		ch = stoi(temp);

		switch (ch) {
		case 1:
			insertEquipment();
			break;
		case 2:
			system("cls");
			display();
			break;
		case 3:
			modify();
			system("cls");
			break;
		case 4:
			deleteEquipment();
			cout << "\n-------Operation is done-------\n";
			break;
		case 5:
			system("cls");
			cout << "|============MEMBERS NAMES LIST==============|" << endl;
			member.displayQueue();
			break;
		case 6:
			system("cls");
			cout << "|============MEMBERS NAMES LIST==============|" << endl;
			member.dequeue();
			member.displayQueue();
			break;
		case 7:
			system("cls");
			cout << "|============memberS NAMES LIST==============|" << endl;
			member.displayQueue();
			if (!member.isempty())
			{
				removeMember(member);
				system("cls");
				cout << "|============memberS NAMES LIST==============|" << endl;
				member.displayQueue();
			}
		
			break;

		default: system("cls");

		}
	} while (ch != 0);
}

void memberBooking() {
	court ct;
	int choice;
	char ch;     //yes or no choice
	int courtcheck;   
	ct.create();
	cout << "\t\t\t============== Welcome to the Court booking portal of our sports complex ============== \n" << endl;
	cout << "One person can book only for himself/herself and two others " << endl;

	do
	{
		cout << "\n1.Book a court for 1 person\n2.Book a court for 2 persons\n3.Book a court for 3 persons\n4.Display the current status of courts\n5.cancel a slot\n6.upgrade\n\n" << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "To book a Basketball court enter number 1 (10 courts available)" << endl;
			cout << "To book a Tennis court enter number 2     (10 courts available)" << endl;
			cout << "To book a Badminton court enter number 3  (10 courts available)" << endl;
			ct.book(1);
			break;
		}
		case 2:
		{
			cout << "To book a Basketball court enter number 1 (10 courts available)" << endl;
			cout << "To book a Tennis court enter number 2     (10 courts available)" << endl;
			cout << "To book a Badminton court enter number 3  (10 courts available)" << endl;
			ct.book(2);
			break;
		}
		case 3:
		{
			cout << "To book a Basketball court enter number 1 (10 courts available)" << endl;
			cout << "To book a Tennis court enter number 2     (10 courts available)" << endl;
			cout << "To book a Badminton court enter number 3  (10 courts available)" << endl;
			ct.book(3);
			break;
		}
		case 4:
		{
			ct.display();
			break;
		}
		case 5:
		{
			cout << "Enter main court number : ";
			cin >> courtcheck;
			ct.cancel(courtcheck);
			break;
		}
		case 6:
		{
			cout << "Enter main court number : ";
			cin >> courtcheck;
			ct.upgrade(courtcheck);
			break;
		}

		default:
			cout << "\nInvalid choice ";
		}
		cout << "\nDo you want to continue(Y / N) ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');

}



int main()
{
	
	system("color B0");     //  changing console color
	gotoxy(55, 5);
	cout << "----------------------------------------------------" << endl;
	gotoxy(55, 7);
	cout << "||        Sports Complex Management System        ||" << endl;
	gotoxy(55, 9);
	cout << "----------------------------------------------------" << endl;
	gotoxy(47, 11);
	cout << "| Subject Teacher : Dr. Kushan Sudheera & Mr.Nilmantha Wijesekara |\n" << endl;
	gotoxy(56, 13);
	cout << "  >>>---- Mini Project Implemented By-----<<<  " << endl;
	gotoxy(64, 15);
	cout << "Dineth Jayakody   (EG/2019/3609)" << endl;
	gotoxy(64, 16);
	cout << "Koshila Isuranda  (EG/2019/3607)" << endl;
	gotoxy(64, 17);
	cout << "Kavindu Induwara  (EG/2019/3646)" << endl << endl;
	system("pause");
	system("cls");
	system("color B0");

	int ch=0;
	while (ch != 4) {

		cout << "\n\t\t    |--------<Main Menu>-----------|";
		cout << "\n\n"; 
		cout << "\t\t 1) Administator of the Sports Complex\n";
		cout << "\t\t 2) Buying Equipments               \n";
		cout << "\t\t 3) Member booking        \n";
		cout << "\t\t 4) Exit                    \n";

		string psw_input;
		string password = "1234";
		cout << "\nEnter Your choice : "; cin >> ch;
		switch (ch) {
		case 1:
			
			cout << "Enter 4 digit password : ";

			cin >> psw_input;
			if (psw_input != password)
			{
				cout << "Password Invalid!!!. Try again" << endl;
				cout << "\nEnter 4 digit password : ";
				cin >> psw_input;
				while (psw_input != password)
				{
					cout << "Password Invalid!!!. Try again" << endl;
					cout << "\nEnter 4 digit password : ";
					cin >> psw_input;
				}
				administator();
				break;
			}
			else
			{
				administator();
				break;
			}
			

		case 2:
			cout << endl << endl;
			system("pause");
			buy();
			break;

		case 3:
			memberBooking();
			break;

		case 4:
			cout << "\n\n\t\t\t\t\tThank You\t\t\t\t";
			break;

		}
	}
	return 0;
}






