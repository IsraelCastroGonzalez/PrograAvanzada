# Problem

_The kitchen at the Infinite House of Pancakes has just received an order for a stack of K pancakes! The chef currently has N pancakes available, where N ≥ K. Each pancake is a cylinder, and different pancakes may have different radii and heights._

_As the sous-chef, you must choose K out of the N available pancakes, discard the others, and arrange those K pancakes in a stack on a plate as follows. First, take the pancake that has the largest radius, and lay it on the plate on one of its circular faces. (If multiple pancakes have the same radius, you can use any of them.) Then, take the remaining pancake with the next largest radius and lay it on top of that pancake, and so on, until all K pancakes are in the stack and the centers of the circular faces are aligned in a line perpendicular to the plate, as illustrated by this example:_

![alt text](https://code.google.com/codejam/contest/images/?image=pancake_stack.png&p=5768968631484416&c=3274486)

_You know that there is only one thing your diners love as much as they love pancakes: syrup! It is best to maximize the total amount of exposed pancake surface area in the stack, since more exposed pancake surface area means more places to pour on delicious syrup. Any part of a pancake that is not touching part of another pancake or the plate is considered to be exposed._

_If you choose the K pancakes optimally, what is the largest total exposed pancake surface area you can achieve?_

### Input
_The first line of the input gives the number of test cases, T. T test cases follow. Each begins with one line with two integers N and K: the total number of available pancakes, and the size of the stack that the diner has ordered. Then, N more lines follow. Each contains two integers Ri and Hi: the radius and height of the i-th pancake, in millimeters._

### Output
_For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum possible total exposed pancake surface area, in millimeters squared. y will be considered correct if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept._

**Limits**

- 1 ≤ T ≤ 100.
- 1 ≤ K ≤ N.
- 1 ≤ Ri ≤ 106, for all i.
- 1 ≤ Hi ≤ 106, for all i.
- Small dataset
    - 1 ≤ N ≤ 10.
- Large dataset
    - 1 ≤ N ≤ 1000.

Sample
~~~ 
Input 
 
4

2 1

100 20

200 10

2 2

100 20

200 10

3 2

100 10

100 10

100 10

4 2

9 3

7 1

10 1

8 4

Output 

- Case #1: 138230.076757951
- Case #2: 150796.447372310
- Case #3: 43982.297150257
- Case #4: 625.176938064

~~~


---
# My Approach

**Notice 1:**

- I need to do a nested array (basically a grid) to be able to say if any space has anything above or if the plate is already below (tha last row is just considered the last pancake)

- I need to sort the pankcakes so its always organized top-to-bottom where the first is always the smallest pankcake.

**Notice 2:**
- Need to use math functions to make it easier because is going to need to calculate the area of a ring basically for every pancake that has a pancake on the top. The scheme language aproach would be as follows:

~~~
> (define pi (* 4 (atan 1)))

> (define (cylinder-vol radius height)
    (* pi height (* radius radius))
  )

> (define (cylinder-area radius height)
    (+ (* 2 pi radius height) (* 2 pi (* radius radius)))
  )

> (define (tube-area inner_r length thick)
    (+ (* 2 pi inner_r length) (* 2 pi (+ inner_r thick) length)
    (* 2 (- (* (+ inner_r thick) (+ inner_r thick) pi) (* inner_r
    inner_r pi))))
  )

~~~

- At the en the only function I would need to call is the ```tube-area [qty-covered][height-of-pancake][qty-not-covered]``` 

**EDITS:**
- Height of the pancake not used (using the image as reference)
- A friend helped me to crack some code on C++ but i needed to do it in C (well crap).
- Didnt knew where to start so i googled some help with no results.
- Running out of time, the partial is comming and I have lots of work to do and some other projects too.
- In the end i kept the C++ code, better than havoing nothing.