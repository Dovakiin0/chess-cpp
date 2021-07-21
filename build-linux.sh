g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp mainMenu.cpp chessGame.cpp
g++ main.o board.o piece.o pieceTextures.o chessGame.o mainMenu.o -o chess -lsfml-graphics -lsfml-window -lsfml-system
