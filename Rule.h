#ifndef RULE_H
#define RULE_H

#include <stdio.h>
#include <stack>
#include <vector>

#define WIDTH 9
#define HEIGHT 10

namespace ChineseChess
{
	enum class PieceType : int
	{
		KING = 1, // tuong
		GUARD = 2, // si
		MINISTER = 3, // tuong
		ROOK = 4, // xe
		KNIGHT = 5, // ma
		CANNON = 6, // phao
		PAWN = 7 // tot
	};

	enum class PieceTeam : int
	{
		WHITE = -1,
		BLACK = 1
	};

	struct Location
	{
		int x;
		int y;

		Location(int x, int y)
		{
			this->x = x;
			this->y = y;
		}

		Location()
		{
			x = y = 0;
		}
	};


	struct Move
	{
		Location from;
		Location to;
	};

	class MoveCommand
	{
	public:
		Move move;	
		int capturedPiece;
	};


	class Board
	{
	public :
		Board()
		{
			memset(state, 0, sizeof(state));
		}

		inline int GetPieceAtLocation(int x, int y)
		{
			return state[x][y];
		}

		inline int GetPieceAtLocation(const Location& loc)
		{
			return GetPieceAtLocation(loc.x, loc.y);
		}

		void DoMove(const Move& move)
		{
			MoveCommand cmd;
			cmd.move = move;

			/////////////////

			commandList.push(cmd);
		}

		void Undo()
		{

		}
	private:
		int state[WIDTH][HEIGHT];

		std::stack<MoveCommand> commandList;
	};

	static class Rule
	{
	public:
		static std::vector<Move> GetAvailableMoveFromLocation(const Location& from, Board board);

		static PieceType GetPieceType(int piece);

		static PieceTeam GetPieceTeam(int piece);

		static bool IsEnemy(int pieceA, int pieceB);

	private:
		static std::vector<Move> moves;

		static bool LocationInRange(const Location& loc)
		{
			return loc.x >= 0 && loc.x < WIDTH && loc.y >= 0 && loc.y < HEIGHT;
		}

		static bool EnemyHeldLocation(const Location& loc, Board& board)
		{
			return board.GetPieceAtLocation(loc);
		}
	};
}


#endif

