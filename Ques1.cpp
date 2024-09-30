#include <iostream>
#include <cstring>
#define MAX_PERSONS 100
using namespace std;

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
bool isAlphaString(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') {
            return false;
        }
    }
    return true;
}

class Person {
public:
    char name[100];
    char role[200];
    char roomNumber[100];
    char telephone[20];
    char email[100];

    Person() {}

    Person(const char* n, const char* r, const char* room, const char* tel, const char* mail) {
        strcpy(name, n);
        strcpy(role, r);
        strcpy(roomNumber, room);
        strcpy(telephone, tel);
        strcpy(email, mail);
    }
    
    virtual void displayContact() {
        cout << "Name: " << name << "\nRole: " << role << "\nRoom: " << roomNumber
             << "\nTelephone: " << telephone << "\nEmail: " << email << "\n" << endl;
    }
};

class Registrar : public Person {
public:
    Registrar(const char* name, const char* role, const char* room, const char* tel, const char* email)
        : Person(name, role, room, tel, email) {}

    void displayContact() override {
        cout << "Registrar:\n";
        Person::displayContact();
    }
};

class Dean : public Person {
protected:
    Person* associateDean;

public:
    Dean(const char* name, const char* role,const char* roomno, const char* tel, const char* email)
        : Person(name, role, roomno, tel, email), associateDean(nullptr) {}

    void assignAssociateDean(Person* assocDean) {
        associateDean = assocDean;
    }

    void displayContact() override {
        Person::displayContact();
         if(associateDean)
          {
            cout<<"This dean has an Associate Dean: "<< associateDean->name<<"\n";
          }
    }
};

class AdministrativeOfficer : public Person {
public:
    AdministrativeOfficer(const char* name, const char* role, const char* room, const char* tel, const char* email)
        : Person(name, role, room, tel, email) {}
};

class Officer : public Person {
public:
    Officer(const char* name, const char* role, const char* room, const char* tel, const char* email)
        : Person(name, role, room, tel, email) {}
};

class AdminStructure {
private:
    Person* persons[MAX_PERSONS];
    int personCount;

public:
    AdminStructure() : personCount(0) {}

    void addPerson(Person* p) {
        if (personCount < MAX_PERSONS) {
            persons[personCount++] = p;
        }
    }

      Person* findPerson(const char* name) {
        char lowerInputName[100];
        strcpy(lowerInputName, name);
        toLowerCase(lowerInputName); 

        for (int i = 0; i < personCount; ++i) {
            char lowerPersonName[100];
            strcpy(lowerPersonName, persons[i]->name);
            toLowerCase(lowerPersonName); 

            if (strcmp(lowerPersonName, lowerInputName) == 0) {
                return persons[i];
            }
        }
        return nullptr;
    }
};

void getContactDetails(AdminStructure& adminStructure, const char* personName) {
    Person* person = adminStructure.findPerson(personName);
    if (person) {
        person->displayContact();
    } else {
        cout << "Person not found in the administrative structure.\n";
    }
}

