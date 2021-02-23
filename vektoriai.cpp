////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                     Darba atliko: Karolis Zeimantas                     //
//    stengiausia padaryti tvarkingai bet iskilo visai daug problemu       //
//    pagrinde su mediana bet suzinojes apie malloc viskas buvo gerai      //
//    tikiuosi daug klaidu nepalikau                                       //
/////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h> 
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::move;
using std::vector;
int studCount;
string fill;
int wantedMarks = 0;
char type;

struct Students
{
    string names;
    string lastNames;
    float vid;
    float med=0;
};
bool checkForDigit(string digit){
    for (int i = 0; i < digit.length(); i++)
    {
        if(!isdigit(digit[i]))
        return false;
    }
    return true;
}
void autoFill(vector<Students> &stud){
    Students tempStruct;
    float *grades;
    srand(time(NULL));
    float mark;
    float tempVid=0;
    for (int i = 0; i < studCount; i++)
    {
        for (int j = 0; j < wantedMarks; j++)
        {        
            
            mark = rand() %10+1;
            tempVid+= mark;
        float * tempArray = grades;
        grades = (float*) malloc (j+1);
        std::copy(tempArray,tempArray+j,grades);
        grades[j] =mark;
        }
    for (int a = 0; a < wantedMarks; a++)
    {
          if(a%2==0&&a==wantedMarks/2)
                tempStruct.med = (grades[a]+grades[a+1])/2;

        else if(a==wantedMarks/2&&a%2==1)
                tempStruct.med = grades[a];  
    }
        tempStruct.vid = tempVid/wantedMarks;
        tempStruct.names = "name"+std::to_string(i);
        tempStruct.lastNames = "lastName"+std::to_string(i);
        tempVid=0;
        stud.push_back(tempStruct);
        tempStruct.med = 0;
    }
    
}
void handFill( vector<Students> &stud){
    Students tempStruct;
    float sum = 0,*grades;
    int j =0;
    string cont="y", temp;
    for (int i = 0; i < studCount; i++)
    {
    cout<<"iveskite studento varda: ";
    cin>> tempStruct.names;
    cout<<"iveskite studento pavarde: ";
    cin>>tempStruct.lastNames;
    
    while(cont=="Y"||cont=="y"){    
        cout<<"iveskite studento pazymi: ";
        cin>>temp;
        while(!checkForDigit(temp))
        {
            cout<<"prasome ivesti pazimi! ";
            cin>>temp;  
        }
        float * tempArray = grades;
        grades = (float*) malloc (j+1);
        std::copy(tempArray,tempArray+j,grades);
        grades[j] = std::stoi(temp);
        j++;
        cout<<"ar norite ivesti daugiau pazimiu?[Y/N]: ";
        cin>>cont;         
        while(true){
            if(cont=="Y" ||cont == "y"||cont == "N"||cont == "n")
            break;
            cout<<"prasome ivesti prasoma simboli! ";
            cin>>cont;            
        }
        sum+=std::stoi(temp);
        if(cont == "N"||cont == "n"){
        cont = "Y";
        break;
        }          
        
    }
    
    for (int a = 0; a < j; a++)
    {
          if(a%2==0&&a==j/2)
                tempStruct.med = (grades[a]+grades[a+1])/2;

        else if(a==j/2&&a%2==1)
                tempStruct.med = grades[a];  
    }
    free(grades);
    float floatTemp = j;
    tempStruct.vid = sum/floatTemp;
    sum = 0;
    j=0;
        stud.push_back(tempStruct);
    }
    
}
void fillFunc( vector<Students> &stud){
if(fill=="Y"||fill=="y"){
    
    cout<<"ar norite skaicuoti pagal vidurki ar mediana?[V/M]: ";
    cin>>type;

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
    cout<<"ivestkite pazimiu kieki: ";
    cin>>wantedMarks;
    cout<<"ar norite skaicuoti pagal vidurki ar mediana?[V/M]: ";
    cin>>type;
    while(true)
    {
    if(type == 'V'||type == 'v'||type == 'M'||type == 'm')
    break;
    cout<<"prasome ivesti priimtinus duomenis![V/M]: ";
    cin>>type;
    }

    autoFill(stud);
    }
    else{
        cout<<"prasome ivesti priimtina simboli!";
        cin>>fill;
        fillFunc(stud);

   }
    
}

void printTable( vector<Students> &stud){
    cout<<"Vardas"<<setw(5)<<' ';
    cout<<"Pavarde"<<setw(5)<<' ';
    if(type=='v'||type=='V')
    cout<<"Galutinis (Vid.)";
    else
    cout<<"Galutinis (Med.)";
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

int main(){
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
    vector<Students> stud;
        
    fillFunc(stud);
    printTable(stud);
}