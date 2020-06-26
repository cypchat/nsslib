#ifndef __IMPLEMENTATIONS__
#define __IMPLEMENTATIONS__
#include <node_api.h>
#define MAX_SIGNAL_SIZE 1024 // max 1024 signals allowed

typedef struct _signal_database_t signal_database_t;
typedef struct _signal_table_t signal_table_t;
typedef struct _slots_t slots_t;

// signal database is collection of signal tables
// and each signal tables also a linked list in each others
struct _signal_database_t {
  signal_table_t *head; // last registered table
  char **signal_names; // we registers signal names into a two dimensional array
  int table_count; // how many tables are in it
};

// signal database is a linked list db style.
// |signal 1| <- |signal 2| <- |signal 3|
struct _signal_table_t {
  char *name;
  napi_value val;
  slots_t *slots;
  slots_t *slot_head; // last registered slot
  signal_table_t *prev; // linked list
  int slot_count; // count that how many signals we have currently
};

struct _slots_t {
  napi_value fn;
  slots_t *prev; // slots are linked to each other
};

napi_value 
initValue(napi_env env, napi_callback_info info);

napi_value 
insertSlot(napi_env env, napi_callback_info info);

napi_value 
emitSignal(napi_env env, napi_callback_info info);

void
allocateTable(void);

void
deallocateTable(void);

#else
#endif // __IMPLEMENTATIONS__
