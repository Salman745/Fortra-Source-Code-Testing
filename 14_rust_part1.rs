// Mini Expense Tracker (Rust)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

use std::collections::BTreeMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut totals: BTreeMap<String, f64> = BTreeMap::new();

    for line in input.lines() {
        let parts: Vec<&str> = line.split(',').collect();
        if parts.len() < 4 { continue; }
        let amt: f64 = parts[2].trim().parse().unwrap_or(0.0);
        let cat = parts[3].trim().to_string();
        *totals.entry(cat).or_insert(0.0) += amt;
    }

    for (k, v) in totals { println!("{}: {:.2}", k, v); }
}
