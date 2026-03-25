#include <stdio.h>
#include <assert.h>

#include <kv.h>

int main(int argv, char* argc[]) {
	
	kv_t *db = kv_init(16);

	kv_put(db, "name", "alice");
	kv_put(db, "city", "berlin");
	
	printf("db init & populated\n");

	assert(kv_delete(db, "name") == 0);
	assert(kv_get(db, "name") == NULL);
	assert(db->count == 1);

	printf("asserts complete\n");

	assert(kv_delete(db, "missing") == -1);

	printf("final assert\n");

	kv_free(db);
	
	printf("db freed\n");

	return 0;
}
