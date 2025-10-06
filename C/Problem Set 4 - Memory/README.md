## Module 4 – Memory

This module explored how computers manage and manipulate memory at a low level, with an emphasis on pointers, arrays, structs, and file I/O.  
Through practical assignments, the problems introduced key ideas such as working with binary file formats, image processing, and memory safety.  

---

### Problem Set 4

#### 1. Volume
- **Task**: Implement a program that modifies the volume of a WAV audio file by scaling each sample value by a given factor.
- **Concepts**: File I/O in C, handling binary file formats (headers + data), manipulating arrays of 16-bit integers, command-line arguments, working with `fopen`, `fread`, `fwrite`, and `fclose`.

#### 2. Filter (less)
- **Task**: Write functions to apply various filters (grayscale, sepia, reflect, blur) to BMP image files.
- **Concepts**: Structs (`RGBTRIPLE`), two-dimensional arrays, image representation as pixels, pointer arithmetic, and algorithm design for image manipulation.

#### 3. Filter (more)
- **Task**: Extend image filtering by implementing more advanced transformations, such as edge detection.
- **Concepts**: Iterating over images with nested loops, convolution-like operations, handling edge cases in a 2D grid, working with helper functions in multiple `.c` files.

#### 4. Recover
- **Task**: Forensically recover JPEG files from a raw memory card image by scanning for JPEG headers and writing each file to disk.
- **Concepts**: Pointers and byte arrays, file carving, signatures in binary data, dynamic file creation, and practicing safe memory management to avoid leaks.
