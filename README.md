# Library Management
*A C++ console app built for my OOP course (Year 1, Semester 2). It simulates a small library with roles, search/sort, borrowing/returning, and CSV seeding.*

## Features
- Two separate menus: **Admin** vs **User**, with different options per role.
- Unique IDs for every **book** and every **user**.
- Search & sort:
  - Partial (single-word) search by **title**, **author**, **genre**.
  - Sort ascending/descending by **name** or **year**.
- Multiple types:
  - Readers: **Student**, **AveragePerson** (regular user).
  - Books: **Poetry**, **Novel**.
- Admin login: **3 password attempts**, then lockout.
- Admin features: add/remove books, view all books & readers, search by title/author/genre.
- User features: view, **borrow**, **return**, **search**, **sort**; subscription price personalized by **age** and **profession**.
- Default data (books & readers) loaded from **CSV**.
- Interactive console menu.
- Exceptions for invalid input + thorough input validation.

## How It Works
- **Library (Singleton)**: orchestrates the app, seeds data from CSV, and runs Admin/User menus.
- **Books**
  - `Book` (base): `title`, `author`, `genre`, `year`, `copies`; stock updated with `++/--`.
  - `Novel` (derived): adds `pages` and `chapters`.
  - `Poetry` (derived): adds `poemCount`.
  - `BookFactory`: interactively creates **Novel** or **Poetry** with input checks (Factory pattern).
- **Readers**
  - `Reader` (base): tracks `borrowedBooks` and `readBooks`; `borrowBook` / `returnBook` update stock.
  - `Student` (derived): up to **5** books; membership cost depends on **school grade**.
  - `AveragePerson` (derived): up to **3** books; discounts for **teacher/doctor** and **age 65+**.
  - `StudentBuilder` / `PersonBuilder`: step-by-step creation of readers (Builder pattern).
- **Finding books**
  - `SearchStrategy`: case-insensitive substring search by **name**, **author**, or **genre** (Strategy pattern).
  - `FilterBooks`: returns a sorted copy by **Name** or **Year** (asc/desc).

## Design Patterns & OOP
- **Singleton** — main `Library` controller.
- **Factory** — `BookFactory` for creating book subtypes.
- **Builder** — `StudentBuilder` / `PersonBuilder` for constructing readers.
- **Strategy** — `SearchStrategy` for pluggable search.
- **Templates** — template utilities/classes where appropriate.
- Core OOP: inheritance (`Book`→`Novel`/`Poetry`, `Reader`→`Student`/`AveragePerson`), virtuals, encapsulation, operator overloading (`++/--` on `Book`), stream I/O.


Some links that helped me:
https://www.geeksforgeeks.org/how-to-validate-user-input-in-cpp/

https://www.geeksforgeeks.org/how-to-convert-std-string-to-lower-case-in-cpp/

https://refactoring.guru/design-patterns

https://stackoverflow.com/questions/7616867/how-to-test-a-string-for-letters-only



