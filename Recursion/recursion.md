🪜 Recursion Instruction Points
1. Define the base case clearly
   -> Always ask: When should this function stop?
   -> Base case must be simple, return directly, and prevent infinite recursion.

2. Ensure progress toward the base case
   -> Each recursive call should move closer to termination (smaller input, reduced range, next node, etc.).

3. Decide what each call should return
   -> Is it a boolean (valid/invalid), a value (sum, max), or a structure (list, tree)?
   -> Make sure recursive results are used, not discarded.

4. Combine results correctly
   -> Use logical operators (&&, ||) or arithmetic (+, max) depending on the problem.
   -> Don’t forget to propagate false or errors upward.

5. Think in terms of subproblems
   -> Break the problem into smaller identical tasks (left subtree, right subtree, next index).
   -> Each call should solve a smaller version of the same problem.

6. Watch out for side effects
   -> If recursion modifies global state (like a list or counter), ensure it’s reset/handled properly.
   -> Prefer returning values instead of relying on external mutation.

7. Analyze complexity early
   -> Time = number of calls × work per call.
   -> Space = recursion depth (stack).
   -> This helps you spot hidden inefficiencies.

8. Dry run on a small tricky case
   -> Manually trace 2–3 levels of recursion.
   -> Write down inputs, outputs, and return values at each step.


⚡ Quick Mnemonic
BPRC-DASD → Base case, Progress, Return, Combine, Divide, Avoid side effects, Space/Time, Dry run.
