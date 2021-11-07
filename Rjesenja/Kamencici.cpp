#include <iostream>

using namespace std;

string ploca;
int ploca_length;
int limit;

int trans_T[351][351][351];

int can_win(int board_start, int board_end, int CA_count, int CB_count, int CA_turn) {
	if (CB_count >= limit) {
		return 2;
	}
	if (CA_count >= limit) {
		return 1;
	}

	if (board_start == board_end) {
		return 1;
	}

	if (trans_T[board_start][board_end][CA_count] != 0) {
		return trans_T[board_start][board_end][CA_count];
	}
	
	int pos1, pos2;
	
	if (ploca[board_end] == 'C') {
		if (CA_turn == 1) {
			pos1 = can_win(board_start, board_end - 1, CA_count + 1, CB_count, (CA_turn + 1) % 2);
		}
		else {
			pos1 = can_win(board_start, board_end - 1, CA_count, CB_count + 1, (CA_turn + 1) % 2);
		}
	}
	else {
		pos1 = can_win(board_start, board_end - 1, CA_count, CB_count, (CA_turn + 1) % 2);
	}

	if (ploca[board_start] == 'C') {
		if (CA_turn == 1) {
			pos2 = can_win(board_start + 1, board_end, CA_count + 1, CB_count, (CA_turn + 1) % 2);
		}
		else {
			pos2 = can_win(board_start + 1, board_end, CA_count, CB_count + 1, (CA_turn + 1) % 2);
		}
	}
	else {
		pos2 = can_win(board_start + 1, board_end, CA_count, CB_count, (CA_turn + 1) % 2);
	}

	if (CA_turn == 1) {
		if (pos1 > pos2) {
			trans_T[board_start][board_end][CA_count] = pos1;
			return pos1;
		}
		trans_T[board_start][board_end][CA_count] = pos2;
		return pos2;
	}
	else {
		if (pos1 < pos2) {
			trans_T[board_start][board_end][CA_count] = pos1;
			return pos1;
		}
		trans_T[board_start][board_end][CA_count] = pos2;
		return pos2;
	}

}

int main(void) {

	scanf("%d%d", &ploca_length, &limit);
	cin >> ploca;

	int state = can_win(0, ploca.size() - 1, 0, 0, 1);

	if (state == 2) {
		cout << "DA";
	}
	else {
		cout << "NE";
	}

	return 0;
}
