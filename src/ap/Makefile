
TARGET = libap.a
DIRS = $(ARCH) bsd crt dirent fenv gen locale math multibyte plan9 posix regex stdio stdlib string thread

.PHONY: all

all: $(TARGET) $(DIRS)

$(TARGET):
	cd $(ARCH); $(MAKE) $(MFLAGS)
	cd bsd; $(MAKE) $(MFLAGS)
	cd crt; $(MAKE) $(MFLAGS)
	cd dirent; $(MAKE) $(MFLAGS)
	cd fenv; $(MAKE) $(MFLAGS)
	cd gen; $(MAKE) $(MFLAGS)
	cd locale; $(MAKE) $(MFLAGS)
	cd math; $(MAKE) $(MFLAGS)
	cd multibyte; $(MAKE) $(MFLAGS)
	cd plan9; $(MAKE) $(MFLAGS)
	cd posix; $(MAKE) $(MFLAGS)
	cd regex; $(MAKE) $(MFLAGS)
	cd stdio; $(MAKE) $(MFLAGS)
	cd stdlib; $(MAKE) $(MFLAGS)
	cd string; $(MAKE) $(MFLAGS)
