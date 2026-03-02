-- Mini Expense Tracker (SQL)
-- Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
-- Input CSV per line: date,description,amount,category

CREATE TABLE transactions (
  tx_date DATE,
  description VARCHAR(200),
  amount DECIMAL(12,2),
  category VARCHAR(100)
);

SELECT category, SUM(amount) AS total_amount
FROM transactions
GROUP BY category
ORDER BY category;
