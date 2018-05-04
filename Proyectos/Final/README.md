# Wolf, Sheep and Cabbage
_A boatman, a wolf, a sheep, and a cabbage are on the bank of a river. They have a small boat that is capable of carrying the boatman and at most one other animal/item with him. However, if left alone by the boatman, the wolf can eat the sheep, and the sheep can eat the cabbage. How can all four be moved safely to the opposite bank of the river?_

_This leads to a more general problem. If there are other groups of animals/items with the boatman, is it possible to move them all to the opposite bank of the river in such a way that nobody/nothing gets eaten?_

_We will give you the number of animals/items (not including the boatman). Moreover, we will give you all a list of pairs of the form "X Y" where the X-th animal/item will be eaten by the Y-th one if they are both on the opposite bank to the boatman._

**You are to determine whether it is possible to achieve the task or not.**

![alt text](https://i.ytimg.com/vi/KFDz8B0blhY/sddefault.jpg)

---

## Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test contains two space separated integers N and M - the number of animals/items not including the boatman, and the number of relations of the form "X will be eaten by Y", respectively.

The following M lines contain pairs of the form X Y with the meaning that the X-th animal/item will be eaten by the Y-th one if they are both on the opposite bank to the boatman.

---
## Output
For each test case, output a single line containing either "YES" or "NO" - the answer to the question "Is it possible to move them all to the opposite bank of the river in such a way that nobody/nothing gets eaten?".

---

## Constraints
1 ≤ T ≤ 100000

**Subtask 1:** 1 ≤ N ≤ 5, 0 ≤ M ≤ 10 - 73 points.

**Subtask 2:** 1 ≤ N ≤ 10, 0 ≤ M ≤ 20 - 27 points.



## My approach

Well I must say this is one of the my favorite problems since I was a kid.

For this problem, from what I´m getting, It´s like im the one judging if the solution that the user writes down is correct or not.

This should be fairly easy, and given the fact that I have like about 4 hours left before bedtime, I´m supposing I´m going to finish this very soon.

I´m going to just write down a bunch of "ifs" and a for, to get started, and then im going to edit from there.

**EDIT:** Well it turns out there was a bunch more to think about, because we need to know the whole scenario and save it in many variables. So my code just expanded.

**EDIT 2:** Just realized the bunch of variables that I´m using haha, when I first read the problem I thought I wouldn´t need many of them.

**EDIT 3:** Ok so I think im done, I finished this during work hours and really hope it works.