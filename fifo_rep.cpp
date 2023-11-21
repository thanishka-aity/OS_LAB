#include <bits/stdc++.h>
using namespace std;


int findpagefaults(int pages[],int frames, int n){
    queue<int> indexes;
    unordered_set<int> set;
    int pf = 0;
    
    for(int i=0;i<n;i++){
        if(set.size() < frames){
            if(set.find(pages[i]) == set.end()){
                set.insert(pages[i]);
                pf++;
                indexes.push(pages[i]);
            }
        }
        
        else{
            if(set.find(pages[i]) == set.end()){
                int val = indexes.front();
                indexes.pop();
                set.erase(val);
                indexes.push(pages[i]);
                set.insert(pages[i]);
                pf++;
            }
        }
    }
    return pf;
}




int main()
{
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frames = 4;
    int pf = findpagefaults(pages,frames,n);
    cout<<"number of pagefaults: "<<pf;
    return 0;
}
