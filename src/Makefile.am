AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = \
    moba-shutdown

moba_shutdown_SOURCES = \
    main.cpp

moba_shutdown_LDADD = \
    -lwiringPi \
    /usr/local/lib/libmobacommon.a

AM_LDFLAGS = \
    -L/usr/local/lib -pthread

AM_CPPFLAGS = \
    $(GTKMM_CFLAGS) \
    -I$(srcdir)/../modules/lib-msghandling/src \
    -ggdb -g3 -O3 -Wno-deprecated-declarations

CLEANFILES = *~
