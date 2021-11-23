ofiles = main.o
gpp_o = g++ -c 
link_flags_sdl2 = -LLib/ -lSDL2

main: $(ofiles)
	g++ $(ofiles) $(link_flags_sdl2) -o main


main.o: main.cpp
	$(gpp_o) main.cpp

run: main
	./main

clean:
	rm *.o main
