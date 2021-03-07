/////////////////////////////////////////////////////////////////////////////
//                     Darba atliko: Karolis Zeimantas                     //
//    stengiausia padaryti tvarkingai bet iskilo visai daug problemu       //
//    pagrinde su mediana bet suzinojes apie malloc viskas buvo gerai      //
//    tikiuosi daug klaidu nepalikau                                       //
/////////////////////////////////////////////////////////////////////////////
#include"structures.h"
#include"usings.h"

int studCount;
string fill;
int wantedMarks = 0;
char type;


bool checkForDigit(string digit){
    for (int i = 0; i < digit.length(); i++)
    {
        if(!isdigit(digit[i]))
        return false;
    }
    return true;
}
bool customer_sorter(Students const& lhs, Students const& rhs) {
    if(lhs.names < rhs.names){
        return true;
    }
    return false;
}
void autoFill(vector<Students> &stud){
    Students tempStruct;
    float *grades;
    srand(time(NULL));
    float mark, egzaminas;
    string cont;
    float tempVid=0;
    for (int i = 0; i < studCount; i++)
    {
        int j = 0;
        while(true)
        {        
            mark = rand() %10+1;
            tempVid+= mark;
        float * tempArray = grades;
        grades = (float*) malloc (j+1);
        std::copy(tempArray,tempArray+j,grades);
        grades[j] =mark;
        j++;
        //cout<<j;
            cout<<mark<<endl<<"Ar norite generuot daugiau pazimiu?[Y/N]";
            cin>>cont;
            while(true){
                if(cont=="Y" ||cont == "y"||cont == "N"||cont == "n")
                    break;
                    cout<<"iveskite prasoma simboli! ";
                    cin>>cont;
            }
            if(cont == "N"||cont == "n")
            break;
        }
        cout<<"Egzamino pazymis: ";
        egzaminas = rand()%10+1;
        cout<<egzaminas<<endl;

        for (int i = 0; i < j; i++)
        {
            for (int z = 0; z < i; z++)
            {
                if(*(grades + i)<*(grades+z)){
                    int temp = *(grades+i);
                    *(grades+i)= *(grades+z);
                    *(grades+z) = temp;
                }
            }
            
        }
        
    for (int a = 0; a < j; a++)
    {
          if(a%2==0&&a==j/2)
                tempStruct.med = (grades[a]+grades[a+1])/2;

        else if(a==j/2&&a%2==1||a==0)
                tempStruct.med = grades[a];  
    }
        tempStruct.vid = tempVid/j;
        tempStruct.names = "name"+std::to_string(i);
        tempStruct.lastNames = "lastName"+std::to_string(i);
        tempStruct.egzaminas = egzaminas;
        tempVid=0;
        stud.push_back(tempStruct);
        tempStruct.med = 0;
    }
    
}
void handFill( vector<Students> &stud){
    Students tempStruct;
    float sum = 0,*grades;
    string egzaminas;
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

        else if(a==j/2&&a%2==1||a==0)
                tempStruct.med = grades[a];  
    }
    float floatTemp = j;
    tempStruct.vid = sum/floatTemp;
    sum = 0;
    j=0;
    cout<<"iveskite studento egzamino pazymi: ";
    cin>>egzaminas;
    while(!checkForDigit(egzaminas))
    {
         cout<<"prasome ivesti pazimi! ";
         cin>>egzaminas;  
    }
    tempStruct.egzaminas = stof(egzaminas);
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
    std::cout << std::left << std::setfill(' ')
              << std::setw(12) << "vardas"
              << std::setw(12) << "pavarde";
    if(type=='v'||type=='V')
    std::cout << std::left << std::setfill(' ')<< std::setw(12)<<"Galutinis (Vid.)";
    else    
    std::cout << std::left << std::setfill(' ')<< std::setw(12)<<"Galutinis (Med.)";

    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    for (int i = 0; i < studCount; i++)
    {
        float rez;
        if(type=='v'||type=='V'){
        rez = stud[i].vid*0.4+stud[i].egzaminas*0.6;
        std::cout << std::left << std::setfill(' ')
              << std::setw(12) << stud[i].names
              << std::setw(12) << stud[i].lastNames
              << std::setw(12) << std::setprecision(1)<<rez;

        }
        else{
        rez = stud[i].med*0.4+stud[i].egzaminas*0.6;
        std::cout << std::left << std::setfill(' ')
              << std::setw(12) << stud[i].names
              << std::setw(12) << stud[i].lastNames
              << std::setw(12) << std::setprecision(1)<<rez;
        }
        cout<<endl;
    }
}
void scanFile(vector<Students> &stud){
    string temp;
    std::ifstream read;
    float vid,med,i=0,tempVid=0,tempMed=0,studCount = 0;
    vector<float> grades;
    Students tempStruct;
    cout<<"is kokio failo norite skaityti duomenis: 10000/100000/1000000[1/2/3]";
    
    while(cin>>temp){
        if(temp=="1"){
            try
            {
               read.open("studentai10000.txt");
               if(!read) throw "failas neatydarytas!";
            break;
            }
            catch(const std::ifstream::failure e)
            {
                std::cerr << "failas neatydarytas!" << '\n';
            }
        }
        else if(temp=="2"){
            try
            {
               read.open("studentai100000.txt");
               if(!read) throw "failas neatydarytas!";
            break;
            }
            catch(const std::ifstream::failure e)
            {
                std::cerr << "failas neatydarytas!" << '\n';
            }
        }
        else if(temp=="3"){
           try
            {
               read.open("studentai1000000.txt");
               if(!read) throw "failas neatydarytas!";
            break;
            }
            catch(const std::ifstream::failure e)
            {
                std::cerr << "failas neatydarytas!" << '\n';
            }
        }
        cout<<"prasome ivesti viena is 3 skaiciu!";
    }
  
    
  
    string firstLine;
    std::getline(read,firstLine);
    while(!read.eof()){
    read>>temp;
    tempStruct.names = temp;
    read>>temp;
    tempStruct.lastNames = temp;
        while(!read.eof()){
            read>>temp;
            if(read.peek()=='\n'||read.peek() == read.eof()){
                tempStruct.egzaminas = std::stoi(temp);
                break;
            }
            i++;
            tempVid += std::stoi(temp);
            grades.push_back(std::stoi(temp)); 
        }
        std::sort(grades.begin(),grades.end());
         tempStruct.vid =(tempVid/i)*0.4+tempStruct.egzaminas*0.6;
         int tempCounter = i;
        for (int a = 0; a < tempCounter; a++)
        {
          if(a%2==0&&a==tempCounter/2){
                tempStruct.med = (grades[a]+grades[a+1])/2;
          }

        else if(a==tempCounter/2&&a%2==1||a==0){
              //  cout<<grades[a]<<" ";
                tempStruct.med = grades[a];  
        }
        }
    //cout<<tempStruct.med<<" " <<tempStruct.vid<<endl;
    stud.push_back(tempStruct);
    tempStruct = {};
    grades.clear();
    tempVid = 0;
    studCount++;
    i=0;
    }
   for(int h=0;h<-1;h++)
        for(int j=i+1;j<studCount;j++)
            if(stud[j].names<stud[i].names)
            std::swap(stud[h],stud[j]);
    
    std::cout << std::left << std::setfill(' ')
              << std::setw(20) << "vardas"
              << std::setw(20) << "pavarde";
    std::cout << std::left << std::setfill(' ')<< std::setw(20)<<"Galutinis (Vid.)";
    std::cout << std::left << std::setfill(' ')<< std::setw(20)<<"Galutinis (Med.)";
    for (int j = 0; j < studCount; j++)
    {
        std::cout << std::left << std::setfill(' ')
              << std::setw(20) << stud[j].names
              << std::setw(20) << stud[j].lastNames
              << std::setw(20) << std::setprecision(2)<<stud[j].vid
              << std::setw(20) << std::setprecision(1)<<stud[j].med<<endl;
        
    }
    read.close();
}
int main(){
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