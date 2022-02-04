#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcpy */

#include "uthash.h"

struct my_struct {
  const char *name; /* key */
  char val[2];
  UT_hash_handle hh; /* makes this structure hashable */
};

int main() {
  const char *names[] = {"dog", "dog", "dog", "dog"};
  char *pattern = "abba";
  struct my_struct *s, *tmp, *users = NULL;

  // for (n = names; *n != NULL; n++) {
  // s = (struct my_struct *)malloc(sizeof(struct my_struct));
  // if (s == NULL) {
  // exit(-1);
  // }
  // s->name = *n;
  // char x[2];
  // x[0] = 'a';
  // x[1] = '\0';
  // strcpy(s->val, x);
  // HASH_ADD_KEYPTR(hh, users, s->name, strlen(s->name), s);
  // }
  //
  // HASH_FIND_STR(users, "betty", s);
  // if (s != NULL) {
  // printf("betty's val is %d\n", s->val[0]);
  // }
  for (int i = 0; i < 4; ++i) {
    HASH_FIND_STR(users, names[i], s);
    if (!s) {
      s = (struct my_struct *)malloc(sizeof(struct my_struct));
      s->name = names[i];
      char x[2];
      x[0] = pattern[i];
      x[1] = '\0';
      strcpy(s->val, x);
      // printf(s->name);
      // printf(s->val);
      HASH_ADD_KEYPTR(hh, users, s->name, strlen(s->name), s);
    } else {
      printf("ok");
      printf("%s\n", s->name);
      printf("%s\n", s->val);
      char *tmp = &pattern[i];
      if (strcmp(s->val, tmp) != 0) {
        // deletemap(&ps);
        // deletemap2(&sp);
        return false;
      }
    }
  }

  /* free the hash table contents */
  HASH_ITER(hh, users, s, tmp) {
    HASH_DEL(users, s);
    free(s);
  }
  return 0;
}