#include <iostream>
using namespace std;


void printSeq( int num , int a[] , int len , int s );
int main()
{
	int a[5];
	printSeq(5,a,0,1);
	cin.get();
	return 0;
}

void printSeq( int num , int a[] , int len , int s ){
	if( num <= 0 ) {
		for( int j = 0 ; j < len ; j++ )
			cout << a[ j ] << "," ;
			cout << endl;

		return;
	}

	for(int i = s ; i <= num ; i++)	{
		a[ len ] = i;
		printSeq( num - i , a , len + 1 , i );
	}
}