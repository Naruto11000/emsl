#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
#include<conio.h>
#include<cstdlib>

using namespace std;

class EmployeeManagement{
    string firstName, lastName, designation;
    char ID[5];
    int CTC, pin, experience, day, month, year, searchID;
    char gender;

public:
    void newEmployee();
    void displayInformation();
    void changeInformation();
    void searchEmployee();
    void deleteEmployeeRecord();
    void Home();
};
void EmployeeManagement::newEmployee(){
system("cls");
    char choice;
    ofstream searchData;
    searchData.open("records.txt", ios::app);

    do{
        cout << "Enter First Name : ";
        cin >> firstName;
        cout << "Enter Last Name : ";
        cin >> lastName;
        cout << "Enter Employee ID : ";
        cin >> ID;
        cout << "Enter DOB : ";
        cin >> day >> month >> year;
        cout << "Enter Gender : ";
        cin >> gender;
        cout << "Enter Experience : ";
        cin >> experience;
        cout << "Enter Designation : ";
        cin >> designation;
        cout << "Enter CTC : ";
        cin >> CTC;
        cout << "Setup your pin [max 6 digits] : ";
        cin >> pin;
        cout << "Employee Details Have Been Registered Successfully :)" << endl;

        searchData << "ID : " << ID << " NAME : " << firstName << " " << lastName << " DESIGNATION : " << designation << " D.O.B : " << day << "-" << month << "-" << year;
        searchData << " GENDER : " << gender << " EXPERIENCE : " << experience << " C.T.C : " << CTC << " PIN : " << pin << endl;
        searchData.close();
        cout << "Do You Want To Enter Details Of Another Employee [y/n] : ";
        cin >> choice;
    }while(choice == 'y' || choice == 'Y');


        cout << "Do you Want to Go Back to HOME Page [y/n]" << endl;
        cin >> choice;

        if(choice == 'y' || choice == 'Y'){
        Home();
        }
        else{
            //exit();
            return;
        }
}

void EmployeeManagement::displayInformation(){
    char choice;
    ifstream showData;
    showData.open("records.txt");
    string s;
    while(showData.eof() == 0) {
        getline(showData, s);
        cout << s << endl;
    }
    showData.close();

    while (true) {
            cout << "Do You Want To Go Back To HOME Page [y/n] : ";
            cin >> choice;

        if(choice == 'y' || choice == 'Y') {
            Home();
        }
        else if ( choice == 'N' || choice == 'n' ) {
            return;
        }
        else {
            cout << "!!! INVALID CHOICE !!!\n";
            continue;
        }
    }
}

void EmployeeManagement::changeInformation(){

    int c = 0;
    char another = 'y' ;
    fstream searchData, update;
    searchData.open("records.txt");
    string st;
    if(searchData.eof() != 0){
        cout << "NO Records Present :(" << endl;
        searchData.close();
    }

    else{
        char searchID[5];
        cout << "Enter ID : ";
        cin >> searchID;
        update.open("Employee_Record.txt");
        while(searchData.eof()==0){

            if(strcmp(searchID, ID) == 0){
                    c++;
                    cout << "Enter First Name : ";
                    cin >> firstName;
                    cout << "Enter Last Name : ";
                    cin >> lastName;
                    cout << "Enter Employee ID : ";
                    cin >> ID;
                    cout << "Enter DOB : ";
                    cin >> day >> month >> year;
                    cout << "Enter Gender : ";
                    cin >> gender;
                    cout << "Enter Experience : ";
                    cin >> experience;
                    cout << "Enter Designation : ";
                    cin >> designation;
                    cout << "Enter CTC : ";
                    cin >> CTC;
                    cout << "Setup your pin [max 6 digits] : ";
                    cin >> pin;
                    update << "ID : " << ID << " NAME : " << firstName << " " << lastName << " DESIGNATION : " << designation << " D.O.B : " << day << "-" << month << "-" << year;
                    update << " GENDER : " << gender << " EXPERIENCE : " << experience << " C.T.C : " << CTC << " PIN : " << pin << endl;
            }
            else {
                update << "ID : " << ID << " NAME : " << firstName << " " << lastName << " DESIGNATION : " << designation << " D.O.B : " << day << "-" << month << "-" << year;
                update << " GENDER : " << gender << " EXPERIENCE : " << experience << " C.T.C : " << CTC << " PIN : " << pin << endl;
            }
            getline(searchData, st);
        }
        if(c == 0){
            cout << "NO Data With ID " << searchID << " found\n";
            Home();
        }
        update.close();
        searchData.close();
        delete("records.txt");
        char oldName[] = "Employee_Record.txt";
        char newName[] = "records.txt";
        rename(oldName, newName);


        cout << "Employee Details Are Updated Successfully  ;-)" << endl << "Do You Want To See Employee Information [y/n] " << endl;
        cin >> another;

        if(another == 'y' || another == 'Y'){
            displayInformation();
        }
        else{
            Home();
        }
    }


}

void EmployeeManagement::deleteEmployeeRecord(){
    char searchID[5];
    string st;
    string* h;

    cout << "Enter Employee ID : ";
    cin >> searchID;

    fstream getData;
    getData.open("records.txt");
    if(getData.eof() != 0){
        cout << "NO DATA PRESENT" << endl;
        getData.close();
    }
    else {

        while(getData.eof() == 0){
                getline(getData, st);
                if(strcmp(searchID, ID) == 0){
                    cout << 1 << " ";
                    delete(&st);
                }

        }
        getData.close();
    }
}
void EmployeeManagement::searchEmployee(){


    cout << "NAME : " << firstName << " " << lastName << endl;
    cout << "ID : " << ID << endl;
    cout << "EXPERIENCE : " << experience << endl;
    cout << "DESIGNATION : " << designation << endl;
    cout << "CTC  : " << CTC << endl;

}
void EmployeeManagement::Home(){

    int choice;

    cout << "1. Enter Details Of New Employee. " << endl;
    cout << "2. View Details Of All Employee. " << endl;
    cout << "3. Search For An Employee. " << endl;
    cout << "4. Modify Details Of An Employee. " << endl;
    cout << "5. Delete Record Of An Employee. " << endl;
    cout << "6. EXIT " << endl;

    cout << "What Do You Want To Do : [1/2/3/4/5/6] : ";
    cin >> choice;

    switch(choice){
    case 1:
        newEmployee();
        break;

    case 2:
        displayInformation();
        break;

    case 3:
        searchEmployee();
        break;

    case 4:
        changeInformation();
        break;

    case 5:
        deleteEmployeeRecord();
        break;

    case 6:
        return;

    default:
        cout << "!!! INVALID CHOICE !!!" << endl;
        break;

    }
}

int main(){
    EmployeeManagement Employee;
    Employee.Home();
return 0;

}
