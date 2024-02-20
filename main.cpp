#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <graphics.h>

using namespace std;

struct echipa
{
    char numme[20];
    char numeechipa[20];
    char tara1[20];
    int datainfiintarii;
    int cod;
};

struct jucatori
{
    char nume[20], prenume [20];
    char tara[20];
    int numar;
    char pozitie[20];
    int valoare;
    int cod;
};

struct antrenori
{
    char numea[20]; char prenumea[20];
    int cod;
};

struct stadion
{
    char numes[20];  char numes2[20];
    int locuri;
    int cod;
};

echipa e[100];int n;
jucatori j[200];int m;
stadion s[100];int p;
antrenori a[100]; int r;

void citire_stadion()
{
    int i;
    ifstream in ("stadion.in");
    in>>p; in.get();
    for(i=1;i<=p;i++)
        in>>s[i].numes>>s[i].numes2>>s[i].locuri>>s[i].cod;
    in.close();
}

void citire_antrenori()
{
    int i;
    ifstream in ("antrenori.in");
    in>>r; in.get();
    for(i=1;i<=r;i++)
        in>>a[i].numea>>a[i].prenumea>>a[i].cod;
    in.close();
}

void citire_echipe ()
{
    int i;
    ifstream in ("echipe.in");
    in>>n; in.get();
    for(i=1;i<=n;i++)
        in>>e[i].numme>>e[i].numeechipa>>e[i].tara1>>e[i].datainfiintarii>>e[i].cod;
    in.close();
}

void citire_jucatori ()
{
    int i;
    ifstream in ("jucatori.in");
    in>>m; in.get();
    for (i=1;i<=m;i++)
        in>>j[i].nume>>j[i].prenume>>j[i].tara>>j[i].numar>>j[i].pozitie>>j[i].valoare>>j[i].cod;
    in.close();
}

void afisare_echipe()
{
    int i;
    for (i=1;i<=n;i++)
            {cout<<e[i].numme;delay(200);cout<<" "<<e[i].numeechipa;delay(200);cout<<", "<<e[i].tara1;delay(200);cout<<" - "<<e[i].datainfiintarii;delay(200);cout<<endl;delay(150);}
}

void sortare_jucatori()
{
    int i,l;
    for(i=1;i<m;i++)
     for(l=i+1;l<=m;l++)
     if(strcmp(j[i].nume,j[l].nume)>0)
    {
        jucatori aux;
        aux=j[i];
        j[i]=j[l];
        j[l]=aux;
    }

}

void afisare_jucatori()
{
    int i;
    for (i=1;i<=m;i++)
    {
        sortare_jucatori();
        {cout<<" "<<j[i].nume;delay(50);cout<<" "<<j[i].prenume;delay(50);cout<<" ("<<j[i].numar;delay(50);cout<<")"<<" - "<<j[i].tara<<endl;delay(50);}
    }
}

void afisare_echipe_jucatori()
{
    int f,i;
    for(f=1;f<=n;f++)
    {
        cout<<endl<<e[f].numme;delay(300);cout<<" "<<e[f].numeechipa;delay(300);cout<<" "<<" - "<<e[f].tara1;delay(300);cout<<endl<<endl;
    for(i=1;i<=m;i++)
        if(j[i].cod==f)
            {cout<<"\t("<<j[i].numar;delay(100);cout<<") "<<j[i].nume;delay(100);cout<<" "<<j[i].prenume;delay(100);cout<<endl;}
    }
}

void afisare_echipe_stadion()
{
    int t,i;
    for(t=1;t<=n;t++)
    {
        cout<<e[t].numme<<" "<<e[t].numeechipa<<", "<<e[t].tara1;delay(500);
    for(i=1;i<=p;i++)
        if(s[i].cod==t)
            {cout<<" - "<<s[i].numes;delay(200);cout<<" "<<s[i].numes2;delay(300);cout<<" "<<" - "<<s[i].locuri<<" "<<"de mii de locuri"<<endl;delay(150);}
    }
}

void afisare_echipe_antrenori()
{
    int t,i;
    for(t=1;t<=n;t++)
    {
        {cout<<e[t].numme<<" "<<e[t].numeechipa<<", "<<e[t].tara1;delay(700);}
    for(i=1;i<=r;i++)
        if(a[i].cod==t)
            {cout<<" - "<<a[i].numea;delay(400);cout<<" "<<a[i].prenumea<<endl;delay(100);}
    }
}

