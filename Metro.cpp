
#include "Metro.h"


#include <sstream>
Metro::Metro():RoadCounter(0),JunctionCounter(0),CarsCounter(0),HeadC(NULL),HeadJ(NULL),HeadR(NULL) {}
Metro::Metro(double **Graph, unsigned int size) {
    Junction *JJ;
    RoadCounter = 0;
    JunctionCounter = 0;
    CarsCounter = 0;
    HeadC = NULL;
    HeadJ = NULL;
    HeadR = NULL;

    for (unsigned int i = 0; i < size; i++) {
        JJ=new Junction(i+1);
        for (unsigned int j = 0; j < size; j++) {
            if(Graph[i][j]!=0){
                JJ->InsertNeighbor(j+1);
                InsertRoad(Graph[i][j],i+1,j+1,0);
            }


        }
        InsertJunction(*JJ);

    }

}

void Metro::InsertRoad(double rLen, int fr, int tt, int c) {
    Road* rr=new Road(rLen,fr,tt,c);
    HeadR=new Roads(rr,HeadR);
    RoadCounter++;
}

void Metro::InsertJunction(const Junction &j) {
    Junction* jec=new Junction(j.JunctionId,j.CarsHead,j.NeighborsHead);
    HeadJ=new Junctions(jec,HeadJ);
    JunctionCounter++;
}

void Metro::InsertCar(int CarId, int pos,char n) {
    Car *c1=NULL;
    if(n=='F')
        c1=new FamilyCar(CarId,pos);
    else if(n=='L')
        c1=new LuxuryCar(CarId,pos);
    else if(n=='S')
        c1=new SportCar(CarId,pos);
    else
        c1= new Maserati(CarId, pos);
    map.insert(CarId,pos);
    HeadC=new Cars(c1,HeadC);
    CarsCounter++;
}
Metro::Cars::Cars(Car *c, Metro::Cars *n) {
    Data=c;
    Next=n;
}
Metro::Junctions::Junctions(Junction *j, Metro::Junctions *n) {
    Data=j;
    Next=n;
}
Metro::Roads::Roads(Road *r, Metro::Roads *n) {
    Data=r;
    Next=n;
}
Junction * Metro::GetJunction(int pos) {
    Junctions *curr;
    curr=HeadJ;
    while(curr!=NULL){
        if(curr->Data->GetId()==pos){
            return curr->Data;
        }
        curr=curr->Next;
    }
    return 0;
}

void Metro::SetCars(string *ss, int jec) {
    for(int i=0;i<jec;i++){
        ss[i]=ss[i].substr(2);
        if(!ss[i].empty()){
            stringstream tt(ss[i]);
            string CarAdd;
            while(!(tt.eof())){
                tt>>CarAdd;
                InsertCar(atoi(CarAdd.substr(1).c_str()),i+1,CarAdd[0]);
                GetJunction(i+1)->InsertCar(atoi(CarAdd.substr(1).c_str()),i+1,CarAdd[0]);
            }
        }
    }

}

void Metro::PrintCars(int size) {
    string st;
    for(int i=1;i<size+1;i++)
    {
        cout<<i<<":";
        st=GetJunction(i)->PrintAllCars();
        cout<<st;
        cout<<endl;

    }
}

double Metro::GetRoadToxic(int fr, int tt) {
    Roads *r=HeadR;
    while(r!=NULL){
        if(r->Data->GetTo()==tt&&r->Data->GetFrom()==fr)
            return r->Data->GetToxic();
        r=r->Next;
    }
    return 0;
}

void Metro::PrintToxicity(int size) {
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++) {
            if(j+1==size)
                cout << GetRoadToxic(i, j);
            else
                cout << GetRoadToxic(i, j) << " ";
        }
        cout<<endl;
    }

}

void Metro::UpdateTox(int fr, int tt,int y) {
    Roads *curr;
    curr=HeadR;
    while(curr!=NULL){
        if(curr->Data->GetFrom()==fr &&curr->Data->GetTo()==tt){
            (*(curr->Data)).SetC(y);
            (*(curr->Data))++;
        }
        curr=curr->Next;
    }
}

void Metro::Move(int t) {
    Junctions *CurrJ=HeadJ;
    Cars *CurrC=HeadC;
    Junctions *CurrJ2=HeadJ;
    int tt,val,z;
    cin>>tt;
    for (int i = 0; i < tt; i++) {
        while(CurrC!=NULL){
            while(CurrJ->Data->GetId()!=CurrC->Data->GetCurrJunction()){
                CurrJ=CurrJ->Next;
            }
            if(CurrC->Data->GetName()=='F') {
                if (CurrJ->Data->GetNumOfNeighbors() > 0)
                    val = rand() & ((CurrJ->Data->GetNumOfNeighbors() - 0));
                else
                    val = 0;
            }
            else if(CurrC->Data->GetName()=='L'){
                val=rand()%((1 - 0)+1) + 0;
                if(val!=0){
                    if(CurrJ->Data->GetNumOfNeighbors()>0)
                    val=rand()%((CurrJ->Data->GetNumOfNeighbors()-1) + 1) + 1;
                    else
                        val=0;
                }
            }
            else if(CurrC->Data->GetName()=='S'||CurrC->Data->GetName()=='M'){
                if(CurrJ->Data->GetNumOfNeighbors()>0)
                    val=rand()%((CurrJ->Data->GetNumOfNeighbors()-1) + 1) + 1;
                else
                    val=0;
            }
            if(val!=0){
                CurrJ->Data->RemoveCar(CurrC->Data->GetId());
                z=CurrJ->Data->GetNeighbor(val);
                while(CurrJ2->Data->GetId()!=z)
                    CurrJ2=CurrJ2->Next;
                CurrJ2->Data->InsertCar(CurrC->Data->GetId(),CurrJ2->Data->GetId(),CurrC->Data->GetName());
                UpdateTox(CurrC->Data->GetCurrJunction(),CurrJ2->Data->GetId(),CurrC->Data->getType());
                CurrC->Data->SetCurrJunction(CurrJ2->Data->GetId());
            }
            CurrC=CurrC->Next;
            CurrJ2=HeadJ;
            CurrJ=HeadJ;

        }
            CurrC=HeadC;
    }
    PrintToxicity(t);
    PrintCars(t);

}

