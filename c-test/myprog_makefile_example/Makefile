CC 		 := gcc
CFLAGS   := -Wall -O2 -g
CPPFLAGS :=
LDFLAGS  := # -L./lib # -lpthread
INCFLAGS := -I./inc
OBJS 	 := main.o foo.o bar.o

myprog: $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

# foo.o: foo.c
# bar.o: bar.c
# main.o: main.c # foo.h bar.h

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o

