#include "includes.h"

void createFiles(){
    fs::create_directory("./files");
    double tempvid = 0, gradeNR = 0;
    vector<float> grades;
    string temp, firstLine;
    std::vector<Students> varg, kiet, tempStud;
    int x = 100;
    srand(time(NULL));
    string tempSS;
    steady_clock::time_point t1 = steady_clock::now();
 for (int i = 0; i < 5; i++)
    {
       // cout<<i;
        std::ofstream fout(".\\files\\failas" + std::to_string(x) + ".txt");
        fout << std::left << std::setfill(' ')
             << std::setw(14) << "var"
             << std::setw(14) << "pav";
        for (int i = 1; i < 15; i++)
            fout << std::left << std::setfill(' ') << std::setw(14) << "ND" + std::to_string(i);
        fout << std::left << std::setfill(' ') << std::setw(14) << "Egz" << endl;

        for (int j = 1; j <= x; j++)
        {
            fout << std::left << std::setfill(' ') << std::setw(14) << "var" + std::to_string(j);
            fout << std::left << std::setfill(' ') << std::setw(14) << "pav" + std::to_string(j);
            for (int k = 0; k < 15; k++){
                if(k!=14)
                fout << std::left << std::setfill(' ') << std::setw(14) << rand() % 10 + 1;
                else{
                    fout <<rand() % 10 + 1;
                }
            }
                if(j!=x)
            fout << endl;
        }
        x*=10;
        fout.close();
    }

}
int main(){
   createFiles();
    cout<<"=============Vector============="<<endl;
   createVector();
    cout<<"=============List============="<<endl;
  createList();
    cout<<"=============Deque============="<<endl;

    createDeque();
    
    
}

