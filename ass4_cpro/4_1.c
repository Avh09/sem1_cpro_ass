#include<stdio.h>
int func(int flag,int arr[5]);
int verify(int flag,int store[5], int arr[5]);
int dou(int flag,int i,int store[5], int arr[5]);
//int flag=0;
int main(){
    
    int arr[10] = {2,1,1,1,1};
    int store[10];
    for(int j=0;j<5;j++){
            store[j]=arr[j];
        }
        // printf("store original : ");
        // for(int i=0;i<5;i++){
        // printf("%d ",store[i]);
        // }
        // printf("\n");
    
    for(int k=0;k<5;k++){
        int flag=0;
        for(int j=0;j<5;j++){
            store[j]=arr[j];
        }
        // printf("store : ");
        // for(int i=0;i<5;i++){
        // printf("%d ",store[i]);
        // }
        // printf("\n");
        func(flag,arr);
        // printf("\narr : ");
        // for(int i=0;i<5;i++){
        // printf("%d ",arr[i]);
        // }
        // printf("\n");

        verify(flag,store,arr);
        if(flag==1){
            for(int j=0;j<5;j++){
            store[j]=arr[j];
            }

        }
        
        
        
        //printf("\n");
    }
    for(int i=0;i<5;i++){
            printf("%d ",store[i]);
    }
}

int func(int flag,int arr[5]){
    int a = arr[4];
    
    for(int i=5;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=a;
    return arr[5];
}

int verify(int flag,int store[5], int arr[5]){
    //int flag=0;
    // printf("\nverify store : ");
    // for(int i=0;i<5;i++){
    //         printf("%d ",store[i]);
    // }
    // printf("\nverify arr : ");
    // for(int i=0;i<5;i++){
    //         printf("%d ",arr[i]);
    // }
    

    if(arr[0]<store[0]){
        flag=1;
        return flag;
        //printf("\n***\n");
    }
    else if(arr[0]==store[0]){
        int i=1;
        dou(flag,i,store,arr);
        return flag;
    }
    else{
        return flag;
    }
}

int dou(int flag,int i,int store[5], int arr[5]){
    if(arr[i]==store[i]){
        i++;
        dou(flag,i,store,arr);
    }
    else if(arr[i]<store[i]){
        flag=1;
    }
    return flag;

}