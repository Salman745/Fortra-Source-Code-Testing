// Mini Expense Tracker (TypeScript)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

type Totals = Map<string, number>;

export function totalsByCategory(lines: string[]): Totals {
  const totals: Totals = new Map();
  for (const line of lines) {
    const t = line.trim();
    if (!t) continue;
    const p = t.split(",");
    if (p.length < 4) continue;
    const amt = Number(p[2]) || 0;
    const cat = (p[3] || "").trim();
    totals.set(cat, (totals.get(cat) ?? 0) + amt);
  }
  return totals;
}

// Example:
console.log([...totalsByCategory(["2026-02-01,Coffee,-3.50,Food"]).entries()]);
