#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

#include "person.cpp"

int readData(vector<Person> &P, string fileName, int &numPeople)
{
  string fName;
  string lName;
  float  hours;
  float  pay;

  ifstream inFile;
  inFile.open("input.txt");

  if (inFile.is_open())
  {
    cout << "File opened successfully ..." << endl;
    cout << "Reading from input file ..." << endl;

    while(inFile >> fName)
    {
      inFile >> lName >> hours >> pay;

      P.setFirstName(fName);
      P.setLastName(lName);
      P.setHoursWorked(hours);
      P.setPayRate(pay);

      numPeople++;
    }
    inFile.close();
  }
  else
    cout << "ERROR: could not open file ..." << endl;

    return numPeople;
}


void writeData(vector<Person> &P, string fileName, int numPeople)
{
  ofstream outFile;
  outFile.open(fileName);

  cout << "Writing to output file ..." << endl;

  for(int i = 0; i < P.size(); i++)
  {
    outFile << P.fullName() << " " << fixed << setprecision(2) << P.totalPay() << endl;
  }
  outFile.close();
  cout << "Output file complete ..." << endl;
}


int main()
{
  int numPeople = 0;

  // create an array of 20 empty people
  typedef vector<Person> employees;

  // read the data from file into the array
  readData(employees, "input.txt", numPeople);
  // write data to an output file
  writeData(employees, "output.txt", numPeople);

  cout << "Exiting ..." << endl;
  return 0;
}
