#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<int> road;
std::vector<int> usroad;
std::vector<int> vans;
int bag,ans,maxans=-1,i,j;
long long bags=0;

void report()
{
    i=(road.end())-(road.begin());
    ans=0;
    bags=0;
    for(j=0 ; j<i ; j++){
        bags+=road[j];
        if(bags>=bag){
            if(bags==bag) ans++;
            if(maxans<=ans){
                maxans=ans;
                vans.assign(usroad.begin(),usroad.end());
            }
            return;
        }
        ans++;
    }
    maxans=ans;
    vans.assign(usroad.begin(),usroad.end());
    return;
}

void deep()
{
    int get;
    scanf(" %d",&get);
    if(get == 0){
        report();
        return;
    }else{
        road.insert(lower_bound(road.begin(),road.end(),get),get);
        usroad.push_back(get);
    }
    deep();
    deep();
    road.erase(lower_bound(road.begin(),road.end(),get));
    usroad.pop_back();
    return;
}

int main()
{
    scanf("%d",&bag);
    deep();
    j=(vans.end())-(vans.begin());
    for(i=0 ; i<j ; i++){
        printf("%d ",vans[i]);
    }
    printf("0");
    return 0;
}
