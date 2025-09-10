Library Manager (OOP Course – Year 1, Semester 2)

This is a small C++ console app I built for my OOP course (1st year, second semester). It simulates a mini-library with separate Admin and User roles, unique IDs for every book and reader, robust input validation with custom exceptions, and default data loaded from CSV files. The UI is a simple, interactive menu.

How it works (quick tour)

Library (Singleton) bootstraps the app, seeds data from CSV, and runs the menus.

Books

Book (base): title, author, genre, year, copies; stock updated with ++/--.

Novel (derived): adds pages and chapters.

Poetry (derived): adds number of poems.

BookFactory creates Novel or Poetry interactively (Factory Pattern).

Readers

Reader (base): tracks borrowed/read lists; borrowBook/returnBook update stock.

Student (derived): up to 5 books; membership cost depends on school grade.

AveragePerson (derived): up to 3 books; discounts for teacher/doctor and age 65+.

StudentBuilder / PersonBuilder build readers step by step (Builder Pattern).

Finding books

SearchStrategy: case-insensitive substring search by name, author, or genre (Strategy Pattern).

FilterBooks: returns a sorted copy by Name or Year (asc/desc).

Features by role

Admin

Password-protected login (3 attempts; then locked out).

Add/remove books, view all books/readers, search by title/author/genre.

User

View, borrow, return, search, and sort books.

Sort ascending/descending by name or year.

See a personalized subscription price based on age and profession.

Extras

Strong input checks (cin guards) + custom numeric exceptions (age/grade/months/choices).

Template classes used where it makes sense.

Two clearly separated menus (Admin vs. User) with role-specific options.


De unde am invatat cum sa fac niste chestii:
https://www.geeksforgeeks.org/how-to-validate-user-input-in-cpp/
https://www.geeksforgeeks.org/how-to-convert-std-string-to-lower-case-in-cpp/
https://refactoring.guru/design-patterns
https://stackoverflow.com/questions/7616867/how-to-test-a-string-for-letters-only


* folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece
conțin fișiere generate și nu ne ajută să le versionăm.
