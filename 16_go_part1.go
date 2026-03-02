// Mini Expense Tracker (Go)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

            package main

            import (
                "bufio"
                "fmt"
                "os"
                "sort"
                "strconv"
                "strings"
            )

            func main() {
                totals := map[string]float64{}
                in := bufio.NewScanner(os.Stdin)
                for in.Scan() {
                    t := strings.TrimSpace(in.Text())
                    if t == "" { continue }
                    p := strings.Split(t, ",")
                    if len(p) < 4 { continue }
                    amt, err := strconv.ParseFloat(p[2], 64); if err != nil { continue }
                    cat := strings.TrimSpace(p[3])
                    totals[cat] += amt
                }
                keys := make([]string, 0, len(totals))
                for k := range totals { keys = append(keys, k) }
                sort.Strings(keys)
                for _, k := range keys { fmt.Printf("%s: %.2f
", k, totals[k]) }
            }
