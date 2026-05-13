/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of ALgorith
 *   Hari dan Tanggal    : Rabu,13 Mei 2026
 *   Nama (NIM)          : Azka Muhammad Aqwam(13224061)
 *   Nama File           : soal2.c
 *   Deskripsi           : Menghitung jumlah ISLAND dan besar ukuran dari ISLAND dalam LARGEST dengan menggunakan bantuan DFS
 * 
 */
#include <stdio.h>

int R, C;
char Grid[100][100];
int dfs(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C || Grid[r][c] == '0') {
        return 0;
    }
    Grid[r][c] = '0';

    int ukuran = 1;
    ukuran += dfs(r - 1, c); 
    ukuran += dfs(r + 1, c); 
    ukuran += dfs(r, c - 1); 
    ukuran += dfs(r, c + 1);
    
    return ukuran;
}

int main() {
    if (scanf("%d %d", &R, &C) != 2) return 0;
    for (int i = 0; i < R; i++) {
        scanf("%s", Grid[i]);
    }

    int totalISLANDS = 0;
    int totalLARGEST = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Grid[i][j] == '1') {
                totalISLANDS = totalISLANDS + 1; 
                int size = dfs(i, j);
                if (size > totalLARGEST) {
                    totalLARGEST = size;
                }
            }
        }
    }

    printf("ISLANDS %d\n", totalISLANDS);
    printf("LARGEST %d\n", totalLARGEST);
    
    return 0;
}

//https://www.geeksforgeeks.org/c/c-program-for-find-the-number-of-islands-set-1-using-dfs/
//https://www.programiz.com/dsa/graph-dfs
//https://www.digibeatrix.com/c/id/function-usage/c-language-matrix-operations-guide/
