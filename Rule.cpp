#include "Rule.h"

using namespace ChineseChess;

std::vector<Move> Rule::moves = std::vector<Move>();

std::vector<Move> ChineseChess::Rule::GetAvailableMoveFromLocation(const Location& from, Board board)
{
	moves.clear();

	Location to;

	int piece = board.GetPieceAtLocation(from);
	if (piece != 0)
	{
		PieceType pieceType = GetPieceType(piece);
		PieceTeam pieceTeam = GetPieceTeam(piece);

		switch (pieceType)
		{
		case ChineseChess::PieceType::KING:
		{

		}
			break;
		case ChineseChess::PieceType::GUARD:
		{

		}
			break;
		case ChineseChess::PieceType::MINISTER:
		{

		}
			break;
		case ChineseChess::PieceType::ROOK:
		{
			for (int i = 1; i < 10; i++)
			{
				to.x = from.x;
				to.y = from.y + i;
				if (LocationInRange(to) && EnemyHeldLocation(to, board))
					break;

			}
		}
			break;
		case ChineseChess::PieceType::KNIGHT:
		{

		}
			break;
		case ChineseChess::PieceType::CANNON:
		{

		}
			break;
		case ChineseChess::PieceType::PAWN:
		{

		}
			break;
		default:
			break;
		}
	}
}

inline PieceType ChineseChess::Rule::GetPieceType(int piece)
{
	if (piece > 0)
		return (PieceType)piece;
	else
		return (PieceType)-piece;
}

inline PieceTeam ChineseChess::Rule::GetPieceTeam(int piece)
{
	if (piece > 0)
		return PieceTeam::WHITE;
	else
		return PieceTeam::BLACK;
}

inline bool ChineseChess::Rule::IsEnemy(int pieceA, int pieceB)
{
	return GetPieceTeam(pieceA) != GetPieceTeam(pieceB);
}
