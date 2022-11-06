#include<iostream>
#include<random>
using namespace std;

int generateMatrix();
bool isPowerOfTwo();
int modifyMatrix();


void sequentialRuns()
{
	int runs = 2048;
	int tests = 10;
	int n;
	int realN = 0;
	long startTime, endTime;
	long timeClassic = 0;
	long timeDC = 0;
	long timeStrassen = 0;
	int arr1[][];
    int arr2[][];
    int sample1[][];
    int sample2[][];
    int sample3[][];

	for(int i = 1; i < runs; i++)
    {
		n = i; 
		//n = (int) Math.pow(2, i);
			
		for(int j = 0; j < 1; j++)
        {
			int arr3[n][n];
			arr1 = generateMatrix(n);
			arr2 = generateMatrix(n); 
			//displayMatrix(A, n);
			//displayMatrix(B, n);
				
			if(isPowerOfTwo(n) == false)
            {
				arr1 = modifyMatrix(arr1, n);
				arr2 = modifyMatrix(arr2, n);
				arr3 = modifyMatrix(arr3, n);
				realN = n;
				n++;
			}
			else
            {
				realN = n;
			}
			
			startTime = System.nanoTime();
			sample1 = classic(arr1, arr2, sizeof(arr1);
			endTime = System.nanoTime();
			timeClassic += endTime - startTime;	
			//System.out.println("Classic Matrix Multiplication:" + realN);
			//displayMatrix(sample1, sample1.length);



			startTime = System.nanoTime(); // FIGURE OUT A C++ ALT



			sample2 = divideAndConquer(arr1, arr2, sizeof(arr1));



			endTime = System.nanoTime(); // FIGURE OUT A C++ ALT



			timeDC += endTime - startTime;
			//System.out.println("\nDivide and Conquer Matrix Multiplication:" + realN);
			//displayMatrix(sample2, sample2.length);


			startTime = System.nanoTime();   // FIGURE OUT A C++ ALT



			sample3 = strassenAlgo(arr1, arr2, arr3, sizeof(arr1));




			endTime = System.nanoTime(); // FIGURE OUT C++ ALT




			timeStrassen += endTime - startTime; 
			//System.out.println("\nStrassen Matrix Multiplication:" + realN);
			//displayMatrix(sample3, sample3.length);
		}

		timeClassic= timeClassic/tests;
		timeDC = timeDC/tests;
		timeStrassen = timeStrassen/tests;

		cout << "n=" << realN << "\nClassic: " << timeClassic
						<< " nanoseconds\nDivide and Conquer: " << timeDC
						<< " nanoseconds\nStrassen: " << timeStrassen << " nanoseconds\n" << endl;
	}		
}

/**
 * Used for testing purposes, this function will act as sanity check 
 */
void sampleTest()
{
	int n=4;
	int tests = 10;
	int sample1[][];
    int sample2[][];
    int sample3[][];
	long startTime, endTime;
	long timeClassic = 0;
	long timeDC = 0;
	long timeStrassen = 0;
	int arr3[n][n];
		
	//for n = 4
	int arr1[][] = {{ 2, 0, -1, 6},
				    { 3, 7, 8, 0 },
				    { -5, 1, 6, -2},
				    { 8, 0, 2, 7}}; 
		
	int arr2[][] = { { 0, 1, 6, 3},
				   { -2, 8, 7, 1 },
				   { 2, 0, -1, 0 },
				   { 9, 1, 6, -2}}; 
		
	/*//for n = 3
	 * int arr1[][] = { { 2, 0, -1},
				   { 3, 7, 8},
				   { -5, 1, 6 },
				   }; 
		
	int arr2[][] = { { 0, 1, 6},
				   { -2, 8, 7, },
				   { 2, 0, -1 },
				  };*/
		
	/*//for n = 5
	* int arr1[][] = { { 2, 0, -1, 6, 5},
				   { 3, 7, 8, 0, 5 },
				   { -5, 1, 6, -2, 5 },
				   { 8, 0, 2, 7, 5},
				   { 9, 1, 6, -2, 5}}; //{ 8, 0, 2, 7}
		
	int arr2[][] = { { 0, 1, 6, 3, 5},
				   { -2, 8, 7, 1, 5 },
				   { 2, 0, -1, 0, 5 },
				 { 9, 1, 6, -2, 5},
				   { 9, 1, 6, -2, 5}}; //{ 9, 1, 6, -2} */
		
	if(n % 2 != 0)
    {
		arr1 = modifyMatrix(arr1, n);
		arr2 = modifyMatrix(arr2, n);
		arr3 = modifyMatrix(arr3, n);
		n++;
	}
		
	sample1 = classic(arr1, arr2, sizeof(arr1));
	sample2 = divideAndConquer(arr1, arr2, sizeof(arr2));
	sample3 = strassenAlgo(arr1, arr2, arr3, sizeof(arr1));
	cout << "Classic Matrix Multiplication:";
	displayMatrix(sample1, n);
	cout << "\nDivide and Conquer Matrix Multiplication:";
	displayMatrix(sample2, n);
	cout << "\nStrassen Matrix Multiplication:";
	displayMatrix(sample3, n);
	
	for(int j = 0; j < tests; j++)
    {
		startTime = System.nanoTime();// FIGURE OUT C++ ALT



		classic(arr1, arr2, A.length);



		endTime = System.nanoTime();// FIGURE OUT C++ ALT



		timeClassic += endTime - startTime;



		startTime = System.nanoTime();// FIGURE OUT C++ ALT



		divideAndConquer(arr1, arr2, A.length);



		endTime = System.nanoTime();// FIGURE OUT C++ ALT



		timeDC += endTime - startTime;



		startTime = System.nanoTime();// FIGURE OUT C++ ALT



		strassenAlgo(arr1, arr2, arr3, sizeof(arr1));



		endTime = System.nanoTime();// FIGURE OUT C++ ALT



		timeStrassen += endTime - startTime; 
	}
		
	timeClassic= timeClassic/tests;
	timeDC = timeDC/tests;
	timeStrassen = timeStrassen/tests;
		
	cout << "n=" << n << "\nClassic: " << timeClassic
						<< " nanoseconds\nDivide and Conquer: " << timeDC
						<< " nanoseconds\nStrassen: " << timeStrassen << " nanoseconds\n" << endl;
}

template <size_t size_x, size_t size_y>
int modifyMatrix(int (&arr)[size_x][size_y], int i)
{
    int count = 0;
    count = changePowerOfTwo(i);

    int matrix[sizeof(arr) + count][sizeof(arr[0] + count)];

    for(int row = 0; row < sizeof(matrix); row++)
    {
        for(int col = 0; col < sizeof(matrix[0]); col++)
        {
            if(row < sizeof(arr) && col < sizeof(arr[0]))
            {
                matrix[row][col] = arr[row][col];
            }
            else
            {
                matrix[row][col] = 0;
            }
        }
    }
    return matrix;
}

bool isPowerOfTwo(int n)
{
    while(n % 2 == 0)
    {
        n=n/2;
    }
    if(n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int changePowerOfTwo(int num)
{
    if(num == 1) 
    {
		return 1;
	}
    else if(num == 2)
    {
		return 0;
	}
    else if(num < 4)
    {
		return 1;
	}
    else if(num < 8)
    {
		return (8 - num);
	}
    else if(num < 16)
    {
		return 16 - num;
	}
    else if(num < 32)
    {
		return 32 - num;
	}
    else if(num < 64)
    {
		return 64 - num;
	}
    else if(num < 128)
    {
		return 128-num;
	}
    else if(num < 256)
    {
		return 256 - num;
	}
    else if(num < 512)
    {
		return 512-num;
	}
    else if(num < 1024)
    {
		return 1024- num;
	}
    else if(num < 2048)
    {
		return 2048 - num;
	}
    else
    {
		return 0;
	}
}

template <size_t size_x, size_t size_y>
void divideMatrix(int (&initialMatrix)[size_x][size_y], int (&newMatrix)[size_x][size_y], int startingRow, int startingCol)
{
    int currentCol = startingCol;

    for(int i = 0; i < sizeof(newMatrix); i++)
    {
		for(int j = 0; j < sizeof(newMatrix); j++)
        {
			newMatrix[i][j] = initialMatrix[startingRow][currentCol++];
		}

		currentCol = startingCol;
		startingRow++;
	}
}

template <size_t size_x, size_t size_y>
int addMatrix(int (&arr1)[size_x][size_y], int (&arr2)[size_x][size_y], int n)
{
    int arr3[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return arr3;
}

template <size_t size_x, size_t size_y>
int subMatrix(int (&arr1)[size_x][size_y], int (&arr2)[size_x][size_y], int n)
{
    int arr3[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr3[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    return arr3;
}

template <size_t size_x, size_t size_y>
int combineMatrix(int (&initialMatrix)[size_x][size_y], int (&newMatrix)[size_x][size_y], int startingRow, int startingCol)
{
    int currCol = startingCol;

    for()
}

int generateMatrix(int n)
{
    int matrix[n][n];
    int guess;

    std::random_device seed;
    std::mt19937 gen{seed()}; // seed the generator
    std::uniform_int_distribution dist{-100, 100}; // set min and max

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            guess = dist(gen);
            matrix[i][j] = guess;
        }
    }

    return matrix;
}

template <size_t size_x, size_t size_y>
int classic(int (&arr1)[size_x][size_y], int (&arr2)[size_x][size_y], int n)
{
    int arr3[n][n];

    for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < n; j++)
        {
			arr3[i][j] = 0;
		}
	}
    for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < n; j++)
        {
			for(int k = 0; k < n; k++)
            {
				arr3[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	return arr3;
}

//Used for testing purposes, this method will display the matrix sent as an argument
template <size_t size_x, size_t size_y>
void displayMatrix(int (&matrix)[size_x][size_y], int n)
{
	for(int i = 0; i < n; i++)
		{
		for(int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

template <size_t size_x, size_t size_y>
int divideAndConquer(int (&arr1)[size_x][size_y], int (&arr2)[size_x][size_y], int n)
{
    int arr3[n][n];

    if(n==1)
    {
        arr3[0][0] = arr1[0][0] * arr2[0][0];
		return arr3;
    }
    else
    {
        int A11 [n/2][n/2];
		int A12 [n/2][n/2];
		int A21 [n/2][n/2];
		int A22 [n/2][n/2];
		int B11 [n/2][n/2];
		int B12 [n/2][n/2];
		int B21 [n/2][n/2];
		int B22 [n/2][n/2];
			
		/*divide matrix into 4 halves from A and B*/
		divideMatrix(arr1, A11, 0, 0); //top left
		divideMatrix(arr1, A12, 0, n/2); //top right
		divideMatrix(arr1, A21, n/2, 0); //bottom left
		divideMatrix(arr1, A22, n/2, n/2); //bottom right
			
		divideMatrix(arr2, B11, 0, 0); //top left
		divideMatrix(arr2, B12, 0, n/2); //top right
		divideMatrix(arr2, B21, n/2, 0); //bottom left
		divideMatrix(arr2, B22, n/2, n / 2); //bottom right

		int C11[][] = addMatrix(divideAndConquer(A11, B11, n/2), divideAndConquer(A12, B21, n/2), n/2);
		int C12[][] = addMatrix(divideAndConquer(A11, B12, n/2), divideAndConquer(A12, B22, n/2), n/2);
		int C21[][] = addMatrix(divideAndConquer(A21, B11, n/2), divideAndConquer(A22, B21, n/2), n/2);
		int C22[][] = addMatrix(divideAndConquer(A21, B12, n/2), divideAndConquer(A22, B22, n/2), n/2);

		combineMatrix(C11, arr3, 0, 0);
		combineMatrix(C12, arr3, 0, n / 2);
		combineMatrix(C21, arr3, n/2, 0);
		combineMatrix(C22, arr3, n/2, n/2); 
    }

    return arr3;
}

template <size_t size_x, size_t size_y>
int strassenAlgo(int (&arr1)[size_x][size_y], int (&arr2)[size_x][size_y], int (&arr3)[size_x][size_y], int n)
{
	if (n == 1)
    {
		arr3[0][0] = arr1[0][0] * arr2[0][0];
		return arr3;
	}
    else if(n == 2)
    {
        arr3[0][0] = (arr1[0][0] * arr2[0][0]) + (arr1[0][1] * arr2[1][0]);
		arr3[0][1] = (arr1[0][0] * arr2[0][1]) + (arr1[0][1] * arr2[1][1]);
        arr3[1][0] = (arr1[1][0] * arr2[0][0]) + (arr1[1][1] * arr2[1][0]);
        arr3[1][1] = (arr1[1][0] * arr2[0][1]) + (arr1[1][1] * arr2[1][1]);
	}
    else
    {
		int A11 [n/2][n/2];
		int A12 [n/2][n/2];
		int A21 [n/2][n/2];
		int A22 [n/2][n/2];
		int B11 [n/2][n/2];
		int B12 [n/2][n/2];
		int B21 [n/2][n/2];
		int B22 [n/2][n/2];

		int P1 [n/2][n/2];
		int P2 [n/2][n/2];
		int P3 [n/2][n/2];
		int P4 [n/2][n/2];
		int P5 [n/2][n/2];
		int P6 [n/2][n/2];
		int P7 [n/2][n/2];
			
		/*divide matrix 4 halves for A and B*/
		divideMatrix(arr1, A11, 0, 0); //top left
		divideMatrix(arr1, A12, 0, n/2); //top right
		divideMatrix(arr1, A21, n/2, 0); //bottom left
		divideMatrix(arr1, A22, n/2, n/2); //bottom right
			
		divideMatrix(arr2, B11, 0, 0); //top left
		divideMatrix(arr2, B12, 0, n/2); //top right
		divideMatrix(arr2, B21, n/2, 0); //bottom left
		divideMatrix(arr2, B22, n/2, n/2); //bottom right

			
		// P1 = A11(B12 - B22)
		strassenAlgo(A11, subtractMatrix(B12, B22, n/2), P1, n/2); 
			
		// P2 = (A11 + A12)B22
		strassenAlgo(addMatrix(A11, A12, n/2), B22, P2, n2);	
			
		// P3 = (A21 + A22)B11
		strassenAlgo(addMatrix(A21, A22, n/2), B11, P3, n/2); 
			
		// P4 = A22(B21 - B11)
		strassenAlgo(A22, subtractMatrix(B21, B11, n/2), P4, n/2);
			
		// P5 = (A11 + A22)(B11 + B22)
		strassenAlgo(addMatrix(A11, A22, n/2), addMatrix(B11, B22, n/2), P5, n/2);
			
		// P6 = (A11 - A22)(B21 + B22)
		strassenAlgo(subtractMatrix(A12, A22, n/2), addMatrix(B21, B22, n/2), P6, n/2);
			
		// P7 = (A11 - A22)(B11 + B12)
		strassenAlgo(subtractMatrix(A11, A21, n/2), addMatrix(B11, B12, n/2), P7, n/2);

			
		// C11 = -P2 + P4 + P5 + P6
		int C11[][] = addMatrix(subtractMatrix(addMatrix(P5, P6, sizeof(P6)), P2, sizeof(P2)), P4, sizeof(P4));
		// C12 = P1 + P2
		int C12[][] = addMatrix(P1, P2, sizeof(P2));
		// C21 = P3 + P4
		int C21[][] = addMatrix(P3, P4, sizeof(P4));
		// C22 = P1 - P3 + P5 - P7
		int C22[][] = addMatrix(subtractMatrix(P1, P3, sizeof(P3)), subtractMatrix(P5, P7, sizeof(P7)), sizeof(P7)); 

		combineMatrix(C11, arr3, 0, 0);
		combineMatrix(C12, arr3, 0, n/2);
		combineMatrix(C21, arr3, n/2, 0);
		combineMatrix(C22, arr3, n/2, n/2);
	}
    
	return arr3;
}

int main()
{
    sequentialRuns();

    return 0;
}