#include "Cell/Cell.h"
#include "Cell/Land.h"
#include "Cell/GrassLand.h"

int main() {
	const int nRow = 10;
	const int nCol = 11;
	
	Cell*** map;
	map = new Cell**[nRow];
	for (int i = 0; i < nRow; i++) {
		map[i] = new Cell*[nCol];
	}
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			map[i][j] = new GrassLand();
		}
	}

	return 0;
}