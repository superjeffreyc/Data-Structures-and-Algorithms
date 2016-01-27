/**
 * This program implements a stack using an array.
 *
 */
public class ArrayStack {

	int			stackPointer	= 0;
	int			basePointer		= 0;
	int			size;
	Object[]	array;

	public ArrayStack(int size) {

		if (size > 0) {
			this.size = size;
			array = new Object[size];
		} else {
			throw new IllegalArgumentException("Minimum stack size is 2.");
		}
	}

	public void push(Object obj) throws Exception {

		if (obj == null)
			throw new NullPointerException();

		if (stackPointer != (size - 1)) {
			stackPointer++;
			array[stackPointer] = obj;

			// debug
			System.out.printf("Pushed %s onto the stack at position %d.\n", obj.toString(), stackPointer);
		} else {
			throw new Exception("The array stack has overflown.");
		}
	}

	public Object pop() {

		Object obj = null;

		if (stackPointer != 0) {
			obj = array[stackPointer];
			stackPointer--;

			// debug
			System.out.printf("Popped %s off the stack from element %d. Stack pointer is now at position %d\n",
					obj.toString(), stackPointer + 1, stackPointer);
		}

		return obj;

	}

	public Object peek() {
		return array[stackPointer];
	}

}
