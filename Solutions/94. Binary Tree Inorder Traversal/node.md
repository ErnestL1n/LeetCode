# With Stack Implementation
  We need to kepp pushing the left child until it is nullptr , then since we have ```while(!stk.empty()||root)``` we have to do ```root=stk.pop()``` , finally we do ```root=root->right``` to operate right side of the left part if right part exists
