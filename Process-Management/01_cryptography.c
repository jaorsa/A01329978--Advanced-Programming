#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef struct Dictionary
{
    char alphabet[27];
    char cipher[27];
} Dict;

size_t sizeArray = 0;
char message[1024];
char encrypted_message[1024];
char decrypted_message[1024];

char findNextChar(char keyphrase[27], char tmp){
    if(tmp == 123){
        tmp = 97;
    }
    for (size_t i = 0; i < 27; i++)
    {
        if(tmp == keyphrase[i]){
            tmp+=1;
            i=0;   
        }
    }
    return tmp;
}

Dict createDict(Dict dict, char keyphrase[27]){
    int i = 0;
    char tmp='a';
    /* Copy keyphrase */
    while(dict.cipher[27] == '\0'){
        if(keyphrase[i] != ' ' && keyphrase[i] != '\0'){
            keyphrase[i] = tolower(keyphrase[i]);
            dict.cipher[i] = tolower(keyphrase[i]);

            if(keyphrase[i] > tmp){
                tmp = keyphrase[i];
            }
        }
        else{
            tmp = findNextChar(keyphrase, tmp+1);
            dict.cipher[i] = tmp;
        }
        dict.alphabet[i] = 'a'+ i;
        i++;
    }
    return dict;
}

void encryptmessage(Dict dictionary){
    printf("The encrypted message says: \n");
    for (size_t i = 0; i < sizeArray; i++)
    {
        for (size_t j = 0; j < 27; j++)
        {
            if(tolower(message[i]) == dictionary.alphabet[j]){
                encrypted_message[i] = dictionary.cipher[j];
            }
            if(message[i] == ' ' || message[i] == '\n'){
                encrypted_message[i] = message[i];
            }
        }
        printf("%c",encrypted_message[i]);
    }
    printf("\n");
}

void decryptmessage(Dict dictionary){
    printf("The decrypted message says: \n");
    for (size_t i = 0; i < sizeArray; i++)
    {
        for (size_t j = 0; j < 27; j++)
        {
            if(encrypted_message[i] == dictionary.cipher[j]){
                decrypted_message[i] = dictionary.alphabet[j];
            }
            if(encrypted_message[i] == ' ' || encrypted_message[i] == '\n'){
                decrypted_message[i] = message[i];
            }
            
        }
        printf("%c",decrypted_message[i]);
    }
    printf("\n");
}

void main(){
    char keyphrase[27];
    int i = 0;
    char tmp;

    struct Dictionary dict;
    memset(keyphrase,' ',27);
    
    clock_t begin = clock();

    FILE *ptr;
    ptr = fopen("input.txt", "r+");

    if(ptr == NULL){
        printf("Archivo inexistente\n");
        exit(1);
    }

    printf("Give me your password\n");
    scanf("%s", keyphrase);
    dict = createDict(dict, keyphrase);

    while(fscanf(ptr, "%c", &tmp) != EOF){
        message[sizeArray] = tmp;
        sizeArray++;
    }

    while (i != 2)
    {
        printf("Press 0 to encrypt the message\nPress 1 to decrypt the message\nPress 2 to terminate the program\n");
        scanf("%d", &i);
        switch(i){
            case 0: 
                encryptmessage(dict);
            break;
            case 1: 
                decryptmessage(dict);
                break;
        }
    }
    
    
    
    clock_t end = clock();
    printf("Time executed in seconds %f\n",(double)(end-begin)/ CLOCKS_PER_SEC);
    fclose(ptr);
}