// Mini Expense Tracker (C)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

\
            #include <stdio.h>
            #include <stdlib.h>
            #include <string.h>

            typedef struct { char cat[64]; double total; } Bucket;

            int main(void) {
                Bucket buckets[256]; int n = 0;
                char line[512];

                while (fgets(line, sizeof(line), stdin)) {
                    char *date = strtok(line, ",");
                    char *desc = strtok(NULL, ",");
                    char *amount_s = strtok(NULL, ",");
                    char *cat = strtok(NULL, ",\r\n");
                    if (!amount_s || !cat) continue;
                    double amt = strtod(amount_s, NULL);

                    int i;
                    for (i = 0; i < n; i++) {
                        if (strcmp(buckets[i].cat, cat) == 0) { buckets[i].total += amt; break; }
                    }
                    if (i == n && n < 256) {
                        strncpy(buckets[n].cat, cat, 63);
                        buckets[n].cat[63] = 0;
                        buckets[n].total = amt;
                        n++;
                    }
                }

                for (int i = 0; i < n; i++) {
                    printf("%s: %.2f\n", buckets[i].cat, buckets[i].total);
                }
                return 0;
            }
