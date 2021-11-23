ofiles = main.o Display.o
gpp_o = g++ -c 
link_flags_sdl2 = -LLib/ -lSDL2

main: $(ofiles)
	g++ $(ofiles) $(link_flags_sdl2) -o main


main.o: main.cpp Display.h
	$(gpp_o) main.cpp

Display.o: Display.h Display.cpp
	$(gpp_o) Display.cpp

run: main
	./main

clean:
	rm *.o main
