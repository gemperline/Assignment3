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
  float  hours;
  float  pay;
  // create a person object, set read data to class memebers
  Person p;

  ifstream inFile;
  inFile.open("input.txt");

  if (inFile.is_open())
  {
    cout << "File opened successfully ..." << endl;
    cout << "Reading from input file ..." << endl;

    while(inFile >> fName)
    {
      inFile >> lName >> hours >> pay;

      p.setFirstName(fName);
      p.setLastName(lName);
      p.setHoursWorked(hours);
      p.setPayRate(pay);
      p.push_back(P);

      // count the number of people in input file
      numPeople++;
    }
    inFile.close();
  }
  else
    cout << "ERROR: could not open file ..." << endl;
}


void writeData(vector<Person> &P, string fileName, int numPeople)
{
  ofstream outFile;
  outFile.open(fileName);

  cout << "Writing to output file ..." << endl;

  for(int i = 0; i < P.size(); i++)
  {
    outFile << p.getFirstName() << " " << fixed << setprecision(2) << p.getHoursWorked() << endl;
  }
  outFile.close();
  cout << "Output file complete ..." << endl;
}


int main()
{
  int numPeople = 0;

  // create an array of 20 empty people
  vector<Person> employees;

  // read the data from input file into the array
  readData(employees, "input.txt", numPeople);

  // write data to an output file
  writeData(employees, "output.txt", numPeople);

  cout << "Exiting ..." << endl;
  return 0;
}
