// Adam Gemperline
// CPSC 301-03

#include "person.h"

Person::Person()
{
}

void Person::setLastName(string lName)
{
  lastName = lName;
}


string Person::getLastName()
{
  return lastName;
}


void Person::setFirstName(string fName)
{
  firstName = fName;
}


string Person::getFirstName()
{
  return firstName;
}


void Person::setPayRate(float rate)
{
  payRate = rate;
}


float Person::getPayRate()
{
  return payRate;
}

void Person::setHoursWorked(float hours)
{
  hoursWorked = hours;
}

float Person::getHoursWorked()
{
  return hoursWorked;
}

float Person::totalPay()
{
  float totalPay = hoursWorked * payRate;
  return totalPay;
}

string Person::fullName()
{
  string fullName = firstName + " " + lastName;
  return fullName;
}


void Person::setEmployeeId(int id)
{
  employeeID = id;
}


int Person::getEmployeeId()
{
  return employeeID;
}


void Person::setCompanyName(string coName)
{
  companyName = coName;
}


string Person::getCompanyName()
{
  return companyName;
}
