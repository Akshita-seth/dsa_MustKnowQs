A auto use
- for(auto it : freq) → it is a copy of that pair.
- for(auto& it : freq) → it is a reference to the actual pair inside the map.
👉 In your code:
- You only need the values (it.first, it.second) to push into the heap.
- Copy is fine — no need to modify the map.
- If you wanted to update frequencies inside the map, you’d use auto&.

B Pair access 
- Access via .first and .second (Works in all C++ versions, Explicit and clear usage)
Example:
pair<int,string> p = {1,"hello"};
cout << p.first << " " << p.second;

- Structured bindings with auto [x,y] (Introduced in C++17, Unpacks pair into separate variables, Cleaner in loops and modern code)
Example:
pair<int,string> p = {1,"hello"};
auto [num,word] = p;
cout << num << " " << word;

Copies by default; use & for references
for (auto &[key,value] : myMap) { ... }
Rule of thumb
- Use .first / .second for compatibility and clarity
- Use auto [x,y] for concise, modern code
- Add & when modifying original values

C Formal Parameter for customComparator()
Comparator:
- Heap of pointers → comparator takes T*.
- Heap of objects(string, int, char, pair) → comparator takes const T&.

D Passing Arrays and Vectors in C++

Raw Arrays (int arr[])
- Automatically decay into a pointer when passed to a function
- No need to explicitly use &
- Mutations inside the function affect the original array
- Function does not know the size, must be passed separately

std::vector
- vector<int> v → passed by value (copy). Mutations affect only the local copy
- vector<int>& v → passed by reference. Mutations affect the original vector
- const vector<int>& v → passed by reference, but immutable. No copy, safe for read-only access

std::array
- Behaves like vector (object type)
- Needs & for reference semantics
- Example: void foo(std::array<int, 5>& arr)

Rule of Thumb
- Use const vector<int>& when you only need to read
- Use vector<int>& when you need to modify
- Avoid plain vector<int> unless you explicitly want a copy

