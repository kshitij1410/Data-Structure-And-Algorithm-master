#include<bits/stdc++.h>
using namespace std;
int m;
unordered_map<string,int>idx;
vector<string>v;
unordered_map<string,int>lockable;
unordered_map<string,set<string>>lockChildList;

int getParent(int index)
{
	if(index==0) return -1;

   int temp=(index-1)/m;
   return temp;
}

bool unlock(string x,int id)
{
	//check whether the node is lock or not
	if(lockable.find(x)==lockable.end())
	return false;

	//check it is remove by same id or not
	int _id=lockable[x];
	if(_id!=id) return false;

	//now we have to remove this node from lockable vector
	lockable.erase(x);

	//now we have remove from their ancestor also in locachildlist
	int i=getParent(idx[x]);
	while(i!=-1)
	{
       lockChildList[v[i]].erase(x);
	   i=getParent(i);
	}

   return true;
}

bool lock(string x,int id)
{ 
  // check if node is already lock or not
  if(lockable.find(x)!=lockable.end())
  return false;

  //check their descandants is lock or not
  if(lockChildList[x].size()>0)
    return false;

  //lets check their ancestor is lock or not

  int i=idx[x];  

  while(i!=-1)
  {
    if(lockable.find(v[i])!=lockable.end())
	return false;
    i=getParent(i);
  }

  //lets store all the ancestor node of x 
  i=getParent(idx[x]);

  while(i!=-1)
  {
	  lockChildList[v[i]].insert(x);
	  i=getParent(i);
  }

  //then lock particular node by the given id
  lockable[x]=id;

  return true;
}

bool upgradeLock(string x,int id)
{
	//check node is already lock or not
	if(lockable.find(x)!=lockable.end()) return false;

	set<int>storeIdx;
    
	for(auto it=lockChildList[x].begin(); it!=lockChildList[x].end();it++)
	{
		storeIdx.insert(lockable[*it]);  // store the id of all users
	}

	if(storeIdx.size()==0 || storeIdx.size()>1) return false;

	int _id = *(storeIdx.begin());

	//now upgrade the descandants to be unlock
	set<string>temp(lockChildList[x]);
	for(auto it=temp.begin();it!=temp.end();it++)
	{
		unlock(*(it),id);
	}
	
	return lock(x,id);
}


int main()
{
	int n,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
	{
        string temp;
		cin>>temp;
		idx[temp]=i;
		v.push_back(temp);
	}

	while(q--)
	{
		int op,id;
		string opname;
		cin>>op>>opname>>id;
		bool ans=0;

		if(op==1)
		{
			//lock operation
			ans=lock(opname,id);

		}
		else if(op==2)
		{
			//unlock operation
			ans=unlock(opname,id);
		}
		else if(op==3)
		{
			//upgrade operation
		    ans=upgradeLock(opname,id);
			
		}
		else{
			//do nothing 
		}

		if(ans==1) cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}

	return 0;

}