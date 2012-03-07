#include<iostream>
using namespace std;
//#include "r_pokaz.h"
#include "r_polje.h"

int brk=0;

void izbornik(){
     cout<<"0. Izlaz iz programa"<<endl;
     cout<<"1. Dodavanje zapisa o klijentima"<<endl;
     cout<<"2. Premjesti starije od 65 godine na pocetak reda"<<endl;
     cout<<"3. Izbaci iz reda sve koji imaju < 100kn, i zele kredit"<<endl;
     cout<<"4. Simuliranje otvaranja saltera"<<endl;
     cout<<"Vas izbor je: ";
     }
void ispis(tred *Q) {
     cout<<"Ispis reda..."<<endl;
    tklijent novi;
    int br=brk;
    while (br) {
      novi = FrontQ(Q);
      DeQueueQ(Q);
      cout << "Ime i prezime: " << novi.imeprez << endl;
      cout << "Godina rodjenja: " << novi.godr << endl;
      cout << "Stanje na racunu: " << novi.stanjer << endl;
      if(novi.vrstT == 'u') cout<<"Vrsta transakcije: Uplata/isplata"<<endl;
      if(novi.vrstT == 'p') cout<<"Vrsta transakcije: Placanje racuna"<<endl;
      if(novi.vrstT == 'k') cout<<"Vrsta transakcije: Kreditiranje"<<endl;
      cout<<"------------------------------"<<endl;
      EnQueueQ(novi,Q);
      br--;      
    }
}

void unos(tred *Q) {
     tklijent novi;
     cout << "Ime i prezime: "; 
     cin.ignore(); 
     cin.getline(novi.imeprez,50);
     cout << "Godina rodjenja: "; 
     cin >> novi.godr;
     cout << "Stanje racuna: "; 
     cin >> novi.stanjer;
     cout << "Vrsta transakcije: ('u' = upl/ispl,'p' =plac rac,'k' = krediti): "<<endl;
     cout<<"Vas izbor je: "; 
     do{
     cin >> novi.vrstT; 
     if((novi.vrstT != 'u') && (novi.vrstT != 'p') && (novi.vrstT != 'k')) cout<<"Pogresan unos, pokusajte ponovo"<<endl;
     }while((novi.vrstT != 'u') && (novi.vrstT != 'p') && (novi.vrstT != 'k'));
     EnQueueQ(novi, Q);
     cout<<"----------------------------------"<<endl<<endl;
     brk++;
}//fun

void starci(tred *Q) {
    tred *pomocni = InitQ(pomocni);
    tklijent novi;
    int br=brk;
    while (br) {
      novi = FrontQ(Q);
      DeQueueQ(Q);
      if (novi.godr > 1945)
        EnQueueQ(novi,pomocni);
      else
        EnQueueQ(novi,Q);
      br--;      
    }
    while (!IsEmptyQ(pomocni)) {
      novi = FrontQ(pomocni);
      DeQueueQ(pomocni);
      EnQueueQ(novi,Q);   
    }
    ispis(Q);
}

void nesposobni(tred *Q) {
    tred *pomocni = InitQ(pomocni);
    tklijent novi;
    int br=brk;
    while (br) {
      novi = FrontQ(Q);
      DeQueueQ(Q);
      if (!(novi.stanjer < 100 && novi.vrstT == 'k'))
        EnQueueQ(novi,Q);
      else brk--;
      br--;      
    }
      ispis(Q);
}

void otvaranje(tred *Q) {
   tklijent novi;
   novi = FrontQ(Q);
   DeQueueQ(Q);
   if (!IsEmptyQ(Q)) otvaranje(Q);
   EnQueueQ(novi,Q);  
}


int main(){
    bool uneseno = false;
    tred *Q = InitQ(Q);
    int izbor;
    do{
    izbornik();
    cin >> izbor;
    switch(izbor){
                  case 1:
                  for (int i=0;i<15;i++){
                  cout<<"Zapis broj: "<<i+1<<endl;
                  cout<<"Preostalo za unijeti: "<<15-(i+1)<<" zapisa"<<endl; 
                  unos(Q);
                  }
                  uneseno = true;
                  break;
                  
                  case 2:
                       if(!uneseno){
                                    cout<<"Niste unijeli podatke"<<endl;
                                    break;
                                    }
                  starci(Q);
                  break;
                  
                  case 3:
                       if(!uneseno){
                                    cout<<"Niste unijeli podatke"<<endl;
                                    break;
                                    }
                  nesposobni(Q);
                  break;
                 
                 case 4:
                      if(!uneseno){
                                    cout<<"Niste unijeli podatke"<<endl;
                                    break;
                                    }
                 otvaranje(Q);
                 ispis(Q);
                 break;
                 case 0: break;
                 default: cout<<"Pogresan izbor, pokusajte ponovo"<<endl;
                 }
    }while(izbor != 0);
                 
    system("pause");
}
