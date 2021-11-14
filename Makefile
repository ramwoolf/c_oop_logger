IDIR=include
BLD=build
CFLAGS=-I $(IDIR)

encapsulation:
	cp samples/encapsulation.c $(BLD)/encapsulation.c
	cp src/simple_logger.c $(BLD)/simple_logger.c
	gcc $(CFLAGS) $(BLD)/encapsulation.c $(BLD)/simple_logger.c -o bin/encapsulation

polymorph:
	cp samples/polymorph.c $(BLD)/polymorph.c
	cp src/base_logger.c $(BLD)/base_logger.c
	cp src/file_text_logger.c $(BLD)/file_text_logger.c
	cp src/terminal_logger.c $(BLD)/terminal_logger.c
	gcc $(CFLAGS) $(BLD)/polymorph.c $(BLD)/base_logger.c $(BLD)/file_text_logger.c $(BLD)/terminal_logger.c -o bin/polymorph

.PHONY: clean

clean:
	rm -f build/*

cleanall:
	rm -f build/*
	rm -f bin/*