#include <iostream>
#include <ctime>
#include <cstring>
#include <limits> 

using namespace std;

#define MAX_HIER 4   
#define MAX_PPL 10     
#define NUM_DEPT 1  

class Prs {
public:
    char n[100];
    char r[100];
    int srLevel;

    Prs(const char* nm, const char* rl, int lvl) {
        strcpy(n, nm);
        strcpy(r, rl);
        srLevel = lvl;
    }

    virtual void handleCmplnt() {
        cout << r << " " << n << " is handling the complaint.\n";
    }
};

class AsstProf : public Prs {
public:
    AsstProf(const char* nm) : Prs(nm, "Asst Prof", 1) {}
};

class AssocProf : public Prs {
public:
    AssocProf(const char* nm) : Prs(nm, "Assoc Prof", 2) {}
};

class Prof : public Prs {
public:
    Prof(const char* nm) : Prs(nm, "Prof", 3) {}
};

class HOD : public Prs {
public:
    HOD(const char* nm) : Prs(nm, "HOD", 4) {}
};

class Officer : public Prs {
public:
    Officer(const char* nm) : Prs(nm, "Officer", 1) {}
};

class AdminOff : public Prs {
public:
    AdminOff(const char* nm) : Prs(nm, "Admin Off", 2) {}
};

class Dn : public Prs {
public:
    Dn(const char* nm) : Prs(nm, "Dean", 3) {}
};

class Dir : public Prs {
public:
    Dir(const char* nm) : Prs(nm, "Director", 4) {}
};

class Cmplnt {
public:
    char detail[200];
    Prs* hndlr;
    time_t timeCrt;
    int dLimit;

    Cmplnt(const char* dtl, Prs* p, int limit = 3) {
        strcpy(detail, dtl);
        hndlr = p;
        timeCrt = time(0);
        dLimit = limit;
    }

    bool needEsc(int daysPassed) {
        return daysPassed > dLimit;
    }

    void escalate(Prs* nxtHndlr) {
        hndlr = nxtHndlr;
        cout << "Complaint escalated to " << hndlr->r << " " << hndlr->n << ".\n";
    }
};

class EscMatrix {
private:
    Prs* hier[MAX_HIER][MAX_PPL]; 
    int pCount[MAX_HIER];           

public:
    EscMatrix() {
        for (int i = 0; i < MAX_HIER; ++i) pCount[i] = 0;
    }

    void addPrs(Prs* p, int lvl) {
        if (pCount[lvl] < MAX_PPL) hier[lvl][pCount[lvl]++] = p;
    }

    Prs* getNxtLvl(Prs* curHndlr) {
        if (curHndlr == nullptr) return nullptr;

        int curLvl = curHndlr->srLevel;
        if (curLvl + 1 < MAX_HIER) {
            if (pCount[curLvl + 1] > 0) return hier[curLvl + 1][0]; 
        }
        return nullptr; 
    }

    Prs* getInitHndlr() {
        if (pCount[0] > 0) return hier[0][0]; 
        return nullptr;
    }

    void printPpl() {
        for (int i = 0; i < MAX_HIER; ++i) {
            cout << "Level " << i + 1 << ":\n";
            for (int j = 0; j < pCount[i]; ++j) {
                cout << "  " << hier[i][j]->r << ": " << hier[i][j]->n << "\n";
            }
        }
    }
};

void chkEsc(Cmplnt& cmplnt, EscMatrix& mx, int daysPassed) {
    if (cmplnt.needEsc(daysPassed)) {
        Prs* nxtHndlr = mx.getNxtLvl(cmplnt.hndlr);
        if (nxtHndlr) cmplnt.escalate(nxtHndlr);
        else cout << "No further escalation possible.\n";
    } else {
        cout << "Complaint is still within resolution time.\n";
    }
}

int getValidatedInput() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            return input;
        }
    }
}

int main() {
    EscMatrix acMatrix[NUM_DEPT];

    const char* deptNames[NUM_DEPT] = { "CSE IIITD" };

    for (int d = 0; d < NUM_DEPT; ++d) {
        cout << "\nSetting up " << deptNames[d] << " Dept Hier...\n";

        acMatrix[d].addPrs(new AsstProf("Arani Bhattacharya"), 0);
        acMatrix[d].addPrs(new AsstProf("Bapi Chatterjee"), 0);

        acMatrix[d].addPrs(new AssocProf("Debarka Sengupta"), 1);
        acMatrix[d].addPrs(new AssocProf("Debajyoti Bera"), 1);

        acMatrix[d].addPrs(new Prof("Mukesh Mohania"), 2);
        acMatrix[d].addPrs(new Prof("Pushpendra Singh"), 2);

        acMatrix[d].addPrs(new HOD("Sambuddho Chakravarty"), 3);

        acMatrix[d].printPpl();
    }

    EscMatrix admMatrix;
    cout << "\nSetting up Admin Dept Hier...\n";

    admMatrix.addPrs(new Officer("Imran Khan"), 0);
    admMatrix.addPrs(new Officer("Kapil Dev Garg"), 0);
    admMatrix.addPrs(new AdminOff("Dr. Deepika Bhaskar"), 1);  
    admMatrix.addPrs(new Dn("Vivek Ashok Bohara"), 2);  
    admMatrix.addPrs(new Dn("Debarka Sengupta(ASS Dean)"), 2);
    admMatrix.addPrs(new Dir("Prof. Ranjan Bose"), 3);

    admMatrix.printPpl();

    char regCmplnt;
    cout << "\nDo you want to register a complaint? (y/n): ";
    cin >> regCmplnt;

    if (regCmplnt == 'y') {
        char cmplntDtl[200];
        int deptChoice, daysPassed;

        cout << "Enter the complaint details: ";
        cin.ignore();  
        cin.getline(cmplntDtl, 200);

        cout << "Choose Dept: (0 for CSE IIITD, 1 for Admin): ";
        cin >> deptChoice;

        if (deptChoice == 0) {
            Cmplnt csCmplnt(cmplntDtl, acMatrix[0].getInitHndlr());
            csCmplnt.hndlr->handleCmplnt();

            cout << "Enter days passed since complaint: ";
            daysPassed = getValidatedInput(); 
            
            chkEsc(csCmplnt, acMatrix[0], daysPassed);
        } else if (deptChoice == 1) {
            Cmplnt admCmplnt(cmplntDtl, admMatrix.getInitHndlr());
            admCmplnt.hndlr->handleCmplnt();

            cout << "Enter days passed since complaint: ";
            daysPassed = getValidatedInput(); 

            chkEsc(admCmplnt, admMatrix, daysPassed);
        } else {
            cout << "Invalid dept choice!\n";
        }
    } else {
        cout << "No complaint registered.\n";
    }

    return 0;
}
