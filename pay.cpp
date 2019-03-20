// Adam Gemperline
// CPSC 301-03


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

#include "person.cpp"



void readData(vector<Person> &P, string fileName, int &numPeople)
{
  string fName;
  string lName;
  int empID;
  string company;
  float  hours;
  float  pay;
  // create a person object to set read data to class memebers
  Person p;

  ifstream inFile;
  inFile.open("input.txt");

  if (inFile.is_open())
  {
    cout << "File opened successfully ..." << endl;
    cout << "Reading from input file ...\n" << endl;

    while(inFile >> fName)
    {
      inFile >> lName >> empID >> company >> hours >> pay;

      p.setFirstName(fName);
      p.setLastName(lName);
      p.setEmployeeId(empID);
      p.setCompanyName(company);
      p.setHoursWorked(hours);
      p.setPayRate(pay);

      //push this object to the end of the vector
      P.push_back(p);
      // count the number of people in input file
      numPeople++;
    }
    cout << endl;
    inFile.close();
  }
  else
    cout << "ERROR: could not open file ..." << endl;
}



void writeData(vector<Person> &P, string fileName)
{
  ofstream outFile;
  outFile.open(fileName);

  cout << "Writing to output file ..." << endl;
  cout << "Array size is " << P.size() << endl;

// loop to write data to output file
  for(int i = 0; i < P.size(); i++)
  {
    outFile << left << setw(8) << P[i].getFirstName() << " " << left << setw(9) << P[i].getLastName()
            << " " << right << setw(3) << P[i].getEmployeeId() << " " << left << setw(10) << P[i].getCompanyName()
            << " " << left << setw(4) << fixed << setprecision(2) << P[i].getHoursWorked()
            << "  " << left << setw(4) << P[i].getPayRate() << " " << endl;
  }
  outFile.close();
  cout << "Output file complete ..." << endl;
}



void getCompanies(vector<Person> &P, vector<string> &C)
{
  string company;
  string s;
  for(int i = 0; i < P.size(); i++)
  {
    company = P[i].getCompanyName();
    C.push_back(company);
  }
}



void printHighestPaid(vector<Person> &P)
{
  double totalPay;
  int highesPaid;
/*
  while(i < P.size() && j < P.size())
  {
    if((P[i].getPayRate() * P[i].getHoursWorked()) > (P[j].getPayRate() * P[j].getHoursWorked()))
    {
      highestPaid = i;
      j++;
    }
    else if((P[i].getPayRate() * P[i].getHoursWorked()) < (P[j].getPayRate() * (P[j].getHoursWorked()))
    {
      i = j;
      highestPaid = j;
      j++;
    }
    else
      cout << "There are two people with the same total pay." << endl;
  }

  totalPay = P[highestPaid].getPayRate() * P[highestPaid].getHoursWorked();
  cout << "Total pay: " << totalPay << endl;
*/

  for(int i = 0, j = 1; j <= P.size(); j++)
  {
    double totalPay_i = P[i].getPayRate() * P[i].getHoursWorked();
    double totalPay_j = P[j].getPayRate() * P[j].getHoursWorked();

    if(totalPay_i < totalPay_j)
    {
      // move i cursor to j
      i = j;
      highestPaid =  j;
      totalPay = totalPay_j;
    }
    else if(totalPay_i > totalPay_j)
    {
      highestPaid = i;
      totalPay = totalPay_i;
    }
    else
      cout << "There are two people with the same total pay." << endl;
  }

  cout << "Highest Paid: " << P[highesPaid].getFirstName() << " " << P[highestPaid].getLastName() << endl;
  cout << "Employee ID: " << P[highesPaid].getEmployeeId() << endl;
  cout << "Employer: " << P[highesPaid].getCompanyName() << endl;
  cout << "Total Pay: " << totalPay;
}



int main()
{
  int numPeople = 0;

  // create a dynamic vector of type Person to store employee data (can grow in size b/c its a vector)
  vector<Person> employees;
  // create a dynamic vector to hold string names
  vector<string> companyNames;

  // read the data from input file into the array
  readData(employees, "input.txt", numPeople);
  cout << "Number of people from read : " << numPeople << endl;

  // write data to an output file
  writeData(employees, "output.txt");

  // retrieve company names from employees  vector and store in company names vector
  getCompanies(employees, companyNames);

  // find and print the highest paid employee
  printHighestPaid(employees);

  cout << "Exiting ..." << endl;
  return 0;
}
