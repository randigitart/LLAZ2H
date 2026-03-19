#include <kv.h>
#include <string.h>


size_t hash(char *, int);

kv_t * kv_init(size_t capacity) {
	if(capacity == 0) {
		return NULL;
	}
	
	kv_t * table = malloc(sizeof(kv_t));
	if(table == NULL) {
		return NULL;
	}
	
	table->capacity = capacity;
	table->count = 0;
	
	table->entries = calloc(capacity, sizeof(kv_entry_t));
	if((table->entries) == NULL) {
		free(table);
		return NULL;
	}
	
	return table;
}

int kv_put(kv_t * table, char * key, char * value) {
	if(!table || !key || !value) return -1;
	
	size_t index = hash(key, table->capacity);
	int empty_index = -1;
	
	for(int i = 0; i < table->capacity; i++) {
		 size_t real_index = (index + i) % table->capacity;
		 kv_entry_t * entry = &table->entries[real_index];
		 
		 //key already set; update
		 if(entry->key && entry->key!=TOMBSTONE && !strcmp(entry->key, key)) {
		 	char* newval = strdup(value);
		 	if(!newval) return -1;
		 	free(entry->value);
		 	entry->value = newval;
		 	return real_index;
		 }
		 //entry at index empty; add new entry
		 if(!entry->key) {
		 	char* newkey = strdup(key);
		 	char* newval = strdup(value);
		 	if(!newkey || !newval) {
		 		free(newkey);
		 		free(newval);
			 	return -1;
			}
		 	entry->key = newkey;
		 	entry->value = newval;
		 	table->count++;
		 	return real_index;
		 }
		 //entry is TOMBSTONE
		 if(entry->key==TOMBSTONE && empty_index==-1) {
		 	empty_index=real_index;
		 }
	}
	
	if(empty_index != -1) {
		kv_entry_t * entry = &table->entries[empty_index];
		char* newkey = strdup(key);
		 	char* newval = strdup(value);
		 	if(!newkey || !newval) {
		 		free(newkey);
		 		free(newval);
			 	return -1;
			}
		 	entry->key = newkey;
		 	entry->value = newval;
		 	table->count++;
		 	return (size_t)real_index;
	}
	
	//table at capacity
	return -2;
	
}

void kv_free(kv_t * table) {
	free(table->entries);
	table->entries = NULL;
	free(table);
	table = NULL;
	return;
}

size_t hash(char *val, int capacity) {
	size_t hash = 0x13371337deadbeef;
	
	while(*val) {
		hash ^= *val;
		hash << 8;
		hash += *val;
		
		val++;
	}
	
	return (hash % capacity);
}
