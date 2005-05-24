TARGETS = test_3_element_struct_and_unions.c test_passing_integers.c \
	test_passing_floats.c test_basic_returning.c

AUTOEXECS = make_3esau make_passing_tests make_returning


all: $(TARGETS)


test_3_element_struct_and_unions.c: make_3esau.c typelist.h typelist.c defines.h args.h
	gcc -o make_3esau make_3esau.c typelist.c && \
	./make_3esau > test_3_element_struct_and_unions.c

test_passing_integers.c test_passing_floats.c: make_passing_tests.c typelist.h typelist.c defines.h args.h
	gcc -o make_passing_tests make_passing_tests.c typelist.c && \
	./make_passing_tests

test_basic_returning.c: make_returning.c typelist.h typelist.c defines.h args.h
	gcc -o make_returning make_returning.c typelist.c && \
	./make_returning > test_basic_returning.c


clean:
	$(RM) *.o *~ core make_sizal2 $(TARGETS) $(AUTOEXECS) a.out

.PHONY: clean dist-clean backup all dep depend
