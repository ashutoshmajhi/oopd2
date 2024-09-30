#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_PERSONS 100
#define MAX_FACULTY 5
#define MAX_DEPARTMENTS 5

using namespace std;

void convertToLower(char* str) {
    for (int i = 0; str[i]; ++i) str[i] = tolower(str[i]);
}

class Person {
public:
    char name[100];
    char role[200];
    char office[100];
    char contact[20];

    Person() {}

    Person(const char* nm, const char* rl, const char* ofc, const char* tel) {
        strcpy(name, nm);
        strcpy(role, rl);
        strcpy(office, ofc);
        strcpy(contact, tel);
    }

    virtual void displayContactInfo() {
        cout << "Office: " << office << ", Contact: " << contact << endl;
    }
};

// Derived class for an Administrative Officer
class AdminOfficer : public Person {
public:
    AdminOfficer(const char* nm, const char* rl, const char* ofc, const char* tel)
        : Person(nm, rl, ofc, tel) {}
};

// Derived class for a Faculty member
class Faculty : public Person {
public:
    Faculty(const char* nm, const char* rl, const char* ofc, const char* tel)
        : Person(nm, rl, ofc, tel) {}
};

// Class representing a Department containing an Administrative Officer and Faculty members
class Department {
private:
    AdminOfficer* adminOfficer;
    Faculty* facultyList[MAX_FACULTY];
    const char* departmentName;

public:
    Department(AdminOfficer* ao, Faculty* facultyMembers[MAX_FACULTY], const char* deptName) {
        adminOfficer = ao;
        departmentName = deptName;
        for (int i = 0; i < MAX_FACULTY; ++i) facultyList[i] = facultyMembers[i];
    }

    bool searchPersonContact(const char* personName) {
        char loweredAdmin[100];
        strcpy(loweredAdmin, adminOfficer->name);
        convertToLower(loweredAdmin);

        char loweredPersonName[100];
        strcpy(loweredPersonName, personName);
        convertToLower(loweredPersonName);


        if (strcmp(loweredAdmin, loweredPersonName) == 0) {
            cout << personName << " is the Administrative Officer in " << departmentName << ":\n";
            adminOfficer->displayContactInfo();
            return true;
        }


        for (int i = 0; i < MAX_FACULTY; ++i) {
            char loweredFaculty[100];
            strcpy(loweredFaculty, facultyList[i]->name);
            convertToLower(loweredFaculty);

            if (strcmp(loweredFaculty, loweredPersonName) == 0) {
                cout << personName << " is a Faculty member in " << departmentName << ":\n";
                facultyList[i]->displayContactInfo();
                return true;
            }
        }
        return false;
    }


    ~Department() {
        delete adminOfficer;
        for (int i = 0; i < MAX_FACULTY; ++i) delete facultyList[i];
    }
};


void initializeDepartments(Department* departments[MAX_DEPARTMENTS]) {
    // CSE Department
    AdminOfficer* adminCSE = new AdminOfficer("Sambuddho", "Head (CSE)", "Room B-503", "011-26907478");
    Faculty* facultyCSE[MAX_FACULTY] = {
        new Faculty("Rinku Shah", "Asst Prof", "Room B-502", "011-26907538"),
        new Faculty("Arani Bhattacharya", "Asst Prof", "Room B-510", "011-26907434"),
        new Faculty("Debajyoti Bera", "Assoc Head", "Room B-508", "011-26907442"),
        new Faculty("Saket Anand", "Asst Prof", "Room B-410", "011-26907425"),
        new Faculty("Vinayak Abrol", "Asst Prof", "Room B-409", "011-26907543")
    };
    departments[0] = new Department(adminCSE, facultyCSE, "CSE Dept");

    // ECE Department
    AdminOfficer* adminECE = new AdminOfficer("A V Subramanyam", "Head (ECE)", "Room B-604", "011-26907437");
    Faculty* facultyECE[MAX_FACULTY] = {
        new Faculty("Sujay Deb", "Prof (ECE)", "Room 201", "987-654-3210"),
        new Faculty("Abhijit Mitra", "Asst Prof", "Room A-605", "011-26907450"),
        new Faculty("Debidas Kundu", "Asst Prof", "Room A-606", "011-26907465"),
        new Faculty("Shobha Sundar Ram", "Assoc Prof", "Room A-606", "011-26907460"),
        new Faculty("Tammam Tillo", "Prof", "Room A-602", "011-26907366")
    };
    departments[1] = new Department(adminECE, facultyECE, "ECE Dept");

    // CB Department
    AdminOfficer* adminCB = new AdminOfficer("G.P.S. Raghava", "Head (CB)", "Room A-302", "011-26907444");
    Faculty* facultyCB[MAX_FACULTY] = {
        new Faculty("Gaurav Ahuja", "Assoc Prof", "Room A-303", "011-26907475"),
        new Faculty("Ganesh Bagler", "Prof", "Room A-305", "011-26907443"),
        new Faculty("Vibhor Kumar", "Assoc Prof", "Room A-304", "011-26907440"),
        new Faculty("Sriram K", "Assoc Prof", "Room A-308", "011-26907436"),
        new Faculty("Tavpritesh Sethi", "Assoc Prof", "Room A-309", "011-26907533")
    };
    departments[2] = new Department(adminCB, facultyCB, "CB Dept");

    // HCD Department
    AdminOfficer* adminHCD = new AdminOfficer("Arjun Ray", "Asst Prof", "Room A-310", "011-26907438");
    Faculty* facultyHCD[MAX_FACULTY] = {
        new Faculty("Debika Banerjee", "Asst Prof", "Room B-310", "011-26907358"),
        new Faculty("Monika Arora", "Asst Prof", "Room A-304", "011-26907587"),
        new Faculty("Rajiv Raman", "Assoc Prof", "Room B-507", "011-26907573"),
        new Faculty("Prahllad Deb", "Asst Prof", "Room B-305", "011-26907551"),
        new Faculty("Anuradha Sharma", "Prof", "Room B-311", "011-26907534")
    };
    departments[3] = new Department(adminHCD, facultyHCD, "HCD Dept");

    // SSH Department
    AdminOfficer* adminSSH = new AdminOfficer("J. V. Meenakshi", "Head (SSH)", "Room B-205", "011-26907535");
    Faculty* facultySSH[MAX_FACULTY] = {
        new Faculty("Aasim Khan", "Asst Prof", "Room B-202", "011-26907463"),
        new Faculty("Paro Mishra", "Asst Prof", "Room B-209", "011-26907570"),
        new Faculty("Deepak Prince", "Asst Prof", "Room A-210", "011-26907595"),
        new Faculty("Kiriti Kanjilal", "Asst Prof", "Room B-208", "011-26907558"),
        new Faculty("Ruhi Sonal", "Asst Prof", "Room A-211", "011-26907556")
    };
    departments[4] = new Department(adminSSH, facultySSH, "SSH Dept");
}

int main() {
    Department* departments[MAX_DEPARTMENTS] = {nullptr};

    initializeDepartments(departments);
    char personName[100];
    cout << "Enter the name of the person you're searching for: ";
    cin.getline(personName, 100);

    convertToLower(personName);

    bool personFound = false;
    for (int i = 0; i < MAX_DEPARTMENTS && !personFound; ++i) {
        if (departments[i]) {
            personFound = departments[i]->searchPersonContact(personName);
        }
    }

    if (!personFound) {
        cout << personName << " not found in any department.\n";
    }

    return 0;
}
