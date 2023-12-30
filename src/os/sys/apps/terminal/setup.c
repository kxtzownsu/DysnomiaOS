#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../../libs/lib.h"


const char pwd_enc_pln[4]; // Automatic storage duration
const char usr[256];         // Automatic storage duration
const char pwd[256];         // Automatic storage duration
const char encryptedPwd[256]; // Automatic storage duration

// Simple XOR encryption function
void xorEncrypt(const char* input, const char* key, char** output) {
    size_t inputLen = strlen(input);
    size_t keyLen = strlen(key);

    *output = (char*)malloc(inputLen + 1);

    for (size_t i = 0; i < inputLen; ++i) {
        (*output)[i] = input[i] ^ key[i % keyLen];
    }

    (*output)[inputLen] = '\0';
}

// Hypothetical JSON writing function
void writeToJson(const char* username, const char* password) {
    // Implement your JSON writing logic here
    FILE* file = fopen("data.json", "a");
    if (file == NULL) {
        perror("Error opening data.json");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "{ \"username\": \"%s\", \"password\": \"%s\" }\n", username, password);

    fclose(file);
}

void getStarted() {
    printf("Welcome to the Terminal setup! This is to set a username and password for your system.\n");
    printf("Would you like your password stored in plaintext (1), or encrypted (2)?\n");

    const char* pwd_enc_pln = input("~> ");
    int pwdtype;

    if (strcmp(pwd_enc_pln, "1") == 0) {
        printf("Storing in plaintext..\n");
        pwdtype = 1;
    } else if (strcmp(pwd_enc_pln, "2") == 0){
        // Handle the case where the user wants an encrypted password (pwdtype = 2)
        printf("Storing encrypted..\n");
        pwdtype = 2;
    } else {
      printf("err: invalid... quitting terminal\n");
      exit(1);
    }

  const char* usr = input("Enter a Username: ");
  printf("Username: %s\n", usr);

  const char* pwd = input("Enter a Password: ");
  printf("Password (pre enc): %s\n", pwd);

  if (pwdtype == 2) {
      char encryptedPwd[256]; // Adjust the size as needed
      char key[1024];  // Adjust the size as needed

      strcpy(key, "DysnomiaOS-");
      strcat(key, usr);

      printf("Username: %s\n", usr);
      printf("Password (pre enc): %s\n", pwd);

      printf("Key: %s\n", key);
      xorEncrypt(pwd, key, encryptedPwd);
      pwd = encryptedPwd;
    }

    // Write user data to JSON
  writeToJson(usr, pwd);
  free(encryptedPwd);

  free(usr);
  free(pwd);
  free(pwd_enc_pln);
}