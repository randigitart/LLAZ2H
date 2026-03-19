#include <stdio.h>
#include <assert.h>

#include <kv.h>

int main(int argv, char* argc[]) {
	
	kv_t *db = kv_init(16);
	assert(db != NULL);
	assert(db->capacity == 16);
	assert(db->count == 0);
	kv_free(db);
	
	return 0;
}
