#include<iostream>
using namespace std;


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
    if (num == 1) 
    {
		return 1;
	}
    else if (num == 2)
    {
		return 0;
	}
    else if(num < 4)
    {
		return 1;
	}
    else if (num < 8)
    {
		return (8 - num);
	}
    else if (num < 16)
    {
		return 16 - num;
	}
    else if (num < 32)
    {
		return 32 - num;
	}
    else if (num < 64)
    {
		return 64 - num;
	}
    else if (num < 128)
    {
		return 128-num;
	}
    else if (num < 256)
    {
		return 256 - num;
	}
    else if (num < 512)
    {
		return 512-num;
	}
    else if (num < 1024)
    {
		return 1024- num;
	}
    else if (num < 2048)
    {
		return 2048 - num;
	}
    else
    {
		return 0;
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
int combineMatrix(int (&initialMatrix)[size_x][size_y], int (&newMatrix)[size_x][size_y], int startingRow, int startingCol)
{
    int currCol = startingCol;

    for()
}


int main()
{
    return 0;
}