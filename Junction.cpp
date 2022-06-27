#include <sstream>
#include "Junction.h"
#include "FamilyCar.h"
#include "LuxuryCar.h"
#include "SportCar.h"
#include "Maserati.h"

Junction::Junction(int Id, Cars *CarsHead, Neighbors *NeighborsHead):JunctionId(Id),CarCount(0),NeighborsCount(0),
CarsHead(NULL),NeighborsHead(NULL){
    while(CarsHead!=NULL){
        InsertCar(CarsHead->Data->GetId(),CarsHead->Data->GetCurrJunction(),CarsHead->Data->GetName());
        CarsHead=CarsHead->Next;
    }
    while(NeighborsHead!=NULL){
        InsertNeighbor(NeighborsHead->Data->GetId());
        NeighborsHead=NeighborsHead->Next;
    }
}
Junction::Junction(int k):JunctionId(k),CarCount(0),NeighborsCount(0),CarsHead(NULL),NeighborsHead(NULL){}

void Junction::InsertCar(unsigned int CarId, int pos,char n) {
    Car *c1=NULL;
    if(n=='F')
        c1=new FamilyCar(CarId,pos);
    else if(n=='L')
        c1=new LuxuryCar(CarId,pos);
    else if(n=='S')
        c1=new SportCar(CarId,pos);
    else
        c1= new Maserati(CarId, pos);
    CarsHead=new Cars(c1,CarsHead);
    CarCount++;
}

void Junction::InsertNeighbor(int Neighbor) {
    Junction* j=new Junction(Neighbor);
    NeighborsHead=new Neighbors(j,NeighborsHead);
    NeighborsCount++;
}

void Junction::RemoveCar(unsigned int CarId) {
    if(!CarsHead){
        return;
    }
    Cars* curr=CarsHead;
    if(curr->Data->GetId()==CarId){
        CarsHead=CarsHead->Next;
        delete curr;
        CarCount--;
        return;
    }
    while(curr->Next&&curr->Next->Data->GetId()!=CarId){
        curr=curr->Next;
    }
    if(curr->Next){
        Cars* DeleteCar=curr->Next;
        curr->Next=DeleteCar->Next;
        delete DeleteCar;
        CarCount--;
    }
}
Junction::Cars::Cars(Car *c, Junction::Cars *n) {
    Data=c;
    Next=n;
}

Junction::Neighbors::Neighbors(Junction *s, Junction::Neighbors *n) {
    Data=s;
    Next=n;
}

string Junction::PrintAllCars() const {
    Cars *c=CarsHead;
    string ss="";
    while(c!=NULL){
        if(c->Data->GetId()!=10)
            ss+=(c->Data->GetId())+'0';
        else
            ss+="01";
        ss+=c->Data->GetName();
        ss+=" ";
        c=c->Next;
    }
    std::reverse(ss.begin(),ss.end());
    return ss;
}

int Junction::GetNeighbor(int k) const {
    Neighbors* curr=NeighborsHead;
    k--;
    while(k>0){
        curr=curr->Next;
        k--;
    }
    return curr->Data->GetId();

}
