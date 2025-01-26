#include <bits/stdc++.h>
using namespace std;

class disjointSet{

vector<int>parent;
vector<int>rank;
vector<int>size;

public:
 disjointSet(int n){
  
  parent.resize(n+1);
  rank.resize(n+1);
  size.resize(n+1);
  
  for(int i=0;i<=n;i++){
    parent[i]=i;
  }

}  	
 

 int findUpar(int node){
  if(parent[node]==node) return node;

  return parent[node]= findUpar(parent[node]); // path compression
 }

 void unionByRank(int u,int v){
  int Upar_u= findUpar(u);
  int Upar_v= findUpar(v);
  if(Upar_u== Upar_v) return;

   if(rank[Upar_v]>rank[Upar_u]){
    parent[Upar_u]=Upar_v;
   }else if(rank[Upar_u]>rank[Upar_v]){
    parent[Upar_v]=Upar_u;
   }else{
    parent[Upar_v]=Upar_u;
    rank[Upar_u]++;
   }
 }

 void unionBySize(int u,int v){
  int Upar_u= findUpar(u);
  int Upar_v= findUpar(v);
  if(Upar_u== Upar_v) return;
    
    if(size[Upar_v]>size[Upar_u]){
     parent[Upar_u]=Upar_v;
     size[Upar_v]+= size[Upar_u];
    }else{
       parent[Upar_v]=Upar_u;
     size[Upar_u]+= size[Upar_v];
    }
    
  }

};


int main(){
   
   disjointSet ds(5);

   ds.unionBySize(1,4);
   ds.unionBySize(2,5);

   // find if 1 and 2 are connected
   if(ds.findUpar(1)==ds.findUpar(2)){
    cout<<"Same"<<endl;
   }else{
    cout<<"Not same"<<endl;
   }

      ds.unionBySize(2,4);
   // find if 1 and 2 are connected
   if(ds.findUpar(1)==ds.findUpar(2)){
    cout<<"Same"<<endl;
   }else{
    cout<<"Not same"<<endl;
   }
  return 0;
}