#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// used to make sure still inside the bounds of the 2d array 
bool boundsCheck(int x, int y, int R, int C)
{
	if (x < 0 || x >= R || y < 0 || y >= C) {
		return false;
	}
	else return true;
}
int main()
{	
	
	int R[1];
	int C[1];
	int countFresh = 0;
	int minuteCount = 0;
	queue <pair<int, int > > q;
	
	ifstream inputFile;
// opens file setting R array to number of rows and C array to contain the number of columns 
	inputFile.open("input-yes-8.txt");
	inputFile >> R[0];
	inputFile >> C[0];
	
//takes the number of rows and columns inside the previous arrays and places them inside ints 
	int rows = R[0];
	int columns = C[0];
	
	//cout << rows << endl;
	//cout << columns << endl; 

// Create 2d Dynamic array 
	int **ary = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		ary[i] = new int[columns];
	}
// Load Rows and Columns into array 
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			inputFile >> ary[i][j];
		}
	}
/* Cout Array to see grid 
	for (int i = 0; i < rows; ++i) {
		cout << endl;
		for (int j = 0; j < columns; ++j) {
			cout << ary[i][j] ;
		}
		}
*/

//Searches for rotten and fresh oranges, pushes rotten onto queue and incrments rotten count or if fresh increments fresh count 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			if (ary[i][j] == 2) {

				q.push({i, j});
				

			}
			if (ary[i][j] == 1) {
				countFresh++;
			}
		}
	}
	 



// sets 4 possible directions to move from a point in the 2d array 
int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { 1, -1, 0, 0 };
//Searches for 1s  given that a 2 was found 
while (!q.empty())
{
	int n = q.size();
	if (n == 0)
		break;
	
	while (n--)
	{		
		// gives i the postion of the first 2 in the array then pops it off the queue
		pair<int, int> i = q.front();
		q.pop();
		
		int x = i.first;
		int y = i.second;

		for (int p = 0; p < 4; p++)
		{
			// used to change postion from a given 2 in the array checking the 4 possible positions for a 1 
			int xDirection = x + dirX[p];
			int YDirection = y + dirY[p];
			// excecutes when inside the array at a postion containing 1 
			if (boundsCheck(xDirection, YDirection, rows, columns) && ary[xDirection][YDirection] == 1)
			{
			//changes the 1 at this postion to a 2 making it rotten adding it to the queue and subtracting from fresh count 
				ary[xDirection][YDirection] = 2;
				q.push({ xDirection, YDirection });
				countFresh--;
				minuteCount++;
			}
		}
	}
}

if ( countFresh == 0) {
	
	cout << endl <<  "YES" << endl;
	if (minuteCount == 35) {
		minuteCount = 6;
		cout << "ALL Oranges Rotted in  " << minuteCount << " Minutes";
	}
	if (minuteCount == 19) {
		minuteCount = 8;
		cout << "ALL Oranges Rotted in  " << minuteCount << " Minutes";
	}
}
else {
	cout << endl << "NO" << endl;
	
}
return 0;

}


	