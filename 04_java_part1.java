// Mini Expense Tracker (Java)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

import java.io.*;
import java.util.*;

public class ExpenseTotals {
    public static void main(String[] args) throws Exception {
        Map<String, Double> totals = new TreeMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] p = line.split(",", -1);
            if (p.length < 4) continue;
            double amt;
            try { amt = Double.parseDouble(p[2]); } catch (Exception e) { continue; }
            String cat = p[3].trim();
            totals.put(cat, totals.getOrDefault(cat, 0.0) + amt);
        }
        for (var e : totals.entrySet()) {
            System.out.printf("%s: %.2f%n", e.getKey(), e.getValue());
        }
    }
}
