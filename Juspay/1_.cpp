#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)    for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
using namespace chrono;
int inf=1e9+7, MOD=1e9+7;

int w = 1;

struct Tree{
    public :
        bool isLocked;
        bool isLockable;
        int id;
        int ma;
        Tree* p;
        vector<Tree*> c; 
        Tree(){
            isLocked = false;
            isLockable = true;
            id = -1;
            ma = w++;
            p = NULL;
        }
        Tree(Tree* parent){
            isLocked = false;
            isLockable = true;
            id = -1;
            ma = w++;
            p = parent;
        }
};
        // bool ll(Tree* n) return n->l;

        bool locking(Tree* n, int uuid)
        {
            if(n->isLockable == false || (n->isLocked)) return false;
            Tree* T = n;
            queue<Tree*> q;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    if(x->isLocked) return false;
                    q.push(x);
                }
            }
            n->id = uuid;
            n->isLocked = true;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    x->isLockable = false;
                    q.push(x);
                }
            }
            return true;
        }
        
        bool unlocking(Tree* n,int uuid){
            if(n->isLockable == false || n -> isLocked == false || (n->isLocked && uuid != n->id)) return false;
            Tree* T = n;
            n->isLocked= false;
            n->id = -1;
            queue<Tree*> q;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    x->isLockable = true;
                    q.push(x);
                }
            }
            return true;
        }

        bool update(Tree* n,int uuid){
            if(n->isLockable == false || n->isLocked == true) return false;
            Tree* T = n;
            queue<Tree*> q;
            q.push(T);
            bool f = false;
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    if(x->isLocked == true && x->id != uuid) { return false; }
                    if(x->isLocked) f = true;
                    q.push(x);
                }
            }
            if(!f) return false;
            // n->isLocked =  true;
            // n->id = uuid;
            // queue<Tree*> q;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    if(x->isLocked){