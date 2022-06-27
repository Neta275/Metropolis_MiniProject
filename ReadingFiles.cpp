
#include "ReadingFiles.h"


int ReadingFiles::GetSize() const {return s;}

double **ReadingFiles::ReadMat(const char *k) {
    stringstream tt;
    string Line1;
    string Line2;
    int CounterLine1=0;
    int CounterLine2=0;
    int size;
    ifstream FileInput(k);
    if(FileInput.is_open()){
        getline(FileInput,Line1);
        tt<<Line1;
        tt>>size;
        this->s=size;
        double** matrix;
        matrix=new double*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i]=new double[size];

        }
        while(getline(FileInput,Line1)){
            stringstream m(Line1);
            stringstream p(Line1);
            while(!p.eof()){
                p>>Line2;
                CounterLine2++;
            }
            if(CounterLine2!=size){
                cerr<<"ERROR: Invalid input.";
                return 0;
            }
            CounterLine2=0;
            for (int i = 0; i < size; i++) {
                m>>matrix[i][CounterLine1];

            }
            CounterLine1++;
        }
        if(CounterLine1!=size)
            cerr<<"invalid input.";
        FileInput.close();
        return matrix;
    }
    else cerr<<"ERROR: Invalid input."<<endl;
    return 0;
}

string *ReadingFiles::GetCars(const char *k, int godel) {
    string *line=new string[godel];
    int i=0;
    ifstream myfile(k);
    if (myfile.is_open()) {
        while (i<godel) {
            getline(myfile, line[i]);
            i++;
        }
        return line;
    }
    else{
        cerr<<"ERROR: Invalid input."<<endl;
    }
    myfile.close();
    return NULL;
}