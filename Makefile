PROG=main.exe
CC=gcc
DEPS=shapes.h calculator.h
SOURCES=main.c calculator.c shapes.c
CFLAGS=-Wall -Werror
OUTPUTDIR=
DEBUG?=1
ifeq ($(DEBUG), 1)
	PROG=programmet-debug.exe
	CFLAGS += -g
	OUTPUTDIR=bin/debug
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
endif
OBJS = $(addprefix $(OUTPUTDIR)/, $(SOURCES:.c=.o))

all: $(OUTPUTDIR) $(PROG)
	@echo  $(DEBUG)
	@echo  $(OUTPUTDIR)

$(PROG): $(OBJS) 
	$(CC) -o $@ $^ $(CFLAGS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

clean:
	@del /q "$(OUTPUTDIR)" 
	@del /q $(PROG)


.PHONY: prep clean