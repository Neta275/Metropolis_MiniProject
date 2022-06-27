
#ifndef ORANJESTAD1_READINGFILES_H
#define ORANJESTAD1_READINGFILES_H
#include "string"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Metro.h"
using namespace std;
class ReadingFiles{
public:
    ReadingFiles():s(0){};
double** ReadMat(const char* k);
int GetSize()const;
string * GetCars(const char* k,int godel);
private:
    int s;
};
#endif //ORANJESTAD1_READINGFILES_H
