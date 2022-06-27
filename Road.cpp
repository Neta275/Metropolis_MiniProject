
#include "Road.h"
Road::Road(double len, int fr, int tt,double C) {
    km=len;
    from=fr;
    to=tt;
    c=0;
    AirToxic=0;
}

int Road::GetFrom() const {return from;}

int Road::GetTo() const {return to;}

double Road::GetToxic() const {return AirToxic;}

Road &Road::operator++() {
    this->AirToxic+=c/km;
    return *this;
}

Road Road::operator++(int) {
    Road curr=*this;
    this->AirToxic+=c/km;
    return curr;
}