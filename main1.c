
#include <stdlib.h>
#include <stdio.h>

int n, m, i, j, a[20][20], xi, yi;
int ok=0;

void readingData();

void boarding();

void displaySolution();

void backtrackingAlg(int x, int y, int nr);

int main()
{

    ///Readin the Data
    readingData();

    /// Boarding the Matrix
    boarding();

    /// Backtracking algorithm
    backtrackingAlg(xi, yi, 1);

    return 0;
}

void readingData() {
    int x;

    printf("Give n,m rows and columns and, the starting position x5,y and the labirinth:\n");
    scanf("%d %d %d %d",&n,&m,&xi,&yi);

    for(int i=1;i<=n;i++) {
        for (int j=1; j<=m; j++) {
            scanf("%d", &x);
            a[i][j] = x;
        }
    }
}

void boarding() {
    for(int i=0;i<=n+1;i++) {
        a[i][0]=a[i][m+1]=-1;
    }
    for(int i=0;i<=m+1;i++) {
        a[0][i]=a[n+1][i]=-1;
    }
}

void displaySolution() {
    ok=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void backtrackingAlg(int x, int y, int nr) {
    if(a[x][y]==-1) {
        a[x][y]=nr;
        displaySolution(&ok, a, n, m);
    }

    if(a[x][y]==0) {
        a[x][y]=nr;

        backtrackingAlg(x+1,y,nr+1);
        backtrackingAlg(x,y+1,nr+1);
        backtrackingAlg(x-1,y,nr+1);
        backtrackingAlg(x,y-1,nr+1);

        a[x][y]=0;
    }
}

