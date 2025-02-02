
### what about two pointers?
Two pointer is primarily used to traverse arrays, collaboratively complete a task

When both pointers reference the same array but move in opposite directions, this pattern can be used 
for searching, typically in sorted arrays.

When both pointers reference the same array and move in the same direction without intersecting, 
this is known as a sliding window (where the region between the two pointers defines the current window). 
This pattern is frequently used for interval/range searching.

### pointer const qualifiers
```cpp
int x; 
int * p1 = &x; // both pointer and value can be modified
const int * p2 = &x; // pointer can be modified, but value cannot (const int) 
int * const p3 = &x; // pointer cannot be modified (* const)，bue value can
const int * const p4 = &x; // neither can be modified
```