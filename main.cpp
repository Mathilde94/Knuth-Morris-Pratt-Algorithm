#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <stdio.h>

using namespace std;

typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ITE(v) typeof(b.begin())
#define FORIT(it,v) for(ITE(v) it=v.begin();it!=v.end();it++)


void construct_table(int T [],int n, char W[]){
  T[0]=-1;
  T[1]=0;
  int pos(2),cnd(0);
  while (pos < n){
    if (W[pos-1]==W[cnd]){ cnd ++; T[pos]=cnd; pos++;} 
    else if (cnd>0) {cnd = T[cnd];}
    else {T[pos]=0; pos++;}
  }

}


int kmp(int T[], char W [],string S, int n){
  int m(0),i(0),count(0);
  while ( (m+i) < S.size()){
    if (i<n && W[i]==S[m+i]){
      if (i==n-1) { cout << m<<' ';count ++;}
      i++;
    }
    else{
      m=m+i-T[i];
      if (i<n && T[i]>-1) {i=T[i];}
      else {i=0;}
    }
  }
  cout << endl;
  return count;
}


int main(int argc, char *  argv []){

  string S("");string S_int("");
  while (getline(cin,S_int)){
    S+=S_int;
  }

  int n = strlen(argv[1]);
  char W [n+1];
  strcpy(W,argv[1]);
  int Table [n+1];
  memset(Table,0,sizeof(Table));

  construct_table(Table,n,W);
  int occurences= kmp(Table,W,S,n);
  cout <<occurences <<endl;

  return 0;
}
