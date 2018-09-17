/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    Flip - Flop the Squarelotron :    10016 :    euclid5

Data structure :

Tricks of the trade :

Problem :

////////////////////////////////////////////////////////////////////*/
#include<iostream>
#include<vector>
using namespace std;

void PerformOp(vector<vector<int> > &, const int &, const int);
void UpsideDownFlip(vector<vector<int> > &, const int);
void LeftRightFlip(vector<vector<int> > &, const int);
void MainDiagonalFlip(vector<vector<int> > &, const int);
void MainInverseDiagonalFlip(vector<vector<int> > &, const int);
void UpDownSwap(vector<vector<int> > &, const int &, const int &);
void LeftRightSwap(vector<vector<int> > &, const int &, const int &);
void MainDiagonalSwap(vector<vector<int> > &, const int &, const int &);
void MainInverseDiagonalSwap(vector<vector<int> > &, const int &, const int &);


int main() {
	int cases, size, ringNumber, numRingOps, maxOps;
	cin >> cases;
	for (int caseNum = 0; caseNum < cases; caseNum++) {
		cin >> size;
		vector<vector<int> > squarelotron(size, vector<int>(size));
		for (int r = 0; r < size; r++) {
			for (int c = 0; c < size; c++) {
				cin >> squarelotron[r][c];

			}
		}
		maxOps = -1;
		(size % 2) ? ringNumber = (size + 1) / 2 : ringNumber = size / 2;
		vector<vector<int> > ringOperations;
		ringOperations.reserve(ringNumber);
		for (int r = 0; r < ringNumber; r++) {
			cin >> numRingOps;
			ringOperations.push_back(vector<int>(numRingOps));
			if (numRingOps > maxOps) {
				maxOps = numRingOps;
			}
			for (int ro = 0; ro < numRingOps; ro++) {
				cin >> ringOperations[r][ro];
			}
			/*for (int ro = 0; ro < numRingOps; ro++) {
				cout << ringOperations[r][ro] << ' ';
				if (ro == numRingOps - 1) {
					cout << '\n';
				}
			}*/
		}

		for (int ro = 0; ro < maxOps; ro++) {
			for (int r = 0; r < ringOperations.size(); r++) {
				if (ro < ringOperations[r].size()) {
					PerformOp(squarelotron, r, ringOperations[r][ro]);
				}
			}
		}

		/*for (int r = 0; r < ringOperations.size(); r++) {
			for (int ro = 0; ro < ringOperations[r].size(); ro++) {
				if (ringOperations[r][ro] == 1) {
					UpsideDownFlip(squarelotron, r, c);
				}
				else if (ringOperations[r][ro] == 2) {
					LeftRightFlip(squarelotron);
				}
				else if (ringOperations[r][ro] == 3) {
					MainDiagonalFlip(squarelotron);
				}
				else if (ringOperations[r][ro] == 4) {
					MainInverseDiagonalFlip(squarelotron);
				}
			}
		}*/

		for (int r = 0; r < size; r++) {
			for (int c = 0; c < size; c++) {
				cout << squarelotron[r][c];
				if (c != size - 1) {
					cout << ' ';
				}
				else cout << '\n';
			}
		}

		//for (int j = 0; j < ringOperations.size(); j++) {
		//	//cout << ringOperations[j].size() << '\n';
		//	for (int i = 0; i < ringOperations[j].size(); i++) {
		//		cout << ringOperations[j][i];
		//		if (i != ringOperations[j].size() - 1) {
		//			cout << ' ';
		//		}
		//		else cout << '\n';
		//	}
		//}
	}
}

void PerformOp(vector<vector<int> > & s, const int & ring, const int op) {
	//cout << ring << '\n';
	switch (op) {
		case 1: {
			UpsideDownFlip(s, ring);
			break;
		}
		case 2: {
			LeftRightFlip(s, ring);
			break;
		}
		case 3: {
			MainDiagonalFlip(s, ring);
			break;
		}
		case 4: {
			MainInverseDiagonalFlip(s, ring);
			break;
			
		}
	}
}

void UpsideDownFlip(vector<vector<int> > & s, const int ring) {
	for (int r = ring; r < (s.size() - ring + 1) / 2; r++) {
		for (int c = ring; c < s.size() - ring; c++) {
			if (r % (s.size() - ring - 1)) {
			//cout << "swap (" << r << ", " << c << ") with (" << s.size() - r - 1 << ", " << c << ")\n";
				if (c % (s.size() - ring - 1) == ring) {
					UpDownSwap(s, r, c);
				}
			}
			else {
				UpDownSwap(s, r, c);
			}
		}
	}
}

void LeftRightFlip(vector<vector<int> > & s, const int ring) {
	for (int r = ring; r < s.size() - ring; r++) {
		for (int c = ring; c < (s.size() - ring) / 2; c++) {
			if (r % (s.size() - ring - 1)) {
				if (c % (s.size() - ring - 1) == 0) {
					LeftRightSwap(s, r, c);
				}
			}
			else {
				LeftRightSwap(s, r, c);
			}
		}
	}
}

void MainDiagonalFlip(vector<vector<int> > & s, const int ring) {
	for (int r = ring + 1; r < s.size() - ring; r++) {
		for (int c = ring; c < r; c++) {
			if (r % (s.size() - ring - 1)) {
				if (c % (s.size() - ring - 1) == 0) {
					MainDiagonalSwap(s, r, c);
				}
			}
			else {
				MainDiagonalSwap(s, r, c);
			}
		}
	}
}

void MainInverseDiagonalFlip(vector<vector<int> > & s, const int ring) {
	for (int r = ring; r < s.size() - ring; r++) {
		for (int c = ring; c < s.size() - ring - r; c++) {
			if (r % (s.size() - ring - 1)) {
				if (c % (s.size() - ring - 1) == 0) {
					MainInverseDiagonalSwap(s, r, c);
				}
			}
			else {
				MainInverseDiagonalSwap(s, r, c);
			}
		}
	}
}

void UpDownSwap(vector<vector<int> > & s, const int & r, const int & c) {
	const int temp = s[r][c];
	s[r][c] = s[s.size() - r - 1][c];
	s[s.size() - r - 1][c] = temp;
	
	//cout << "swap " << s[r][c] << " with " << s[s.size() - r - 1][c] << "\n";

}

void LeftRightSwap(vector<vector<int> > & s, const int & r, const int & c) {
	//cout << "I\n";
	const int temp = s[r][c];
	s[r][c] = s[r][s.size() - c - 1];
	s[r][s.size() - c - 1] = temp;

}

void MainDiagonalSwap(vector<vector<int> > & s, const int & r, const int & c) {
	//cout << "am\n";
	const int temp = s[r][c];
	s[r][c] = s[c][r];
	s[c][r] = temp;

}

void MainInverseDiagonalSwap(vector<vector<int> > & s, const int & r, const int & c) {
	//cout << "spaghiti\n";
	const int temp = s[r][c];
	s[r][c] = s[s.size() - c - 1][s.size() - r - 1];
	s[s.size() - c - 1][s.size() - r - 1] = temp;

}