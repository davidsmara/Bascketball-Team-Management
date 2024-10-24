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

    Jucator &operator=(const Jucator &rhs) {
        if(this != &rhs) {
            this->jucatorId = rhs.jucatorId;
            strcpy(this->nume, rhs.nume);
            strcpy(this->prenume, rhs.prenume);
            this->inaltime = rhs.inaltime;
            strcpy(this->pozitie, rhs.pozitie);
            this->valoareTransfer = rhs.valoareTransfer;
            this->salariu = rhs.salariu;
        }
        return *this;
    }
};

ostream &operator<<(ostream& os, const Jucator& rhs) {
    os <<"Nume: " << rhs.nume<<", Prenume: "<<rhs.prenume<<", Pozitie: "<<rhs.pozitie;
    return os;
}

class Echipa{
    private:
    int echipaId;
    int nrJucatori;
    Jucator jucator[20];
    char numeEchipa[20];
    char numeOwner[20];
    int valoareTotala;

    public:
    Echipa() {
        echipaId=0;
        nrJucatori=0;
        for(int i=1; i<=20; i++)
            jucator[i] = Jucator();
        strcpy(numeEchipa, "");
        strcpy(numeOwner, "");
        valoareTotala=0;
    }

    Echipa(int echipaId, int nrJucatori, Jucator jucator[20], char *numeEchipa, char *numeOwner, int valoareTotala) {
        this->echipaId = echipaId;
        this->nrJucatori = nrJucatori;
        for(int i=1; i<=20; i++)
            this->jucator[i] = jucator[i];
        strcpy(this->numeEchipa, numeEchipa);
        strcpy(this->numeOwner, numeOwner);
        this->valoareTotala = valoareTotala;
    }

    Echipa(const Echipa &rhs) {
        echipaId = rhs.echipaId;
        strcpy(numeEchipa, rhs.numeEchipa);
        strcpy(numeOwner, rhs.numeOwner);
        for(int i=1; i<=20; i++)
            this->jucator[i] = rhs.jucator[i];
        this->valoareTotala = rhs.valoareTotala;
        this->nrJucatori = rhs.nrJucatori;
    }

    void setEchipaId(int echipaId) {
        this->echipaId = echipaId;
    }

    int getEchipaId() {
        return this->echipaId;
    }

    void setNrJucatori(int nrJucatori) {
        this->nrJucatori = nrJucatori;
    }

    int getNrJucatori() {
        return this->nrJucatori;
    }

    void setJucatori(Jucator jucator[20]) {
        for(int i=1; i<this->nrJucatori; i++)
            this->jucator[i] = jucator[i];
    }

    Jucator* getJucatori(Jucator jucator[20]) {
        return jucator;
    }

    void setNumeEchipa(char numeEchipa[20]) {
        strcpy(this->numeEchipa, numeEchipa);
    }

    char *getNumeEchipa() {
        return this->numeEchipa;
    }

    void setNumeOwner(char *numeOwner) {
        strcpy(this->numeOwner, numeOwner);
    }

    char *getNumeOwner() {
        return this->numeOwner;
    }

    void setValoareTotala(int valoareTotala) {
        this->valoareTotala = valoareTotala;
    }

    int getValoareTotala() {
        return this->valoareTotala;
    }

    friend ostream &operator<<(ostream &os, const Echipa &rhs);
    };

ostream &operator<<(ostream& os, const Echipa& rhs) {
    os <<"NumeEchipa: " << rhs.numeEchipa<<", NumeOwner: "<<rhs.numeOwner;
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
        cout<<"3 - Adaugare jucator"<<endl;
        cout<<"4 - Stergerea unui jucator"<<endl;
        cout<<"0 - Iesire program"<<endl;

    int ok;
    cin>>ok;

    switch(ok) {
        case 1: {
            for(int i = 0; i < nrJucatori; i++) {
                cout<<jucator[i]<<endl;
            }
            cout<<endl;
            break;
        }

        case 2: {
            cout<<"Id jucator:";
            int jucatorId;
            cin>>jucatorId;
            for(int i = 0; i < nrJucatori; i++) {
                if(jucatorId == jucator[i].getJucatorId()) {
                    cout<<jucator[i].getSalariu()<<endl;
                }
            }
            break;
        }

        case 3: {
            cout<<"Adaugare jucator:"<<endl;
            char nume[20], prenume[20], pozitie[20];
            cout<<"Nume jucator:\n";
            cin>>nume;
            cout<<"Prenume jucator:\n";
            cin>>prenume;
            int salariu;
            cout<<"Salariu jucator:\n";
            cin>>salariu;
            int valoareTransfer;
            cout<<"Valoare jucator:\n";
            cin>>valoareTransfer;
            float inaltime;
            cout<<"Inaltime jucator:\n";
            cin>>inaltime;
            cout<<"Pozitie jucator:\n";
            cin>>pozitie;

            nrJucatori++;
            Jucator *aux = new Jucator[nrJucatori];
            for(int i = 0; i < nrJucatori-1; i++) {
                aux[i]=jucator[i];
            }
            aux[nrJucatori-1]=Jucator(aux[nrJucatori-2].getJucatorId()+1, nume, prenume, inaltime, pozitie, valoareTransfer, salariu);
            delete[] jucator;

            jucator = aux;
            break;
        }

        case 4: {
            cout<<"Stergerea unui jucator:\n"<<endl;
            cout<<"In functie de:\n1 - Nume\n2 - Id\n3 - Pozitie\n";
            int o;
            cin>>o;
            Jucator *aux = new Jucator[nrJucatori-1];
            if(o == 1) {
                cout<<"Nume jucator:\n";
                char nume[20];
                int v=0;
                cin>>nume;
                for(int i = 0; i < nrJucatori; i++) {
                    if(strcmp(jucator[i].getNume(), nume) == 0) {
                        v=1;
                    }
                }

                if(v==0) {
                    cout<<"Nu exista jucatorul cu numele " << nume << ", stergerea nu a fost posibila"<<endl;
                }
                else {
                    int j=0;
                    for(int i = 0; i < nrJucatori; i++) {
                        if(strcmp(jucator[i].getNume(), nume) != 0) {
                            aux[j]=jucator[i]; j++;
                        }
                    }

                    cout<<"Jucatorul a fost sters!\n";

                }
            }
            delete[] jucator;
            jucator = aux;
            nrJucatori--;
            break;
        }

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
//Afisare salariu mediu
//Reducere salariu 20%
//Afisare echipa
//Adaugare echipa (fara jucatori)
//Adaugare jucatori in echipa
//Scoatere jucatori din echipa
//Stergere echipa