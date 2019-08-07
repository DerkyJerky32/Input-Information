// Derrick Demers
// 8/6/19
// Input Information Program
// This program gets information from a user and puts it into a txt file
// OR it can take information from a txt file and shows it tot he user

#include <iostream>
#include <fstream> // allows us to use files
#include <string>
#include <Windows.h> // that's for a suprise ;)


using namespace std;

int main() {

	string firstName, lastName, jobTitle, employer, empID, email;
	int age;
	ifstream inFile;
	inFile.open("Info.txt"); //opens a file

	char choice, yesOrNo;

	cout << "Hello there. Would you like to enter new employee " << endl
		<< "information OR would you like to take it from a file?" << endl
		<< "(a) enter new information " << endl
		<< "(b) take from a file " << endl
		<< "Choice: ";
	cin >> choice;
	cout << endl;

	if (choice == 'a')
	{
		ofstream outputFile; // let's the program know it's going to write things into a file
		outputFile.open("InputInfo.txt"); // calls the file and opens it
		cout << "Let's begin with entering the following..." << endl << endl;
		cout << "First Name: ";
		cin >> firstName;
		outputFile << "First Name: " << firstName << endl; //writes to file
		cout << "Last Name: ";
		cin >> lastName;
		outputFile << "Last Name: " << lastName << endl;
		cout << "Age: ";
		cin >> age;
		outputFile << "Age: " << age << endl;
		cin.ignore();
		cout << "Job: ";
		getline(cin, jobTitle);
		outputFile << "Job: " << jobTitle << endl;
		cout << "Employer: ";
		cin >> employer;
		outputFile << "Employer: " << employer << endl;
		cout << "Employee ID: ";
		cin >> empID;
		outputFile << "Employee ID: " << empID << endl;
		cout << "Email Address: ";
		cin >> email;
		outputFile << "Email Address: " << email << endl;
		cout << endl << endl;

		system("pause"); // "Press any key to continue..."

		cout << "Information gathered..." << endl << endl;

		cout << "Name: " << firstName << " " << lastName << endl
			<< "Age: " << age << endl << "Job: " << jobTitle << endl
			<< "Employer: " << employer << endl << "Employee ID: " << empID << endl
			<< "Email: " << email << endl; // prints it all out

		cout << "So " << firstName << "..." << endl;
		system("pause");

		cout << "Would you like to hire me? (Y/N)" << endl << "Choice: ";
		cin >> yesOrNo;
		if (yesOrNo == 'n')
		{
			do
			{
				cout << "Oh...you sure?" << endl;
				system("pause");
				cout << "Would you like to hire me? (Y/N) " << endl << "Choice: ";
				cin >> yesOrNo;
			} while (yesOrNo == 'n');
		} // loops until the user inputs 'y'
		cout << "Wonderful!!" << endl << endl;
		system("pause");
		ShellExecute(0, 0, L"https://derrickdemers.weebly.com/", 0, 0, SW_SHOW); // opens a web browser and directs the user to my website

	}

	if (choice == 'b')
	{
		if (inFile.fail()) {
			cerr << "Error opening file" << endl;
			exit(1);
		} //checks for file


		inFile >> firstName >> lastName >> age >> jobTitle >> employer >> empID >> email; // takes information from the file
		cout << "Name: " << firstName << " " << lastName << endl
			<< "Age: " << age << endl << "Job: " << jobTitle << endl
			<< "Employer: " << employer << endl << "Employee ID: " << empID << endl
			<< "Email: " << email << endl << endl; //shows the user the file information

		cout << "So " << firstName << "..." << endl;
		system("pause");

		cout << "Would you like to hire me? (Y/N)" << endl << "Choice: ";
		cin >> yesOrNo;
		if (yesOrNo == 'n')
		{
			do
			{
				cout << "Oh...you sure?" << endl;
				system("pause");
				cout << "Would you like to hire me? (Y/N) " << endl << "Choice: ";
				cin >> yesOrNo;
			} while (yesOrNo == 'n');
		}
		cout << "Wonderful!!" << endl << endl;
		system("pause");
		ShellExecute(0, 0, L"https://derrickdemers.weebly.com/", 0, 0, SW_SHOW);


		return 0;
	}
}
