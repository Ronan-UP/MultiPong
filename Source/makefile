ofiles = main.o Display.o Shape.o Rectangle.o Player.o
gpp_o = g++ -c 
link_flags_sdl2 = -LLib/ -lSDL2

main: $(ofiles)
	g++ $(ofiles) $(link_flags_sdl2) -o main


main.o: main.cpp Display.h Player.h
	$(gpp_o) main.cpp

Display.o: Display.h Display.cpp
	$(gpp_o) Display.cpp

Shape.o: Shape.cpp Shape.h
	$(gpp_o) Shape.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h
	$(gpp_o) Rectangle.cpp

Player.o: Player.h Player.cpp Rectangle.h
	$(gpp_o) Player.cpp

run: main
	./main

clean:
	rm *.o main
