#include <stdio.h>
#include <stdlib.h>

int choice = 0;
int magic_index = 0;
unsigned long COOL_MAGIC[4] = {0x100000, 0x200000, 0x300000, 0x400000};
unsigned long MAGIC_PARAM;

void init_proc(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

int main(){
    init_proc();
    puts("Which magic do you like ?");
    char MAGIC[0x100];
    fgets(MAGIC, sizeof(MAGIC), stdin); 
    
    puts("I will give you a kind of magic, called OOB");
    
    while(1){
        printf("Get choice > ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("MAGIC ! OOB READ > ");
            if (scanf("%d", &magic_index) != 1) {
                exit(0);
            }
            else{
                printf("result ! %lx\n", COOL_MAGIC[magic_index]);
            }
        } else if(choice == 2){
            printf("MAGIC ! OOB WRITE > ");
            if (scanf("%d", &magic_index) != 1) {
                exit(0);
            } else{
                printf("Adjust your magic param ! ");
                if (scanf("%lu", &MAGIC_PARAM) != 1) {
                    exit(0);
                } else{
                    COOL_MAGIC[magic_index] = MAGIC_PARAM;
                    printf("result ! %lx\n", COOL_MAGIC[magic_index]);
                }
            }
        } else {
            break;
        }
    }
    
    puts("Magic is so cool !");

    return 0;
}