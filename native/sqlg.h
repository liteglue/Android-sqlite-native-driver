/* Export some important sqlite open flags to the Java interface (VFS not supported): */
#define SQLG_OPEN_READONLY      0x00001
#define SQLG_OPEN_READWRITE     0x00002
#define SQLG_OPEN_CREATE        0x00004
#define SQLG_OPEN_URI           0x00040
#define SQLG_OPEN_MEMORY        0x00080
#define SQLG_OPEN_NOMUTEX       0x08000
#define SQLG_OPEN_FULLMUTEX     0x10000
#define SQLG_OPEN_SHAREDCACHE   0x20000
#define SQLG_OPEN_PRIVATECACHE  0x40000

/* some important sqlite result codes to the Java interface: */
#define SQLG_RESULT_OK          0
#define SQLG_RESULT_ERROR       1
#define SQLG_RESULT_INTERNAL    2
#define SQLG_RESULT_PERM        3
#define SQLG_RESULT_ABORT       4
/* TBD ... */
#define SQLG_RESULT_MISUSE      21
/* TBD ... */
#define SQLG_RESULT_ROW         100
#define SQLG_RESULT_DONE        101

/* and sqlite datatypes: */
#define SQLG_INTEGER    1
#define SQLG_FLOAT      2
#define SQLG_TEXT       3
#define SQLG_BLOB       4
#define SQLG_NULL       5

/* Could not easily get int64_t from stddef.h for gluegen */
typedef long long sqlg_long_t;

/* negative number indicates an error: */
typedef sqlg_long_t sqlg_handle_t;

sqlg_handle_t sqlg_db_open(const char *filename, int flags);

// FUTURE TBD (???):
//sqlg_handle_t sqlg_db_open_vfs(const char *filename, int flags, const char *vfs);

// FUTURE TBD for sqlcipher:
//  int sqlg_db_key_bytes(sqlg_handle_t db, unsigned char *key_bytes, int num_bytes);
//  int sqlg_db_rekey_bytes(sqlg_handle_t db, unsigned char *key_bytes, int num_bytes);
// and/or:
//  int sqlg_db_key_string_native(sqlg_handle_t db, char *key_string);
//  int sqlg_db_rekey_string_native(sqlg_handle_t db, char *key_string);

sqlg_handle_t sqlg_db_prepare_st(sqlg_handle_t db, const char *sql);

sqlg_long_t sqlg_db_last_insert_rowid(sqlg_handle_t db);
int sqlg_db_total_changes(sqlg_handle_t db);

// FUTURE TBD bind blob:
//  int sqlg_st_bind_blob(sqlg_handle_t st, int col, const void *val, int len); // ??
int sqlg_st_bind_double(sqlg_handle_t st, int col, double val);
int sqlg_st_bind_int(sqlg_handle_t st, int col, int val);
int sqlg_st_bind_long(sqlg_handle_t st, int col, sqlg_long_t val);
/* Converts UTF-16 to UTF-8 internally: */
int sqlg_st_bind_text_native(sqlg_handle_t st, int col, const char *val);
// FUTURE TBD: bind text in UTF-16 format to SKIP the conversion
//  int sqlg_st_bind_text_string(sqlg_handle_t st, int col, const char *val);

int sqlg_st_step(sqlg_handle_t st);

int sqlg_st_column_count(sqlg_handle_t st);
int sqlg_st_column_type(sqlg_handle_t st, int col);
const char *sqlg_st_column_name(sqlg_handle_t st, int col);
// FUTURE TBD get column as blob (using a Java Buffer ??):
//  void *sqlg_st_column_blob(sqlg_handle_t st, int col);
double sqlg_st_column_double(sqlg_handle_t st, int col);
int sqlg_st_column_int(sqlg_handle_t st, int col);
sqlg_long_t sqlg_st_column_long(sqlg_handle_t st, int col);
/* Converts UTF-8 to UTF-16 internally: */
const char *sqlg_st_column_text_native(sqlg_handle_t st, int col);
// FUTURE TBD: get text in UTF-16 format to SKIP the conversion
//  const char *sqlg_st_column_text_string(sqlg_handle_t st, int col);

int sqlg_st_finish(sqlg_handle_t st); /* call sqlite3_finalize() */

int sqlg_db_close(sqlg_handle_t db);

