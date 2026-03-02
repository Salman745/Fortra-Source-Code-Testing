// Mini Expense Tracker (Ada)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

package Expense is
   type Amount is digits 12;
   function Safe_Add (A, B : Amount) return Amount;
end Expense;
