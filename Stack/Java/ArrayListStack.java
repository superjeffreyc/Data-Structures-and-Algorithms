import java.util.ArrayList;

/**
 * This program implements a stack using an ArrayList.
 *
 */
public class ArrayListStack {

	int					stackPointer	= 0;
	ArrayList<Object>	stack;

	public ArrayListStack() {
		stack = new ArrayList<>();
		stack.add(null);
	}

	public void push(Object obj) {

		if (obj == null)
			throw new NullPointerException();

		stackPointer++;

		if (stack.size() == stackPointer) {
			stack.add(stackPointer, obj);
		} else {
			stack.set(stackPointer, obj);
		}

		// debug
		System.out.printf("Pushed %s onto the stack at position %d.\n", obj.toString(), stackPointer);

	}

	public Object pop() {

		Object obj = null;

		if (stackPointer != 0) {
			obj = stack.get(stackPointer);
			stackPointer--;

			// debug
			System.out.printf("Popped %s off the stack from element %d. Stack pointer is now at position %d\n",
					obj.toString(), stackPointer + 1, stackPointer);
		}

		return obj;

	}

	public Object peek() {
		return stack.get(stackPointer);
	}

}
