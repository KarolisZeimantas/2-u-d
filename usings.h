#pragma once
#ifndef GRANDPARENT_H
#define GRANDPARENT_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ratio>
#include <fstream>
#include <iomanip>
#include <string> 
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <chrono>
#include"structures.h"
#include <list>
// #include<deque>
// #include <iostream>
// #include <ctime>
// #include <cstdlib>
// #include <iomanip>
// #include <stdlib.h>
#include<bits/stdc++.h> 
#include <algorithm>

#include <ctype.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::move;
using std::vector;
using std::fixed;
using std::chrono::duration;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
bool customer_sorter(Students const&, Students const&);
void autoFill(vector<Students> &);
void handFill( vector<Students> &);
void fillFunc( vector<Students> &);
void printTable( vector<Students> &);
void scanFile(vector<Students> &);
bool checkForDigit(string);
void createFile();

#endif /* GRANDPARENT_H */