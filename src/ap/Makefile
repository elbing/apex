
TARGET = libap.a
DIRS = $(ARCH) conf crt dirent env errno fcntl fenv gen harvey legacy locale math misc multibyte network passwd regex signal stat stdio stdlib string temp termios thread time unistd

.PHONY: all

all: $(TARGET) $(DIRS)

$(TARGET):
	cd $(ARCH); $(MAKE) $(MFLAGS)
	cd conf; $(MAKE) $(MFLAGS)
	cd crt; $(MAKE) $(MFLAGS)
	cd dirent; $(MAKE) $(MFLAGS)
	cd env; $(MAKE) $(MFLAGS)
	cd errno; $(MAKE) $(MFLAGS)
	cd fcntl; $(MAKE) $(MFLAGS)
	cd fenv; $(MAKE) $(MFLAGS)
	cd gen; $(MAKE) $(MFLAGS)
	cd harvey; $(MAKE) $(MFLAGS)
	cd legacy; $(MAKE) $(MFLAGS)
	cd locale; $(MAKE) $(MFLAGS)
	cd math; $(MAKE) $(MFLAGS)
	cd misc; $(MAKE) $(MFLAGS)
	cd multibyte; $(MAKE) $(MFLAGS)
	cd network; $(MAKE) $(MFLAGS)
	cd passwd; $(MAKE) $(MFLAGS)
	cd regex; $(MAKE) $(MFLAGS)
	cd signal; $(MAKE) $(MFLAGS)
	cd stat; $(MAKE) $(MFLAGS)
	cd stdio; $(MAKE) $(MFLAGS)
	cd stdlib; $(MAKE) $(MFLAGS)
	cd string; $(MAKE) $(MFLAGS)
	cd temp; $(MAKE) $(MFLAGS)
	cd termios; $(MAKE) $(MFLAGS)
	cd thread; $(MAKE) $(MFLAGS)
	cd time; $(MAKE) $(MFLAGS)
	cd unistd; $(MAKE) $(MFLAGS)
