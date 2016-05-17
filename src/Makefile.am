AM_CPPFLAGS = @VMOD_INCLUDES@ -Wall -Werror

TESTS_ENVIRONMENT = PATH=$(LIBVARNISHAPI_BINDIR):$(LIBVARNISHAPI_SBINDIR):$$PATH

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_example.la

libvmod_example_la_LDFLAGS = -module -export-dynamic -avoid-version -shared

libvmod_example_la_SOURCES = \
	vmod_example.c

nodist_libvmod_example_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

dist_man_MANS = vmod_example.3

vmod_example.3: vmod_example.man.rst
	${RST2MAN} $< $@


vmod_example.lo vmod_example.man.rst: vcc

vcc: @VMODTOOL@ $(top_srcdir)/src/vmod_example.vcc
	@PYTHON@ @VMODTOOL@ $(top_srcdir)/src/vmod_example.vcc

VTC_LOG_COMPILER = $(VARNISHTEST) -v \
	-Dvmod_topbuild=$(abs_top_builddir)
TEST_EXTENSIONS = .vtc
TESTS = @VMOD_TESTS@

@VMOD_TESTS@: vcc

EXTRA_DIST = \
	vmod_example.vcc \
	$(VMOD_TESTS)

CLEANFILES = \
	$(builddir)/vcc_if.c \
	$(builddir)/vcc_if.h \
	$(builddir)/vmod_example.rst \
	$(builddir)/vmod_example.man.rst \
	$(dist_man_MANS)
