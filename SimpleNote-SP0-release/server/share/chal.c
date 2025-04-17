#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZEMAX 8

unsigned short SIZE_ARRAY[SIZEMAX];
unsigned char *NOTE_ARRAY[SIZEMAX];

void menu(){
    puts("=============");
    puts("(1) Add");
    puts("(2) edit");
    puts("(3) delete");
    puts("(4) show");
    puts("(5) GIFT");
    puts("=============");
    printf("Note > ");
}

int get_choice(){
    int choice;
    scanf("%d", &choice);
    return choice;
}

void init_proc(){
    setvbuf(stdin, 0, _IONBF, 0);
    setvbuf(stdout, 0, _IONBF, 0);
}

int get_index(){
    unsigned int index;
    scanf("%d", &index);
    if (index > sizeof(SIZE_ARRAY)){
        puts("[x] Index out of the range");
        exit(0);
    }
    return index;
}

int get_size(){
    int size;
    printf("Input Size > ");
    scanf("%d", &size);
    if (size > 0x100){
        puts("[x] Not enough memory ");
        exit(0);
    } else{
        return size;
    }
    
}

void add_note(){
    printf("Input Index > ");
    int index = get_index();
    if (NOTE_ARRAY[index]){
        puts("[x] Index have been used");
    } else{
        int size = get_size();
        if(!(NOTE_ARRAY[index] = (unsigned char*)malloc(size))){
            puts("[x] Memory allocate failed");
            exit(0);
        } else {
        
            SIZE_ARRAY[index] = size;
            memset(NOTE_ARRAY[index], 0, SIZE_ARRAY[index]);
            puts("[!] Success Allocate");
            return;
            
        }
    }
}

void FLUSH(){
    while (getchar() != '\n'); 
}

void get_content(int index){
    printf("Input Content > ");
    FLUSH();
    fgets(NOTE_ARRAY[index], SIZE_ARRAY[index], stdin);
    return;
}

void edit_note(){
    printf("Input Index > ");
    int index = get_index();
    if(!NOTE_ARRAY[index]){
        puts("[x] Not allocate anything");
        exit(0);
    } else {
        get_content(index);
        return;
    }
    
}

void delete_note(){
    printf("Input Index > ");
    int index = get_index();
    if(!NOTE_ARRAY[index]){
        puts("[x] Not allocate anything");
        exit(0);        
    } else{
        free(NOTE_ARRAY[index]);
        NOTE_ARRAY[index] = NULL;
        return;
    }
}

void show_note(){
    printf("Input Index > ");
    int index = get_index();
    if(!NOTE_ARRAY[index]){
        puts("[x] Not allocate anything");
        exit(0);
    } else {
        printf("Content : ");
        fwrite(NOTE_ARRAY[index], SIZE_ARRAY[index], sizeof(unsigned char), stdout);
    }
}


int main(){
    init_proc();
    while(true){
        menu();
        int choice = get_choice();
        
        if (choice == 1){
            add_note();
        } else if(choice == 2){
            edit_note();
        } else if(choice == 3){
            delete_note();
        } else if(choice == 4){
            show_note();
        } else if(choice == 5){
            size_t stack_var;
            printf("[!] gift: %p \n", (char *)&stack_var);
        } else{
            puts("[!] Bye Bye !");
            break;
        }
        
    }

    return 0;
}
