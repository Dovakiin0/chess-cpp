g++ -c main.cpp board.cpp piece.cpp help.cpp pieceTextures.cpp mainMenu.cpp recent.cpp chessGame.cpp
g++ main.o board.o piece.o pieceTextures.o help.o chessGame.o recent.o mainMenu.o -o chess -lsfml-graphics -lsfml-window -lsfml-system
