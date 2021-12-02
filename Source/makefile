ofiles = main.o Display.o Shape.o Rectangle.o Player.o Circle.o Ball.o
gpp_o = g++ -c 
link_flags_sdl2 = -LLib/ -lSDL2 -lSDL2_ttf

main: $(ofiles)
	g++ $(ofiles) $(link_flags_sdl2) -o main


main.o: main.cpp Display.h Player.h Ball.h
	$(gpp_o) main.cpp

Display.o: Display.h Display.cpp Circle.h
	$(gpp_o) Display.cpp

Shape.o: Shape.cpp Shape.h
	$(gpp_o) Shape.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h
	$(gpp_o) Rectangle.cpp

Circle.o: Circle.cpp Circle.h Shape.h
	$(gpp_o) Circle.cpp

Player.o: Player.h Player.cpp Rectangle.h
	$(gpp_o) Player.cpp

Ball.o: Ball.h Ball.cpp Circle.h Player.h
	$(gpp_o) Ball.cpp

run: main
	./main

clean:
	rm *.o main
