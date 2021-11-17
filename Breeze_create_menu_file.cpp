#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;


int main() {
	string number, name, price;
	string file_name;

	cout << "Insert your desired filename(Without space): " << endl;
	cout << "Filename: ";
	cin >> file_name;
	cout << "Enter '0 0 0' to end this function: " << endl;
	for (;;) {
		cout << "Enter serial number, name and price of your item accordingly: " << endl;
		cin >> number >> name >> price;
		if (number == "0" && name == "0" && price == "0") break;
		ofstream out((file_name+".txt"), ios::app);
		out << std::left << setw(23) << number;
		out << std::left << setw(45) << name;
		out << std::left << setw(22) << price << endl;
	}
}