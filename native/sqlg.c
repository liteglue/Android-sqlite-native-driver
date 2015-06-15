#include "sqlg.h"

#include <stddef.h> /* for NULL */

#include <android/log.h>

#include "sqlite3.h"

#define BASE_HANDLE_OFFSET 0x100000000LL

#define HANDLE_FROM_VP(p) ( BASE_HANDLE_OFFSET + ( (unsigned char *)(p) - (unsigned char *)NULL ) )
#define HANDLE_TO_VP(h) (void *)( (unsigned char *)NULL + (ptrdiff_t)((h) - BASE_HANDLE_OFFSET) )

sqlg_handle_t sqlg_db_open(const char *filename, int flags)
{
  sqlite3 *d1;
  int r1;

  // see http://stackoverflow.com/questions/7030760/how-to-print-log-address-of-a-variable-in-ndk
  // and http://www.ibm.com/developerworks/opensource/tutorials/os-androidndk/section5.html

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "db_open %s %d", filename, flags);

  r1 = sqlite3_open_v2(filename, &d1, flags, NULL);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "db_open %s result %d ptr %p", filename, r1, d1);

  return (r1 == 0) ? HANDLE_FROM_VP(d1) : -r1;
}

sqlg_handle_t sqlg_db_prepare_st(sqlg_handle_t db, const char *sql)
{
  sqlite3 *mydb = HANDLE_TO_VP(db);
  sqlite3_stmt *s;
  int rv;

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "prepare db %p sql %s", mydb, sql);

  rv = sqlite3_prepare_v2(mydb, sql, -1, &s, NULL);

  return (rv == 0) ? HANDLE_FROM_VP(s) : -rv;
}

/** FUTURE TBD for sqlcipher:
int sqlg_db_key_bytes(sqlg_handle_t db, unsigned char *key_bytes, int num_bytes)
{
  sqlite3 *mydb = HANDLE_TO_VP(db);

#ifdef SQLITE_HAS_CODEC
  return sqlite3_key(mydb, key_bytes, num_bytes);
#else
  return SQLITE_ERROR;
#endif
}

int sqlg_db_rekey_bytes(sqlg_handle_t db, unsigned char *key_bytes, int num_bytes)
{
  sqlite3 *mydb = HANDLE_TO_VP(db);

#ifdef SQLITE_HAS_CODEC
  return sqlite3_rekey(mydb, key_bytes, num_bytes);
#else
  return SQLITE_ERROR;
#endif
}
**/

sqlg_long_t sqlg_db_last_insert_rowid(sqlg_handle_t db)
{
  sqlite3 *mydb = HANDLE_TO_VP(db);

  return sqlite3_last_insert_rowid(mydb);
}

int sqlg_db_total_changes(sqlg_handle_t db)
{
  sqlite3 *mydb = HANDLE_TO_VP(db);

  return sqlite3_total_changes(mydb);
}

int sqlg_st_bind_double(sqlg_handle_t st, int col, double val)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p %d %lf", __func__, myst, col, val);

  return sqlite3_bind_double(myst, col, val);
}

int sqlg_st_bind_int(sqlg_handle_t st, int col, int val)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p %d %d", __func__, myst, col, val);

  return sqlite3_bind_int(myst, col, val);
}

int sqlg_st_bind_long(sqlg_handle_t st, int col, sqlg_long_t val)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p %d %lld", __func__, myst, col, val);

  return sqlite3_bind_int64(myst, col, val);
}

int sqlg_st_bind_text_native(sqlg_handle_t st, int col, const char *val)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p %d %s", __func__, myst, col, val);

  return sqlite3_bind_text(myst, col, val, -1, SQLITE_TRANSIENT);
}

int sqlg_st_bind_text_string(sqlg_handle_t st, int col, const char *val)
{
  return sqlg_st_bind_text_native(st, col, val);
}

int sqlg_st_bind_int64(sqlg_handle_t st, int col, sqlg_long_t val)
{
  return sqlg_st_bind_long(st, col, val);
}

int sqlg_st_step(sqlg_handle_t stmt)
{
  sqlite3_stmt *mystmt = HANDLE_TO_VP(stmt);

  return sqlite3_step(mystmt);
}

int sqlg_st_column_count(sqlg_handle_t st)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p", __func__, myst);

  return sqlite3_column_count(myst);
}

const char *sqlg_st_column_name(sqlg_handle_t st, int col)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p %d", __func__, myst, col);

  return sqlite3_column_name(myst, col);
}

double sqlg_st_column_double(sqlg_handle_t st, int col)
{
  return sqlite3_column_double(HANDLE_TO_VP(st), col);
}

int sqlg_st_column_int(sqlg_handle_t st, int col)
{
  return sqlite3_column_int(HANDLE_TO_VP(st), col);
}

sqlg_long_t sqlg_st_column_long(sqlg_handle_t st, int col)
{
  return sqlite3_column_int64(HANDLE_TO_VP(st), col);
}

const char *sqlg_st_column_text_native(sqlg_handle_t st, int col)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p %d", __func__, myst, col);

  return sqlite3_column_text(myst, col);
}

const char *sqlg_st_column_text_string(sqlg_handle_t st, int col)
{
  return sqlg_st_column_text_native(st, col);
}

int sqlg_st_column_type(sqlg_handle_t st, int col)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p %d", __func__, myst, col);

  return sqlite3_column_type(myst, col);
}

int sqlg_st_finish(sqlg_handle_t st)
{
  sqlite3_stmt *myst = HANDLE_TO_VP(st);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p", __func__, myst);

  return sqlite3_finalize(myst);
}

int sqlg_db_close(sqlg_handle_t db)
{
  sqlite3 *mydb = HANDLE_TO_VP(db);

  __android_log_print(ANDROID_LOG_VERBOSE, "sqlg", "%s %p", __func__, mydb);

// XXX TBD consider sqlite3_close() vs sqlite3_close_v2() ??:
  return sqlite3_close(mydb);
}

