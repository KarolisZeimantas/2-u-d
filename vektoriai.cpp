/////////////////////////////////////////////////////////////////////////////
//                     Darba atliko: Karolis Zeimantas                     //
/////////////////////////////////////////////////////////////////////////////
#include"usings.h"
int studCount;
int wantedMarks = 0;
std::string fill;
char type;
int main(){

    createFile();
    exit(1);
    cout<<"a";
    vector<Students> stud;     
    string failas;
    cout<<"ar norite duomenis skaityti is failo?[Y/N]";
    while(cin>>failas){
        if(failas=="y"||failas=="Y"||failas=="n"||failas=="N") break;
        cout<<"iveskite prasoma simboli! ";
    }
    if(failas=="y"||failas=="Y"){
        scanFile(stud);
        return 0;
    }
    string temp;
    
    cout<<"iveskite studentu kieki: ";
    cin>>temp;
    while(!checkForDigit(temp)){
        cout<<"iveskite skaiciu: ";
        cin>>temp;
    }
    studCount =std::stof(temp);

    cout<<"ar norite ivesti duomenis ranka?[Y/N]: ";
    cin>>fill;   
    fillFunc(stud);
    printTable(stud);
}