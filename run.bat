 g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp help.cpp recent.cpp chessGame.cpp mainMenu.cpp -I C:\SFML-2.5.1\include -mwindows
 g++ main.o board.o piece.o pieceTextures.o chessGame.o recent.o help.o mainMenu.o -o chess -mwindows -L C:\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
 