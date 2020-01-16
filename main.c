#include<stdio.h>
#include<math.h>


int rec(int x, int i) {
    if(i==0)
        return 1;
    else if(i==1)
        return 2*x;
    else
        return (2*i*rec(x, i-1))-(2*(i-1)*rec(x, i-2));
}

int nonRec(int x, int n) {
    int i;
    if(n==0) {
        return 1;
    }
    else if(n==1) {
        return 2*x;
    }
    else {
        int s=1+2*x;
        for(i=2; i<=n; i++) {
            s+=(2*i*x)-(2*(i-1)*x);
        }
        return s;
    }
}
