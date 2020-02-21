# Custom Memory Manager
- Globally overloads new, new[], delete, delete[] operators
- Uses First Fit Algorithm
- Capped at 256 Megabytes. This can be changed in `allocator.h`
- Fast, lightweight, easy to maintain
- Singleton design pattern
