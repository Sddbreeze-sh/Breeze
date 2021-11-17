#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<iomanip>
#include<Windows.h>

using namespace std;
///////////////////////
/// Class declaration
///////////////////////
class Base_orders {
public:
	string order_number; //Order number(Receipt number)
	string dish_number; //Item's serial number
	string dish_name; //Item's name
	string dish_price; //Item's price
	int amount = 0; //Amount of same dishes user wants to order
	double total_price = 0;
	void out_file_eachDish(string file_name); //To output ordered dish to a .txt file as a receipt
	void cout_orders(); //Print out what the suer ordered
};

class Delivery_orders :public Base_orders {
public:
	int delivery_fee = 5;
	Delivery_orders(string a, string b, string c, string d, int j) { order_number = a, dish_number = b, dish_name = c, dish_price = d, amount = j; }

};

class Pickup_orders :public Base_orders {
public:
	Pickup_orders(string a, string b, string c, string d, int h) { order_number = a, dish_number = b, dish_name = c, dish_price = d, amount = h; }

};

class User {
private:
	vector<Delivery_orders> vec_Delivery_orders; //Vector to store variable like order_number, dish_number, dish_name, dish_price and amount
	vector<Pickup_orders> vec_Pickup_orders; //Vector to store variable like order_number, dish_number, dish_name, dish_price and amount
public:
	string order_number;
	void start_order_malay(); //Start ordering in different stall
	void start_order_mamak();
	void start_order_beverage();
	void start_order_korean();
	void start_order_japanese();
	void user_data_delivery(string& user_name, string& user_contact, string& user_id, string& user_address); //To acqurie user's details
	void user_data_pickup(string& user_name, string& user_contact, string& user_id); //To acquire user's details
};

///////////////////////////
/// Function definition
///////////////////////////

void cout_menu(string file_name) {
	ifstream fin(file_name);
	string str;
	cout << "==============================Menu==============================" << endl;
	cout << std::left << setw(9) << "Serial number\t" << std::left << setw(35) << "Name\t" << std::left << setw(16) << "Price" << endl;
	while (getline(fin, str))
		cout << str << endl;
	fin.close();
}

void Base_orders::out_file_eachDish(string file_name) { //Create a file that store whatever the user ordered
	ofstream out(file_name, ios::app);
	out << std::left << setw(23) << dish_number;
	out << std::left << setw(45) << dish_name;
	out << std::left << setw(22) << dish_price;
	out << std::left << setw(16) << amount << endl;
}

void Base_orders::cout_orders() { //Print out what the user have ordered in the system
	cout << std::left << setw(23) << dish_number;
	cout << std::left << setw(45) << dish_name;
	cout << std::left << setw(22) << dish_price;
	cout << std::left << setw(16) << amount << endl;
}

void User::user_data_delivery(string& user_name, string& user_contact, string& user_id, string& user_address) {
	int option_data; //User's option to re-enter personal details
	restartdata:
	cout << "Can we have your name?" << endl;
	cin.ignore(1, '\n');
	getline(cin, user_name);
	cout << "Aye hello " << user_name << ":)" << endl;
	cout << "Can we have your contact number?" << endl;
	getline(cin, user_contact);
	cout << "And student id" << endl;
	getline(cin, user_id);
	cout << "Where do you want us to deliver the food?" << endl;
	getline(cin, user_address);
	cout << endl << "Name: " << user_name << endl; //To double check with the user
	cout << "Student id: " << user_id << endl;
	cout << "Contact number: " << user_contact << endl;
	cout << "Address: " << user_address << endl;
	cout << endl << "Do you want to reinsert your data?" << endl; //Ask if the user wants to re-enter the data
	cout << "[1] YES" << endl << "[2] NO" << endl;
	cout << "To continue, just select a number from the list." << endl;
	cout << "Your option: ";
	cin >> option_data;
	if (option_data == 1) {
		goto restartdata;
	}
	else if (option_data == 2) {
		cout << "Sure let's move on." << endl;
	}
	else {
		cout << "Wrong input! Please enter only the given numbers. Let's try again." << endl; //Detect wrong input, let user to try again
		goto restartdata;
	}
}

