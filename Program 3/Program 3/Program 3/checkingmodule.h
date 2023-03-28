#pragma once
#include <string>
using namespace std;

void PrintCustomersData(string userID[], string userFirstName[], string userLastName[], double userSaving[], double userChecking[], int personNum);
//The function takes in the arrays and array size for ID, first name, last name, savings, and checking
//All of the array data is output

void PrintNames(string userFirstName[], string userLastName[], int personNum);
//The function takes the arrays and array size for last name and first name
//The names are output alphabeticaly by first name

void PrintBankTotal(string userID[], double userSaving[], double userChecking[], int personNum);
//The function takes in the arrays and array size for ID, saving, and checking
//The savings, checking, and total is output for each ID as well as a grand total at the end

void PrintMenu();
//The function takes no parameters
//A menu is output to the user