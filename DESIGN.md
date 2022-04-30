# Stack_Push

For Stack Push I will simply create a new node corresponding to the CalculatorItem given.
Since this new node pointer will be used outside of this functions stack, I will allocate memory for it
and account for it in my stack delete function later. The node must be freed later on. If there is an error in
allocating memory for this node, I will return false. I will then set the node item to the calculator item
parameter and set the node next value to the current stack top. Thus, the new stack top will be this newly created node.

# Stack_Pop

Looking ahead, I noticed I will create a stack_empty function. I think I can use this to my advantage here to check
if the stack is empty and do an early return if it is. In the output pointer given, I will change the value to the stack top value
anad the item to the stack top item respectively. Since we are popping, I now set the stack top to be the current top's (which is a node)
next node.

# Stack_Empty

If the stack is empty, the top of the stack will be NULL or 0 (since we used calloc to initiate the stack). Using this, I can simply return !(s -> top). This will check if there is a top of the stack and if there is return false otherwise true.

# Stack_delete

Given a pointer to a pointer of the stack, I must dereference this pointer once to get the actual stack pointer. I free this pointer's top value and then free the pointer itself. I must free the top value for as long as there is one since I allocate memory for the top Nodes. After freeing the top value, I must set the top to the next node and free that one as well, since there is memory allocated for it.

# Stack_compute_step

This function is pretty straightforward. I will first check if the CalculatorItem given is a NUMBER or operator. If it is a number, I will simply add it to the stack and return true. If if is an operator, I must initialize two new CalculatorItems to get the two most recent stack items. If one or both of these are not numbers I should return false since I need two operands. Likewise if the stack is empty when trying to assign these two new values, I also return false; I will also initialize a new CalculatorItem res to carry the info of my calculation. The res value will be pushed to the stack after calculation. If the operator is plus I set res.value to the two other CalculatorItems I created added together. The same is said for the other operatos respectively. Finally, If the stack is empty after all of this, I delete it via my stack_delete function which should free everything in it. The last statement of this function is return true, since all the false returns should have been covered by now.
