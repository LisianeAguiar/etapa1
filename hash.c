#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"



void hashInit (void) {
  int i;
  for (i = 0 ; i < HASH_SIZE ; i++ ){
    table[i] = 0;
  }
}


int hashAddress (char *text) {
  int address = 1;
  int i;
  for (i = 0 ; i < strlen(text) ; i++ ){
    address = (address *text[i])%HASH_SIZE + 1;
  }
  return address - 1;

}


HASH *hashInsert (int type, char *text) {
  HASH *newnode = 0;
  int address = hashAddress(text);
  newnode = (HASH*) calloc(1,sizeof(HASH));
  newnode->text = (char *) calloc(strlen(text)+1, sizeof(char));
  strcpy(newnode->text,text);

  newnode->type = type;
  newnode->next = table[address];
  table[address] = newnode;
  return newnode;
}


void hashPrint (void) {
  int i;
  HASH *node;
  for(i = 0; i < HASH_SIZE ; i++){
    for(node = table[i]; node ; node = node->next) {
      printf("Table[%d] has %s\n", i, node->text);
    }
  }
}
