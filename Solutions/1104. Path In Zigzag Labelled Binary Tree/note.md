## Intuition
  * We know that the target node's actual parent should be the parent of its symmetric node at current height.
  * we first get the current height which is the first whlie loop
  * Then, to get the symmetric node, we first need to realize the fact:
    * (label of current node + label of symmetric node) == (label of minimum node at current height) + (label of maximum node at current height)
    * The minimum label can be calculated by 2^(level - 1) and
    * maximum label can be calculated by 2^(level) - 1, where level is the current height.
