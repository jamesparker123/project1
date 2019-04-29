/*
This program will be able to perform multiple tasks:
 - Encrypt a message using a rotation cypher.
 - Decrypt a message encrypeted with a rotation cypher.
 - Encrypt a message using a substitution cypher. 
 - Decrypt a message encrypted wiht a substitution cypher. 
 */
 
#include <stdio.h>
#include <string.h> // Include the function strlen().

int main() {
    
// Declare the variables and strings. 
int a; // Used to choose the task.
int i; // Used as counter and index.
int key; // The key for the rotational cipher.
int A; // Other variable used.
int B; // Other variable used.
char message[9999]; // String used for the given message.
char convert[9999]; // String used for the converted message.
char keysub[] = "PHQGIUMEAYLNOFDXJKRCVSTZWB"; // String used as the key for the substitution cipher.


// ask the user what task they would like to perform.
printf("Which task would you like to perform?\n");
printf("1. Encryption of a message with a rotation cypher.\n");
printf("2. Decryption of a message encrypted with a rotation cipher.\n");
printf("3. Encryption of a message with a substitution cipher.\n");

    scanf("%d", &a); // ask user what task to perform.
    
    
   
    // Performing task based on the user's selection.
    switch(a) {
        
       case 1: // Encrypt a message using rotational cipher given the message and key.
       
          // Read message from the user
          printf("What message do you want to encrypt?\n"); 
          scanf(" %[^\n]s", message); // reads all characters up to a new line.
        
          // Read the key from the user.       
          printf("What is the key? \n");
          scanf("%d", &key);

          // Conversion of letters
          for(i = 0; i < strlen(message); i++) {
           
             // If lowercase letters are entered, change them to uppercase.
             if(message[i] >= 97 && message[i] <=122) {
               message[i] = message[i] - 32;
             }
           
             // Change ASCII code to corresponding value from 0-25.
             A = message[i] - 65;
         
             // Convert all letters.
             if(0 <= A && A <= 25) {
                B = (A + key) % 26;
                convert[i] = B + 65;
             }
         
             // Leave every other character the same.
             else {
                B = A;
                convert[i] = B + 65;
                printf("\n");
             }
    
          }
         
          // Print the encrypted message.
          printf("The encrypted message is: %s\n", convert);
          break;

       case 2: // Decrypt a message that was encrypted with a rotational cypher given the message and key. 
       
          // Read the message from the user. 
          printf("What message do you want to decrypt? \n");
          scanf(" %[^\n]s", message);
       
          // Read the key from the user. 
          printf("Enter the key that was used to encrypt the message: \n");
          scanf("%d", &key);
       
          // Conversion of letters.
          for(i = 0; i < strlen(message); i++) {
           
              // If lowercase letters are entered, change them to uppercase.
              if(message[i] >= 97 && message[i] <=122) {
                 message[i] = message[i] - 32;
              }
           
              // Change ASCII code to corresponding value from 0-25.
              A = message[i] - 65;
           
              // Convert all letters.
              if(0 <= A && A <= 25 ) {
                 B = (A + (26 - key)) % 26;
                 convert[i] = B + 65;
              }
       
              // Leave every other character the same.
              else {
                 B = A;
                 convert[i] = B + 65;
                 printf("\n");
              }
       
          }
           
          // Print the decrypted message.
          printf("The decrypted message is: %s\n", convert);
          break;
       
       case 3: // Encrypt a message using a substitution cipher given the message and key.
          
          // Read the message from the user.
          printf("What is the message you want to encrypt? \n");
          scanf(" %[^\n]s", message);

          // Conversion of letters.
          for (i = 0; i < strlen(message); i++) {
              
              // If lowercase letters are entered, change them to uppercase.
             if(message[i] >= 97 && message[i] <=122) {
               message[i] = message[i] - 32;
             }

              
             // Change ASCII code to corresponding value from 0-25.
             A = message[i] - 65;
             
             // Convert all letters.
             if(0 <= A && A <= 25) {
                B = keysub[A];
                A = B;
                convert[i] = A;
             }
             
             // Leave all other characters the same.
             else {
                convert[i] = A + 65;
             }
          }
          
          // Print the Encrypted message.
          printf("The encrypted message is %s\n", convert);
          break;
       
       
       default: 
        printf("That is not an option.\n");
    }

    return 0;
}