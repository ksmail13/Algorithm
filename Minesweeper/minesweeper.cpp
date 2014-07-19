//
//  minesweeper.cpp
//  
//
//  Created by 김민규 on 2014. 3. 12..
//
//

#include <iostream>
#define MAX_SIZE 100

#define MINE		'*'

// initial map info
inline int init_map(char map[MAX_SIZE][MAX_SIZE], int x, int y);

// to make mine map
inline void draw_mine_map(char map[MAX_SIZE][MAX_SIZE], int x, int y);

// print map to console
inline void print_map(char map[MAX_SIZE][MAX_SIZE], int x, int y);

int main(void) {
    char map[MAX_SIZE][MAX_SIZE];
	// map size
	int x, y;
	
	
	while(true) {
		std::cin >> y >> x;
		if(x==0 && y==0) break;
		
		init_map(map, x, y);
	
		draw_mine_map(map, x, y);
	
		print_map(map, x, y);
	}
    return 0;
}

inline int init_map(char map[MAX_SIZE][MAX_SIZE], int x, int y) {
	// index var i,j
	int i, j;
	for (i=0 ; i<y; i++) {
		for (j=0; j<x; j++) {
			std::cin >> map[i][j];
		}
	}


}

// to make mine map
inline void draw_mine_map(char map[MAX_SIZE][MAX_SIZE], int x, int y) {
	// index val i,j
	int i,j;
	for (i=0 ; i<y; i++) {
		for (j=0; j<x; j++) {
			char &field = map[i][j];
			if(field != MINE) {
				field = 0;
				if(i>0	&&	j>0			&& map[i-1][j-1]== MINE) field++;			// left top
				if(i>0					&& map[i-1][j]	== MINE) field++;			// top
				if(i>0	&&	j<MAX_SIZE-1	&& map[i-1][j+1]== MINE) field++;			// right top
				
				if(j>0			&& map[i][j-1]	== MINE) field++;					// left
				if(j<MAX_SIZE-1	&& map[i][j+1]	== MINE) field++;					// right
				
				if(i<MAX_SIZE-1 && j>0 && map[i+1][j-1]== MINE) field++;				// left bottom
				if(i<MAX_SIZE-1	&& map[i+1][j] == MINE) field++;						// bottom
				if(i<MAX_SIZE-1 && j<MAX_SIZE-1	&& map[i+1][j+1]== MINE) field++;	// right bottom
			}
		}
	}
}

// print map to console
inline void print_map(char map[MAX_SIZE][MAX_SIZE], int x, int y) {
	// index val i,j
	int i,j;
	for (i=0 ; i<y; i++) {
		for (j=0; j<x; j++) {
			if(map[i][j] == MINE)
				std::cout << map[i][j];
			else
				std::cout << map[i][j]+0;
		}
		std::cout << std::endl;
	}
}