CC=gcc

CFLAGS= -O3 -g -Wall -Iincludes `pkg-config --cflags glib-2.0`

LDFLAGS=`pkg-config --libs glib-2.0` -lm -lcurses

all: programa-principal programa-testes

programa-principal: src/main.o src/types/date.o src/types/user.o src/types/ride.o src/types/driver.o src/utilities/parser.o src/utilities/catalog.o src/types/query.o src/types/query_1.o src/types/query_2.o src/types/query_3.o src/types/query_4.o src/types/query_5.o src/types/query_6.o src/types/query_7.o src/types/query_8.o src/types/query_9.o src/types/validate.o src/gui/gui.o src/gui/utils.o src/types/execute.o src/gui/pages/page_queries.o src/gui/pages/page_main_menu.o src/gui/pages/page_db.o
	$(CC) $^ $(LDFLAGS) -o $@

programa-testes: src/tests.o src/types/date.o src/types/user.o src/types/ride.o src/types/driver.o src/utilities/parser.o src/utilities/catalog.o src/types/query.o src/types/query_1.o src/types/query_2.o src/types/query_3.o src/types/query_4.o src/types/query_5.o src/types/query_6.o src/types/query_7.o src/types/query_8.o src/types/query_9.o src/types/validate.o src/gui/gui.o src/gui/utils.o src/types/execute.o src/gui/pages/page_queries.o src/gui/pages/page_main_menu.o src/gui/pages/page_db.o
	$(CC) $^ $(LDFLAGS) -o $@

src/main.o: src/main.c
src/tests.o: src/tests.c
src/types/date.o: src/types/date.c
src/types/driver.o: src/types/driver.c
src/types/user.o: src/types/user.c
src/types/ride.o: src/types/ride.c
src/types/query_1.o: src/types/query_1.c
src/types/query_2.o: src/types/query_2.c
src/types/query_3.o: src/types/query_3.c
src/types/query_4.0: src/types/query_4.c
src/types/query_5.o: src/types/query_5.c
src/types/query_6.o: src/types/query_6.c
src/types/query_7.o: src/types/query_7.c
src/types/query_8.o: src/types/query_8.c
src/types/query_9.o: src/types/query_9.c
src/types/query.o: src/types/query.c
src/types/validate.o: src/types/validate.c
src/types/execute.o: src/types/execute.c
src/utilities/parser.o: src/utilities/parser.c
src/utilities/catalog.o: src/utilities/catalog.c
src/gui/gui.o: src/gui/gui.c
src/gui/utils.o: src/gui/utils.c
src/gui/pages/page_queries.o: src/gui/pages/page_queries.c
src/gui/pages/page_main_menu.o: src/gui/pages/page_main_menu.c
src/gui/pages/page_db.o: src/gui/pages/page_db.c

clean:
	rm -f programa-testes src/*.o
	rm -f programa-principal src/*.o
	rm -f programa-principal src/utilities/*.o
	rm -f programa-principal src/types/*.o
	rm -f programa-principal src/gui/*.o
	rm -f programa-principal src/gui/pages/*.o
	rm -f Resultados/*.txt

