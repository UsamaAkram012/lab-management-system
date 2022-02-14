/*
			Name:			Usama Akram
			Roll Number:	bitf19m514
			Task 1 (Home Work Number 1)
			Function:       Lab management System
*/
#include<iostream>
#include<iomanip>
using namespace std;

bool isexist_search(int id, int lab, int pc, int** array) {    //check the location of user for search purposes
	for (int i = lab; i < pc; i++) {
		if (array[lab][i] == id) {
			cout << "The user exist in lab " << lab + 1 << " at Pc " << i + 1 << endl;
			return true;
		}
	}
	return false;
}
void sub_display(int** array, int iteration, int a) {     //sub_display for labs 
	cout << "Lab " << a + 1 << ":\t";
	for (int i = 0; i < iteration; i++)
	{
		if (array[a][i] == 0)
			cout << "(" << i + 1 << ") empty ";			//displaying empty at loction containing zero
		else
			cout << "(" << i + 1 << ")" << array[a][i] << " ";   // dispplaying roll number instead of zero
	}
}
bool isexist_login(int lab_no, int pc_no) {			//check either login exist or not
	if (lab_no == 1) { if (pc_no >= 1 && pc_no <= 5) return true; }				// for lab 1 and return value
	if (lab_no == 2) { if (pc_no >= 1 && pc_no <= 6) return true; }				// for lab 2 and return value
	if (lab_no == 3) { if (pc_no >= 1 && pc_no <= 4) return true; }				// for lab 3 and return value
	if (lab_no == 4) { if (pc_no >= 1 && pc_no <= 3) return true; }				// for lab 4 and return value
	return false;   // return if login does not exist
}
void init(int** array, int iteration, int a) {  // initilizing array by zero.
	for (int i = 0; i < iteration; i++) {
		array[a][i] = 0;
	}
}
void display(int** array) {    // display ftn
	int iter = 5, Lab_no = 0;
	cout << setw(36) << "Lab Directory\n";
	sub_display(array, iter, Lab_no);    //call to sub-display for lab 1
	cout << endl;
	sub_display(array, iter + 1, Lab_no + 1);      //call to sub-display for lab 2
	cout << endl;
	sub_display(array, iter - 1, Lab_no + 2);        //call to sub-display for lab 3
	cout << endl;
	sub_display(array, iter - 2, Lab_no + 3);      //call to sub-display for lab 4
	cout << endl;
}
void log_In(int** array) {    // ftn for loging in 
	int id, lab_no, pc_no;
	cout << "Enter your Five digit id, lab no. and station number: ";
	cin >> id >> lab_no >> pc_no;
loop0:
	if (id < 10000 || id>99999) {     // checking valid ID
		cout << "Invalid Id No...!Enter five digit ID: ";
		cin >> id;
		goto loop0;
	}
loop1:
	if (lab_no < 0 || lab_no>4) {    // checking valid Lab no.
		cout << "Invalid Lab no...!Enter value (1-4): ";
		cin >> lab_no;
		goto loop1;
	}
loop3:
loop7:
	if (isexist_login(lab_no, pc_no)) {		// checking valid station no.
		if (array[lab_no - 1][pc_no - 1] == '\0') {
			array[lab_no - 1][pc_no - 1] = id;
			cout << "You have been Successfully login to the PC no. " << pc_no << " of Lab no. " << lab_no << endl;
		}
		else {
			cout << "User already exists at this Position...Log in to any other Pc Number: ";
			cin >> pc_no;
			goto loop7;
		}
	}
	else {
		cout << "Invalid input...!PC does not exist. Login to any other station: ";
		cin >> pc_no;
		goto loop3;
	}
}
void log_Out(int** array) {    //ftn for loging out
	int id, lab_no, pc_no;
	cout << "Enter Lab no. and Station no. you want to log out: ";
	cin >> lab_no >> pc_no;
loop4:
	if (lab_no < 0 || lab_no>4) {        //checking valid lab no.
		cout << "Invalid Lab no...!Enter value (1-4): ";
		cin >> lab_no;;
		goto loop4;
	}
loop5:
	if (isexist_login(lab_no, pc_no)) {     //checking valid station no.
		if (array[lab_no - 1][pc_no - 1] != '\0') {
			array[lab_no - 1][pc_no - 1] = 0;
			cout << "You have been Successfully log out of the PC no. " << pc_no << " of Lab no. " << lab_no << endl;
		}
		else {
			cout << "No one has been Log In to this Place....\n";
		}
	}
	else {
		cout << "Invalid input...!PC does not exist.Input correct station Number: ";
		cin >> pc_no;
		goto loop5;
	}
}
void search(int** array) {    //ftn to check the user existence
	int id;
	cout << "Enter the ID you want to search in database: ";
	cin >> id;
	if (isexist_search(id, 0, 5, array)) {}   //searching in lab 1
	else if (isexist_search(id, 1, 6, array)) {}			 //searching in lab 2
	else if (isexist_search(id, 2, 4, array)) {}			 //searching in lab 3
	else if (isexist_search(id, 3, 3, array)) {}			//searching in lab 4
	else {   // if no user exist
		cout << "User does not exist in our DataBase: \n";
	}
}
void admin_menu() {		// admin Menu
	cout << setw(70) << "=============================" << endl;
	cout << setw(65) << "Administrator Menu" << endl;
	cout << setw(70) << "=============================" << endl;
	int choice_num[5] = { 01,02,03,04,05 };
	string choice_name[14] = { "Log In","Log Out","Search","View Directory","Main Menu", };
	for (int i = 0; i < 5; i++) {
		cout << setw(50) << choice_num[i] << "  " << choice_name[i] << endl;
	}
}
void main_menu() {			// Main Menu
	cout << setw(70) << "=============================" << endl;
	cout << setw(60) << "Main Menu" << endl;
	cout << setw(70) << "=============================" << endl;
	int choice_num[5] = { 01,02,03 };
	string choice_name[14] = { "As Administrator","As User","Quit" };
	for (int i = 0; i < 3; i++) {
		cout << setw(50) << choice_num[i] << "  " << choice_name[i] << endl;
	}
}
void user_menu() {			// User Menu
	cout << setw(70) << "=============================" << endl;
	cout << setw(60) << "User Menu" << endl;
	cout << setw(70) << "=============================" << endl;
	int choice_num[5] = { 01,02,03 };
	string choice_name[14] = { "Log In","Log Out","Main Menu" };
	for (int i = 0; i < 3; i++) {
		cout << setw(50) << choice_num[i] << "  " << choice_name[i] << endl;
	}
}
void case_1(int** array) {    //for admin
	int choice;
	while (1) {
		cout << "Enter your choice: ";
	loop1:
		cin >> choice;
		if (choice < 0 || choice>5) {
			cout << "Invalid choice....!\nEnter choice again: ";
			goto loop1;
		}
		switch (choice) {
		case 1:
			log_In(array);
			system("PAUSE");
			system("CLS");
			admin_menu();
			break;
		case 2:
			log_Out(array);
			system("Pause");
			system("CLS");
			admin_menu();
			break;
		case 3:
			search(array);
			system("Pause");
			system("CLS");
			admin_menu();
			break;
		case 4:
			display(array);
			system("Pause");
			system("CLS");
			admin_menu();
			break;
		case 5:
			return;
		}
	}
}
void case_2(int** array) {     // for user
	int choice;
	while (1) {
		cout << "Enter your choice: ";
	loop1:
		cin >> choice;
		if (choice < 0 || choice>3) {
			cout << "Invalid choice....!\nEnter choice again: ";
			goto loop1;
		}
		switch (choice) {
		case 1:
			log_In(array);
			system("PAUSE");
			system("CLS");
			user_menu();
			break;
		case 2:
			log_Out(array);
			system("Pause");
			system("CLS");
			user_menu();
			break;
		case 3:
			return;
		}
	}
}
int main() {
	int** array = new int* [4];    //decalring rows of 2D_Array
	int lab = 0, pc = 5, choice;
	array[lab] = new int[pc];                //decalring rows of 2D_Array at row index 0
	array[lab + 1] = new int[pc + 1];		 //decalring rows of 2D_Array at row index 1
	array[lab + 2] = new int[pc - 1];		 //decalring rows of 2D_Array at row index 3
	array[lab + 3] = new int[pc - 2];		 //decalring rows of 2D_Array at row index 4
	init(array, pc, lab);				//calling ftn to initiliaze 0 in lab 1
	init(array, pc + 1, lab + 1);		//calling ftn to initiliaze 0 in lab 2
	init(array, pc - 1, lab + 2);		//calling ftn to initiliaze 0 in lab 3
	init(array, pc - 2, lab + 3);		//calling ftn to initiliaze 0 in lab 4
	while (1) {
		system("CLS");
		main_menu();
		cout << "You want to continue as: ";
	loop6:
		cin >> choice;
		if (choice < 0 || choice>3) {
			cout << "Invalid Input......Enter choice again: ";
			goto loop6;
		}
		switch (choice) {
		case 1:
			system("CLS");
			admin_menu();
			case_1(array);
			break;
		case 2:
			system("CLS");
			user_menu();
			case_2(array);
			break;
		case 3:
			return 0;
		}
	}
	for (int i = 0; i < 4; i++) {  //deleting dynamic array
		delete[] array[i];
	}
	delete[] array;
}