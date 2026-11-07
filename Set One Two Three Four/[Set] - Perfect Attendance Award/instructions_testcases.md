# \[Set\] - Perfect Attendance Award
by Gran Sabandal

Bit Vector · Intersection, Union, Complement · write one function: _void attendanceReport(Set days[], int d, Set perfect, Set never)_

## Story Version
The DSA class has 16 students, numbered 0 to 15. Every day the classroom scanner records who showed up, and each day's record is stored as a bit vector.

At the end of the week, the instructor wants two lists:

- 🏆 Perfect Attendance: students who were present on every day.
- 👻 Ghost Students: students who were never present.

Build both lists using set operations.

## Direct Version
Given d bit vectors days\[0..d-1\] over the universe {0..15}:

- perfect = days\[0] ∩ days\[1] ∩ … ∩ days\[d-1]
- never = complement of (days[\0] ∪ days\[1] ∪ … ∪ days\[d-1])

perfect and never contain garbage when the function is called, so fill in every index.

# Test Cases 
## Test Case 1
Number of days: 2
Day 1 number of students: 5
Enter students od day 1: 4 4 4 8 8
Day 2 number of students: 2
Enter students od day 2: 8 4
Perfect attendance: {4, 8}
Never attended: {0, 1, 2, 3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15}

## Test Case 2
Number of days: 2
Day 1 number of students: 8
Enter students od day 1: 0 1 2 3 4 5 6 7
Day 2 number of students: 8
Enter students od day 2: 8 9 10 11 12 13 14 15
Perfect attendance: {}
Never attended: {}

## Test Case 3
Number of days: 3
Day 1 number of students: 3
Enter students od day 1: 3 6 9
Day 2 number of students: 3
Enter students od day 2: 9 6 3
Day 3 number of students: 3
Enter students od day 3: 6 3 9
Perfect attendance: {3, 6, 9}
Never attended: {0, 1, 2, 4, 5, 7, 8, 10, 11, 12, 13, 14, 15}

## Test Case 4
Number of days: 5
Day 1 number of students: 7
Enter students od day 1: 0 2 4 6 8 10 12
Day 2 number of students: 8
Enter students od day 2: 0 1 2 4 6 8 12 13
Day 3 number of students: 6
Enter students od day 3: 0 2 4 8 12 14
Day 4 number of students: 7
Enter students od day 4: 0 2 3 4 8 11 12
Day 5 number of students: 5
Enter students od day 5: 0 2 4 8 12
Perfect attendance: {0, 2, 4, 8, 12}
Never attended: {5, 7, 9, 15}

## Test Case 5
Number of days: 3
Day 1 number of students: 6
Enter students od day 1: 0 1 2 5 7 9
Day 2 number of students: 5
Enter students od day 2: 1 2 5 9 12
Day 3 number of students: 5
Enter students od day 3: 2 5 9 12 14
Perfect attendance: {2, 5, 9}
Never attended: {3, 4, 6, 8, 10, 11, 13, 15}

## Test Case 6
Number of days: 1
Day 1 number of students: 4
Enter students od day 1: 3 6 8 10
Perfect attendance: {3, 6, 8, 10}
Never attended: {0, 1, 2, 4, 5, 7, 9, 11, 12, 13, 14, 15}

## Test Case 7
Number of days: 3
Day 1 number of students: 3
Enter students od day 1: 1 2 3
Day 2 number of students: 0
Enter students od day 2: Day 3 number of students: 2
Enter students od day 3: 2 3
Perfect attendance: {}
Never attended: {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

## Test Case 8
Number of days: 2
Day 1 number of students: 16
Enter students od day 1: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Day 2 number of students: 16
Enter students od day 2: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
Perfect attendance: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
Never attended: {}

## Test Case 9
Number of days: 2
Day 1 number of students: 0
Enter students od day 1: Day 2 number of students: 0
Enter students od day 2: Perfect attendance: {}
Never attended: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

## Test Case 10
Number of days: 2
Day 1 number of students: 2
Enter students od day 1: 0 15
Day 2 number of students: 3
Enter students od day 2: 0 7 15
Perfect attendance: {0, 15}
Never attended: {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14}