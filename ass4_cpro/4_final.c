#include<stdio.h>
#include<string.h>

char* func(int flag,int n,char *arr);
int verify(int flag,int n,char *store,char *arr);
int dou(int n,char *store,char *arr,int i);
int verifyyy(int flag,int n,char *pre,char *arr);
int doubbb(int n,char *pre,char *arr,int i);

int main(){
    char arr[1001];
    char store[1001];
    char pre[1001];
    scanf("%s", arr);
    int n = strlen(arr);
    
    for(int j=0;j<n;j++){
            store[j]=arr[j];
    }
    for(int j=0;j<n;j++){
            pre[j]=arr[j];
    }
    
    for(int k=0;k<n;k++){
        int flag=0;
        func(flag,n,arr);
        verify(flag,n,store,arr);
        
        if(verify(flag,n,store,arr)==1){
            for(int j=0;j<n;j++){
            store[j]=arr[j];
            }

        }
        verifyyy(flag,n,pre,arr);
        if(verifyyy(flag,n,pre,arr)==2){
            for(int j=0;j<n;j++){
            pre[j]=arr[j];
            }
        }
    }
    
    for(int i=0;i<n;i++){
            printf("%c",store[i]);
    }

    printf("\n");

    for(int i=0;i<n;i++){
            printf("%c",pre[i]);
    }
}

char* func(int flag,int n,char *arr){
    char a = arr[n-1];
    for(int i=n;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=a;
    return arr;
}

int verify(int flag,int n,char *store,char *arr){
    if(arr[0]<store[0]){
        flag=1;
        return flag;
    }
    else if(arr[0]==store[0]){
        int i=1;
        dou(n,store,arr,i);
        return dou(n,store,arr,i);
    }
    else{
        return flag;
    }
}

int dou(int n,char *store,char *arr,int i){
    int flag=0;
    if(arr[i]==store[i]){
        i++;
        dou(n,store,arr,i);
    }
    else if(arr[i]<store[i]){
        flag=1;
        return flag;
    }
    else{
        return flag;
    }
}

int verifyyy(int flag,int n,char *pre,char *arr){
    if(arr[0]>pre[0]){
        flag=2;
        return flag;
        //printf("\n***\n");
    }
    else if(arr[0]==pre[0]){
        int i=1;
        doubbb(n,pre,arr,i);
        //printf("********%d\n",dou(n,store,arr,i));
        return doubbb(n,pre,arr,i);
    }
    else{
        return flag;
    }
}

int doubbb(int n,char *pre,char *arr,int i){
    int flag=0;
    if(arr[i]==pre[i]){
        i++;
        doubbb(n,pre,arr,i);
    }
    else if(arr[i]>pre[i]){
        //printf("######\n");
        flag=2;
        //printf("after # %d\n",flag);
        return flag;
    }
    //return flag;
    else{
        return flag;
    }
}
