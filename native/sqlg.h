/* Export some important sqlite open flags to Java interface: */
#define SQLG_OPEN_READONLY      1
#define SQLG_OPEN_READWRITE     2
#define SQLG_OPEN_CREATE        4

/* Could not easily get int64_t from stddef.h for gluegen */
typedef long long sqlg_long_t;

/* negative number indicates an error: */
typedef sqlg_long_t sqlg_handle_t;

sqlg_handle_t sqlg_db_open(const char *filename, int flags);

// FUTURE TODO:
//sqlg_handle_t sqlg_db_open_vfs(const char *filename, int flags, const char *vfs);

/* FUTURE TBD for sqlcipher:
int sqlg_db_key_bytes(sqlg_handle_t db, unsigned char *key_bytes, int num_bytes);
int sqlg_db_rekey_bytes(sqlg_handle_t db, unsigned char *key_bytes, int num_bytes);
*/

sqlg_handle_t sqlg_db_prepare_st(sqlg_handle_t db, const char *sql);

sqlg_long_t sqlg_db_last_insert_rowid(sqlg_handle_t db);
int sqlg_db_total_changes(sqlg_handle_t db);

// FUTURE TODO blob:
//int sqlg_st_bind_blob(sqlg_handle_t st, int col, const void *val, int len); // ??
int sqlg_st_bind_double(sqlg_handle_t st, int col, double val);
int sqlg_st_bind_int(sqlg_handle_t st, int col, int val);
int sqlg_st_bind_long(sqlg_handle_t st, int col, sqlg_long_t val);
/* Converts UTF-16 to UTF-8 internally: */
int sqlg_st_bind_text_native(sqlg_handle_t st, int col, const char *val);
// FUTURE TODO: get text in UTF-16 format to SKIP the conversion
// XXX SUBJECT TO CHANGE (or may be removed):
int sqlg_st_bind_text_string(sqlg_handle_t st, int col, const char *val);
// XXX DEPRECATED & MAY BE REMOVED:
int sqlg_st_bind_int64(sqlg_handle_t st, int col, sqlg_long_t val);
// TBD FUTURE TODO bind others (??)

int sqlg_st_step(sqlg_handle_t st);

int sqlg_st_column_count(sqlg_handle_t st);
int sqlg_st_column_type(sqlg_handle_t st, int col);
const char *sqlg_st_column_name(sqlg_handle_t st, int col);
double sqlg_st_column_double(sqlg_handle_t st, int col);
int sqlg_st_column_int(sqlg_handle_t st, int col);
sqlg_long_t sqlg_st_column_long(sqlg_handle_t st, int col);
/* Converts UTF-8 to UTF-16 internally: */
const char *sqlg_st_column_text_native(sqlg_handle_t st, int col);
// XXX SUBJECT TO CHANGE (or may be removed):
const char *sqlg_st_column_text_string(sqlg_handle_t st, int col);
// TODO other column queries

int sqlg_st_finish(sqlg_handle_t st); /* call sqlite3_finalize() */

int sqlg_db_close(sqlg_handle_t db);

