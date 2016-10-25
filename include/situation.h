#include <stdbool.h>
#include "item.h"

#ifndef _JORG_SITUATION_H
#define _JORG_SITUATION_H

typedef struct _line_t
{
  char *text;
  char *keywords[10];
  struct _line_t *next[10];
} line_t;


typedef enum { TALK, FIGHT, MERCHANT, ROOM, EXPLORE } situation_type_t;
typedef struct
{
  situation_type_t type;
  char *description;

  //TALK
  char *talk_names[10];
  int talk_index[10];
  line_t line;
  char *recruitable_companion;

  //FIGHT
  char *attack_description;
  int enemies_index[10];
  situation_type_t tobe;

  //MERCHANT
  int market_size;
  int market[100];

  //ROOM

  //EXPLORE
  char *explore_names[10];
  int explore_index[10];

} situation_t;

situation_t *current_situtation;
situation_t *last_situation;
situation_t *last_place;
situation_t situations[100];

void line_init(line_t *ret, char *text, line_t *keyw[10]);
void line_init_nokey(line_t *ret, char *text);
void change_situation(int index);
void change_situation_t(situation_t *sit);
void show_shop();
void show_fight();
char *color_keywords(const char* str, char *kw[10], int color);

#endif /* _JORG_SITUATION_H */