void afisare_date_jucator()
{
    int i,x;
    char num[20]; char num2[20];int sem=0;
    cout<<"Cautati jucatorul:";cin>>num>>num2;
    for(i=1;i<=m;i++)
        if(strcmp(j[i].nume,num)==0 && strcmp(j[i].prenume,num2)==0)
        {
            sem=1;
            cout<<j[i].nume<<" "<<j[i].prenume<<": "<<endl<<" - "<<"Tara de origine este : "<<j[i].tara;delay(200);cout<<endl<<" - "<<"Numar : "<<j[i].numar;delay(200);cout<<" "<<endl<<" - "<<"Pozitie : "<<j[i].pozitie;delay(200);cout<<endl;
                for(x=1;x<=n;x++)
                    if(e[x].cod==j[i].cod)
                        {cout<<" - "<<"Club : "<<e[x].numme;delay(200);cout<<" "<<e[x].numeechipa;delay(200);cout<<" - "<<e[x].tara1;delay(200);cout<<endl;}
            cout<<" - "<<"Valoare : "<<j[i].valoare;delay(200);cout<<" de milioane euro";
        }
       if(!sem)
        cout<<endl<<"Jucatorul cautat nu se afla in baza de date"<<endl;

}

void save_jucator()
{
    int i;
    ofstream out("jucatori.in");
    out<<m<<endl;
    for(i=1;i<=m;i++)
        out<<j[i].nume<<" "<<j[i].prenume<<" "<<j[i].tara<<" "<<j[i].numar<<" "<<j[i].pozitie<<" "<<j[i].valoare<<" "<<j[i].cod<<endl;;
}
int returneaza_cod_echipa(char num[])
{
    int i;
    for(i=1;i<=n;i++)
        if(strcmp(e[i].numme,num)==0)
         return e[i].cod;
    return 0;
}
void adaugare_jucator()
{
    m++;
    int nr;
    cout<<"Dati numele si prenumele jucatorului: "; cin>>j[m].nume>>j[m].prenume;
    cout<<"Dati tara de origine al acestui jucator: ";cin>>j[m].tara;
    cout<<"Dati numarul jucatorului: "; cin>>j[m].numar;
    cout<<"Postul jucatorului: "; cin>>j[m].pozitie;
    cout<<"Valoarea jucatorului: "; cin>>j[m].valoare;
    cout<<"Dati codul echipei la care va juca:"; cin>>nr;
    if(nr>10)
        cout<<"Nu exista aceasta echipa.";
    else
        {
            j[m].cod=nr;
            save_jucator();
        }
}
int cauta_echipa(char ech[20],char tara1[30])
{
    int i;
    for(i=1;i<=n;i++)
        if(stricmp(e[i].numme,ech)==0 && strcmp(e[i].tara1,tara1)==0)
        return e[i].cod;
    return -1;
}

void afisare_jucatori_echipa(int id)
{
    int i;
    for(i=1;i<=m;i++)
        if(j[i].cod==id)
        cout<<"\t"<<j[i].nume<<" "<<j[i].prenume<<" "<<": "<<endl<<"\t\t"<<"Numar: "<<j[i].numar<<" "<<endl<<"\t\t"<<"Pozitie: "<<j[i].pozitie<<endl;
}
void jucatori_anumita_echipa()
{
    int id;
    char ech[30],ech1[30],tara1[30];
    cout<<"Dati echipa: ";
    cin>>ech>>ech1;
    cout<<"Dati tara: ";
    cin>>tara1;
    id=cauta_echipa(ech,tara1);
    if(id==-1)
        cout<<"Echipa cautata nu exista";
    else
        {
            cout<<"Jucatorii acestei echipe sunt:"<<endl;
            afisare_jucatori_echipa(id);
        }
}

int main()
{
    initwindow(605,342," ",100,50);
    readimagefile("inc.jpg",0,0,605,342);
    getch();
    closegraph();
    citire_echipe();
    citire_jucatori();
    citire_antrenori();
    citire_stadion();
    int op;
    do
    {
        system ("cls");
        cout<<"============MENIU============"<<endl;
        cout<<"1.Echipele si anul infiintarii"<<endl;
        cout<<"2.Jucatorii si tara de origine"<<endl;
        cout<<"3.Echipele si jucatorii acestora"<<endl;
        cout<<"4.Antrenorii echipelor"<<endl;
        cout<<"5.Stadioanele echipelor si capacitatea lor"<<endl;
        cout<<"6.Cautare jucator"<<endl;
        cout<<"7.Adaugare jucator"<<endl;
        cout<<"8.Jucatorii de la o anumita echipa"<<endl;
        cout<<"0.Iesire"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Alegeti optiunea:"; cin>>op; cout<<endl;
        switch (op)
        {
            case 1: afisare_echipe(); cout<<endl; system("pause"); break;
            case 2: afisare_jucatori(); cout<<endl; system("pause"); break;
            case 3: afisare_echipe_jucatori(); cout<<endl; system("pause"); break;
            case 4: afisare_echipe_antrenori(); cout<<endl; system("pause"); break;
            case 5: afisare_echipe_stadion(); cout<<endl; system("pause"); break;
            case 6: afisare_date_jucator(); cout<<endl; system("pause"); break;
            case 7: adaugare_jucator(); cout<<endl; system("pause"); break;
            case 8: jucatori_anumita_echipa();cout<<endl; system("pause"); break;

        }
    }while (op!=0);
    return 0;
}
