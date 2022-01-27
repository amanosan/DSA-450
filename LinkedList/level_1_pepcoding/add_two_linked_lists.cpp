#include "LinkedList2.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
Given Two Linked Lists:
9 -> 7 -> 8 -> 5
          4 -> 6
So we need to add the numbers 9785 with 46.
The answer should be 9831
*/

class LL : public LinkedList
{
    // need to pass result as reference,
    // because we dont want new lists to get created everytime
    static int helper(Node *one, int pv1, Node *two, int pv2, LL &result)
    {
        if (one == nullptr and two == nullptr)
            return 0;

        // pv1 and pv2 are the place value of the digit
        // eg. in 9785, place value of 5 is 1, 8 is 2 etc.
        // and we can add number only if their place values are same
        // and we start from the right most towards the left.
        int ans = 0;
        if (pv1 > pv2) // when list one has data but list two has nothing in the pv2 place.
        {
            // moving pv1 and one towards left
            int old_carry = helper(one->next, pv1 - 1, two, pv2, result);
            ans = one->data + old_carry;
        }
        else if (pv1 < pv2) // when list one has nothing and list two has some data
        {
            // moving two towards the left
            int old_carry = helper(one, pv1, two->next, pv2 - 1, result);
            ans = two->data + old_carry;
        }
        else
        {
            int old_carry = helper(one->next, pv1 - 1, two->next, pv2 - 1, result);
            // at some point the recursion will result in one and two both as nullptr
            // then we return 0 as carry and start adding the values by backtracking
            ans = one->data + two->data + old_carry;
        }
        // for getting the final ans:
        // ans value can be greater than 10, so we need to get the
        // digit value (ans % 10) and new_carry(ans / 10)
        int new_ans = ans % 10;
        int new_carry = ans / 10;
        result.add_first(new_ans);
        return new_carry;
    }

public:
    static LL add_two(LL one, LL two)
    {
        LL result;
        int oc = helper(one.head, one.size, two.head, two.size, result);
        // we can have old carry after completing as well
        if (oc > 0)
            result.add_first(oc);
        return result;
    }
};

int main()
{
    LL l1;
    LL l2;
    l1.add_last(4);
    l1.add_last(6);
    l2.add_last(9);
    l2.add_last(7);
    l2.add_last(8);
    l2.add_last(5);
    l1.display(); // 46
    l2.display(); // 9785
    LL result = LL::add_two(l1, l2);
    result.display(); // 9831
    return 0;
}