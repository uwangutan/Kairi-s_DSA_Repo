# \[Set\] - Pizza Allergy Checker
by Gran Sabandal

Computer Word · Intersection, Subset · write one function: _int findPizzas(Set menu[], int n, Set allergy, Set craving, int result[])_

## Story Version
Pizza Paradiso has 8 toppings, and each one is a single bit in an unsigned char:

bit01234567toppingCheesePepperoniMushroomOnionPineappleShrimpPeanutChili

A customer walks in with a list of allergies and a list of cravings. The ordering kiosk must show only the pizzas that are:

- Safe: they contain none of the allergy toppings.
- Satisfying: they contain all of the craved toppings.

## Direct Version
Given n computer-word sets menu[i], plus the sets allergy and craving, store in result[] (in menu order) every index i where:

- (menu[i] & allergy) == 0
- (menu[i] & craving) == craving

Return how many indices were stored.

# Test Cases 
## Test Case 1
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 4
Pizza #1 name: Hawaiian
Pizza #1 - number of toppings: 3
Pizza #1 - topping numbers (0-7): 0 1 4
Pizza #2 name: Seafood
Pizza #2 - number of toppings: 3
Pizza #2 - topping numbers (0-7): 0 5 7
Pizza #3 name: Veggie
Pizza #3 - number of toppings: 3
Pizza #3 - topping numbers (0-7): 0 2 3
Pizza #4 name: Spicy
Pizza #4 - number of toppings: 3
Pizza #4 - topping numbers (0-7): 0 1 7
Allergy - number of toppings: 1
Allergy - topping numbers (0-7): 5
Craving - number of toppings: 1
Craving - topping numbers (0-7): 0


=== KIOSK RESULT ===
Allergy: 00100000 {Shrimp}
Craving: 00000001 {Cheese}
Matches: 3
\- Hawaiian 00010011 {Cheese, Pepperoni, Pineapple}
\- Veggie 00001101 {Cheese, Mushroom, Onion}
\- Spicy 10000011 {Cheese, Pepperoni, Chili}

## Test Case 2
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 3
Pizza #1 name: Margherita
Pizza #1 - number of toppings: 1
Pizza #1 - topping numbers (0-7): 0
Pizza #2 name: Supreme
Pizza #2 - number of toppings: 4
Pizza #2 - topping numbers (0-7): 0 1 2 3
Pizza #3 name: Thai
Pizza #3 - number of toppings: 3
Pizza #3 - topping numbers (0-7): 0 5 6
Allergy - number of toppings: 0
Craving - number of toppings: 0


=== KIOSK RESULT ===
Allergy: 00000000 {}
Craving: 00000000 {}
Matches: 3
\- Margherita 00000001 {Cheese}
\- Supreme 00001111 {Cheese, Pepperoni, Mushroom, Onion}
\- Thai 01100001 {Cheese, Shrimp, Peanut}

## Test Case 3
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 3
Pizza #1 name: Pepperoni
Pizza #1 - number of toppings: 2
Pizza #1 - topping numbers (0-7): 0 1
Pizza #2 name: Meaty
Pizza #2 - number of toppings: 3
Pizza #2 - topping numbers (0-7): 0 1 7
Pizza #3 name: Classic
Pizza #3 - number of toppings: 1
Pizza #3 - topping numbers (0-7): 0
Allergy - number of toppings: 1
Allergy - topping numbers (0-7): 1
Craving - number of toppings: 1
Craving - topping numbers (0-7): 1


=== KIOSK RESULT ===
Allergy: 00000010 {Pepperoni}
Craving: 00000010 {Pepperoni}
Matches: 0
Sorry, no pizza for you!

## Test Case 4
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 3
Pizza #1 name: Plain
Pizza #1 - number of toppings: 0
Pizza #2 name: Cheesy
Pizza #2 - number of toppings: 1
Pizza #2 - topping numbers (0-7): 0
Pizza #3 name: Spicy
Pizza #3 - number of toppings: 1
Pizza #3 - topping numbers (0-7): 7
Allergy - number of toppings: 8
Allergy - topping numbers (0-7): 0 1 2 3 4 5 6 7
Craving - number of toppings: 0


=== KIOSK RESULT ===
Allergy: 11111111 {Cheese, Pepperoni, Mushroom, Onion, Pineapple, Shrimp, Peanut, Chili}
Craving: 00000000 {}
Matches: 1
\- Plain 00000000 {}

## Test Case 5
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 3
Pizza #1 name: Everything
Pizza #1 - number of toppings: 8
Pizza #1 - topping numbers (0-7): 0 1 2 3 4 5 6 7
Pizza #2 name: AlmostAll
Pizza #2 - number of toppings: 7
Pizza #2 - topping numbers (0-7): 0 1 2 3 4 5 6
Pizza #3 name: Hawaiian
Pizza #3 - number of toppings: 3
Pizza #3 - topping numbers (0-7): 0 1 4
Allergy - number of toppings: 0
Craving - number of toppings: 8
Craving - topping numbers (0-7): 0 1 2 3 4 5 6 7


=== KIOSK RESULT ===
Allergy: 00000000 {}
Craving: 11111111 {Cheese, Pepperoni, Mushroom, Onion, Pineapple, Shrimp, Peanut, Chili}
Matches: 1
\- Everything 11111111 {Cheese, Pepperoni, Mushroom, Onion, Pineapple, Shrimp, Peanut, Chili}

