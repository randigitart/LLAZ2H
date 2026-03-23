#ifndef KV_H
#define KV_H

#include <stdlib.h>

typedef struct {
	char* key;
	char* value;
} kv_entry_t;

typedef struct {
	size_t capacity;
	size_t count;
	
	kv_entry_t * entries;
} kv_t;

/*kv_init(size_t)
	returns a pointer to a 0 initialized database of capacity size_t */
kv_t * kv_init(size_t capacity);

/*kv_put(kv_t*, char*, char*)
	stores or updates a key-value pair in provided database
	returns 0 on success; upon error, -1; if table is at capacity, -2 */
int kv_put(kv_t * table, const char * key, const char * value);

/*kv_get(kv_t*,const char*)
	retrieves the value corresponding to the provided key in a database
	returns pointer to value, if found; else NULL */
char * kv_get(kv_t * db, const char* key);

/*kv_delete(kv_t*, const char*)
	deletes key/value entry in table; frees stored key/value and adds TOMBSTONE
	returns 0 upon succed; -1 upon error*/
int kv_delete(kv_t * db, const char* key);

/*kv_free(kv_t*)
	frees all allocated memory of a table*/
void kv_free(kv_t * table);

#endif
