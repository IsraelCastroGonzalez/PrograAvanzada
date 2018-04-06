#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
* APPROACH:
* How I would solve this is by comparing every substring | _p_ | 
* of length | _v_ | and output every one of those that differ 
* with _v_ at most in 1 character. But given the fact that _p_ 
* is basically an array of lenght n and I would need to make n 
* linear compartions divided with the size of | _v_ | this could be 
* very slow but given the fact that I do not have a lot of time 
* I think its ok for the moment.
* **EDIT:** Figured the time would be O( | _p_ || _v_ | ) which is linear, 
* which is really slow. But still i dont have a lot of time to think about a better approach.
*/


int main()
{
    int t,i,j,len,l,flag;
    char p[1000001];
    char v[1000001];
    scanf("%d",&t);
    while(t--)
    {
        int t=0;
        scanf("%s",p);scanf("%s",v);
        len = strlen(p);l = strlen(v);
        
        for(i=0;i<=(len-l);i++)
        {
            flag=0;
            for(j=0;j<l;j++)
                if(p[i+j]==v[j])
                   flag++;
                
            if((flag==l)||(flag==(l-1)))
            {
                t=1;printf("%d ",i);
            }   
        }
        if(!t) printf("No Match!");
        printf("\n");
    }    
    return 0;
}   