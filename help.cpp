#include "help.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Help::Help()

{
    background.loadFromFile("Textures/helpbg.jpg");
    backSprite.setTexture(background);
    backSprite.setColor(sf::Color(255, 255, 255, 100)); // half transparent

    loadHelps();

    font.loadFromFile("Textures/DK-Lemon-Yellow-Sun.ttf");

    title.setFont(font);
    title.setString("Tutorial !!!");
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(512 / 2, 50));

    helpText.setFont(font);
    helpText.setString(helps[currentPage]);
    helpText.setCharacterSize(25);
    helpText.setFillColor(sf::Color::White);
    helpText.setPosition(sf::Vector2f(0, 100));

    footer.setFont(font);
    footer.setString("Use Arrow keys to change page!");
    footer.setCharacterSize(15);
    footer.setFillColor(sf::Color::White);
    footer.setPosition(sf::Vector2f(512 / 2, 490));
}

Help::~Help()
{
}

void Help::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    target.draw(backSprite);
    target.draw(title);
    target.draw(helpText);
    target.draw(footer);
}

void Help::nextPage()
{
    currentPage++;
    currentPage = std::min(currentPage, MAX_HELP_PAGE - 1);
    helpText.setString(helps[currentPage]);
}

void Help::prevPage()
{
    currentPage--;
    currentPage = std::max(0, currentPage);
    helpText.setString(helps[currentPage]);
}

void Help::loadHelps()
{
    helps[0] = R"(
    Step 1: Setup, Turns, and Taking Pieces

    Setup:
    The board is setup as shown. There should always be a white square 
    at the closest right-hand side for both players. Remember that the 
    queen must be on a square that matches her color.

    Turns:
    White always moves first, and players alternate turns. Players can 
    only move one piece at a time, except when castling (explained later).

    Taking Pieces:
    Players take pieces when they encounter an opponent in their movement 
    path. Only pawns take differently than they move (explained later). 
    Players cannot take or move through their own pieces.
    )";
    helps[1] = R"(
    Step 2: Pawn Movement

    Pawns only move forward. On the first move a pawn can move one or two 
    spaces, every subsequent move can only be one space. Pawns move 
    diagonally to take opponents.

    Pawn Promotion:
    If a pawn reaches the opposite side of the board, it is promoted to a 
    higher piece (except king). There is no limit to how many pawns can be 
    promoted.
    )";
    helps[2] = R"(
    Step 3: Rook

    Rooks move in a continuous line forwards, backwards and side-to-side.
    )";
    helps[3] = R"(
    Step 4: Knight

    Knights are the only pieces that "jump" off the board. Unlike other 
    pieces they are not blocked if there are pieces between them and their 
    destination square.

    To make it easier to remember how a knight moves think of an L. Two 
    spaces in a direction forward, backward or side-to-side, and one 
    space at a right turn.
    )";
    helps[4] = R"(
    Step 5: Bishop

    Bishops move in continuous diagonal lines in any direction.
    )";
    helps[5] = R"(
    Step 6: Queen

    The queen moves in continuous diagonal and straight lines. Forward, 
    backward and side-to-side.
    )";
    helps[6] = R"(
    Step 7: King

    The king can move in any direction, one square at a time.

    A king cannot move to a square that is under attack by the opponent. 
    )";
    helps[7] = R"(
    Step 8: Special Move: Castling

    Castling is the only move that allows two pieces to move during the 
    same turn.
    During castling a king moves two spaces towards the rook that it 
    will castle with, and the rook jumps to the other side. The king can 
    castle to either side as long as:
    1. The king has not moved.
    2. The king is not in check.
    3. The king does not move through or into check.
    4. There are no pieces between the king and castling-side rook.
    5. The castling-side rook has not moved.

    It does not matter:
    A. If the king was in check, but is no longer.
    B. If the rook can be attacked by an opponent's piece before 
    castling.
    )";
    helps[8] = R"(
    Step 9: Special Move: En Passant

    En passant is a special movement for pawns attacking pawns. It only 
    applies if \your opponent moves a pawn two spaces, and its 
    destination space is next to your pawn. You can take the opposing 
    piece by moving forward-diagonal to your pawn's attacked square.
    )";
    helps[9] = R"(
    Step 10: Check

    A king is in check when an opponent's piece is in a position that 
    can attack the king. A player must move their king out of check, 
    block the check or capture the attacking piece.
    A player cannot move their king into check.
    )";
    helps[10] = R"(
    Step 11: Checkmate

    Putting an opponent's king in "checkmate" is the only way to win 
    the game.

    A king is in checkmate if it is in check, the opponent's piece that 
    has the king in check cannot be captured, the check cannot be blocked, 
    and the king cannot move to a square that is not under attack.

    In the illustration the white queen has the black king in check, 
    and all of the spaces where the king can move can be attacked by 
    the queen. The king cannot take the queen, because the knight is 
    protecting the queen. The black bishop cannot block the queen. 
    This is checkmate.
    )";
    helps[11] = R"(
    Step 12: Stalemate

    Simply put, a "Stalemate" is a tie. It is achieved if there are no 
    legal moves for a player to make.

    In this illustration it is white's turn. All spaces around the king 
    are being attacked, but the king is not in check, therefore it cannot 
    move. The only other white piece, the pawn, is blocked by the king. 
    Because movement is impossible, the game is a stalemate.

    If white had another piece somewhere on the board that was not blocked, 
    it would have to move. The game would continue.
    )";
}