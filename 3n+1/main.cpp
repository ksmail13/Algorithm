#include <iostream>
#include <algorithm>

/**
  3n+1 의 알고리즘에 의해 생기는 수열의 갯수를 반환
 */
int job(int i);

int main(void) {

	int i, j, length=0;
	int tmp;
	std::cin >> i >> j;
	tmp = j;
	while(tmp >= i) {
		length = std::max(length,job(tmp--));
	}

	std::cout << i << " " << j << ' ' << length << '\n';	

	return 0;
}


int job(int i) {
	int length = 1;		// 자기 자신도 수열의 일부이므로 1 부터 시작

	while(i != 1) {

		if(i%2 == 0) {
			i = i/2;
		}
		else {
			i = 3*i+1;
		}

		length++;
	}
	return length;
}
