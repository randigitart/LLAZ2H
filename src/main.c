#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <kv.h>

int main(int argv, char* argc[]) {
	
	char* keys[4] = {"name", "addr1", "city", "state"};
	
	char* val1 = "Shmoremoo";
	char* val2 = "67 Boom Road";
	char* val3 = "Flavor Town";
	char* val4 = "Ohio";
	
	kv_t *db = kv_init(16);
	assert(db != NULL);
	assert(db->capacity == 16);
	assert(db->count == 0);
	
	kv_put(db, keys[0], val1);
	kv_put(db, keys[1], val2);
	kv_put(db, keys[2], val3);
	kv_put(db, keys[3], val4);
	
	printf("%d\n", (int)db->count);
	for(int i = 0; i < 4; i++) {
		printf("%s: %s\n", keys[i], kv_get(db, keys[i]));
	}
	
	assert(strcmp(kv_get(db, keys[3]), val4) == 0);
	assert(kv_get(db, "missing") == NULL);
	
	assert(kv_delete(db, keys[0]) == 0);
	assert(kv_get(db, "name") == NULL);
	assert(db->count == 3);
	
	kv_free(db);
	
	return 0;
}
