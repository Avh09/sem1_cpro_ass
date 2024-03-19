#include<stdio.h>

//void func1();
// void func2(char *str,int total,int mango,int n,int k,int c);

void func2(char *str,int total,int mango,int n,int k,int c,int q){
    printf("flag : %c\n", str[n-1]);
    int fck=str[n-1];
    if(str[n-1]-97 < 13){
        printf("flag : 4\n");
        int  mango=mango+q;
            
        
        int index=1;
        for(int h=1;h<26;h++){
            //printf("\n----\n");
            if((str[n-index])-fck!=mango){
                str[n-index]++;
                printf("%c\n",str[n-index]);
            }
        
            if(str[n-index]-fck==mango){
                printf("%c...%c...%d\n",str[n-index],fck,mango);
                printf("%s",str);
                break;
            }

            if(str[n-index]=='z'){
                index++;
                int h=1;
            }
        }
    }

    else if(str[n-1]-97 >= 13){
        //printf("%c--------\n",str[n-1]);
        //int mango=mango-q;
        printf("%d*****\n",mango);
        str[n-1]=c;
        
        //printf("%c****",str[n-1]);
        int index=2;
        for(int h=1;h<26;h++){
            //printf("\n----\n");
            if((str[n-index])-fck!=mango){
                
                //printf("%c___",str[n-index]);
                str[n-index]++;
                
                //printf("%c\n",str[n-index]);
                
            }
        
            else if(str[n-index]-fck==mango){
                printf("%c..%d\n",str[n-index],mango);
                printf("%s",str);
                break;
            }

            else if(str[n-index]=='z'){
                mango=mango-25;
                index++;
                int h=1;
            }
        }

    }
} 

        

int main(){
    int n,k,q;
    scanf("%d %d",&n,&k);
    char str[8];
    scanf("%s",str);
    int c=97;
    
    
        int total=0,mango=k;
        for(int i=0;i<n;i++){
            int q=str[i]-c;
            total=total+q;
            
            if(total>k){
                str[i]=str[i]-mango;
                printf("%s",str);
                break;   
            }
            if(total==k){
                str[i]=c;
                printf("%s",str);
                break;
            }
            if(total<k){
                int temp=str[i]-97;
                str[i]=c;
                mango-=total;
                //printf("%d-*",)


                
                

                if( i==n-1 && mango!=0){
                    printf("%d-----",mango);
                    str[i]+=temp;
                    //printf("%s...\n",str);
                    printf("flag : 1\n");
                    
                    func2(str,total,mango,n,k,c,q);
                }

                if(mango>0){
                    str[i]=c;
                    //continue;
                }
                
            }
        }   
        
        return 0;
}