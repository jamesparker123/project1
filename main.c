/*
This program will be able to perform multiple tasks:
 - Encrypt a message using a rotation cypher.
 - Decrypt a message encrypeted with a rotation cypher.
 - Encrypt a message using a substitution cypher. 
 - Decrypt a message encrypted wiht a substitution cypher. 
 */
 
#include <stdio.h>
#include <string.h>

int main() {
    
// declare the variables and strings. 
int a;
int i, key, A, B;
char message[] = "DATG";
char convert[9999];

// ask the user what task they would like to perform.
printf("Which task would you like to perform?\n");
printf("1. Encryption of a message with a rotation cypher.\n");
printf("2. Decryption of a message encrypted with a rotation cipher.\n");
printf("3. Encryption of a message with a substitution cipher.\n");
printf("4. Decryption of a message encrypted with a substitution cipher.\n");
//printf("5. Decryption of a message encrypted with a rotation cipher given cipher text only.\n");
//printf("6. Decryption of a message encrypted with a substitution cipher given cipher text only.\n");
    scanf("%d", &a);
   
   // performing task based on the user's selection.
    switch(a) {
       case 1: //encrypt a message using rotational cipher given the message and key.
       
       // read the key from the user.       
       printf("What is the key? \n");
        scanf("%d", &key);

       for(i = 0; i < strlen(message); i++) {
         A = message[i] - 65;
         if(A == -33) {
           B = A;
           convert[i] = B + 65;
           printf("\n");
       }
         else {
           B = (A + key) % 26;
           convert[i] = B + 65;
       }
    }
    printf("The encrypted message is: %s\n", convert);
       break;

       case 2: // decrypt a message that was encrypted with a rotational cypher. 
       
       // read the key from the user. 
       printf("Enter the key that was used to encrypt the message: \n");
        scanf("%d", &key);
       
       for(i = 0; i < strlen(message); i++) {
       A = message[i] - 65;
       if(A == -33) {
           B = A;
           convert[i] = B + 65;
           printf("\n");
       }
       else {
           B = (A + (26 - key)) % 26;
           convert[i] = B + 65;
       }
    }
    printf("The decrypted message is: %s\n", convert);
       break;
       
       case 3:
       
       printf("PUT STUFF HERE\n");
       break;
       case 4:
       
       printf("PUT STUFF HERE\n");
       break;
       //case 5:
       
       //case 6:
       
       default: 
       printf("That is not an option.\n");
    }

    return 0;
}
