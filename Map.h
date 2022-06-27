

#ifndef HW4_MAP_H
#define HW4_MAP_H
#include <iostream>
using namespace std;

template <class T,class V>
struct NodeMap{
    T key;
    V value;
    NodeMap<T,V> *next;
};
template<class T,class V>
class Map{
public:

    Map(){first=NULL,last=NULL,counter=0;}
    void insert(T k,V v);
    void remove(T k);
    NodeMap<T,V>* find(T k)const;
    void print()const;
    void clear();
    int GetCounter(){return counter;}

private:
    NodeMap<T,V> *first;
    NodeMap<T,V> *last;
    int counter;


};
template<class T,class V>
void Map<T, V>::clear(){
    while(first){
        remove(first->key);
    }
}
template<class T,class V>
void Map<T, V>::remove(T k) {
    NodeMap<T,V> *temp=first;
    NodeMap<T,V> *temp2=NULL;
    if(temp->key==k){
        temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;
        counter--;
        return;
    }
    while(temp->next){
        if(temp->next->key==k){
            temp2=temp->next;
            temp->next=temp->next->next;
            delete temp2;
            counter--;
            return;
        }
        temp=temp->next;
    }
}
template<class T,class V>
void Map<T, V>::print() const {
    NodeMap<T,V> *temp=first;
    while(temp!=NULL){
        cout<<temp->key<<" "<<temp->value<< endl;
        temp=temp->next;
    }
}
template<class T,class V>
void Map<T, V>::insert(T k, V v) {
    if(!first){
        first=new NodeMap<T,V>;
        first->value=v;
        first->key=k;
        first->next=NULL;
        last=first;
        counter++;
        return;
    }
    else{
        NodeMap<T,V> *temp=first;
        if(temp->key>k){
            last=new NodeMap<T,V>;
            last->key=k;
            last->value=v;
            last->next=temp;
            first=last;
            counter++;
            return;
        }
        while(temp->next){
            if(temp->key==k){
                temp->value=v;
                return;
            }
            else if(temp->key<k&&temp->next->key>k){
                last=new NodeMap<T,V>;
                last->key=k;
                last->value=v;
                last->next=temp->next;
                temp->next=last;
                counter++;
                return;
            }
            temp=temp->next;
        }
        last=new NodeMap<T,V>;
        last->key=k;
        last->value=v;
        last->next=NULL;
        temp->next=last;
        counter++;

    }
}
template<class T,class V>
NodeMap<T, V> *Map<T, V>::find(T k) const {
    NodeMap<T,V> *temp=first;
    while(temp){
        if(temp->key=k)
            return temp;
        temp=temp->next;
    }
}


#endif //HW4_MAP_H
