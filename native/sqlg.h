#define SQLG_OPEN_READONLY      1
#define SQLG_OPEN_READWRITE     2
#define SQLG_OPEN_CREATE        4

/* Could not easily get int64_t from stddef.h for gluegen */
typedef long long sqlg_long_t;

/* negative number indicates an error: */
typedef sqlg_long_t sqlg_handle_t;

sqlg_handle_t sqlg_db_open(const char *filename, int flags);

// TODO:
//sqlg_handle_t sqlg_db_open_vfs(const char *filename, int flags, const char *vfs);

sqlg_handle_t sqlg_db_prepare_st(sqlg_handle_t db, const char *sql);

// TODO blob:
//int sqlg_st_bind_blob(sqlg_handle_t st, int col, const void *val, int len); // ??
int sqlg_st_bind_double(sqlg_handle_t st, int col, double val);
int sqlg_st_bind_int(sqlg_handle_t st, int col, int val);
int sqlg_st_bind_int64(sqlg_handle_t st, int col, sqlg_long_t val);
int sqlg_st_bind_text(sqlg_handle_t st, int col, const char *val);
// TBD TODO bind others (??)

int sqlg_st_step(sqlg_handle_t st);

int sqlg_st_column_count(sqlg_handle_t st);
const char *sqlg_st_column_name(sqlg_handle_t st, int col);
const char *sqlg_st_column_text(sqlg_handle_t st, int col);
int sqlg_st_column_type(sqlg_handle_t st, int col);
// TODO other column queries

int sqlg_st_finish(sqlg_handle_t st); /* call sqlite3_finalize() */

int sqlg_db_close(sqlg_handle_t db);

