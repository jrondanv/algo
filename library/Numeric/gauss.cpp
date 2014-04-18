#define EPS 1e-6
#define zero(a) (fabs(a)<EPS)
double m[MAXN][MAXN];
int n, rank;

void gauss(){
	int i, j, k, st=0;
	for( i=0 ; i<n && st<n ; i++ ){
		while( st<n && zero(m[i][st]) ){
			for( j=i+1 ; j<n ; j++ ){
				if( !zero(m[j][st]) ){
					for( k=st ; k<n ; k++ ){
						swap(m[i][k],m[j][k]);
					}
					detE*=-1;
					break;
				}
			}
			if( zero(m[i][st]) ){
				st++;
				rank--;
			}
		}
		if( st<n ){
			for( j=i+1 ; j<n ; j++ ){
				double mult=(m[j][st]/m[i][st]);
				for( k=st ; k<n ; k++ ){
					if( k==st ){
						m[j][k]=0;
					}
					else{
						m[j][k]-=m[i][k]*mult;
					}
				}
			}
			st++;
		}
	}
}