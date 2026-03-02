#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
   
    string fullName;          
    string birthDate;          
    string phone;              
    string city;               
    string country;            

    
    string universityName;     
    string univCity;           
    string univCountry;        

    string groupNumber;       

public:
    void inputData();
    void outputData() const;

    string getFullName() const;
    string getBirthDate() const;
    string getPhone() const;
    string getCity() const;
    string getCountry() const;
    string getUniversityName() const;
    string getUnivCity() const;
    string getUnivCountry() const;
    string getGroupNumber() const;

    void setFullName(const string& name);
    void setBirthDate(const string& date);
    void setPhone(const string& phoneNumber);
    void setCity(const string& studentCity);
    void setCountry(const string& studentCountry);
    void setUniversityName(const string& uniName);
    void setUnivCity(const string& city);
    void setUnivCountry(const string& country);
    void setGroupNumber(const string& group);
};

#endif
