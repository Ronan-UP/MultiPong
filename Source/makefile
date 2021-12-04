ofiles = main.o Display.o Shape.o Rectangle.o Player.o Circle.o Ball.o Server.o Client.o Game.o LocalGame.o ClientGame.o ServerGame.o
gpp_o = g++ -c 
link_flags_sdl2 = -LLib/ -lSDL2 -lSDL2_ttf

main: $(ofiles)
	g++ $(ofiles) $(link_flags_sdl2) -o main


main.o: main.cpp Display.h Player.h Ball.h Server.h Client.h LocalGame.h  ClientGame.o ServerGame.o
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

Server.o: Server.h Server.cpp
	$(gpp_o) Server.cpp

Client.o: Client.h Client.cpp
	$(gpp_o) Client.cpp

Game.o: Game.h Game.cpp
	$(gpp_o) Game.cpp

LocalGame.o: Game.h LocalGame.h LocalGame.cpp
	$(gpp_o) LocalGame.cpp

ClientGame.o: Client.h Game.h ClientGame.h ClientGame.cpp
	$(gpp_o) ClientGame.cpp

ServerGame.o: Server.h Game.h ServerGame.h ServerGame.cpp
	$(gpp_o) ServerGame.cpp

run: main
	./main

clean:
	rm *.o main
