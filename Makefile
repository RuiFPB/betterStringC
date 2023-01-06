SOURCES=btrString.c
HEADERS=btrString.h
OBJECTS=$(SOURCES:.c=.o)
LIBRARY=libbtrString.a
PREFIX=/usr/local
LIBRARY_NAME=BetterString
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -O3
CC=gcc

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(LIBRARY)

install: $(LIBRARY)
	install -d $(PREFIX)/lib
	install -m 644 $(LIBRARY) $(PREFIX)/lib
	install -d $(PREFIX)/include
	install -m 644 $(HEADERS) $(PREFIX)/include

uninstall: $(LIBRARY)
	rm -f $(PREFIX)/lib/$(LIBRARY)
	rm -f $(PREFIX)/include/$(HEADERS)

remove: uninstall

help:
	@echo "$(LIBRARY_NAME)"
	@echo ""
	@echo "To just build the library, run 'make' or 'make all'."
	@echo "To install the library, run 'make install'. (might need sudo)"
	@echo "Use 'make install PREFIX=/path/to/install' to install to a different location."
	@echo ""
	@echo "	make [all] - build the $(LIBRARY_NAME) library"
	@echo "	make clean - remove all object files"
	@echo "	make install - install the $(LIBRARY_NAME) library"
	@echo "	make uninstall - uninstall the $(LIBRARY_NAME) library"
	@echo "	make remove - same as uninstall"