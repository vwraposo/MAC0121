#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

struct l {
    int x;
    int y;
    int d;
};

typedef struct l lista;

int
distance (int x1, int y1, int x2, int y2)
{
    int d;
    d = sqrt ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    return d;
}

int 
candidate (int i, int j, lista v, int k, int resp[])
{
    for (int i = 0; i < k; i++)
        if (distance (i, j, v.x, v.y) != v.d) return 0;
    resp[0] = i;
    resp [1] = j;
    return 1;
}

int 
main () 
{
    int n, k, count = 0, resp[2];
    lista v[105];
    cin >> n >> k;
    for (int i = 0; i < k; i++) 
        cin >> v[i].x >> v[i].y >> v[i].d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++i) {
                if (candidate (i, j, v[l], k, resp))
                    count++;
        }
    if (count == 1)
        printf("%d %d\n", resp[0], resp[1]);
    else 
        printf("%d %d\n",-1, -1);
    return 0;
}