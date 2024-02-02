/***********************************************************
 * @file name: STL_set.cpp
 * @author: liubo
 * @date: 2024.02.02
 * @describe: template
 * 
 * 
 **********************************************************/
#include"STL_set.h"

Bool Set::Member(int elem) {
    for(int i=0;i<card;++i) {
        if(elems[i]==elem) {
            return True;
        }
    }
    return False;
}

ErrCode Set::AddElem(int elem) {
    if(Member(elem)) {
        return noErr;
    }
    if(card<size) {
        elems[card++]=elem;
        return noErr;
    }
    return overflow;
}

void Set::RmvElem(int elem) {
    for(int i=0;i<card;++i) {
        if(elems[i]==elem) {
            for(;i<card-1;++i) {
                elems[i]=elems[i+1];
            }
            --card;
            return;
        }
    }
}

void Set1::Copy(Set *set) {
    for(int i=0;i<card;++i) {
        set->elems[i]=elems[i];
    }
    set->card=card;
}

void Set::Copy(Set *set) { // this -> set
    if(set->size<size) {
        delete []set->elems;
        set->elems=new int[size];	
        set->size=size;
    }
    for(int i=0;i<card;++i) {
        set->elems[i]=elems[i];
    }
    set->card=card; 
}

Bool Set::Equal(Set *set) {
    if(card!=set->card) {
        return False;
    }
    for(int i=0;i<card;++i) {
        if(!set->Member(elems[i])) {
            return False;
        }
    }
    return True;
}

void Set::Print() {
    cout<<"{";
    for(int i=0;i<card;++i) {
        cout<<elems[i]<<";";
    }
    cout<<"}\n";
}

void Set2::Print() {
    cout<<"{";
    for(int i=0;i<card-1;++i) {
        cout<<elems[i]<<";";
    }
    if(card>0) {
        cout<<elems[card-1];
    }
    cout<<"}\n";
}










void Set1::Intersect(Set *set,Set *res) {//*this Π *set->*res
    res->card=0;
    for(int i=0;i<card;++i) {
        for(int j=0;j<set->card;++j) {
            if(elems[i]==set->elems[j]) {
                res->elems[res->card++]=elems[i];
                break;
            }
        }
    }
}



void Set::Intersect(Set *set,Set *res)
{
  if(res->size<size)
  {
    delete []res->elems;
    res->elems=new int[size];
    res->size=size;	
  }	
  res->card=0;
  for(int i=0;i<card;++i)
     for(int j=0;j<set->card;++j)
        if(elems[i]==set->elems[j])
          {
             res->elems[res->card++]=elems[i];
             break;	
          }
}















ErrCode Set::Union(Set *set,Set *res) {
    set->Copy(res); // set->res
    for(int i=0;i<card;++i) {
        if(res->AddElem(elems[i])==overflow) {
            return overflow;
        }
    }
    return noErr;
}


