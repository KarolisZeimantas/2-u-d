#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::move;
int studCount;
string fill;
int wantedMarks;
char type;
struct Students
{
    string names;
    string lastNames;
    float vid;
    float med;
};

void autoFill(Students stud[]){
    Students tempStruct;
    srand(time(NULL));
    float mark;
    float tempVid=0;
    for (int i = 0; i < studCount; i++)
    {
        for (int j = 0; j < wantedMarks; j++)
        {        
            
            mark = rand() %10+1;
            tempVid+= mark;

            if(wantedMarks%2==0&&wantedMarks/2 ==j)
                tempStruct.med = mark;
            else if(wantedMarks/2==j||wantedMarks/2+1==j)
                tempStruct.med += mark;
        }
        tempStruct.med = tempStruct.med/2;
        tempStruct.vid = tempVid/wantedMarks;
        tempStruct.names = "name"+std::to_string(i);
        tempStruct.lastNames = "lastName"+std::to_string(i);
        tempVid=0;
        stud[i] = tempStruct;
    }
    
}
void handFill(Students stud[]){
    Students tempStruct;
    int temp;
    for (int i = 0; i < studCount; i++)
    {
    cout<<"iveskite studento varda: ";
    cin>> tempStruct.names;
    cout<<"iveskite studento pavarde: ";
    cin>>tempStruct.lastNames;
    cout<<"iveskite sudento pazymius po viena: ";
    for (int j = 0; j < wantedMarks; j++)
    {
        cin>>temp;
        while(temp>10||temp<1){
            cout<<"prasome ivesti normalu pazimi: ";
            cin>>temp;
        }
        //tempStruct.marks.push_back(temp);
    }
    tempStruct.vid = temp/studCount;
    stud[i] = tempStruct;
    }
    
}
void fillFunc(string fill,Students stud[]){
if(fill=="Y"||fill=="y"){

    while(true)
    {
    if(type == 'V'||type == 'v'||type == 'M'||type == 'm')
    break;
    cout<<"prasome ivesti priimtinus duoneis![V/M]: ";
    cin>>type;
    }
    handFill(stud);

    }
    else if (fill=="N"||fill=="n"){    

    while(true)
    {
    if(type == 'V'||type == 'v'||type == 'M'||type == 'm')
    break;
    cout<<"prasome ivesti priimtinus duoneis![V/M]: ";
    cin>>type;
    }
    autoFill(stud);

    }
    else{
        cout<<"prasome ivesti priimtina simboli!";
        string temp;
        cin>>temp;
        fillFunc(temp,stud);
    }
    
}

void printTable(Students stud[]){
    cout<<"Vardas"<<setw(5)<<' ';
    cout<<"Pavarde"<<setw(5)<<' ';
    cout<<"Galutinis (Vid.)";
    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    for (int i = 0; i < studCount; i++)
    {
        if(type=='v'||type=='V')
        cout<<stud[i].names<<setw(5)<<' '<<stud[i].lastNames<<setw(5)<<' '<<std::setprecision(2)<<stud[i].vid<<endl;
        else
        cout<<stud[i].names<<setw(5)<<' '<<stud[i].lastNames<<setw(5)<<' '<<std::setprecision(2)<<stud[i].med<<endl;
    }
    
}
bool checkForDigit(string digit){
    for (int i = 0; i < digit.length(); i++)
    {
        if(!isdigit(digit[i]))
        return false;
    }
    return true;
}
int main(){
    string temp;
    cout<<"iveskite norimu pazimiu skaiciu: ";
    cin>>temp;
    while(!checkForDigit(temp)){
        cout<<"iveskite skaiciu: ";
        cin>>temp;
    }
    wantedMarks =std::stof(temp);
    cout<<"iveskite studentu kieki: ";
    cin>>temp;
    while(!checkForDigit(temp)){
        cout<<"iveskite skaiciu: ";
        cin>>temp;
    }
    studCount =std::stof(temp);
    cout<<"ar norite ivesti duomenis ranka?[Y/N]: ";
    cin>>fill;
    cout<<"ar norite skaicuoti pagal vidurki ar mediana?[V/M]: ";
    cin>>type;
    Students stud[studCount];
        
    fillFunc(fill,stud);
    printTable(stud);
}