## Test Case 6
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 2
Pizza #1 name: Margherita
Pizza #1 - number of toppings: 1
Pizza #1 - topping numbers (0-7): 0
Pizza #2 name: Veggie
Pizza #2 - number of toppings: 2
Pizza #2 - topping numbers (0-7): 2 3
Allergy - number of toppings: 8
Allergy - topping numbers (0-7): 0 1 2 3 4 5 6 7
Craving - number of toppings: 0


=== KIOSK RESULT ===
Allergy: 11111111 {Cheese, Pepperoni, Mushroom, Onion, Pineapple, Shrimp, Peanut, Chili}
Craving: 00000000 {}
Matches: 0
Sorry, no pizza for you!

## Test Case 7
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 3
Pizza #1 name: Hawaiian
Pizza #1 - number of toppings: 3
Pizza #1 - topping numbers (0-7): 0 1 4
Pizza #2 name: Tropical
Pizza #2 - number of toppings: 2
Pizza #2 - topping numbers (0-7): 0 4
Pizza #3 name: Fruity
Pizza #3 - number of toppings: 1
Pizza #3 - topping numbers (0-7): 4
Allergy - number of toppings: 1
Allergy - topping numbers (0-7): 6
Craving - number of toppings: 2
Craving - topping numbers (0-7): 4 0


=== KIOSK RESULT ===
Allergy: 01000000 {Peanut}
Craving: 00010001 {Cheese, Pineapple}
Matches: 2
\- Hawaiian 00010011 {Cheese, Pepperoni, Pineapple}
\- Tropical 00010001 {Cheese, Pineapple}

## Test Case 8
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 4
Pizza #1 name: OnionRing
Pizza #1 - number of toppings: 2
Pizza #1 - topping numbers (0-7): 3 0
Pizza #2 name: Mushy
Pizza #2 - number of toppings: 2
Pizza #2 - topping numbers (0-7): 2 0
Pizza #3 name: Garden
Pizza #3 - number of toppings: 3
Pizza #3 - topping numbers (0-7): 0 2 3
Pizza #4 name: Dry
Pizza #4 - number of toppings: 1
Pizza #4 - topping numbers (0-7): 2
Allergy - number of toppings: 0
Craving - number of toppings: 2
Craving - topping numbers (0-7): 2 3


=== KIOSK RESULT ===
Allergy: 00000000 {}
Craving: 00001100 {Mushroom, Onion}
Matches: 1
\- Garden 00001101 {Cheese, Mushroom, Onion}

## Test Case 9
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 4
Pizza #1 name: ChiliOnly
Pizza #1 - number of toppings: 1
Pizza #1 - topping numbers (0-7): 7
Pizza #2 name: CheeseOnly
Pizza #2 - number of toppings: 1
Pizza #2 - topping numbers (0-7): 0
Pizza #3 name: Both
Pizza #3 - number of toppings: 2
Pizza #3 - topping numbers (0-7): 0 7
Pizza #4 name: Neither
Pizza #4 - number of toppings: 1
Pizza #4 - topping numbers (0-7): 3
Allergy - number of toppings: 1
Allergy - topping numbers (0-7): 3
Craving - number of toppings: 0


=== KIOSK RESULT ===
Allergy: 00001000 {Onion}
Craving: 00000000 {}
Matches: 3
\- ChiliOnly 10000000 {Chili}
\- CheeseOnly 00000001 {Cheese}
\- Both 10000001 {Cheese, Chili}

## Test Case 10
TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili
Enter number of pizzas: 10
Pizza #1 name: Hawaiian
Pizza #1 - number of toppings: 3
Pizza #1 - topping numbers (0-7): 0 1 4
Pizza #2 name: Seafood
Pizza #2 - number of toppings: 3
Pizza #2 - topping numbers (0-7): 0 5 7
Pizza #3 name: Veggie
Pizza #3 - number of toppings: 3
Pizza #3 - topping numbers (0-7): 0 2 3
Pizza #4 name: Spicy
Pizza #4 - number of toppings: 3
Pizza #4 - topping numbers (0-7): 0 1 7
Pizza #5 name: Satay
Pizza #5 - number of toppings: 3
Pizza #5 - topping numbers (0-7): 0 6 7
Pizza #6 name: Fiesta
Pizza #6 - number of toppings: 4
Pizza #6 - topping numbers (0-7): 0 3 4 7
Pizza #7 name: Shroom
Pizza #7 - number of toppings: 2
Pizza #7 - topping numbers (0-7): 2 7
Pizza #8 name: Cebuano
Pizza #8 - number of toppings: 4
Pizza #8 - topping numbers (0-7): 1 3 5 7
Pizza #9 name: Supreme
Pizza #9 - number of toppings: 5
Pizza #9 - topping numbers (0-7): 0 1 2 3 7
Pizza #10 name: Plain
Pizza #10 - number of toppings: 0
Allergy - number of toppings: 2
Allergy - topping numbers (0-7): 5 6
Craving - number of toppings: 2
Craving - topping numbers (0-7): 7 0


=== KIOSK RESULT ===
Allergy: 01100000 {Shrimp, Peanut}
Craving: 10000001 {Cheese, Chili}
Matches: 3
\- Spicy 10000011 {Cheese, Pepperoni, Chili}
\- Fiesta 10011001 {Cheese, Onion, Pineapple, Chili}
\- Supreme 10001111 {Cheese, Pepperoni, Mushroom, Onion, Chili}