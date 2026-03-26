#include <stdio.h>
#include <assert.h>

#include <kv.h>

int main(int argv, char* argc[]) {

	kv_t *db = kv_init(16);

	kv_put(db, "name", "alice");
	kv_put(db, "city", "berlin");
	kv_put(db, "lang", "c");

	kv_delete(db, "city");

	kv_free(db);


	return 0;
}
