#include<stdio.h>
int main(){
    int z,a,b,c=0;
    scanf("%d",&z);
     
    for(int i=0;;i++){
        
        a=z/2;
        b=z%2;
        z=a;

        
             if(b==1){
                c++;
                

             }
           

           if(a==0){
            break;
           }
                 
          
    } 
         printf("%d",c);
    
   
    return 0;
}
    