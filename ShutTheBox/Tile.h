#pragma once

class Tile
{
public:
	Tile(int number) : number(number+1), shut(false) {}
	inline void flip(); // player flips tile to either open or close it
	inline int getNumber() const;
	inline bool isShut() const; // to check whether tile has been opened or closed

private:
	int number;
	bool shut;
};

inline void Tile::flip() { shut = !shut; }
inline int Tile::getNumber() const { return number; }
inline bool Tile::isShut() const { return shut; }