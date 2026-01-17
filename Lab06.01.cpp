#include <iostream>
#include <cstdint>
#include <limits>
#include <math.h>

using namespace std;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint64_t u64;
typedef uint16_t uint;

const int BITS_IN_UNIT = sizeof(uint) * CHAR_BIT;

// CÂU 1

bool get_bit(uint N, int K) {
	return (N >> K) & 1; // trả về 0 thì false
	                     // trả về 1 thì true
}

void out_bits(uint N) {
	for (int i = BITS_IN_UNIT-1; i >= 0; i--) {
		cout << get_bit(N, i);
	}
}

int count_bit(uint N) {
	int count = 0;
	for (int i = BITS_IN_UNIT - 1; i >= 0; i--) {
		if (get_bit(N, i))
			count++;
	}
	return count;
}

bool set_bit(uint& N, int K, bool Status) {
	if (get_bit(N, K) == Status)
		return false; // bit thứ K không thay đổi
	if (Status)
		N = N ^ (1 << K);
	else
		N = N & (~(1 << K));
	return true; // bit thứ K thay đổi
}

bool swap_bit(uint& N, int K, int L) {
	if (get_bit(N, K) == get_bit(N, L))
		return false; // 2 bit K và L giống nhau
	N = N ^ ((1 << K) | (1 << L));
	return true; // 2 bit K và L khác nhau
}

int max_len1(uint N) {
	int k = 0, j = 0;
	for (int i = 0; i <= BITS_IN_UNIT - 1; i++) {
		if (get_bit(N, i)) {
			k++;
			if (k > j)
				j = k;
		}
		else
			k = 0;
	}
	return j;
}

int max_len2(uint N,bool B) {
	int k = 0, len = 0, s = 0;
	for (int i = 0; i <= BITS_IN_UNIT - 1; i++) {
		if (get_bit(N, i) == B) {
			k++;
			if (k > len) {
				len = k;
				s = i;
			}

		}
		else 
			k = 0;
	}
	return len;
}

int start_pos(uint N, bool B) {
	int k = 0, len = 0, s;
	for (int i = 0; i <= BITS_IN_UNIT - 1; i++) {
		if (get_bit(N, i) == B) {
			k++;
			if (k > len) {
				len = k;
				s = i;
			}

		}
		else
			k = 0;
	}
	return s - len + 1;
}

u16 max_len(uint N, bool B) {
	int k = 0, len = 0, s = 0;
	for (int i = 0; i <= BITS_IN_UNIT - 1; i++) {
		if (get_bit(N, i) == B) {
			k++;
			if (k > len) {
				len = k;
				s = i;
			}

		}
		else
			k = 0;
	}
	if (len == 0)
		return 0;
	int len_minus_one = len - 1,
		start_pos = s + 1 - len;
	u16 bits = (len_minus_one) | (start_pos << 6) | (B << 12);
	return bits;
}

uint rotate_left(uint N, int K) {
	return (N << K) ^ ((N & (~((1 << (BITS_IN_UNIT - K))-1))) >> (BITS_IN_UNIT - K));
}

uint rotate_right(uint N, int K) {
	return (N >> K) ^ ((N & ((1 << K) - 1)) << (BITS_IN_UNIT - K));
}

int get_bit1(uint N, int K) {
	if ((N & (1 << K)) == 0)
		return 0;
	return 1;
}

u8 count_transitions(uint N) {
	int status = get_bit1(N, 0),
		count = 0;
	for (int i = 1; i <= (BITS_IN_UNIT - 1); i++) {
		if ((status != get_bit1(N, i))) {
			count++;
			status = get_bit1(N, i);
		}
	}
	return count;
}

int abs(int a) {
	return (a > 0) ? a : (-a);
}

u8 Nearest_window(uint N, uint M, u8 W) {
	uint min_diff = INT_MAX;
	int pos_P = 0;
	uint mask = (1 << W) - 1;
	for (int P = 0; P <= BITS_IN_UNIT - W; P++) {
		int current_diff = abs((int)M - (int)((N >> P) & mask));
		if (current_diff < min_diff) {
			min_diff = current_diff;
			pos_P = P;
		}
		if (min_diff == 0)
			return pos_P;
	}
	return pos_P;
}

//Câu 2

bool get_bit(uint N, int K) {
	return (N >> K) & 1; // trả về 0 thì false
	// trả về 1 thì true
}

void out_bits(uint N) {
	for (int i = BITS_IN_UNIT - 1; i >= 0; i--) {
		cout << get_bit(N, i);
	}
}

int count_bit(uint N) {
	int count = 0;
	for (int i = BITS_IN_UNIT - 1; i >= 0; i--) {
		if (get_bit(N, i))
			count++;
	}
	return count;
}

bool set_bit(uint& N, int K, bool Status) {
	if (get_bit(N, K) == Status)
		return false; // bit thứ K không thay đổi
	if (Status)
		N = N ^ (1 << K);
	else
		N = N & (~(1 << K));
	return true; // bit thứ K thay đổi
}

bool swap_bit(uint& N, int K, int L) {
	if (get_bit(N, K) == get_bit(N, L))
		return false; // 2 bit K và L giống nhau
	N = N ^ ((1 << K) | (1 << L));
	return true; // 2 bit K và L khác nhau
}

int max_len1(uint N) {
	int k = 0, j = 0;
	for (int i = 0; i <= BITS_IN_UNIT - 1; i++) {
		if (get_bit(N, i)) {
			k++;
			if (k > j)
				j = k;
		}
		else
			k = 0;
	}
	return j;
}

u16 max_len(uint N, bool B) {
	int k = 0, len = 0, s = 0;
	for (int i = 0; i <= BITS_IN_UNIT - 1; i++) {
		if (get_bit(N, i) == B) {
			k++;
			if (k > len) {
				len = k;
				s = i;
			}

		}
		else
			k = 0;
	}
	if (len == 0)
		return 0;
	int len_minus_one = len - 1,
		start_pos = s + 1 - len;
	u16 bits = (len_minus_one) | (start_pos << 6) | (B << 12);
	return bits;
}

uint rotate_left(uint N, int K) {
	return (N << K) ^ ((N & (~((1 << (BITS_IN_UNIT - K)) - 1))) >> (BITS_IN_UNIT - K));
}

uint rotate_right(uint N, int K) {
	return (N >> K) ^ ((N & ((1 << K) - 1)) << (BITS_IN_UNIT - K));
}

int get_bit1(uint N, int K) {
	if ((N & (1 << K)) == 0)
		return 0;
	return 1;
}

u8 count_transitions(uint N) {
	int status = get_bit1(N, 0),
		count = 0;
	for (int i = 1; i <= (BITS_IN_UNIT - 1); i++) {
		if ((status != get_bit1(N, i))) {
			count++;
			status = get_bit1(N, i);
		}
	}
	return count;
}

u8 Nearest_window(uint N, uint M, u8 W) {
	uint min_diff = INT_MAX;
	int pos_P = 0;
	uint mask = (1 << W) - 1;
	for (int P = 0; P <= BITS_IN_UNIT - W; P++) {
		int current_diff = abs((int)M - (int)((N >> P) & mask));
		if (current_diff < min_diff) {
			min_diff = current_diff;
			pos_P = P;
		}
		if (min_diff == 0)
			return pos_P;
	}
	return pos_P;
}

int main() {
	out_bits(15);
	cout << endl;
	out_bits(rotate_left(15,14));
	
}
	