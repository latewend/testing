#include <stdio.h>
#include<unistd.h>

void add_one(char* me);

int main(int argc, char* argv[]){
    volatile long unsigned int c = 1;
    if (c <= 30){
        printf("%ld\n",c);
        add_one(*argv);
        execvp(*argv, argv);
    } else {
        printf("Done!\n");
    }
}

void add_one(char* me){
    FILE *ptr;
    int notfound = 1;
    ptr = fopen(me,"r+b");
    unsigned char a;
    int red= 0;
    
    while (notfound) {
        if (!red) {
            fread(&a,1,1,ptr);    
        } else {
            red = 0;
        }
        if (a == (unsigned char)(72) ){
            fread(&a,1,1,ptr);
            red = 1;
            if (a == (unsigned char)(199) ){
                fread(&a,1,1,ptr);
                if (a == (unsigned char)(69) ){
                    fread(&a,1,1,ptr);
                    fread(&a,1,1,ptr);
                    fseek(ptr, -1 , SEEK_CUR);
                    ftell(ptr);
                    a +=1;
                    fwrite(&a,1,1,ptr);
                    ftell(ptr);
                    notfound = 0;
                }
            }
            
        }
    }
    fclose(ptr);
}