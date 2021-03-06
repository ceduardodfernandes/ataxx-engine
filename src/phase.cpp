#include <cassert>
#include "phase.hpp"
#include "other.hpp"

float phase(const Position &pos)
{
    float p = (float)popcountll(pos.pieces[PIECE::CROSS] | pos.pieces[PIECE::NOUGHT] | pos.blockers) / 49;
    assert(p >= 0.0);
    assert(p <= 1.0);
    return p;
}

bool is_endgame(const Position &pos)
{
    return phase(pos) >= 0.75;
}
