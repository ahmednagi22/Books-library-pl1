#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void Insert(void);
void Delete(void);
void search_id(int id,int i);
void search_name(void);
void display_sorted(int);
void display_unsorted(void);
void implement(void);
  FILE *file;
int option,id,i=0;
int counter=0,p=0;
char check[5];
char ch1[5]="yes";
char ch2[5]="YES";
    struct Details{
       int id;
       char name[40];
       int quantity;  };
       struct Details books_detail[30];
        struct Details D[30];//struct for sorted data
int main(){
file=fopen("book data","r");             //start implement data from file to array of struct
if(file==NULL){printf("file cannot be found");}
    else{
            while(!feof(file)){
           fscanf(file,"%d\t",&books_detail[counter].id);
           fscanf(file,"\t%[^_]%*s",&books_detail[counter].name);
           fscanf(file,"%d\n",&books_detail[counter].quantity);
           counter++;
                              }
} fclose(file);
                                          //end implement data from file to array of struct
do{
     printf("1:Insert a book \n");
     printf("2:Delete a book by id\n");
     printf("3:Search a book by id\n");
     printf("4:Search a book by name\n");
     printf("5:Display all books sorted(id,name,quantity)\n");
     printf("6:Display all books unsorted(id,name,quantity)\n");
     printf("enter option:");
     scanf("%d",&option);
     getchar();
    // system("cls");
   switch(option){
    case 1:Insert();break;
    case 2:Delete();break;
    case 3:printf("enter id to search:");
           scanf("%d",&id);
           search_id(id,i);
           break;
    case 4:search_name();break;
    case 5:display_sorted(1);break;
    case 6:display_unsorted();break;
   }implement();
 printf("would you like to make another operation press (yes or no):\n");
 scanf("%s",check);
    // system("cls");
          }
   while(strcmp(check,ch1)==0||strcmp(check,ch2)==0);//repeat program
   return 0;
   }
void Insert(void){                        //start insert book function

        printf("enter book id:");
        scanf("%d",&books_detail[counter].id);
        getchar();
        printf("enter book name:");
        gets(books_detail[counter].name);
        printf("enter book quantity:");
        scanf("%d",&books_detail[counter].quantity);
        counter++;
    }                                      //end insert book function
void Delete(void){                      //start delete book function
     int j,d,q=0,delete_id;
      printf("enter book id to Delete:");
      scanf("%d",&d);
         for(q=0;q<counter;q++){
            if(books_detail[q].id==d)break;
         }if(q<counter){                   //if id was found
         counter--;
         for(j=q;j<counter;j++){
                books_detail[j].id=books_detail[j+1].id;
         }
         books_detail[j].quantity=books_detail[j+1].quantity;
         }
         else{printf("ID NOT FOUND\n");}
                }                           //end delete function


void search_id(int id,int i){            //   start search books function with id recursion
   if(i<counter)
    {       if(id==books_detail[i].id){
            printf("Book ID=%d\nBook name=%s\nBook Quantity=%d\n",books_detail[i].id,books_detail[i].name,books_detail[i].quantity);
             i++;return search_id(id,counter+1);
            }
            else {i++;
                return search_id(id,i);}
    }
   else if(i==counter){printf("cannot find this id\n");}
  }                          //   end search books function with id recursion
void search_name(void){
     display_sorted(0);
     int low=0,middle,high=p-1;char key[25];
     int cheak_num=0;
    printf("enter book name to search:");
    gets(key);
     while(low<=high){
        middle=(low+high)/2;
        if(strcmp(key,D[middle].name)==0){
            printf("Book ID=%d\nBook name=%s\nBook Quantity=%d\n",D[middle].id,D[middle].name,D[middle].quantity);
            cheak_num=1;low=10;
        }
        else if(strcmp(key,D[middle].name)==-1){low=middle+1;}
        else high=middle-1;
    }
    if(cheak_num==0){printf("name not found\n");}
}
void display_sorted(int mine){                           //start display books function from file in sorted
    int h=0,g;char s_temp[40];

     file=fopen("book data","r");             // new array of struct so the main array and file not change
if(file==NULL){printf("file cannot be found");}
    else{ while(!feof(file)){
           fscanf(file,"\t%d",&D[p].id);
           fscanf(file,"\t%[^_]%*s",D[p].name);
           fscanf(file,"%d\n",&D[p].quantity);
           p++;
           }
} fclose(file);
   for(h=1;h<p;h++){
    for(g=0;g<p;g++){
    if(strcmp(D[h].name,D[g].name)>0){
            int temp;
            temp=D[g].id;
            D[g].id=D[g+1].id;
            D[g+1].id=temp;
            temp=D[g].quantity;
            D[g].quantity=D[g+1].quantity;
            D[g+1].quantity=temp;
            strcpy(s_temp,D[g].name);
            strcpy(D[g].name,D[g+1].name);
            strcpy(D[g+1].name,s_temp);
    }
    }
   }
   if(mine){
   printf("books id\tbooks name\tbooks quantity\n");
    for(int i=0;i<p;i++){
       printf("%4d\t\t%s\t\t%d\n",D[i].id,D[i].name,D[i].quantity);
                        }
               }
}                           //end display books function from file in sorted
    void display_unsorted(void){    //start display books function from file in unsorted
    printf("books id\tbooks name\tbooks quantity\n");
   for(int y=0;y<counter;y++){
   printf("%4d\t\t%s\t\t%d\n",books_detail[y].id,books_detail[y].name,books_detail[y].quantity);
   }
   }                           //end display books function from file in unsorted
void implement(void){                          //implement books data from array of struct to file
            file=fopen("book data","w");
            for(int z=0;z<counter;z++){
         fprintf(file,"%-10d",books_detail[z].id);
         fprintf(file,"%15s_",books_detail[z].name);
         fprintf(file,"%6.2d\n",books_detail[z].quantity);}
         fclose(file);
        }

