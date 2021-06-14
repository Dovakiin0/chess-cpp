g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp chessGame.cpp
g++ main.o board.o piece.o pieceTextures.o chessGame.o -o chess -lsfml-graphics -lsfml-window -lsfml-system