void User::user_data_pickup(string& user_name, string& user_contact, string& user_id) {
	int option_data; //User's option to re-enter personal details
restartdata:
	cout << "Can we have your name?" << endl;
	cin.ignore(1, '\n');
	getline(cin, user_name);
	cout << "Aye hello " << user_name << ":)" << endl;
	cout << "Can we have your contact number?" << endl;
	getline(cin, user_contact);
	cout << "And student id" << endl;
	getline(cin, user_id);
	cout << endl << "Name: " << user_name << endl; //To double check with the user
	cout << "Student id: " << user_id << endl;
	cout << "Contact number: " << user_contact << endl;
	cout << endl << "Do you want to reinsert your data?" << endl; //Ask if the user wants to re-enter the data
	cout << "[1] YES" << endl << "[2] NO" << endl;
	cout << "To continue, just select a number from the list." << endl;
	cout << "Your option: ";
	cin >> option_data;
	if (option_data == 1) {
		goto restartdata;
	}
	else if (option_data == 2) {
		cout << "Alright thank you for your time." << endl;
	}
	else {
		cout << "Wrong input! Please enter only the given numbers. Let's try again." << endl; //Detect wrong input, let user to try again
		goto restartdata;
	}
}

void User::start_order_malay() {
	int consume_op;
	double total_pric = 0;
	double delivery_fe = 0;
	int date;
	string dish_num;
	int dish_amount;
	string dish_nam;
	string dish_pri;
	string order_number;
	string user_nam;
	string user_contac;
	string user_Id;
	string user_addres;
	SYSTEMTIME st = { 0 };
	GetSystemTime(&st);
	date = ((st.wDay * 100 + st.wHour) * 100 + st.wMinute);
	order_number = to_string(date) + order_number;

	string file_name = to_string(date) + " _Malay.txt";
	ofstream out(file_name, ios::app);

	cout << "Would you like to Pick up the orders or want us to Deliver it?" << endl;
	cout << "[1] PICK UP" << endl;
	cout << "[2] DELIVER" << endl;
	cout << "Your option: ";
	cin >> consume_op;

	if (consume_op == 1) {
		ifstream fin("menu_Malay_Pickup.txt");
		cout_menu("menu_Malay_Pickup.txt");
	}
	else if (consume_op == 2) {
		ifstream fin("menu_Malay_Delivery.txt");
		cout_menu("menu_Malay_Delivery.txt");
	}

		
	cout << "Please enter Serial Number and Quantity of your desired option (Guide: enter '0 0' to end the order) : " << endl;
	vec_Delivery_orders.clear();
	vec_Pickup_orders.clear();

	string str;

	for (;;) {
		cin >> dish_num >> dish_amount;
		int i = 0;
		int flag = 0;
		ifstream fin2("menu_Malay_Pickup.txt");
		while (fin2 >> str) {
			i++;
			if (i == 1) {
				if (dish_num == str)
					flag = 1;
			}
			if (flag == 1) {
				if (i == 2) dish_nam = str;
				if (i == 3) {
					dish_pri = str;
					if (consume_op == 1) {
						Pickup_orders pickup_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Pickup_orders.push_back(pickup_ord);
					}
					else if (consume_op == 2) {
						Delivery_orders delivery_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Delivery_orders.push_back(delivery_ord);
					}
					flag = 0;

				}
			}
			if (i == 3) i = 0;
		}if (dish_num == "0" && dish_amount == 0) break;
	}

	if (consume_op == 1) {
		user_data_pickup(user_nam, user_contac, user_Id);
	}
	else if (consume_op == 2) {
		delivery_fe = 5;
		user_data_delivery(user_nam, user_contac, user_Id, user_addres);
	}

	total_pric = delivery_fe;

	if (consume_op == 1) {
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			total_pric += atof((vec_Pickup_orders[i].dish_price).c_str()) * vec_Pickup_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Pickup_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered MalayStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
	else if (consume_op == 2) {
		for (int i = 0; i < vec_Delivery_orders.size(); i++) {
			total_pric += atof((vec_Delivery_orders[i].dish_price).c_str()) * vec_Delivery_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Delivery_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Address: " << user_addres << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered MalayStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Address: " << user_addres << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
}

void User::start_order_mamak() {
	int consume_op;
	double total_pric = 0;
	double delivery_fe = 0;
	int date;
	string dish_num;
	int dish_amount;
	string dish_nam;
	string dish_pri;
	string order_number;
	string user_nam;
	string user_contac;
	string user_Id;
	string user_addres;
	SYSTEMTIME st = { 0 };
	GetSystemTime(&st);
	date = ((st.wDay * 100 + st.wHour) * 100 + st.wMinute);
	order_number = to_string(date) + order_number;

	string file_name = to_string(date) + " _Mamak.txt";
	ofstream out(file_name, ios::app);

	cout << "Would you like to Pick up the orders or want us to Deliver it?" << endl;
	cout << "[1] PICK UP" << endl;
	cout << "[2] DELIVER" << endl;
	cout << "Your option: ";
	cin >> consume_op;

	if (consume_op == 1) {
		ifstream fin("menu_Mamak_Pickup.txt");
		cout_menu("menu_Mamak_Pickup.txt");
	}
	else if (consume_op == 2) {
		ifstream fin("menu_Mamak_Delivery.txt");
		cout_menu("menu_Mamak_Delivery.txt");
	}


	cout << "Please enter Serial Number and Quantity of your desired option (Guide: enter '0 0' to end the order) : " << endl;
	vec_Delivery_orders.clear();
	vec_Pickup_orders.clear();

	string str;

	for (;;) {
		cin >> dish_num >> dish_amount;
		int i = 0;
		int flag = 0;
		ifstream fin2("menu_Mamak_Pickup.txt");
		while (fin2 >> str) {
			i++;
			if (i == 1) {
				if (dish_num == str)
					flag = 1;
			}
			if (flag == 1) {
				if (i == 2) dish_nam = str;
				if (i == 3) {
					dish_pri = str;
					if (consume_op == 1) {
						Pickup_orders pickup_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Pickup_orders.push_back(pickup_ord);
					}
					else if (consume_op == 2) {
						Delivery_orders delivery_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Delivery_orders.push_back(delivery_ord);
					}
					flag = 0;

				}
			}
			if (i == 3) i = 0;
		}if (dish_num == "0" && dish_amount == 0) break;
	}

	if (consume_op == 1) {
		user_data_pickup(user_nam, user_contac, user_Id);
	}
	else if (consume_op == 2) {
		delivery_fe = 5;
		user_data_delivery(user_nam, user_contac, user_Id, user_addres);
	}

	total_pric = delivery_fe;

	if (consume_op == 1) {
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			total_pric += atof((vec_Pickup_orders[i].dish_price).c_str()) * vec_Pickup_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Pickup_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered MamakStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
	else if (consume_op == 2) {
		for (int i = 0; i < vec_Delivery_orders.size(); i++) {
			total_pric += atof((vec_Delivery_orders[i].dish_price).c_str()) * vec_Delivery_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Delivery_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Address: " << user_addres << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered MamakStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Address: " << user_addres << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
}

void User::start_order_beverage() {
	int consume_op;
	double total_pric = 0;
	double delivery_fe = 0;
	int date;
	string dish_num;
	int dish_amount;
	string dish_nam;
	string dish_pri;
	string order_number;
	string user_nam;
	string user_contac;
	string user_Id;
	string user_addres;
	SYSTEMTIME st = { 0 };
	GetSystemTime(&st);
	date = ((st.wDay * 100 + st.wHour) * 100 + st.wMinute);
	order_number = to_string(date) + order_number;

	string file_name = to_string(date) + " _Beverage.txt";
	ofstream out(file_name, ios::app);

	cout << "Would you like to Pick up the orders or want us to Deliver it?" << endl;
	cout << "[1] PICK UP" << endl;
	cout << "[2] DELIVER" << endl;
	cout << "Your option: ";
	cin >> consume_op;

	if (consume_op == 1) {
		ifstream fin("menu_Beverage_Pickup.txt");
		cout_menu("menu_Beverage_Pickup.txt");
	}
	else if (consume_op == 2) {
		ifstream fin("menu_Beverage_Delivery.txt");
		cout_menu("menu_Beverage_Delivery.txt");
	}


	cout << "Please enter Serial Number and Quantity of your desired option (Guide: enter '0 0' to end the order) : " << endl;
	vec_Delivery_orders.clear();
	vec_Pickup_orders.clear();

	string str;

	for (;;) {
		cin >> dish_num >> dish_amount;
		int i = 0;
		int flag = 0;
		ifstream fin2("menu_Beverage_Pickup.txt");
		while (fin2 >> str) {
			i++;
			if (i == 1) {
				if (dish_num == str)
					flag = 1;
			}
			if (flag == 1) {
				if (i == 2) dish_nam = str;
				if (i == 3) {
					dish_pri = str;
					if (consume_op == 1) {
						Pickup_orders pickup_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Pickup_orders.push_back(pickup_ord);
					}
					else if (consume_op == 2) {
						Delivery_orders delivery_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Delivery_orders.push_back(delivery_ord);
					}
					flag = 0;

				}
			}
			if (i == 3) i = 0;
		}if (dish_num == "0" && dish_amount == 0) break;
	}

	if (consume_op == 1) {
		user_data_pickup(user_nam, user_contac, user_Id);
	}
	else if (consume_op == 2) {
		delivery_fe = 5;
		user_data_delivery(user_nam, user_contac, user_Id, user_addres);
	}

	total_pric = delivery_fe;

	if (consume_op == 1) {
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			total_pric += atof((vec_Pickup_orders[i].dish_price).c_str()) * vec_Pickup_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Pickup_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(4) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered BeverageStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
	else if (consume_op == 2) {
		for (int i = 0; i < vec_Delivery_orders.size(); i++) {
			total_pric += atof((vec_Delivery_orders[i].dish_price).c_str()) * vec_Delivery_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Delivery_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Address: " << user_addres << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered BeverageStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Address: " << user_addres << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
}

void User::start_order_korean() {
	int consume_op;
	double total_pric = 0;
	double delivery_fe = 0;
	int date;
	string dish_num;
	int dish_amount;
	string dish_nam;
	string dish_pri;
	string order_number;
	string user_nam;
	string user_contac;
	string user_Id;
	string user_addres;
	SYSTEMTIME st = { 0 };
	GetSystemTime(&st);
	date = ((st.wDay * 100 + st.wHour) * 100 + st.wMinute);
	order_number = to_string(date) + order_number;

	string file_name = to_string(date) + " _Korean.txt";
	ofstream out(file_name, ios::app);

	cout << "Would you like to Pick up the orders or want us to Deliver it?" << endl;
	cout << "[1] PICK UP" << endl;
	cout << "[2] DELIVER" << endl;
	cout << "Your option: ";
	cin >> consume_op;

	if (consume_op == 1) {
		ifstream fin("menu_Korean.txt");
		cout_menu("menu_Korean.txt");
	}
	else if (consume_op == 2) {
		ifstream fin("menu_Korean.txt");
		cout_menu("menu_Korean.txt");
	}


	cout << "Please enter Serial Number and Quantity of your desired option (Guide: enter '0 0' to end the order) : " << endl;
	vec_Delivery_orders.clear();
	vec_Pickup_orders.clear();

	string str;

	for (;;) {
		cin >> dish_num >> dish_amount;
		int i = 0;
		int flag = 0;
		ifstream fin2("menu_Korean.txt");
		while (fin2 >> str) {
			i++;
			if (i == 1) {
				if (dish_num == str)
					flag = 1;
			}
			if (flag == 1) {
				if (i == 2) dish_nam = str;
				if (i == 3) {
					dish_pri = str;
					if (consume_op == 1) {
						Pickup_orders pickup_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Pickup_orders.push_back(pickup_ord);
					}
					else if (consume_op == 2) {
						Delivery_orders delivery_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Delivery_orders.push_back(delivery_ord);
					}
					flag = 0;

				}
			}
			if (i == 3) i = 0;
		}if (dish_num == "0" && dish_amount == 0) break;
	}

	if (consume_op == 1) {
		user_data_pickup(user_nam, user_contac, user_Id);
	}
	else if (consume_op == 2) {
		delivery_fe = 5;
		user_data_delivery(user_nam, user_contac, user_Id, user_addres);
	}

	total_pric = delivery_fe;

	if (consume_op == 1) {
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			total_pric += atof((vec_Pickup_orders[i].dish_price).c_str()) * vec_Pickup_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Pickup_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered KoreanStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
	else if (consume_op == 2) {
		for (int i = 0; i < vec_Delivery_orders.size(); i++) {
			total_pric += atof((vec_Delivery_orders[i].dish_price).c_str()) * vec_Delivery_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Delivery_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Address: " << user_addres << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered KoreanStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Address: " << user_addres << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
}

void User::start_order_japanese() {
	int consume_op;
	double total_pric = 0;
	double delivery_fe = 0;
	int date;
	string dish_num;
	int dish_amount;
	string dish_nam;
	string dish_pri;
	string order_number;
	string user_nam;
	string user_contac;
	string user_Id;
	string user_addres;
	SYSTEMTIME st = { 0 };
	GetSystemTime(&st);
	date = ((st.wDay * 100 + st.wHour) * 100 + st.wMinute);
	order_number = to_string(date) + order_number;

	string file_name = to_string(date) + " _Japanese.txt";
	ofstream out(file_name, ios::app);

	cout << "Would you like to Pick up the orders or want us to Deliver it?" << endl;
	cout << "[1] PICK UP" << endl;
	cout << "[2] DELIVER" << endl;
	cout << "Your option: ";
	cin >> consume_op;

	if (consume_op == 1) {
		ifstream fin("menu_Japanese.txt");
		cout_menu("menu_Japanese.txt");
	}
	else if (consume_op == 2) {
		ifstream fin("menu_Japanese.txt");
		cout_menu("menu_Japanese.txt");
	}


	cout << "Please enter Serial Number and Quantity of your desired option (Guide: enter '0 0' to end the order) : " << endl;
	vec_Delivery_orders.clear();
	vec_Pickup_orders.clear();

	string str;

	for (;;) {
		cin >> dish_num >> dish_amount;
		int i = 0;
		int flag = 0;
		ifstream fin2("menu_Japanese.txt");
		while (fin2 >> str) {
			i++;
			if (i == 1) {
				if (dish_num == str)
					flag = 1;
			}
			if (flag == 1) {
				if (i == 2) dish_nam = str;
				if (i == 3) {
					dish_pri = str;
					if (consume_op == 1) {
						Pickup_orders pickup_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Pickup_orders.push_back(pickup_ord);
					}
					else if (consume_op == 2) {
						Delivery_orders delivery_ord(order_number, dish_num, dish_nam, dish_pri, dish_amount);
						vec_Delivery_orders.push_back(delivery_ord);
					}
					flag = 0;

				}
			}
			if (i == 3) i = 0;
		}if (dish_num == "0" && dish_amount == 0) break;
	}

	if (consume_op == 1) {
		user_data_pickup(user_nam, user_contac, user_Id);
	}
	else if (consume_op == 2) {
		delivery_fe = 5;
		user_data_delivery(user_nam, user_contac, user_Id, user_addres);
	}

	total_pric = delivery_fe;

	if (consume_op == 1) {
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			total_pric += atof((vec_Pickup_orders[i].dish_price).c_str()) * vec_Pickup_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Pickup_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered JapaneseStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "Amount" << endl;
		for (int i = 0; i < vec_Pickup_orders.size(); i++) vec_Pickup_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
	else if (consume_op == 2) {
		for (int i = 0; i < vec_Delivery_orders.size(); i++) {
			total_pric += atof((vec_Delivery_orders[i].dish_price).c_str()) * vec_Delivery_orders[i].amount;
		}
		for (int i = 0; i < vec_Pickup_orders.size(); i++) {
			vec_Delivery_orders[i].total_price = total_pric;
		}
		out << "Order number: ";
		out << order_number << endl;
		out << "Ordered: " << endl;
		out << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].out_file_eachDish(file_name);
		out << "Your name: " << user_nam << endl;
		out << "Id: " << user_Id << endl;
		out << "Contact number: " << user_contac << endl;
		out << "Address: " << user_addres << endl;
		out << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;

		cout << endl << "Receipt: " << endl;
		cout << "Order number: ";
		cout << order_number << endl;
		cout << "You ordered JapaneseStall: " << endl;
		cout << std::left << setw(23) << "Serial number" << std::left << setw(45) << "Name" << std::left << setw(22) << "Price" << std::left << setw(16) << "amount" << endl;
		for (int i = 0; i < vec_Delivery_orders.size(); i++) vec_Delivery_orders[i].cout_orders();
		cout << "Your name: " << user_nam << endl;
		cout << "Id: " << user_Id << endl;
		cout << "Contact number: " << user_contac << endl;
		cout << "Address: " << user_addres << endl;
		cout << "Total price: " << setiosflags(ios::fixed) << setprecision(2) << total_pric << endl << endl;
	}
}

int stall() {
	int option_stall; //User's option to choose which stall to visit
	cout << "We are pleased to offer you a wide variety of food." << endl;
	cout << "[1] MALAY" << endl << "[2] MAMAK" << endl << "[3] BEVERAGE" << endl << "[4] KOREAN" << endl << "[5] JAPANESE" << endl; //Options for user to choose which stall they want to visit
	cout << "To continue, just select a number from the list." << endl;
	cout << "Your option: ";
	cin >> option_stall;
	return option_stall;
}

//////////////////////// 
/// Main function
////////////////////////
int main() {
	User user;
	int option1; //User's first option at the beginning
	int option_stall; //User's option to choose which stall to visit
	string user_name, user_address, user_contact, user_id; //Store user details
	beginning: //To comeback to this step when RESTART BOT is selected or error input from user.
	cout << "Welcome to Breeze Cafeteria" << endl;
	cout << "We believe that Good Food equals to Good Mood. Here we provide good quality food made with good mood." << endl;
	cout << "How may I help you?" << endl;
	cout << "[1] ORDER NOW" << endl << "[2] FAQs" << endl; //Options for user to look up for FAQs or start the order
	cout << "To continue, just select a number from the list." << endl;
	cout << "Your option: ";
	cin >> option1;


	if (option1 == 1) { //Outer if else statement for option1
		cout << "Alright!" << endl;
		beginning_stall_option:
		option_stall = stall();
		switch (option_stall) {
		case 1:
			cout << "=====Malay Stall=====" << endl;
			user.start_order_malay();
			break;
		case 2:
			cout << "=====Mamak Stall=====" << endl;
			user.start_order_mamak();
			break;
		case 3:
			cout << "=====Beverage=====" << endl;
			user.start_order_beverage();
			break;
		case 4:
			cout << "=====Korean=====" << endl;
			user.start_order_korean();
			break;
		case 5:
			cout << "=====Japanese=====" << endl;
			user.start_order_japanese();
			break;
		default:
			cout << "Wrong input! Please enter only the given numbers. Let's try again." << endl; //Detect wrong input, let user to try again
			goto beginning_stall_option;
			break;
		}
	}
	else if (option1 == 2) {
		int option_faq; //User's option after FAQ
		cout << "Alright!" << endl;
		cout << "Below are our FAQ list, if you have any unanswered queries please feel free to contact our live customer service." << endl;
		//Insert FAQs

		cout << "[1] LIVE CHAT" << endl << "[2] RESTART BOT" << endl << "[3] END BOT" << endl;
		cout << "To continue, just select a number from the list." << endl;
		cout << "Your option: ";
		cin >> option_faq;
		if (option_faq == 1) { //If else statement for option_faq
			cout << "Thanks for the information. My Human Agents will contact you in just a minute." << endl;
		}
		else if (option_faq == 2) {
			goto beginning;
		}
		else if (option_faq == 3) {
			return 0;
		}
	}
	else {
		cout << "Wrong input! Please enter only the given numbers. Let's try again." << endl; //Detect wrong input, let user to try again
		goto beginning;
	}
	

	return 0;
}
