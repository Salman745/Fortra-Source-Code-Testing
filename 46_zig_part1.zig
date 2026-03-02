// Mini Expense Tracker (Zig)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

const std = @import("std");

pub fn main() !void {
    const out = std.io.getStdOut().writer();
    try out.print("Expense totals (placeholder)\n", .{});
}
