A
for(auto it : freq) → it is a copy of that pair.
for(auto& it : freq) → it is a reference to the actual pair inside the map.
👉 In your code:
You only need the values (it.first, it.second) to push into the heap.
Copy is fine — no need to modify the map.
If you wanted to update frequencies inside the map, you’d use auto&.

B
Comparator:
Heap of pointers → comparator takes T*.
Heap of objects(string, int, char, pair → comparator takes const T&.
