#include <stdio.h>
#include <assert.h>

#include <kv.h>

int main(int argv, char* argc[]) {
	
	char* key1 = "name";
	char* key2 = "addr1";
	char* key3 = "city";
	char* key4 = "state";
	char* val1 = "Shmoremoo";
	char* val2 = "67 Boom Road";
	char* val3 = "Flavor Town";
	char* val4 = "Ohio";
	
	char* newAddr = "69420 Gaylord Ave";
	
	int name, addr1, city, state;
	
	kv_t *db = kv_init(16);
	assert(db != NULL);
	assert(db->capacity == 16);
	assert(db->count == 0);
	
	name = kv_put(db, key1, val1);
	addr1 = kv_put(db, key2, val2);
	city = kv_put(db, key3, val3);
	state = kv_put(db, key4, val4);
	
	printf("%d\n", (int)db->count);
	for(int i = 0; i < db->capacity; i++) {
		if(db->entries[i].key) {
			printf("%s: %s\n", db->entries[i].key, db->entries[i].value);
		}
	}
	printf("%d, %d, %d, %d\n", name, addr1, city, state);
	
	addr1 = kv_put(db, key2, newAddr);
	
	printf("%d\n", (int)db->count);
	for(int i = 0; i < db->capacity; i++) {
		if(db->entries[i].key) {
			printf("%s: %s\n", db->entries[i].key, db->entries[i].value);
		}
	}
	
	kv_free(db);
	
	return 0;
}
