# Day 13.5 — Operator Overloading Practice

## The clean perspective (read this first)

Operator overloading is nothing magical: `a + b` is just a **function call in
disguise**. You are writing normal functions with special names:

```cpp
a + b     // really:  a.operator+(b)        (member version)
          //     or:  operator+(a, b)       (non-member version)
a == b    // really:  a.operator==(b)
cout << a // really:  operator<<(cout, a)   (MUST be non-member — why? see rule 4)
```

That's the whole trick. Everything else is deciding *which form* to use.

### The rules that actually matter

1. **You can't invent new operators** (no `**`), can't change precedence,
   arity, or how operators work on built-in types.
2. **Member function form**: the *left* operand is your object.
   `Mystring::operator+(const Mystring &rhs)` — `this` is the left side.
3. **Non-member (often `friend`) form**: use when the left operand is NOT
   your class, or when you want symmetric conversions
   (`"hello" + my_str` only works with the non-member form).
4. **Stream operators `<<` and `>>` must be non-member**, because the left
   operand is `std::ostream`/`std::istream`, which you can't modify.
5. **Return types follow convention**:
   - comparison (`==`, `<`)            → `bool`
   - arithmetic (`+`, `-`)             → new object **by value**
   - compound assignment (`+=`)        → `*this` by reference (`Mystring&`)
   - assignment (`=`)                  → `*this` by reference, check self-assignment
   - `operator<<`                      → the `ostream&` you were given (enables chaining)
6. **Pre vs post increment**: `operator++()` is `++x`; `operator++(int)` is
   `x++` — the unused `int` is just a tag to tell them apart. Post-increment
   must save and return the OLD value.
7. Overload only when the meaning is obvious. `movie1 + movie2` — obvious? No.
   `str1 + str2` — obvious. If you'd have to explain it, use a named method.

### Member vs non-member cheat sheet

| Operator            | Prefer            | Why                                  |
|---------------------|-------------------|--------------------------------------|
| `=` `+=` `[]` `()`  | member (required for `=` `[]` `()`) | left side is always your object |
| `+` `-` `==` `<`    | non-member friend | symmetric — allows `"abc" + s`       |
| `<<` `>>`           | non-member friend | left side is a stream, not your class|
| `++` `--` unary `-` | member            | acts on a single object of your type |

---

## Part A — Mystring class (files in this folder)

Work through `Mystring.h` / `Mystring.cpp`. The class manages a raw
`char *str` on the heap **on purpose** — that's what makes `=`, copy, and
move meaningful. `main.cpp` has tests for every level; uncomment each
`LEVEL_x` block as you finish it.

- [ ] **Level 1 — equality**: `operator==`, `operator!=` (compare with `strcmp`)
- [ ] **Level 2 — comparison**: `operator<`, `operator>` (lexical order)
- [ ] **Level 3 — unary minus**: `operator-` returns a lowercase copy (use `tolower`)
- [ ] **Level 4 — concatenation**: `operator+` returns a new Mystring
      (allocate `strlen(a)+strlen(b)+1`, `strcpy` then `strcat`)
- [ ] **Level 5 — compound**: `operator+=` implemented AS `*this = *this + rhs;`
      (one line — notice how operators compose)
- [ ] **Level 6 — repeat**: `operator*` so `s * 3` gives `"abcabcabc"`, and `operator*=`
- [ ] **Level 7 — increment**: pre `operator++` (uppercase in place) and
      post `operator++(int)` (uppercase, but return the OLD value)
- [ ] **Level 8 — streams**: friend `operator<<` and `operator>>`
- [ ] **Level 9 — the big three you already know from Day 13**:
      copy assignment `operator=` (self-assignment check!) and
      move assignment `operator=(Mystring &&)` (steal pointer, null the source)

## Part B — retrofit your own Movie/Movies classes (../)

Now apply it to code you wrote — this is where it clicks:

- [ ] friend `operator<<` for `Movie` → replaces the display logic
      (`os << movie` prints `name, rating, watched`)
- [ ] `operator==` for `Movie` → two movies are equal if names match;
      use it inside `Movies::add_movie` duplicate check
- [ ] pre-increment `operator++` for `Movie` → bumps `watched`;
      use it inside `Movies::increment_watched`
- [ ] friend `operator<<` for `Movies` → prints the whole collection,
      so `std::cout << my_movies;` replaces `my_movies.display()`

## Build & run

```
g++ -std=c++17 -Wall main.cpp Mystring.cpp -o main && ./main
```

## Self-check questions (answer without looking)

1. Why must `operator<<` be a non-member?
2. Why does post-increment take a dummy `int` parameter, and why is it
   slightly slower than pre-increment?
3. Why does `operator=` return `Mystring&` and not `void` or `Mystring`?
4. What breaks if you forget the self-assignment check in `operator=`?
5. Why does the friend version of `operator+` allow `"hello" + s1` but the
   member version doesn't?
