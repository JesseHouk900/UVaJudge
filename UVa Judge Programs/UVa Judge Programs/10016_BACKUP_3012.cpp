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
			for (unsigned int r = 0; r < ringOperations.size(); r++) {
				if (static_cast<unsigned int>(ro) < ringOperations[r].size()) {
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
<<<<<<< HEAD
		case 1:
		{
			UpsideDownFlip(s, ring);
			break;
		}
		case 2:
		{
			LeftRightFlip(s, ring);
			break;
		}
		case 3:
		{
			MainDiagonalFlip(s, ring);
			break;
		}
		case 4:
		{
			MainInverseDiagonalFlip(s, ring);
			break;
=======
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
			
>>>>>>> 84f69b7d9f479788e00649486077bc5fc9773c73
		}
	}
}

void UpsideDownFlip(vector<vector<int> > & s, const int ring) {
<<<<<<< HEAD
	// if the ring is not the center ring on an odd size
	if (ring != s.size() - ring - 1) {
		// swap the upper left corner
		UpDownSwap(s, ring, ring);
		// swap the upper right corner
		UpDownSwap(s, ring, s.size() - ring - 1);
		// loop through half of the length of the ring
		for (int pos = ring + 1; pos < s.size() / 2; pos++) {
			// swap the elements on the left side
			UpDownSwap(s, pos, ring);
			// swap the elements on the left side of the top and bottom
			UpDownSwap(s, ring, pos);
			// swap the elements on the right side
			UpDownSwap(s, pos, s.size() - ring - 1);
			// swap the elements on the right side of the top and bottom
			UpDownSwap(s, ring, s.size() - pos - 1);
		}
		// if s has an odd size, swap the middle element on the top and bottom
		if (s.size() % 2) {
			UpDownSwap(s, ring, s.size() / 2);
=======
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
>>>>>>> 84f69b7d9f479788e00649486077bc5fc9773c73
		}
	}
}

void LeftRightFlip(vector<vector<int> > & s, const int ring) {
<<<<<<< HEAD
	// if the ring is not the center ring on an odd size
	if (ring != s.size() - ring - 1) {
		// swap the upper left corner
		LeftRightSwap(s, ring, ring);
		// swap the Lower left corner
		LeftRightSwap(s, s.size() - ring - 1, ring);
		// loop through half of the length of the ring
		for (int pos = ring + 1; pos < s.size() / 2; pos++) {
			// swap the elements on the upper side of the left and right side
			LeftRightSwap(s, pos, ring);
			// swap the elements on the top
			LeftRightSwap(s, ring, pos);
			// swap the elements on the bottom
			LeftRightSwap(s, s.size() - ring - 1, pos);
			// swap the elements on the right side of the top and bottom
			LeftRightSwap(s, s.size() - pos - 1, ring);
		}
		// if s has an odd size, swap the middle element on the top and bottom
		if (s.size() % 2) {
			LeftRightSwap(s, s.size() / 2, ring);
=======
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
>>>>>>> 84f69b7d9f479788e00649486077bc5fc9773c73
		}
	}
}

void MainDiagonalFlip(vector<vector<int> > & s, const int ring) {
<<<<<<< HEAD
	// if the ring is not the center ring on an odd size
	if (ring != s.size() - ring - 1) {
		// swap the corner
		MainDiagonalSwap(s, s.size() - ring - 1, ring);
		// loop through half of the length of the ring
		for (int pos = ring + 1; pos < s.size() / 2; pos++) {
			// swap the elements on the top of the left side
			MainDiagonalSwap(s, pos, ring);
			// swap the elements on the bottom of the left side
			MainDiagonalSwap(s, s.size() - pos - 1, ring);
			// swap the elements on the left of the bottom side
			MainDiagonalSwap(s, s.size() - ring - 1, pos);
			// swap the elements on the right of the bottom side
			MainDiagonalSwap(s, s.size() - ring - 1, s.size() - pos - 1);
		}
		// if s has an odd size, swap the middle element on the bottom and left
		if (s.size() % 2) {
			MainDiagonalSwap(s, s.size() - ring - 1, s.size() / 2);
			MainDiagonalSwap(s, s.size() / 2, ring);
=======
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
>>>>>>> 84f69b7d9f479788e00649486077bc5fc9773c73
		}
	}
}

void MainInverseDiagonalFlip(vector<vector<int> > & s, const int ring) {
<<<<<<< HEAD
	// if the ring is not the center ring on an odd size
	if (ring != s.size() - ring - 1) {
		// swap the corner
		MainInverseDiagonalSwap(s, s.size() - ring - 1, s.size() - ring - 1);
		// loop through half of the length of the ring
		for (int pos = ring + 1; pos < s.size() / 2; pos++) {
			// swap the elements on the top of the left side
			MainInverseDiagonalSwap(s, pos, ring);
			// swap the elements on the bottom of the left side
			MainInverseDiagonalSwap(s, s.size() - pos - 1, ring);
			// swap the elements on the left of the top side
			MainInverseDiagonalSwap(s, ring, pos);
			// swap the elements on the right of the top side
			MainInverseDiagonalSwap(s, ring, s.size() - pos - 1);
		}
		// if s has an odd size, swap the middle element on the bottom and left
		if (s.size() % 2) {
			MainInverseDiagonalSwap(s, ring, s.size() / 2);
			MainInverseDiagonalSwap(s, s.size() / 2, ring);
=======
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
>>>>>>> 84f69b7d9f479788e00649486077bc5fc9773c73
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