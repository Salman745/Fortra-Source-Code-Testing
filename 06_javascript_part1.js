// Mini Expense Tracker (JavaScript)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

const fs = require("fs");

function totalsByCategory(text) {
  const totals = new Map();
  const lines = text.trim().split(/\r?\n/).filter(Boolean);
  for (const line of lines) {
    const p = line.split(",");
    if (p.length < 4) continue;
    const amt = Number(p[2]) || 0;
    const cat = (p[3] || "").trim();
    totals.set(cat, (totals.get(cat) || 0) + amt);
  }
  return totals;
}

const input = fs.readFileSync(0, "utf8");
const totals = totalsByCategory(input);
[...totals.entries()].sort().forEach(([k,v]) => console.log(`${k}: ${v.toFixed(2)}`));
