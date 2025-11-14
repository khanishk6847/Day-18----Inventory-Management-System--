#include <stdio.h>
#include <string.h>

int main() {
    int id[10], qty[10];
    char name[10][50];
    float price[10];
    int n = 0, ch, i, find, pos;
    float total, maxv, minv;

    while (1) {
        printf("\n1.Add Product\n2.Show All\n3.Total Value\n4.Search\n5.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            if (n < 10) {
                printf("ID: ");
                scanf("%d", &id[n]);
                printf("Name: ");
                scanf("%s", name[n]);
                printf("Qty: ");
                scanf("%d", &qty[n]);
                printf("Price: ");
                scanf("%f", &price[n]);
                n++;
            }
        }

        else if (ch == 2) {
            for (i = 0; i < n; i++) {
                printf("%d %s %d %.2f\n", id[i], name[i], qty[i], price[i]);
            }
        }

        else if (ch == 3) {
            total = 0;
            maxv = qty[0] * price[0];
            minv = qty[0] * price[0];

            for (i = 0; i < n; i++) {
                float v = qty[i] * price[i];
                total += v;
                if (v > maxv) maxv = v;
                if (v < minv) minv = v;
            }

            printf("Total Value: %.2f\n", total);
            printf("Max Value: %.2f\n", maxv);
            printf("Min Value: %.2f\n", minv);
        }

        else if (ch == 4) {
            printf("Enter ID: ");
            scanf("%d", &find);
            pos = -1;

            for (i = 0; i < n; i++) {
                if (id[i] == find) {
                    pos = i;
                    break;
                }
            }

            if (pos == -1) {
                printf("Not Found\n");
            } else {
                printf("%d %s %d %.2f\n", id[pos], name[pos], qty[pos], price[pos]);
            }
        }

        else if (ch == 5) {
            break;
        }
    }

    return 0;
}