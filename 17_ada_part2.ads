-- Mini Expense Tracker (Ada) - package body (Part 2)
package body Expense is
   function Safe_Add (A, B : Amount) return Amount is
   begin
      return A + B;
   end Safe_Add;
end Expense;
