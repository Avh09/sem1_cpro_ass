#include <stdio.h>
#include<string.h>
#define MAX_LINE_LEN 1024

int main() {
  char address[MAX_LINE_LEN];
  char file_name[MAX_LINE_LEN];
  
  FILE *fp;
  //char *gets(char* s);
  char* fgets(char* str,int n,stdin);
  /*Taking your address as input. These will be appended into a file...*/
  printf("Your address: ");
  fgets(address,20,stdin);
  
  /*Taking the file name as input...*/
  printf("Enter the file name to append to: ");
  fgets(file_name);
  
  /*Opening the file in appending mode...*/
  fp = fopen(file_name, "a+");
  
  /*File open operation failed.*/
  if (fp == NULL) return -1;
  
  /*Appending your address into the file...*/
  fprintf(fp, "Your address: %s\n", address);
  
  /*Closing the file...*/
  fclose(fp);
  
  printf("Your address is appended to the file %s. Open and check.\n", file_name);
  return 0;
}
