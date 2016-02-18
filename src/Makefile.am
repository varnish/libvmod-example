AM_CPPFLAGS = @VMOD_INCLUDES@
AM_CFLAGS = -Wall -Werror -Wextra

# VMOD library

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_example.la

VCC_FILES = \
	vcc_if.c \
	vcc_if.h

DOC_FILES = \
	vmod_example.rst \
	vmod_example.man.rst

libvmod_example_la_LDFLAGS = \
	-module \
	-export-dynamic \
	-avoid-version \
	-shared

libvmod_example_la_SOURCES = \
	vmod_example.c

nodist_libvmod_example_la_SOURCES = \
	$(VCC_FILES)

$(srcdir)/vmod_example.c: $(VCC_FILES)

$(VCC_FILES) $(DOC_FILES): .vcc

.vcc: vmod_example.vcc
	@echo vmodtool: @VMODTOOL@ $<
	@@PYTHON@ @VMODTOOL@ $<
	@touch $@

# Documentation

dist_man_MANS = vmod_example.3

%.3: %.man.rst
if HAVE_RST2MAN
	${RST2MAN} $< $@
else
	@echo "========================================"
	@echo "You need rst2man installed to make dist"
	@echo "========================================"
	@false
endif

# Test suite

VMOD_FILE="$(abs_builddir)/.libs/libvmod_example.so"

VTC_LOG_COMPILER = \
	env PATH="@TEST_PATH@" \
	varnishtest -v \
	-Dvmod_example="example from \"$(VMOD_FILE)\""

TEST_EXTENSIONS = .vtc

TESTS = @VTC_TESTS@

# misc

EXTRA_DIST = \
	vmod_example.vcc \
	$(TESTS)

CLEANFILES = \
	$(VCC_FILES) \
	$(DOC_FILES) \
	$(dist_man_MANS) \
	.vcc
