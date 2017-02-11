## Process this file with automake to produce Makefile.in

TESTS = check_calculate
check_PROGRAMS = check_calculate
check_calculate_SOURCES = check_calculate.c $(top_builddir)/src/calculate.h
check_calculate_CFLAGS = @CHECK_CFLAGS@
check_calculate_LDADD = $(top_builddir)/src/libcalculate.la @CHECK_LIBS@
