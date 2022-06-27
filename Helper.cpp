
#include "Helper.h"
void Helper::start(const char *t1, const char *t2) {
    ReadingFiles Read;
    double** matrix;
    string *Cars;
    matrix=Read.ReadMat(t1);
    Cars=Read.GetCars(t2,Read.GetSize());
    Metro metro(matrix,Read.GetSize());
    metro.SetCars(Cars,Read.GetSize());
    metro.Move(Read.GetSize());

}