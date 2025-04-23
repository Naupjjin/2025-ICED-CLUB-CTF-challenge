#include <stdio.h>
#include <stdlib.h>

int choice = 0;
long long magic_index = 0;
long long COOL_MAGIC[4] = {0x100000, 0x200000, 0x300000, 0x400000};
long long MAGIC_PARAM;

void init_proc(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void magic_gift(){
    puts("Welcome to magic world!");
    printf("First, I will give you a cool number: %p\n", (void *)printf);
}

int main(){
    init_proc();
    magic_gift();
    puts("Which magic do you like ?");
    char MAGIC[0x28];
    fgets(MAGIC, sizeof(MAGIC), stdin); 
    
    puts("I will give you a kind of magic, called OOB");
    
    while(1){
        printf("Get choice > ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("MAGIC ! OOB READ > ");
            if (scanf("%lld", &magic_index) != 1) {
                exit(0);
	    } else{
                printf("result ! %llx\n", COOL_MAGIC[magic_index]);
                if (magic_index > 100 || magic_index < -100){
		    printf("Magic Error !!!");
		    exit(0);
		}
	    }
        } else if(choice == 2){
            printf("MAGIC ! OOB WRITE > ");
            if (scanf("%lld", &magic_index) != 1) {
                exit(0);
            } else{
                printf("Adjust your magic param ! ");
                if (scanf("%lld", &MAGIC_PARAM) != 1) {
                    exit(0);
                } else{
                    COOL_MAGIC[magic_index] = MAGIC_PARAM;
                    printf("result ! %llx\n", COOL_MAGIC[magic_index]);
                }
            }
        } else {
            break;
        }
    }
    
    puts("Imagination is the source of all magic ~");

    return 0;
}
