#include<stdio.h>
int n,k;
int main(){
    int total=0,tot=0;
    scanf("%d %d",&n,&k);
    char str[n+1];
    scanf("%s",str);
    for(int i=0;i<n;i++){
        total+=(str[i]-'a');
    }
    if(total>=k){
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=str[i]-'a';
            if(tot<k){
                str[i]='a';
                continue;
            }
            else if(tot==k){
                str[i]='a';
                printf("%s\n",str);
            }
            else if(tot>k){
                tot=(tot-(str[i]-'a'));
                int left=k-tot;
                str[i]=str[i]-left;
                printf("%s\n",str);
                break;
                
            }
        }
    }
    else if(total<k){
        char str2[n];
        int diff=k-total;
        
        for(int i=0;i<n;i++){
            str2[i]='a';
        }

        for(int i=n-1;i>=0;i--){
            int lol=0;
            if(diff==0){
                break;
            }
            
            else if(i==0 && diff>25){
                printf("-1");
                return 0;
            }
            
            else if(str[i]>'m'){
                str2[i]='a';
                break;
            }

            else if(str[i]<='m'){
                str2[i]=str[i]+1;
                diff=diff-1;
                int chu=0;
                for(int j=0;j<26;j++){
                    if(diff==0){
                        str2[i]=str2[i];
                        break;
                    }
                    else if(str2[i]=='z'){
                        str2[i]='z';
                        break;
                    }

                        else{
                        if(chu==0)
                        {
                        str2[i]=str[i];
                        diff=diff+((str[i]-'a'));
                        lol='z'-str[i];
                        chu=1;
                        }

                        else if(diff<=lol)
                        {
                        str2[i]=str2[i]+diff;
                        diff=0;
                        }

                        else if(diff>lol){
                            str2[i]='z';
                            diff-='z'-str[i];
                            break;
                        }
                    }
                }
            }
        }
        printf("%s",str2);
    }
    return 0;   
}
