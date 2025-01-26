#include<bits/stdc++.h>


using namespace std;

  
class SegmentTree{

   int n;
   vector<int>st;
   
   public:
   void init(int _n){
    this->n=_n;
    st.resize(4*n,0);

   }  

   int comb(int a,int b){
    return a+b;
   }


   void build(int start, int end,int node , vector<int>& arr){
     
     if(start==end){
      st[node]= arr[start];
      return;
     }

     int mid= (start + end )/2;

     build(start, mid, 2*node+1, arr);
     build(mid+1,end, 2*node+2, arr);

     st[node]= comb(st[2*node+1], st[2*node+2]);

   }
   

   void build(vector<int> &arr){
     
     build(0,n-1, 0 , arr);
    
   }

   int query(int start,int end, int l, int r, int node){
    
    if(start>r || end<l) return 0;

    if(start>=l && end<=r) return st[node];

    int mid= (start + end)/2;
   

   int q1= query(start,mid,l,r,2*node+1);
   int q2= query(mid+1,end,l,r,2*node+2);


    return comb(q1, q2);

   }

   int query(int l,int r){
    return query(0,n-1, l,r,0);
   }



   void update(int start, int end,int node, int index, int value){
    if(start==end){
      st[node]=value;
      return;
    } 

    int mid= (start+end)/2;

    if(index<=mid) update(start,mid,2*node+1, index,value);
     else update(mid+1,end, 2*node+2, index,value);
     

     st[node]= comb(st[node*2+1], st[node*2+2]);

     return;
         
   }
   
   void update(int index,int value){
   update(0,n-1,0,index,value);
   return; 
   }

   int walk(int start, int end,int node, int sum, int targetSum){
    
    if(start==end) return start;
     
     int mid= (start+end)/2;

     if(sum+st[2*node+1]>= targetSum) return walk(start,mid,2*node+1,sum,targetSum);

      return walk(mid+1,end,2*node+2,sum+st[node*2+1],targetSum);


   }

   int walk(int targetSum){ // wanted index
    
    return walk(0,n-1,0,0,targetSum);

   }    

};



int main(){
  
  vector<int>arr={3, 6 , 7 ,4 ,3 , 23, 2 , 2 ,11,9 };

  SegmentTree tree;
  
  int n;
  cin>>n;

  tree.init(n);

  tree.build(arr);

  
   
  for(int i=0;i<n;i++){
    tree.update(i,1);
  }


  int q;
  cin>>q;

  for(int i=0;i<q;i++){
    int x;
    cin>>x;

    int ans= tree.walk(x);
   
   cout<<arr[ans]<<" ";

    tree.update(ans,0);
  }


  return 0;
}