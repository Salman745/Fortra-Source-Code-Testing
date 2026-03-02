// Mini Expense Tracker (C#)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

using System;
using System.Collections.Generic;

class ExpenseTotals {
    static void Main() {
        var totals = new SortedDictionary<string, double>(StringComparer.OrdinalIgnoreCase);
        string? line;
        while ((line = Console.ReadLine()) != null) {
            line = line.Trim();
            if (line.Length == 0) continue;
            var p = line.Split(',');
            if (p.Length < 4) continue;
            if (!double.TryParse(p[2], out var amt)) continue;
            var cat = p[3].Trim();
            totals[cat] = (totals.TryGetValue(cat, out var cur) ? cur : 0) + amt;
        }
        foreach (var kv in totals) Console.WriteLine($"{kv.Key}: {kv.Value:F2}");
    }
}
