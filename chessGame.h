/*
    This header file contains th ChessGame class.
    contains the whole game.
*/

#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "board.h"
#include "piece.h"
#include <chrono>

class ChessGame : public sf::Drawable
{
private:
    Board board;
    std::array<Piece, 16> whitePieces;
    std::array<Piece, 16> blackPieces;
    Piece *selectedPiece;
    std::vector<sf::RectangleShape> possibleMovesSquares;
    std::string lastMove;

    sf::RectangleShape infoRestart;

    sf::Font font;
    sf::Text textRestart;
    sf::Text textTurn;
    sf::Text textSituation;
    sf::Text textLastMove;

    // Tracking time
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    void startTime();
    void endTime();
    std::chrono::seconds getElapsedTime();

    // save details of recent games
    std::vector<std::string> name_vec;
    std::vector<int> sec_vec;
    void saveDetail();
    void loadDetail();

    bool selected;
    bool playerTurn; // true = White turn, false = Black Turn
    bool playerTurnCheck;
    bool mate;
    int turn;

    void createMovesSquares();

    void calcPossibleMoves();
    void calcKingMoves(Piece *tmpPiece);
    void calcQueenMoves(Piece *tmpPiece);
    void calcRookMoves(Piece *tmpPiece);
    void calcBishopMoves(Piece *tmpPiece);
    void calcKnightMoves(Piece *tmpPiece);
    void calcPawnMoves(Piece *tmpPiece);
    void calcCastling(Piece *tmpPiece);

    void eraseMoves(Piece *tmpPiece);

    void checkMate();

    void updateInfo();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    ChessGame(sf::Color bordCol1, sf::Color bordCol2);

    bool getSelected() { return selected; }

    bool getMate() { return mate; }

    bool selectPiece(int pos);

    void moveSelected(int pos);

    void restart();
};

#endif