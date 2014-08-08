#include <stdio.h>

#define A c1[0]
#define B c1[1]
#define P c1[2]
#define C c2[0]
#define D c2[1]
#define Q c2[2]

#define PRINTXY(x,y) printf("%.2lf %.2lf\n", (x), (y))

void calc(int *c1, int *c2) {
    double x, y;

    if(C != 0) {
        y = (1.0*A*Q-P*C)/(1.0*A*D-B*C);
        x = (1.0*P-y*B)/A;
    }
    else {
        if(D == 0) {
            if(Q == 0) {
                printf("not decided\n");
                return ;
            }
            else {
                printf("impossible\n");
                return ;
            }

        }
        if(B == 0 && A!=0) {
            printf("%.2lf %.2lf\n", 1.0*P/A, 1.0*Q/D);
            return ;
        }

        if(A==0) {
            if(B!=0 && 1.0*Q/D == 1.0*P/B) {
                printf("not decided\n");
                return ;
            }
            else {
                printf("impossible\n");
                return ;
            }
        }

        y = 1.0*Q/D;
        x = (1.0*P-y*B)/A;
    }


    printf("%.2lf %.2lf\n", x,y);
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
       /* int c1[3] = {};
        int c2[3] = {};

        scanf("%d %d %d", &c1[0], &c1[1], &c1[2]);
        scanf("%d %d %d", &c2[0], &c2[1], &c2[2]);

        if(A == 0)
            calc(c2, c1);
        else
            calc(c1, c2);
*/

        
        int a,b,p;
        int c,d,q;
        double xtop, ytop, xbot, ybot;
        scanf("%d %d %d", &a, &b, &p);
        scanf("%d %d %d", &c, &d, &q);
        
        if(c != 0 && d!=0) {
            xtop = p-(1.0*b/d*q);
            xbot = a-(1.0*b/d*c);

            ytop = p-(1.0*a/c*q);
            ybot = b-(1.0*a/c*d);

//            printf("x = %lf/%lf y = %lf/%lf\n", xtop,xbot, ytop,ybot); 

            if((xbot == 0 && xtop == 0 && ybot == 0 && ytop == 0)) {
                printf("not decided\n");
                continue;
            }

            if(xbot == 0 && ybot == 0) {
                printf("impossible\n");
                continue;
            }


            PRINTXY(xtop/xbot, ytop/ybot);
        }
        else if(a!=0 && b!=0 && c==0 && d!=0){
            PRINTXY((p-(1.0*b*q/d))/a, 1.0*q/d);
        }
        else if(a==0 && b!=0 && c!=0 && d!= 0) {
            PRINTXY((q-(1.0*p*d/b))/c, 1.0*p/b);
        }
        else if(a!=0 && b==0 && c!=0 && d!= 0) {
            PRINTXY(1.0*p/a, (q-(1.0*c*p/a))/d);
        }
        else if(a!=0 && b!=0 && c!=0 && d== 0) {
            PRINTXY(1.0*q/c, (p-(1.0*a*q/c))/b);
        }
        else if(a==0 && b!=0 && c!=0 && d== 0) {
            PRINTXY(1.0*q/c, 1.0*p/b);
        }
        else if(a!=0 && b==0 && c==0 && d!= 0) {
            PRINTXY(1.0*p/a, 1.0*q/d);
        }
        else if(a!=0 && b==0 && c!=0 && d== 0) {
            if(1.0*p/a != 1.0*q/c)
                printf("impossible\n");
            else
                printf("not decided\n");
        }
        else if(a==0 && b!=0 && c==0 && d!= 0) {
            if(1.0*p/b != 1.0*q/d)
                printf("impossible\n");
            else
                printf("not decided\n");
        }
        else if((a==0 && b==0) || (c==0 && d==0)) {
            printf("impossible\n");
        }
        
    }
    return 0;
}
