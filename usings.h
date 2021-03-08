#ifndef GRANDPARENT_H
#define GRANDPARENT_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string> 
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <stdint.h>
#include"structures.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::move;
using std::vector;
using std::fixed;

bool customer_sorter(Students const&, Students const&);
void autoFill(vector<Students> &);
void handFill( vector<Students> &);
void fillFunc( vector<Students> &);
void printTable( vector<Students> &);
void scanFile(vector<Students> &);
bool checkForDigit(string);


#endif /* GRANDPARENT_H */