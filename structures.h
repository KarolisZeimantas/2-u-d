#pragma once
#ifndef GRANDPARENT_H1
#define GRANDPARENT_H1
#include<string>
extern int studCount;
extern std::string fill;
extern int wantedMarks;
extern char type;
struct Students
{
    std::string names;
    std::string lastNames;
    float vid;
    float med=0;
    float egzaminas;

    // Students(std::string name,std::string lastNames,float vid,float med, float egzaminas )
    //     :names(names), lastNames(lastNames), vid(vid), med(med),egzaminas(egzaminas){}
    
    // Students(const Students& students)
    //         :names(students.names), lastNames(students.lastNames), vid(students.vid), med(students.med),egzaminas(students.egzaminas){}
};

// struct Students
// {
//     std::string names;
//     std::string lastNames;
//     float vid;
//     float med=0;
//     float egzaminas;

// };

#endif /* GRANDPARENT_H1 */