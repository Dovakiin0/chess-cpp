g++ -c main.cpp board.cpp mainMenu.cpp piece.cpp help.cpp pieceTextures.cpp chessGame.cpp
g++ main.o board.o piece.o pieceTextures.o mainMenu.o help.o chessGame.o -o chess -lsfml-graphics -lsfml-window -lsfml-system
