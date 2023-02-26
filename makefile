Exec = dcompile
OPTS = -O3 -pthread -g

objects := $(patsubst %.c,%.o,$(wildcard *.c))

GXX = gcc

.PHONY: all
all: $(Exec)

.PHONY: check
check:
	echo Objects are $(objects)

$(objects): %.o: %.c *.h
	$(GXX) -c $(OPTS) $< -o $@

$(Exec): $(objects)
	$(GXX) $(OPTS) $(objects) -o $(Exec)
	echo $(GXX) $(OPTS) $(objects) -o $(Exec)

.PHONY: clean
clean:
	-rm *.o $(Exec)