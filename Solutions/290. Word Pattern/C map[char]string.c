#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcpy */

#include "uthash.h"

struct my_struct {
  char name[2]; /* key */
  char *val;
  UT_hash_handle hh; /* makes this structure hashable */
};

int main() {
  char *names[] = {"dog", "dog", "dog", "dog"};
  char *pattern = "abba";
  struct my_struct *s, *tmp, *users = NULL;

  // for (n = names; *n != NULL; n++) {
  // s = (struct my_struct *)malloc(sizeof(struct my_struct));
  // if (s == NULL) {
  // exit(-1);
  // }
  // strcpy(s->name, *n);
  // s->id = i++;
  // HASH_ADD_STR(users, name, s);
  // }

  for (int i = 0; i < 4; ++i) {
    // printf("%c", pattern[i]);
    char *tmp = (char *)malloc(2);
    tmp[0] = pattern[i];
    tmp[1] = '\0';
    HASH_FIND_STR(users, tmp, s);
    if (!s) {
      // printf("fff\n");
      s = (struct my_struct *)malloc(sizeof(struct my_struct));
      char x[2];
      x[0] = pattern[i];
      x[1] = '\0';
      strcpy(s->name, x);
      s->val = names[i];
      HASH_ADD_STR(users, name, s);
      printf("%s\n", s->name);
      printf("%s\n", s->val);
    } else {
      // printf("ok\n");
      // printf("%s\n", s->name);
      // printf("%s\n", s->val);
      if (strcmp(s->val, names[i]) != 0) {
        printf("xxx");
        // deletemap(&ps);
        // deletemap2(&sp);
        return false;
      }
    }
  }

  // HASH_FIND_STR(users, "betty", s);
  // if (s != NULL) {
  // printf("betty's id is %d\n", s->id);
  // }

  /* free the hash table contents */
  HASH_ITER(hh, users, s, tmp) {
    HASH_DEL(users, s);
    free(s);
  }
  return 0;
}