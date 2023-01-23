#include <stdio.h>
#include <stdlib.h>
int n,m,k,counter;
char data[50005001],*pf=data,*pb=data;
int main()
{
    scanf("%d %d %d %s",&n,&m,&k,data);
    m++;
    for(int i=0 ; i<n ; i++){
        counter=0;
        for(int j=0 ; j<m ; j++){
            if(*pb-'0') counter++;
            pb++;
        }
        if(counter%2==k) *pf='0';
        else *pf='1';
        pf++;
    }
    *pf='\0';
    printf("%s",data);
    return 0;
}
