"""
A MMD Table Formatter.

Silly script that takes a MMD table as a \
string and returns a tidied version of the table.

Credit: https://codereview.stackexchange.com/a/145294
"""

import sys


def get_alignment(cell):
    """"
    :---"    left aligned
    "---:"    right aligned
    ":--:"    centered (also accepts "---"), default
    """
    if cell.startswith(":") and not cell.endswith(":"):
        return str.ljust
    elif cell.endswith(":") and not cell.startswith(":"):
        return str.rjust
    return str.center


with open(sys.argv[1], 'r') as f:
    query = f.read()

query = query.strip()
print("Before: " + "\n\n" + query, end="\n"* 3)

# For "cleaned" table entries: ***
rows = [[el.strip() for el in row.split('|')][1:-1] for row in query.splitlines()]

# sort rows by the priority (the third element) in ascending order
rows_task = rows[2:-1]                  # skip the non-task rows
rows_task.sort(key=lambda x: int(x[2][-1]), reverse=False)
rows[2:-1] = rows_task                  # replace the sorted rows (refs) back

# Max length of each "entry" is what we'll use
# to evenly space "columns" in the final table

col_widths = [max(map(len, column)) for column in zip(*rows)]

# Let's align entries as per intended formatting.
# Second line of input string contains alignment commmands: ***
alignments = list(map(get_alignment, rows[1]))

# Prepare for output string:
out = []
for row in rows:
    for entry, width, align in zip(row, col_widths, alignments):
        if not width:
            continue
        out.append("| {} ".format(align(entry, width)))
    out.append("|\n")

query = "".join(out)

print("After: " + "\n\n" + query, end="")

with open(sys.argv[1], 'w') as f:
    f.write(query)

