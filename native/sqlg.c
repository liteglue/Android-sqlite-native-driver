#include <stdlib.h>

#include <android/log.h>

#include "sqlite3.h"

ptrdiff_t sqlg_db_open(const char *filename, int flags)
{
  sqlite3 *d1;
  int r1;

  // see http://stackoverflow.com/questions/7030760/how-to-print-log-address-of-a-variable-in-ndk
  // and http://www.ibm.com/developerworks/opensource/tutorials/os-androidndk/section5.html

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "db_open %s %d", filename, flags);

  r1 = sqlite3_open_v2(filename, &d1, flags, NULL);

  return (r1 == 0) ? ((unsigned char *)d1 - (unsigned char *)NULL) : -r1;
}

ptrdiff_t sqlg_db_prepare_st(ptrdiff_t db, const char *sql)
{
  sqlite3 *mydb;
  sqlite3_stmt *s;
  int rv;

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "prepare db %x sql %s", db, sql);

  mydb = (sqlite3 *)((unsigned char *)NULL + db);

  rv = sqlite3_prepare_v2(mydb, sql, -1, &s, NULL);

  return (rv == 0) ? ((unsigned char *)s - (unsigned char *)NULL) : -rv;
}

int sqlg_st_bind_double(ptrdiff_t st, int col, double val)
{
  sqlite3_stmt *myst = (sqlite3_stmt *)((unsigned char *)NULL + st);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x %d %lf", __func__, st, col, val);

  return sqlite3_bind_double(myst, col, val);
}

int sqlg_st_bind_int(ptrdiff_t st, int col, int val)
{
  sqlite3_stmt *myst = (sqlite3_stmt *)((unsigned char *)NULL + st);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x %d %d", __func__, st, col, val);

  return sqlite3_bind_int(myst, col, val);
}

int sqlg_st_bind_int64(ptrdiff_t st, int col, ptrdiff_t /*long*/ val)
{
  sqlite3_stmt *myst = (sqlite3_stmt *)((unsigned char *)NULL + st);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x %d %ld", __func__, st, col, val);

  return sqlite3_bind_int64(myst, col, val);
}

int sqlg_st_bind_text(ptrdiff_t st, int col, const char *val)
{
  sqlite3_stmt *myst = (sqlite3_stmt *)((unsigned char *)NULL + st);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x %d %s", __func__, st, col, val);

  return sqlite3_bind_text(myst, col, val, -1, SQLITE_TRANSIENT);
}

int sqlg_st_step(ptrdiff_t stmt)
{
  sqlite3_stmt *mystmt;

  mystmt = (sqlite3_stmt *)((unsigned char *)NULL + stmt);

  sqlite3_step(mystmt);
}

int sqlg_st_column_count(ptrdiff_t st)
{
  sqlite3_stmt *myst = (sqlite3_stmt *)((unsigned char *)NULL + st);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x", __func__, st);

  return sqlite3_column_count(myst);
}

const char *sqlg_st_column_name(ptrdiff_t st, int col)
{
  sqlite3_stmt *myst = (sqlite3_stmt *)((unsigned char *)NULL + st);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x %d", __func__, st, col);

  return sqlite3_column_name(myst, col);
}

const char *sqlg_st_column_text(ptrdiff_t st, int col)
{
  sqlite3_stmt *myst = (sqlite3_stmt *)((unsigned char *)NULL + st);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x %d", __func__, st, col);

  return sqlite3_column_text(myst, col);
}

int sqlg_st_column_type(ptrdiff_t st, int col)
{
  sqlite3_stmt *myst = (sqlite3_stmt *)((unsigned char *)NULL + st);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x %d", __func__, st, col);

  return sqlite3_column_type(myst, col);
}

int sqlg_st_finish(ptrdiff_t stmt)
{
  sqlite3_stmt *mystmt = (sqlite3_stmt *)((unsigned char *)NULL + stmt);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x", __func__, stmt);

  return sqlite3_finalize(mystmt);
}

int sqlg_db_close(ptrdiff_t db)
{
  sqlite3 *mydb = (sqlite3 *)((unsigned char *)NULL + db);

  __android_log_print(ANDROID_LOG_INFO, "sqlg", "%s %x", __func__, db);

// XXX TBD consider sqlite3_close() vs sqlite3_close_v2() ??:
  return sqlite3_close(mydb);
}

