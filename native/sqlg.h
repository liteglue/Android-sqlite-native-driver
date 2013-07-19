#define SQLG_OPEN_READONLY      1
#define SQLG_OPEN_READWRITE     2
#define SQLG_OPEN_CREATE        4

ptrdiff_t sqlg_db_open(const char *filename, int flags);

// TODO:
//ptrdiff_t sqlg_db_open_vfs(const char *filename, int flags, const char *vfs);

ptrdiff_t sqlg_db_prepare_st(ptrdiff_t db, const char *sql);

// TODO bind

int sqlg_st_step(ptrdiff_t st);

int sqlg_st_column_count(ptrdiff_t st);
const char *sqlg_st_column_name(ptrdiff_t st, int col);
const char *sqlg_st_column_text(ptrdiff_t st, int col);
int sqlg_st_column_type(ptrdiff_t st, int col);
// TODO other column queries

int sqlg_st_finish(ptrdiff_t st); /* call sqlite3_finalize() */

int sqlg_db_close(ptrdiff_t db);

