#include <iostream>
#include <cstring>
using namespace std;

class Jucator {
private:
    int jucatorId;
    char nume[20];
    char prenume[20];
    float inaltime;
    char pozitie[20];
    int valoareTransfer;
    int salariu;
public:
    Jucator(){
        jucatorId = 0;
        strcpy(nume,"");
        strcpy(prenume,"");
        inaltime = 0;
        salariu = 0;
        strcpy(pozitie,"");
        valoareTransfer = 0;
    };

    Jucator(int jucatorId, char *nume, char *prenume, float inaltime, char *pozitie, int valoareTransfer, int salariu) {
        this->jucatorId = jucatorId;
        strcpy(this->nume, nume);
        strcpy(this->prenume, prenume);
        this->inaltime = inaltime;
        strcpy(this->pozitie, pozitie);
        this->valoareTransfer = valoareTransfer;
        this->salariu = salariu;
    }

    Jucator(const Jucator &rhs) {
        jucatorId = rhs.jucatorId;
        strcpy(nume, rhs.nume);
        strcpy(prenume, rhs.prenume);
        this->inaltime = rhs.inaltime;
        strcpy(this->pozitie, rhs.pozitie);
        this->valoareTransfer = rhs.valoareTransfer;
        this->salariu = rhs.salariu;
    }

    void setJucatorId(int jucatorId) {
        this->jucatorId = jucatorId;
    }

    int getJucatorId() {
        return this->jucatorId;
    }

    void setNume(char nume[20]) {
        strcpy(this->nume, nume);
    }

    char* getNume() {
        return this->nume;
    }

    void setPrenume(char prenume[20]) {
        strcpy(this->prenume, prenume);
    }

    char* getPrenume() {
        return this->prenume;
    }

    void setInaltime(float inaltime) {
        this->inaltime = inaltime;
    }

    float getInaltime() {
        return this->inaltime;
    }

    void setPozitie(char pozitie[20]) {
        strcpy(this->pozitie, pozitie);
    }

    char* getPozitie() {
        return this->pozitie;
    }

    void setSalariu(int salariu) {
        this->salariu = salariu;
    }

    int getSalariu() {
        return this->salariu;
    }

    void setValoareTransfer(int valoareTransfer) {
        this->valoareTransfer = valoareTransfer;
    }

    int getValoareTransfer() {
        return this->valoareTransfer;
    }

    friend ostream &operator<<(ostream &os, const Jucator &rhs);
};

ostream &operator<<(ostream& os, const Jucator& rhs) {
    os <<"Nume: " << rhs.nume<<", Prenume: "<<rhs.prenume<<", Pozitie: "<<rhs.pozitie;
    return os;
}



int nrJucatori = 3;
Jucator *jucator = new Jucator[3];

void initializare() {
    jucator[0].setJucatorId(1);
    jucator[1].setJucatorId(2);
    jucator[2].setJucatorId(3);

    jucator[0].setNume("Ion");
    jucator[1].setNume("Popescu");
    jucator[2].setNume("Smara");

    jucator[0].setPrenume("Mihai");
    jucator[1].setPrenume("Andrei");
    jucator[2].setNume("Alex");

    jucator[0].setSalariu(12000);
    jucator[1].setSalariu(17000);
    jucator[2].setSalariu(20000);

    jucator[0].setValoareTransfer(120000);
    jucator[1].setValoareTransfer(185002);
    jucator[2].setValoareTransfer(200000);

    jucator[0].setInaltime(1.8);
    jucator[1].setInaltime(1.9);
    jucator[2].setInaltime(2);

    jucator[0].setPozitie("point guard");
    jucator[1].setPozitie("shooting guard");
    jucator[2].setPozitie("small forward");
}

int main() {
    initializare();

    start:
        cout<<"1 - Afisare Jucatori"<<endl;
        cout<<"2 - Afisare salariu unui jucator"<<endl;
        cout<<"0 - Iesire program"<<endl;

    int ok;
    cin>>ok;

    switch(ok) {
        case 1:
            for(int i = 0; i < nrJucatori; i++) {
                cout<<jucator[i]<<endl;
            }
        cout<<endl;
        break;

        case 2:
            cout<<"Id jucator:";
        int jucatorId;
        cin>>jucatorId;
        for(int i = 0; i < nrJucatori; i++) {
            if(jucatorId == jucator[i].getJucatorId()) {
                cout<<jucator[i].getSalariu()<<endl;
            }
        }
        break;

        case 0:
            return 0;
    }

    cout<<"0 - Iesire program"<<endl;
    cout<<"1 - Intoarcere Meniu"<<endl;
    cin>>ok;

    if(ok == 1) {
        goto start;
    }
    return 0;
}