int main() {
    // Initialize the administrative structure
    AdminStructure adminStructure;

    // Adding Registrar
    Registrar registrar("Dr. Deepika Bhaskar", "Registrar", "B-204 (Academic Block)", "+91-11-26907419", "deepika@iiitd.ac.in");
    adminStructure.addPerson(&registrar);

    
    // Adding Deans
    Dean deanIRD("Debarka Sengupta", "Associate Dean of IRD","Room NM" ,"+91-11-26907446", "adird@iiitd.ac.in");
    adminStructure.addPerson(&deanIRD);
     
    Dean deanStudentAffairs("Shobha Sundar Ram", "Dean of Student Affairs", "Room NM", "+91-11-26907460", "dosa@iiitd.ac.in");
    adminStructure.addPerson(&deanStudentAffairs);

    
    Dean deanAcademics("Sumit J Darak", "Dean of Academic Affairs", "Room JKL", "+91-11-26907427", "doaa@iiitd.ac.in");
    adminStructure.addPerson(&deanAcademics);
    Dean associteDeanAcademics("Debarka Sengupta", "Associate Dean of IRD", "Room XYZ", "+91-11-26907446", "adird@iiitd.ac.in");
    deanAcademics.assignAssociateDean(&associteDeanAcademics);
    adminStructure.addPerson(&registrar);
    
    Dean deanResearch("Vivek Ashok Bohara", "Dean of Innovation, Research & Development", "Room MNO", "+91-11-26907454", "dird@iiitd.ac.in");
    adminStructure.addPerson(&deanResearch);

    // Adding IRD department personnel
    Officer imranKhan("Imran Khan", "Junior Administrative Officer (IRD) (SG)", "Room No. A-307 (Academic Block)", "011 26907 594", "imran@iiitd.ac.in");
    adminStructure.addPerson(&imranKhan);
        
    Officer MohitKumar("Mohit Kumar", "Assistant Administrative Officer (IRD) (SG)", "Room No. A-311 (Academic Block)", "011 26907 505", "mohit@iiitd.ac.in");
    adminStructure.addPerson(&MohitKumar);
    
    AdministrativeOfficer kapilDevGarg("Kapil Dev Garg", "Administrative Officer (IRD)", "Room No. A-306 (Academic Block)", "011 26907 119", "kapildev@iiitd.ac.in");
    adminStructure.addPerson(&kapilDevGarg);

    // Adding Academics department personnel
    Officer aakashGupta("Aakash Gupta", "Junior Administrative Officer (Academics)", "Room No. B-207 (Academic Block)", "011 26907 135", "aakash@iiitd.ac.in");
    adminStructure.addPerson(&aakashGupta);

    Officer akanksha("Akanksha", "Junior Administrative Officer (Academics)", "Room No. B-207 (Academic Block)", "011 26907 140", "akanksha@iiitd.ac.in");
    adminStructure.addPerson(&akanksha);

    Officer ashishAggarwal("Ashish Aggarwal", "Junior Administrative Officer (Academics)", "Room No. B-207 (Academic Block)", "011 26907 136", "ashisha@iiitd.ac.in");
    adminStructure.addPerson(&ashishAggarwal);
    
    AdministrativeOfficer anshuDureja("Anshu Dureja", "Deputy Administrative Officer (Academics)", "Room No. B-208 (Academic Block)", "011 26907 507", "anshu@iiitd.ac.in");
    adminStructure.addPerson(&anshuDureja);

    Officer prachiMukherjee("Prachi Mukherjee", "Assistant Administrative Officer (Academics) (SG)", "Room No. B-207 (Academic Block)", "011 26907 545", "prachi@iiitd.ac.in");
    adminStructure.addPerson(&prachiMukherjee);

    Officer AshutoshBrahma("Ashutosh Brahma", " Administrative Officer (Academics) (SG)", "Room No. B-202 (Academic Block)", "011 26907 416", "ashutosh@iiitd.ac.in");
    adminStructure.addPerson(&AshutoshBrahma);

    Officer RajuBiswas("Raju Biswas", "Junior Administrative Officer (Academics) (SG)", "Room No. B-208 (Academic Block)", "011 26907 137", "raju@iiitd.ac.in");
    adminStructure.addPerson(&RajuBiswas);

    Officer SanjanaSoni("Sanjana Soni", "Junior Administrative Officer (Academics) (SG)", "Room No. B-207 (Academic Block)", "011 26907 129", "Sanjanas@iiitd.ac.in");
    adminStructure.addPerson(&SanjanaSoni);

    Officer SudhanshuTamta("Sudhanshu Tamta", "junior Administrative Officer (Academics) (SG)", "Room No. B-207 (Academic Block)", "011 26907 117", "Sudhanshut@iiitd.ac.in");
    adminStructure.addPerson(&SudhanshuTamta);


    // Adding Student Affairs department personnel
    AdministrativeOfficer raviBhasin("Dr. Ravi Bhasin", "Administrative Officer (Student Affairs)", "Room No. A-207-1 (Academic Block)", "011 26907 504", "ravi@iiitd.ac.in");
    adminStructure.addPerson(&raviBhasin);

    Officer jagadanandDwivedi("Jagadanand Dwivedi", "Junior Administrative Officer (Student Affairs) (SG)", "Room No. A-207-1 (Academic Block)", "011 26907 421", "jagadanand@iiitd.ac.in");
    adminStructure.addPerson(&jagadanandDwivedi);

    Officer sonalGarg("Sonal Garg", "Junior Administrative Officer (Student Affairs) (SG)", "Room No. A-207-1 (Academic Block)", "011 26907 553", "sonal@iiitd.ac.in");
    adminStructure.addPerson(&sonalGarg);

    // Adding Store & Purchase department personnel
    AdministrativeOfficer ajayKumar("Ajay Kumar", "Administrative Officer (Store & Purchase)", "Room No. A-103(2) (Academic Block)", "011 26907 561", "ajay@iiitd.ac.in");
    adminStructure.addPerson(&ajayKumar);

    Officer nidhiYadav("Nidhi Yadav", "Assistant Administrative Officer (Store & Purchase) (SG)", "Room No. A-108 (Academic Block)", "011 26907 597", "nidhi@iiitd.ac.in");
    adminStructure.addPerson(&nidhiYadav);

    Officer sangamYadav("Sangam Kumar Yadav", "Junior Administrative Officer (Store & Purchase)", "A-106, Academic Block", "011 26907 400", "sangam@iiitd.ac.in");
    adminStructure.addPerson(&sangamYadav);

    // Adding Library personnel
    Officer parikshitaBehera("Parikshita Behera", "Junior Library Officer", "Library Block", "011 26907 503", "parikshita@iiitd.ac.in");
    adminStructure.addPerson(&parikshitaBehera);

    AdministrativeOfficer rajendraSingh("Rajendra Singh", "Library Officer (SG)", "Library Block", "011 26907 510", "rajendra@iiitd.ac.in");
    adminStructure.addPerson(&rajendraSingh);

    // Example usage
    char queryName[100];
    cout << "Enter the name of the person to get their contact details: ";
    cin.getline(queryName, 100);
    if (isAlphaString(queryName)) {
        getContactDetails(adminStructure, queryName);
    } else {
        cout << "Invalid input. Please enter a valid name containing only alphabetic characters.\n";
    }

    return 0;
}