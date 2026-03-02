#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    char* fullName;              
    string birthDate;            
    string phone;                
    string city;                 
    string country;              
    string universityName;       
    string univCity;             
    string univCountry;         
    string groupNumber;          

public:
    
    Student();                                           
    Student(const char* name, const string& group);      
    Student(const Student& other);                       

    
    ~Student();

    
    Student& operator=(const Student& other);

    
    inline void inputData();
    inline void outputData() const;

    
    inline const char* getFullName() const;
    inline string getBirthDate() const;
    inline string getPhone() const;
    inline string getCity() const;
    inline string getCountry() const;
    inline string getUniversityName() const;
    inline string getUnivCity() const;
    inline string getUnivCountry() const;
    inline string getGroupNumber() const;

    
    void setFullName(const char* name);
    inline void setBirthDate(const string& date);
    inline void setPhone(const string& phoneNumber);
    inline void setCity(const string& studentCity);
    inline void setCountry(const string& studentCountry);
    inline void setUniversityName(const string& uniName);
    inline void setUnivCity(const string& city);
    inline void setUnivCountry(const string& country);
    inline void setGroupNumber(const string& group);
};

#endif