 g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp chessGame.cpp mainMenu.cpp help.cpp -I C:\SFML-2.5.1\include -mwindows
 g++ main.o board.o piece.o pieceTextures.o chessGame.o mainMenu.o help.o -o chess -mwindows -L C:\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
 